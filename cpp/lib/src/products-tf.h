#ifndef PRODUCT_TF_H
#define PRODUCT_TF_H

#include <string>

#include "product.h"
#include "units.h"

namespace ProductTestFramework {

    std::string generateValidCompany();

    std::string generateValidName();

    unsigned int generateValidDose();

    units::DoseUnit selectUnit();
}

#endif
