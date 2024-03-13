// Things to test:
// 1. Create a patient object with valid data
// 2. Set individual values with invalid data,
// check to make sure that nothing is changed
// in response.
// 2.1. Set invalid first name 
// 2.2. Set invalid last name 
// 2.3. Set invalid birth day 
// 2.4. Set invalid birth month 
// 2.5. Set invalid birth year (before 1900 and after the current year) 
// 2.6. Set an overall invalid birth date (date after current day)
// 3. Add a phone number that is valid

#include <cassert>
#include <ctime>
#include <string>
#include <iostream>
#include <structs/patient.h>

int main(int argc, char* argv[]) {

	Patient test_patient;

	// Save values to patient object
	test_patient.setFirstName(argv[1]);
	test_patient.setLastName(argv[2]);

	test_patient.setBirthDay((unsigned short)std::stoi(argv[3]));
	test_patient.setBirthMonth((unsigned short)std::stoi(argv[4]));
	test_patient.setBirthYear((unsigned short)std::stoi(argv[5]));

	// Assert that values saved to the patient are the same when retrieved
	assert((test_patient.getFirstName() == argv[1]));
	assert((test_patient.getLastName() == argv[2]));
	assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	assert((test_patient.getBirthMonth() == std::stoi(argv[4])));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	// Assert that after passing an invalid name the patient class won't
	// change the currently valid data
	test_patient.setFirstName("123456");
	assert((test_patient.getFirstName() != "123456"));
	assert((test_patient.getFirstName() == argv[1]));

	test_patient.setLastName("123456");
	assert((test_patient.getLastName() != "123456"));
	assert((test_patient.getLastName() == argv[2]));

	// Assert that after passing invalid dates the patient class won't
	// change the currently valid data
	test_patient.setBirthDay(40);
	assert((test_patient.getBirthDay() != 40));
	assert((test_patient.getBirthDay() == std::stoi(argv[3])));

	test_patient.setBirthMonth(15);
	assert((test_patient.getBirthMonth() != 15));
	assert((test_patient.getBirthMonth() == std::stoi(argv[4])));

	test_patient.setBirthYear(1800);
	assert((test_patient.getBirthYear() != 1800));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));
	
	test_patient.setBirthYear(2500);
	assert((test_patient.getBirthYear() != 2500));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	std::tm future_date;
	future_date.tm_year = 2025;
	future_date.tm_mon = 11;
	future_date.tm_mday = 15;

	test_patient.setBirthDate(&future_date);
	
	assert((test_patient.getBirthDay() != 15));
	assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	
	assert((test_patient.getBirthYear() != 11));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	assert((test_patient.getBirthYear() != 2025));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	std::tm valid_birth_date;
	valid_birth_date.tm_mday = 10;
	valid_birth_date.tm_mon = 3;
	valid_birth_date.tm_year = 1993;

	test_patient.setBirthDate(&valid_birth_date);
	
	std::cout << "Birthday: " << test_patient.getBirthDay();
	std::cout << "Birthmonth: " << test_patient.getBirthMonth();
	std::cout << "Birthyear: " << test_patient.getBirthYear();

	assert((test_patient.getBirthDay() == 10));
	assert((test_patient.getBirthMonth() == 3));
	assert((test_patient.getBirthYear() == 1993));

	std::string valid_phone_number {"1123456789"};
	test_patient.addPhoneNumber(valid_phone_number);

	return 0;
}
