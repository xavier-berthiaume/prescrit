#ifndef USER_H
#define USER_H

#include <string>

#include "../globals.h"

// Pure Virtual
class User {
protected:

    std::string firstName_ = {};
    std::string lastName_ = {};

    std::string username_ = {};
    std::string password_ = {};
    std::string pinCode_ = {};
public:

    // Pure virtual destructor to prevent instantiating user objects
    virtual ~User() = 0;

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    std::string getUsername() const;

    void setFirstName(const std::string &);
    void setLastName(const std::string &);
    void setUsername(const std::string &);
    void setPassword(const std::string &, bool);
    void setPinCode(const std::string &);
};

class Pharmacist : public User {
    
    std::string license_;
public:
    
    std::string getLicense() const;

    void setLicense(const std::string &);
};

class Technician : public User {
    // Leave this empty for now, later attach a
    // permission system to technicians
};


#endif
