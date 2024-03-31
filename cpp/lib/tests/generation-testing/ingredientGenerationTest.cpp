#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    // Generate an ingredient using the generation functionality
    Ingredient *generatedIngredient = testFramework::generateIngredient();
    std::cout << "Ingredient: \n"
        "Name: " << generatedIngredient->getFormattedName() << "\n"
        "Dose: " << generatedIngredient->getFormattedDose() << "\n";
    std::cout << std::endl;
    
    Ingredient *copyIngredient = new Ingredient(generatedIngredient);

    delete generatedIngredient;
    delete copyIngredient;

    return 0;
}
