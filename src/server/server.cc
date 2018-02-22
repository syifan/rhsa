#include "src/server/server.h"

#include <iostream>

#include "hsa/hsa.h"
#include "hsa/hsa_ext_finalize.h"

#include "src/common/agent.h"
#include "src/conn/disconnect_exception.h"
#include "src/request/request.h"

namespace rhsa {

void loadAgentName(hsa_agent_t agent, Agent *agent_info) {
  char name[64];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_NAME, name);
  agent_info->SetName(name);
}

void loadVendorName(hsa_agent_t agent, Agent *agent_info) {
  char name[64];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_VENDOR_NAME, name);
  agent_info->SetVendorName(name);
}

hsa_status_t storeAgent(hsa_agent_t agent, void *data) {
  auto agents = static_cast<std::vector<std::unique_ptr<Agent>> *>(data);

  auto agent_info = std::make_unique<Agent>();

  loadAgentName(agent, agent_info.get());
  loadVendorName(agent, agent_info.get());

  std::cout << agent_info->GetVendorName() << "\n";

  agents->push_back(std::move(agent_info));

  return HSA_STATUS_SUCCESS;
}

void Server::Init() { hsa_init(); }

void Server::IterateAgents() { hsa_iterate_agents(storeAgent, &agents_); };

void Server::Handle(std::unique_ptr<Connection> conn) {
  std::cout << "Connected.\n";
  try{
    while(true) {
      auto req = conn->Recv();
      std::cout << "Received: " << req->GetPayloadCase() << "\n";
    }
  } catch (DisconnectException &e) {
    std::cout << "Client disconnected.\n";
  }
}

}
