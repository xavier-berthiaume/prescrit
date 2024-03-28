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

// Convert the years to number of days
// Account for the leap years
// Convert the months to days, account
// for the different number of days per
// month
// Add the number of days
tm *time_validation::addToDate(tm *timeParam, const unsigned int &daysParam, const unsigned int &monthsParam, const unsigned int &yearsParam) {

    unsigned int totalDays = 0;
    totalDays = totalDays + convertYearToDays(yearsParam);
    totalDays = totalDays + convertMonthToDays(monthsParam, yearsParam);
    totalDays = totalDays + timeParam;


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
}
