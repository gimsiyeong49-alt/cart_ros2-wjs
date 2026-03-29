// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from roboteq_interfaces:srv/Maintenance.idl
// generated code does not contain a copyright notice
#include "roboteq_interfaces/srv/detail/maintenance__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "roboteq_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roboteq_interfaces/srv/detail/maintenance__struct.h"
#include "roboteq_interfaces/srv/detail/maintenance__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // user_input
#include "rosidl_runtime_c/string_functions.h"  // user_input

// forward declare type support functions


using _Maintenance_Request__ros_msg_type = roboteq_interfaces__srv__Maintenance_Request;

static bool _Maintenance_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Maintenance_Request__ros_msg_type * ros_message = static_cast<const _Maintenance_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: user_input
  {
    const rosidl_runtime_c__String * str = &ros_message->user_input;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Maintenance_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Maintenance_Request__ros_msg_type * ros_message = static_cast<_Maintenance_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: user_input
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->user_input.data) {
      rosidl_runtime_c__String__init(&ros_message->user_input);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->user_input,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'user_input'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roboteq_interfaces
size_t get_serialized_size_roboteq_interfaces__srv__Maintenance_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Maintenance_Request__ros_msg_type * ros_message = static_cast<const _Maintenance_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name user_input
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->user_input.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Maintenance_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roboteq_interfaces__srv__Maintenance_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roboteq_interfaces
size_t max_serialized_size_roboteq_interfaces__srv__Maintenance_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: user_input
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Maintenance_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_roboteq_interfaces__srv__Maintenance_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Maintenance_Request = {
  "roboteq_interfaces::srv",
  "Maintenance_Request",
  _Maintenance_Request__cdr_serialize,
  _Maintenance_Request__cdr_deserialize,
  _Maintenance_Request__get_serialized_size,
  _Maintenance_Request__max_serialized_size
};

static rosidl_message_type_support_t _Maintenance_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Maintenance_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roboteq_interfaces, srv, Maintenance_Request)() {
  return &_Maintenance_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "roboteq_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "roboteq_interfaces/srv/detail/maintenance__struct.h"
// already included above
// #include "roboteq_interfaces/srv/detail/maintenance__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // result
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // result

// forward declare type support functions


using _Maintenance_Response__ros_msg_type = roboteq_interfaces__srv__Maintenance_Response;

static bool _Maintenance_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Maintenance_Response__ros_msg_type * ros_message = static_cast<const _Maintenance_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    const rosidl_runtime_c__String * str = &ros_message->result;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _Maintenance_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Maintenance_Response__ros_msg_type * ros_message = static_cast<_Maintenance_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: result
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->result.data) {
      rosidl_runtime_c__String__init(&ros_message->result);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->result,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'result'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roboteq_interfaces
size_t get_serialized_size_roboteq_interfaces__srv__Maintenance_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Maintenance_Response__ros_msg_type * ros_message = static_cast<const _Maintenance_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name result
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->result.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Maintenance_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roboteq_interfaces__srv__Maintenance_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roboteq_interfaces
size_t max_serialized_size_roboteq_interfaces__srv__Maintenance_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: result
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Maintenance_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_roboteq_interfaces__srv__Maintenance_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Maintenance_Response = {
  "roboteq_interfaces::srv",
  "Maintenance_Response",
  _Maintenance_Response__cdr_serialize,
  _Maintenance_Response__cdr_deserialize,
  _Maintenance_Response__get_serialized_size,
  _Maintenance_Response__max_serialized_size
};

static rosidl_message_type_support_t _Maintenance_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Maintenance_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roboteq_interfaces, srv, Maintenance_Response)() {
  return &_Maintenance_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "roboteq_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roboteq_interfaces/srv/maintenance.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Maintenance__callbacks = {
  "roboteq_interfaces::srv",
  "Maintenance",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roboteq_interfaces, srv, Maintenance_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roboteq_interfaces, srv, Maintenance_Response)(),
};

static rosidl_service_type_support_t Maintenance__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Maintenance__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roboteq_interfaces, srv, Maintenance)() {
  return &Maintenance__handle;
}

#if defined(__cplusplus)
}
#endif
