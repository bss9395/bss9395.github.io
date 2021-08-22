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
const int _Min = -65536;
const int _Max = +65535;
int _Loser[_M];
int _Player[_M + 1];

void Input(int i) {
    static bool once = true;
    static char buffer[1024];
    static FILE *data[_M + 1];
    if (once == true) {
        for (int i = 0; i < _M; i += 1) {
            sprintf(buffer, "data%d.txt", i);
            data[i + 1] = fopen(buffer, "rt");
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
    char buffer[1024];
    int data0[] = { 10, 15, 16, 65535 }; int size0 = sizeof(data0) / sizeof(*data0);
    int data1[] = { 9, 18, 20, 65535 }; int size1 = sizeof(data0) / sizeof(*data0);
    int data2[] = { 20, 22, 40, 65535 }; int size2 = sizeof(data0) / sizeof(*data0);
    int data3[] = { 6, 15, 25, 65535 }; int size3 = sizeof(data0) / sizeof(*data0);
    int data4[] = { 12, 37, 48, 65535 }; int size4 = sizeof(data0) / sizeof(*data0);
    int *data[] = { data0, data1, data2, data3, data4 };
    int size[] = { size0, size1, size2, size3, size4 };
    FILE *in = NULL;
    for (int i = 0; i < _M; i += 1) {
        sprintf(buffer, "data%d.txt", i);
        if (in == NULL) {
            in = fopen(buffer, "wt");
        }
        else {
            in = freopen(buffer, "wt", in);
        }
        for (int j = 0; j < size[i]; j += 1) {
            fprintf(in, "%d ", data[i][j]);
        }
    }
    fclose(in);

    ////////////////////////////////////

    Create_Loser_Tree();
    while (_Player[_Loser[0]] != _Max) {
        fprintf(stdout, "%d, ", _Player[_Loser[0]]);
        Input(_Loser[0]);
        Adjust(_Loser[0]);
    }

    return 0;
}