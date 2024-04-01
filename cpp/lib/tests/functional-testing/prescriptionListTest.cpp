// Things to test:
// 1. Creating a prescription history
// 2. Refill
// 3. Cleanup (no memleaks!)

#include <iostream>
#include <cassert>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    // Create the test prescriber
	Prescriber *testPrescriber = new Prescriber();
	testPrescriber->setFirstName("Big");
	testPrescriber->setLastName("Bob");
	testPrescriber->setLicense("12345678");

    // Create the test product
	Product *testProduct = new Product();
	testProduct->setName("acetaminophen");
	
    // Create the test prescription
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

    // Create the prescription refill history list
	PrescriptionRefillList refillHistory = PrescriptionRefillList();
	refillHistory.setHead(testPrescription);

    refillHistory.refillPrescription(30);
    assert((refillHistory.getHead()->getRemainingQuantity() == 330));
    refillHistory.refillPrescription(30);
    assert((refillHistory.getHead()->getRemainingQuantity() == 300));

    delete testPrescriber;
    delete testProduct;
    delete testPrescription;

    PrescriptionRefillList secondRefillHistory = PrescriptionRefillList();
    Normal *generatedPrescription = testFramework::generateNormal();
    generatedPrescription->setOriginalQuantity(60);
    generatedPrescription->setOriginalRefills(12);
    generatedPrescription->setRemainingQuantity(60*12);
    secondRefillHistory.setHead(generatedPrescription);
    delete generatedPrescription;
    secondRefillHistory.refillPrescription(60);
    secondRefillHistory.refillPrescription(60);
    secondRefillHistory.refillPrescription(60);
    secondRefillHistory.refillPrescription(60);

    Prescription *currentRefill = secondRefillHistory.getHead();
    std::cout << "Prescription History: \n\n";
    while (currentRefill != nullptr) {
    
        std::cout << "\tPrescription: \n"
            "\t\tOriginal Date: " << currentRefill->getOriginalDate().tm_mday << " / " << currentRefill->getOriginalDate().tm_mon+1 << " / " << currentRefill->getOriginalDate().tm_year+1900 << "\n"
            "\t\tExpiry Date: " << currentRefill->getExpiryDate().tm_mday << " / " << currentRefill->getExpiryDate().tm_mon+1 << " / " << currentRefill->getExpiryDate().tm_year+1900 << "\n"
            "\t\tRefill Date: " << currentRefill->getRefillDate().tm_mday << " / " << currentRefill->getRefillDate().tm_mon+1 << " / " << currentRefill->getRefillDate().tm_year+1900 << "\n"
            "\t\tPrescribed Product: " << currentRefill->getOriginalProduct()->getDetailedName() << "\n"
            "\t\tGiven Product: " << currentRefill->getGivenProduct()->getDetailedName() << "\n"
            "\t\tOriginal Quantity: " << currentRefill->getOriginalQuantity() << " r" << currentRefill->getOriginalRefills() << "\n"
            "\t\tRefill Quantity: " << currentRefill->getRefillQuantity() << "\n"
            "\t\tRemaining Quantity: " << currentRefill->getRemainingQuantity() << "\n";
        std::cout << std::endl;
        currentRefill = secondRefillHistory.getNextPrescription(currentRefill);
    }

	return 0;
}
