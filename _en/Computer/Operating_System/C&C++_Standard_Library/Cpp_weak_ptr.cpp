/* Cpp_weak_ptr.cpp
Author: BSS9395
Update: 2023-10-05T17:17:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Standard Library: weak_ptr
*/

#include <iostream>
#include <memory>

class A;
class B;

class A {
public:
    std::weak_ptr<B> pointer;
    ~A() {
        std::cout << "A was destroyed" << std::endl;
    }
};

class B {
public:
    std::weak_ptr<A> pointer;
    ~B() {
        std::cout << "B was destroyed" << std::endl;
    }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->pointer = b;
    b->pointer = a;

    return 0;
}