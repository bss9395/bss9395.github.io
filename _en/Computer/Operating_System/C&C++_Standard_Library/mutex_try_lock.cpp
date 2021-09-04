/* mutex_try_lock.cpp
Author: BSS9395
Update: 2020-09-04T17:25:00+08@China-Guangdong-Zhanjiang+08
Design: mutex.try_lock()
*/

/*
#include <mutex>
class mutex;
*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

string str;
mutex mtx;
bool goon;

void thread1(int num) {
    goon = true;
    while (0 < num) {
        if (mtx.try_lock()) {
            int len = (int)str.length();
            if (len % 4 == 0) {
                str += 'A';
                num -= 1;
            }
            mtx.unlock();
        }
    }
    goon = false;
}

void thread2() {
    while (true) {
        if (mtx.try_lock()) {
            int len = (int)str.length();
            if (len % 4 == 1) {
                str += 'B';
            }
            else if (goon == false && len % 4 == 0) {
                mtx.unlock();
                break;
            }
            mtx.unlock();
        }
    }
}

void thread3() {
    while (true) {
        if (mtx.try_lock()) {
            int len = (int)str.length();
            if (len % 4 == 2) {
                str += 'C';
            }
            else if (goon == false && len % 4 == 0) {
                mtx.unlock();
                break;
            }
            mtx.unlock();
        }
    }
}

void thread4() {
    while (true) {
        if (mtx.try_lock()) {
            int len = (int)str.length();
            if (len % 4 == 3) {
                str += 'D';
            }
            else if (goon == false && len % 4 == 0) {
                mtx.unlock();
                break;
            }
            mtx.unlock();
        }
    }
}

int main(int argc, char *argv[]) {
    int num = 10;

    str.clear();
    thread th1(thread1, num);
    thread th2(thread2);
    thread th3(thread3);
    thread th4(thread4);
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    cout << str << endl;

    return 0;
}