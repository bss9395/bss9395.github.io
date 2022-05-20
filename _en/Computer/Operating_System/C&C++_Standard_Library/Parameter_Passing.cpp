/* Parameter_Passing.cpp
Author: BSS9395
Update: 2022-05-15T23:16:00+08@China-Shanghai+08
Design: C++ Language Feature: Parameter Passing
*/

#include <iostream>

void Pass_By_Value(double lhs, double rhs) {
    double temp = lhs;   // swap nothing
    lhs = rhs;
    rhs = lhs;
}

void Pass_By_Pointer(double* lhs, double* rhs) {
    double temp = *lhs;  // swap values
    *lhs = *rhs;
    *rhs = temp;

    //double* tmp = lhs; // swap nothing but pointers
    //lhs = rhs;
    //rhs = tmp;
}

void Pass_By_Reference(double& lhs, double& rhs) {
    double temp = lhs;   // swap values
    lhs = rhs;
    rhs = temp;
}

void Test_Pass_By_Value() {
    double lhs = 2.0;
    double rhs = 3.0;
    Pass_By_Value(lhs, rhs);
    fprintf(stdout, "lhs = %lf, rhs = %lf", lhs, rhs);
}

void Test_Pass_By_Pointer() {
    double lhs = 2.0;
    double rhs = 3.0;
    Pass_By_Pointer(&lhs, &rhs);
    fprintf(stdout, "lhs = %lf, rhs = %lf", lhs, rhs);
}

void Test_Pass_By_Reference() {
    double lhs = 2.0;
    double rhs = 3.0;
    Pass_By_Reference(lhs, rhs);
    fprintf(stdout, "lhs = %lf, rhs = %lf", lhs, rhs);
}

int main(int argc, char* argv[]) {
    //Test_Pass_By_Value();
    //Test_Pass_By_Pointer();
    Test_Pass_By_Reference();
    return 0;
}
