#pragma once
#include <array>
#include <atomic>
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

#include "sim-module/eventq.hh"
#include "sim-module/message.hh"
#include "sim-module/optional.hh"
#include "sim-module/request_pool.hh"
#include "sim-module/trace.hh"
#include "sim-module/statistics.hh"
using namespace statistics;

#ifndef METHOD_AS_EVENT_HANDLER
#define METHOD_AS_EVENT_HANDLER(method) std::bind(&method, this, std::placeholders::_1)
#endif

#ifndef SET_REG_BY_IDX
#define SET_REG_BY_IDX_W_HANDLER( idx, handler)     case (idx): handler; break
#define SET_REG_BY_IDX( idx, reg_var, data)              case (idx): (reg_var) = (data); break
#endif

#ifndef GET_REG_BY_IDX
#define GET_REG_BY_IDX( idx, reg_var)   case (idx): return (reg_var)
#endif

// Base class for all simulation object
class SimObject {
public:
    using id_type            = unsigned;
    using event_type         = EventQueue::event_type;
    using hw_id_type         = EventQueue::hw_id_type;
    using dep_count_type     = EventQueue::dep_count_type;
    using event_handler_type = event_type::event_handler_type;
    using tick_type          = event_type::tick_type;
    using tick_offset_type   = event_type::tick_offset_type;
    using message_type       = event_type::message_type;
    constexpr static size_t bus_width = 512;

	// For now, supports 32-bit addressing only.
    using address_type        = std::uint32_t;
    using reg_type            = std::uint32_t;
    using size_type           = std::uint32_t;
    using transaction_id_type = std::uint32_t;

    struct data_type {
        size_type len;
        unsigned char data[bus_width / 8];
		data_type() : len(0) {}
        data_type(size_type l, unsigned char *d) : len{l} {
            assert(l <= (bus_width / 8));
            // TODO: memcpy
            for(size_type i = 0; i < l; ++i) {
                data[i] = d[i];
            }
        }
    };
protected:

private:
    static std::atomic<id_type> numOfSimObjects;

    EventQueue &event_queue;

    using request_pool_type = RequestPool<transaction_id_type, address_type, reg_type, data_type>;
    // Unlimited for now
    request_pool_type requests;

public:
    const std::string name;
    const id_type id;

    SimObject(EventQueue &eq, std::string n)
      : event_queue{eq}
      , name{std::move(n)}
      , id{++numOfSimObjects}
    {}
    virtual ~SimObject() = default;

    void regStats();
    void printStats();

public:
    template <typename Callback>
    transaction_id_type requestRegisterRead(address_type addr, Callback&& callback) {
      return requests.pushRead(addr, std::forward<Callback>(callback));
    }

    template <typename Callback>
    transaction_id_type requestMemoryRead(address_type addr, Callback&& callback) {
      return requests.pushRead(addr, std::forward<Callback>(callback));
    }

    void regReceive(address_type addr, transaction_id_type trans_id, reg_type value) {
        auto request = requests.popRead(trans_id);
        assert(addr == request.address);
        scheduleEvent(1, [=, callback=move(nonstd::get<std::function<void(reg_type)>>(request.callback))](Event&) {
            callback(value);
        }, this->name + "regReceive");
    }

    void memReceive(address_type addr, transaction_id_type trans_id, data_type value) {
        auto request = requests.popRead(trans_id);
        assert(addr == request.address);
        scheduleEvent(1, [=, callback=move(nonstd::get<std::function<void(const data_type&)>>(request.callback))](Event&) {
            callback(value);
        }, this->name + "memReceive");
    }

protected:
    void scheduleEvent(tick_offset_type offset, event_handler_type handler, std::string event_debug_message = "unknown") {
        event_queue.emplace(offset, std::move(handler), nullptr, std::move(event_debug_message));
    }

    void scheduleEvent(tick_offset_type offset, event_handler_type handler, owner<message_type*> message, std::string event_debug_message = "unknown") {
        event_queue.emplace(offset, std::move(handler), message, std::move(event_debug_message));
    }

	void addWaitingEvent(hw_id_type hw_id, dep_count_type init_count, tick_offset_type offset, event_handler_type handler, std::string event_debug_message = "unknown") {
		event_queue.add_dep_event(hw_id, init_count, offset, std::move(handler), std::move(event_debug_message));
	}

	bool hwWaiting(hw_id_type hw_id) {
		return event_queue.hw_waiting(hw_id);
	}

	void finishDependency(hw_id_type hw_id) {
		event_queue.decrement_dep_count(hw_id);
	}
};

std::ostream& operator<<(std::ostream& os, const SimObject::data_type& obj);
