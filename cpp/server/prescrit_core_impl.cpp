#include "prescrit_core_impl.h"
#include "DatabaseHandler.h"
#include "user.h"

#include <capnp/message.h>
#include <iostream>

kj::Promise<void> PrescritCoreImpl::echo(EchoContext context) {

    std::cout << "Echo call\n";
    return kj::READY_NOW;
}

kj::Promise<void> PrescritCoreImpl::createUser(CreateUserContext context) {

    std::cout << "CreateUser call\n";
    // Create the user storable object
    User createdUser = User();
    createdUser.firstName_ = context.getParams().getUser().getFirstName().cStr();
    createdUser.lastName_ = context.getParams().getUser().getLastName().cStr();
    createdUser.username_ = context.getParams().getUser().getUsername().cStr();
    createdUser.password_ = context.getParams().getUser().getPassword().cStr();

    // Create the user in the database
    AbstractDatabaseHandler *db = AbstractDatabaseHandler::getInstance();
    if(db->saveStorable(&createdUser)) {
        context.getResults().setStatus(true);
    } else {
        context.getResults().setStatus(false);
    }

    /*
     * Eventually implement the bottom functionality to return the data directly from the database back
     * to the client. Might not be useful and should be removed if that' the case

    // Return the result of the database operation
    capnp::MallocMessageBuilder messageBuilder;
    Serializers::User::Builder userBuilder = messageBuilder.initRoot<Serializers::User>();
    userBuilder.setId(createdUser.id_);
    userBuilder.setFirstName(createdUser.firstName_);
    userBuilder.setLastName(createdUser.lastName_);
    userBuilder.setUsername(createdUser.username_);
    userBuilder.setPassword(createdUser.password_);

    */

    return kj::READY_NOW;
}
    
kj::Promise<void> PrescritCoreImpl::checkUsernameAvailable(CheckUsernameAvailableContext context) {

    std::cout << "CheckUsernameAvailable call\n";
    std::cout << "Username passed: " << context.getParams().getName().cStr() << "\n";

    std::cout << "Checking for username in database...\n";

    AbstractDatabaseHandler *db = AbstractDatabaseHandler::getInstance();
    
    // Create a storable with only the username field filled out, then read it from the database
    User *user = new User();
    user->username_ = context.getParams().getName().cStr();
    std::vector<unsigned int> columnList = {3};
    db->readStorable(user, columnList);

    // If the user object has an ID of 0, then that means that there isn't a database
    // entry that 'filled out' the information of the user object, therefore there's no
    // entry.
    if(user->id_ != 0) {
        std::cout << "Username is taken" << std::endl;
        context.getResults().setStatus(false);
    } else {
        std::cout << "Username is not taken" << std::endl;
        context.getResults().setStatus(true);
    }
    
    delete user;
    return kj::READY_NOW;
}
