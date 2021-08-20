/* Multi_Merge.c
Author: BSS9395
Update: 2020-08-19T12:31:00+08@China-Guangdong-Zhanjiang+08
Design: External File Data Sorting
Original: http://c.biancheng.net/view/3453.html
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Heap
                   |    Preferred
                   ©¦  0:	0
                   ©¦   	     \
0:	    0          ©¦  1:      1
       / \         ©¦         / \
1:    1   2        ©¦  2:    2   3
     / \ / \       ©¦       / \  / \
2:  3  4 5  6      ©¦  3:  4[1/10][2/9][3/20]
                   |     / \
                   |    [4/6][5/12]
H[i] ¡Ü H[2¡¤i+1]    ©¦  H[i] ¡Ü H[2¡¤i+0]
H[i] ¡Ü H[2¡¤i+2]    ©¦  H[i] ¡Ü H[2¡¤i+1]
H[(i-1)/2] ¡Ü H[i]  ©¦  H[i/2] ¡Ü H[i]
                   |  Internal Nodes Count = _M - 1
                   |  Leaves   Nodes Count = _M
*/

#define _M 5
static int _Min = -65536;
static int _Max = +65535;
static int _Loser[_M];
static int _Player[_M + 1];

void Input(int i) {
    static bool once = true;
    static char buffer[1024];
    static FILE *data[_M + 1];
    if (once == true) {
        for (int i = 1; i <= _M; i += 1) {
            sprintf(buffer, "data%d.txt", i);
            data[i] = fopen(buffer, "r");
        }
        once = false;
    }
    fscanf(data[i], "%d", &_Player[i]);
}

void Adjust(int winner) {
    int head = (winner + _M - 1) / 2;
    while (0 < head) {
        if (_Player[_Loser[head]] < _Player[winner]) {
            int swap = _Loser[head];
            _Loser[head] = winner;
            winner = swap;
        }
        head = head / 2;
    }
    _Loser[0] = winner;
}

void Create_Loser_Tree() {
    _Player[0] = _Min;
    for (int i = 0; i <= _M; i += 1) {
        _Loser[i] = 0;
    }
    for (int i = 1; i <= _M; i += 1) {
        Input(i);
    }
    for (int i = _M; 0 < i; i -= 1) {
        // ajustment start from the last leaves node.
        Adjust(i);
    }
}


int main(int argc, char *argv[]) {
    Create_Loser_Tree();
    while (_Player[_Loser[0]] != _Max) {
        fprintf(stdout, "%d, ", _Player[_Loser[0]]);
        Input(_Loser[0]);
        Adjust(_Loser[0]);
    }

    return 0;
}