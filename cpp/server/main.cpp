#include "prescrit_core_impl.h"
#include "Mariadb.h"

#include "user.h"

#include <iostream>
#include <capnp/ez-rpc.h>

int main(int argc, char *argv[]) {

    if(argc != 3) {

        std::cout << "USAGE: server [DB NAME] [DB USERNAME]" << std::endl;
        return 1;
    }

    // Create the mariadb handler
    std::cout << "Creating database connection\n";
    MariadbHandler *db = MariadbHandler::init(argv[1], "localhost", argv[2], "");

    // Create the User Table
    std::cout << "Creating User() table\n";
    User *blankuser = new User;
    db->createTable(blankuser->kTableName_, blankuser->kColumnList_);
    delete blankuser;
    std::cout << "User() table created\n";

    std::cout << "Creating server\n";
    capnp::EzRpcServer server(kj::heap<PrescritCoreImpl>(), "127.0.0.1", 6000);
    

    std::cout << "Creation successful, starting to listen\n";
    kj::NEVER_DONE.wait(server.getWaitScope());
} 
