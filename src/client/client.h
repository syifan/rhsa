#ifndef SRC_CLIENT_CLIENT_H_
#define SRC_CLIENT_CLIENT_H_

#include "src/conn/conn.h"

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

 private:
  Client() {}
  ~Client() {}
};

}

#endif  // SRC_CLIENT_CLIENT_H_
