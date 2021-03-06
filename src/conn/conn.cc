#include "src/conn/conn.h"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

#include "src/conn/disconnect_exception.h"
#include "src/proto/msg.pb.h"

namespace rhsa {

TCPConnection::TCPConnection(int sock, MsgEncoder *encoder) {
  this->sock = sock;
  this->encoder = encoder;
}

void TCPConnection::Send(const Msg &msg) {
  auto buf = this->encoder->Encode(msg);

  std::cout << "Sending: ";
  for (int i = 0; i < msg.ByteSize() + 8; i++) {
    printf("%02x ", buf[i]);
  }
  std::cout << "\n";

  send(this->sock, buf.get(), msg.ByteSize() + 8, 0);
}

std::unique_ptr<Msg> TCPConnection::Recv() {
  uint64_t size;
  uint8_t *size_buf = (uint8_t *)&size;
  uint32_t size_buf_fullness = 0;
  while (size_buf_fullness < 8) {
    ssize_t n = read(this->sock, size_buf + size_buf_fullness,
                     (size_t)(8 - size_buf_fullness));

    if (n <= 0) {
      throw DisconnectException("Network disconnected");
    }

    size_buf_fullness += n;
    if (n == 0) return NULL;
  }

  std::cout << "Received Size: " << size << "\n";

  uint8_t *req_buf = (uint8_t *)malloc(size);
  uint32_t req_buf_fullness = 0;
  while (req_buf_fullness < size) {
    ssize_t n =
        read(this->sock, req_buf + req_buf_fullness, size - req_buf_fullness);

    if (n <= 0) {
      throw DisconnectException("Network disconnected");
    }

    req_buf_fullness += n;
    if (n == 0) return NULL;
  }

  for (uint32_t i = 0; i < size; i++) {
    printf("%02x ", req_buf[i]);
  }
  std::cout << "\n";

  auto msg = this->encoder->Decode(req_buf, size);
  return msg;
}

void TCPConnection::Close() { close(this->sock); }

}  // namespace rhsa
