// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roboteq_interfaces:srv/Maintenance.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__STRUCT_HPP_
#define ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__roboteq_interfaces__srv__Maintenance_Request __attribute__((deprecated))
#else
# define DEPRECATED__roboteq_interfaces__srv__Maintenance_Request __declspec(deprecated)
#endif

namespace roboteq_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Maintenance_Request_
{
  using Type = Maintenance_Request_<ContainerAllocator>;

  explicit Maintenance_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_input = "";
    }
  }

  explicit Maintenance_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : user_input(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_input = "";
    }
  }

  // field types and members
  using _user_input_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _user_input_type user_input;

  // setters for named parameter idiom
  Type & set__user_input(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->user_input = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roboteq_interfaces__srv__Maintenance_Request
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roboteq_interfaces__srv__Maintenance_Request
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Maintenance_Request_ & other) const
  {
    if (this->user_input != other.user_input) {
      return false;
    }
    return true;
  }
  bool operator!=(const Maintenance_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Maintenance_Request_

// alias to use template instance with default allocator
using Maintenance_Request =
  roboteq_interfaces::srv::Maintenance_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roboteq_interfaces


#ifndef _WIN32
# define DEPRECATED__roboteq_interfaces__srv__Maintenance_Response __attribute__((deprecated))
#else
# define DEPRECATED__roboteq_interfaces__srv__Maintenance_Response __declspec(deprecated)
#endif

namespace roboteq_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Maintenance_Response_
{
  using Type = Maintenance_Response_<ContainerAllocator>;

  explicit Maintenance_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit Maintenance_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roboteq_interfaces__srv__Maintenance_Response
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roboteq_interfaces__srv__Maintenance_Response
    std::shared_ptr<roboteq_interfaces::srv::Maintenance_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Maintenance_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Maintenance_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Maintenance_Response_

// alias to use template instance with default allocator
using Maintenance_Response =
  roboteq_interfaces::srv::Maintenance_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roboteq_interfaces

namespace roboteq_interfaces
{

namespace srv
{

struct Maintenance
{
  using Request = roboteq_interfaces::srv::Maintenance_Request;
  using Response = roboteq_interfaces::srv::Maintenance_Response;
};

}  // namespace srv

}  // namespace roboteq_interfaces

#endif  // ROBOTEQ_INTERFACES__SRV__DETAIL__MAINTENANCE__STRUCT_HPP_
