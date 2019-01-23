#include "src/proto/encoder.h"
#include "src/server/server.h"

int port() {
  const char *port_env_str = std::getenv("RHSA_PORT");
  if (port_env_str) {
    return std::stoi(port_env_str);
  }

  return 9001;
}

int main() {
  rhsa::Server server;
  rhsa::MsgEncoderImpl encoder;

  server.Init();
  //server.IterateAgents();

  rhsa::Listener listener(&server, &encoder);
  listener.Listen(port());
}
