#ifndef PATIENT_FILE_H
#define PATIENT_FILE_H

#include "patient.h"
#include "prescription-list.h"

class PatientFile {
friend class PatientFileFactory;

    std::string fileid_ = {};
    Patient *patient_ = nullptr;
    std::vector<PrescriptionRefillList *> prescriptions_ {};

    // I should store patient conditions here, but haven't implemented those yet

    PatientFile();
    ~PatientFile();
public:

    Patient *getPatient() const;
    uint16_t getPrescriptionCount() const;
    PrescriptionRefillList *getPrescription(const uint16_t &) const ;
    
};

class PatientFileFactory {

};

#endif
