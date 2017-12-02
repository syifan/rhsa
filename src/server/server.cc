#include "src/conn/listener.h"

int main() {
  rhsa::SimpleConnectionHandler conn_handler;
  rhsa::Listener listener(&conn_handler);

  listener.Listen(9001);
}
