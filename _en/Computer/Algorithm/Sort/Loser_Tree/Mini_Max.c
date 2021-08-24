/* Mini_Max.c
Author: BSS9395
Update: 2020-08-20T17:44:00+08@China-Guangdong-Zhanjiang+08
Design: External File Data Segmentation
Original: http://data.biancheng.net/view/78.html
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

/* Heap
                   |    Preferred
                   ©¦  0:	0
                   ©¦   	     \
0:	    0          ©¦  1:      1
       / \         ©¦         / \
1:    1   2        ©¦  2:    2   3
     / \ / \       ©¦       / \ / \
2:  3  4 5  6      ©¦  3:  4[1][2][3]
                   |     / \
                   |    [4][5]
H[i] ¡Ü H[2¡¤i+1]    ©¦  H[i] ¡Ü H[2¡¤i+0]
H[i] ¡Ü H[2¡¤i+2]    ©¦  H[i] ¡Ü H[2¡¤i+1]
H[(i-1)/2] ¡Ü H[i]  ©¦  H[i/2] ¡Ü H[i]
                   |  Internal Nodes Count = _M - 1
                   |  Leaves   Nodes Count = _M
*/

/* Snowplow Model
     |||||||||
================= Snow Evenly
S>   |\           H ¡¤ L = 2 ¡¤ M
n>   ||\
o>   |||\             H represents the average High of snowplow.
w>   ||||\            L represents the average Length of each round.
p> H |||||\       H ¡¤ L represents the average data volumn of each round.
l>   ||||||\          M represents the average tree volumn.
o>   ||M||||\
w>   ||||||||\
         L
=================
*/

#define _M 5
const int _Min = -65536;
const int _Max = +65535;

int _Loser[_M];
struct {
    int _key;
    int _round;
} _Player[_M + 1];
FILE *input = NULL;
FILE *output = NULL;

void Mini_Max(int winner) {
    int swap = 0;
    int head = (winner + _M - 1) / 2;
    while (0 < head) {
        //if (_Player[_Loser[head]]._round < _Player[winner]._round
        //    || _Player[_Loser[head]]._key < _Player[winner]._key) {
        if (_Player[_Loser[head]]._round < _Player[winner]._round
            || _Player[_Loser[head]]._round == _Player[winner]._round && _Player[_Loser[head]]._key < _Player[winner]._key) {
            swap = _Loser[head]; _Loser[head] = winner; winner = swap;
        }
        head = head / 2;
    }
    _Loser[0] = winner;
}

void Create_Loser_Tree() {
    input = fopen("data", "rb");
    _Player[0]._key = _Min;
    for (int i = 0; i <= _M; i += 1) {
        _Loser[i] = 0;
    }
    for (int i = 1; i <= _M; i += 1) {
        fread(&_Player[i]._key, sizeof(int), 1, input);
        _Player[i]._round = 0;
    }
    for (int i = _M; 0 < i; i -= 1) {
        Mini_Max(i);
    }
}

void Segment() {
    char buffer[1024] = { "section" };
    int round = 0;
    int minimax = 0;
    int ret = 1;
    // while (_Player[_Loser[0]]._round <= round) {
    while (_Player[_Loser[0]]._key != _Max) {
        sprintf(buffer, "section%d", round);
        output = (output == NULL) ? fopen(buffer, "wb") : freopen(buffer, "wb", output);

        while (_Player[_Loser[0]]._round == round) {
            fwrite(&_Player[_Loser[0]]._key, sizeof(int), 1, output);
            minimax = _Player[_Loser[0]]._key;

            ret = fread(&_Player[_Loser[0]]._key, sizeof(int), 1, input);
            if (ret == 1) {
                if (_Player[_Loser[0]]._key < minimax) {
                    // if new record less than minimax, then it belongs to next round.
                    _Player[_Loser[0]]._round = round + 1;
                }
            }
            else {
                // if no new record.
                _Player[_Loser[0]]._key = _Max;
                _Player[_Loser[0]]._round = _Max;        // gap round for ending test.
            }
            Mini_Max(_Loser[0]);
        }
        fwrite(&_Max, sizeof(int), 1, output);
        round += 1;
    }
}

int main(int argc, char *argv[]) {
    //int data[] = {
    //     9, 0, 8, 2, 6, 1, 3, 4, 5, 7
    //};
    int data[] = {
        51, 49, 39, 46, 38, 29, 14, 61, 15, 30, 1, 48, 52, 3, 63, 27, 4, 13, 89, 24, 46, 58, 33, 76
    };
    FILE *in = fopen("data", "wb");
    fwrite(data, sizeof(int), sizeof(data) / sizeof(*data), in);
    fclose(in);

    ////////////////////////////////////

    Create_Loser_Tree();
    Segment();
    fclose(input);
    fclose(output);

    ////////////////////////////////////

    FILE *out = fopen("section0", "rb");
    int ret = 0;
    int key = 0;
    while (true) {
        ret = fread(&key, sizeof(int), 1, out);
        if (ret == 1) {
            (key == _Max)
                ? fprintf(stdout, "\n")
                : fprintf(stdout, "%d, ", key);
            continue;
        }
        break;
    }
    fclose(out);
    return 0;
}