#ifndef SRC_PROTO_ENCODER_H_
#define SRC_PROTO_ENCODER_H_

#include <memory>

namespace rhsa {

class Msg;

class MsgEncoder {
 public:
  virtual std::unique_ptr<uint8_t[]> Encode(const Msg &msg) = 0;
  virtual std::unique_ptr<Msg> Decode(const uint8_t *buf, int size) = 0;
  virtual ~MsgEncoder() {}
};

class MsgEncoderImpl : public MsgEncoder {
 public:
  virtual std::unique_ptr<uint8_t[]> Encode(const Msg &msg) override;
  virtual std::unique_ptr<Msg> Decode(const uint8_t *buf, int size) override;
};

}  // namespace rhsa

#endif  // SRC_PROTO_ENCODER_H_
