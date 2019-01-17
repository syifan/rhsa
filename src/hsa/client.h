#ifndef SRC_CLIENT_CLIENT_H_
#define SRC_CLIENT_CLIENT_H_

#include <memory>

#include "src/conn/conn.h"
//#include "src/request/request_factory.h"

namespace rhsa{

/**
 * Client is a singleton class that stores the client global runtime 
 * information.
 */
class Client {
 public:
  static Client &GetInstance() {
    static Client instance;
    return instance;
  }

  Client(Client const &) = delete;
  Client(Client &&) = delete;
  Client &operator=(Client const&) = delete;
  Client &operator=(Client &&) = delete;

  /**
   * The connection to the server
   */
  std::unique_ptr<Connection> conn;
 
  /**
   * The request factory
   */
  //std::unique_ptr<RequestFactory> request_factory;

  /**
   * All the agents
   */
  //std::vector<std::unique_ptr<Agent>> agents;

 private:
  Client() {
    //request_factory = std::make_unique<RequestFactory>();
  }
  ~Client() {}
};

}

#endif  // SRC_CLIENT_CLIENT_H_
