// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice

#ifndef ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__FUNCTIONS_H_
#define ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "roboteq_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "roboteq_interfaces/msg/detail/channel_values__struct.h"

/// Initialize msg/ChannelValues message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * roboteq_interfaces__msg__ChannelValues
 * )) before or use
 * roboteq_interfaces__msg__ChannelValues__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
bool
roboteq_interfaces__msg__ChannelValues__init(roboteq_interfaces__msg__ChannelValues * msg);

/// Finalize msg/ChannelValues message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
void
roboteq_interfaces__msg__ChannelValues__fini(roboteq_interfaces__msg__ChannelValues * msg);

/// Create msg/ChannelValues message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * roboteq_interfaces__msg__ChannelValues__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
roboteq_interfaces__msg__ChannelValues *
roboteq_interfaces__msg__ChannelValues__create();

/// Destroy msg/ChannelValues message.
/**
 * It calls
 * roboteq_interfaces__msg__ChannelValues__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
void
roboteq_interfaces__msg__ChannelValues__destroy(roboteq_interfaces__msg__ChannelValues * msg);

/// Check for msg/ChannelValues message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
bool
roboteq_interfaces__msg__ChannelValues__are_equal(const roboteq_interfaces__msg__ChannelValues * lhs, const roboteq_interfaces__msg__ChannelValues * rhs);

/// Copy a msg/ChannelValues message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
bool
roboteq_interfaces__msg__ChannelValues__copy(
  const roboteq_interfaces__msg__ChannelValues * input,
  roboteq_interfaces__msg__ChannelValues * output);

/// Initialize array of msg/ChannelValues messages.
/**
 * It allocates the memory for the number of elements and calls
 * roboteq_interfaces__msg__ChannelValues__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
bool
roboteq_interfaces__msg__ChannelValues__Sequence__init(roboteq_interfaces__msg__ChannelValues__Sequence * array, size_t size);

/// Finalize array of msg/ChannelValues messages.
/**
 * It calls
 * roboteq_interfaces__msg__ChannelValues__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
void
roboteq_interfaces__msg__ChannelValues__Sequence__fini(roboteq_interfaces__msg__ChannelValues__Sequence * array);

/// Create array of msg/ChannelValues messages.
/**
 * It allocates the memory for the array and calls
 * roboteq_interfaces__msg__ChannelValues__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
roboteq_interfaces__msg__ChannelValues__Sequence *
roboteq_interfaces__msg__ChannelValues__Sequence__create(size_t size);

/// Destroy array of msg/ChannelValues messages.
/**
 * It calls
 * roboteq_interfaces__msg__ChannelValues__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
void
roboteq_interfaces__msg__ChannelValues__Sequence__destroy(roboteq_interfaces__msg__ChannelValues__Sequence * array);

/// Check for msg/ChannelValues message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
bool
roboteq_interfaces__msg__ChannelValues__Sequence__are_equal(const roboteq_interfaces__msg__ChannelValues__Sequence * lhs, const roboteq_interfaces__msg__ChannelValues__Sequence * rhs);

/// Copy an array of msg/ChannelValues messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_roboteq_interfaces
bool
roboteq_interfaces__msg__ChannelValues__Sequence__copy(
  const roboteq_interfaces__msg__ChannelValues__Sequence * input,
  roboteq_interfaces__msg__ChannelValues__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROBOTEQ_INTERFACES__MSG__DETAIL__CHANNEL_VALUES__FUNCTIONS_H_
