// Things to test:
// 1. Create a prescriber object
// 2. Provide valid data for all fields
// 3. Provide invalid data for all fields, 
// assert that the valid data shouldn't be
// overwritten.

#include <cassert>
#include <prescrit/structs.h>

int main(int argc, char *argv[]) {

    Prescriber testPrescriber = Prescriber();
    testPrescriber.setFirstName(argv[1]);
    testPrescriber.setLastName(argv[2]);
    testPrescriber.setLicense(argv[3]);

    assert((testPrescriber.getFirstName() == argv[1]));
    assert((testPrescriber.getLastName() == argv[2]));
    assert((testPrescriber.getLicense() == argv[3]));

    testPrescriber.setFirstName("123123123");
    testPrescriber.setLastName("2342342342342");
    testPrescriber.setLicense("1");

    assert((testPrescriber.getFirstName() == argv[1]));
    assert((testPrescriber.getLastName() == argv[2]));
    assert((testPrescriber.getLicense() == argv[3]));
    
    testPrescriber.setLicense("1123131231231232131");
    assert((testPrescriber.getLicense() == argv[3]));

    return 0;
}
