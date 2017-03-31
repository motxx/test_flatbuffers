// automatically generated by the FlatBuffers compiler, do not modify

#include <iostream>
#include <assert.h>

#ifndef FLATBUFFERS_GENERATED_SAMPLE_SAMPLE_H_
#define FLATBUFFERS_GENERATED_SAMPLE_SAMPLE_H_

#include "flatbuffers/flatbuffers.h"

namespace sample {

struct Object1;
struct Object1T;

struct Object2;
struct Object2T;

struct SampleRoot;
struct SampleRootT;

enum Object {
  Object_NONE = 0,
  Object_Object1 = 1,
  Object_Object2 = 2,
  Object_MIN = Object_NONE,
  Object_MAX = Object_Object2
};

inline const char **EnumNamesObject() {
  static const char *names[] = {
    "NONE",
    "Object1",
    "Object2",
    nullptr
  };
  return names;
}

inline const char *EnumNameObject(Object e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesObject()[index];
}

template<typename T> struct ObjectTraits {
  static const Object enum_value = Object_NONE;
};

template<> struct ObjectTraits<Object1> {
  static const Object enum_value = Object_Object1;
};

template<> struct ObjectTraits<Object2> {
  static const Object enum_value = Object_Object2;
};

struct ObjectUnion {
  Object type;
  flatbuffers::NativeTable *table;

  ObjectUnion() : type(Object_NONE), table(nullptr) {}
  ObjectUnion(ObjectUnion&& u) FLATBUFFERS_NOEXCEPT :
    type(Object_NONE), table(nullptr)
    { std::swap(type, u.type); std::swap(table, u.table); }
  ObjectUnion(const ObjectUnion &);
  ObjectUnion &operator=(const ObjectUnion &u);
  ObjectUnion &operator=(ObjectUnion &&u) FLATBUFFERS_NOEXCEPT
    { std::swap(type, u.type); std::swap(table, u.table); return *this; }
  ~ObjectUnion() { Reset(); }

  void Reset();

  template <typename T>
  void Set(T&& value) {
    Reset();
    type = ObjectTraits<typename T::TableType>::enum_value;
    if (type != Object_NONE) {
      table = new T(std::forward<T>(value));
    }
  }

  static flatbuffers::NativeTable *UnPack(const void *obj, Object type, const flatbuffers::resolver_function_t *resolver);
  flatbuffers::Offset<void> Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *_rehasher = nullptr) const;

  Object1T *AsObject1() {
    return type == Object_Object1 ?
      reinterpret_cast<Object1T *>(table) : nullptr;
  }
  Object2T *AsObject2() {
    return type == Object_Object2 ?
      reinterpret_cast<Object2T *>(table) : nullptr;
  }
};

bool VerifyObject(flatbuffers::Verifier &verifier, const void *obj, Object type);
bool VerifyObjectVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Object1T : public flatbuffers::NativeTable {
  typedef Object1 TableType;
  std::string text;
  bool boolean;
  Object1T()
      : boolean(false) {
  }
};

struct Object1 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef Object1T NativeTableType;
  enum {
    VT_TEXT = 4,
    VT_BOOLEAN = 6
  };
  const flatbuffers::String *text() const {
    return GetPointer<const flatbuffers::String *>(VT_TEXT);
  }
  bool boolean() const {
    return GetField<uint8_t>(VT_BOOLEAN, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_TEXT) &&
           verifier.Verify(text()) &&
           VerifyField<uint8_t>(verifier, VT_BOOLEAN) &&
           verifier.EndTable();
  }
  Object1T *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(Object1T *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Object1> Pack(flatbuffers::FlatBufferBuilder &_fbb, const Object1T* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct Object1Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_text(flatbuffers::Offset<flatbuffers::String> text) {
    fbb_.AddOffset(Object1::VT_TEXT, text);
  }
  void add_boolean(bool boolean) {
    fbb_.AddElement<uint8_t>(Object1::VT_BOOLEAN, static_cast<uint8_t>(boolean), 0);
  }
  Object1Builder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  Object1Builder &operator=(const Object1Builder &);
  flatbuffers::Offset<Object1> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Object1>(end);
    fbb_.Required(o, Object1::VT_TEXT);
    return o;
  }
};

