#include <memory>

#include "include/hsa.h"
#include "gtest/gtest.h"

#include "src/conn/mock_connection.h"
#include "src/client/client.h"

namespace rhsa {

TEST(HSA_Client, hsa_iterate_agents) {
  auto &client = Client::GetInstance();
  client.conn = std::make_unique<MockConnection>();

  hsa_iterate_agents(nullptr, nullptr);
}

}
