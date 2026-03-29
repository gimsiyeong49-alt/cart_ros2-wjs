// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roboteq_interfaces:srv/Maintenance.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__TRAITS_HPP_
#define ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__TRAITS_HPP_

#include "roboteq_interfaces/srv/detail/maintenance__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const roboteq_interfaces::srv::Maintenance_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: user_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "user_input: ";
    value_to_yaml(msg.user_input, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const roboteq_interfaces::srv::Maintenance_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<roboteq_interfaces::srv::Maintenance_Request>()
{
  return "roboteq_interfaces::srv::Maintenance_Request";
}

template<>
inline const char * name<roboteq_interfaces::srv::Maintenance_Request>()
{
  return "roboteq_interfaces/srv/Maintenance_Request";
}

template<>
struct has_fixed_size<roboteq_interfaces::srv::Maintenance_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roboteq_interfaces::srv::Maintenance_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roboteq_interfaces::srv::Maintenance_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const roboteq_interfaces::srv::Maintenance_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const roboteq_interfaces::srv::Maintenance_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<roboteq_interfaces::srv::Maintenance_Response>()
{
  return "roboteq_interfaces::srv::Maintenance_Response";
}

template<>
inline const char * name<roboteq_interfaces::srv::Maintenance_Response>()
{
  return "roboteq_interfaces/srv/Maintenance_Response";
}

template<>
struct has_fixed_size<roboteq_interfaces::srv::Maintenance_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roboteq_interfaces::srv::Maintenance_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roboteq_interfaces::srv::Maintenance_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<roboteq_interfaces::srv::Maintenance>()
{
  return "roboteq_interfaces::srv::Maintenance";
}

template<>
inline const char * name<roboteq_interfaces::srv::Maintenance>()
{
  return "roboteq_interfaces/srv/Maintenance";
}

template<>
struct has_fixed_size<roboteq_interfaces::srv::Maintenance>
  : std::integral_constant<
    bool,
    has_fixed_size<roboteq_interfaces::srv::Maintenance_Request>::value &&
    has_fixed_size<roboteq_interfaces::srv::Maintenance_Response>::value
  >
{
};

template<>
struct has_bounded_size<roboteq_interfaces::srv::Maintenance>
  : std::integral_constant<
    bool,
    has_bounded_size<roboteq_interfaces::srv::Maintenance_Request>::value &&
    has_bounded_size<roboteq_interfaces::srv::Maintenance_Response>::value
  >
{
};

template<>
struct is_service<roboteq_interfaces::srv::Maintenance>
  : std::true_type
{
};

template<>
struct is_service_request<roboteq_interfaces::srv::Maintenance_Request>
  : std::true_type
{
};

template<>
struct is_service_response<roboteq_interfaces::srv::Maintenance_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__TRAITS_HPP_
