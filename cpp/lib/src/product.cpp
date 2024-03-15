#include "product.h"
#include "units.h"
#include <tuple>

std::string Product::getName() const {

	return name_;
}

std::string Product::getDetailedName() const {

	return name_;
}

void Product::setName(const std::string& nameParam) {

	// TODO Validate name before assignment
	name_ = nameParam;
}

std::string Premade::getDetailedName() const {

	return producer_ + " " + Product::getDetailedName();
}

std::string Premade::getProducer() const {

	return producer_;
}

void Premade::setProducer(const std::string& producerParam) {

	// TODO Validate producer before assignment
	producer_ = producerParam;
}

Medication::Medication() {

	ingredients_ = new IngredientList();
}

Medication::~Medication() {

	delete ingredients_;
}

std::string Medication::getDetailedName() const {

	std::string formatted_doses {};
	Ingredient *next_ingredient = ingredients_->getNextIngredient();
	do {
	
		formatted_doses.append(next_ingredient->getFormattedDose());
		next_ingredient = ingredients_->getNextIngredient(next_ingredient);
		if(next_ingredient != nullptr)
			formatted_doses.append("/");
	}while (next_ingredient != nullptr);

	return Premade::getDetailedName() + " " + formatted_doses;
}

std::string Medication::getDIN() const {

	return din_;
}

IngredientList *Medication::getActiveIngredients() const {

	return ingredients_;
}

void Medication::setDIN(const std::string& dinParam) {

	if(dinParam.length() != 8)
		return;

	din_ = dinParam;
}

void Medication::AddIngredient(const std::string& nameParam, const unsigned int& doseParam, units::DoseUnit unitParam) {

	if(nameParam.length() > MAXNAMELENGTH) 
		return;

	ingredients_->addIngredient(nameParam, doseParam, unitParam);
}

std::string Bandage::getDetailedName() const {

	std::string width_string, length_string;
	width_string = std::to_string(std::get<0>(width_)) + units::convertToString(std::get<1>(width_));
	length_string = std::to_string(std::get<0>(length_)) + units::convertToString(std::get<1>(length_));
	return Premade::getDetailedName() + " " + width_string + "x" + length_string;
}

std::string Bandage::getIdentifier() const {

	return identifier_;
}

std::tuple<unsigned int, units::SizeUnit> Bandage::getWidth() const {

	return width_;
}

std::tuple<unsigned int, units::SizeUnit> Bandage::getLength() const {

	return length_;
}

std::tuple<unsigned int, units::AreaUnit> Bandage::getArea() const {

	if(std::get<1>(width_) != std::get<1>(length_))
		return std::make_tuple(0, units::um2);

	unsigned int area_measure = std::get<0>(width_) * std::get<0>(length_); 
	units::AreaUnit area_unit;

	switch(std::get<1>(width_)) {
		case units::um:
			area_unit = units::um2;
			break;
		case units::mm:
			area_unit = units::mm2;
			break;
		case units::cm:
			area_unit = units::cm2;
			break;
		case units::m:
			area_unit = units::m2;
			break;
	}

	return std::make_tuple(area_measure, area_unit);
}

void Bandage::setWidth(const unsigned int& measureParam, units::SizeUnit unitParam) {

	width_ = std::make_tuple(measureParam, unitParam);
}

void Bandage::setLength(const unsigned int& measureParam, units::SizeUnit unitParam) {

	length_ = std::make_tuple(measureParam, unitParam);
}
