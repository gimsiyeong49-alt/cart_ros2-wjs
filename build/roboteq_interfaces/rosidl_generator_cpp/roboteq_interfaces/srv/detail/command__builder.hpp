// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roboteq_interfaces:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__SRV__DETAIL__COMMAND__BUILDER_HPP_
#define ROBOTEQ_INTERFACES__SRV__DETAIL__COMMAND__BUILDER_HPP_

#include "roboteq_interfaces/srv/detail/command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace roboteq_interfaces
{

namespace srv
{

namespace builder
{

class Init_Command_Request_value
{
public:
  explicit Init_Command_Request_value(::roboteq_interfaces::srv::Command_Request & msg)
  : msg_(msg)
  {}
  ::roboteq_interfaces::srv::Command_Request value(::roboteq_interfaces::srv::Command_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roboteq_interfaces::srv::Command_Request msg_;
};

class Init_Command_Request_channel
{
public:
  explicit Init_Command_Request_channel(::roboteq_interfaces::srv::Command_Request & msg)
  : msg_(msg)
  {}
  Init_Command_Request_value channel(::roboteq_interfaces::srv::Command_Request::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_Command_Request_value(msg_);
  }

private:
  ::roboteq_interfaces::srv::Command_Request msg_;
};

class Init_Command_Request_user_input
{
public:
  Init_Command_Request_user_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Command_Request_channel user_input(::roboteq_interfaces::srv::Command_Request::_user_input_type arg)
  {
    msg_.user_input = std::move(arg);
    return Init_Command_Request_channel(msg_);
  }

private:
  ::roboteq_interfaces::srv::Command_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roboteq_interfaces::srv::Command_Request>()
{
  return roboteq_interfaces::srv::builder::Init_Command_Request_user_input();
}

}  // namespace roboteq_interfaces


namespace roboteq_interfaces
{

namespace srv
{

namespace builder
{

class Init_Command_Response_result
{
public:
  Init_Command_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::roboteq_interfaces::srv::Command_Response result(::roboteq_interfaces::srv::Command_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roboteq_interfaces::srv::Command_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roboteq_interfaces::srv::Command_Response>()
{
  return roboteq_interfaces::srv::builder::Init_Command_Response_result();
}

}  // namespace roboteq_interfaces

#endif  // ROBOTEQ_INTERFACES__SRV__DETAIL__COMMAND__BUILDER_HPP_
