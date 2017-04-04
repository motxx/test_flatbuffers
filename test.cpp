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
        {
            std::vector<IrohaFlatbuf::OffsetUnion> objects;
            objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, "naobou",  /*boolean=*/true));
            objects.emplace_back(IrohaFlatbuf::CreateObject2(fbb, "kayanon",  /*integer=*/623));
            objects.emplace_back(IrohaFlatbuf::CreateObject3(fbb, "inosuke",  /*str=*/"pray"));
            objects.emplace_back(IrohaFlatbuf::CreateObject2(fbb, "nanjolno", /*integer=*/123));

            const auto sample_offset =
                IrohaFlatbuf::CreateSampleRoot(fbb, std::move(objects));
            FinishSampleRootBuffer(fbb, sample_offset);
        }

        flatbuffers::Verifier verifier(fbb.GetBufferPointer(), fbb.GetSize());
        assert(VerifySampleRootBuffer(verifier));
        buf_ptr = fbb.ReleaseBufferPointer();
    }

    // Decode test
    {
        const SampleRoot *sample = GetSampleRoot(buf_ptr.get());
        assert(sample->objects_type()->size() == 4);
        assert(sample->objects_type()->GetEnum<Object>(0) == Object::Object_Object1);
        assert(sample->objects_type()->GetEnum<Object>(1) == Object::Object_Object2);
        assert(sample->objects_type()->GetEnum<Object>(2) == Object::Object_Object3);
        assert(sample->objects_type()->GetEnum<Object>(3) == Object::Object_Object2);

        assert(sample->objects()->size() == 4);
        {
            const auto *obj =
                reinterpret_cast<const Object1 *>(sample->objects()->Get(0));
            assert(obj->text()->str() == "naobou");
            assert(obj->boolean());
        }
        {
            const auto *obj =
                reinterpret_cast<const Object2 *>(sample->objects()->Get(1));
            assert(obj->text()->str() == "kayanon");
            assert(obj->integer() == 623);
        }
        {
            const auto *obj =
                reinterpret_cast<const Object3 *>(sample->objects()->Get(2));
            assert(obj->text()->str() == "inosuke");
            assert(obj->message()->str() == "pray");
        }
        {
            const auto *obj =
                reinterpret_cast<const Object2 *>(sample->objects()->Get(3));
            assert(obj->text()->str() == "nanjolno");
            assert(obj->integer() == 123);
        }
    }
    {
        flatbuffers::FlatBufferBuilder fbb;
        const SampleRoot *sample = GetSampleRoot(buf_ptr.get());

        assert(sample->objects_type()->size() == sample->objects()->size());

        std::vector<IrohaFlatbuf::OffsetUnion> objects;

        for (int i = 0; i < sample->objects()->size(); ++i){
            auto t = sample->objects_type()->Get(i);
            auto v = sample->objects()->Get(i);



            objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, "naobou",  /*boolean=*/true));
            objects.emplace_back(IrohaFlatbuf::CreateObject2(fbb, "kayanon",  /*integer=*/623));
            objects.emplace_back(IrohaFlatbuf::CreateObject3(fbb, "inosuke",  /*str=*/"pray"));
            objects.emplace_back(IrohaFlatbuf::CreateObject2(fbb, "nanjolno", /*integer=*/123));


            switch (t) {
                case Object::Object_Object1: {
                    auto obj = reinterpret_cast<const Object1 *>(v);
                    objects.emplace_back(IrohaFlatbuf::CreateObject1(fbb, obj->text()->str().c_str(), obj->boolean()));
                    break;
                }
                case Object::Object_Object2: {
                    auto obj = reinterpret_cast<const Object2 *>(v);
                    objects.emplace_back(IrohaFlatbuf::CreateObject2(fbb, obj->text()->str().c_str(), obj->integer()));
                    break;
                }
                case Object::Object_Object3: {
                    auto obj = reinterpret_cast<const Object3 *>(v);
                    objects.emplace_back(IrohaFlatbuf::CreateObject3(fbb, obj->text()->str().c_str(), obj->message()->str().c_str()));
                    break;
                }
            }
        }

        const auto sample_offset =
            IrohaFlatbuf::CreateSampleRoot(fbb, std::move(objects));
        FinishSampleRootBuffer(fbb, sample_offset);
        auto buf = fbb.GetBufferPointer();
        flatbuffers::Verifier verifier(buf, fbb.GetSize());
        assert(VerifySampleRootBuffer(verifier));
    }

    return 0;
}
