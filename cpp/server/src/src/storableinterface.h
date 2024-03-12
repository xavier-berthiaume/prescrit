#ifndef STORABLEINTERFACE_H
#define STORABLEINTERFACE_H

// Storable interface, all classes that represent objects
// that can be stored MUST implement this interface

struct Storable {

	virtual void createStorable() = 0;

	virtual void readStorable() = 0;

	virtual void updateStorable() = 0;

	virtual void deleteStorable() = 0;

};

#endif
