/* Palindrome_Number.c
Author: BSS9395
Update: 2021-09-01T09:05:00+08@China-Guangdong-Zhanjiang+08
Design: Check Palindrome Number
Original: https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Palindrome Number
case Even: 4334
     number == reversed
case Odd: 34543
     number == reversed / 10
*/
bool Palindrome_Number(int number) {
    if (number < 0 || (number % 10 == 0 && number != 0)) {
        return false;
    }

    int reversed = 0;
    while (number > reversed) {
        reversed = reversed * 10 + number % 10;
        number = number / 10;
    }

    return ((number == reversed) || number == reversed / 10);
}

int main(int argc, char *argv[]) {
    bool check = Palindrome_Number(34543);
    //bool check = Palindrome_Number(4334);
    fprintf(stdout, "%s""\n", (check ? "true" : "false"));

    return 0;
}

