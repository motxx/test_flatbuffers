#ifndef IROHA_FLATBUF_WRAPPER_HPP
#define IROHA_FLATBUF_WRAPPER_HPP

#include "sample_generated.h"
#include <string>

namespace IrohaFlatbuf {

struct OffsetUnion {
  uint8_t type;
  flatbuffers::Offset<void> obj;
};

// Args...に union vector
// が含まれる場合、enumのvectorとunionのvectorを２つ用意する方法になるかもしれない
template <typename... Args>
inline OffsetUnion CreateObject1(flatbuffers::FlatBufferBuilder &_fbb,
                                 Args &&... args) {
  return OffsetUnion{
      sample::Object::Object_Object1,
      sample::CreateObject1Direct(_fbb, std::forward<Args>(args)...).Union()};
}

template <typename... Args>
inline OffsetUnion CreateObject2(flatbuffers::FlatBufferBuilder &_fbb,
                                 Args &&... args) {
  return OffsetUnion{
      sample::Object::Object_Object2,
      sample::CreateObject2Direct(_fbb, std::forward<Args>(args)...).Union()};
}

template <typename... Args>
inline OffsetUnion CreateObject3(flatbuffers::FlatBufferBuilder &_fbb,
                                 Args &&... args) {
  return OffsetUnion{
      sample::Object::Object_Object3,
      sample::CreateObject3Direct(_fbb, std::forward<Args>(args)...).Union()};
}

flatbuffers::Offset<sample::SampleRoot> inline CreateSampleRoot(
    flatbuffers::FlatBufferBuilder &_fbb, std::vector<OffsetUnion> &&o) {
  std::vector<uint8_t> types;
  std::vector<flatbuffers::Offset<void>> objects;
  for (std::size_t i = 0; i < o.size(); ++i) {
    types.push_back(o[i].type);
    objects.push_back(std::move(o[i].obj));
  }
  return sample::CreateSampleRootDirect(_fbb, &types, &objects);
}

} // namespace IrohaFlatbuf

#endif // IROHA_FLATBUF_WRAPPER_HPP
