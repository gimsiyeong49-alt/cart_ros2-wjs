// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from roboteq_interfaces:srv/Config.idl
// generated code does not contain a copyright notice
#include "roboteq_interfaces/srv/detail/config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include directives for member types
// Member `user_input`
#include "rosidl_runtime_c/string_functions.h"

bool
roboteq_interfaces__srv__Config_Request__init(roboteq_interfaces__srv__Config_Request * msg)
{
  if (!msg) {
    return false;
  }
  // user_input
  if (!rosidl_runtime_c__String__init(&msg->user_input)) {
    roboteq_interfaces__srv__Config_Request__fini(msg);
    return false;
  }
  // channel
  // value
  return true;
}

void
roboteq_interfaces__srv__Config_Request__fini(roboteq_interfaces__srv__Config_Request * msg)
{
  if (!msg) {
    return;
  }
  // user_input
  rosidl_runtime_c__String__fini(&msg->user_input);
  // channel
  // value
}

bool
roboteq_interfaces__srv__Config_Request__are_equal(const roboteq_interfaces__srv__Config_Request * lhs, const roboteq_interfaces__srv__Config_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // user_input
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->user_input), &(rhs->user_input)))
  {
    return false;
  }
  // channel
  if (lhs->channel != rhs->channel) {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
roboteq_interfaces__srv__Config_Request__copy(
  const roboteq_interfaces__srv__Config_Request * input,
  roboteq_interfaces__srv__Config_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // user_input
  if (!rosidl_runtime_c__String__copy(
      &(input->user_input), &(output->user_input)))
  {
    return false;
  }
  // channel
  output->channel = input->channel;
  // value
  output->value = input->value;
  return true;
}

roboteq_interfaces__srv__Config_Request *
roboteq_interfaces__srv__Config_Request__create()
{
  roboteq_interfaces__srv__Config_Request * msg = (roboteq_interfaces__srv__Config_Request *)malloc(sizeof(roboteq_interfaces__srv__Config_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roboteq_interfaces__srv__Config_Request));
  bool success = roboteq_interfaces__srv__Config_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
roboteq_interfaces__srv__Config_Request__destroy(roboteq_interfaces__srv__Config_Request * msg)
{
  if (msg) {
    roboteq_interfaces__srv__Config_Request__fini(msg);
  }
  free(msg);
}


bool
roboteq_interfaces__srv__Config_Request__Sequence__init(roboteq_interfaces__srv__Config_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  roboteq_interfaces__srv__Config_Request * data = NULL;
  if (size) {
    data = (roboteq_interfaces__srv__Config_Request *)calloc(size, sizeof(roboteq_interfaces__srv__Config_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roboteq_interfaces__srv__Config_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roboteq_interfaces__srv__Config_Request__fini(&data[i - 1]);
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
roboteq_interfaces__srv__Config_Request__Sequence__fini(roboteq_interfaces__srv__Config_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roboteq_interfaces__srv__Config_Request__fini(&array->data[i]);
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

roboteq_interfaces__srv__Config_Request__Sequence *
roboteq_interfaces__srv__Config_Request__Sequence__create(size_t size)
{
  roboteq_interfaces__srv__Config_Request__Sequence * array = (roboteq_interfaces__srv__Config_Request__Sequence *)malloc(sizeof(roboteq_interfaces__srv__Config_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = roboteq_interfaces__srv__Config_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
roboteq_interfaces__srv__Config_Request__Sequence__destroy(roboteq_interfaces__srv__Config_Request__Sequence * array)
{
  if (array) {
    roboteq_interfaces__srv__Config_Request__Sequence__fini(array);
  }
  free(array);
}

bool
roboteq_interfaces__srv__Config_Request__Sequence__are_equal(const roboteq_interfaces__srv__Config_Request__Sequence * lhs, const roboteq_interfaces__srv__Config_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roboteq_interfaces__srv__Config_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roboteq_interfaces__srv__Config_Request__Sequence__copy(
  const roboteq_interfaces__srv__Config_Request__Sequence * input,
  roboteq_interfaces__srv__Config_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(roboteq_interfaces__srv__Config_Request);
    roboteq_interfaces__srv__Config_Request * data =
      (roboteq_interfaces__srv__Config_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roboteq_interfaces__srv__Config_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          roboteq_interfaces__srv__Config_Request__fini(&data[i]);
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
    if (!roboteq_interfaces__srv__Config_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
roboteq_interfaces__srv__Config_Response__init(roboteq_interfaces__srv__Config_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    roboteq_interfaces__srv__Config_Response__fini(msg);
    return false;
  }
  return true;
}

void
roboteq_interfaces__srv__Config_Response__fini(roboteq_interfaces__srv__Config_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
roboteq_interfaces__srv__Config_Response__are_equal(const roboteq_interfaces__srv__Config_Response * lhs, const roboteq_interfaces__srv__Config_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
roboteq_interfaces__srv__Config_Response__copy(
  const roboteq_interfaces__srv__Config_Response * input,
  roboteq_interfaces__srv__Config_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

roboteq_interfaces__srv__Config_Response *
roboteq_interfaces__srv__Config_Response__create()
{
  roboteq_interfaces__srv__Config_Response * msg = (roboteq_interfaces__srv__Config_Response *)malloc(sizeof(roboteq_interfaces__srv__Config_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(roboteq_interfaces__srv__Config_Response));
  bool success = roboteq_interfaces__srv__Config_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
roboteq_interfaces__srv__Config_Response__destroy(roboteq_interfaces__srv__Config_Response * msg)
{
  if (msg) {
    roboteq_interfaces__srv__Config_Response__fini(msg);
  }
  free(msg);
}


bool
roboteq_interfaces__srv__Config_Response__Sequence__init(roboteq_interfaces__srv__Config_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  roboteq_interfaces__srv__Config_Response * data = NULL;
  if (size) {
    data = (roboteq_interfaces__srv__Config_Response *)calloc(size, sizeof(roboteq_interfaces__srv__Config_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = roboteq_interfaces__srv__Config_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        roboteq_interfaces__srv__Config_Response__fini(&data[i - 1]);
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
roboteq_interfaces__srv__Config_Response__Sequence__fini(roboteq_interfaces__srv__Config_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      roboteq_interfaces__srv__Config_Response__fini(&array->data[i]);
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

roboteq_interfaces__srv__Config_Response__Sequence *
roboteq_interfaces__srv__Config_Response__Sequence__create(size_t size)
{
  roboteq_interfaces__srv__Config_Response__Sequence * array = (roboteq_interfaces__srv__Config_Response__Sequence *)malloc(sizeof(roboteq_interfaces__srv__Config_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = roboteq_interfaces__srv__Config_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
roboteq_interfaces__srv__Config_Response__Sequence__destroy(roboteq_interfaces__srv__Config_Response__Sequence * array)
{
  if (array) {
    roboteq_interfaces__srv__Config_Response__Sequence__fini(array);
  }
  free(array);
}

bool
roboteq_interfaces__srv__Config_Response__Sequence__are_equal(const roboteq_interfaces__srv__Config_Response__Sequence * lhs, const roboteq_interfaces__srv__Config_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!roboteq_interfaces__srv__Config_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
roboteq_interfaces__srv__Config_Response__Sequence__copy(
  const roboteq_interfaces__srv__Config_Response__Sequence * input,
  roboteq_interfaces__srv__Config_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(roboteq_interfaces__srv__Config_Response);
    roboteq_interfaces__srv__Config_Response * data =
      (roboteq_interfaces__srv__Config_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!roboteq_interfaces__srv__Config_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          roboteq_interfaces__srv__Config_Response__fini(&data[i]);
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
    if (!roboteq_interfaces__srv__Config_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
