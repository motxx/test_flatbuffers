// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: sample

#include "sample_generated.h"
#include "sample.grpc.fb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace sample {

static const char* SampleService_method_names[] = {
  "/sample.SampleService/Endpoint",
};

std::unique_ptr< SampleService::Stub> SampleService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< SampleService::Stub> stub(new SampleService::Stub(channel));
  return stub;
}

SampleService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel)  , rpcmethod_Endpoint_(SampleService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}
  
::grpc::Status SampleService::Stub::Endpoint(::grpc::ClientContext* context, const flatbuffers::BufferRef<SampleRoot>& request, flatbuffers::BufferRef<Response>* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Endpoint_, context, request, response);
}

::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<Response>>* SampleService::Stub::AsyncEndpointRaw(::grpc::ClientContext* context, const flatbuffers::BufferRef<SampleRoot>& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< flatbuffers::BufferRef<Response>>(channel_.get(), cq, rpcmethod_Endpoint_, context, request);
}

SampleService::Service::Service() {
  (void)SampleService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      SampleService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< SampleService::Service, flatbuffers::BufferRef<SampleRoot>, flatbuffers::BufferRef<Response>>(
          std::mem_fn(&SampleService::Service::Endpoint), this)));
}

SampleService::Service::~Service() {
}

::grpc::Status SampleService::Service::Endpoint(::grpc::ServerContext* context, const flatbuffers::BufferRef<SampleRoot>* request, flatbuffers::BufferRef<Response>* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace sample

