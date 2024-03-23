#include <prescrit/structs/patient.h>

const unsigned short Patient::kMaximumNameLength = MAXNAMELENGTH;

Patient::Patient() {
	birthdate_ = new std::tm();
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

	return birthdate_->tm_mon;
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

	if(!time_validation::checkDayWithinRange(birthDateParam, birthdate_->tm_mon, birthdate_->tm_year))
		return;
	
	const auto currentTime = std::chrono::system_clock::now();
	const std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	const std::tm *currentTime_tm = std::localtime(&currentTime_t);
	const unsigned short currentDay = currentTime_tm->tm_mday;

	if(birthDateParam > currentDay) {
		return;
	}

	birthdate_->tm_mday = birthDateParam;
}

void Patient::setBirthMonth(const unsigned short& birthMonthParam) {
	
	const auto currentTime = std::chrono::system_clock::now();
	const std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	const std::tm *currentTime_tm = std::localtime(&currentTime_t);
	const unsigned short currentMonth = currentTime_tm->tm_mon+1;

	if(birthMonthParam > 11) {
		return;
	}

	birthdate_->tm_mon = birthMonthParam;
}

void Patient::setBirthYear(const unsigned short& birthYearParam) {

	const auto currentTime = std::chrono::system_clock::now();
	const std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	const std::tm *currentTime_tm = std::localtime(&currentTime_t);
	const unsigned short currentYear = currentTime_tm->tm_year + 1900;

	if(birthYearParam < 1900 || birthYearParam > currentYear) {
		return;
	}

	birthdate_->tm_year = birthYearParam-1900;
}

void Patient::setBirthDate(const tm* birthDateParam) {

	if(!time_validation::checkDateBeforePresent(birthDateParam))
		return;

	if(!time_validation::checkDayWithinRange(birthDateParam->tm_mday, birthDateParam->tm_mon, birthDateParam->tm_year) ||
	   !time_validation::checkMonthWithinRange(birthDateParam->tm_mon) ||
	   !time_validation::checkYearWithinRange(birthDateParam->tm_year+1900))
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
