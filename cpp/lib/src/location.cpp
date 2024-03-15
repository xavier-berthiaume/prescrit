#include "location.h"

WorkLocation::WorkLocation(const std::string& addressParam, 
	     const std::string& cityParam) : address_(addressParam),
					     city_(cityParam) {}

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

WorkLocation *LocationList::getNextLocation(WorkLocation( *currentParam)) {

	if(currentParam == nullptr || currentParam->getNext() == nullptr) {
		return nullptr;
	} else {
		return currentParam->getNext();
	}
}

WorkLocation *LocationList::getNextLocation() {

	return head;
}
