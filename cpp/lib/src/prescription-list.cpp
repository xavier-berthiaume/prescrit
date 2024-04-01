#include <prescrit/structs/prescription-list.h>

PrescriptionRefillList::PrescriptionRefillList() : head{nullptr} {}

PrescriptionRefillList::PrescriptionRefillList(PrescriptionRefillList *cpyObject) {
    
    if(cpyObject->getHead() != nullptr) {
        if(dynamic_cast<Normal *>(cpyObject->getHead())) {
            head = new Normal(dynamic_cast<Normal *>(cpyObject->getHead()));
        } else if(dynamic_cast<Magistral *>(cpyObject->getHead())) {
            head = new Magistral(dynamic_cast<Magistral *>(cpyObject->getHead()));
        } else {
            head = new Prescription(cpyObject->getHead());
        }
    } else {
        head = nullptr;
    }

	Prescription *currentPositionOriginal = cpyObject->getNextPrescription(cpyObject->getHead());
	Prescription *currentPositionNew = head;
	while(currentPositionOriginal != nullptr) {

        if(dynamic_cast<Normal *>(cpyObject->getHead())) {
		    currentPositionNew->setPreviousRefill(new Normal(dynamic_cast<Normal *>(currentPositionOriginal)));
        } else if(dynamic_cast<Magistral *>(cpyObject->getHead())) {
		    currentPositionNew->setPreviousRefill(new Magistral(dynamic_cast<Magistral *>(currentPositionOriginal)));
        } else {
		    currentPositionNew->setPreviousRefill(new Prescription(currentPositionOriginal));
        }

		currentPositionNew = currentPositionNew->getPreviousRefill();
		currentPositionOriginal = currentPositionOriginal->getPreviousRefill();
	}
}

PrescriptionRefillList::~PrescriptionRefillList() {

	while(head != nullptr) {

		Prescription *nextPrescription = head->getPreviousRefill();
		delete head;
		head = nextPrescription;
	}
}

Prescription *PrescriptionRefillList::getNextPrescription(Prescription *prescriptionParam) {

	return prescriptionParam->getPreviousRefill();
}

Prescription *PrescriptionRefillList::getHead() {

	return head;
}

void PrescriptionRefillList::setHead(Prescription *prescriptionParam) {

	head = new Prescription(prescriptionParam);
}

bool PrescriptionRefillList::refillPrescription(const unsigned int& quantityParam) {

	Prescription *recentRefill = new Prescription(head);
	if(recentRefill->getRemainingQuantity() < quantityParam)
		return false;
	recentRefill->setRefillQuantity(quantityParam);
	recentRefill->setRemainingQuantity(recentRefill->getRemainingQuantity() - quantityParam);

	recentRefill->setPreviousRefill(head);
	head = recentRefill;
	
	return true;
}
