/* foreach.cpp
Author: BSS9395
Update: 2021-10-11T22:24:00+08@China-Guangdong-Shenzhen+08
Design: C++ foreach Loop
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    vector<string> strs;
    strs.push_back("C");
    strs.push_back("C++");
    strs.push_back("C#");

    for (string str : strs) {
        str = "Do";           // Original value will not change.
        cout << str << endl;
    }

    cout << "========================================" << endl;
    for (string &str : strs) {
        cout << str << endl;
        str = "Do";          // Original value will change.
    }

    cout << "========================================" << endl;
    for (auto &str : strs) {
        cout << str << endl;
    }

    return 0;
}
