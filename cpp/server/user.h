#ifndef USER_H
#define USER_H

#include  "storable.h"

struct User final : public Storable {
    
    static const std::string kFirstNameField_;
    std::string firstName_;

    static const std::string kLastNameField_;
    std::string lastName_;

    static const std::string kUserNameField_;
    std::string username_;

    static const std::string kPasswordField_;
    std::string password_;

    User();
    ~User();
};

#endif
