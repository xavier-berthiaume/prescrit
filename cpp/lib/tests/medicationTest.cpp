// Things to test:
// 1. Create a medication object
// 2. Set a valid name, producer, din,
// ingredient, and annex
// 3. Try setting an invalid din, valid
// din should not be overwritten
// 4. Try getting the ingredients

#include <cassert>
#include <prescrit/structs.h>

int main(int argc, char *argv[]) {

	Medication test_medication = Medication();
	test_medication.setDIN(argv[3]);
	test_medication.setProducer(argv[1]);
	test_medication.setName(argv[2]);

	test_medication.AddIngredient(argv[4], std::stoi(argv[5]), units::mg);

	assert((test_medication.getName() != test_medication.getDetailedName()));
	assert((test_medication.getDIN() == argv[3]));
	assert((test_medication.getActiveIngredients()->getHead() != nullptr));

	return 0;
}
