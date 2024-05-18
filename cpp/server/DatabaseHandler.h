#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <vector>

#include "storable.h"

/**
 * @class AbstractDatabaseHandler
 *
 * @details Abstract class that needs to be implemented
 * for any database handler class. Database handlers should
 * be implementations of storage backends. Expectation is that 
 * the handlers are implemented as singletons.
 */

struct AbstractDatabaseHandler {

    virtual bool saveStorable(Storable *) = 0;
    // Save the storable to the database, and return the created database storable
    virtual bool saveAndReturnStorable(Storable *) = 0;
    virtual void readStorable(Storable *, std::vector<unsigned int>) = 0;
    virtual void readMultipleStorables(std::vector<Storable *>, std::vector<unsigned int>) = 0;
    virtual void updateStorable(Storable *) = 0;
    virtual void deleteStorable(Storable *) = 0;

    virtual void createTable(const std::string &, std::vector<Column>) = 0;

    static AbstractDatabaseHandler *getInstance();

protected:
    static AbstractDatabaseHandler *instance;
};

#endif
