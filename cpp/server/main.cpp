#include <iostream>
#include <capnp/rpc.h>
#include <capnp/ez-rpc.h>

#include <prescrit/network/rpc_interface.capnp.h>

class RpcServiceImpl final : public RpcService::Server {
    // Implementation of the interface
    
    public:
        kj::Promise<void> hello(HelloContext context) override {
            std::cout << "Success at triggering the function" << std::endl;

            return kj::READY_NOW;
        }
};

int main(int argc, char *argv[]) {

  capnp::EzRpcServer server(kj::heap<RpcServiceImpl>(), "127.0.0.1", 6000);
  auto& waitscope = server.getWaitScope();

  kj::NEVER_DONE.wait(waitscope);
}
