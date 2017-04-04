#ifndef IROHA_FLATBUF_WRAPPER_HPP
#define IROHA_FLATBUF_WRAPPER_HPP

#include "sample_generated.h"

namespace IrohaFlatbuf {

struct OffsetUnion {
  uint8_t type;
  Offset<void> obj;
};

using OffsetUnion = flatbuffers::Offset<void>;

struct nil {};

template<typename T>
struct OffsetRet {
  typedef nil ReturnType;
};

template<>
struct OffsetRet<std::string> {
  typedef flatbuffers::String ReturnType;
};

template<>
struct OffsetRet<int> {
  typedef flatbuffers:: ReturnType;
};

template<typename T, typename U>
flatbuffers::Offset<U> CreateObjectDirect(T val) {

}

template<typename Head, typename Rest...>
OffsetUnion CreateObject(flatbufefrs::FlatBufferBuilder &_fbb, uint8_t type,
                         Head &&head, Rest&& ... rest) {
  switch (type) {
    case Object::Object_Object1: {
      return CreateObject1(_fbb, CreateObjectDirect<Head, OffsetRet<Head>::ReturnType>(head), CreateObjectDirect(rest)...);
    }
    case Object::Object_Object2: {
      return CreateObject1(_fbb, CreateObjectDirect(head), CreateObjectDirect(rest)...);
    }
    default: return 0;
  }
}

template<typename Args...>
OffsetUnion CreateObject(flatbuffers::FlatBufferBuilder &_fbb, uint8_t type,
                         Args &&... args) {
//  return {type, sample::CreateObject(_fbb, text ? _fbb.CreateString(text) : 0, boolean)};
}
}

#endif // IROHA_FLATBUF_WRAPPER_HPP