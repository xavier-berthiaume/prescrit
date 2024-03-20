// Things to test:
// 1. Create a prescription with valid data
// 2. Set individual values with invalid data
// and check to make sure that nothing was changed
// 2.1 Set invalid products (nullptr)
// 2.2 Set invalid dates (Post year 3000)
// 2.3 Set invalid dates (Pre year 1900)
// 2.4 Set invalid prescriber (nullptr)
// 2.5 Set invalid quantities
//
// A seperate test will be created to test the refill function of the Prescription class

#include <cassert>
#include <iostream>

#include <structs/prescriber.h>
#include <structs/product.h>
#include <structs/prescription.h>

int main(int argc, char *argv[]) {

	std::cout << "Creating test product";
	Product *testProduct = new Product;
	testProduct->setName("Test Product");

	std::cout << "Creating test prescriber";
	Prescriber *testPrescriber = new Prescriber;
	testPrescriber->setFirstName("Bob");
	testPrescriber->setLastName("Ross");
	testPrescriber->setLicense("123456");

	std::cout << "Creating test prescription";
	Prescription testPrescription = Prescription();

	std::cout << "Setting dates";
	testPrescription.setOriginalDate(5, 10, 2023);
	testPrescription.setExpiryDate(5, 10, 2025);
	testPrescription.setRefillDate(20, 3, 2024);

	std::cout << "Setting quantities";
	testPrescription.setOriginalQuantity(30);
	testPrescription.setOriginalRefills(12);
	testPrescription.setRemainingQuantity(30*12);
	testPrescription.setRefillQuantity(0);

	std::cout << "Setting prescriber";
	testPrescription.setPrescriber(testPrescriber);

	std::cout << "Setting products";
	testPrescription.setOriginalProduct(testProduct);
	testPrescription.setGivenProduct(testProduct);

	// Assertions that check if the object was properly created
	assert((testPrescription.getPrescriber() != nullptr));
	assert((testPrescription.getOriginalProduct() != nullptr));
	assert((testPrescription.getGivenProduct() != nullptr));

	assert((testPrescription.getOriginalDate().tm_mday == 5));
	assert((testPrescription.getOriginalDate().tm_mon == 10));
	assert((testPrescription.getOriginalDate().tm_year+1900 == 2023));

	assert((testPrescription.getExpiryDate().tm_mday == 5));
	assert((testPrescription.getExpiryDate().tm_mon == 10));
	assert((testPrescription.getExpiryDate().tm_year+1900 == 2025));

	assert((testPrescription.getRefillDate().tm_mday == 20));
	assert((testPrescription.getRefillDate().tm_mon == 3));
	assert((testPrescription.getRefillDate().tm_year+1900 == 2024));

	assert((testPrescription.getOriginalQuantity() == 30));
	assert((testPrescription.getOriginalRefills() == 12));
	assert((testPrescription.getRemainingQuantity() == 360));
	assert((testPrescription.getRefillQuantity() == 0));

	// Try adding invalid data
	testPrescription.setPrescriber(nullptr);
	assert((testPrescription.getPrescriber() != nullptr));

	testPrescription.setOriginalProduct(nullptr);
	testPrescription.setGivenProduct(nullptr);
	assert((testPrescription.getOriginalProduct() != nullptr));
	assert((testPrescription.getGivenProduct() != nullptr));
}
