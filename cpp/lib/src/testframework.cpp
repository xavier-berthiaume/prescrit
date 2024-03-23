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
