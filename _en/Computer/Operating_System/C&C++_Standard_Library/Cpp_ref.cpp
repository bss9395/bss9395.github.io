/* Cpp_ref.cpp
Author: BSS9395
Update: 2023-10-05T09:36:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: ref
*/

#include <iostream>
#include <functional>
#include<vector>
using namespace std;

void f(int& a, int& b) {
    fprintf(stdout, "in function: a = %d, b = %d, &a = %p, &b = %p\n", a, b, &a, &b);
    a += 1;
    b += 10;
}

int main() {
    int n1 = 1, n2 = 10;
    int& r1 = n1;

    function<void()> f1 = bind(f, r1, ref(n2));
   
    f1();
    fprintf(stdout, "out function: n1 = %d, n2 = %d, &n1 = %p, &n2 = %p\n", n1, n2, &n1, &n2);
    f1();
    fprintf(stdout, "out function: n1 = %d, n2 = %d, &n1 = %p, &n2 = %p\n", n1, n2, &n1, &n2);
    return 0;
}
