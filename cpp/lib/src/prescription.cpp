#include <prescrit/structs/prescription.h> 

Prescription::Prescription() {

	prescriber_ = nullptr;

	originalProduct_ = nullptr;
	givenProduct_ = nullptr;
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

    originalDate_.tm_mday = tmParam->tm_mday;
    originalDate_.tm_mon = tmParam->tm_mon;
    originalDate_.tm_year = tmParam->tm_year;
}

void Prescription::setExpiryDate(tm *tmParam) {

    if(!time_validation::checkValidDate(tmParam))
        return;

    expiryDate_.tm_mday = tmParam->tm_mday;
    expiryDate_.tm_mon = tmParam->tm_mon;
    expiryDate_.tm_year = tmParam->tm_year;
}

void Prescription::setRefillDate(tm *tmParam) {

    if(!time_validation::checkValidDate(tmParam))
        return;

    refillDate_.tm_mday = tmParam->tm_mday;
    refillDate_.tm_mon = tmParam->tm_mon;
    refillDate_.tm_year = tmParam->tm_year;
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

Normal::Normal() {

	originalProduct_ = nullptr;
	givenProduct_ = nullptr;
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

Magistral::Magistral() {}

Magistral::Magistral(Magistral *cpyObject) {

    // This doesn't create a deep copy, you have to create
    // new and identical elements on a per element basis
	// ingredients_ = cpyObject->getIngredients();
    
    // Initialize the array as empty, then copy over element by element
    constituentProducts_ = {};

    for(unsigned short x = 0; x < cpyObject->getConstituentProducts().size(); x++) {
        if(dynamic_cast<Medication *>(cpyObject->getConstituentProducts()[x])) {
            constituentProducts_.push_back(new Medication(dynamic_cast<Medication *>(cpyObject->getConstituentProducts()[x])));
        } else if(dynamic_cast<Bandage *>(cpyObject->getConstituentProducts()[x])) {
            constituentProducts_.push_back(new Bandage(dynamic_cast<Bandage *>(cpyObject->getConstituentProducts()[x])));
        } else if(dynamic_cast<Syringe *>(cpyObject->getConstituentProducts()[x])) {
            constituentProducts_.push_back(new Syringe(dynamic_cast<Syringe *>(cpyObject->getConstituentProducts()[x])));
        } else {
            constituentProducts_.push_back(new Premade(dynamic_cast<Premade *>(cpyObject->getConstituentProducts()[x])));
        }
    }

	originalDate_ = cpyObject->getOriginalDate();
	expiryDate_ = cpyObject->getExpiryDate();
	refillDate_ = cpyObject->getRefillDate();

	prescriber_ = cpyObject->getPrescriber();

	originalQuantity_ = cpyObject->getOriginalQuantity();
	originalRefills_ = cpyObject->getOriginalRefills();
	remainingQuantity_ = cpyObject->getRemainingQuantity();
	refillQuantity_ = cpyObject->getRefillQuantity();
}

Magistral::~Magistral() {
    
    // Delete the items that are in the constituentProducts vector
    for(unsigned short x = 0; x < constituentProducts_.size(); x++) {

        delete constituentProducts_[x];
    }
}

std::vector<Premade *> Magistral::getConstituentProducts() const {

	return constituentProducts_;
}

void Magistral::addIngredient(Premade *ingredientParam) {

	if(ingredientParam == nullptr)
		return;

    // Set a logical maximum to the number of products that can
    // be in a magistral product
    if(constituentProducts_.size() > 100)
        return;

    if(dynamic_cast<Medication *>(ingredientParam)) {
        constituentProducts_.push_back(new Medication(dynamic_cast<Medication *>(ingredientParam)));
    } else if(dynamic_cast<Bandage *>(ingredientParam)) {
        constituentProducts_.push_back(new Bandage(dynamic_cast<Bandage *>(ingredientParam)));
    } else if(dynamic_cast<Syringe *>(ingredientParam)) {
        constituentProducts_.push_back(new Syringe(dynamic_cast<Syringe *>(ingredientParam)));
    } else {
        constituentProducts_.push_back(new Premade(dynamic_cast<Premade *>(ingredientParam)));
    }
}

void Magistral::removeIngredient(Premade *ingredientParam) {

	if(ingredientParam == nullptr)
		return;

    // Find the ingredients address within the vector, then delete its pointer.
	constituentProducts_.erase(std::remove(constituentProducts_.begin(), constituentProducts_.end(), ingredientParam), constituentProducts_.end());
    delete ingredientParam;
}

Product *Magistral::getOriginalProduct() const {
	
    return product_;
}

Product *Magistral::getGivenProduct() const {

	return product_;
}

void Magistral::setOriginalProduct(Product *productParam) {

	if(productParam == nullptr)
		return;

	product_ = productParam;
}

void Magistral::setGivenProduct(Product *productParam) {

	if(productParam == nullptr)
		return;

	product_ = productParam;
}

PrescriptionRefillList::PrescriptionRefillList() : head{nullptr} {}

PrescriptionRefillList::PrescriptionRefillList(PrescriptionRefillList *cpyObject) {

	head = new Prescription(cpyObject->getHead());
	Prescription *currentPositionOriginal = cpyObject->getNextPrescription(cpyObject->getHead());
	Prescription *currentPositionNew = head;
	while(currentPositionOriginal != nullptr) {

		currentPositionNew->setPreviousRefill(new Prescription(currentPositionOriginal));
		currentPositionNew = currentPositionNew->getPreviousRefill();
		currentPositionOriginal = currentPositionOriginal->getPreviousRefill();
	}
}

PrescriptionRefillList::~PrescriptionRefillList() {

	while(head != nullptr) {

		Prescription *nextPrescription = head->getPreviousRefill();
		delete head;
		head = nextPrescription;
	}
}

Prescription *PrescriptionRefillList::getNextPrescription(Prescription *prescriptionParam) {

	return prescriptionParam->getPreviousRefill();
}

Prescription *PrescriptionRefillList::getHead() {

	return head;
}

void PrescriptionRefillList::setHead(Prescription *prescriptionParam) {

	head = prescriptionParam;
}

bool PrescriptionRefillList::refillPrescription(const unsigned int& quantityParam) {

	Prescription *recentRefill = new Prescription(head);
	if(recentRefill->getRemainingQuantity() < quantityParam)
		return false;
	recentRefill->setRefillQuantity(quantityParam);
	recentRefill->setRemainingQuantity(recentRefill->getRemainingQuantity() - quantityParam);

	recentRefill->setPreviousRefill(head);
	head = recentRefill;
	
	return true;
}
