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

	enum AreaUnit {
		um2,
		mm2,
		cm2,
		m2
	};

	std::string convertToString(DoseUnit);
	std::string convertToString(SizeUnit);
	std::string convertToString(AreaUnit);
};

#endif // !UNITS_H
