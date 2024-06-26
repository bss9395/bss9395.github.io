/* lock_guard.cpp
Author: BSS9395
Update: 2021-09-22T21:37:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library lock_guard
*/

/*
#include <mutex>
template <class Mutex>
class lock_guard;
*/

#include <iostream>
#include <exception>
#include <thread>
#include <mutex>

using std::cout;
using std::cerr;
using std::endl;
using std::exception;
using std::thread;
using std::mutex;
using std::lock_guard;

class Singleton {
    static Singleton *_singleton;
    static mutex _mtx;

public:
    Singleton() {
        cout << __FUNCTION__ << endl;
    }

    ~Singleton() {
        cout << __FUNCTION__ << endl;
    }

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
    void operator=(Singleton&&) = delete;

public:
    static Singleton *GetInstace() {
        if (_singleton == nullptr) {
            lock_guard<mutex> lock(_mtx);
            if (_singleton == nullptr) {
                static Singleton singleton;
                _singleton = &singleton;
            }
        }
        return _singleton;
    }
};

Singleton singleton;
Singleton *Singleton::_singleton = &singleton;
mutex Singleton::_mtx;

void func(int i) {
    try {
        Singleton::GetInstace();
    }
    catch (...) {
        cout << "exception..." << endl;
    }
}

int main(int argc, char *argv[]) {
    const int thread_num = 10;
    thread arr[thread_num];

    for (int i = 0; i < thread_num; ++i) {
        arr[i] = thread(func, i);
    }

    for (int i = 0; i < thread_num; ++i) {
        arr[i].join();
    }

    return 0;
}
