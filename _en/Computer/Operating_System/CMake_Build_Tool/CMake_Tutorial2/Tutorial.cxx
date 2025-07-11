
#include <cmath>
#include <iostream>
#include <string>
#include "TutorialConfig.h"
#include "MathFunctions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stdout, "[%s] Version: %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double inputValue = std::stod(argv[1]);
    double outputValue = mathfunctions::sqrt(inputValue);
    fprintf(stdout, "The square root of %lf is %lf\n", inputValue, outputValue);
    return 0;
}
