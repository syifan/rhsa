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
  auto request_factory = client.request_factory.get();

  auto query_req = request_factory->BuildQueryAgentRequest();
  client.conn->Send(query_req.get());

  auto req = client.conn->Recv();
  std::cout << "Req received: " << req->GetPayloadCase() << "\n";

  // All the agents to the client
  for(int i = 0; i < req->GetNumAgents(); i++) {
    auto agent = req->GetAgent(i);
    client.agents.push_back(std::move(agent));
  }

  // Traverse all the agents
  for(auto &agent : client.agents) {
    //std::cout << agent->GetName() << "\n";
    if (callback) {
      hsa_agent_t agent_handle = {uint64_t(agent.get())};
      callback(agent_handle, data);
    }
  }

  return HSA_STATUS_SUCCESS; 
}

}
