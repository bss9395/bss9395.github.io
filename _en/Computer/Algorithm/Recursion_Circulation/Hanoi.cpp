/* Hanoi.cpp
Author: BSS9395
Update: 2022-06-24T15:46:00+08@China-Shanghai+08
Design: Hanoi problem 
*/

#include <iostream>
using namespace std;
typedef intptr_t iptr;

void Move(const string& from, const string& to) {
    static iptr count = 0;
    count += 1;
    fprintf(stdout, "[%td] %s --> %s\n", count, &from[0], &to[0]);
}

// move from A by B to C.
void Hanoi(iptr numb, const string &from, const string &by, const string &to) {
    if (numb == 1) {
        Move(from, to);
        return;
    }
    Hanoi(numb - 1, from, to, by);
    Move(from, to);
    Hanoi(numb - 1, by, from, to);
}

int main(int argc, char *argv[]) {
    Hanoi(3, "A", "B", "C");
}
