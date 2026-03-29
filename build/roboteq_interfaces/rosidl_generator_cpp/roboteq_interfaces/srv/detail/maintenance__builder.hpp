// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roboteq_interfaces:srv/Maintenance.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__BUILDER_HPP_
#define ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__BUILDER_HPP_

#include "roboteq_interfaces/srv/detail/maintenance__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace roboteq_interfaces
{

namespace srv
{

namespace builder
{

class Init_Maintenance_Request_user_input
{
public:
  Init_Maintenance_Request_user_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::roboteq_interfaces::srv::Maintenance_Request user_input(::roboteq_interfaces::srv::Maintenance_Request::_user_input_type arg)
  {
    msg_.user_input = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roboteq_interfaces::srv::Maintenance_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roboteq_interfaces::srv::Maintenance_Request>()
{
  return roboteq_interfaces::srv::builder::Init_Maintenance_Request_user_input();
}

}  // namespace roboteq_interfaces


namespace roboteq_interfaces
{

namespace srv
{

namespace builder
{

class Init_Maintenance_Response_result
{
public:
  Init_Maintenance_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::roboteq_interfaces::srv::Maintenance_Response result(::roboteq_interfaces::srv::Maintenance_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roboteq_interfaces::srv::Maintenance_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roboteq_interfaces::srv::Maintenance_Response>()
{
  return roboteq_interfaces::srv::builder::Init_Maintenance_Response_result();
}

}  // namespace roboteq_interfaces

#endif  // ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__BUILDER_HPP_
