#include <memory>

#include "gtest/gtest.h"

#include "src/client/rsp_handler.h"
#include "src/proto/msg.pb.h"

namespace {

using namespace rhsa;

//void producer(RspHandler *handler, std::unique_ptr<Msg> msg) {
  //handler->chan.push(std::move(msg));
//}

TEST(RspHandler, receive) {
  RspHandler handler;

  auto msg = std::make_unique<Msg>();
  auto raw_msg = msg.get();

  std::thread td([&](){
    handler.chan.push(std::move(msg));
  });

  auto ret_msg = handler.chan.value_pop();

  EXPECT_EQ(ret_msg.get(), raw_msg);

  td.join();
}

}  // namespace
