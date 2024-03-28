#include <prescrit/structs/product.h> 

Product::Product() {}

Product::Product(Product *cpyObject) {

	name_ = cpyObject->getName();
}

Product::~Product() {}

std::string Product::getName() const {

	return name_;
}

std::string Product::getDetailedName() const {

	return name_;
}

void Product::setName(const std::string& nameParam) {

	if(nameParam.length() > MAXNAMELENGTH)
		return;

	name_ = nameParam;
}

Premade::Premade() {}

Premade::Premade(Premade *cpyObject) {

    name_ = cpyObject->getName();
    producer_ = cpyObject->getProducer();
}

Premade::~Premade() {}

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

Medication::Medication(Medication *cpyObject) {

	name_ = cpyObject->getName();
	producer_ = cpyObject->getProducer();
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

Bandage::Bandage() {

    width_ = std::make_tuple(0, units::mm);
    length_ = std::make_tuple(0, units::mm);
    identifier_ = "";
}

Bandage::Bandage(Bandage *cpyObject) {

    width_ = cpyObject->width_;
    length_ = cpyObject->length_;
    identifier_ = cpyObject->getIdentifier();
}

Bandage::~Bandage() {}

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

void Bandage::setIdentifier(const std::string& identifierParam) {

	if(identifierParam.length() > MAXIDENTIFIERLENGTH) 
		return;

	identifier_ = identifierParam;
}

void Bandage::setWidth(const unsigned int& measureParam, units::SizeUnit unitParam) {

	width_ = std::make_tuple(measureParam, unitParam);
}

void Bandage::setLength(const unsigned int& measureParam, units::SizeUnit unitParam) {

	length_ = std::make_tuple(measureParam, unitParam);
}

Syringe::Syringe() {

    guage_ = 0;
    identifier_ = "";
}

Syringe::Syringe(Syringe *cpyObject) {

    guage_ = cpyObject->getGuage();
    identifier_ = cpyObject->getIdentifier();
}

Syringe::~Syringe() {}

std::string Syringe::getDetailedName() const {

	return Premade::getDetailedName() + " " + std::to_string(guage_) + "G, " + identifier_;
}

std::string Syringe::getIdentifier() const {

	return identifier_;
}

unsigned short Syringe::getGuage() const {

	return guage_;
}

void Syringe::setIdentifier(const std::string& identifierParam) {

	if(identifierParam.length() > MAXIDENTIFIERLENGTH)
		return;

	identifier_ = identifierParam;
}

void Syringe::setGuage(const unsigned short& guageParam) {

	guage_ = guageParam;
}
