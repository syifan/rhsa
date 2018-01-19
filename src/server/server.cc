#include <iostream>
#include <memory>
#include <vector>

#include "hsa/hsa.h"
#include "hsa/hsa_ext_finalize.h"

#include "src/conn/listener.h"
#include "src/proto/agent.pb.h"
#include "src/request/request.h"

namespace rhsa {

class Agent {
  // std::vector<hsa_agent_info_t> agent_info;
  // auto temp;

  // void init_agents() { hsa_iterate_agents(*storeAgent, NULL); }

  std::unique_ptr<AgentMesg> agent_mesg_;

 public:
  Agent() { agent_mesg_ = std::make_unique<AgentMesg>(); }

  std::string GetVendorName() { return ""; }

  void SetName(char *name) { agent_mesg_->set_name(name); }
};

hsa_status_t storeAgent(hsa_agent_t agent, void *data) {
  // TODO: Code to store agent info to Agent vector
  // hsa_agent_get_info(agent, HSA_AGENT_INFO_NAME, );

  auto agents = static_cast<std::vector<std::unique_ptr<Agent>> *>(data);

  auto curr_agent = std::make_unique<Agent>();
  char name[64];
  hsa_agent_get_info(agent, HSA_AGENT_INFO_NAME, name);
  printf("Agent name %s\n", name);
  curr_agent->SetName(name);

  agents->push_back(std::move(curr_agent));

  return HSA_STATUS_SUCCESS;
}

class Server : public ConnectionHandler {
  std::vector<std::unique_ptr<Agent>> agents_;

 public:
  void Init() { auto res = hsa_init(); }

  void IterateAgents() { hsa_iterate_agents(storeAgent, &agents_); };

  virtual void Handle(std::unique_ptr<Connection> conn) override {
    std::cout << "Connected.\n";
    auto req = conn->Recv();
    std::cout << "Received: " << req->GetPayloadCase() << "\n";
  }
};
}

int main() {
  rhsa::Server server;
  server.Init();
  server.IterateAgents();

  // rhsa::Listener listener(&server);

  // listener.Listen(9001);
}
