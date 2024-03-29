#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "units.h"

struct Ingredient {
	Ingredient(const std::string&, const unsigned int&, units::DoseUnit);
	Ingredient(Ingredient *);
	~Ingredient();

	std::string ingredientName_;
	unsigned int dose_;
	units::DoseUnit unit_;
	
	std::string getFormattedDose() const;
	std::string getFormattedName() const;

	Ingredient *getNext() const;
	void setNext(Ingredient *);

private:
	Ingredient *next;

};

struct IngredientList {
	IngredientList();
	IngredientList(IngredientList *);
	~IngredientList();

	void addIngredient(const std::string&, const unsigned int&, units::DoseUnit);
	void addIngredient(Ingredient *);
	Ingredient *getNextIngredient(Ingredient *);
	Ingredient *getHead();

private:
	Ingredient *head;

};


#endif // !INGREDIENT_H
