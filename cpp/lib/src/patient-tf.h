#ifndef PATIENT_TF_H 
#define PATIENT_TF_H

#include <string>

#include "patient.h"

namespace PatientTestFramework {

    std::string generateValidName();

    std::string generateInvalidName();

    tm *generateValidBirthday();

    tm *generateInvalidBirthday();

    Patient *generatePatient();
}

#endif
