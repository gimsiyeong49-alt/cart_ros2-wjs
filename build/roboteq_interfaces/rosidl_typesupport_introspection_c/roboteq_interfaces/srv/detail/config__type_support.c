// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from roboteq_interfaces:srv/Config.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "roboteq_interfaces/srv/detail/config__rosidl_typesupport_introspection_c.h"
#include "roboteq_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "roboteq_interfaces/srv/detail/config__functions.h"
#include "roboteq_interfaces/srv/detail/config__struct.h"


// Include directives for member types
// Member `user_input`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Config_Request__rosidl_typesupport_introspection_c__Config_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roboteq_interfaces__srv__Config_Request__init(message_memory);
}

void Config_Request__rosidl_typesupport_introspection_c__Config_Request_fini_function(void * message_memory)
{
  roboteq_interfaces__srv__Config_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_member_array[3] = {
  {
    "user_input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces__srv__Config_Request, user_input),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "channel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces__srv__Config_Request, channel),  // bytes offset in struct
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
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces__srv__Config_Request, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_members = {
  "roboteq_interfaces__srv",  // message namespace
  "Config_Request",  // message name
  3,  // number of fields
  sizeof(roboteq_interfaces__srv__Config_Request),
  Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_member_array,  // message members
  Config_Request__rosidl_typesupport_introspection_c__Config_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Config_Request__rosidl_typesupport_introspection_c__Config_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_type_support_handle = {
  0,
  &Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roboteq_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config_Request)() {
  if (!Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_type_support_handle.typesupport_identifier) {
    Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Config_Request__rosidl_typesupport_introspection_c__Config_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "roboteq_interfaces/srv/detail/config__rosidl_typesupport_introspection_c.h"
// already included above
// #include "roboteq_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "roboteq_interfaces/srv/detail/config__functions.h"
// already included above
// #include "roboteq_interfaces/srv/detail/config__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Config_Response__rosidl_typesupport_introspection_c__Config_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  roboteq_interfaces__srv__Config_Response__init(message_memory);
}

void Config_Response__rosidl_typesupport_introspection_c__Config_Response_fini_function(void * message_memory)
{
  roboteq_interfaces__srv__Config_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(roboteq_interfaces__srv__Config_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_members = {
  "roboteq_interfaces__srv",  // message namespace
  "Config_Response",  // message name
  1,  // number of fields
  sizeof(roboteq_interfaces__srv__Config_Response),
  Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_member_array,  // message members
  Config_Response__rosidl_typesupport_introspection_c__Config_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Config_Response__rosidl_typesupport_introspection_c__Config_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_type_support_handle = {
  0,
  &Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roboteq_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config_Response)() {
  if (!Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_type_support_handle.typesupport_identifier) {
    Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Config_Response__rosidl_typesupport_introspection_c__Config_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "roboteq_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "roboteq_interfaces/srv/detail/config__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_members = {
  "roboteq_interfaces__srv",  // service namespace
  "Config",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_Request_message_type_support_handle,
  NULL  // response message
  // roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_Response_message_type_support_handle
};

static rosidl_service_type_support_t roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_type_support_handle = {
  0,
  &roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_roboteq_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config)() {
  if (!roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_type_support_handle.typesupport_identifier) {
    roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, roboteq_interfaces, srv, Config_Response)()->data;
  }

  return &roboteq_interfaces__srv__detail__config__rosidl_typesupport_introspection_c__Config_service_type_support_handle;
}
