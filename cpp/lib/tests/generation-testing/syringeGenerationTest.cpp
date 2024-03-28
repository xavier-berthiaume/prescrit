#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Syringe *generatedSyringe = testFramework::generateSyringe();

    std::cout << "Generated Syringe: \n"
        "\tName: " << generatedSyringe->getDetailedName() << "\n"
        "\tGuage: " << generatedSyringe->getGuage() << "G\n"
        "\tIdentifier: " << generatedSyringe->getIdentifier() << "\n";

    delete generatedSyringe;

    return 0;
}
