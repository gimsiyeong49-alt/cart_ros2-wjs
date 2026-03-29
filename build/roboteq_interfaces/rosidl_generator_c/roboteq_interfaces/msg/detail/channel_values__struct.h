// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__STRUCT_H_
#define ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'value'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/ChannelValues in the package roboteq_interfaces.
typedef struct roboteq_interfaces__msg__ChannelValues
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__int64__Sequence value;
} roboteq_interfaces__msg__ChannelValues;

// Struct for a sequence of roboteq_interfaces__msg__ChannelValues.
typedef struct roboteq_interfaces__msg__ChannelValues__Sequence
{
  roboteq_interfaces__msg__ChannelValues * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roboteq_interfaces__msg__ChannelValues__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__STRUCT_H_
