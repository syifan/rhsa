#ifndef SRC_CLIENT_RSP_HANDLER_H_
#define SRC_CLIENT_RSP_HANDLER_H_

#include <boost/fiber/unbuffered_channel.hpp>

#include "src/proto/msg.pb.h"

namespace rhsa {

typedef boost::fibers::unbuffered_channel<std::unique_ptr<Msg>> Chan;

class RspHandler {
 public:
   Chan chan;
};

}

#endif  // SRC_CLIENT_RSP_HANDLER_H_
