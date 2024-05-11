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
    
kj::Promise<void> PrescritCoreImpl::checkUsernameAvailable(CheckUsernameAvailableContext context) {

    std::cout << "CheckUsernameAvailable call\n";
    std::cout << "Username passed: " << context.getParams().getName().cStr() << "\n";
    // Actually poll the database to see if the sent username exists
    // For now this will be a dummy function that just says true/false
    // on some set username for testing purposes
    
    if(context.getParams().getName() == "xavier1") {
        context.getResults().setStatus(true);
    } else {
        context.getResults().setStatus(false);
    }

    return kj::READY_NOW;
}
