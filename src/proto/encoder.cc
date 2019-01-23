#include "src/proto/encoder.h"

#include <cstring>
#include "src/proto/msg.pb.h"

namespace rhsa {

std::unique_ptr<uint8_t[]> MsgEncoderImpl::Encode(const Msg &msg) {
  uint64_t size = msg.ByteSize();
  auto buf = std::make_unique<uint8_t[]>(size + 8);

  // google::protobuf::io::ArrayOutputStream aos(buf.get(), size);
  // google::protobuf::io::CodedOutputStream coded_output(&aos);
  // coded_output.WriteLittleEndian64(size);
  // msg.SerializeToCodedStream(&coded_output);

  memcpy(buf.get(), &size, 8);
  msg.SerializeToArray(buf.get() + 8, size);

  return buf;
}

std::unique_ptr<Msg> MsgEncoderImpl::Decode(const uint8_t *buf, int size) {
  auto msg = std::make_unique<Msg>();
  msg->ParseFromArray(buf, size);
  return msg;
}

}  // namespace rhsa
