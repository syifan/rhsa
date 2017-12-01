#include <memory>
#include <string>

#include "src/conn/conn.h"

namespace rhsa {

/**
 * Connector helps a client to establish a connection with a server.
 */
class Connector {
 public:

  /**
   * Connect establish a connection to the server that is hosted at IP address
   * ip and using port port. This function returns the connection to the
   * server.
   */
  virtual std::unique_ptr<Connection> Connect(const std::string &ip,
                                              int port) = 0;
  virtual ~Connector() {};
};

/**
 * TCPConnector establishes TCP connection to the server.
 */
class TCPConnector final : public Connector {
 public:
  std::unique_ptr<Connection> Connect(const std::string &ip, int port);
};

}
