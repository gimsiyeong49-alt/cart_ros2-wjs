// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__TRAITS_HPP_
#define ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__TRAITS_HPP_

#include "roboteq_interfaces/msg/detail/channel_values__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const roboteq_interfaces::msg::ChannelValues & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.value.size() == 0) {
      out << "value: []\n";
    } else {
      out << "value:\n";
      for (auto item : msg.value) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const roboteq_interfaces::msg::ChannelValues & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<roboteq_interfaces::msg::ChannelValues>()
{
  return "roboteq_interfaces::msg::ChannelValues";
}

template<>
inline const char * name<roboteq_interfaces::msg::ChannelValues>()
{
  return "roboteq_interfaces/msg/ChannelValues";
}

template<>
struct has_fixed_size<roboteq_interfaces::msg::ChannelValues>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roboteq_interfaces::msg::ChannelValues>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roboteq_interfaces::msg::ChannelValues>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__TRAITS_HPP_
