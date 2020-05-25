#pragma once
#include <algorithm>
#include <atomic>
#include <cassert>
#include <cstdint>
#include <functional>
#include <queue>
#include <memory>
#include <mutex>
#include <type_traits>
#include <vector>
#include <cinttypes>
#include <unordered_map>
#include <utility>

#include "sim-module/message.hh"
#include "sim-module/optional.hh"

template <typename Int>
struct Offset {
  static_assert(std::is_integral<Int>::value, "only accept integral offset types");

  using value_type = Int;

  constexpr Offset() noexcept
    : offset{0}
  {}
  constexpr Offset(value_type offset) noexcept
    : offset{offset}
  {}

  constexpr explicit operator value_type() noexcept {
    return offset;
  }

private:
  const value_type offset;
};

template <
  typename Int,
  typename OtherInt,
  typename = typename std::enable_if<
    std::is_integral<Int>::value && std::is_integral<OtherInt>::value
  >::type
>
constexpr Int operator+(Int i, Offset<OtherInt> offset) {
  return static_cast<Int>(i + static_cast<OtherInt>(offset));
}

// type alias for indicating transfer ownership of raw pointer
// see: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-raw
template <
  typename T,
  typename = typename std::enable_if<std::is_pointer<T>::value>::type
>
using owner = T;

struct Event {
    using tick_type          = std::uint64_t;
    using tick_offset_type   = Offset<std::uint64_t>;
    using event_handler_type = std::function<void(Event&)>;
    using message_type       = Message;
	using id_type            = std::uint64_t;

    friend class EventQueue;

    Event(const Event&) = default;
    Event(Event&&) = default;

    Event& operator=(const Event&) = default;
    Event& operator=(Event&&) = default;

    ~Event() = default;

	id_type                       event_id;
    tick_type                     tick;
    event_handler_type            event_handler;
    std::shared_ptr<message_type> message;
    // TODO: disable this on non-debug build
    std::string                   debug_message;

private:
    Event(id_type id, tick_type tick, event_handler_type handler, owner<message_type*> message)
      : event_id{id}
	  , tick{tick}
      , event_handler{std::move(handler)}
      , message{message}
    {}
};

struct EventPriorityComp {
  constexpr bool operator()(const Event& lhs, const Event& rhs) const {
    return lhs.tick > rhs.tick;
  }
};

struct DependentEvent {
	using hw_id_type         = uint32_t;
	using dep_count_type     = uint32_t;
	using tick_offset_type   = Event::tick_offset_type;
	using event_handler_type = Event::event_handler_type;

	friend class EventQueue;

private:
	DependentEvent(hw_id_type id, dep_count_type cnt, tick_offset_type offset
			, event_handler_type handler, std::string msg = "unknown")
		: hw_id{id}, dependency_count{cnt}, event_offset{offset}
		, event_handler{std::move(handler)}, debug_message{std::move(msg)}
	{}
	hw_id_type         hw_id;
	dep_count_type     dependency_count;
	tick_offset_type   event_offset;
	event_handler_type event_handler;
	std::string        debug_message;

};

class EventQueue
{
  using impl_queue_type = std::priority_queue<Event, std::vector<Event>, EventPriorityComp>;
  using mutex_type      = std::recursive_mutex;
  using update_list_type= std::vector<std::function<void(void)>>;
  using dep_queue_type  = std::unordered_map<DependentEvent::hw_id_type, DependentEvent>; 

public:
  using event_type         = impl_queue_type::value_type;
  using update_type        = update_list_type::value_type;
  using const_reference    = impl_queue_type::const_reference;
  using tick_type          = event_type::tick_type;
  using id_type            = event_type::id_type;
  using tick_offset_type   = event_type::tick_offset_type;
  using event_handler_type = event_type::event_handler_type;
  using message_type       = event_type::message_type;
  using dep_event_type     = DependentEvent;
  using hw_id_type         = dep_event_type::hw_id_type;
  using dep_count_type     = dep_event_type::dep_count_type;

  EventQueue()
    : latest{0}, accumulated_id{0}
  {}

