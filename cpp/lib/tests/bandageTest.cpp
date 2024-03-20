// Things to test:
// 1. Create a bandage object
// 2. Set a valid width, length and identifier
// 3. Get and validate the area provided
// 4. Try to assign an invalid identifier

#include <cassert>
#include <string>
#include <prescrit/structs.h>

int main(int argc, char *argv[]) {

	Bandage test_bandage = Bandage();
	test_bandage.setName(argv[2]);
	test_bandage.setProducer(argv[1]);
	test_bandage.setWidth(std::stoi(argv[3]), units::cm);
	test_bandage.setLength(std::stoi(argv[4]), units::cm);
	test_bandage.setIdentifier(argv[5]);

	std::tuple<unsigned int, units::AreaUnit> calculated_area = test_bandage.getArea();
	int area = std::stoi(argv[3]) * std::stoi(argv[4]);

	assert((std::get<0>(calculated_area) == area));
	assert((test_bandage.getIdentifier() == argv[5]));

	test_bandage.setIdentifier("This is a test string that is too long to be a valid identifier");
	assert((test_bandage.getIdentifier() == argv[5]));

	return 0;
}
