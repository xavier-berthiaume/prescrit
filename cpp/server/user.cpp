#include "user.h"

const std::string User::kFirstNameField_ = "first_name";
const std::string User::kLastNameField_ = "last_name";
const std::string User::kUserNameField_ = "user_name";
const std::string User::kPasswordField_ = "password";

User::User() : Storable(
        "user", 
        {
            {kIdField_, UINT32, &id_, true, true, true, true},
            {kFirstNameField_, STRING64, &firstName_, false, true},
            {kLastNameField_, STRING64, &lastName_, false, true},
            {kUserNameField_, STRING32, &username_, true, true},
            {kPasswordField_, STRING64, &password_}
        }) {

    firstName_ = {};
    lastName_ = {};
    username_ = {};
    password_ = {};
}

User::~User() {}
