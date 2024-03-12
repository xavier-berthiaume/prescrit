#include "time.h"

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

bool time_validation::checkDateBeforePresent(const tm *dateParam) {
	
	const auto currentTime = std::chrono::system_clock::now();
	const std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
	const std::tm *currentTime_tm = std::localtime(&currentTime_t);

	if(dateParam->tm_year > currentTime_tm->tm_year ||
	   dateParam->tm_mon > currentTime_tm->tm_mon ||
	   dateParam->tm_mday > currentTime_tm->tm_mday
	)
		return false;

	return true;
}
