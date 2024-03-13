#include "phonenumbers.h"

bool phone_validation::checkPhoneNumber(const std::string &phoneParam) {

	for(char digit : phoneParam) {
		if (!std::isdigit(digit)) {
			return false;
		}
	}

	if(phoneParam.length() != PHONENUMBERLENGTH)
		return false;

	return true;
}
