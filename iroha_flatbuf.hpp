#ifndef IROHA_FLATBUF_WRAPPER_HPP
#define IROHA_FLATBUF_WRAPPER_HPP

#include "sample_generated.h"
#include <string>

namespace IrohaFlatbuf {

struct OffsetUnion {
  uint8_t type;
  flatbuffers::Offset<void> obj;
};
/*
template <typename T> struct OffsetRet {
  typedef flatbuffers::Offset<T> ReturnType;
};

template <> struct OffsetRet<const char*> {
  typedef flatbuffers::Offset<flatbuffers::String> ReturnType;
};

template <> struct OffsetRet<std::string> {
  typedef flatbuffers::Offset<flatbuffers::String> ReturnType;
};

OffsetRet<const char*>::ReturnType CreateObjectDirect(const char* val) {
  return flatbuffers::Offset<flatbuffers::String>();//flatbuffers::CreateString(val);
}

OffsetRet<std::string>::ReturnType CreateObjectDirect(const std::string &val) {
  return flatbuffers::Offset<flatbuffers::String>();//flatbuffers::CreateString(val);
}

template <typename T> typename OffsetRet<T>::ReturnType CreateObjectDirect(T val) { return val; }
*/
template <typename... Args>
OffsetUnion CreateObject1(flatbuffers::FlatBufferBuilder &_fbb,
                          Args &&... args) {
  return OffsetUnion{sample::Object::Object_Object1, sample::CreateObject1Direct(_fbb, std::forward<Args>(args)...).Union()};
}

/*
template<typename Args...>
OffsetUnion CreateObject(flatbuffers::FlatBufferBuilder &_fbb, uint8_t type,
                         Args &&... args) {
  switch (type) {
    case Object::Object_Object1: {
      return CreateObject1(_fbb, CreateObjectDirect(args)...);
    }
    case Object::Object_Object2: {
      return CreateObject2(_fbb, CreateObjectDirect(args)...);
    }
    default: return 0;
  }
}
*/
} // namespace IrohaFlatbuf

#endif // IROHA_FLATBUF_WRAPPER_HPP
