#ifndef PRESCRIPTION_TF_H
#define PRESCRIPTION_TF_H

#include <string>

#include "../structs.h"
#include "patient-tf.h"
#include "products-tf.h"
#include "prescriber-tf.h"

namespace testFramework {

    std::string generateValidMagistralName();

    std::tuple<tm *, tm *, tm *> generatePrescriptionDates();

    Prescription *generatePrescription();

    Magistral *generateMagistral();

    PrescriptionRefillList *generatePrescriptionList();
}

#endif
