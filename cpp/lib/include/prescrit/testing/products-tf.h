#ifndef PRODUCT_TF_H
#define PRODUCT_TF_H

#include <string>

#include "../structs.h"
#include "../utils.h"

namespace testFramework {

    std::string generateValidCompany();

    std::string generateValidProductName();

    std::string generateValidMagistralName();

    unsigned int generateValidDose();

    std::string generateValidDIN();

    units::DoseUnit selectUnit();

    ValidPrescriptionTypes selectAnnex();

    Ingredient *generateIngredient();

    Product *generateProduct();

    Premade *generatePremade();

    Medication *generateMedication();

    Magistral *generateMagistral();
}

#endif
