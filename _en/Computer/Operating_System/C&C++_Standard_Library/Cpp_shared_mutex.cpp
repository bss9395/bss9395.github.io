/* Cpp_shared_mutex.cpp
Author: BSS9395
Update: 2023-10-03T16:05:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: shared_mutex
*/

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

class Counter_Safe {
public:
    Counter_Safe() = default;

    unsigned int get() {
        std::shared_lock<std::shared_mutex> lock(_mutex);
        return _counter;
    }

    void increment() {
        std::unique_lock<std::shared_mutex> lock(_mutex);
        _counter++;
    }

    void reset() {
        std::unique_lock<std::shared_mutex> lock(_mutex);
        _counter = 0;
    }

private:
    std::shared_mutex _mutex;
    unsigned int _counter = 0;
};

int main() {
    Counter_Safe counter;
    auto increment_and_print = [&counter]() {
        for (int i = 0; i < 3; i++) {
            counter.increment();
            fprintf(stdout, "%ld: %d\n", std::this_thread::get_id(), counter.get());
        }
    };

    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    thread1.join();
    thread2.join();

    return 0;
}