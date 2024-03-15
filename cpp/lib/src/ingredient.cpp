#include "ingredient.h"

Ingredient::Ingredient(const std::string& nameParam, 
		       const unsigned int& magnitudeParam, 
		       units::DoseUnit unitParam) : ingredientName_(nameParam),
						    dose_(magnitudeParam),
						    unit_(unitParam) {

	
}

IngredientList::~IngredientList() {

	while(head != nullptr) {
		Ingredient *nextIngredient = head->getNext();
		delete head;
		head = nextIngredient;
	}
}

std::string Ingredient::getFormattedDose() {

	return std::to_string(dose_) + units::convertToString(unit_);
}

std::string Ingredient::getFormattedName() {

	return ingredientName_ + " " + std::to_string(dose_) + units::convertToString(unit_);
}

Ingredient *Ingredient::getNext() {

	return next;
}

void Ingredient::setNext(Ingredient *ingredientParam) {

	next = ingredientParam;
}

IngredientList::IngredientList() : head(nullptr) {}

void IngredientList::addIngredient(const std::string& nameParam, const unsigned int& magnitudeParam, units::DoseUnit unitParam) {

	Ingredient *newIngredient = new Ingredient(nameParam, magnitudeParam, unitParam);
	newIngredient->setNext(head);
	head = newIngredient;
}

Ingredient *IngredientList::getNextIngredient(Ingredient *currentParam) {

	if(currentParam == nullptr || currentParam->getNext() == nullptr) {
		return nullptr;
	} else {
		return currentParam->getNext();
	}
}

Ingredient *IngredientList::getNextIngredient() {

	return head;
}
