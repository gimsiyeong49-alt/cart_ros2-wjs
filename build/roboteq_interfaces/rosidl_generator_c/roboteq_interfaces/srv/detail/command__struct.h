// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roboteq_interfaces:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__SRV__DETAIL__COMMAND__STRUCT_H_
#define ROBOTEQ_INTERFACES__SRV__DETAIL__COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'user_input'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/Command in the package roboteq_interfaces.
typedef struct roboteq_interfaces__srv__Command_Request
{
  rosidl_runtime_c__String user_input;
  int64_t channel;
  int64_t value;
} roboteq_interfaces__srv__Command_Request;

// Struct for a sequence of roboteq_interfaces__srv__Command_Request.
typedef struct roboteq_interfaces__srv__Command_Request__Sequence
{
  roboteq_interfaces__srv__Command_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roboteq_interfaces__srv__Command_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/Command in the package roboteq_interfaces.
typedef struct roboteq_interfaces__srv__Command_Response
{
  rosidl_runtime_c__String result;
} roboteq_interfaces__srv__Command_Response;

// Struct for a sequence of roboteq_interfaces__srv__Command_Response.
typedef struct roboteq_interfaces__srv__Command_Response__Sequence
{
  roboteq_interfaces__srv__Command_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roboteq_interfaces__srv__Command_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTEQ_INTERFACES__SRV__DETAIL__COMMAND__STRUCT_H_
