// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__STRUCT_HPP_
#define ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__roboteq_interfaces__msg__ChannelValues __attribute__((deprecated))
#else
# define DEPRECATED__roboteq_interfaces__msg__ChannelValues __declspec(deprecated)
#endif

namespace roboteq_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ChannelValues_
{
  using Type = ChannelValues_<ContainerAllocator>;

  explicit ChannelValues_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit ChannelValues_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _value_type =
    std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>>;
  _value_type value;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__value(
    const std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>> & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roboteq_interfaces::msg::ChannelValues_<ContainerAllocator> *;
  using ConstRawPtr =
    const roboteq_interfaces::msg::ChannelValues_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::msg::ChannelValues_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::msg::ChannelValues_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roboteq_interfaces__msg__ChannelValues
    std::shared_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roboteq_interfaces__msg__ChannelValues
    std::shared_ptr<roboteq_interfaces::msg::ChannelValues_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChannelValues_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChannelValues_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChannelValues_

// alias to use template instance with default allocator
using ChannelValues =
  roboteq_interfaces::msg::ChannelValues_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace roboteq_interfaces

#endif  // ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__STRUCT_HPP_
