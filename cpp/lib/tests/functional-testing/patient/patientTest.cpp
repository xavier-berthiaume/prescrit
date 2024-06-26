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
#include <iostream>
#include <string>
#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char* argv[]) {

	Patient test_patient;

	// Save values to patient object
	test_patient.setFirstName(argv[1]);
	test_patient.setLastName(argv[2]);

    tm birthday = tm();
    birthday.tm_mday = std::stoi(argv[3]);
    birthday.tm_mon = std::stoi(argv[4])-1;
    birthday.tm_year = std::stoi(argv[5])-1900;

    test_patient.setBirthDate(&birthday);

    std::cout << "Patient: \n"
        "First Name: " << test_patient.getFirstName() << "\n"
        "Last Name: " << test_patient.getLastName() << "\n"
        "Birthday: " << test_patient.getBirthDay() << "/" << test_patient.getBirthMonth() << "/" << test_patient.getBirthYear() << "\n";
    std::cout << std::endl;

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

    std::tm invalid_date = tm();
    invalid_date.tm_year = -25; // Invalid year
    invalid_date.tm_mon = 10; // Valid month
    invalid_date.tm_mday = 13; // Valid day
    
    test_patient.setBirthDate(&invalid_date);
	
    assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	assert((test_patient.getBirthMonth() == std::stoi(argv[4])));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

    invalid_date.tm_year = 100; // Valid year
    invalid_date.tm_mon = 30; // Invalid month
    invalid_date.tm_mday = 13; // Valid day

    test_patient.setBirthDate(&invalid_date);

	assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	assert((test_patient.getBirthMonth() == std::stoi(argv[4])));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

    invalid_date.tm_year = 100; // Valid year
    invalid_date.tm_mon = 10; // Valid month
    invalid_date.tm_mday = 130; // Invalid day

    test_patient.setBirthDate(&invalid_date);

	assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	assert((test_patient.getBirthMonth() == std::stoi(argv[4])));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	std::tm future_date = tm();
	future_date.tm_year = 125;
	future_date.tm_mon = 11;
	future_date.tm_mday = 15;

	test_patient.setBirthDate(&future_date);
	
	assert((test_patient.getBirthDay() != 15));
	assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	
	assert((test_patient.getBirthYear() != 11));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	assert((test_patient.getBirthYear() != 2025));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));
	
	tm valid_birth_date = tm();
	valid_birth_date.tm_mday = 10;
	valid_birth_date.tm_mon = 2;
	// 93 as year in tm struct is 1993
	valid_birth_date.tm_year = 93;

	test_patient.setBirthDate(&valid_birth_date);
	
	assert((test_patient.getBirthDay() == 10));
	assert((test_patient.getBirthMonth() == 3));
	assert((test_patient.getBirthYear() == 1993));

	std::string valid_phone_number {"1123456789"};
	test_patient.addPhoneNumber(valid_phone_number);

	return 0;
}
