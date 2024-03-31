#include <prescrit/structs/bandage.cpp>

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
