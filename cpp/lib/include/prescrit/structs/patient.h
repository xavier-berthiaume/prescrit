#ifndef PATIENT_H
#define PATIENT_H

#include <ctime>
#include <cctype>
#include <chrono>
#include <tuple>
#include <string>
#include <vector>

#include "../globals.h"
#include "../utils.h"

class Patient {

	static const uint16_t kMaximumNameLength;

	std::string firstName_;
	std::string lastName_;

	tm birthdate_;

	std::vector<std::string> phoneNumbers_;
public:

	Patient();
	Patient(Patient *);
	~Patient();

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getFullName() const;

    std::tuple<unsigned short, std::string> getAge() const;
	std::string getFormattedBirthdate() const;
	const unsigned short getBirthDay() const;
	const unsigned short getBirthMonth() const;
	const unsigned short getBirthYear() const;
    const tm *getBirthDate() const;

	std::vector<std::string> getPhoneNumbers() const;
	std::string getPhoneNumber(const unsigned int&) const;

	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	
    /**
     * @deprecated
     */
	void setBirthDay(const unsigned short&);

    /**
     * @deprecated
     */
	void setBirthMonth(const unsigned short&);

    /**
     * @deprecated
     */
	void setBirthYear(const unsigned short&);

	void setBirthDate(const tm*);

	void addPhoneNumber(const std::string&);
};

#endif // !PATIENT_H
