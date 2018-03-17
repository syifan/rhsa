#include <iostream>

#include "include/hsa.h"

#include "src/client/client.h"
#include "src/request/request.h"

extern "C" {
 
hsa_status_t hsa_iterate_agents(
  hsa_status_t (*callback)(hsa_agent_t agent, void *data), 
  void *data
) {
  using namespace rhsa;

  auto &client = Client::GetInstance();

  auto query_req = std::make_unique<QueryAgentRequest>();
  client.conn->Send(query_req.get());

  auto req = client.conn->Recv();
  std::cout << "Req received: " << req->GetPayloadCase() << "\n";

  std::cout << "Iterating agents\n";
  return HSA_STATUS_SUCCESS; 
}

}
