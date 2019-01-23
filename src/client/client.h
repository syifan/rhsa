#ifndef SRC_CLIENT_CLIENT_H_
#define SRC_CLIENT_CLIENT_H_

#include <memory>
#include <vector>

#include "src/conn/conn.h"
#include "src/proto/encoder.h"

namespace rhsa {

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
  Client &operator=(Client const &) = delete;
  Client &operator=(Client &&) = delete;

  /**
   * The connection to the server
   */
  std::unique_ptr<Connection> conn;
  MsgEncoderImpl encoder;

 private:
  Client() {}
  ~Client() {}

};

}  // namespace rhsa

#endif  // SRC_CLIENT_CLIENT_H_
