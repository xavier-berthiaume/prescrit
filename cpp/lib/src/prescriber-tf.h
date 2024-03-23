#ifndef PRESCRIBER_TF_H
#define PRESCRIBER_TF_H

#include <string>

#include "prescriber.h"

namespace PrescriberTestFramework {

    std::string generateValidName();

    std::string generateInvalidName();

    std::string generateValidLicense();

    std::string generateInvalidLicense();

    WorkLocation *generateWorkLocation();

    LocationList *generateLocationList();

    Prescriber *generatePrescriber();
}

#endif
