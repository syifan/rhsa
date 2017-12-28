namespace rhsa {

class Request;

class Connection {
 public:
  virtual void Send(Request* req) = 0;
  virtual Request* Recv() = 0;
  virtual void Close() = 0;
  virtual ~Connection() {}
};

class TCPConnection : public Connection {
  int sock;

 public:

  TCPConnection(int sock);

  void Send(Request *req) override;
  Request* Recv() override;
  void Close() override;
  ~TCPConnection() {
    // Free resources;
  }
};

}
