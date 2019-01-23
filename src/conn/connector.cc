#include "src/conn/connector.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <memory>

namespace rhsa {

TCPConnector::TCPConnector(MsgEncoder *encoder) : encoder_(encoder) {}

std::unique_ptr<Connection> TCPConnector::Connect(const std::string &ip,
                                                  int port) {
  int sock;
  struct sockaddr_in addr;

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip.c_str());
  addr.sin_port = htons(port);

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(-1);
  }

  if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
    perror("Connection failed");
    exit(-1);
  }

  std::cout << "Connection established.\n";

  auto conn = std::make_unique<TCPConnection>(sock, encoder_);
  return std::move(conn);
}

}  // namespace rhsa
