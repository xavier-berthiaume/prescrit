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

    return 0;
}
