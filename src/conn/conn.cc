#include "src/conn/conn.h"

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

#include "src/conn/disconnect_exception.h"
#include "src/request/request.h"

namespace rhsa {

TCPConnection::TCPConnection(int sock) { this->sock = sock; }

void TCPConnection::Send(Request *request) {
  auto msg = request->Encode();

  for (int i = 0; i < request->ByteSize(); i++) {
    printf("%02x ", msg[i]);
  }

  send(this->sock, msg.get(), request->ByteSize(), 0);
}

std::unique_ptr<Request> TCPConnection::Recv() {
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

  std::cout << "Size: " << size << "\n";

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

  auto req = std::make_unique<Request>(std::string((char *)req_buf));
  return std::move(req);
}

void TCPConnection::Close() {
  close(this->sock);
}

}
