// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: simple_matrix.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "simple_matrix.pb.h"

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

namespace {

const ::google::protobuf::Descriptor* SimpleMatrix_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SimpleMatrix_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* SimpleMatrixDataType_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_simple_5fmatrix_2eproto() {
  protobuf_AddDesc_simple_5fmatrix_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "simple_matrix.proto");
  GOOGLE_CHECK(file != NULL);
  SimpleMatrix_descriptor_ = file->message_type(0);
  static const int SimpleMatrix_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, num_cols_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, data_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, payload_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, device_id_),
  };
  SimpleMatrix_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SimpleMatrix_descriptor_,
      SimpleMatrix::default_instance_,
      SimpleMatrix_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SimpleMatrix, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SimpleMatrix));
  SimpleMatrixDataType_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_simple_5fmatrix_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SimpleMatrix_descriptor_, &SimpleMatrix::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_simple_5fmatrix_2eproto() {
  delete SimpleMatrix::default_instance_;
  delete SimpleMatrix_reflection_;
}

void protobuf_AddDesc_simple_5fmatrix_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023simple_matrix.proto\"z\n\014SimpleMatrix\022\n\n"
    "\002id\030\001 \001(\t\022\020\n\010num_cols\030\002 \001(\021\022(\n\tdata_type"
    "\030\003 \001(\0162\025.SimpleMatrixDataType\022\017\n\007payload"
    "\030\004 \003(\014\022\021\n\tdevice_id\030\005 \001(\t*!\n\024SimpleMatri"
    "xDataType\022\t\n\005SINT8\020\000B0\n\032com.hello.suripu"
    ".api.audioB\022SimpleMatrixProtos", 230);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "simple_matrix.proto", &protobuf_RegisterTypes);
  SimpleMatrix::default_instance_ = new SimpleMatrix();
  SimpleMatrix::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_simple_5fmatrix_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_simple_5fmatrix_2eproto {
  StaticDescriptorInitializer_simple_5fmatrix_2eproto() {
    protobuf_AddDesc_simple_5fmatrix_2eproto();
  }
} static_descriptor_initializer_simple_5fmatrix_2eproto_;
const ::google::protobuf::EnumDescriptor* SimpleMatrixDataType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SimpleMatrixDataType_descriptor_;
}
bool SimpleMatrixDataType_IsValid(int value) {
  switch(value) {
    case 0:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int SimpleMatrix::kIdFieldNumber;
const int SimpleMatrix::kNumColsFieldNumber;
const int SimpleMatrix::kDataTypeFieldNumber;
const int SimpleMatrix::kPayloadFieldNumber;
const int SimpleMatrix::kDeviceIdFieldNumber;
#endif  // !_MSC_VER

SimpleMatrix::SimpleMatrix()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SimpleMatrix)
}

void SimpleMatrix::InitAsDefaultInstance() {
}

SimpleMatrix::SimpleMatrix(const SimpleMatrix& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SimpleMatrix)
}

void SimpleMatrix::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  num_cols_ = 0;
  data_type_ = 0;
  device_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SimpleMatrix::~SimpleMatrix() {
  // @@protoc_insertion_point(destructor:SimpleMatrix)
  SharedDtor();
}

void SimpleMatrix::SharedDtor() {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete id_;
  }
  if (device_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete device_id_;
  }
  if (this != default_instance_) {
  }
}

void SimpleMatrix::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SimpleMatrix::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SimpleMatrix_descriptor_;
}

const SimpleMatrix& SimpleMatrix::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_simple_5fmatrix_2eproto();
  return *default_instance_;
}

SimpleMatrix* SimpleMatrix::default_instance_ = NULL;

SimpleMatrix* SimpleMatrix::New() const {
  return new SimpleMatrix;
}

