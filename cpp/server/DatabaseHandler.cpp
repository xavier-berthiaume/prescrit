#include "DatabaseHandler.h"

AbstractDatabaseHandler *AbstractDatabaseHandler::instance = nullptr;

AbstractDatabaseHandler *AbstractDatabaseHandler::getInstance() {

    return instance;
}
