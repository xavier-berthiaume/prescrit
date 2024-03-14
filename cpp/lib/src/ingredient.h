#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "units.h"

struct Ingredient {
	Ingredient(const std::string&, const unsigned int&, units::DoseUnit);

	std::string ingredientName_;
	unsigned int dose_;
	units::DoseUnit unit_;
	
	std::string getFormattedDose();
	std::string getFormattedName();

	Ingredient *getNext();
	void setNext(Ingredient *);

private:
	Ingredient *next;

};

struct IngredientList {
	IngredientList();

	void addIngredient(const std::string&, const unsigned int&, units::DoseUnit);
	Ingredient *getNextIngredient(Ingredient *);
	Ingredient *getNextIngredient();

private:
	Ingredient *head;

};


#endif // !INGREDIENT_H
