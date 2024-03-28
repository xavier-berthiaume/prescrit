#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Patient *generatedPatient = testFramework::generatePatient();
    std::cout << "Generated Patient: \n"
        "\tName: " << generatedPatient->getFullName() << "\n"
        "\tBirthday: " << generatedPatient->getFormattedBirthdate() << "\n";
    std::cout << std::endl;

    return 0;
}
