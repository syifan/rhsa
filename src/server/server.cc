#include <iostream>
#include "src/request/request.h"
#include "src/conn/listener.h"

namespace rhsa {

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