inline flatbuffers::Offset<Object1> CreateObject1(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> text = 0,
    bool boolean = false) {
  Object1Builder builder_(_fbb);
  builder_.add_text(text);
  builder_.add_boolean(boolean);
  return builder_.Finish();
}

inline flatbuffers::Offset<Object1> CreateObject1Direct(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *text = nullptr,
    bool boolean = false) {
  return sample::CreateObject1(
      _fbb,
      text ? _fbb.CreateString(text) : 0,
      boolean);
}

flatbuffers::Offset<Object1> CreateObject1(flatbuffers::FlatBufferBuilder &_fbb, const Object1T *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct Object2T : public flatbuffers::NativeTable {
  typedef Object2 TableType;
  std::string text;
  int32_t integer;
  Object2T()
      : integer(0) {
  }
};

struct Object2 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef Object2T NativeTableType;
  enum {
    VT_TEXT = 4,
    VT_INTEGER = 6
  };
  const flatbuffers::String *text() const {
    return GetPointer<const flatbuffers::String *>(VT_TEXT);
  }
  int32_t integer() const {
    return GetField<int32_t>(VT_INTEGER, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_TEXT) &&
           verifier.Verify(text()) &&
           VerifyField<int32_t>(verifier, VT_INTEGER) &&
           verifier.EndTable();
  }
  Object2T *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(Object2T *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<Object2> Pack(flatbuffers::FlatBufferBuilder &_fbb, const Object2T* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct Object2Builder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_text(flatbuffers::Offset<flatbuffers::String> text) {
    fbb_.AddOffset(Object2::VT_TEXT, text);
  }
  void add_integer(int32_t integer) {
    fbb_.AddElement<int32_t>(Object2::VT_INTEGER, integer, 0);
  }
  Object2Builder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  Object2Builder &operator=(const Object2Builder &);
  flatbuffers::Offset<Object2> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Object2>(end);
    fbb_.Required(o, Object2::VT_TEXT);
    return o;
  }
};

inline flatbuffers::Offset<Object2> CreateObject2(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> text = 0,
    int32_t integer = 0) {
  Object2Builder builder_(_fbb);
  builder_.add_integer(integer);
  builder_.add_text(text);
  return builder_.Finish();
}

inline flatbuffers::Offset<Object2> CreateObject2Direct(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *text = nullptr,
    int32_t integer = 0) {
  return sample::CreateObject2(
      _fbb,
      text ? _fbb.CreateString(text) : 0,
      integer);
}

flatbuffers::Offset<Object2> CreateObject2(flatbuffers::FlatBufferBuilder &_fbb, const Object2T *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct SampleRootT : public flatbuffers::NativeTable {
  typedef SampleRoot TableType;
  std::vector<Object> objects_type;
  std::vector<ObjectUnion> objects;
  SampleRootT() {
  }
};

struct SampleRoot FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef SampleRootT NativeTableType;
  enum {
    VT_OBJECTS_TYPE = 4,
    VT_OBJECTS = 6
  };
  const flatbuffers::Vector<uint8_t> *objects_type() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_OBJECTS_TYPE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<void>> *objects() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<void>> *>(VT_OBJECTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBJECTS_TYPE) &&
           verifier.Verify(objects_type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBJECTS) &&
           verifier.Verify(objects()) &&
           VerifyObjectVector(verifier, objects(), objects_type()) &&
           verifier.EndTable();
  }
  SampleRootT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(SampleRootT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<SampleRoot> Pack(flatbuffers::FlatBufferBuilder &_fbb, const SampleRootT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct SampleRootBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_objects_type(flatbuffers::Offset<flatbuffers::Vector<Object>> objects_type) {
    fbb_.AddOffset(SampleRoot::VT_OBJECTS_TYPE, objects_type);
  }
  void add_objects(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> objects) {
    fbb_.AddOffset(SampleRoot::VT_OBJECTS, objects);
  }
  SampleRootBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SampleRootBuilder &operator=(const SampleRootBuilder &);
  flatbuffers::Offset<SampleRoot> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<SampleRoot>(end);
    return o;
  }
};

inline flatbuffers::Offset<SampleRoot> CreateSampleRoot(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<Object>> objects_type = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> objects = 0) {
  SampleRootBuilder builder_(_fbb);
  builder_.add_objects(objects);
  builder_.add_objects_type(objects_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<SampleRoot> CreateSampleRootDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<Object> objects_type,
    const std::vector<flatbuffers::Offset<void>> *objects = nullptr) {
  return sample::CreateSampleRoot(
      _fbb,
      !objects_type.empty() ? _fbb.CreateVector<Object>(objects_type) : Object_NONE,
      objects ? _fbb.CreateVector<flatbuffers::Offset<void>>(*objects) : 0);
}

flatbuffers::Offset<SampleRoot> CreateSampleRoot(flatbuffers::FlatBufferBuilder &_fbb, const SampleRootT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline Object1T *Object1::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new Object1T();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Object1::UnPackTo(Object1T *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = text(); if (_e) _o->text = _e->str(); };
  { auto _e = boolean(); _o->boolean = _e; };
}

inline flatbuffers::Offset<Object1> Object1::Pack(flatbuffers::FlatBufferBuilder &_fbb, const Object1T* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateObject1(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Object1> CreateObject1(flatbuffers::FlatBufferBuilder &_fbb, const Object1T *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  auto _text = _fbb.CreateString(_o->text);
  auto _boolean = _o->boolean;
  return sample::CreateObject1(
      _fbb,
      _text,
      _boolean);
}

inline Object2T *Object2::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new Object2T();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void Object2::UnPackTo(Object2T *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = text(); if (_e) _o->text = _e->str(); };
  { auto _e = integer(); _o->integer = _e; };
}

inline flatbuffers::Offset<Object2> Object2::Pack(flatbuffers::FlatBufferBuilder &_fbb, const Object2T* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateObject2(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<Object2> CreateObject2(flatbuffers::FlatBufferBuilder &_fbb, const Object2T *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  auto _text = _fbb.CreateString(_o->text);
  auto _integer = _o->integer;
  return sample::CreateObject2(
      _fbb,
      _text,
      _integer);
}

inline SampleRootT *SampleRoot::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new SampleRootT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void
SampleRoot::UnPackTo(SampleRootT *_o,
                     const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;

  {
    auto _e = objects_type();
    if (_e) {
      for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) {
        _o->objects_type.emplace_back(static_cast<Object>(_e->Get(_i)));
      }
    }
  };

  {
    auto _e = objects();
    if (_e) {
      _o->objects.resize(_o->objects_type.size());
      for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) {
        _o->objects[_i].type = static_cast<Object>(objects_type()->Get(_i));
        _o->objects[_i].table = ObjectUnion::UnPack(
            _e->Get(_i), static_cast<Object>(objects_type()->Get(_i)),
            _resolver);
      }
    }
  };
}

inline flatbuffers::Offset<SampleRoot> SampleRoot::Pack(flatbuffers::FlatBufferBuilder &_fbb, const SampleRootT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateSampleRoot(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<SampleRoot>
CreateSampleRoot(flatbuffers::FlatBufferBuilder &_fbb, const SampleRootT *_o,
                 const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;

  // no use `_rehasher`

  flatbuffers::Offset<flatbuffers::Vector<sample::Object> > _objects_type =
      _o->objects_type.size()
          ? _fbb.CreateVector((const Object *)_o->objects_type.data(),
                              _o->objects_type.size())
          : 0; // Vectorが空のときOffsetに0を突っ込むのはsecure?

  // std::cout << "CreateSampleRoot:: ENUM: " << _objects_type << "\n";
  // std::vector<unsigned char*>  _objects; _objects.resize(_o->objects.size());
  std::vector<flatbuffers::Offset<void>> _objects;
//   std::transform(_o->_objects.begin(), _o->_objects.end(), _o->_objects.begin(), std::back_inserter(_objects)); // lambdaでPack必要
  _objects.resize(_o->objects.size());
  for (auto _i = 0; _i < _objects.size(); ++_i) {
    _objects[_i] = _o->objects[_i].Pack(_fbb);
  }
  // auto _objects = _o->objects.size() ? _fbb.CreateVector((const unsigned
  // char*)_o->objects.data(), _o->objects.size()) : 0;
  return sample::CreateSampleRoot(
      _fbb, _objects_type,
      _fbb.CreateVector<flatbuffers::Offset<void>>(_objects));
}

inline bool VerifyObject(flatbuffers::Verifier &verifier, const void *obj, Object type) {
  switch (type) {
    case Object_NONE: {
      return true;
    }
    case Object_Object1: {
      auto ptr = reinterpret_cast<const Object1 *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Object_Object2: {
      auto ptr = reinterpret_cast<const Object2 *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyObjectVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyObject(
        verifier,  values->Get(i), types->GetEnum<Object>(i))) {
      return false;
    }
  }
  return true;
}

inline flatbuffers::NativeTable *ObjectUnion::UnPack(const void *obj, Object type, const flatbuffers::resolver_function_t *resolver) {
  // ObjectUnionのUnPackはHogeT型のUnionの実体になるNativeTableを生成する
  // そのため、enumで指定された型にswitchで分岐させ、適切なHogeT型にUnPack()による生成を委譲する。
  switch (type) {
    case Object_Object1: {
      auto ptr = reinterpret_cast<const Object1 *>(obj);
      // return nullptrにしたらLEAKが起こらない。ObjectUnionのReset()によって、tableがdeleteされようとしても、delete nullptrは実害なし。
      return ptr->UnPack(resolver);// LEAK OCCURS.
    }
    case Object_Object2: {
      auto ptr = reinterpret_cast<const Object2 *>(obj);
      return ptr->UnPack(resolver);
    }
    default: return nullptr;
  }
}

inline flatbuffers::Offset<void> ObjectUnion::Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *_rehasher) const {
  switch (type) {
    case Object_Object1: {
      auto ptr = reinterpret_cast<const Object1T *>(table);
      // unionは静的な型情報を消す。型はenumで管理される。
      // HogeT型の内容をHoge型のOffsetに変換する。CreateHogeを通じてHogeBuilderを介して生成される。
      return CreateObject1(_fbb, ptr, _rehasher).Union();
    }
    case Object_Object2: {
      auto ptr = reinterpret_cast<const Object2T *>(table);
      return CreateObject2(_fbb, ptr, _rehasher).Union();
    }
    default: return 0;
  }
}

inline void ObjectUnion::Reset() {
  switch (type) {
    case Object_Object1: {
      std::cout << "LET'S DELETE ObjectUnion!\n";
      auto ptr = reinterpret_cast<Object1T *>(table);
      delete ptr;
      break;
    }
    case Object_Object2: {
      auto ptr = reinterpret_cast<Object2T *>(table);
      delete ptr;
      break;
    }
    default: break;
  }
  table = nullptr;
  type = Object_NONE;
}

inline const sample::SampleRoot *GetSampleRoot(const void *buf) {
  return flatbuffers::GetRoot<sample::SampleRoot>(buf);
}

inline bool VerifySampleRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sample::SampleRoot>(nullptr);
}

inline void FinishSampleRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<sample::SampleRoot> root) {
  fbb.Finish(root);
}

inline std::unique_ptr<SampleRootT> UnPackSampleRoot(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<SampleRootT>(GetSampleRoot(buf)->UnPack(res));
}

}  // namespace sample

#endif  // FLATBUFFERS_GENERATED_SAMPLE_SAMPLE_H_
