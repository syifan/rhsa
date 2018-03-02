#include "gmock/gmock.h"

#include "conn.h"
#include "src/request/request.h"

namespace rhsa {


class MockConnection : public Connection {
 public:
  MOCK_METHOD1(Send,
      void(Request* req));
  MOCK_METHOD0(Recv,
      std::unique_ptr<Request>());
  MOCK_METHOD0(Close,
      void());
};

}  // namespace rhsa
