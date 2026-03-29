// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roboteq_interfaces:msg/ChannelValues.idl
// generated code does not contain a copyright notice
#include "roboteq_interfaces/msg/detail/channel_values__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `value`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
roboteq_interfaces__msg__ChannelValues__init(roboteq_interfaces__msg__ChannelValues * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    roboteq_interfaces__msg__ChannelValues__fini(msg);
    return false;
  }
  // value
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->value, 0)) {
    roboteq_interfaces__msg__ChannelValues__fini(msg);
    return false;
  }
  return true;
}

void
roboteq_interfaces__msg__ChannelValues__fini(roboteq_interfaces__msg__ChannelValues * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // value
  rosidl_runtime_c__int64__Sequence__fini(&msg->value);
}

bool
roboteq_interfaces__msg__ChannelValues__are_equal(const roboteq_interfaces__msg__ChannelValues * lhs, const roboteq_interfaces__msg__ChannelValues * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // value
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->value), &(rhs->value)))
  {
    return false;
  }
  return true;
}

bool
roboteq_interfaces__msg__ChannelValues__copy(
  const roboteq_interfaces__msg__ChannelValues * input,
  roboteq_interfaces__msg__ChannelValues * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // value
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->value), &(output->value)))
  {
    return false;
  }
  return true;
}

roboteq_interfaces__msg__ChannelValues *
roboteq_interfaces__msg__ChannelValues__create()
{
  roboteq_interfaces__msg__ChannelValues * msg = (roboteq_interfaces__msg__ChannelValues *)malloc(sizeof(roboteq_interfaces__msg__ChannelValues));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roboteq_interfaces__msg__ChannelValues));
  bool success = roboteq_interfaces__msg__ChannelValues__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
roboteq_interfaces__msg__ChannelValues__destroy(roboteq_interfaces__msg__ChannelValues * msg)
{
  if (msg) {
    roboteq_interfaces__msg__ChannelValues__fini(msg);
  }
  free(msg);
}


bool
roboteq_interfaces__msg__ChannelValues__Sequence__init(roboteq_interfaces__msg__ChannelValues__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  roboteq_interfaces__msg__ChannelValues * data = NULL;
  if (size) {
    data = (roboteq_interfaces__msg__ChannelValues *)calloc(size, sizeof(roboteq_interfaces__msg__ChannelValues));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roboteq_interfaces__msg__ChannelValues__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roboteq_interfaces__msg__ChannelValues__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
roboteq_interfaces__msg__ChannelValues__Sequence__fini(roboteq_interfaces__msg__ChannelValues__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roboteq_interfaces__msg__ChannelValues__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

roboteq_interfaces__msg__ChannelValues__Sequence *
roboteq_interfaces__msg__ChannelValues__Sequence__create(size_t size)
{
  roboteq_interfaces__msg__ChannelValues__Sequence * array = (roboteq_interfaces__msg__ChannelValues__Sequence *)malloc(sizeof(roboteq_interfaces__msg__ChannelValues__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = roboteq_interfaces__msg__ChannelValues__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
roboteq_interfaces__msg__ChannelValues__Sequence__destroy(roboteq_interfaces__msg__ChannelValues__Sequence * array)
{
  if (array) {
    roboteq_interfaces__msg__ChannelValues__Sequence__fini(array);
  }
  free(array);
}

bool
roboteq_interfaces__msg__ChannelValues__Sequence__are_equal(const roboteq_interfaces__msg__ChannelValues__Sequence * lhs, const roboteq_interfaces__msg__ChannelValues__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roboteq_interfaces__msg__ChannelValues__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roboteq_interfaces__msg__ChannelValues__Sequence__copy(
  const roboteq_interfaces__msg__ChannelValues__Sequence * input,
  roboteq_interfaces__msg__ChannelValues__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(roboteq_interfaces__msg__ChannelValues);
    roboteq_interfaces__msg__ChannelValues * data =
      (roboteq_interfaces__msg__ChannelValues *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roboteq_interfaces__msg__ChannelValues__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          roboteq_interfaces__msg__ChannelValues__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!roboteq_interfaces__msg__ChannelValues__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
