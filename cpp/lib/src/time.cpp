#include <prescrit/utils/time.h>


bool time_validation::checkDayWithinRange(const unsigned short &dayParam, 
			       const unsigned short &monthParam, 
			       const unsigned short &yearParam) {

	unsigned short monthDays;
	bool leapyear;

	if ((yearParam % 4 == 0 && yearParam % 100 != 0) || (yearParam % 400 == 0))
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

bool time_validation::checkValidDate(const tm *timeToValidate) {

    if(!checkDayWithinRange(timeToValidate->tm_mday, timeToValidate->tm_mon, timeToValidate->tm_year))
        return false;

    if(!checkMonthWithinRange(timeToValidate->tm_mon))
        return false;

    if(!checkYearWithinRange(timeToValidate->tm_year))
        return false;

    return true;
}

bool time_validation::checkDateBeforePresent(const tm *dateParam) {
	
	const auto currentTime = std::chrono::system_clock::now();
	const std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	const std::tm *currentTime_tm = std::localtime(&currentTime_t);

	if(dateParam->tm_year > currentTime_tm->tm_year) {
		return false;
	} else if (dateParam->tm_year == currentTime_tm->tm_year) {
		if(dateParam->tm_mon > currentTime_tm->tm_mon) {
			return false;
		} else if (dateParam->tm_mon == currentTime_tm->tm_mon) {
			if(dateParam->tm_mday > currentTime_tm->tm_mday) {
				return false;
			}
		}
	}

	return true;
}

unsigned int time_validation::convertYearToDays(const unsigned int &yearParam) {

	if ((yearParam % 4 == 0 && yearParam % 100 != 0) || (yearParam % 400 == 0))
		return 366;

    return 365;
}

unsigned int time_validation::convertMonthToDays(const unsigned int &monthParam, const unsigned int &yearParam) {

	unsigned short monthDays;
	bool leapyear;

	if ((yearParam % 4 == 0 && yearParam % 100 != 0) || (yearParam % 400 == 0))
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

    return monthDays;
}

tm *time_validation::addToDate(tm *timeParam, const unsigned int &daysParam, const unsigned int &monthsParam, const unsigned int &yearsParam) {

    // Here, check timeParam->tm_year to know if it's a leap year
    // also loop through all the numbers that are between
    // timeParam->tm_year and timeParam->tm_year+2 and check which
    // are leap years
    // Add 1 day to result for each leap year skipped
    //
    // Also, if you start on a leap year or end on one, check to
    // see if the leap day was accounted for or not
    

    unsigned int totalDays = 0, totalSeconds;
    totalDays = totalDays + convertYearToDays(yearsParam);
    totalDays = totalDays + convertMonthToDays(monthsParam, yearsParam);
    totalDays = totalDays + daysParam;
    totalSeconds = totalDays * 60 * 60 * 24;

    time_t initialTime = std::mktime(timeParam);
    time_t finalTime = initialTime + totalSeconds;
    
    tm *returnTime = std::localtime(&finalTime);
    return returnTime;
}

tm *time_validation::subtractFromDate(tm *timeParam, const unsigned int &daysParam, const unsigned int &monthsParam, const unsigned int &yearsParam) {

    unsigned int totalDays = 0, totalSeconds;
    totalDays = totalDays + convertYearToDays(yearsParam);
    totalDays = totalDays + convertMonthToDays(monthsParam, yearsParam);
    totalDays = totalDays + daysParam;
    totalSeconds = totalDays * 60 * 60 * 24;

    time_t initialTime = std::mktime(timeParam);
    time_t finalTime = initialTime - totalSeconds;
    
    tm *returnTime = std::localtime(&finalTime);
    return returnTime;
}
