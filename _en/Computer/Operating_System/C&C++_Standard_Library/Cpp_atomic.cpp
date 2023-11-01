/* Cpp_atomic.cpp
Author: BSS9395
Update: 2023-10-05T17:53:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: atomic
*/

#include <atomic>
#include <thread>
#include <iostream>

int main() {
    std::atomic<int> count = { 0 };

    std::thread t1([&count]() {
        count.fetch_add(1);
    });

    std::thread t2([&count]() {
        count++;     // note: identical to fetch_add
        count += 1;  // note: identical to fetch_add
    });

    t1.join();
    t2.join();

    std::cout << count << std::endl;
    return 0;
}