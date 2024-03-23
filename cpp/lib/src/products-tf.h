#ifndef PRODUCT_TF_H
#define PRODUCT_TF_H

#include <string>

#include "product.h"
#include "units.h"

namespace testFramework {

    std::string generateValidCompany();

    std::string generateValidProductName();

    unsigned int generateValidDose();

    units::DoseUnit selectUnit();
}

#endif
