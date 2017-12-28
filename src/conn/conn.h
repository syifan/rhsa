namespace rhsa {

class Message;

class Connection {
 public:
  virtual void SendMessage(Message* message) = 0;
  virtual Message* RecvMessage() = 0;
  virtual void Close() = 0;
  virtual ~Connection() {}
};

class TCPConnection : public Connection {
  int sock;

 public:

  TCPConnection(int sock);

  void SendMessage(Message *message) override;
  Message* RecvMessage () override;
  void Close() override;
  ~TCPConnection() {
    // Free resources;
  }
};

}
