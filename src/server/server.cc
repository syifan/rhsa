#include <iostream>
#include "src/request/request.h"
#include "src/conn/listener.h"
#include "src/agent"
#include "hsa/hsa.h"
#include "hsa/hsa_ext_finalize.h"

namespace rhsa {

class Agent {
	
	hsa_status_t storeAgent(hsa_agent_t agent, void *data) {
		// TODO: Code to store agent info to Agent vector

		return HSA_STATUS_SUCCESS;	
	}	

	void init_agents() {
		hsa_iterate_agents(*storeAgent, NULL);
	}
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


