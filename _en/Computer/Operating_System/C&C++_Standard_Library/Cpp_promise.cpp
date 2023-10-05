/* Cpp_promise.cpp
Author: BSS9395
Update: 2023-10-01-T10:02:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: promise
*/

#include <iostream>     
#include <functional>     
#include <thread>         
#include <future>         

void _Print(std::future<int>& future) {
    int value = future.get();
    std::cout << "value: " << value << '\n';
}

int main() {
    std::promise<int> promise;                      
    std::future<int> fut = promise.get_future();   
    std::thread th1(_Print, std::ref(fut)); 
    promise.set_value(10);                         
    th1.join();
    return 0;
}