#ifndef PRESCRIPTION_LIST_H
#define PRESCRIPTION_LIST_H

#include "../globals.h"
#include "prescription.h"
#include "normal.h"
#include "magistral.h"

struct PrescriptionRefillList {

	PrescriptionRefillList();
	PrescriptionRefillList(PrescriptionRefillList *);
	~PrescriptionRefillList();

	Prescription *getNextPrescription(Prescription *);
	Prescription *getHead();

	void setHead(Prescription *);

	bool refillPrescription(const unsigned int&);
private:

	Prescription *head;
};

#endif
