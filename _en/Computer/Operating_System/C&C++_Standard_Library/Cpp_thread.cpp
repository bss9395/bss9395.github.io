/* Cpp_thread.cpp
Author: bss9395
Update: 2025-07-15T09:35:00+08@China-ShangHai+08
*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

class Run {
public:
    void _Func(bool except, double arg1, std::string arg2) {
        _mutex.lock();
        std::cout << __FUNCTION__ << ", arg1 = " << arg1 << std::endl;
        if(except == true) {
            throw std::string("error occurred.");
        }
        for (int i = 0; i < (int)arg2.size(); i += 1) {
            std::cout << arg2[i];
        }
        std::cout << std::endl;
        _mutex.unlock();
    }

private:
    std::mutex _mutex;
};

void _Test_thread() {
    Run* run = new Run();
    std::thread routine1 = std::thread(&Run::_Func, run, false, 1.0, "abcdefghijklmnopqrstuvwxyz");
    std::thread routine2 = std::thread(&Run::_Func, run, false, 2.0, "ABCEDFGHIJKLMNOPQRSTUVWXYZ");
    routine1.join();
    routine2.join();
    delete run;
}

void _Test_Exception() {
    try {
        Run* run = new Run();
        std::thread routine1 = std::thread(&Run::_Func, run, false, 1.0, "abcdefghijklmnopqrstuvwxyz");
        std::thread routine2 = std::thread(&Run::_Func, run, true, 2.0, "ABCEDFGHIJKLMNOPQRSTUVWXYZ");
        routine1.join();
        routine2.join();
        delete run;
    } catch(const std::string& except) {
        std::cout << "exception caught: " << except << std::endl;
    } catch(...) {
        std::cout << "unknown exception." << std::endl;
        throw;
    }
}

int main() {
    // _Test_thread();
    _Test_Exception();

    return 0;
}
