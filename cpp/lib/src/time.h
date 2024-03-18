#ifndef TIME_H
#define TIME_H

#include "globalDefinitions.h"

#include <chrono>
#include <ctime>

// Collection of time validation functions
namespace time_validation {

	/**
	 * @brief Validates that a provided unsigned short is a valid day number within a given month and year.
	 *
	 * @return True on a valid date being passed
	 */
	bool checkDayWithinRange(const unsigned short&, const unsigned short&, const unsigned short&);

	bool checkMonthWithinRange(const unsigned short&);

	bool checkYearWithinRange(const unsigned short&);

	bool checkDateBeforePresent(const tm*);
};

#endif // !TIME_H 
