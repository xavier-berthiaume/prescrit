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

	virtual Prescription *refill(const unsigned int&);
};

class Normal : public Prescription {

	// Premades
	Premade *originalProduct_;
	Premade *givenProduct_;
public:

	Normal();
	Normal(Normal *);
	~Normal();

	Premade *getOriginalProduct() const override;
	Premade *getGivenProduct() const override;
	void setOriginalProduct(Product *) override;
	void setGivenProduct(Product *) override;

	Prescription *refill(const unsigned int&) override;
};

class Magistral : public Prescription {

	Product *product_;
	// Just a list of ingredients
	std::vector<Premade *> ingredients_;
public:

	Magistral();
	Magistral(Magistral *);
	~Magistral();

	std::vector<Premade *> getIngredients() const;
	void addIngredient(Premade *);
	void removeIngredient(Premade *);

	// Although both getters and setters are included here, they will both point to the same thing
	Product *getOriginalProduct() const override;
	Product *getGivenProduct() const override;
	void setOriginalProduct(Product *) override;
	void setGivenProduct(Product *) override;

	Prescription *refill(const unsigned int&) override;
};

struct PrescriptionRefillList {

	PrescriptionRefillList();
	PrescriptionRefillList(PrescriptionRefillList *);
	~PrescriptionRefillList();

	Prescription *getNextPrescription(Prescription *);
	Prescription *getHead();
private:

	Prescription *head;
};

#endif // !PRESCRIPTION_H
