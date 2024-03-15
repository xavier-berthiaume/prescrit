#include "prescriber.h"

Prescriber::Prescriber() {

	workLocations_ = new LocationList();
}

Prescriber::~Prescriber() {

	delete workLocations_;
}

std::string Prescriber::getFirstName() const {

	return firstName_;
} 

std::string Prescriber::getLastName() const {

	return lastName_;
} 

std::string Prescriber::getFullName() const {

	return firstName_ + " " + lastName_;
} 

std::string Prescriber::getLicense() const {

	return license_;
}

LocationList *Prescriber::getLocations() const {

	return workLocations_;
}

bool Prescriber::validateLicense(const std::string& licenseParam) {

	if(licenseParam.length() != 6)
		return false;

	for(char character : licenseParam) {
		if(!std::isdigit(character))
			return false;
	}

	return true;
}

void Prescriber::setFirstName(const std::string& nameParam) {

	if(nameParam.length() > MAXNAMELENGTH)
		return;
	
	for(char character : nameParam) {
		if(!std::isalpha(character))
			return;
	}

	firstName_ = nameParam;
}

void Prescriber::setLastName(const std::string& nameParam) {

	if(nameParam.length() > MAXNAMELENGTH)
		return;
	
	for(char character : nameParam) {
		if(!std::isalpha(character))
			return;
	}

	lastName_ = nameParam;
}

void Prescriber::setLicense(const std::string& licenseParam) {

	if(!validateLicense(licenseParam))
		return;

	license_ = licenseParam;
}
