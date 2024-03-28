#include <iostream>

#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    tm *refillDate, *originalDate, *expiryDate;
    std::tie(refillDate, originalDate, expiryDate) = testFramework::generatePrescriptionDates();
    std::cout << "Generated Dates: \n"
        "\tRefill Date: \n"
        "\t\tYear: " << refillDate->tm_year+1900 << "\n"
        "\t\tMonth: " << refillDate->tm_mon+1 << "\n"
        "\t\tDay: " << refillDate->tm_mday << "\n"
        "\tOriginal Date: \n"
        "\t\tYear: " << originalDate->tm_year+1900 << "\n"
        "\t\tMonth: " << originalDate->tm_mon+1 << "\n"
        "\t\tDay: " << originalDate->tm_mday << "\n"
        "\tExpiry Date: \n"
        "\t\tYear: " << expiryDate->tm_year+1900 << "\n"
        "\t\tMonth: " << expiryDate->tm_mon+1 << "\n"
        "\t\tDay: " << expiryDate->tm_mday << "\n";
    std::cout << std::endl;
    delete refillDate;
    delete originalDate;
    delete expiryDate;

    return 0;
}
