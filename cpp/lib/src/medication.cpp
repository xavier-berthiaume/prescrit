#include <prescrit/structs/medication.h>

Medication::Medication() {

    name_ = "";
    producer_ = "";
    din_ = "";
    annex_ = Annex1;
	ingredients_ = new IngredientList();
}

Medication::Medication(Medication *cpyObject) {

	name_ = cpyObject->getName();
	producer_ = cpyObject->getProducer();
    din_ = cpyObject->getDIN();
    annex_ = cpyObject->getAnnex();
	ingredients_ = new IngredientList(cpyObject->getActiveIngredients());
}

Medication::~Medication() {

	delete ingredients_;
}

std::string Medication::getDetailedName() const {

	std::string formatted_doses {};
	Ingredient *next_ingredient = ingredients_->getHead();
	while (next_ingredient != nullptr) {
	
		formatted_doses.append(next_ingredient->getFormattedDose());
		next_ingredient = ingredients_->getNextIngredient(next_ingredient);
		if(next_ingredient != nullptr)
			formatted_doses.append("/");
	}

	return Premade::getDetailedName() + " " + formatted_doses;
}

std::string Medication::getDIN() const {

	return din_;
}

IngredientList *Medication::getActiveIngredients() const {

	return ingredients_;
}

ValidPrescriptionTypes Medication::getAnnex() const {

	return annex_;
}

void Medication::setDIN(const std::string& dinParam) {

	if(dinParam.length() != 8)
		return;

	din_ = dinParam;
}

void Medication::setAnnex(ValidPrescriptionTypes annexParam) {

	annex_ = annexParam;
}

void Medication::AddIngredient(const std::string& nameParam, const unsigned int& doseParam, units::DoseUnit unitParam) {

	if(nameParam.length() > MAXNAMELENGTH) 
		return;

	ingredients_->addIngredient(nameParam, doseParam, unitParam);
}
