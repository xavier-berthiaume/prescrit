#ifndef USER_H
#define USER_H

#include <string>

// Pure Virtual
class User {
protected:
    std::string firstName_ = {};
    std::string lastName_ = {};

    std::string username = {};
    std::string password = {};
    std::string pinCode = {};
public:
};

class Pharmacist : public User {

};

class Technician : public User {

};


#endif
