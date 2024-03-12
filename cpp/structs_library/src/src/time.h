#ifndef TIME_H
#define TIME_H

#include "../globalDefinitions.h"

#include <chrono>
#include <ctime>

namespace time_validation {

	bool checkDayWithinRange(const unsigned short&, const unsigned short&, const unsigned short&);

	bool checkMonthWithinRange(const unsigned short&);

	bool checkYearWithinRange(const unsigned short&);

	bool checkDateBeforePresent(const tm*);
};

#endif // !TIME_H
