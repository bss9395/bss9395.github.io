/* Cpp_lock_guard.cpp
Author: BSS9395
Update: 2023-10-01T09:17:00:+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: lock_guard
*/

#include <iostream>       
#include <thread>         
#include <mutex>       
#include <stdexcept>     

std::mutex mtx;

void _Print_Even(int x) {
    if (x % 2 == 0) {
        std::cout << x << " is even" << std::endl;
    }
    else {
        throw std::logic_error("not even");
    }
}

void _Print_Thread(int id) {
    try {
        std::lock_guard<std::mutex> lock(mtx);
        _Print_Even(id);
    }
    catch (std::logic_error&) {
        std::cout << "[exception caught]\n";
    }
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; i += 1) {
        threads[i] = std::thread(_Print_Thread, i + 1);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}