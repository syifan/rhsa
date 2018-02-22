#include <iostream>

#include "include/hsa.h"

extern "C" {
 
hsa_status_t hsa_iterate_agents(
  hsa_status_t (*callback)(hsa_agent_t agent, void *data), 
  void *data
) {
  std::cout << "Iterating agents\n";
  return HSA_STATUS_SUCCESS; 
}

}
