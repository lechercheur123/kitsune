// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simple_matrix.proto

#ifndef PROTOBUF_simple_5fmatrix_2eproto__INCLUDED
#define PROTOBUF_simple_5fmatrix_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_simple_5fmatrix_2eproto();
void protobuf_AssignDesc_simple_5fmatrix_2eproto();
void protobuf_ShutdownFile_simple_5fmatrix_2eproto();

class SimpleMatrix;

enum SimpleMatrixDataType {
  SINT8 = 0
};
bool SimpleMatrixDataType_IsValid(int value);
const SimpleMatrixDataType SimpleMatrixDataType_MIN = SINT8;
const SimpleMatrixDataType SimpleMatrixDataType_MAX = SINT8;
const int SimpleMatrixDataType_ARRAYSIZE = SimpleMatrixDataType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SimpleMatrixDataType_descriptor();
inline const ::std::string& SimpleMatrixDataType_Name(SimpleMatrixDataType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SimpleMatrixDataType_descriptor(), value);
}
inline bool SimpleMatrixDataType_Parse(
    const ::std::string& name, SimpleMatrixDataType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SimpleMatrixDataType>(
    SimpleMatrixDataType_descriptor(), name, value);
}
// ===================================================================

class SimpleMatrix : public ::google::protobuf::Message {
 public:
  SimpleMatrix();
  virtual ~SimpleMatrix();

  SimpleMatrix(const SimpleMatrix& from);

  inline SimpleMatrix& operator=(const SimpleMatrix& from) {
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
  static const SimpleMatrix& default_instance();

  void Swap(SimpleMatrix* other);

  // implements Message ----------------------------------------------

  SimpleMatrix* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SimpleMatrix& from);
  void MergeFrom(const SimpleMatrix& from);
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

  // optional string id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline const ::std::string& id() const;
  inline void set_id(const ::std::string& value);
  inline void set_id(const char* value);
  inline void set_id(const char* value, size_t size);
  inline ::std::string* mutable_id();
  inline ::std::string* release_id();
  inline void set_allocated_id(::std::string* id);

  // optional sint32 num_cols = 2;
  inline bool has_num_cols() const;
  inline void clear_num_cols();
  static const int kNumColsFieldNumber = 2;
  inline ::google::protobuf::int32 num_cols() const;
  inline void set_num_cols(::google::protobuf::int32 value);

  // optional .SimpleMatrixDataType data_type = 3;
  inline bool has_data_type() const;
  inline void clear_data_type();
  static const int kDataTypeFieldNumber = 3;
  inline ::SimpleMatrixDataType data_type() const;
  inline void set_data_type(::SimpleMatrixDataType value);

