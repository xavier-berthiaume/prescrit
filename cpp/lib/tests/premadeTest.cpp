// Things to test
// 1. Creating the premade object and setting a producer
// 2. Making sure that the name and detailed name don't return
// the same value. Detailed name should take the most derived
// implementation.

#include <cassert>
#include <string>
#include <structs/product.h>

int main(int argc, char *argv[]) {

	Premade test_product = Premade();

	test_product.setProducer(argv[1]);
	test_product.setName(argv[2]);

	assert((test_product.getName() != test_product.getDetailedName()));
}
