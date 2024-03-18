#include "prescription.h"
#include "prescriber.h"

std::tm *Prescription::getOriginalDate() const {

	return originalDate_;
}

std::tm *Prescription::getExpiryDate() const {

	return expiryDate_;
}

std::tm *Prescription::getRefillDate() const {

	return refillDate_;
}

Prescriber *Prescription::getPrescriber() const {

	return prescriber_;
}

unsigned int Prescription::getOriginalQuantity() const {

	return originalQuantity_;
}

unsigned short Prescription::getOriginalRefills() const {

	return originalRefills_;
}

unsigned int Prescription::getRemainingQuantity() const {
	
	return remainingQuantity_;
}

unsigned int Prescription::getRefillQuantity() const {

	return refillQuantity_;
}

Prescription *Prescription::getPreviousRefill() const {

	return previousRefill_;
}

void Prescription::setOriginalDate(const unsigned short& dayParam, 
				   const unsigned short& monthParam, 
				   const unsigned short& yearParam) {

}

void Prescription::setExpiryDate(const unsigned short&, const unsigned short&, const unsigned short&) {}

void Prescription::setRefillDate(const unsigned short&, const unsigned short&, const unsigned short&){}

void Prescription::setPrescriber(Prescriber *) {}

void Prescription::setOriginalQuantity(const unsigned int&) {}

void Prescription::setOriginalRefills(const unsigned short&) {}

void Prescription::setRemainingQuantity(const unsigned int&) {}

void Prescription::setRefillQuantity(const unsigned int&) {}

void Prescription::setPreviousRefill(Prescription *) {}
