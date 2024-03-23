#include <prescrit/utils/ingredient.h>

Ingredient::Ingredient(const std::string& nameParam, 
		       const unsigned int& magnitudeParam, 
		       units::DoseUnit unitParam) : ingredientName_(nameParam),
						    dose_(magnitudeParam),
						    unit_(unitParam) {}

Ingredient::Ingredient(Ingredient *cpyObject) {

	ingredientName_ = cpyObject->getName();
	dose_ = cpyObject->getDose();
	unit_ = cpyObject->getUnit();
}

Ingredient::~Ingredient() {}

std::string Ingredient::getName() const {

	return ingredientName_;
}

unsigned int Ingredient::getDose() const {

	return dose_;
}

units::DoseUnit Ingredient::getUnit() const {

	return unit_;
}

std::string Ingredient::getFormattedDose() const {

	return std::to_string(dose_) + units::convertToString(unit_);
}

std::string Ingredient::getFormattedName() const {

	return ingredientName_ + " " + std::to_string(dose_) + units::convertToString(unit_);
}

Ingredient *Ingredient::getNext() const {

	return next;
}

void Ingredient::setNext(Ingredient *ingredientParam) {

	next = ingredientParam;
}

IngredientList::IngredientList() : head(nullptr) {}

IngredientList::IngredientList(IngredientList *cpyObject) {

	head = new Ingredient(cpyObject->getHead());
	Ingredient *currentPositionOriginal = cpyObject->getNextIngredient(cpyObject->getHead());
	Ingredient *currentPositionNew = head;
	while(currentPositionOriginal != nullptr) {

		currentPositionNew->setNext(new Ingredient(currentPositionOriginal));
		currentPositionNew = currentPositionNew->getNext();
		currentPositionOriginal = currentPositionOriginal->getNext();
	}
}

IngredientList::~IngredientList() {

	while(head != nullptr) {
		Ingredient *nextIngredient = head->getNext();
		delete head;
		head = nextIngredient;
	}
}

void IngredientList::addIngredient(const std::string& nameParam, const unsigned int& magnitudeParam, units::DoseUnit unitParam) {

	Ingredient *newIngredient = new Ingredient(nameParam, magnitudeParam, unitParam);
	newIngredient->setNext(head);
	head = newIngredient;
}

void IngredientList::addIngredient(Ingredient *ingredientParam) {

	ingredientParam->setNext(head);
	head = ingredientParam;
}

Ingredient *IngredientList::getNextIngredient(Ingredient *currentParam) {

	if(currentParam == nullptr || currentParam->getNext() == nullptr) {
		return nullptr;
	} else {
		return currentParam->getNext();
	}
}

Ingredient *IngredientList::getHead() {

	return head;
}
