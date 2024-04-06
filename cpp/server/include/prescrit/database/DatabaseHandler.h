#ifndef DATABASEHANDLER_H 
#define DATABASEHANDLER_H

#include "storables.h"

// Database handler and functions defined here

class DatabaseHandler {

	bool connect();

	void disconnect();

	bool createEntry(Storable *);

	Storable *readEntry();

	bool updateEntry(Storable *);

	bool deleteEntry(Storable *);
};

#endif // !
