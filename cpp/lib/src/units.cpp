#include "units.h"

std::string units::convertToString(DoseUnit unitParam) {
	
	switch(unitParam) {
		case ug:
			return "mcg";
		case mg:
			return "mg";
		case g:
			return "g";
		case uL:
			return "mcL";
		case mL:
			return "mL";
		case L:
			return "L";
		case mgmL:
			return "mg/mL";
		case ui:
			return "ui";
		case uimL:
			return "ui/mL";
	}
}
