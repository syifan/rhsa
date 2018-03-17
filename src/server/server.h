#ifndef SRC_SERVER_SERVER_H_
#define SRC_SERVER_SERVER_H_

#include <memory>
#include <vector>

#include "src/conn/listener.h"
#include "src/common/agent.h"

namespace rhsa {

class Server : public ConnectionHandler {
  std::vector<std::unique_ptr<Agent>> agents_;

  void HandleQueryAgent(Connection *conn);

 public:
  void Init();
  void IterateAgents();
  virtual void Handle(std::unique_ptr<Connection> conn) override;
};

}

#endif  // SRC_SERVER_SERVER_H_
