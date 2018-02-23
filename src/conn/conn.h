#ifndef SRC_CONN_CONN_H_
#define SRC_CONN_CONN_H_

#include <memory>

namespace rhsa {

class Request;

class Connection {
 public:
  virtual void Send(Request* req) = 0;
  virtual std::unique_ptr<Request> Recv() = 0;
  virtual void Close() = 0;
  virtual ~Connection() {}
};

class TCPConnection : public Connection {
  int sock;

 public:

  TCPConnection(int sock);

  void Send(Request *req) override;
  std::unique_ptr<Request> Recv() override;
  void Close() override;
  ~TCPConnection() {
    // Free resources;
  }
};

}

#endif  // SRC_CONN_CONN_H_
