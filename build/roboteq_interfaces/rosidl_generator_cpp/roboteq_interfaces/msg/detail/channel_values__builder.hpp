// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__BUILDER_HPP_
#define ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__BUILDER_HPP_

#include "roboteq_interfaces/msg/detail/channel_values__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace roboteq_interfaces
{

namespace msg
{

namespace builder
{

class Init_ChannelValues_value
{
public:
  explicit Init_ChannelValues_value(::roboteq_interfaces::msg::ChannelValues & msg)
  : msg_(msg)
  {}
  ::roboteq_interfaces::msg::ChannelValues value(::roboteq_interfaces::msg::ChannelValues::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roboteq_interfaces::msg::ChannelValues msg_;
};

class Init_ChannelValues_header
{
public:
  Init_ChannelValues_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChannelValues_value header(::roboteq_interfaces::msg::ChannelValues::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ChannelValues_value(msg_);
  }

private:
  ::roboteq_interfaces::msg::ChannelValues msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::roboteq_interfaces::msg::ChannelValues>()
{
  return roboteq_interfaces::msg::builder::Init_ChannelValues_header();
}

}  // namespace roboteq_interfaces

#endif  // ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__BUILDER_HPP_
