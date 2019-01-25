#include "src/client/receiver.h"

#include <stdexcept>

namespace rhsa {

void Receiver::Recv() {
  while (true) {
    auto rsp = conn_->Recv();
    printf("Receiver received.\n");

    std::lock_guard<std::mutex> lck(handlers_mutex_);
    for (auto h : handlers_) {
      rsp = TryProcessRspWithHandler(std::move(rsp), h);
      printf("Return from handler.\n");
      if (IsRspConsumed(rsp.get())) {
        break;
      }
    }
  }
}

std::unique_ptr<Msg> Receiver::TryProcessRspWithHandler(
    std::unique_ptr<Msg> msg, RspHandler *handler) {
  printf("%p\n", &handler->chan);
  handler->chan.push(std::move(msg));
  auto ret_msg = handler->chan.value_pop();
  return ret_msg;
  // return std::unique_ptr<Msg>(nullptr);
}

bool Receiver::IsRspConsumed(Msg *msg) {
  if (msg == nullptr) {
    return true;
  }
  return false;
}

void Receiver::RegisterHandler(RspHandler *handler) {
  std::lock_guard<std::mutex> lck(handlers_mutex_);
  handlers_.push_back(handler);
}

void Receiver::UnregisterHandler(RspHandler *handler) {
  std::lock_guard<std::mutex> lck(handlers_mutex_);
  auto it = handlers_.begin();
  while (it != handlers_.end()) {
    if (*it == handler) {
      handlers_.erase(it);
      return;
    }

    throw new std::invalid_argument("handler not found");
  }
}

}  // namespace rhsa
