#include <prescrit/utils/time.h>


bool time_validation::checkDayWithinRange(const unsigned short &dayParam, 
			       const unsigned short &monthParam, 
			       const unsigned short &yearParam) {

	unsigned short monthDays {0};
	bool leapyear {false};

	if((yearParam % 4 == 0 && yearParam % 100 != 0) || (yearParam % 400 == 0))
		leapyear = true;

	switch(monthParam) {
		case 0:
			monthDays = 31;
			break;
		case 1:
			if(leapyear) {
				monthDays = 29;
			} else {
				monthDays = 28;
			}
			break;
		case 2:
			monthDays = 31;
			break;
		case 3:
			monthDays = 30;
			break;
		case 4:
			monthDays = 31;
			break;
		case 5:
			monthDays = 30;
			break;
		case 6:
			monthDays = 31;
			break;
		case 7:
			monthDays = 31;
			break;
		case 8:
			monthDays = 30;
			break;
		case 9:
			monthDays = 31;
			break;
		case 10:
			monthDays = 30;
			break;
		case 11:
			monthDays = 31;
			break;
	}

	if(dayParam > monthDays || dayParam <= 0)
		return false;

	return true;
}

bool time_validation::checkMonthWithinRange(const unsigned short &monthParam) {
	
	if(monthParam > 11)
		return false;

	return true;
}

bool time_validation::checkYearWithinRange(const unsigned short &yearParam) {
	
	if(yearParam < 1900 || yearParam > MAXVALIDYEAR)
		return false;

	return true;
}

bool time_validation::checkDayWithinRange(const tm *timeParam) {

    unsigned short yearParam = timeParam->tm_year+1900;
    unsigned short monthParam = timeParam->tm_mon+1;
    unsigned short dayParam = timeParam->tm_mday;

	unsigned short monthDays {0};
	bool leapyear {false};

	if((yearParam % 4 == 0 && yearParam % 100 != 0) || (yearParam % 400 == 0))
		leapyear = true;

	switch(monthParam) {
		case 0:
			monthDays = 31;
			break;
		case 1:
			if(leapyear) {
				monthDays = 29;
			} else {
				monthDays = 28;
			}
			break;
		case 2:
			monthDays = 31;
			break;
		case 3:
			monthDays = 30;
			break;
		case 4:
			monthDays = 31;
			break;
		case 5:
			monthDays = 30;
			break;
		case 6:
			monthDays = 31;
			break;
		case 7:
			monthDays = 31;
			break;
		case 8:
			monthDays = 30;
			break;
		case 9:
			monthDays = 31;
			break;
		case 10:
			monthDays = 30;
			break;
		case 11:
			monthDays = 31;
			break;
	}

	if(dayParam > monthDays || dayParam <= 0)
		return false;

	return true;

}

bool time_validation::checkMonthWithinRange(const tm *timeParam) {

    unsigned short monthParam = timeParam->tm_mon;
	
	if(monthParam > 11)
		return false;

	return true;
}

bool time_validation::checkYearWithinRange(const tm *timeParam) {

    unsigned short yearParam = timeParam->tm_year;
	
	if(yearParam < 0 || yearParam > MAXVALIDYEAR-1900)
		return false;

	return true;
}

bool time_validation::checkValidDate(const tm *timeToValidate) {

    time_t convertedTimeToValidate = std::mktime(const_cast<tm *>(timeToValidate));
    tm maximumValidDate = tm();
    maximumValidDate.tm_sec = 0;
    maximumValidDate.tm_min = 0;
    maximumValidDate.tm_hour = 0;
    maximumValidDate.tm_mday = 31;
    maximumValidDate.tm_mon = 11;
    maximumValidDate.tm_year = MAXVALIDYEAR-1900;
    time_t maximumFutureTime = mktime(&maximumValidDate);

    if(convertedTimeToValidate < 0)
        return false;

    if(convertedTimeToValidate > maximumFutureTime)
        return false;

    return true;
}

bool time_validation::checkDateBeforePresent(const tm *dateParam) {
	
	const auto currentTime = std::chrono::system_clock::now();
	const std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

    const time_t dateTime_t = mktime(const_cast<tm *>(dateParam));

    if(dateTime_t > currentTime_t)
        return false;

	return true;
}

tm *time_manipulation::addToDate(tm *timeParam, const unsigned int &daysParam, const unsigned int &monthsParam, const unsigned int &yearsParam) {

    unsigned int totalDays = 0, totalSeconds;
    totalDays = totalDays + yearsParam * 365;
    totalDays = totalDays + monthsParam * 30;
    totalDays = totalDays + daysParam;
    totalSeconds = totalDays * 60 * 60 * 24;

    time_t initialTime = std::mktime(timeParam);
    time_t finalTime = initialTime + totalSeconds;
    
    tm *returnTime = std::localtime(&finalTime);
    return returnTime;
}

tm *time_manipulation::subtractFromDate(tm *timeParam, const unsigned int &daysParam, const unsigned int &monthsParam, const unsigned int &yearsParam) {

    unsigned int totalDays = 0, totalSeconds;
    totalDays = totalDays + yearsParam * 365;
    totalDays = totalDays + monthsParam * 30;
    totalDays = totalDays + daysParam;
    totalSeconds = totalDays * 60 * 60 * 24;

    time_t initialTime = std::mktime(timeParam);
    time_t finalTime = initialTime - totalSeconds;
    
    tm *returnTime = std::localtime(&finalTime);
    return returnTime;
}
