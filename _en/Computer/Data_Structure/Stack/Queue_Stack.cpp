/* Queue_Stack.cpp
Author: BSS9395
Update: 2020-08-25T15:20:00+08@China-Guangdong-Zhanjiang+08
Design: Stack Implementation by Two Queue
Original: https://leetcode-cn.com/problems/implement-stack-using-queues/solution/yong-liang-ge-dui-lie-shi-xian-yi-ge-zhan-by-labyr/
*/

/* Queue Stack Model
                                   Stack Top = x_n              Stack Top = x_{n-1}
Queue1:  [x_0, x_1, ..., x_n]  =>  [x_n                   ]  => [x_0, x_1, ..., x_{n-2}]
Queue2:  [                  ]  =>  [x_0, x_1, ..., x_{n-1}]  => [x_{n-1}               ]
*/

#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Stack {
private:
    queue<T> _queue1;
    queue<T> _queue2;

public:
    Stack() {

    }

public:
    int size() {
        return (_queue1.size() + _queue2.size());
    }


    bool empty() {
        return (_queue1.empty() && _queue2.empty());
    }


    void push(T elem) {
        if (!_queue1.empty()) {
            _queue1.push(elem);
        }
        else {
            _queue2.push(elem);
        }
    }


    T pop() {
        T ret;
        if (!_queue1.empty()) {
            for (int size = _queue1.size(); 1 < size; size -= 1) {
                _queue2.push(_queue1.front());
                _queue1.pop();
            }
            ret = _queue1.front();
            _queue1.pop();
        }
        else if (!_queue2.empty()) {
            for (int size = _queue2.size(); 1 < size; size -= 1) {
                _queue1.push(_queue2.front());
                _queue2.pop();
            }
            ret = _queue2.front();
            _queue2.pop();
        }
        else {
            throw (const char *)("The stack is empty");
        }

        return ret;
    }


    T top() {
        T ret;
        if (!_queue1.empty()) {
            ret = _queue1.back();
        }
        else if (!_queue2.empty()) {
            ret = _queue2.back();
        }
        else {
            throw (const char *)("The stack is empty");
        }
        return ret;
    }

};


int main(int argc, char *argv[]) {
    Stack<int> stack = Stack<int>();
    stack.push(9);
    stack.push(0);
    stack.push(8);
    stack.push(2);
    stack.push(6);

    cout << "stack.top() = " << stack.top() << endl;
    cout << "stack.size() = " << stack.size() << endl;
    cout << "----------------------------------------" << endl;

    stack.pop();
    stack.pop();

    cout << "stack.top() = " << stack.top() << endl;
    cout << "stack.size() = " << stack.size() << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}