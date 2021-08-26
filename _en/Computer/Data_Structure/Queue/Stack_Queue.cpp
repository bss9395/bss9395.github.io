/* Stack_Queue.cpp
Author: BSS9395
Update: 2020-08-25T11:10:00+08@China-Guangdong-Zhanjiang+08
Design: Queue Implementation by Two Stack
Original: https://blog.csdn.net/ailunlee/article/details/85100514
*/

/* Stack Queue Model
                                      Queue Front = x_0
                                      Queue Back  = x_N
Stack_In :  [x_0, x_1, ..., x_n]  =>  [x_{n+1}, x_{n+2}, ..., x_N]
Stack_Out:  [                  ]  =>  [x_n, x_{n-1},     ..., x_0]
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<typename T>
class Queue {
private:
    stack<T> _stack_in;
    stack<T> _stack_out;

public:
    Queue() {

    }

public:
    int size() {
        return (_stack_in.size() + _stack_out.size());
    }


    bool empty() {
        return (_stack_in.empty() && _stack_out.empty());
    }


    void push(T elem) {
        _stack_in.push(elem);
    }


    T pop() {
        T ret;
        if (!_stack_out.empty()) {
            ret = _stack_out.top();
            _stack_out.pop();
        }
        else if (!_stack_in.empty()) {
            while (!_stack_in.empty()) {
                _stack_out.push(_stack_in.top());
                _stack_in.pop();
            }
            ret = _stack_out.top();
            _stack_out.pop();
        }
        else {
            throw (const char *)("The queue is empty.");
        }
        return ret;
    }


    T front() {
        if (!_stack_out.empty()) {
            return _stack_out.top();
        }
        else if (!_stack_in.empty()) {
            while (!_stack_in.empty()) {
                _stack_out.push(_stack_in.top());
                _stack_in.pop();
            }
            return _stack_out.top();
        }
        else {
            throw (const char *)("The queue is empty.");
        }
    }


    T back() {
        if (!_stack_in.empty()) {
            return _stack_in.top();
        }
        else if (!_stack_out.empty()) {
            while (!_stack_out.empty()) {
                _stack_in.push(_stack_out.top());
                _stack_out.pop();
            }
            return _stack_in.top();
        }
        else {
            throw (const char *)("The queue is empty.");
        }
    }
};


int main(int argc, char *argv[]) {
    Queue<int> queue = Queue<int>();
    queue.push(9);
    queue.push(0);
    queue.push(8);
    queue.push(2);
    queue.push(6);

    cout << "queue.front() = " << queue.front() << endl;
    cout << "queue.back() = " << queue.back() << endl;
    cout << "queue.size() = " << queue.size() << endl;
    cout << "----------------------------------------" << endl;

    queue.pop();
    queue.pop();

    cout << "queue.front() = " << queue.front() << endl;
    cout << "queue.back() = " << queue.back() << endl;
    cout << "queue.size() = " << queue.size() << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}