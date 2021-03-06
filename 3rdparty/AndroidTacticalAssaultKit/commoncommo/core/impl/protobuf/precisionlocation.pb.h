// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: precisionlocation.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_precisionlocation_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_precisionlocation_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_precisionlocation_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_precisionlocation_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace atakmap {
namespace commoncommo {
namespace protobuf {
namespace v1 {
class PrecisionLocation;
struct PrecisionLocationDefaultTypeInternal;
extern PrecisionLocationDefaultTypeInternal _PrecisionLocation_default_instance_;
}  // namespace v1
}  // namespace protobuf
}  // namespace commoncommo
}  // namespace atakmap
PROTOBUF_NAMESPACE_OPEN
template<> ::atakmap::commoncommo::protobuf::v1::PrecisionLocation* Arena::CreateMaybeMessage<::atakmap::commoncommo::protobuf::v1::PrecisionLocation>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace atakmap {
namespace commoncommo {
namespace protobuf {
namespace v1 {

// ===================================================================

class PrecisionLocation final :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:atakmap.commoncommo.protobuf.v1.PrecisionLocation) */ {
 public:
  inline PrecisionLocation() : PrecisionLocation(nullptr) {}
  ~PrecisionLocation() override;
  explicit constexpr PrecisionLocation(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PrecisionLocation(const PrecisionLocation& from);
  PrecisionLocation(PrecisionLocation&& from) noexcept
    : PrecisionLocation() {
    *this = ::std::move(from);
  }

  inline PrecisionLocation& operator=(const PrecisionLocation& from) {
    CopyFrom(from);
    return *this;
  }
  inline PrecisionLocation& operator=(PrecisionLocation&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const PrecisionLocation& default_instance() {
    return *internal_default_instance();
  }
  static inline const PrecisionLocation* internal_default_instance() {
    return reinterpret_cast<const PrecisionLocation*>(
               &_PrecisionLocation_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PrecisionLocation& a, PrecisionLocation& b) {
    a.Swap(&b);
  }
  inline void Swap(PrecisionLocation* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PrecisionLocation* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PrecisionLocation* New() const final {
    return new PrecisionLocation();
  }

  PrecisionLocation* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PrecisionLocation>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)  final;
  void CopyFrom(const PrecisionLocation& from);
  void MergeFrom(const PrecisionLocation& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(PrecisionLocation* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "atakmap.commoncommo.protobuf.v1.PrecisionLocation";
  }
  protected:
  explicit PrecisionLocation(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kGeopointsrcFieldNumber = 1,
    kAltsrcFieldNumber = 2,
  };
  // string geopointsrc = 1;
  void clear_geopointsrc();
  const std::string& geopointsrc() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_geopointsrc(ArgT0&& arg0, ArgT... args);
  std::string* mutable_geopointsrc();
  PROTOBUF_MUST_USE_RESULT std::string* release_geopointsrc();
  void set_allocated_geopointsrc(std::string* geopointsrc);
  private:
  const std::string& _internal_geopointsrc() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_geopointsrc(const std::string& value);
  std::string* _internal_mutable_geopointsrc();
  public:

  // string altsrc = 2;
  void clear_altsrc();
  const std::string& altsrc() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_altsrc(ArgT0&& arg0, ArgT... args);
  std::string* mutable_altsrc();
  PROTOBUF_MUST_USE_RESULT std::string* release_altsrc();
  void set_allocated_altsrc(std::string* altsrc);
  private:
  const std::string& _internal_altsrc() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_altsrc(const std::string& value);
  std::string* _internal_mutable_altsrc();
  public:

  // @@protoc_insertion_point(class_scope:atakmap.commoncommo.protobuf.v1.PrecisionLocation)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr geopointsrc_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr altsrc_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_precisionlocation_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PrecisionLocation

// string geopointsrc = 1;
inline void PrecisionLocation::clear_geopointsrc() {
  geopointsrc_.ClearToEmpty();
}
inline const std::string& PrecisionLocation::geopointsrc() const {
  // @@protoc_insertion_point(field_get:atakmap.commoncommo.protobuf.v1.PrecisionLocation.geopointsrc)
  return _internal_geopointsrc();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PrecisionLocation::set_geopointsrc(ArgT0&& arg0, ArgT... args) {
 
 geopointsrc_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:atakmap.commoncommo.protobuf.v1.PrecisionLocation.geopointsrc)
}
inline std::string* PrecisionLocation::mutable_geopointsrc() {
  std::string* _s = _internal_mutable_geopointsrc();
  // @@protoc_insertion_point(field_mutable:atakmap.commoncommo.protobuf.v1.PrecisionLocation.geopointsrc)
  return _s;
}
inline const std::string& PrecisionLocation::_internal_geopointsrc() const {
  return geopointsrc_.Get();
}
inline void PrecisionLocation::_internal_set_geopointsrc(const std::string& value) {
  
  geopointsrc_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PrecisionLocation::_internal_mutable_geopointsrc() {
  
  return geopointsrc_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PrecisionLocation::release_geopointsrc() {
  // @@protoc_insertion_point(field_release:atakmap.commoncommo.protobuf.v1.PrecisionLocation.geopointsrc)
  return geopointsrc_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void PrecisionLocation::set_allocated_geopointsrc(std::string* geopointsrc) {
  if (geopointsrc != nullptr) {
    
  } else {
    
  }
  geopointsrc_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), geopointsrc,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:atakmap.commoncommo.protobuf.v1.PrecisionLocation.geopointsrc)
}

// string altsrc = 2;
inline void PrecisionLocation::clear_altsrc() {
  altsrc_.ClearToEmpty();
}
inline const std::string& PrecisionLocation::altsrc() const {
  // @@protoc_insertion_point(field_get:atakmap.commoncommo.protobuf.v1.PrecisionLocation.altsrc)
  return _internal_altsrc();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PrecisionLocation::set_altsrc(ArgT0&& arg0, ArgT... args) {
 
 altsrc_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:atakmap.commoncommo.protobuf.v1.PrecisionLocation.altsrc)
}
inline std::string* PrecisionLocation::mutable_altsrc() {
  std::string* _s = _internal_mutable_altsrc();
  // @@protoc_insertion_point(field_mutable:atakmap.commoncommo.protobuf.v1.PrecisionLocation.altsrc)
  return _s;
}
inline const std::string& PrecisionLocation::_internal_altsrc() const {
  return altsrc_.Get();
}
inline void PrecisionLocation::_internal_set_altsrc(const std::string& value) {
  
  altsrc_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PrecisionLocation::_internal_mutable_altsrc() {
  
  return altsrc_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PrecisionLocation::release_altsrc() {
  // @@protoc_insertion_point(field_release:atakmap.commoncommo.protobuf.v1.PrecisionLocation.altsrc)
  return altsrc_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void PrecisionLocation::set_allocated_altsrc(std::string* altsrc) {
  if (altsrc != nullptr) {
    
  } else {
    
  }
  altsrc_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), altsrc,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:atakmap.commoncommo.protobuf.v1.PrecisionLocation.altsrc)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace protobuf
}  // namespace commoncommo
}  // namespace atakmap

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_precisionlocation_2eproto
