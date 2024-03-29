#include <prescrit/structs.h>
#include <prescrit/test-fr.h>

int main(int argc, char *argv[]) {

    Normal *generatedNormal = testFramework::generateNormal();

    Normal *copyNormal = new Normal(generatedNormal);
    
    delete generatedNormal;
    delete copyNormal;

    return 0;
}
