#include "sample_generated.h"
#include <iostream>

using namespace sample;

int main(){

  auto object1T = Object1T();
  object1T.text = "object1_text";
  object1T.boolean = true;

  auto objectUnion  = ObjectUnion();
  objectUnion.Set(std::move(object1T));
  auto sampleRootT = SampleRootT();

  sampleRootT.objects_type.emplace_back(Object_Object1);
  sampleRootT.objects.emplace_back(std::move(objectUnion));

  for (int i=0; i<sampleRootT.objects_type.size(); ++i) {
    std::cout << sampleRootT.objects_type[i] << ", " << sampleRootT.objects[i].AsObject1()->text << std::endl;
  }

  flatbuffers::FlatBufferBuilder fbb;
  fbb.Finish(SampleRoot::Pack(fbb, &sampleRootT));

  std::vector<uint8_t> buffer;
  auto ptr = reinterpret_cast<const uint8_t*>(fbb.GetBufferPointer());
  buffer.assign(ptr, ptr + fbb.GetSize());
  SampleRoot const* rsmpl = GetSampleRoot(reinterpret_cast<const uint8_t*>(buffer.data()));

  std::cout << "UNPACK BEGIN\n";
  std::unique_ptr<SampleRootT> smplrtTPtr(rsmpl->UnPack());

  std::cout << "size = " << smplrtTPtr->objects.size() << "\n";

  std::cout << reinterpret_cast<Object1T *>(smplrtTPtr->objects[0].table)->text << std::endl;
  std::cout << smplrtTPtr->objects[0].AsObject1()->text << ", " << smplrtTPtr->objects[0].AsObject1()->boolean << std::endl;

  // "LET'S DELETE ObjectUnion!" が2回呼ばれる理由
  // 1. sampleRootT.objects[0] (<- moved from objectUnion) が呼ばれている
  // 2. smplrtTPtr.objects[0]
  
  return 0;
}