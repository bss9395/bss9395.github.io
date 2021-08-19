/* Loser_Tree.c
Author: BSS9395
Update: 2020-08-19T11:14:00+08@China-Guangdong-Zhanjiang+08
Design: Loser Tree
Original: https://www.cnblogs.com/qianye/archive/2012/11/25/2787923.html
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Heap
                   |    Preferred
                   ©¦  0:	0
                   ©¦   	     \
0:	    0          ©¦  1:      1
       / \         ©¦         / \
1:    1   2        ©¦  2:    2   3
     / \ / \       ©¦       / \  / \
2:  3  4 5  6      ©¦  3:  4[1:9][2:0][3:8]
                   |     / \
                   |    [4:2][5:6]
H[i] ¡Ü H[2¡¤i+1]    ©¦  H[i] ¡Ü H[2¡¤i+0]
H[i] ¡Ü H[2¡¤i+2]    ©¦  H[i] ¡Ü H[2¡¤i+1]
H[(i-1)/2] ¡Ü H[i]  ©¦  H[i/2] ¡Ü H[i]
                   |  Internal Nodes Count = _M - 1
                   |  Leaves   Nodes Count = _M
*/

#define _M 5
#define _MIN -65536
#define _MAX +65535
int _Loser[_M + 1];
int _Player[_M + 1];

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
    freopen("data.txt", "r", stdin);
    for (int i = 1; i <= _M; i += 1) {
        fscanf(stdin, "%d", &_Player[i]);
    }
    _Player[0] = _MIN;
    for (int i = 0; i <= _M; i += 1) {
        _Loser[i] = 0;
    }
    for (int i = _M; 0 < i; i -= 1) {
        Adjust(i);
    }
}

int main(int argc, char *argv[]) {
    Create_Loser_Tree();
    for (int i = 1; i <= _M; i += 1) {
        fprintf(stdout, "%d, ", _Player[_Loser[0]]);
        _Player[_Loser[0]] = _MAX;
        Adjust(_Loser[0]);
    }

    return 0;
}