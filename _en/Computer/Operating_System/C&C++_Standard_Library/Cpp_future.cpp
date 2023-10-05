/* Cpp_future.cpp
Author: BSS9395
Update: 2023-09-30T16:33:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: future
*/


#include <iostream>      
#include <future>         
#include <chrono>   

bool _Validate_Prime(int prime) {
    for (int i = 2; i < prime; ++i) {
        if (prime % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::future<bool> future = std::async(_Validate_Prime, 444444443);

    std::chrono::milliseconds span(100);
    while (future.wait_for(span) == std::future_status::timeout)
        std::cout << '.' << std::flush;

    bool x = future.get();
    std::cout << std::endl << "444444443 " << (x ? "is" : "is not") << " prime." << std::endl;

    return 0;
}