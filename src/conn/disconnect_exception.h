#ifndef SRC_CONN_DISCONNECT_EXCEPTION_H_
#define SRC_CONN_DISCONNECT_EXCEPTION_H_

#include <exception>

namespace rhsa {

class DisconnectException : std::runtime_error {
 public:
  explicit DisconnectException(const std::string &what) : 
    std::runtime_error(what) {}
};

}

#endif  // SRC_CONN_DISCONNECT_EXCEPTION_H_

