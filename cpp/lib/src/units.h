#ifndef UNITS_H
#define UNITS_H

#include <string>

namespace units {
	enum DoseUnit {
		ug,
		mg,
		g,
		uL,
		mL,
		L,
		mgmL,
		ui,
		uimL,
	};


	enum SizeUnit {
		um,
		mm,
		cm,
		m
	};

	std::string convertToString(DoseUnit);
	std::string convertToString(SizeUnit);

	long convertToBase(const int&, DoseUnit);	
	long convertToBase(const int&, SizeUnit);	

	long convertFromBaseToUnit(DoseUnit);
	long convertFromBaseToUnit(SizeUnit);

	long convertToUnit(const int&, DoseUnit, DoseUnit);
	long convertToUnit(const int&, SizeUnit, DoseUnit);
};

#endif // !UNITS_H
