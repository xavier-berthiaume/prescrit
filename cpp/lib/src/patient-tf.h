#ifndef PATIENT_TF_H 
#define PATIENT_TF_H

#include <string>
#include <vector>
#include <random>

#include "patient.h"

namespace testFramework {

    std::string generateValidName();

    std::string generateInvalidName();

    tm *generateValidBirthday();

    tm *generateInvalidBirthday();

    Patient *generatePatient();
}

#endif
