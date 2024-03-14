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

std::string units::convertToString(SizeUnit unitParam) {

	switch(unitParam) {
		case um:
			return "mcm";
		case mm:
			return "mm";
		case cm:
			return "cm";
		case m:
			return "m";
	}
}
