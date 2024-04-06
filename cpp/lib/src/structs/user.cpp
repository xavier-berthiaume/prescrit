#include <prescrit/structs/user.h>

std::string User::getFirstName() const {

    return firstName_;
}

std::string User::getLastName() const {

    return lastName_;
}

std::string User::getFullName() const {

    return firstName_ + " " + lastName_;
}

std::string User::getUsername() const {

    return username_;
}

void User::setFirstName(const std::string &nameParam) {

    if(nameParam.length() > MAXNAMELENGTH)
        return;

	for(char character : nameParam) {
		if(!std::isalpha(character))
			return;
	}

    firstName_ = nameParam;
}

void User::setLastName(const std::string &nameParam) {

    if(nameParam.length() > MAXNAMELENGTH)
        return;

	for(char character : nameParam) {
		if(!std::isalpha(character))
			return;
	}

    firstName_ = nameParam;
}

void User::setUsername(const std::string &usernameParam) {

    // Further implement validation once you figure out what kind
    // of structure the username should have
    username_ = usernameParam;
}

void User::setPassword(const std::string &passwordParam, bool isHashed = false) {

    if(isHashed)
        password_ = passwordParam; 

    // Hash the password, then set it
    std::string hashedPassword = {};

    password_ = hashedPassword;
}
