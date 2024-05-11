#ifndef PRESCRIT_CORE_IMPL_H
#define PRESCRIT_CORE_IMPL_H

#include "lib/src/prescrit_interface.capnp.h"

struct PrescritCoreImpl final : public PrescritCore::Server {

    kj::Promise<void> echo(EchoContext context);
    kj::Promise<void> createUser(CreateUserContext context);

};

#endif
