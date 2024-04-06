#include <prescrit/structs/patient-file.h>

PatientFile::~PatientFile() {

    if(patient_ != nullptr)
        delete patient_;

    if(insurances_.size() > 0)
        for(auto insurance : insurances_) {
            if(insurance != nullptr)
                delete insurance;
        }

    if(prescriptions_.size() > 0)
        for(auto prescription : prescriptions_) {
            if(prescription != nullptr)
                delete prescription;
        }
}

std::string PatientFile::getFileId() const {

    return fileid_;
}

Patient *PatientFile::getPatient() const {

    return patient_;
}

uint16_t PatientFile::getPrescriptionCount() const {

    return prescriptions_.size();
}

PrescriptionRefillList *PatientFile::getPrescriptionList(const uint16_t &indexParam) const {

    if(indexParam > prescriptions_.size() - 1)
        return nullptr;

    return prescriptions_[indexParam];
}

void PatientFile::setFileId(const std::string &idParam) {

   if(idParam.length() > MAXFILEIDLENGTH) 
       return;

   fileid_ = idParam;
}

void PatientFile::setPatient(Patient *patientParam) {

    if(patientParam == nullptr)
        return;

    patient_ = new Patient(patientParam);
}
