/* Cpp_unique_ptr.cpp
Author: BSS9395
Update: 2023-10-05T14:50:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: unique_ptr
*/

#include <iostream>
#include <memory>
using namespace std;

int main() {
    std::unique_ptr<int> p5(new int);
    *p5 = 10;
    int* p = p5.release();
    cout << *p << endl;
    if (p5) {
        cout << "p5 is not nullptr" << endl;
    }
    else {
        cout << "p5 is nullptr" << endl;
    }
    std::unique_ptr<int> p6;
    p6.reset(p);
    cout << *p6 << endl;;
    return 0;
}