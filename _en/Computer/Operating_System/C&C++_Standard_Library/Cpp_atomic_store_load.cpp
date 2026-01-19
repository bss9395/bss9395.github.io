/// Record: Cpp_atomic_store_load.cpp
/// Author: bss9395
/// Update: 2026/01/17⊥22:06:00&+08$08@China-BeiJing
/// Keepin: bss9395@yeah.net
/// Credit: https://legacy.cplusplus.com/reference/atomic/atomic/load/

#include <iostream>     
#include <atomic>       
#include <thread>      

class Type {
public:
    std::atomic<int> _value = 0;

    void _Set(int value) {
        _value.store(value, std::memory_order_relaxed);
    }

    void _Print() {
        int value = _value.load(std::memory_order_relaxed);
        std::cout << value << std::endl;
    }
};

int main(int argc, char *argv[]) {
    Type* type = new Type();
    std::thread one(&Type::_Set, type, 10);
    std::thread two(&Type::_Print, type);
    two.join();
    one.join();
    delete type;

    return 0;
}
