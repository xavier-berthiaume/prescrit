#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Magistral testMagistral = Magistral();

    Prescriber *generatedPrescriber = testFramework::generatePrescriber();
    testMagistral.setPrescriber(generatedPrescriber);
    delete generatedPrescriber;

    Product generatedProduct = Product();
    generatedProduct.setName(testFramework::generateValidMagistralName());
    testMagistral.setOriginalProduct(&generatedProduct);

    tm *refillDate, *originalDate, *expiryDate;
    std::tie(refillDate, originalDate, expiryDate) = testFramework::generatePrescriptionDates();
    testMagistral.setRefillDate(refillDate);
    testMagistral.setOriginalDate(originalDate);
    testMagistral.setExpiryDate(expiryDate);
    delete refillDate;
    delete originalDate;
    delete expiryDate;

    testMagistral.setOriginalQuantity(100);
    testMagistral.setOriginalRefills(12);
    testMagistral.setRemainingQuantity(1200);
    testMagistral.setRefillQuantity(0);
    
    Medication *generatedMedication = testFramework::generateMedication();
    testMagistral.addIngredient(generatedMedication);
    delete generatedMedication;

    Bandage *generatedBandage = testFramework::generateBandage();
    testMagistral.addIngredient(generatedBandage);
    delete generatedBandage;

    generatedBandage = testFramework::generateBandage();
    testMagistral.addIngredient(generatedBandage);
    delete generatedBandage;
    
    generatedBandage = testFramework::generateBandage();
    testMagistral.addIngredient(generatedBandage);
    delete generatedBandage;

    Syringe *generatedSyringe = testFramework::generateSyringe();
    testMagistral.addIngredient(generatedSyringe);
    delete generatedSyringe;

    Premade *generatedPremade = testFramework::generatePremade();
    testMagistral.addIngredient(generatedPremade);
    delete generatedPremade;

    return 0;
}
