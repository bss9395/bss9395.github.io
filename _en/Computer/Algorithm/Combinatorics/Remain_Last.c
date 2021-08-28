/* Remain_Last.c
Author: BSS9395
Update: 2020-08-28T19:56:00+08@China-Guangdong-Zhanjiang+08
Design: Remain Last of Joseph Ring
Original: https://blog.csdn.net/u011500062/article/details/72855826
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Joseph Ring Model
numb=11, dele=3, last=6                               |
index  :  00  01 [02] 03  04  05  06  07  08  09  10  |
round00:  00  01 [02] 03  04  05  06  07  08  09  10  |
round01:  00  01  03  04 [05] 06  07  08  09  10      |
round02:  00  01  03  04  06  07 [08] 09  10          |
round03: [00] 01  03  04  06  07  09  10              |
round04:  01  03 [04] 06  07  09  10                  |
round05:  01  03  06  07 [09] 10                      |
round06:  01 [03] 06  07  10                          |
round07:  01  06  07 [10]                             |
round08:  01  06 [07]                                 |
round09: [01] 06                                      |
round10: [06]                                         |
--------------------------------------------------------------------------------
index  :  00  01 [02] 03  04  05  06  07  08  09  10  |  f(n) = (f(n-1) + dele) % n
shift00:  00  01 [02] 03  04  05  06  07  08  09  10  |  6 = (3 + 3) % 11
shift01:  03  04 [05] 06  07  08  09  10  00  01      |  3 = (0 + 3) % 10
shift02:  06  07 [08] 09  10  00  01  03  04          |  0 = (6 + 3) % 9
shift03:  09  10 [00] 01  03  04  06  07              |  6 = (3 + 3) % 8
shift04:  01  03 [04] 06  07  09  10                  |  3 = (0 + 3) % 7
shift05:  06  07 [09] 10  01  03                      |  0 = (3 + 3) % 6
shift06:  10  01 [03] 06  07                          |  3 = (0 + 3) % 5
shift07:  06  07 [10] 01                              |  0 = (1 + 3) % 4
shift08:  01  06 [07]                                 |  1 = (1 + 3) % 3
shift09:  01  06|[01] 06                              |  1 = (0 + 3) % 2
shift10:  06| 06 [06]                                 |  0 = (0 + 3) % 1
*/

int Remain_Last(int numb, int dele) {
    int last = 0;
    for (int i = 1; i <= numb; i += 1) {
        last = (last + dele) % i;
    }
    return last;
}

int Remain_Last_Recursion(int numb, int dele) {
    if (numb == 1) {
        return 0;
    }
    return (Remain_Last_Recursion(numb - 1, dele) + dele) % numb;
}


int main(int argc, char *argv[]) {
    int numb = 11;
    int dele = 3;
    int last = Remain_Last(numb, dele);
    // int last = Remain_Last_Recursion(numb, dele);
    fprintf(stdout, "%d""\n", last);

    return 0;
}
