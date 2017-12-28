// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: request.proto

#ifndef PROTOBUF_request_2eproto__INCLUDED
#define PROTOBUF_request_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "init.pb.h"
// @@protoc_insertion_point(includes)

namespace rhsa {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_request_2eproto();
void protobuf_AssignDesc_request_2eproto();
void protobuf_ShutdownFile_request_2eproto();

class RequestMessage;

// ===================================================================

class RequestMessage : public ::google::protobuf::Message {
 public:
  RequestMessage();
  virtual ~RequestMessage();

  RequestMessage(const RequestMessage& from);

  inline RequestMessage& operator=(const RequestMessage& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RequestMessage& default_instance();

  enum PayloadCase {
    kInit = 1000,
    PAYLOAD_NOT_SET = 0,
  };

  void Swap(RequestMessage* other);

  // implements Message ----------------------------------------------

  RequestMessage* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RequestMessage& from);
  void MergeFrom(const RequestMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .rhsa.Init init = 1000;
  inline bool has_init() const;
  inline void clear_init();
  static const int kInitFieldNumber = 1000;
  inline const ::rhsa::Init& init() const;
  inline ::rhsa::Init* mutable_init();
  inline ::rhsa::Init* release_init();
  inline void set_allocated_init(::rhsa::Init* init);

  inline PayloadCase Payload_case() const;
  // @@protoc_insertion_point(class_scope:rhsa.RequestMessage)
 private:
  inline void set_has_init();

  inline bool has_Payload();
  void clear_Payload();
  inline void clear_has_Payload();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  union PayloadUnion {
    ::rhsa::Init* init_;
  } Payload_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend void  protobuf_AddDesc_request_2eproto();
  friend void protobuf_AssignDesc_request_2eproto();
  friend void protobuf_ShutdownFile_request_2eproto();

  void InitAsDefaultInstance();
  static RequestMessage* default_instance_;
};
// ===================================================================


// ===================================================================

// RequestMessage

// optional .rhsa.Init init = 1000;
inline bool RequestMessage::has_init() const {
  return Payload_case() == kInit;
}
inline void RequestMessage::set_has_init() {
  _oneof_case_[0] = kInit;
}
inline void RequestMessage::clear_init() {
  if (has_init()) {
    delete Payload_.init_;
    clear_has_Payload();
  }
}
inline const ::rhsa::Init& RequestMessage::init() const {
  return has_init() ? *Payload_.init_
                      : ::rhsa::Init::default_instance();
}
inline ::rhsa::Init* RequestMessage::mutable_init() {
  if (!has_init()) {
    clear_Payload();
    set_has_init();
    Payload_.init_ = new ::rhsa::Init;
  }
  return Payload_.init_;
}
inline ::rhsa::Init* RequestMessage::release_init() {
  if (has_init()) {
    clear_has_Payload();
    ::rhsa::Init* temp = Payload_.init_;
    Payload_.init_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void RequestMessage::set_allocated_init(::rhsa::Init* init) {
  clear_Payload();
  if (init) {
    set_has_init();
    Payload_.init_ = init;
  }
}

inline bool RequestMessage::has_Payload() {
  return Payload_case() != PAYLOAD_NOT_SET;
}
inline void RequestMessage::clear_has_Payload() {
  _oneof_case_[0] = PAYLOAD_NOT_SET;
}
inline RequestMessage::PayloadCase RequestMessage::Payload_case() const {
  return RequestMessage::PayloadCase(_oneof_case_[0]);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace rhsa

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_request_2eproto__INCLUDED
