#include "prescrit/testing/patient-tf.h"
#include <prescrit/structs/patient.h>

int main() {

    Patient *testPatient = testFramework::generatePatient();

	const auto currentTime = std::chrono::system_clock::now();
	std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    
    // Test time of a patient born an hour ago
    currentTime_t = currentTime_t - 60 * 60;
    const tm *born1HourAgo = std::localtime(&currentTime_t);
    testPatient->setBirthDate(born1HourAgo);
    testPatient->getAge();

    // Test time of a patient born a day ago
    currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    currentTime_t = currentTime_t - 60 * 60 * 24;
    const tm *born1DayAgo = std::localtime(&currentTime_t);
    testPatient->setBirthDate(born1DayAgo);
    testPatient->getAge();

    currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    currentTime_t = currentTime_t - 60 * 60 * 24 * 31;
    const tm *born1MonthAgo = std::localtime(&currentTime_t);
    testPatient->setBirthDate(born1MonthAgo);
    testPatient->getAge();

    currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    currentTime_t = currentTime_t - 60 * 60 * 24 * 365;
    const tm *born1YearAgo = std::localtime(&currentTime_t);
    testPatient->setBirthDate(born1YearAgo);
    testPatient->getAge();

    currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    currentTime_t = currentTime_t - 60 * 60 * 24 * 365 * 10;
    const tm *bornManyYearAgo = std::localtime(&currentTime_t);
    testPatient->setBirthDate(bornManyYearAgo);
    testPatient->getAge();

    delete testPatient;

    return 0;
}
