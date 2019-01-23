#include "src/conn/listener.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

namespace rhsa {

void SimpleConnectionHandler::Handle(std::unique_ptr<Connection> conn) {
  std::cout << "Connected.\n";
}

Listener::Listener(ConnectionHandler *connection_handler, MsgEncoder *encoder)
    : connection_handler_(connection_handler), encoder_(encoder) {}

void Listener::Listen(int port) {
  int sock;
  int client_sock;
  struct sockaddr_in addr;
  int addr_len = sizeof(addr);

  memset(&addr, 0, sizeof(addr));

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Failed to create server socket.");
    exit(-1);
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);

  if (bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
    perror("Failed to bind socket to address.");
    exit(-1);
  }

  if (listen(sock, 10) < 0) {
    perror("Failed to listen to socket.");
    exit(-1);
  }

  while (true) {
    client_sock =
        accept(sock, (struct sockaddr *)&addr, (socklen_t *)&addr_len);
    if (client_sock < 0) {
      perror("Failed to accept incomming connection.");
      exit(-1);
    }

    auto conn = std::make_unique<TCPConnection>(client_sock, encoder_);
    connection_handler_->Handle(std::move(conn));
  }
}
}  // namespace rhsa
