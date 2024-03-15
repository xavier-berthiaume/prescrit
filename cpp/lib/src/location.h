#ifndef LOCATION_H
#define LOCATION_H

#include <string>

#include "phonenumbers.h"

struct WorkLocation {
	WorkLocation(const std::string&, const std::string&);
	std::string address_;
	std::string city_;
	std::string zipCode_;

	std::string phoneNumber_;
	std::string faxNumber_;
	
	std::string getFormattedAddress() const;
	
	WorkLocation *getNext() const;
	void setNext(WorkLocation *);

private:
	WorkLocation *next;
	
};

struct LocationList {
	LocationList();
	~LocationList();

	void addLocation(const std::string&, const std::string&);
	WorkLocation *getNextLocation(WorkLocation *);
	WorkLocation *getNextLocation();

private:
	WorkLocation *head;

};

#endif // !LOCATION_H
