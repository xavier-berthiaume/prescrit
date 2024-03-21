#ifndef PRESCRIBER_H
#define PRESCRIBER_H

#include <string>
#include <cctype>

#include "globalDefinitions.h"
#include "location.h"

class Prescriber {
	std::string firstName_;
	std::string lastName_;
	std::string license_;

	LocationList *workLocations_;

	static bool validateLicense(const std::string&);
public:
	Prescriber();
    Prescriber(Prescriber *);
	~Prescriber();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getFullName() const;
	std::string getLicense() const;

	LocationList *getLocations() const;

	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	void setLicense(const std::string&);
	void addLocation(const std::string&, const std::string&, const std::string&);

};

#endif // !PRESCRIBER_H
