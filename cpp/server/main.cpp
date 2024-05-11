#include "prescrit_core_impl.h"

#include <iostream>
#include <capnp/ez-rpc.h>

int main(int argc, char *argv[]) {

    std::cout << "Creating server\n";
    capnp::EzRpcServer server(kj::heap<PrescritCoreImpl>(), "127.0.0.1", 6000);
    

    std::cout << "Creation successful, starting to listen\n";
    kj::NEVER_DONE.wait(server.getWaitScope());
} 
