#include "src/conn/conn.h"

namespace rhsa {

TCPConnection::TCPConnection(int sock) {
  this->sock = sock;
}

void TCPConnection::SendMessage(Message *message) {
}

Message *TCPConnection::RecvMessage() {
  return nullptr;
}

void TCPConnection::Close() {
}

}
