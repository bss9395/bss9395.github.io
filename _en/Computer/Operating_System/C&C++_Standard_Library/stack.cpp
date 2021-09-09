/* stack.cpp
Author: BSS9395
Update: 2021-09-09T08:42:00+08@China-Guangdong-Zhanjiang+08
Design: stack
*/

/*
#include <stack>

template <class T, class Container = deque<T> >
class stack;
*/

#include <iostream>
#include <stack>

using namespace std;

bool Check_Parenthese(string &str) {
    stack<char> stk;
    for (int i = 0; i < (int)str.length(); i += 1) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stk.push(str[i]);
        }
        else if (str[i] == ')') {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            }
            else {
                return false;
            }
        }
        else if (str[i] == ']') {
            if (!stk.empty() && stk.top() == '[') {
                stk.pop();
            }
            else {
                return false;
            }
        }
        else if (str[i] == '}') {
            if (!stk.empty() && stk.top() == '{') {
                stk.pop();
            }
            else {
                return false;
            }
        }
    }
    if (!stk.empty()) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    string str = "([)]";
    //string str = "()[]{}";
    bool ret = Check_Parenthese(str);
    cout << boolalpha << ret << endl;

    return 0;
}