#ifndef QEMU_HW_NVDLA_REQUEST_POOL_HH_INCLUDED
#define QEMU_HW_NVDLA_REQUEST_POOL_HH_INCLUDED

#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include <unordered_map>

#include "sim-module/nonstd/variant.hpp"

namespace internal {
  template <typename T>
  using callback_arg_type = typename std::conditional<
    std::is_integral<T>::value,
    T,
    typename std::add_lvalue_reference<typename std::add_const<T>::type>::type
  >::type;

  template <typename... DataTypes>
  using callback_variant_type = nonstd::variant<std::function<void(callback_arg_type<DataTypes>)>...>;

  template <typename Address, typename... DataTypes>
  struct read_request {
    Address                             address; 
    callback_variant_type<DataTypes...> callback;    
  };

  template <typename Address, typename... DataTypes>
  struct write_request {
    Address                       address; 
    nonstd::variant<DataTypes...> value;
  };
} // namespace internal

template <typename Transaction, typename Address, typename... DataTypes>
class RequestPool final {
  static_assert(0 < sizeof...(DataTypes), "should provide at least 1 data type");
  static_assert(std::is_unsigned<Transaction>::value, "Transaction should be unsigned integral type");
  static_assert(std::is_unsigned<Address>::value, "Address should be unsigned integral type");

public:
  using transaction_id_type = Transaction;
  using address_type        = Address;
  using read_request_type   = internal::read_request<address_type, DataTypes...>;
  using write_request_type  = internal::write_request<address_type, DataTypes...>;
  using request_type        = nonstd::variant<read_request_type, write_request_type>;
  using requests_type       = std::unordered_map<transaction_id_type, request_type>;

public:
  template <typename Callback>
  transaction_id_type pushRead(address_type address, Callback&& callback) {
    const auto transaction_id = next_transaction_id++;

    requests.emplace(
      transaction_id,
      read_request_type{address, std::forward<Callback>(callback)}
    );

    return transaction_id;
  }

  template <typename Value>
  transaction_id_type pushWrite(address_type address, Value&& value) {
    const auto transaction_id = next_transaction_id++;

    requests.emplace(
      transaction_id,
      write_request_type{address, std::forward<Value>(value)}
    );

    return transaction_id;
  }

  read_request_type popRead(transaction_id_type transaction_id) {
    assert(isRead(transaction_id));
    return std::move(
      nonstd::get<read_request_type>(pop(transaction_id))
    );
  }

  write_request_type popWrite(transaction_id_type transaction_id) {
    assert(isWrite(transaction_id));
    return std::move(
      nonstd::get<write_request_type>(pop(transaction_id))
    );
  }

  bool isRead(transaction_id_type transaction_id) const {
    const auto found = requests.find(transaction_id);
    if (found == std::end(requests)) {
      return false;
    }

    return found->second.index() == 0;
  }

  bool isWrite(transaction_id_type transaction_id) const {
    return !isRead(transaction_id); 
  }

private:
  request_type pop(transaction_id_type transaction_id) {
    const auto found = requests.find(transaction_id);
    assert(found != std::end(requests));

    request_type request = std::move(found->second);
    requests.erase(transaction_id);
    return std::move(request);
  }

private:  
  requests_type       requests;
  transaction_id_type next_transaction_id = 0;
};

#endif
