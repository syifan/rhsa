#ifndef SRC_CLIENT_RECEIVER_H_
#define SRC_CLIENT_RECEIVER_H_

#include <mutex>
#include <vector>

#include "src/client/rsp_handler.h"
#include "src/conn/conn.h"

namespace rhsa {

class Receiver {
  Connection *conn_;
  std::vector<RspHandler *> handlers_;
  std::mutex handlers_mutex_;

  std::unique_ptr<Msg> TryProcessRspWithHandler(std::unique_ptr<Msg> msg,
                                                RspHandler *handler);
  bool IsRspConsumed(Msg *msg);

 public:
  explicit Receiver(Connection *conn) : conn_(conn) {}
  void Recv();
  void RegisterHandler(RspHandler *handler);
  void UnregisterHandler(RspHandler *handler);
};

}  // namespace rhsa

#endif  // SRC_CLIENT_RECEIVER_H_
