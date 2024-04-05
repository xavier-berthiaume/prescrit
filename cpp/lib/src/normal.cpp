#include <prescrit/structs/normal.h> 

Normal::Normal() {

	originalProduct_ = nullptr;
	givenProduct_ = nullptr;

    originalDate_ = tm();
    originalDate_.tm_isdst = -1;
    expiryDate_ = tm();
    expiryDate_.tm_isdst = -1;
    refillDate_ = tm();
    refillDate_.tm_isdst = -1;
}

Normal::Normal(Normal *cpyObject) {
    
    Premade *productParam = cpyObject->getOriginalProduct();

    if(dynamic_cast<Medication *>(productParam)) {
        originalProduct_ = new Medication(dynamic_cast<Medication *>(productParam));
    } else if(dynamic_cast<Bandage *>(productParam)) {
        originalProduct_ = new Bandage(dynamic_cast<Bandage *>(productParam));
    } else if(dynamic_cast<Syringe *>(productParam)) {
        originalProduct_ = new Syringe(dynamic_cast<Syringe *>(productParam));
    } else {
	    originalProduct_ = new Premade(dynamic_cast<Premade *>(productParam));
    }

    productParam = cpyObject->getGivenProduct();

    if(dynamic_cast<Medication *>(productParam)) {
        givenProduct_ = new Medication(dynamic_cast<Medication *>(productParam));
    } else if(dynamic_cast<Bandage *>(productParam)) {
        givenProduct_ = new Bandage(dynamic_cast<Bandage *>(productParam));
    } else if(dynamic_cast<Syringe *>(productParam)) {
        givenProduct_ = new Syringe(dynamic_cast<Syringe *>(productParam));
    } else {
	    givenProduct_ = new Premade(dynamic_cast<Premade *>(productParam));
    }

	originalDate_ = cpyObject->getOriginalDate();
	expiryDate_ = cpyObject->getExpiryDate();
	refillDate_ = cpyObject->getRefillDate();

	prescriber_ = new Prescriber(cpyObject->getPrescriber());

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
}

Premade *Normal::getOriginalProduct() const {

    if(dynamic_cast<Medication *>(originalProduct_)) {
	    return dynamic_cast<Medication *>(originalProduct_);
    } else if(dynamic_cast<Bandage *>(originalProduct_)) {
        return dynamic_cast<Bandage *>(originalProduct_);
    } else if(dynamic_cast<Syringe *>(originalProduct_)) {
        return dynamic_cast<Syringe *>(originalProduct_);
    } else {
        return dynamic_cast<Premade *>(originalProduct_);
    }
}

Premade *Normal::getGivenProduct() const {

    if(dynamic_cast<Medication *>(givenProduct_)) {
	    return dynamic_cast<Medication *>(givenProduct_);
    } else if(dynamic_cast<Bandage *>(givenProduct_)) {
        return dynamic_cast<Bandage *>(givenProduct_);
    } else if(dynamic_cast<Syringe *>(givenProduct_)) {
        return dynamic_cast<Syringe *>(givenProduct_);
    } else {
        return dynamic_cast<Premade *>(givenProduct_);
    }
}

void Normal::setOriginalProduct(Product *productParam) {

	if(productParam == nullptr)
		return;

    if(dynamic_cast<Medication *>(productParam)) {
        originalProduct_ = new Medication(dynamic_cast<Medication *>(productParam));
    } else if(dynamic_cast<Bandage *>(productParam)) {
        originalProduct_ = new Bandage(dynamic_cast<Bandage *>(productParam));
    } else if(dynamic_cast<Syringe *>(productParam)) {
        originalProduct_ = new Syringe(dynamic_cast<Syringe *>(productParam));
    } else {
	    originalProduct_ = new Premade(dynamic_cast<Premade *>(productParam));
    }
}

void Normal::setGivenProduct(Product *productParam) {
	
	if(productParam == nullptr)
		return;

    if(dynamic_cast<Medication *>(productParam)) {
        givenProduct_ = new Medication(dynamic_cast<Medication *>(productParam));
    } else if(dynamic_cast<Bandage *>(productParam)) {
        givenProduct_ = new Bandage(dynamic_cast<Bandage *>(productParam));
    } else if(dynamic_cast<Syringe *>(productParam)) {
        givenProduct_ = new Syringe(dynamic_cast<Syringe *>(productParam));
    } else {
	    givenProduct_ = new Premade(dynamic_cast<Premade *>(productParam));
    }
}
