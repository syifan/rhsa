#include <memory>

#include "src/conn/conn.h"

namespace rhsa {

/**
 * A ConnectionHandler is a general interface to define the action to trigger
 * for incomming connection.
 */
class ConnectionHandler {
 public:
  /**
   * Handle perform a certain action for the new comming connection conn.
   */
  virtual void Handle(std::unique_ptr<Connection> conn) = 0;
};

/**
 * A SimpleConnectionHandler is a handler that just print connection
 * information and close the connection.
 */
class SimpleConnectionHandler : public ConnectionHandler {
 public:
  void Handle(std::unique_ptr<Connection> conn);
};

/**
 * The listener listen to a network port and wait for incomming connections.
 * When there is a client connect in, the listener calls the ConnectionHandler
 * to decide how to deal with the new connection.
 */
class Listener {
  ConnectionHandler *connection_handler_;
  MsgEncoder *encoder_;

 public:
  /**
   * Constructor
   *
   * @param connection_handler The Connection handler that defines the action
   * to deal with a new connection.
   */
  Listener(ConnectionHandler *connection_handler, MsgEncoder *encoder);

  /**
   * Listen monitors a port for incomming connections. This function will
   * never return.
   */
  void Listen(int port);
};

}  // namespace rhsa
