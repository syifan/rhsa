#include <iostream>
#include "src/request/request.h"
#include "src/conn/listener.h"
#include "src/agent"
#include "hsa/hsa.h"
#include "hsa/hsa_ext_finalize.h"
#include <vector>

namespace rhsa {

class Agent {
	std::vector<hsa_agent_info_t> agent_info;
	auto temp;

	hsa_status_t storeAgent(hsa_agent_t agent, void *data) {
		// TODO: Code to store agent info to Agent vector
		hsa_agent_get_info(agent, HSA_AGENT_INFO_NAME, );
		return HSA_STATUS_SUCCESS;	
	}	

	void init_agents() {
		hsa_iterate_agents(*storeAgent, NULL);
	}


	public:
	Agent() {
		agent_info;
	};
}

class Server : public ConnectionHandler {
  virtual void Handle(std::unique_ptr<Connection> conn) {
    std::cout << "Connected.\n";
    auto req = conn->Recv();
    std::cout << "Received: " << req->GetPayloadCase() << "\n";
  }
};

}

int main() {
  rhsa::Server server;
  rhsa::Listener listener(&server);

  listener.Listen(9001);
}


