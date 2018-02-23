// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: request.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "request.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace rhsa {

namespace {

const ::google::protobuf::Descriptor* RequestMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RequestMessage_reflection_ = NULL;
struct RequestMessageOneofInstance {
  const ::rhsa::InitMessage* init_;
  const ::rhsa::QueryAgent* queryagent_;
}* RequestMessage_default_oneof_instance_ = NULL;

}  // namespace


void protobuf_AssignDesc_request_2eproto() {
  protobuf_AddDesc_request_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "request.proto");
  GOOGLE_CHECK(file != NULL);
  RequestMessage_descriptor_ = file->message_type(0);
  static const int RequestMessage_offsets_[3] = {
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(RequestMessage_default_oneof_instance_, init_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(RequestMessage_default_oneof_instance_, queryagent_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestMessage, Payload_),
  };
  RequestMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RequestMessage_descriptor_,
      RequestMessage::default_instance_,
      RequestMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestMessage, _unknown_fields_),
      -1,
      RequestMessage_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RequestMessage, _oneof_case_[0]),
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RequestMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_request_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RequestMessage_descriptor_, &RequestMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_request_2eproto() {
  delete RequestMessage::default_instance_;
  delete RequestMessage_default_oneof_instance_;
  delete RequestMessage_reflection_;
}

void protobuf_AddDesc_request_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::rhsa::protobuf_AddDesc_init_2eproto();
  ::rhsa::protobuf_AddDesc_agent_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rrequest.proto\022\004rhsa\032\ninit.proto\032\013agent"
    ".proto\"h\n\016RequestMessage\022\"\n\004init\030\350\007 \001(\0132"
    "\021.rhsa.InitMessageH\000\022\'\n\nqueryAgent\030\320\017 \001("
    "\0132\020.rhsa.QueryAgentH\000B\t\n\007Payload", 152);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "request.proto", &protobuf_RegisterTypes);
  RequestMessage::default_instance_ = new RequestMessage();
  RequestMessage_default_oneof_instance_ = new RequestMessageOneofInstance;
  RequestMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_request_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_request_2eproto {
  StaticDescriptorInitializer_request_2eproto() {
    protobuf_AddDesc_request_2eproto();
  }
} static_descriptor_initializer_request_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RequestMessage::kInitFieldNumber;
const int RequestMessage::kQueryAgentFieldNumber;
#endif  // !_MSC_VER

RequestMessage::RequestMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:rhsa.RequestMessage)
}

void RequestMessage::InitAsDefaultInstance() {
  RequestMessage_default_oneof_instance_->init_ = const_cast< ::rhsa::InitMessage*>(&::rhsa::InitMessage::default_instance());
  RequestMessage_default_oneof_instance_->queryagent_ = const_cast< ::rhsa::QueryAgent*>(&::rhsa::QueryAgent::default_instance());
}

RequestMessage::RequestMessage(const RequestMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:rhsa.RequestMessage)
}

void RequestMessage::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  clear_has_Payload();
}

RequestMessage::~RequestMessage() {
  // @@protoc_insertion_point(destructor:rhsa.RequestMessage)
  SharedDtor();
}

void RequestMessage::SharedDtor() {
  if (has_Payload()) {
    clear_Payload();
  }
  if (this != default_instance_) {
  }
}

void RequestMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RequestMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RequestMessage_descriptor_;
}

const RequestMessage& RequestMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_request_2eproto();
  return *default_instance_;
}

RequestMessage* RequestMessage::default_instance_ = NULL;

RequestMessage* RequestMessage::New() const {
  return new RequestMessage;
}

void RequestMessage::clear_Payload() {
  switch(Payload_case()) {
    case kInit: {
      delete Payload_.init_;
      break;
    }
    case kQueryAgent: {
      delete Payload_.queryagent_;
      break;
    }
    case PAYLOAD_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = PAYLOAD_NOT_SET;
}


void RequestMessage::Clear() {
  clear_Payload();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RequestMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:rhsa.RequestMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16383);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .rhsa.InitMessage init = 1000;
      case 1000: {
        if (tag == 8002) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_init()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16002)) goto parse_queryAgent;
        break;
      }

      // optional .rhsa.QueryAgent queryAgent = 2000;
      case 2000: {
        if (tag == 16002) {
         parse_queryAgent:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_queryagent()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:rhsa.RequestMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:rhsa.RequestMessage)
  return false;
#undef DO_
}

void RequestMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:rhsa.RequestMessage)
  // optional .rhsa.InitMessage init = 1000;
  if (has_init()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1000, this->init(), output);
  }

  // optional .rhsa.QueryAgent queryAgent = 2000;
  if (has_queryagent()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2000, this->queryagent(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:rhsa.RequestMessage)
}

::google::protobuf::uint8* RequestMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:rhsa.RequestMessage)
  // optional .rhsa.InitMessage init = 1000;
  if (has_init()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1000, this->init(), target);
  }

  // optional .rhsa.QueryAgent queryAgent = 2000;
  if (has_queryagent()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2000, this->queryagent(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rhsa.RequestMessage)
  return target;
}

int RequestMessage::ByteSize() const {
  int total_size = 0;

  switch (Payload_case()) {
    // optional .rhsa.InitMessage init = 1000;
    case kInit: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->init());
      break;
    }
    // optional .rhsa.QueryAgent queryAgent = 2000;
    case kQueryAgent: {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->queryagent());
      break;
    }
    case PAYLOAD_NOT_SET: {
      break;
    }
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RequestMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RequestMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RequestMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RequestMessage::MergeFrom(const RequestMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  switch (from.Payload_case()) {
    case kInit: {
      mutable_init()->::rhsa::InitMessage::MergeFrom(from.init());
      break;
    }
    case kQueryAgent: {
      mutable_queryagent()->::rhsa::QueryAgent::MergeFrom(from.queryagent());
      break;
    }
    case PAYLOAD_NOT_SET: {
      break;
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RequestMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RequestMessage::CopyFrom(const RequestMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RequestMessage::IsInitialized() const {

  if (has_init()) {
    if (!this->init().IsInitialized()) return false;
  }
  if (has_queryagent()) {
    if (!this->queryagent().IsInitialized()) return false;
  }
  return true;
}

void RequestMessage::Swap(RequestMessage* other) {
  if (other != this) {
    std::swap(Payload_, other->Payload_);
    std::swap(_oneof_case_[0], other->_oneof_case_[0]);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RequestMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RequestMessage_descriptor_;
  metadata.reflection = RequestMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rhsa

// @@protoc_insertion_point(global_scope)
