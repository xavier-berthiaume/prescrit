#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Medication *generatedMedication = testFramework::generateMedication();
    std::cout << "Generated Medication: \n"
        "\tName: " << generatedMedication->getName() << "\n"
        "\tCompany: " << generatedMedication->getProducer() << "\n"
        "\tDIN: " << generatedMedication->getDIN() << "\n"
        "\tAnnex: " << generatedMedication->getAnnex() << "\n"
        "\tDetailed Name: " << generatedMedication->getDetailedName() << "\n"
        "\tIngredients: \n";
    Ingredient *currentIngredient = generatedMedication->getActiveIngredients()->getHead();
    while(currentIngredient != nullptr) {
    
        std::cout << "\t\t" << currentIngredient->getFormattedName() << "\n";
        currentIngredient = currentIngredient->getNext();
    }
    std::cout << std::endl;
    delete generatedMedication;

    return 0;
}
