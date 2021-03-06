#ifndef SRC_CONN_CONNECTOR_H_
#define SRC_CONN_CONNECTOR_H_

#include <memory>
#include <string>

#include "src/conn/conn.h"

namespace rhsa {

class MsgEncoder;

/**
 * Connector helps a client to establish a connection with a server.
 */
class Connector {
 public:
  /**
   * Connect establish a connection to the server that is hosted at IP address
   * ip and using port port. This function returns the connection to the
   * server.
   *
   * @param ip IP address
   */
  virtual std::unique_ptr<Connection> Connect(const std::string &ip,
                                              int port) = 0;
  virtual ~Connector(){};
};

/**
 * TCPConnector establishes TCP connection to the server.
 */
class TCPConnector final : public Connector {
  MsgEncoder *encoder_;

 public:

  explicit TCPConnector(MsgEncoder *encoder);

  std::unique_ptr<Connection> Connect(const std::string &ip, int port) override;
};

}  // namespace rhsa

#endif  // SRC_CONN_CONNECTOR_H_
