#ifndef TIME_H
#define TIME_H

#include "../globals.h"

#include <chrono>
#include <ctime>

// Collection of time validation functions
namespace time_validation {

	/**
     * @deprecated
	 * @brief Validates that a provided unsigned short is a valid day number within a given month and year.
	 *
     * @param The first parameter is the day of the month
     * @param The second parameter is the month that is to be checked, it should be zero-indexed (January is month 0)
     * @param The third parameter is the year that is to be checked
     *
	 * @return True on a valid date being passed
	 */
	bool checkDayWithinRange(const unsigned short&, const unsigned short&, const unsigned short&);

	/**
     * @deprecated
	 * @brief Validates that a provided unsigned short is a valid month number.
	 *
     * @param The first parameter is the month, it should be zero-indexed (January is month 0)
     *
	 * @return True on a valid month being passed
	 */
	bool checkMonthWithinRange(const unsigned short&);

	/**
     * @deprecated
	 * @brief Validates that a provided unsigned short is a valid month number.
	 *
     * @param The first parameter is the year that is to be checked 
     *
	 * @return True on a valid year being passed
	 */
	bool checkYearWithinRange(const unsigned short&);
    
    bool checkDayWithinRange(const tm *);

    bool checkMonthWithinRange(const tm *);

    bool checkYearWithinRange(const tm *);

    bool checkValidDate(const tm *);

	bool checkDateBeforePresent(const tm *);
};

namespace time_manipulation {

    tm *addToDate(tm *, const unsigned int &, const unsigned int &, const unsigned int &);

    tm *subtractFromDate(tm *, const unsigned int &, const unsigned int &, const unsigned int &);
};

#endif // !TIME_H 
