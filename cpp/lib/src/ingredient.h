#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "units.h"

struct Ingredient {
	std::string ingredientName_;
	unsigned int dose_;
	units::DoseUnit unit_;

	std::string getFormattedDose();
	std::string getFormattedName();

};

#endif // !INGREDIENT_H
