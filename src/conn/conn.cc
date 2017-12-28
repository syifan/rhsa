#include "src/conn/conn.h"

#include "src/request/request.h"

namespace rhsa {

TCPConnection::TCPConnection(int sock) {
  this->sock = sock;
}

void TCPConnection::Send(Request *request) {
}

Request *TCPConnection::Recv() {
  return nullptr;
}

void TCPConnection::Close() {
}

}
