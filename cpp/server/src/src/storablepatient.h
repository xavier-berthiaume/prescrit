#ifndef STORABLEPATIENT_H
#define STORABLEPATIENT_H

#include "storableinterface.h"

// Class that will be used to wrap around the Patient class

class StorablePatient: Storable {

	void createStorable() override;

	void readStorable() override;

	void updateStorable() override;

	void deleteStorable() override;

	// StorablePatient(Patient *);
};

#endif // !STORABLEPATIENT_H
