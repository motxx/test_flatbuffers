//#include "sample_generated.h"
#include "iroha_flatbuf.hpp"
#include <cassert>
#include <memory>

#include <iostream>

using namespace sample;

int main(){

    flatbuffers::unique_ptr_t buf_ptr;
    // Encode test
    {
        flatbuffers::FlatBufferBuilder fbb;

        // union values.
        std::vector<IrohaFlatbuf::OffsetUnion> objects;
        objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, "naobou",   /*boolean=*/true));
        objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, "toyama",   /*boolean=*/true));
        objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, "TOYAMA",   /*boolean=*/true));
        objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, "NAOBOU",   /*boolean=*/true));
/*
        const auto sample_offset =
            IrohaFlatbuf::CreateSampleRootDirect(fbb, &objects);
        FinishSampleRootBuffer(fbb, sample_offset);
        flatbuffers::Verifier verifier(fbb.GetBufferPointer(), fbb.GetSize());
        assert(VerifySampleRootBuffer(verifier));

        buf_ptr = fbb.ReleaseBufferPointer();
        */
    }
    /*
    // Decode test
    {
        const SampleRoot *sample = GetSampleRoot(buf_ptr.get());
        assert(sample->objects_type()->size() == 4);
        assert(sample->objects_type()->GetEnum<Object>(0) == Object::Object_Object1);
        assert(sample->objects_type()->GetEnum<Object>(1) == Object::Object_Object1);
        assert(sample->objects_type()->GetEnum<Object>(2) == Object::Object_Object1);
        assert(sample->objects_type()->GetEnum<Object>(3) == Object::Object_Object1);

        assert(sample->objects()->size() == 4);
        {
            const Object1 *obj =
                reinterpret_cast<const Object1 *>(sample->objects()->Get(0));
            assert(obj->text()->str() == "naobou");
            assert(obj->boolean());
        }
        {
            const Object1 *obj =
                reinterpret_cast<const Object1 *>(sample->objects()->Get(1));
            assert(obj->text()->str() == "toyama");
            assert(obj->boolean());
        }
        {
            const Object1 *obj =
                reinterpret_cast<const Object1 *>(sample->objects()->Get(2));
            assert(obj->text()->str() == "TOYAMA");
            assert(obj->boolean());
        }
        {
            const Object1 *obj =
                reinterpret_cast<const Object1 *>(sample->objects()->Get(3));
            assert(obj->text()->str() == "NAOBOU");
            assert(obj->boolean());
        }
    }
    {
        flatbuffers::FlatBufferBuilder fbb;
        const SampleRoot *sample = GetSampleRoot(buf_ptr.get());

        assert(sample->objects_type()->size() == sample->objects()->size());

        std::vector<uint8_t> types;
        std::vector<flatbuffers::Offset<void>> objects;

        for(int i=0;i < sample->objects()->size(); ++i){
            auto t = sample->objects_type()->Get(i);
            auto v = sample->objects()->Get(i);
            switch (t) {
                case Object::Object_Object1: {
                    auto obj = reinterpret_cast<const Object1 *>(v);
                    types.emplace_back(t);
                    objects.emplace_back(
                            CreateObject1Direct(fbb, obj->text()->str().c_str(), obj->boolean()).Union()); break;
                }
                case Object::Object_Object2: {
                    auto obj = reinterpret_cast<const Object2 *>(v);
                    types.emplace_back(t);
                    objects.emplace_back(
                            CreateObject2Direct(fbb, obj->text()->str().c_str(), obj->integer()).Union()); break;
                }
                case Object::Object_Object3: {
                    auto obj = reinterpret_cast<const Object3 *>(v);
                    types.emplace_back(t);
                    objects.emplace_back(
                            CreateObject3Direct(fbb, obj->text()->str().c_str(), obj->message()->str().c_str()).Union()); break;
                }
            }
        }

        const auto sample_offset =
            CreateSampleRootDirect(fbb, &types, &objects);
        FinishSampleRootBuffer(fbb, sample_offset);
        auto buf = fbb.GetBufferPointer();
        flatbuffers::Verifier verifier(buf, fbb.GetSize());
        assert(VerifySampleRootBuffer(verifier));
    }
    */
    return 0;
}
