#ifndef PATIENT_H
#define PATIENT_H

#include <cctype>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>

#include <utilDefinitions.h>
#include <globalDefinitions.h>

class Patient {

	static const unsigned short kMaximumNameLength;

	std::string firstName_;
	std::string lastName_;

	unsigned short age_;
	tm *birthdate_;

	std::vector<std::string> phoneNumbers_;

public:

	Patient();

	~Patient();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getFullName() const;

	unsigned short getAge() const;
	std::string getFormattedBirthdate() const;
	const unsigned short getBirthDay() const;
	const unsigned short getBirthMonth() const;
	const unsigned short getBirthYear() const;

	std::vector<std::string> getPhoneNumbers() const;
	std::string getPhoneNumber(const unsigned int&) const;

	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	
	void setBirthDay(const unsigned short&);
	void setBirthMonth(const unsigned short&);
	void setBirthYear(const unsigned short&);
	void setBirthDate(const tm*);

	void addPhoneNumber(const std::string&);

};

#endif // !PATIENT_H
