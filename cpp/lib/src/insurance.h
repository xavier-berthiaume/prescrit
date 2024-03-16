#ifndef INSURANCE_H
#define INSURANCE_H

#include <string>

#include "globalDefinitions.h"

enum Beneficiary {
	Insured,
	Spouse,
	Child
};

class Insurance {

	std::string carrier_;
	std::string group_;
	std::string policy_;

	Beneficiary beneficiary_;

public:
	std::string getCarrier() const;
	std::string getGroup() const;
	std::string getPolicy() const;
	Beneficiary getBeneficiary() const;
	
	void setCarrier(const std::string&);
	void setGroup(const std::string&);
	void setPolicy(const std::string&);
	void setBeneficiary(Beneficiary);
};

#endif // !INSURANCE_H
