#include "prescription.h"
#include "globalDefinitions.h"

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

	if(!time_validation::checkDayWithinRange(dayParam, monthParam, yearParam))
		return;

	if(!time_validation::checkMonthWithinRange(monthParam))
		return;

	if(!time_validation::checkYearWithinRange(yearParam))
		return;

	originalDate_->tm_mday = dayParam;
	originalDate_->tm_mon = monthParam;
	originalDate_->tm_year = yearParam;
}

void Prescription::setExpiryDate(const unsigned short& dayParam, 
				 const unsigned short& monthParam, 
				 const unsigned short& yearParam) {

	if(!time_validation::checkDayWithinRange(dayParam, monthParam, yearParam))
		return;

	if(!time_validation::checkMonthWithinRange(monthParam))
		return;

	if(!time_validation::checkYearWithinRange(yearParam))
		return;

	expiryDate_->tm_mday = dayParam;
	expiryDate_->tm_mon = monthParam;
	expiryDate_->tm_year = yearParam;
}

void Prescription::setRefillDate(const unsigned short& dayParam, 
				 const unsigned short& monthParam, 
				 const unsigned short& yearParam){

	if(!time_validation::checkDayWithinRange(dayParam, monthParam, yearParam))
		return;

	if(!time_validation::checkMonthWithinRange(monthParam))
		return;

	if(!time_validation::checkYearWithinRange(yearParam))
		return;

	refillDate_->tm_mday = dayParam;
	refillDate_->tm_mon = monthParam;
	refillDate_->tm_year = yearParam;
}

void Prescription::setPrescriber(Prescriber *prescriberParam) {

	prescriber_ = prescriberParam;
}

void Prescription::setOriginalQuantity(const unsigned int& quantityParam) {

	if(quantityParam > MAXRXQUANTITY) {
		originalQuantity_ = MAXRXQUANTITY;
		return;
	}

	originalQuantity_ = quantityParam;
}

void Prescription::setOriginalRefills(const unsigned short& quantityParam) {

	if(quantityParam > 999) {
		originalRefills_ = 999;
		return;
	}

	originalRefills_ = quantityParam;
}

void Prescription::setRemainingQuantity(const unsigned int& quantityParam) {

	if(quantityParam > MAXRXQUANTITY) {
		remainingQuantity_ = MAXRXQUANTITY;
		return;
	}

	// Makes no sense to have the remaining quantity be greater than the original quantity
	if(quantityParam > originalQuantity_)
		return;

	remainingQuantity_ = quantityParam;
}

void Prescription::setRefillQuantity(unsigned int quantityParam) {

	if(quantityParam > MAXRXQUANTITY)
		quantityParam = MAXRXQUANTITY;

	if(quantityParam > remainingQuantity_)
		return;

	refillQuantity_ = quantityParam;
}

void Prescription::setPreviousRefill(Prescription *prescriptionParam) {

	previousRefill_ = prescriptionParam;
}
