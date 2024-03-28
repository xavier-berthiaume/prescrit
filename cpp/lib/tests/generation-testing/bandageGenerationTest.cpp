#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Bandage *generatedBandage = testFramework::generateBandage();

    std::cout << "Generated bandage: \n"
        "\tName: " << generatedBandage->getDetailedName() << "\n"
        "\tWidth: " << std::get<0>(generatedBandage->getWidth()) << units::convertToString(std::get<1>(generatedBandage->getWidth())) << "\n"
        "\tLength: " << std::get<0>(generatedBandage->getLength()) << units::convertToString(std::get<1>(generatedBandage->getLength())) << "\n"
        "\tArea: " << std::get<0>(generatedBandage->getArea()) << units::convertToString(std::get<1>(generatedBandage->getArea())) << "\n"
        "\tIdentifier: #" << generatedBandage->getIdentifier() << "\n";
    std::cout << std::endl;

    delete generatedBandage;

    return 0;
}
