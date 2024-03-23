#include "patient-tf.h"
#include "products-tf.h"
#include "prescriber-tf.h"
#include "prescription-tf.h"

std::string testFramework::generateValidName() {

    std::vector<std::string> validNameList {
        "Xavier",
        "Florence",
        "Daniel",
        "Christine",
        "Florence"
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, validNameList.size() - 1);

    int randomIndex = distribution(generator);

    return validNameList[randomIndex];
}

std::string testFramework::generateInvalidName() {

    std::vector<std::string> invalidNameList {
        "Xav21123123ier",
        "12312312323",
        "asldkfjasdlkjflkdsafjlkdsajflkasjdflkasdjflaskdfjlkasjdflksafjdklasdjfasdlkfjalskdfjlsakjdflksadjflkasjdflkjasldkfasdflkj",
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, invalidNameList.size() - 1);

    int randomIndex = distribution(generator);

    return invalidNameList[randomIndex];
}

tm *testFramework::generateValidBirthday() {

    tm *validGeneratedBirthday;
    
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distrbution(0, 100);

    // This is certain to work for any month, since all months have at least 28 days
    validGeneratedBirthday->tm_mday = distrbution(generator)%28;

    validGeneratedBirthday->tm_mon = distrbution(generator)%12;

    validGeneratedBirthday->tm_year = distrbution(generator);

    return validGeneratedBirthday;
}

tm *testFramework::generateInvalidBirthday() {

    tm*invalidGeneratedBirthday;

    std::random_device rd;
    std::mt19937 generator(rd());
    // Distibution that will generate a random day of the month that could be in bounds,
    // or could be completely out of bounds
    std::uniform_int_distribution<int> distributionDay(0, 100);

    // Distribution that will generate a random month of the year that could be in
    // bounds, or could be completely out of bounds
    std::uniform_int_distribution<int> distributionMonth(0, 20);
    
    // Distribution that will generate a random year that is between 3000 and 4000
    std::uniform_int_distribution<int> distributionYear(0, 1000);
    invalidGeneratedBirthday->tm_mday = distributionDay(generator);
    invalidGeneratedBirthday->tm_mon = distributionMonth(generator);
    invalidGeneratedBirthday->tm_year = distributionYear(generator) + 1000; 

    return invalidGeneratedBirthday;
}

Patient *testFramework::generatePatient() {

    Patient *testPatient = new Patient();

    testPatient->setFirstName(generateValidName());
    testPatient->setLastName(generateValidName());
    testPatient->setBirthDate(generateValidBirthday());

    return testPatient;
}
