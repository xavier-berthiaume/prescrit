#include <prescrit/structs/syringe.h>

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
