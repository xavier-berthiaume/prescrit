#ifndef MAGISTRAL_H
#define MAGISTRAL_H

#include "../globals.h"
#include "prescription.h"

class Magistral : public Prescription {

	Product *product_;
	// Just a list of ingredients
	std::vector<Premade *> constituentProducts_;
public:

	Magistral();
	Magistral(Magistral *);
	~Magistral();

	std::vector<Premade *> getConstituentProducts() const;
	void addIngredient(Premade *);
	void removeIngredient(Premade *);

	// Although both getters and setters are included here, they will both point to the same thing
	Product *getOriginalProduct() const override;
	Product *getGivenProduct() const override;
	void setOriginalProduct(Product *) override;
	void setGivenProduct(Product *) override;
};

#endif
