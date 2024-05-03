#include "prescrit_core_impl.h"

kj::Promise<void> PrescritCoreImpl::echo(EchoContext context) {

    return kj::READY_NOW;
}

kj::Promise<void> PrescritCoreImpl::createUser(CreateUserContext context) {

    // Create the user in the database
    

    // Return the result of the database operation

    return kj::READY_NOW;
}
