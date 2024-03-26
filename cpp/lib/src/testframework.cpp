#include <prescrit/test-fr.h>

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

    tm *validGeneratedBirthday = new tm;
    
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

    tm *invalidGeneratedBirthday = new tm;

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
    tm *generatedBirthday = generateValidBirthday();
    testPatient->setBirthDate(generatedBirthday);

    delete generatedBirthday;

    return testPatient;
}

std::string testFramework::generateValidCompany() {
    
    std::vector<std::string> validCompanyList = {
        "Pfizer",
        "Johnson & Johnson",
        "Novartis",
        "Roche",
        "Merck",
        "GlaxoSmithKline",
        "AbbVie",
        "Sanofi",
        "AstraZeneca",
        "Bayer",
        "Jamp",
        "Teva", 
        "Pro Doc",
        "Auro"
        // Add more company names as needed
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, validCompanyList.size() - 1);

    int randomIndex = distribution(generator);
    
    return validCompanyList[randomIndex];
}

std::string testFramework::generateValidProductName() {

    std::vector<std::string> validProductNames = {
        "Acetaminophen",
        "Ibuprofen",
        "Aspirin",
        "Lisinopril",
        "Metformin",
        "Atorvastatin",
        "Levothyroxine",
        "Simvastatin",
        "Losartan",
        "Amlodipine",
        // Add more medication names as needed
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, validProductNames.size() - 1);

    int randomIndex = distribution(generator);

    return validProductNames[randomIndex];
}

std::string testFramework::generateValidMagistralName() {

    std::vector<std::string> validProductNames = {
        "ASA 5% Cream",
        "Tadalafil 1% Cream",
        "Magic Mouth Wash",
        "Newmann Ointment"
        // Add more medication names as needed
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, validProductNames.size() - 1);

    int randomIndex = distribution(generator);

    return validProductNames[randomIndex];
}

unsigned int testFramework::generateValidDose() {

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 1000);

    return (unsigned int)distribution(generator);
}

std::string testFramework::generateValidDIN() {

    int length = 8;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 9); // Digits 0 to 9

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += std::to_string(distribution(gen));
    }
    return result;
}

units::DoseUnit testFramework::selectUnit() {

    std::vector<units::DoseUnit> unitsList = {
        units::DoseUnit::ug,
        units::DoseUnit::mg,
        units::DoseUnit::g,
        units::DoseUnit::uL,
        units::DoseUnit::mL,
        units::DoseUnit::L,
        units::DoseUnit::mgmL,
        units::DoseUnit::ui,
        units::DoseUnit::uimL
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, unitsList.size() - 1);

    int randomIndex = distribution(generator);
    
    return unitsList[randomIndex];
}

ValidPrescriptionTypes testFramework::selectAnnex() {

    std::vector<ValidPrescriptionTypes> annexList = {
        Annex1,
        Annex2,
        Annex3
    };

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, annexList.size() - 1);

    int randomIndex = distribution(generator);

    return annexList[randomIndex];
}

Ingredient *testFramework::generateIngredient() {

    Ingredient *generatedIngredient = new Ingredient(
            testFramework::generateValidProductName(),
            testFramework::generateValidDose(),
            testFramework::selectUnit());

    return generatedIngredient;
}

Product *testFramework::generateProduct() {

    Product *generatedProduct = new Product();

    generatedProduct->setName(generateValidProductName());
    
    return generatedProduct;
}

Premade *testFramework::generatePremade() {

    Premade *generatedPremade = new Premade();

    generatedPremade->setName(generateValidProductName());
    generatedPremade->setProducer(generateValidCompany());

    return generatedPremade;
}

Medication *testFramework::generateMedication() {

    Medication *generatedMedication = new Medication();

    generatedMedication->setName(generateValidProductName());
    generatedMedication->setProducer(generateValidCompany());
    generatedMedication->setDIN(generateValidDIN());
    generatedMedication->setAnnex(selectAnnex());

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 5);

    int randomIndex = distribution(generator);

    for (int x = 0; x < randomIndex; x++) {
        generatedMedication->AddIngredient(
            testFramework::generateValidProductName(),
            testFramework::generateValidDose(),
            testFramework::selectUnit());
    }

    return generatedMedication;
}

