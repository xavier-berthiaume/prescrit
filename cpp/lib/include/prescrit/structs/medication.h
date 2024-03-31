#ifndef MEDICATION_H
#define MEDICATION_H

#include "premade.h"

class Medication : public Premade {
protected:

	IngredientList *ingredients_;

	std::string din_;

	ValidPrescriptionTypes annex_;
public:

	Medication();
	Medication(Medication *);
	~Medication();

	std::string getDetailedName() const override;
	std::string getDIN() const;
	IngredientList *getActiveIngredients() const;
	ValidPrescriptionTypes getAnnex() const;

	void setDIN(const std::string&);
	void setAnnex(ValidPrescriptionTypes);
	void AddIngredient(const std::string&, const unsigned int&, units::DoseUnit);
};

#endif
