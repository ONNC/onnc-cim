#pragma once

#include <memory>

struct nullopt_t {};
static constexpr nullopt_t nullopt;

template <typename T>
class optional {
public:
  using value_type = T;
  using pointer    = value_type*;
  using reference  = value_type&;

public:
  optional() = default;
  optional(nullopt_t)
    : optional()
  { } 
  optional(const optional& other) {
    if (other) {
      value = std::make_unique<value_type>(*other);
    }
  }
  optional(optional&& other) = default;
  optional(const value_type& value)
    : value{std::make_unique<value_type>(value)}
  { }
  optional(value_type&& value)
    : value{std::make_unique<value_type>(std::move(value))}
  { }
  ~optional() = default;

  optional& operator=(const optional& other) {
    if (other) {
      value = std::make_unique<value_type>(*other);
    } else {
      value.reset(); 
    }
    return *this;
  }
  optional& operator=(optional&& other) = default;
  optional& operator=(const value_type& value) {
    value = std::make_unique<value_type>(value);
    return *this; 
  }
  optional& operator=(value_type&& value) {
    value = std::make_unique<value_type>(std::move(value));
    return *this; 
  }

  pointer operator->() const {
    return value.get(); 
  }

  reference operator*() const {
    return *value; 
  }

  operator bool() const {
    return value != nullptr;
  }

private:
  std::unique_ptr<value_type> value;
};
