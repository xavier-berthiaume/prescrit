#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Prescriber *generatedPrescriber = testFramework::generatePrescriber();
    std::cout << "Generated Prescriber: \n"
        "\tFull Name: " << generatedPrescriber->getFullName() << "\n"
        "\tLicense Number: " << generatedPrescriber->getLicense() << "\n"
        "\tLocations: \n";
    WorkLocation *currentLocation = generatedPrescriber->getLocations()->getHead();
    while (currentLocation != nullptr) {

        std::cout << "\t\t" << currentLocation->getFormattedAddress() << "\n";
        currentLocation = currentLocation->getNext();
    }
    std::cout << std::endl;
    delete generatedPrescriber;

    return 0;
}
