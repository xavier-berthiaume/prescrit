#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Premade *generatedPremade = testFramework::generatePremade();
    std::cout << "Generated Premade: \n"
        "\tName: " << generatedPremade->getName() << "\n"
        "\tCompany: " << generatedPremade->getProducer() << "\n"
        "\tDetailed Name: " << generatedPremade->getDetailedName() << "\n";
    std::cout << std::endl;
    delete generatedPremade;

    return 0;
}
