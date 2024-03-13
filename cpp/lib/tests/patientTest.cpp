// Things to test:
// 1. Create a patient object with valid data
// 2. Set individual values with invalid data,
// check to make sure that nothing is changed
// in response.
// 3. Add a phone number that is valid

#include <cassert>
#include <string>
#include <structs/patient.h>

int main(int argc, char* argv[]) {

	Patient test_patient;

	test_patient.setFirstName(argv[1]);
	test_patient.setLastName(argv[2]);

	test_patient.setBirthDay((unsigned short)std::stoi(argv[3]));
	test_patient.setBirthMonth((unsigned short)std::stoi(argv[4]));
	test_patient.setBirthYear((unsigned short)std::stoi(argv[5]));

	assert((test_patient.getFirstName() == argv[1]));
	assert((test_patient.getLastName() == argv[2]));
	assert((test_patient.getBirthDay() == std::stoi(argv[3])));
	assert((test_patient.getBirthMonth() == std::stoi(argv[4])));
	assert((test_patient.getBirthYear() == std::stoi(argv[5])));

	return 0;
}
