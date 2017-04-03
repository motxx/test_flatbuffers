#include "sample_generated.h"
#include <iostream>

using namespace sample;

void printVectorObjects(std::vector<ObjectUnion>& v) {
  std::cout << "[";
  for (std::size_t i=0; i<v.size(); ++i) {
    if (i) std::cout << ", ";
    std::cout << "("  << EnumNameObject(v[i].type);
    std::cout << ", " << (v[i].type == Object_Object1 ? v[i].AsObject1()->text    : v[i].AsObject2()->text);
    std::cout << ", " << (v[i].type == Object_Object1 ? v[i].AsObject1()->boolean : v[i].AsObject2()->integer) << ")";
  }
  std::cout << "]\n";
}

int main(){

  // テストとして以下の様なものが揃えられれば良さそう
  // vectorが
  //   1. 空のときのPack, UnPack
  //   2. 1要素のとき
  //   3. N要素のとき
  // unionが
  //   1. 空のとき
  //   2. N要素のとき

  auto sampleRootT = SampleRootT();

  for (int i=0; i<2; i++) {
    auto object2T = Object2T();
    object2T.text = "object2_text";
    object2T.integer = 12345;

    auto objectUnion2 = ObjectUnion();
    objectUnion2.Set(std::move(object2T));

    sampleRootT.objects.emplace_back(std::move(objectUnion2));
  }

  for (int i=0; i<2; i++) {
    auto object1T = Object1T();
    object1T.text = "object1_text";
    object1T.boolean = true;

    auto objectUnion = ObjectUnion();
    objectUnion.Set(std::move(object1T));

    sampleRootT.objects.emplace_back(std::move(objectUnion));
  }

  std::cout << "BEFORE PACK:\n";
  printVectorObjects(sampleRootT.objects);

  flatbuffers::FlatBufferBuilder fbb;
  fbb.Finish(SampleRoot::Pack(fbb, &sampleRootT));

  std::vector<uint8_t> buffer;
  auto ptr = reinterpret_cast<const uint8_t*>(fbb.GetBufferPointer());
  buffer.assign(ptr, ptr + fbb.GetSize());
  SampleRoot const* rsmpl = GetSampleRoot(reinterpret_cast<const uint8_t*>(buffer.data()));


  std::unique_ptr<SampleRootT> smplrtTPtr(rsmpl->UnPack());

  std::cout << "UNPACK:\n";
  std::cout << smplrtTPtr->objects.size() << std::endl;
  for (auto const &e: smplrtTPtr->objects) {
    std::cout << e.type << ", ";
  } puts("");
//  printVectorObjects(smplrtTPtr->objects);

  // "LET'S DELETE ObjectUnion!" が2回呼ばれる理由
  // 1. sampleRootT.objects[0] (<- moved from objectUnion) が呼ばれている
  // 2. smplrtTPtr.objects[0]

  return 0;
}