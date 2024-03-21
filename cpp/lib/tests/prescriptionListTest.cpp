// Things to test:
// 1. Creating a prescription history
// 2. Refill
// 3. Cleanup (no memleaks!)

#include <cassert>
#include <prescrit/structs.h>

int main(int argc, char *argv[]) {

	Prescriber *testPrescriber = new Prescriber();
	testPrescriber->setFirstName("Big");
	testPrescriber->setLastName("Bob");
	testPrescriber->setLicense("12345678");

	Product *testProduct = new Product();
	testProduct->setName("acetaminophen");
	
	Prescription *testPrescription = new Prescription();
	testPrescription->setOriginalDate(5, 10, 2023);
	testPrescription->setExpiryDate(5, 10, 2025);
	testPrescription->setRefillDate(20, 2, 2024);

	testPrescription->setPrescriber(testPrescriber);

	testPrescription->setOriginalProduct(testProduct);
	testPrescription->setGivenProduct(testProduct);

	testPrescription->setOriginalQuantity(30);
	testPrescription->setOriginalRefills(12);
	testPrescription->setRemainingQuantity(30*12);
	testPrescription->setRefillQuantity(0);

	PrescriptionRefillList refillHistory = PrescriptionRefillList();
	refillHistory.setHead(testPrescription);
	refillHistory.refillPrescription(30);
	assert((refillHistory.getHead()->getRemainingQuantity() == 330));
	refillHistory.refillPrescription(30);
	assert((refillHistory.getHead()->getRemainingQuantity() == 300));

	return 0;
}
