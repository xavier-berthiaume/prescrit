#ifndef PRESCRIPTION_TF_H
#define PRESCRIPTION_TF_H

#include <string>

#include "../structs.h"
#include "patient-tf.h"
#include "products-tf.h"
#include "prescriber-tf.h"

namespace testFramework {

    Prescription *generatePrescription();

    PrescriptionRefillList *generatePrescriptionList();
}

#endif
