#include "include/hsa.h"
#include <cmath>

#include "src/client/client.h"

extern "C" {

struct rhsaQueue {
  uint32_t features;

  void * base_address;
  uint32_t reserved0;

  uint64_t doorbell_signal;
  uint32_t size;
  uint32_t reserved1;
  uint64_t id;
};

bool isPowerOfTwo(uint32_t val) {
  double exp = 1;
  uint32_t twoPow = (uint32_t) std::pow(2, exp);
  while(val < twoPow) {
    exp++;
    twoPow = (uint32_t) std::pow(2, exp);
  }

  if (val == twoPow) {
    return true;
  } else {
    return false;
  }
}

hsa_status_t hsa_queue_create(
    hsa_agent_t agent, uint32_t size, hsa_queue_type32_t type,
    void (*callback)(hsa_status_t status, hsa_queue_t *source, void *data),
    void *data, uint32_t private_segment_size, uint32_t group_segment_size,
    hsa_queue_t **queue) {
  // if ((queue == NULL) || (size == 0) || (!isPowerOfTwo(size)) ||
  //     (type < HSA_QUEUE_TYPE_MULTI) || (type > HSA_QUEUE_TYPE_SINGLE)) {
  //   return HSA_STATUS_ERROR_INVALID_ARGUMENT;
  // }

  struct rhsaQueue newQueue = {.features = 0,
                          .base_address = 0,
                          .reserved0 = 0,
                          .doorbell_signal = 0,
                          .size = 0,
                          .reserved1 = 0,
                          .id = 0};
  *queue = (hsa_queue_t *) &newQueue;

  return HSA_STATUS_SUCCESS;
}
}
