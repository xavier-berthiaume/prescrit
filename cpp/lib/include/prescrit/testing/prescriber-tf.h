#ifndef PRESCRIBER_TF_H
#define PRESCRIBER_TF_H

#include <string>

#include "../structs.h"

namespace testFramework {

    std::string generateValidLicense();

    std::string generateInvalidLicense();

    std::string generateAddress();

    std::string generateCity();

    std::string generateZipCode();

    WorkLocation *generateWorkLocation();

    Prescriber *generatePrescriber();
}

#endif