  // repeated bytes payload = 4;
  inline int payload_size() const;
  inline void clear_payload();
  static const int kPayloadFieldNumber = 4;
  inline const ::std::string& payload(int index) const;
  inline ::std::string* mutable_payload(int index);
  inline void set_payload(int index, const ::std::string& value);
  inline void set_payload(int index, const char* value);
  inline void set_payload(int index, const void* value, size_t size);
  inline ::std::string* add_payload();
  inline void add_payload(const ::std::string& value);
  inline void add_payload(const char* value);
  inline void add_payload(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& payload() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_payload();

  // optional string device_id = 5;
  inline bool has_device_id() const;
  inline void clear_device_id();
  static const int kDeviceIdFieldNumber = 5;
  inline const ::std::string& device_id() const;
  inline void set_device_id(const ::std::string& value);
  inline void set_device_id(const char* value);
  inline void set_device_id(const char* value, size_t size);
  inline ::std::string* mutable_device_id();
  inline ::std::string* release_device_id();
  inline void set_allocated_device_id(::std::string* device_id);

  // @@protoc_insertion_point(class_scope:SimpleMatrix)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_num_cols();
  inline void clear_has_num_cols();
  inline void set_has_data_type();
  inline void clear_has_data_type();
  inline void set_has_device_id();
  inline void clear_has_device_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* id_;
  ::google::protobuf::int32 num_cols_;
  int data_type_;
  ::google::protobuf::RepeatedPtrField< ::std::string> payload_;
  ::std::string* device_id_;
  friend void  protobuf_AddDesc_simple_5fmatrix_2eproto();
  friend void protobuf_AssignDesc_simple_5fmatrix_2eproto();
  friend void protobuf_ShutdownFile_simple_5fmatrix_2eproto();

  void InitAsDefaultInstance();
  static SimpleMatrix* default_instance_;
};
// ===================================================================


// ===================================================================

// SimpleMatrix

// optional string id = 1;
inline bool SimpleMatrix::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SimpleMatrix::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SimpleMatrix::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SimpleMatrix::clear_id() {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_->clear();
  }
  clear_has_id();
}
inline const ::std::string& SimpleMatrix::id() const {
  // @@protoc_insertion_point(field_get:SimpleMatrix.id)
  return *id_;
}
inline void SimpleMatrix::set_id(const ::std::string& value) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  id_->assign(value);
  // @@protoc_insertion_point(field_set:SimpleMatrix.id)
}
inline void SimpleMatrix::set_id(const char* value) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  id_->assign(value);
  // @@protoc_insertion_point(field_set_char:SimpleMatrix.id)
}
inline void SimpleMatrix::set_id(const char* value, size_t size) {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SimpleMatrix.id)
}
inline ::std::string* SimpleMatrix::mutable_id() {
  set_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:SimpleMatrix.id)
  return id_;
}
inline ::std::string* SimpleMatrix::release_id() {
  clear_has_id();
  if (id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = id_;
    id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SimpleMatrix::set_allocated_id(::std::string* id) {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete id_;
  }
  if (id) {
    set_has_id();
    id_ = id;
  } else {
    clear_has_id();
    id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:SimpleMatrix.id)
}

// optional sint32 num_cols = 2;
inline bool SimpleMatrix::has_num_cols() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SimpleMatrix::set_has_num_cols() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SimpleMatrix::clear_has_num_cols() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SimpleMatrix::clear_num_cols() {
  num_cols_ = 0;
  clear_has_num_cols();
}
inline ::google::protobuf::int32 SimpleMatrix::num_cols() const {
  // @@protoc_insertion_point(field_get:SimpleMatrix.num_cols)
  return num_cols_;
}
inline void SimpleMatrix::set_num_cols(::google::protobuf::int32 value) {
  set_has_num_cols();
  num_cols_ = value;
  // @@protoc_insertion_point(field_set:SimpleMatrix.num_cols)
}

// optional .SimpleMatrixDataType data_type = 3;
inline bool SimpleMatrix::has_data_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SimpleMatrix::set_has_data_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SimpleMatrix::clear_has_data_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SimpleMatrix::clear_data_type() {
  data_type_ = 0;
  clear_has_data_type();
}
inline ::SimpleMatrixDataType SimpleMatrix::data_type() const {
  // @@protoc_insertion_point(field_get:SimpleMatrix.data_type)
  return static_cast< ::SimpleMatrixDataType >(data_type_);
}
inline void SimpleMatrix::set_data_type(::SimpleMatrixDataType value) {
  assert(::SimpleMatrixDataType_IsValid(value));
  set_has_data_type();
  data_type_ = value;
  // @@protoc_insertion_point(field_set:SimpleMatrix.data_type)
}

// repeated bytes payload = 4;
inline int SimpleMatrix::payload_size() const {
  return payload_.size();
}
inline void SimpleMatrix::clear_payload() {
  payload_.Clear();
}
inline const ::std::string& SimpleMatrix::payload(int index) const {
  // @@protoc_insertion_point(field_get:SimpleMatrix.payload)
  return payload_.Get(index);
}
inline ::std::string* SimpleMatrix::mutable_payload(int index) {
  // @@protoc_insertion_point(field_mutable:SimpleMatrix.payload)
  return payload_.Mutable(index);
}
inline void SimpleMatrix::set_payload(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:SimpleMatrix.payload)
  payload_.Mutable(index)->assign(value);
}
inline void SimpleMatrix::set_payload(int index, const char* value) {
  payload_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:SimpleMatrix.payload)
}
inline void SimpleMatrix::set_payload(int index, const void* value, size_t size) {
  payload_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SimpleMatrix.payload)
}
inline ::std::string* SimpleMatrix::add_payload() {
  return payload_.Add();
}
inline void SimpleMatrix::add_payload(const ::std::string& value) {
  payload_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:SimpleMatrix.payload)
}
inline void SimpleMatrix::add_payload(const char* value) {
  payload_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:SimpleMatrix.payload)
}
inline void SimpleMatrix::add_payload(const void* value, size_t size) {
  payload_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:SimpleMatrix.payload)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
SimpleMatrix::payload() const {
  // @@protoc_insertion_point(field_list:SimpleMatrix.payload)
  return payload_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
SimpleMatrix::mutable_payload() {
  // @@protoc_insertion_point(field_mutable_list:SimpleMatrix.payload)
  return &payload_;
}

// optional string device_id = 5;
inline bool SimpleMatrix::has_device_id() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SimpleMatrix::set_has_device_id() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SimpleMatrix::clear_has_device_id() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SimpleMatrix::clear_device_id() {
  if (device_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    device_id_->clear();
  }
  clear_has_device_id();
}
inline const ::std::string& SimpleMatrix::device_id() const {
  // @@protoc_insertion_point(field_get:SimpleMatrix.device_id)
  return *device_id_;
}
inline void SimpleMatrix::set_device_id(const ::std::string& value) {
  set_has_device_id();
  if (device_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    device_id_ = new ::std::string;
  }
  device_id_->assign(value);
  // @@protoc_insertion_point(field_set:SimpleMatrix.device_id)
}
inline void SimpleMatrix::set_device_id(const char* value) {
  set_has_device_id();
  if (device_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    device_id_ = new ::std::string;
  }
  device_id_->assign(value);
  // @@protoc_insertion_point(field_set_char:SimpleMatrix.device_id)
}
inline void SimpleMatrix::set_device_id(const char* value, size_t size) {
  set_has_device_id();
  if (device_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    device_id_ = new ::std::string;
  }
  device_id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:SimpleMatrix.device_id)
}
inline ::std::string* SimpleMatrix::mutable_device_id() {
  set_has_device_id();
  if (device_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    device_id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:SimpleMatrix.device_id)
  return device_id_;
}
inline ::std::string* SimpleMatrix::release_device_id() {
  clear_has_device_id();
  if (device_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = device_id_;
    device_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SimpleMatrix::set_allocated_device_id(::std::string* device_id) {
  if (device_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete device_id_;
  }
  if (device_id) {
    set_has_device_id();
    device_id_ = device_id;
  } else {
    clear_has_device_id();
    device_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:SimpleMatrix.device_id)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::SimpleMatrixDataType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SimpleMatrixDataType>() {
  return ::SimpleMatrixDataType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_simple_5fmatrix_2eproto__INCLUDED
