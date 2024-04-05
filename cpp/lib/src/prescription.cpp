#include <prescrit/structs/prescription.h> 

Prescription::Prescription() : previousRefill_(nullptr) {

	prescriber_ = nullptr;

	originalProduct_ = nullptr;
	givenProduct_ = nullptr;

    originalDate_ = tm();
    expiryDate_ = tm();
    refillDate_ = tm();
}

Prescription::Prescription(Prescription *cpyObject) {

	originalProduct_ = new Product(cpyObject->getOriginalProduct());
	givenProduct_ = new Product(cpyObject->getGivenProduct());
	
	originalDate_ = cpyObject->getOriginalDate();
	expiryDate_ = cpyObject->getExpiryDate();
	refillDate_ = cpyObject->getRefillDate();

	prescriber_ = new Prescriber(cpyObject->getPrescriber());

	originalQuantity_ = cpyObject->getOriginalQuantity();
	originalRefills_ = cpyObject->getOriginalRefills();
	remainingQuantity_ = cpyObject->getRemainingQuantity();
	refillQuantity_ = cpyObject->getRefillQuantity();

    previousRefill_ = nullptr;    
}

Prescription::~Prescription() {

	if(prescriber_ != nullptr)
		delete prescriber_;

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

std::tm Prescription::getOriginalDate() const {

	return originalDate_;
}

std::tm Prescription::getExpiryDate() const {

	return expiryDate_;
}

std::tm Prescription::getRefillDate() const {

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

	originalProduct_ = new Product(productParam);
}

void Prescription::setGivenProduct(Product *productParam) {

	if(productParam == nullptr)
		return;

	givenProduct_ = new Product(productParam);
}

void Prescription::setOriginalDate(tm *tmParam) {

    if(!time_validation::checkValidDate(tmParam))
        return;

    /*
    originalDate_.tm_mday = tmParam->tm_mday;
    originalDate_.tm_mon = tmParam->tm_mon;
    originalDate_.tm_year = tmParam->tm_year;
    originalDate_.tm_isdst = tmParam->
    */

    originalDate_ = *tmParam;
}

void Prescription::setExpiryDate(tm *tmParam) {

    if(!time_validation::checkValidDate(tmParam))
        return;

    /*
    expiryDate_.tm_mday = tmParam->tm_mday;
    expiryDate_.tm_mon = tmParam->tm_mon;
    expiryDate_.tm_year = tmParam->tm_year;
    */

    expiryDate_ = *tmParam;
}

void Prescription::setRefillDate(tm *tmParam) {

    if(!time_validation::checkValidDate(tmParam))
        return;

    /*
    refillDate_.tm_mday = tmParam->tm_mday;
    refillDate_.tm_mon = tmParam->tm_mon;
    refillDate_.tm_year = tmParam->tm_year;
    */

    refillDate_ = *tmParam;
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

	originalDate_.tm_mday = dayParam;
	originalDate_.tm_mon = monthParam;
	originalDate_.tm_year = yearParam-1900;
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

	expiryDate_.tm_mday = dayParam;
	expiryDate_.tm_mon = monthParam;
	expiryDate_.tm_year = yearParam-1900;
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

	refillDate_.tm_mday = dayParam;
	refillDate_.tm_mon = monthParam;
	refillDate_.tm_year = yearParam-1900;
}

void Prescription::setPrescriber(Prescriber *prescriberParam) {

	if(prescriberParam == nullptr)
		return;

	prescriber_ = new Prescriber(prescriberParam);
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
	if(quantityParam > originalQuantity_*originalRefills_)
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
