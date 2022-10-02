/* Prime_Factorization.cpp
Author: BSS9395
Update: 2022-09-29T17:52:00+08@China-Guangdong-Zhanjiang
Design: Prime_Factorization.cpp
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Prime_Factorization(long numb) {
    for (long factor = 2; factor * factor <= numb; ) {
        if (numb % factor == 0) {
            fprintf(stdout, "%d ", factor);
            numb /= factor;
        }
        else {
            factor += 1;
        }
    }
    fprintf(stdout, "%d ", numb);
}

int main(int argc, char* argv[]) {
    Prime_Factorization(180);

    return 0;
}
