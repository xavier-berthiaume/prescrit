#include <prescrit/utils/location.h> 

WorkLocation::WorkLocation(const std::string& addressParam, 
	     const std::string& cityParam) : address_(addressParam),
					     city_(cityParam) {}

WorkLocation::WorkLocation(WorkLocation *cpyObject) {

    address_ = cpyObject->address_;
    city_ = cpyObject->city_;
    zipCode_ = cpyObject->zipCode_;
    phoneNumber_ = cpyObject->phoneNumber_;
    faxNumber_ = cpyObject->faxNumber_;
}

std::string WorkLocation::getFormattedAddress() const {

	return address_ + ", " + city_ + ", " + zipCode_;
}

WorkLocation *WorkLocation::getNext() const {

	return next;
}

void WorkLocation::setNext(WorkLocation *nextParam) {

	next = nextParam;
}

LocationList::LocationList() : head(nullptr) {}

LocationList::LocationList(LocationList *cpyObject) {

    if(cpyObject->getHead() != nullptr) {
        head = new WorkLocation(cpyObject->getHead());
    } else {
        head = nullptr;
    }

    WorkLocation *currentPositionOriginal = cpyObject->getNextLocation(cpyObject->getHead());
    WorkLocation *currentPositionNew = head;
    while(currentPositionOriginal != nullptr) {

        currentPositionNew->setNext(new WorkLocation(currentPositionOriginal));
        currentPositionNew = currentPositionNew->getNext();
        currentPositionOriginal = currentPositionOriginal->getNext();
    }
}

LocationList::~LocationList() {

	while(head != nullptr) {
		WorkLocation *nextLocation = head->getNext();
		delete head;
		head = nextLocation;
	}
}

void LocationList::addLocation(const std::string& addressParam, const std::string& cityParam) {

	WorkLocation *newLocation = new WorkLocation(addressParam, cityParam);
	newLocation->setNext(head);
	head = newLocation;
}

WorkLocation *LocationList::getNextLocation(WorkLocation *currentParam) {

	if(currentParam == nullptr || currentParam->getNext() == nullptr) {
		return nullptr;
	} else {
		return currentParam->getNext();
	}
}

WorkLocation *LocationList::getHead() {

	return head;
}
