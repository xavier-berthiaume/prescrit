#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <string>
#include <ctime>

#include "globalDefinitions.h"
#include "prescriber.h"
#include "product.h"
#include "ingredient.h"

class Prescription {
	std::tm *originalDate_;
	std::tm *expiryDate_;
	std::tm *refillDate_;

	Prescriber *prescriber_;

	unsigned int originalQuantity_;
	unsigned short originalRefills_;
	unsigned int remainingQuantity_;

	// Linked list implementation of refills
	// Each refill is its own Prescription instance with its
	// own data at that point
	Prescription *previousRefill_;
};

class Normal : public Prescription {

	// Premades
	Premade *product_;
};

class Magistral : public Prescription {

	// Just a list of ingredients
	std::vector<Premade *> ingredients_;
};

class Misc : public Prescription {

	// Products
	
};

#endif // !PRESCRIPTION_H
