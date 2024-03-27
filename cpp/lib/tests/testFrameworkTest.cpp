#include <iostream>

#include <prescrit/globals.h>
#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    std::cout << "Generated valid first name: " << testFramework::generateValidName() << "\n";        
    std::cout << "Generated valid first name: " << testFramework::generateValidName() << "\n";        
    std::cout << "Generated valid first name: " << testFramework::generateValidName() << "\n";        
    std::cout << std::endl;

    /*
     * Do not use this section of code for testing, it leaks memory and was only implemented
     * to quickly check what values were being spit out.
    std::cout << "Generated valid birth day: " << testFramework::generateValidBirthday()->tm_mday << "\n";
    std::cout << "Generated valid birth day: " << testFramework::generateValidBirthday()->tm_mday << "\n";
    std::cout << "Generated valid birth day: " << testFramework::generateValidBirthday()->tm_mday << "\n";
    std::cout << std::endl;

    std::cout << "Generated valid birth month: " << testFramework::generateValidBirthday()->tm_mon << "\n";
    std::cout << "Generated valid birth month: " << testFramework::generateValidBirthday()->tm_mon << "\n";
    std::cout << "Generated valid birth month: " << testFramework::generateValidBirthday()->tm_mon << "\n";
    std::cout << std::endl;

    std::cout << "Generated valid birth year: " << testFramework::generateValidBirthday()->tm_year+1900 << "\n";
    std::cout << "Generated valid birth year: " << testFramework::generateValidBirthday()->tm_year+1900 << "\n";
    std::cout << "Generated valid birth year: " << testFramework::generateValidBirthday()->tm_year+1900 << "\n";
    std::cout << std::endl;
    */

    tm *validBday = testFramework::generateValidBirthday();
    std::cout << "Generated valid birthday: \n"
        "\tDay: " << validBday->tm_mday << "\n"
        "\tMonth: " << validBday->tm_mon << "\n"
        "\tYear: " << validBday->tm_year+1900 << "\n";
    std::cout << std::endl;
    delete validBday;

    tm *invalidBday = testFramework::generateInvalidBirthday();
    std::cout << "Generated invalid birthday: \n"
        "\tDay: " << invalidBday->tm_mday << "\n"
        "\tMonth: " << invalidBday->tm_mon << "\n"
        "\tYear: " << invalidBday->tm_year+1900 << "\n";
    std::cout << std::endl;
    delete invalidBday;

    Patient *testpatient = testFramework::generatePatient();
    delete testpatient;

    std::cout << "Generated valid product company: " << testFramework::generateValidCompany() << "\n";
    std::cout << "Generated valid product company: " << testFramework::generateValidCompany() << "\n";
    std::cout << "Generated valid product company: " << testFramework::generateValidCompany() << "\n";
    std::cout << std::endl;

    std::cout << "Generated valid product name: " << testFramework::generateValidProductName() << "\n";
    std::cout << "Generated valid product name: " << testFramework::generateValidProductName() << "\n";
    std::cout << "Generated valid product name: " << testFramework::generateValidProductName() << "\n";
    std::cout << std::endl;

    std::cout << "Generate valid product dose: " << testFramework::generateValidDose() << "\n";
    std::cout << "Generate valid product dose: " << testFramework::generateValidDose() << "\n";
    std::cout << "Generate valid product dose: " << testFramework::generateValidDose() << "\n";
    std::cout << std::endl;
    
    Product *generatedProduct = testFramework::generateProduct();
    std::cout << "Generated Product: \n"
        "\tName: " << generatedProduct->getName() << "\n"
        "\tDetailed Name: " << generatedProduct->getDetailedName() << "\n";
    std::cout << std::endl;
    delete generatedProduct;

    Premade *generatedPremade = testFramework::generatePremade();
    std::cout << "Generated Premade: \n"
        "\tName: " << generatedPremade->getName() << "\n"
        "\tCompany: " << generatedPremade->getProducer() << "\n"
        "\tDetailed Name: " << generatedPremade->getDetailedName() << "\n";
    std::cout << std::endl;
    delete generatedPremade;

    Medication *generatedMedication = testFramework::generateMedication();
    std::cout << "Generated Medication: \n"
        "\tName: " << generatedMedication->getName() << "\n"
        "\tCompany: " << generatedMedication->getProducer() << "\n"
        "\tDIN: " << generatedMedication->getDIN() << "\n"
        "\tAnnex: " << generatedMedication->getAnnex() << "\n"
        "\tDetailed Name: " << generatedMedication->getDetailedName() << "\n";
    std::cout << std::endl;
    delete generatedMedication;
    
    // Test work location generation here
    WorkLocation *generatedLocation = testFramework::generateWorkLocation();
    std::cout << "Generated Work Location: \n"
        "\tAddress: " << generatedLocation->getFormattedAddress() << "\n";
    std::cout << std::endl;
    delete generatedLocation;

    Prescriber *generatedPrescriber = testFramework::generatePrescriber();
    std::cout << "Generated Prescriber: \n"
        "\tFull Name: " << generatedPrescriber->getFullName() << "\n"
        "\tLicense Number: " << generatedPrescriber->getLicense() << "\n";
    delete generatedPrescriber;
    std::cout << std::endl;

    tm *refillDate, *originalDate, *expiryDate;
    std::tie(refillDate, originalDate, expiryDate) = testFramework::generatePrescriptionDates();
    std::cout << "Generated Dates: \n"
        "\tRefill Date: \n"
        "\t\tYear: " << refillDate->tm_year+1900 << "\n"
        "\t\tMonth: " << refillDate->tm_mon << "\n"
        "\t\tDay: " << refillDate->tm_mday << "\n"
        "\tOriginal Date: \n"
        "\t\tYear: " << originalDate->tm_year+1900 << "\n"
        "\t\tMonth: " << originalDate->tm_mon << "\n"
        "\t\tDay: " << originalDate->tm_mday << "\n"
        "\tExpiry Date: \n"
        "\t\tYear: " << expiryDate->tm_year+1900 << "\n"
        "\t\tMonth: " << expiryDate->tm_mon << "\n"
        "\t\tDay: " << expiryDate->tm_mday << "\n";
    std::cout << std::endl;
    delete refillDate;
    delete originalDate;
    delete expiryDate;

    Prescription *generatedPrescription = testFramework::generatePrescription();
    std::cout << "Generated Prescription: \n"
        "\tDates: \n"
        "\t\tOriginal Date: "
        << generatedPrescription->getOriginalDate().tm_mday << " - "
        << generatedPrescription->getOriginalDate().tm_mon << " - "
        << generatedPrescription->getOriginalDate().tm_year+1900 << "\n"
        "\t\tExpiration Date: "
        << generatedPrescription->getExpiryDate().tm_mday << " - "
        << generatedPrescription->getExpiryDate().tm_mon << " - "
        << generatedPrescription->getExpiryDate().tm_year+1900 << "\n"
        "\t\tRefill Date: "
        << generatedPrescription->getRefillDate().tm_mday << " - "
        << generatedPrescription->getRefillDate().tm_mon << " - "
        << generatedPrescription->getRefillDate().tm_year+1900 << "\n"
        "\tPrescriber: \n"
        "\t\tName: " << generatedPrescription->getPrescriber()->getFullName() << "\n"
        "\t\tLicense: " << generatedPrescription->getPrescriber()->getLicense() << "\n"
        "\tPrescribed Product: " << generatedPrescription->getOriginalProduct()->getDetailedName() << "\n"
        "\tGiven Product: " << generatedPrescription->getGivenProduct()->getDetailedName() << "\n"
        "\tQuantities: \n"
        "\t\tPrescribed: " << generatedPrescription->getOriginalQuantity() << "\n"
        "\t\tRefills: " << generatedPrescription->getOriginalRefills() << "\n"
        "\t\tRemaining: " << generatedPrescription->getRemainingQuantity() << "\n"
        "\t\tPrevious Refill: " << generatedPrescription->getRefillQuantity() << "\n";
    std::cout << std::endl;
    delete generatedPrescription;

    return 0;
}
