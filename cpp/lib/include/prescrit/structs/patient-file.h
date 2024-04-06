#ifndef PATIENT_FILE_H
#define PATIENT_FILE_H

#include "insurance.h"
#include "patient.h"
#include "prescription-list.h"
#include "../globals.h"

class PatientFile {
friend class PatientFileFactory;

    std::string fileid_ = {};
    Patient *patient_ = nullptr;
    std::vector<Insurance *> insurances_ {};
    std::vector<PrescriptionRefillList *> prescriptions_ {};

    // I should store patient conditions here, but haven't implemented those yet
public:

    PatientFile() = default;
    ~PatientFile();

    std::string getFileId() const;
    Patient *getPatient() const;
    uint16_t getPrescriptionCount() const;
    PrescriptionRefillList *getPrescriptionList(const uint16_t &) const;

    void setFileId(const std::string &);
    void setPatient(Patient *);
    void addPrescriptionList(PrescriptionRefillList *);
    void removePrescriptionList(const uint16_t &);
};

#endif
