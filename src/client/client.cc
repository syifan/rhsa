#include "src/client/client.h"

#include <boost/fiber/fiber.hpp>

#include "src/conn/connector.h"

namespace rhsa {

int Client::Port() {
  const char *port_env_str = std::getenv("RHSA_PORT");
  if (port_env_str) {
    return std::stoi(port_env_str);
  }

  return 9001;
}

bool Client::EstablishConnection() {
  TCPConnector connector(&encoder);
  auto connection = connector.Connect("127.0.0.1", Port());
  conn = std::move(connection);
  receiver = std::make_unique<Receiver>(conn.get());
  boost::fibers::fiber(&Receiver::Recv, receiver.get()).detach();
  return true;
}

}  // namespace rhsa
