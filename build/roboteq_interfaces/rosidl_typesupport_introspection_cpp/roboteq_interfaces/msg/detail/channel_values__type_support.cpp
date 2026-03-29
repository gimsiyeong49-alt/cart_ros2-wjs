// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "roboteq_interfaces/msg/detail/channel_values__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace roboteq_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ChannelValues_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) roboteq_interfaces::msg::ChannelValues(_init);
}

void ChannelValues_fini_function(void * message_memory)
{
  auto typed_message = static_cast<roboteq_interfaces::msg::ChannelValues *>(message_memory);
  typed_message->~ChannelValues();
}

size_t size_function__ChannelValues__value(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ChannelValues__value(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void * get_function__ChannelValues__value(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void resize_function__ChannelValues__value(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ChannelValues_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces::msg::ChannelValues, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces::msg::ChannelValues, value),  // bytes offset in struct
    nullptr,  // default value
    size_function__ChannelValues__value,  // size() function pointer
    get_const_function__ChannelValues__value,  // get_const(index) function pointer
    get_function__ChannelValues__value,  // get(index) function pointer
    resize_function__ChannelValues__value  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ChannelValues_message_members = {
  "roboteq_interfaces::msg",  // message namespace
  "ChannelValues",  // message name
  2,  // number of fields
  sizeof(roboteq_interfaces::msg::ChannelValues),
  ChannelValues_message_member_array,  // message members
  ChannelValues_init_function,  // function to initialize message memory (memory has to be allocated)
  ChannelValues_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ChannelValues_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ChannelValues_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace roboteq_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<roboteq_interfaces::msg::ChannelValues>()
{
  return &::roboteq_interfaces::msg::rosidl_typesupport_introspection_cpp::ChannelValues_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, roboteq_interfaces, msg, ChannelValues)() {
  return &::roboteq_interfaces::msg::rosidl_typesupport_introspection_cpp::ChannelValues_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
