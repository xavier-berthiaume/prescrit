#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Product *generatedProduct = testFramework::generateProduct();
    std::cout << "Generated Product: \n"
        "\tName: " << generatedProduct->getName() << "\n"
        "\tDetailed Name: " << generatedProduct->getDetailedName() << "\n";
    std::cout << std::endl;
    delete generatedProduct;

    return 0;
}
