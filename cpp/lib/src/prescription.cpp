#include "prescription.h"

Prescription::Prescription() {

	originalProduct_ = nullptr;
	givenProduct_ = nullptr;
}

Prescription::Prescription(Prescription *cpyObject) {

	originalProduct_ = cpyObject->getOriginalProduct();
	givenProduct_ = cpyObject->getGivenProduct();
	
	originalDate_ = cpyObject->getOriginalDate();
	expiryDate_ = cpyObject->getExpiryDate();
	refillDate_ = cpyObject->getRefillDate();

	prescriber_ = cpyObject->getPrescriber();

	originalQuantity_ = cpyObject->getOriginalQuantity();
	originalRefills_ = cpyObject->getOriginalRefills();
	remainingQuantity_ = cpyObject->getRemainingQuantity();
	refillQuantity_ = cpyObject->getRefillQuantity();
}

Prescription::~Prescription() {

	if(originalProduct_ != nullptr)
		delete originalProduct_;

	if(givenProduct_ != nullptr)
		delete givenProduct_;
}

Product *Prescription::getOriginalProduct() const {

	return originalProduct_;
}

Product *Prescription::getGivenProduct() const {

	return givenProduct_;
}

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

void Prescription::setOriginalProduct(Product *productParam) {

	if(productParam == nullptr)
		return;

	originalProduct_ = productParam;
}

void Prescription::setGivenProduct(Product *productParam) {

	if(productParam == nullptr)
		return;

	givenProduct_ = productParam;
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

Prescription *Prescription::refill(const unsigned int& quantityParam) {

	return nullptr;
}

Normal::Normal() {

	originalProduct_ = nullptr;
	givenProduct_ = nullptr;
}

Normal::Normal(Normal *cpyObject) {

	originalProduct_ = cpyObject->getOriginalProduct();
	givenProduct_ = cpyObject->getGivenProduct();

	originalDate_ = cpyObject->getOriginalDate();
	expiryDate_ = cpyObject->getExpiryDate();
	refillDate_ = cpyObject->getRefillDate();

	prescriber_ = cpyObject->getPrescriber();

	originalQuantity_ = cpyObject->getOriginalQuantity();
	originalRefills_ = cpyObject->getOriginalRefills();
	remainingQuantity_ = cpyObject->getRemainingQuantity();
	refillQuantity_ = cpyObject->getRefillQuantity();

	// Do not copy over the previous refill
}

Normal::~Normal() {

	if(originalProduct_ != nullptr)
		delete  originalProduct_;

	if(givenProduct_ != nullptr)
		delete givenProduct_;

	// Maybe a better way to do this?
	if(previousRefill_ != nullptr)
		delete previousRefill_;
}

Premade *Normal::getOriginalProduct() const {

	return originalProduct_;
}

Premade *Normal::getGivenProduct() const {

	return givenProduct_;
}

void Normal::setOriginalProduct(Product *productParam) {

	originalProduct_ = productParam;
}

void Normal::setGivenProduct(Product *productParam) {

	givenProduct_ = productParam;
}

Prescription *Normal::refill(const unsigned int& quantityParam) {

	return nullptr;
}

Magistral::Magistral() {}

Magistral::Magistral(Magistral *cpyObject) {

	ingredients_ = cpyObject->getIngredients();

	originalDate_ = cpyObject->getOriginalDate();
	expiryDate_ = cpyObject->getExpiryDate();
	refillDate_ = cpyObject->getRefillDate();

	prescriber_ = cpyObject->getPrescriber();

	originalQuantity_ = cpyObject->getOriginalQuantity();
	originalRefills_ = cpyObject->getOriginalRefills();
	remainingQuantity_ = cpyObject->getRemainingQuantity();
	refillQuantity_ = cpyObject->getRefillQuantity();
}

Magistral::~Magistral() {}

std::vector<Premade *> Magistral::getIngredients() const {

	return ingredients_;
}

void Magistral::addIngredient(Premade *ingredientParam) {

	if(ingredientParam == nullptr)
		return;

	ingredients_.push_back(ingredientParam);
}

void Magistral::removeIngredient(Premade *ingredientParam) {

	if(ingredientParam == nullptr)
		return;

	ingredients_.erase(std::remove(ingredients_.begin(), ingredients_.end(), ingredientParam), ingredients_.end());
}

Prescription *Magistral::refill(const unsigned int& quantityParam) {

	return nullptr;
}
