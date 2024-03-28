#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    // Test work location generation here
    WorkLocation *generatedLocation = testFramework::generateWorkLocation();
    std::cout << "Generated Work Location: \n"
        "\tAddress: " << generatedLocation->getFormattedAddress() << "\n";
    std::cout << std::endl;
    delete generatedLocation;

    return 0;
}
