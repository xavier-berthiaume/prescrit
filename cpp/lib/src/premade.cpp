#include <prescrit/structs/premade.h>

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
