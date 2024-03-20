// Things to test:
// 1. Create a prescription with valid data
// 2. Set individual values with invalid data
// and check to make sure that nothing was changed
// 2.1 Set invalid products (nullptr)
// 2.2 Set invalid dates (Post year 3000)
// 2.3 Set invalid dates (Pre year 1900)
// 2.4 Set invalid prescriber (nullptr)
// 2.5 Set invalid quantities

#include <cassert>

#include <structs/prescription.h>

int main(int argc, char *argv[]) {

	Product *testProduct = new Product;
	testProduct->setName("Test Product");

	Prescriber *testPrescriber = new Prescriber;
	testPrescriber->setFirstName("Bob");
	testPrescriber->setLastName("Ross");
	testPrescriber->setLicense("123456");

	Prescription testPrescription = Prescription();
	testPrescription.setOriginalDate(5, 10, 2023);
	testPrescription.setExpiryDate(5, 10, 2025);
	testPrescription.setRefillDate(20, 3, 2024);

	testPrescription.setOriginalQuantity(30);
	testPrescription.setOriginalRefills(12);
	testPrescription.setRemainingQuantity(30*12);
	testPrescription.setRefillQuantity(0);

	testPrescription.setPrescriber(testPrescriber);
}