void SimpleMatrix::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<SimpleMatrix*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 23) {
    ZR_(num_cols_, data_type_);
    if (has_id()) {
      if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        id_->clear();
      }
    }
    if (has_device_id()) {
      if (device_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        device_id_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  payload_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SimpleMatrix::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SimpleMatrix)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string id = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->id().data(), this->id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_num_cols;
        break;
      }

      // optional sint32 num_cols = 2;
      case 2: {
        if (tag == 16) {
         parse_num_cols:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &num_cols_)));
          set_has_num_cols();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_data_type;
        break;
      }

      // optional .SimpleMatrixDataType data_type = 3;
      case 3: {
        if (tag == 24) {
         parse_data_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::SimpleMatrixDataType_IsValid(value)) {
            set_data_type(static_cast< ::SimpleMatrixDataType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_payload;
        break;
      }

      // repeated bytes payload = 4;
      case 4: {
        if (tag == 34) {
         parse_payload:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->add_payload()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(34)) goto parse_payload;
        if (input->ExpectTag(42)) goto parse_device_id;
        break;
      }

      // optional string device_id = 5;
      case 5: {
        if (tag == 42) {
         parse_device_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_device_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->device_id().data(), this->device_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "device_id");
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
  // @@protoc_insertion_point(parse_success:SimpleMatrix)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SimpleMatrix)
  return false;
#undef DO_
}

void SimpleMatrix::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SimpleMatrix)
  // optional string id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->id(), output);
  }

  // optional sint32 num_cols = 2;
  if (has_num_cols()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(2, this->num_cols(), output);
  }

  // optional .SimpleMatrixDataType data_type = 3;
  if (has_data_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->data_type(), output);
  }

  // repeated bytes payload = 4;
  for (int i = 0; i < this->payload_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->payload(i), output);
  }

  // optional string device_id = 5;
  if (has_device_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->device_id().data(), this->device_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "device_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->device_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SimpleMatrix)
}

::google::protobuf::uint8* SimpleMatrix::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SimpleMatrix)
  // optional string id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->id(), target);
  }

  // optional sint32 num_cols = 2;
  if (has_num_cols()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(2, this->num_cols(), target);
  }

  // optional .SimpleMatrixDataType data_type = 3;
  if (has_data_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->data_type(), target);
  }

  // repeated bytes payload = 4;
  for (int i = 0; i < this->payload_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBytesToArray(4, this->payload(i), target);
  }

  // optional string device_id = 5;
  if (has_device_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->device_id().data(), this->device_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "device_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->device_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SimpleMatrix)
  return target;
}

int SimpleMatrix::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->id());
    }

    // optional sint32 num_cols = 2;
    if (has_num_cols()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->num_cols());
    }

    // optional .SimpleMatrixDataType data_type = 3;
    if (has_data_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->data_type());
    }

    // optional string device_id = 5;
    if (has_device_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->device_id());
    }

  }
  // repeated bytes payload = 4;
  total_size += 1 * this->payload_size();
  for (int i = 0; i < this->payload_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::BytesSize(
      this->payload(i));
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

void SimpleMatrix::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SimpleMatrix* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SimpleMatrix*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SimpleMatrix::MergeFrom(const SimpleMatrix& from) {
  GOOGLE_CHECK_NE(&from, this);
  payload_.MergeFrom(from.payload_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_num_cols()) {
      set_num_cols(from.num_cols());
    }
    if (from.has_data_type()) {
      set_data_type(from.data_type());
    }
    if (from.has_device_id()) {
      set_device_id(from.device_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SimpleMatrix::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SimpleMatrix::CopyFrom(const SimpleMatrix& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SimpleMatrix::IsInitialized() const {

  return true;
}

void SimpleMatrix::Swap(SimpleMatrix* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(num_cols_, other->num_cols_);
    std::swap(data_type_, other->data_type_);
    payload_.Swap(&other->payload_);
    std::swap(device_id_, other->device_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SimpleMatrix::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SimpleMatrix_descriptor_;
  metadata.reflection = SimpleMatrix_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