  void emplace(tick_offset_type offset, event_handler_type handler, owner<message_type*> message, std::string event_debug_message) {
    std::lock_guard<mutex_type> _(mutex);

    event_type e{accumulated_id, tick() + offset, std::move(handler), message};

    //std::cout << " - Schedule event <" << event_debug_message << "> to tick: " << e.tick << std::endl;
    writelog(" - Schedule event(%" PRIu64 ") <%s> to tick: %" PRIu64 "\n", accumulated_id, event_debug_message.c_str(), e.tick);

    // Assign here is for optimization, so that we can easily disable this for non-debug build.
    e.debug_message = event_debug_message;

	accumulated_id++;
    impl_queue.emplace(std::move(e));
  }

  void add_dep_event(hw_id_type id, dep_count_type cnt, tick_offset_type offset, event_handler_type handler, std::string msg) {
    assert(dep_queue.find(id) == dep_queue.end() &&
      "This hardware block already has another pending event.");
		assert(cnt>0 && "Initial dependency count should be positive.");
    auto p = std::make_pair(id, dep_event_type{id, cnt, offset, std::move(handler), std::move(msg)});
    dep_queue.insert(std::move(p));
  }

  void decrement_dep_count(hw_id_type id) {
    assert(dep_queue.find(id) != dep_queue.end() &&
      "No pending event for this hardware block.");
    if(--dep_queue.at(id).dependency_count == 0) {
      dep_event_type e{std::move(dep_queue.at(id))};
      dep_queue.erase(id);
      emplace(e.event_offset, std::move(e.event_handler), nullptr, std::move(e.debug_message));
    }
  }

  bool hw_waiting(hw_id_type id) {
	  return dep_queue.find(id) != dep_queue.end();
  }
  
  void add_update(update_type update) {
    update_list.emplace_back(std::move(update));
  }

  void pop() {
    std::lock_guard<mutex_type> _(mutex);

    event_type event = top();
    latest = event.tick;
    impl_queue.pop();
  }

  optional<event_type> try_pop() {
    std::lock_guard<mutex_type> _(mutex);

    if (empty()) {
      return nullopt;
    }

    event_type event = top();
    latest = event.tick;
    impl_queue.pop();

    return std::move(event);
  }

  template <typename Predicate>
  optional<event_type> try_pop_if(Predicate&& predicate) {
    std::lock_guard<mutex_type> _(mutex);

    if (empty()) {
      return nullopt;
    }

    if (!std::forward<Predicate>(predicate)(top())) {
      return nullopt;
    }

    event_type event = top();
    latest = event.tick;
    impl_queue.pop();

    return std::move(event);
  }

  bool empty() {
    std::lock_guard<mutex_type> _(mutex);
    // TODO: read write lock
    return impl_queue.empty();
  }

  void handle_queue_top_tick_event() {
    tick_type next;
    {
        std::lock_guard<mutex_type> _(mutex);
        if (empty()) return;
        next = next_tick() + 1;
		handle_all_event_up_to_tick(next);
    }
    run_update();
  }

  void handle_all_event_up_to_tick(tick_type tick) {
    const auto should_handle = [tick](const event_type& event) {
      return event.tick < tick;
    };
    for (optional<event_type> event; (event = try_pop_if(should_handle));) {
      //std::cout << "Dispatch event <" << event->debug_message << "> on tick: " << event->tick << std::endl;
      writelog("Dispatch event(%" PRIu64 ") <%s> on tick: %" PRIu64 "\n", event->event_id, event->debug_message.c_str(), event->tick);
      event->event_handler(*event);
    }
  }

  void consume_all_events() {
    for (optional<event_type> event; (event = try_pop());) {
      //std::cout << "Dispatch event <" << event->debug_message << "> on tick: " << event->tick << std::endl;
      writelog("Dispatch event(%" PRIu64 ") <%s> on tick: %" PRIu64 "\n", event->event_id, event->debug_message.c_str(), event->tick);
      event->event_handler(*event);
	  {
		std::lock_guard<mutex_type> _(mutex);
		if (!empty() and tick() != next_tick())
		  run_update();
	  }
    }
  }

  tick_type tick() const noexcept {
    return latest;
  }

  tick_type next_tick() noexcept {
    std::lock_guard<mutex_type> _(mutex);
    return top().tick;
  }

  void run_update() const noexcept {
    for(const update_type &routine : update_list)
	  routine();
  }

private:
  const_reference top() const {
    return impl_queue.top();
  }

private:
  std::atomic<tick_type> latest;
  id_type accumulated_id;
  impl_queue_type impl_queue;
  update_list_type update_list;
  mutex_type mutex;
  dep_queue_type dep_queue;
};
