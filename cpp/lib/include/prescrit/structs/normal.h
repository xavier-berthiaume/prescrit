#ifndef NORMAL_H
#define NORMAL_H

#include "prescription.h"

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
    // For these setters, check the class of object you're receiving
    // It'll be derived from Product, and then create a correctly
    // assigned deep copy
	void setOriginalProduct(Product *) override;
	void setGivenProduct(Product *) override;
};

#endif
