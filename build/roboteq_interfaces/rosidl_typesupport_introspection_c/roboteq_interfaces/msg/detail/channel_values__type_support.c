// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roboteq_interfaces/msg/detail/channel_values__rosidl_typesupport_introspection_c.h"
#include "roboteq_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roboteq_interfaces/msg/detail/channel_values__functions.h"
#include "roboteq_interfaces/msg/detail/channel_values__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `value`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roboteq_interfaces__msg__ChannelValues__init(message_memory);
}

void ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_fini_function(void * message_memory)
{
  roboteq_interfaces__msg__ChannelValues__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces__msg__ChannelValues, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces__msg__ChannelValues, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_members = {
  "roboteq_interfaces__msg",  // message namespace
  "ChannelValues",  // message name
  2,  // number of fields
  sizeof(roboteq_interfaces__msg__ChannelValues),
  ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_member_array,  // message members
  ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_init_function,  // function to initialize message memory (memory has to be allocated)
  ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_type_support_handle = {
  0,
  &ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roboteq_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, msg, ChannelValues)() {
  ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_type_support_handle.typesupport_identifier) {
    ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ChannelValues__rosidl_typesupport_introspection_c__ChannelValues_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
