#include <prescrit/structs/patient.h>

const unsigned short Patient::kMaximumNameLength = MAXNAMELENGTH;

Patient::Patient() {
	birthdate_ = new std::tm();
    birthdate_->tm_min = 0;
    birthdate_->tm_sec = 0;
}

Patient::~Patient() {
	delete birthdate_;
}

std::string Patient::getFirstName() const {

	return firstName_;
}

std::string Patient::getLastName() const {

	return lastName_;
}

std::string Patient::getFullName() const {
	
	std::string fullName = firstName_ + lastName_;
	return fullName;
}

unsigned short Patient::getAge() const {
	
	return age_;
}

std::string Patient::getFormattedBirthdate() const {

	std::string formattedAge;

	return formattedAge;
}

const unsigned short Patient::getBirthDay() const {
	
	return birthdate_->tm_mday;
}

const unsigned short Patient::getBirthMonth() const {

	return birthdate_->tm_mon+1;
}

const unsigned short Patient::getBirthYear() const {

	return birthdate_->tm_year+1900;
}

std::vector<std::string> Patient::getPhoneNumbers() const {

	return phoneNumbers_;
}

std::string Patient::getPhoneNumber(const unsigned int& positionParam) const {

	return phoneNumbers_.at(positionParam);
}

void Patient::setFirstName(const std::string& firstNameParam) {

	if(firstNameParam.length() > Patient::kMaximumNameLength)
		return;

	for(char character : firstNameParam) {
		if(!std::isalpha(character))
			return;
	}

	firstName_ = firstNameParam; 
}

void Patient::setLastName(const std::string& lastNameParam) {

	if(lastNameParam.length() > Patient::kMaximumNameLength)
		return;

	for(char character : lastNameParam) {
		if(!std::isalpha(character))
			return;
	}

	lastName_ = lastNameParam;
}

void Patient::setBirthDay(const unsigned short& birthDateParam) {

    // Check if the day that's passed makes any sense
	if(!time_validation::checkDayWithinRange(birthDateParam, birthdate_->tm_mon-1, birthdate_->tm_year+1900))
		return;

    // Create a copy of the current birthday, change the day to the
    // parameter, then check if it's before the current day
    tm newBirthday = tm();
    newBirthday.tm_mday = birthDateParam;
    newBirthday.tm_mon = birthdate_->tm_mon;
    newBirthday.tm_year = birthdate_->tm_year;

    if(!time_validation::checkDateBeforePresent(&newBirthday))
        return;

	birthdate_->tm_mday = birthDateParam;
}

void Patient::setBirthMonth(const unsigned short& birthMonthParam) {

	if(birthMonthParam-1 > 11) {
		return;
	}
    
    // Create a copy of the current birthday, change the day to the
    // parameter, then check if it's before the current day
    tm newBirthday = tm();
    newBirthday.tm_mday = birthdate_->tm_mday;
    newBirthday.tm_mon = birthMonthParam-1;
    newBirthday.tm_year = birthdate_->tm_year;

    if(!time_validation::checkDateBeforePresent(&newBirthday))
        return;

	birthdate_->tm_mon = birthMonthParam-1;
}

void Patient::setBirthYear(const unsigned short& birthYearParam) {

    if(!time_validation::checkYearWithinRange(birthYearParam))
        return;

    // Create a copy of the current birthday, change the day to the
    // parameter, then check if it's before the current day
    tm newBirthday = tm();
    newBirthday.tm_mday = birthdate_->tm_mday;
    newBirthday.tm_mon = birthdate_->tm_mon;
    newBirthday.tm_year = birthYearParam-1900;

    if(!time_validation::checkDateBeforePresent(&newBirthday))
        return;

	birthdate_->tm_year = birthYearParam-1900;
}

void Patient::setBirthDate(const tm* birthDateParam) {

	if(!time_validation::checkDateBeforePresent(birthDateParam))
		return;

	if(!time_validation::checkDayWithinRange(birthDateParam) ||
	   !time_validation::checkMonthWithinRange(birthDateParam) ||
	   !time_validation::checkYearWithinRange(birthDateParam))
		return;

	birthdate_->tm_year = birthDateParam->tm_year;
	birthdate_->tm_mon = birthDateParam->tm_mon;
	birthdate_->tm_mday = birthDateParam->tm_mday;
}

void Patient::addPhoneNumber(const std::string& phoneNumberParam) {

	// First validate the number
	if(!phone_validation::checkPhoneNumber(phoneNumberParam))
		return;
	
	phoneNumbers_.push_back(phoneNumberParam);
}
