#include "prescrit_core_impl.h"

#include <iostream>

kj::Promise<void> PrescritCoreImpl::echo(EchoContext context) {

    std::cout << "Echo call\n";
    return kj::READY_NOW;
}

kj::Promise<void> PrescritCoreImpl::createUser(CreateUserContext context) {

    std::cout << "CreateUser call\n";
    // Create the user in the database
    

    // Return the result of the database operation

    return kj::READY_NOW;
}
