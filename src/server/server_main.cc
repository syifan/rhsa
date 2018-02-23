#include "src/server/server.h"

int main() {
  rhsa::Server server;
  server.Init();
  server.IterateAgents();

  rhsa::Listener listener(&server);
  listener.Listen(9001);
}
