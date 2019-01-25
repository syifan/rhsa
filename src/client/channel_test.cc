#include <memory>

#include "gtest/gtest.h"

#include "src/client/rsp_handler.h"

namespace {

typedef boost::fibers::unbuffered_channel<char> Channel_t;

void producer(Channel_t *chan) {
  chan->push('1');
  chan->push('2');
  chan->push('3');
  chan->push('4');
}

TEST(Channel, channel) {
  Channel_t chan; 

  std::thread td(&producer, &chan);

  char a[4];

  for (int i = 0; i < 4; i++) {
    a[i] = chan.value_pop();
    printf("%c,\n", a[i]);
  }

  td.join();
}

}
