/* Limits.c
Author: BSS9395
Update: 2021-09-27T15:23:00+08@China-Guangdong-Shenzhen+08
Design: C/C++ type Limits
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/*
C/C++ type int: 32bits
                      0x87654321
Iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
-2^{32-1}  to  +2^{32-1}-1

////////////////////////////////////////

C/C++ type long: 64bits
Iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
-2^{64-1}  to  +2^{64-1}-1
*/
void Limits_Fixed() {
    int int_min; *(unsigned int *)&int_min = 0x80000000;
    int int_max; *(unsigned int *)&int_max = 0x7FFFFFFF;
    fprintf(stdout, "int_min = %+i, %+E""\n", int_max, (double)int_max);
    fprintf(stdout, "int_min = %+i, %+E""\n", int_min, (double)int_min);
    fprintf(stdout, "--------------------------------------------------------------------------------""\n");

    ////////////////////////////////////

    fprintf(stdout, "abs(int_max) = %+i""\n", abs(int_max));
    fprintf(stdout, "abs(int_min) = %+i""\n", abs(int_min));
    fprintf(stdout, "--------------------------------------------------------------------------------""\n");
}

/* IEEE
C/C++ type float: 32bits
                      0x87654321
¡Àeeeeeeeefffffffffffffffffffffff
1       8                     23
Bias=2^{8-1}-1=127    Exponent-Bias=[1~254]-127=[-126~+127]
(-1)^{Sign} ¡Á 2^{Exponent-Bias} ¡Á (1.Fraction)

////////////////////////////////////////

C/C++ type double: 64bits
                                                      0x87654321
¡Àeeeeeeeeeeeffffffffffffffffffffffffffffffffffffffffffffffffffff
1         11                                                  52
Bias=2^{11-1}-1=1023  Exponent-Bias=(1~2046)-1023=(-1022~+1023)
(-1)^{Sign} ¡Á 2^{Exponent-Bias} ¡Á (1.Fraction)
*/
void Limits_Floating() {
    float f0 = (float)000.12345678901234567890;
    float f1 = (float)123.45678901231234567890;
    float f2 = (float)123456.78901231234567890;
    float f3 = (float)123456789.01231234567890;
    fprintf(stdout, "f0 = %.10f, f1 = %.10f, f2 = %.10f, f3 = %.10f""\n", f0, f1, f2, f3);
    fprintf(stdout, "--------------------------------------------------------------------------------""\n");

    ////////////////////////////////////

    float float_nan_plus; *(unsigned int *)&float_nan_plus = 0x7FFFFFFF;
    float float_nan_minus; *(unsigned int *)&float_nan_minus = 0xFFFFFFFF;
    float float_inf_plus; *(unsigned int *)&float_inf_plus = 0x7F800000;
    float float_inf_minus; *(unsigned int *)&float_inf_minus = 0xFF800000;
    float float_max; *(unsigned int *)&float_max = 0x7F7FFFFF;
    float float_min; *(unsigned int *)&float_min = 0x00800000;
    float float_max_epsilon; *(unsigned int *)&float_max_epsilon = 0x007FFFFF;
    float float_min_epsilon; *(unsigned int *)&float_min_epsilon = 0x00000001;
    float float_zero_plus; *(unsigned int *)&float_zero_plus = 0x00000000;
    float float_zero_minus; *(unsigned int *)&float_zero_minus = 0x80000000;
    fprintf(stdout, "float_nan_plus = %+f, %+E, %0#10X""\n", float_nan_plus, float_nan_plus, *(unsigned int *)&float_nan_plus);
    fprintf(stdout, "float_nan_minus = %+f, %+E, %0#10X""\n", float_nan_minus, float_nan_minus, *(unsigned int *)&float_nan_minus);
    fprintf(stdout, "float_inf_plus = %+f, %+E, %0#10X""\n", float_inf_plus, float_inf_plus, *(unsigned int *)&float_inf_plus);
    fprintf(stdout, "float_inf_minus = %+f, %+E, %0#10X""\n", float_inf_minus, float_inf_minus, *(unsigned int *)&float_inf_minus);
    fprintf(stdout, "float_max = %+f, %+E, %0#10X""\n", float_max, float_max, *(unsigned int *)&float_max);
    fprintf(stdout, "float_min = %+f, %+E, %0#10X""\n", float_min, float_min, *(unsigned int *)&float_min);
    fprintf(stdout, "float_max_epsilon = %+f, %+E, %0#10X""\n", float_max_epsilon, float_max_epsilon, *(unsigned int *)&float_max_epsilon);
    fprintf(stdout, "float_min_epsilon = %+f, %+E, %0#10X""\n", float_min_epsilon, float_min_epsilon, *(unsigned int *)&float_min_epsilon);
    fprintf(stdout, "float_zero_plus = %+f, %+E, %0#10X""\n", float_zero_plus, float_zero_plus, *(unsigned int *)&float_zero_plus);
    fprintf(stdout, "float_zero_minus = %+f, %+E, %0#10X""\n", float_zero_minus, float_zero_minus, *(unsigned int *)&float_zero_minus);
    fprintf(stdout, "--------------------------------------------------------------------------------""\n");
}


int main(int argc, char *argv[]) {
    Limits_Fixed();
    Limits_Floating();

    return 0;
}
