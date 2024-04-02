#ifndef PATIENT_FILE_H
#define PATIENT_FILE_H

#include "patient.h"
#include "prescription-list.h"
#include "prescription.h"
#include "normal.h"
#include "magistral.h"

// Singleton implementation
class PatientFile {

    Patient *patient_;
    std::vector<PrescriptionRefillList *> prescriptions_;

    // I should store patient conditions here, but haven't implemented those yet

    PatientFile();
    ~PatientFile();
public:

    
};

#endif
