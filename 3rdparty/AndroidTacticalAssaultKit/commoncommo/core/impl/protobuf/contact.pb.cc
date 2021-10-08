// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: contact.proto

#include "contact.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace atakmap {
namespace commoncommo {
namespace protobuf {
namespace v1 {
constexpr Contact::Contact(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : endpoint_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , callsign_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct ContactDefaultTypeInternal {
  constexpr ContactDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ContactDefaultTypeInternal() {}
  union {
    Contact _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ContactDefaultTypeInternal _Contact_default_instance_;
}  // namespace v1
}  // namespace protobuf
}  // namespace commoncommo
}  // namespace atakmap
namespace atakmap {
namespace commoncommo {
namespace protobuf {
namespace v1 {

// ===================================================================

class Contact::_Internal {
 public:
};

Contact::Contact(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:atakmap.commoncommo.protobuf.v1.Contact)
}
Contact::Contact(const Contact& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  endpoint_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_endpoint().empty()) {
    endpoint_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_endpoint(), 
      GetArenaForAllocation());
  }
  callsign_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_callsign().empty()) {
    callsign_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_callsign(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:atakmap.commoncommo.protobuf.v1.Contact)
}

inline void Contact::SharedCtor() {
endpoint_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
callsign_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

Contact::~Contact() {
  // @@protoc_insertion_point(destructor:atakmap.commoncommo.protobuf.v1.Contact)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

inline void Contact::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  endpoint_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  callsign_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Contact::ArenaDtor(void* object) {
  Contact* _this = reinterpret_cast< Contact* >(object);
  (void)_this;
}
void Contact::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Contact::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Contact::Clear() {
// @@protoc_insertion_point(message_clear_start:atakmap.commoncommo.protobuf.v1.Contact)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  endpoint_.ClearToEmpty();
  callsign_.ClearToEmpty();
  _internal_metadata_.Clear<std::string>();
}

const char* Contact::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string endpoint = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_endpoint();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, nullptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string callsign = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_callsign();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, nullptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Contact::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:atakmap.commoncommo.protobuf.v1.Contact)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string endpoint = 1;
  if (!this->_internal_endpoint().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_endpoint().data(), static_cast<int>(this->_internal_endpoint().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "atakmap.commoncommo.protobuf.v1.Contact.endpoint");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_endpoint(), target);
  }

  // string callsign = 2;
  if (!this->_internal_callsign().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_callsign().data(), static_cast<int>(this->_internal_callsign().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "atakmap.commoncommo.protobuf.v1.Contact.callsign");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_callsign(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:atakmap.commoncommo.protobuf.v1.Contact)
  return target;
}

size_t Contact::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:atakmap.commoncommo.protobuf.v1.Contact)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string endpoint = 1;
  if (!this->_internal_endpoint().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_endpoint());
  }

  // string callsign = 2;
  if (!this->_internal_callsign().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_callsign());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Contact::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const Contact*>(
      &from));
}

void Contact::MergeFrom(const Contact& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:atakmap.commoncommo.protobuf.v1.Contact)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_endpoint().empty()) {
    _internal_set_endpoint(from._internal_endpoint());
  }
  if (!from._internal_callsign().empty()) {
    _internal_set_callsign(from._internal_callsign());
  }
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
}

void Contact::CopyFrom(const Contact& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:atakmap.commoncommo.protobuf.v1.Contact)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Contact::IsInitialized() const {
  return true;
}

void Contact::InternalSwap(Contact* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &endpoint_, GetArenaForAllocation(),
      &other->endpoint_, other->GetArenaForAllocation()
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &callsign_, GetArenaForAllocation(),
      &other->callsign_, other->GetArenaForAllocation()
  );
}

std::string Contact::GetTypeName() const {
  return "atakmap.commoncommo.protobuf.v1.Contact";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace protobuf
}  // namespace commoncommo
}  // namespace atakmap
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::atakmap::commoncommo::protobuf::v1::Contact* Arena::CreateMaybeMessage< ::atakmap::commoncommo::protobuf::v1::Contact >(Arena* arena) {
  return Arena::CreateMessageInternal< ::atakmap::commoncommo::protobuf::v1::Contact >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>