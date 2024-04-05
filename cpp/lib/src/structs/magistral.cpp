#include <prescrit/structs/magistral.h>

Magistral::Magistral() {

    prescriber_ = nullptr;

    originalDate_ = tm();
    originalDate_.tm_isdst = -1;
    expiryDate_ = tm();
    expiryDate_.tm_isdst = -1;
    refillDate_ = tm();
    refillDate_.tm_isdst = -1;
}

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
