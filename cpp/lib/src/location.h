#ifndef LOCATION_H
#define LOCATION_H

#include <string>

#include "phonenumbers.h"

struct WorkLocation {
	WorkLocation(const std::string&, const std::string&);
    WorkLocation(WorkLocation *);
	std::string address_;
	std::string city_;
	std::string zipCode_;

	std::string phoneNumber_;
	std::string faxNumber_;
	
	std::string getFormattedAddress() const;

    std::string getAddress() const;
    std::string getCity() const;
    std::string getZipCode() const;
    
    std::string getPhone() const;
    std::string getFax() const;
	
	WorkLocation *getNext() const;
	void setNext(WorkLocation *);

private:
	WorkLocation *next;
	
};

struct LocationList {
	LocationList();
    LocationList(LocationList *);
	~LocationList();

	void addLocation(const std::string&, const std::string&);
	WorkLocation *getNextLocation(WorkLocation *);
    WorkLocation *getHead();

private:
	WorkLocation *head;

};

#endif // !LOCATION_H
