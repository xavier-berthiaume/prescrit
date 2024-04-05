#include <prescrit/utils.h>

int main() {

    tm testTime = tm();

    if(!time_validation::checkDateBeforePresent(&testTime))
        return 1;

    return 0;
}
