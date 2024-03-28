// Things to test:
// 1. Create an insurance object
// 2. Provide valid data for all
// fields
// 3. Provide invalid data for all
// fields, and they should remain
// unchanged

#include <cassert>
#include <prescrit/structs.h>

int main(int argc, char *argv[]) {

    Insurance testInsurance = Insurance();
    testInsurance.setCarrier(argv[1]);
    testInsurance.setGroup(argv[2]);
    testInsurance.setPolicy(argv[3]);
    testInsurance.setBeneficiary(Beneficiary::Insured);

    assert((testInsurance.getCarrier() == argv[1]));
    assert((testInsurance.getGroup() == argv[2]));
    assert((testInsurance.getPolicy() == argv[3]));

    return 0;
}