Magistral *testFramework::generateMagistral() {
    
    Product *generatedProduct = new Product();
    generatedProduct->setName(generateValidProductName());

    Magistral *generatedMagistral = new Magistral();
    generatedMagistral->setOriginalProduct(generatedProduct);

    return generatedMagistral;
}

std::string testFramework::generateValidLicense() {

    int length = 5;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 9); // Digits 0 to 9

    std::string result = "1";
    for (int i = 0; i < length; ++i) {
        result += std::to_string(distribution(gen));
    }
    return result;
}

std::string testFramework::generateInvalidLicense() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 9); // Digits 0 to 9

    int length = distribution(gen);
    // Lazy check to make sure that we don't accidentally generate a valid license number
    if(length == 6)
        length++;
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += std::to_string(distribution(gen));
    }
    return result;
}

std::string testFramework::generateAddress() {

    std::vector<std::string> addressList = {
        "123 big street",
        "792 new street",
        "1 grand boulevard",
        "10 mountain drive",
        "30 goat avenue"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, addressList.size() - 1); // Digits 0 to 9

    int randomIndex = distribution(gen);
    return addressList[randomIndex];
}

std::string testFramework::generateCity() {

    std::vector<std::string> cityList = {
        "Paris",
        "London",
        "Milan",
        "Montreal",
        "Ottawa",
        "Toronto"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, cityList.size() - 1); // Digits 0 to 9

    int randomIndex = distribution(gen);
    return cityList[randomIndex];
}

std::string testFramework::generateZipCode() {
    
    std::string postalCode;

    // Random number generator for selecting letters
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25); // for letters A-Z

    // Random number generator for selecting numbers
    std::uniform_int_distribution<> dis_num(0, 9); // for digits 0-9

    // First letter (A-Z)
    char firstLetter = 'A' + dis(gen);
    postalCode.push_back(firstLetter);

    // Second character (numeric)
    postalCode.push_back('0' + dis_num(gen));

    // Third letter (A-Z), excluding 'D', 'F', 'I', 'O', 'Q', 'U', 'W', 'Z'
    char thirdLetter;
    do {
        thirdLetter = 'A' + dis(gen);
    } while (thirdLetter == 'D' || thirdLetter == 'F' || thirdLetter == 'I' || 
             thirdLetter == 'O' || thirdLetter == 'Q' || thirdLetter == 'U' || 
             thirdLetter == 'W' || thirdLetter == 'Z');
    postalCode.push_back(thirdLetter);

    // Space
    postalCode.push_back(' ');

    // Fourth number (0-9)
    postalCode.push_back('0' + dis_num(gen));

    // Fifth letter (A-Z)
    char fifthLetter = 'A' + dis(gen);
    postalCode.push_back(fifthLetter);

    // Sixth number (0-9)
    postalCode.push_back('0' + dis_num(gen));

    return postalCode;
}

WorkLocation *testFramework::generateWorkLocation() {

    WorkLocation *generatedLocation;

    generatedLocation->address_ = generateAddress();
    generatedLocation->city_ = generateCity();
    generatedLocation->zipCode_ = generateZipCode();

    // Next generate a phone number and fax number
    // once you've implemented phone number generation

    return generatedLocation;
}

Prescriber *testFramework::generatePrescriber() {

    Prescriber *generatedPrescriber = new Prescriber();

    generatedPrescriber->setFirstName(generateValidName());
    generatedPrescriber->setLastName(generateValidName());
    generatedPrescriber->setLicense(generateValidLicense());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 3);

    int randomIndex = distribution(gen);
    
    for(int x = 0; x < randomIndex; x++) {
        generatedPrescriber->addLocation(generateAddress(), generateCity(), generateZipCode());
    }

    return generatedPrescriber;
}
