#ifndef SRC_CONN_CONN_H_
#define SRC_CONN_CONN_H_

#include <memory>
#include "src/proto/encoder.h"

namespace rhsa {

class Msg;

class Connection {
 public:
  virtual void Send(const Msg &msg) = 0;
  virtual std::unique_ptr<Msg> Recv() = 0;
  virtual void Close() = 0;
  virtual ~Connection() {}
};

class TCPConnection : public Connection {
  int sock;
  MsgEncoder *encoder;

 public:
  TCPConnection(int sock, MsgEncoder *encoder);

  void Send(const Msg &msg) override;
  std::unique_ptr<Msg> Recv() override;
  void Close() override;
  ~TCPConnection() {
    // Free resources;
  }
};

}  // namespace rhsa

#endif  // SRC_CONN_CONN_H_
