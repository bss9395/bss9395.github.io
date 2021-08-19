/* Winner_Tree.c
Author: BSS9395
Update: 2020-08-19T09:17:00+08@China-Guangdong-Zhanjiang+08
Design: Winner Tree
Original: https://www.cnblogs.com/qianye/archive/2012/11/25/2787923.html
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _M 5
#define _MAX 0xFFFF
int _Player[_M + 1];
int _Winner[_M + 1];

/* Heap
                   |    Preferred
                   ©¦  0:	  0
                   ©¦   	   \
0:	  0          ©¦  1:      1
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

void Compete(int head) {
    int left = 0, right = 0;

    left = (2 * head < _M)
        ? _Winner[2 * head]
        : 2 * head - (_M - 1);
    right = (2 * head + 1 < _M)
        ? _Winner[2 * head + 1]
        : 2 * head - (_M - 1) + 1;

    _Winner[head] = _Player[left] < _Player[right] ? left : right;
}

void Create_Winner_Tree() {
    freopen("data.txt", "r", stdin);
    for (int i = 1; i <= _M; i += 1) {
        fscanf(stdin, "%d", &_Player[i]);
    }
    for (int head = _M - 1; 0 < head; head -= 1) {
        // ajustment start from the last one
        Compete(head);
    }
}

void Adjust(int winner) {
    int head = (winner + _M - 1) / 2;
    while (0 < head) {
        Compete(head);
        head = head / 2;
    }
}

int main(int argc, char *argv[]) {
    Create_Winner_Tree();
    for (int i = 1; i <= _M; i += 1) {
        fprintf(stdout, "%d, ", _Player[_Winner[1]]);
        _Player[_Winner[1]] = _MAX;
        Adjust(_Winner[1]);
    }

    return 0;
}