// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roboteq_interfaces:srv/Config.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_HPP_
#define ROBOTEQ_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__roboteq_interfaces__srv__Config_Request __attribute__((deprecated))
#else
# define DEPRECATED__roboteq_interfaces__srv__Config_Request __declspec(deprecated)
#endif

namespace roboteq_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Config_Request_
{
  using Type = Config_Request_<ContainerAllocator>;

  explicit Config_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_input = "";
      this->channel = 0ll;
      this->value = 0ll;
    }
  }

  explicit Config_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : user_input(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_input = "";
      this->channel = 0ll;
      this->value = 0ll;
    }
  }

  // field types and members
  using _user_input_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _user_input_type user_input;
  using _channel_type =
    int64_t;
  _channel_type channel;
  using _value_type =
    int64_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__user_input(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->user_input = _arg;
    return *this;
  }
  Type & set__channel(
    const int64_t & _arg)
  {
    this->channel = _arg;
    return *this;
  }
  Type & set__value(
    const int64_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roboteq_interfaces::srv::Config_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const roboteq_interfaces::srv::Config_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Config_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Config_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roboteq_interfaces__srv__Config_Request
    std::shared_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roboteq_interfaces__srv__Config_Request
    std::shared_ptr<roboteq_interfaces::srv::Config_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Config_Request_ & other) const
  {
    if (this->user_input != other.user_input) {
      return false;
    }
    if (this->channel != other.channel) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Config_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Config_Request_

// alias to use template instance with default allocator
using Config_Request =
  roboteq_interfaces::srv::Config_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roboteq_interfaces


#ifndef _WIN32
# define DEPRECATED__roboteq_interfaces__srv__Config_Response __attribute__((deprecated))
#else
# define DEPRECATED__roboteq_interfaces__srv__Config_Response __declspec(deprecated)
#endif

namespace roboteq_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Config_Response_
{
  using Type = Config_Response_<ContainerAllocator>;

  explicit Config_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit Config_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    roboteq_interfaces::srv::Config_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const roboteq_interfaces::srv::Config_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Config_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roboteq_interfaces::srv::Config_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roboteq_interfaces__srv__Config_Response
    std::shared_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roboteq_interfaces__srv__Config_Response
    std::shared_ptr<roboteq_interfaces::srv::Config_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Config_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Config_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Config_Response_

// alias to use template instance with default allocator
using Config_Response =
  roboteq_interfaces::srv::Config_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roboteq_interfaces

namespace roboteq_interfaces
{

namespace srv
{

struct Config
{
  using Request = roboteq_interfaces::srv::Config_Request;
  using Response = roboteq_interfaces::srv::Config_Response;
};

}  // namespace srv

}  // namespace roboteq_interfaces

#endif  // ROBOTEQ_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_HPP_
