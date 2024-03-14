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
};

#endif // !UNITS_H
