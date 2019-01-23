#ifndef SRC_SERVER_SERVER_H_
#define SRC_SERVER_SERVER_H_

#include <memory>
#include <vector>

#include "src/conn/listener.h"
#include "src/proto/msg.pb.h"

namespace rhsa {

class Server : public ConnectionHandler {

  std::vector<std::unique_ptr<Agent>> agents_;
  //void HandleQueryAgent(Connection *conn, Request *req);
  
  void IterateAgents();

 public:
  void Init();
  virtual void Handle(std::unique_ptr<Connection> conn) override;
};

}

#endif  // SRC_SERVER_SERVER_H_
