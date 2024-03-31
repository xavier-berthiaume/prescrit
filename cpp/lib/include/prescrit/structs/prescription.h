#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <algorithm>
#include <string>
#include <ctime>

#include "../globals.h"
#include "../utils.h"
#include "prescriber.h"
#include "product.h"

class Prescription {

	Product *originalProduct_;
	Product *givenProduct_;
protected:

	std::tm originalDate_;
	std::tm expiryDate_;
	std::tm refillDate_;

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

	Prescription();
	Prescription(Prescription *);
	~Prescription();

	std::tm getOriginalDate() const;
	std::tm getExpiryDate() const;
	std::tm getRefillDate() const;

	Prescriber *getPrescriber() const;

	virtual Product *getOriginalProduct() const;
	virtual Product *getGivenProduct() const;

	unsigned int getOriginalQuantity() const;
	unsigned short getOriginalRefills() const;
	unsigned int getRemainingQuantity() const;
	unsigned int getRefillQuantity() const;

	Prescription *getPreviousRefill() const;
	
	void setOriginalDate(tm *);
	void setExpiryDate(tm *);
	void setRefillDate(tm *);
	void setOriginalDate(const unsigned short&, const unsigned short&, const unsigned short&);
	void setExpiryDate(const unsigned short&, const unsigned short&, const unsigned short&);
	void setRefillDate(const unsigned short&, const unsigned short&, const unsigned short&);
	
	void setPrescriber(Prescriber *);
	
	virtual void setOriginalProduct(Product *);
	virtual void setGivenProduct(Product *); 

	void setOriginalQuantity(const unsigned int&);
	void setOriginalRefills(const unsigned short&);
	void setRemainingQuantity(const unsigned int&);
	void setRefillQuantity(unsigned int);

	void setPreviousRefill(Prescription *);
};

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

#endif // !PRESCRIPTION_H
