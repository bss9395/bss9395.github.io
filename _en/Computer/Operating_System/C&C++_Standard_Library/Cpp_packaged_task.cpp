/* Cpp_packaged_task.cpp
Author: BSS9395
Update: 2023-09-30T17:23:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: packaged_task
*/

#include <future>       
#include <chrono>       
#include <thread>       
#include <iostream>

int countdown(int from, int to) {
    for (int i = from; i != to; i -= 1) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return from - to;
}

int main() {
    std::packaged_task<int(int, int)> task(countdown);   
    std::future<int> future = task.get_future();           

    std::thread thread(std::move(task), 10, 0);
    int value = future.get();                              
    std::cout << "The countdown lasted for " << value << " seconds.\n";

    thread.join();
    return 0;
}