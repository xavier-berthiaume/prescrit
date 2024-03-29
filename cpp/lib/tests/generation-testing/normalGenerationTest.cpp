#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Normal *generatedPrescription = testFramework::generateNormal();
    std::string productType = "";

    if(dynamic_cast<Medication *>(generatedPrescription->getOriginalProduct())) {
        productType = "Medication()";
    } else if(dynamic_cast<Bandage *>(generatedPrescription->getOriginalProduct())) {
        productType = "Bandage()";
    } else if(dynamic_cast<Syringe *>(generatedPrescription->getOriginalProduct())) {
        productType = "Syringe()";
    } else {
        productType = "Premade()";
    }

    std::cout << "Generated Prescription: \n"
        "\tDates: \n"
        "\t\tOriginal Date: "
        << generatedPrescription->getOriginalDate().tm_mday << " - "
        << generatedPrescription->getOriginalDate().tm_mon+1 << " - "
        << generatedPrescription->getOriginalDate().tm_year+1900 << "\n"
        "\t\tExpiration Date: "
        << generatedPrescription->getExpiryDate().tm_mday << " - "
        << generatedPrescription->getExpiryDate().tm_mon+1 << " - "
        << generatedPrescription->getExpiryDate().tm_year+1900 << "\n"
        "\t\tRefill Date: "
        << generatedPrescription->getRefillDate().tm_mday << " - "
        << generatedPrescription->getRefillDate().tm_mon+1 << " - "
        << generatedPrescription->getRefillDate().tm_year+1900 << "\n"
        "\tPrescriber: \n"
        "\t\tName: " << generatedPrescription->getPrescriber()->getFullName() << "\n"
        "\t\tLicense: " << generatedPrescription->getPrescriber()->getLicense() << "\n"
        "\tPrescribed Product: " << generatedPrescription->getOriginalProduct()->getDetailedName() << "\n"
        "\tGiven Product: " << generatedPrescription->getGivenProduct()->getDetailedName() << "\n"
        "\tProduct Type: " << productType << "\n"
        "\tQuantities: \n"
        "\t\tPrescribed: " << generatedPrescription->getOriginalQuantity() << "\n"
        "\t\tRefills: " << generatedPrescription->getOriginalRefills() << "\n"
        "\t\tRemaining: " << generatedPrescription->getRemainingQuantity() << "\n"
        "\t\tPrevious Refill: " << generatedPrescription->getRefillQuantity() << "\n";
    std::cout << std::endl;

    delete generatedPrescription;

    return 0;
}
