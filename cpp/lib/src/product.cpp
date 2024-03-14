#include "product.h"

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

std::string Medication::getDetailedName() const {

	// Only append the doses and their units, slash separated
	std::string concatenated_doses {};
	for(Ingredient ing : ingredients_) {
	}
	return Premade::getDetailedName() + " ";
}
