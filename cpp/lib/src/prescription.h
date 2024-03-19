#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <algorithm>
#include <string>
#include <ctime>

#include "globalDefinitions.h"
#include "time.h"
#include "prescriber.h"
#include "product.h"

class Prescription {

	std::tm *originalDate_;
	std::tm *expiryDate_;
	std::tm *refillDate_;

	Prescriber *prescriber_;

	unsigned int originalQuantity_;
	unsigned short originalRefills_;
	unsigned int remainingQuantity_;
	unsigned int refillQuantity_;

	// Linked list implementation of refills
	// Each refill is its own Prescription instance with its
	// own data at that point
	Prescription *previousRefill_;
public:

	std::tm *getOriginalDate() const;
	std::tm *getExpiryDate() const;
	std::tm *getRefillDate() const;

	Prescriber *getPrescriber() const;

	unsigned int getOriginalQuantity() const;
	unsigned short getOriginalRefills() const;
	unsigned int getRemainingQuantity() const;
	unsigned int getRefillQuantity() const;

	Prescription *getPreviousRefill() const;

	void setOriginalDate(const unsigned short&, const unsigned short&, const unsigned short&);
	void setExpiryDate(const unsigned short&, const unsigned short&, const unsigned short&);
	void setRefillDate(const unsigned short&, const unsigned short&, const unsigned short&);
	
	void setPrescriber(Prescriber *);

	void setOriginalQuantity(const unsigned int&);
	void setOriginalRefills(const unsigned short&);
	void setRemainingQuantity(const unsigned int&);
	void setRefillQuantity(unsigned int);

	void setPreviousRefill(Prescription *);
};

class Normal : public Prescription {

	// Premades
	Premade *originalProduct_;
	Premade *givenProduct_;
public:
	Premade *getOriginalProduct() const;
	Premade *getGivenProduct() const;
	void setOriginalProduct(Premade *);
	void setGivenProduct(Premade *);
};

class Magistral : public Prescription {

	// Just a list of ingredients
	std::vector<Premade *> ingredients_;
public:
	std::vector<Premade *> getIngredients() const;
	void addIngredient(Premade *);
	void removeIngredient(Premade *);
};

class Misc : public Prescription {

	// Products
	Product *prescribedProduct_;
	Product *givenProduct_;
public:
	Product *getPrescribedProduct() const;
	Product *getGivenProduct() const;
	void setPrescribedProduct(Product *);
	void setGivenProduct(Product *);
};

#endif // !PRESCRIPTION_H
