// Things to test:
// 1. Create a syringe object

#include <cassert>
#include <string>
#include <prescrit/structs.h>

int main(int argc, char *argv[]) {

	Syringe test_syringe = Syringe();

	test_syringe.setName(argv[2]);
	test_syringe.setProducer(argv[1]);
	test_syringe.setGuage(std::stoi(argv[3]));
	test_syringe.setIdentifier(argv[4]);

	assert((test_syringe.getIdentifier() == argv[4]));
	test_syringe.setIdentifier("This string is too long to be considered a valid identifier. It should not be able to replace the already valid identifier.");
	assert((test_syringe.getIdentifier() == argv[4]));

	return 0;
}
