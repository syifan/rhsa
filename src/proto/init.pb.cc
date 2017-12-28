// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: init.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "init.pb.h"

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

const ::google::protobuf::Descriptor* InitMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  InitMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_init_2eproto() {
  protobuf_AddDesc_init_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "init.proto");
  GOOGLE_CHECK(file != NULL);
  InitMessage_descriptor_ = file->message_type(0);
  static const int InitMessage_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InitMessage, type_),
  };
  InitMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      InitMessage_descriptor_,
      InitMessage::default_instance_,
      InitMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InitMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(InitMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(InitMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_init_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    InitMessage_descriptor_, &InitMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_init_2eproto() {
  delete InitMessage::default_instance_;
  delete InitMessage_reflection_;
}

void protobuf_AddDesc_init_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ninit.proto\022\004rhsa\"\033\n\013InitMessage\022\014\n\004typ"
    "e\030\001 \002(\r", 47);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "init.proto", &protobuf_RegisterTypes);
  InitMessage::default_instance_ = new InitMessage();
  InitMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_init_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_init_2eproto {
  StaticDescriptorInitializer_init_2eproto() {
    protobuf_AddDesc_init_2eproto();
  }
} static_descriptor_initializer_init_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int InitMessage::kTypeFieldNumber;
#endif  // !_MSC_VER

InitMessage::InitMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:rhsa.InitMessage)
}

void InitMessage::InitAsDefaultInstance() {
}

InitMessage::InitMessage(const InitMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:rhsa.InitMessage)
}

void InitMessage::SharedCtor() {
  _cached_size_ = 0;
  type_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

InitMessage::~InitMessage() {
  // @@protoc_insertion_point(destructor:rhsa.InitMessage)
  SharedDtor();
}

void InitMessage::SharedDtor() {
  if (this != default_instance_) {
  }
}

void InitMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* InitMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return InitMessage_descriptor_;
}

const InitMessage& InitMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_init_2eproto();
  return *default_instance_;
}

InitMessage* InitMessage::default_instance_ = NULL;

InitMessage* InitMessage::New() const {
  return new InitMessage;
}

void InitMessage::Clear() {
  type_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool InitMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:rhsa.InitMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 type = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &type_)));
          set_has_type();
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
  // @@protoc_insertion_point(parse_success:rhsa.InitMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:rhsa.InitMessage)
  return false;
#undef DO_
}

void InitMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:rhsa.InitMessage)
  // required uint32 type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:rhsa.InitMessage)
}

::google::protobuf::uint8* InitMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:rhsa.InitMessage)
  // required uint32 type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rhsa.InitMessage)
  return target;
}

int InitMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->type());
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

void InitMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const InitMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const InitMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void InitMessage::MergeFrom(const InitMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void InitMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void InitMessage::CopyFrom(const InitMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InitMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void InitMessage::Swap(InitMessage* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata InitMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = InitMessage_descriptor_;
  metadata.reflection = InitMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rhsa

// @@protoc_insertion_point(global_scope)
