/* shared_ptr.cpp
Author: BSS9395
Update: 2022-04-22T22:10:00+08@China-Shanghai+08
Design: C++ Standard Library: shared_ptr
*/

#include <iostream>
#include <memory>
using namespace std;

struct B; // note: declaration of B;
struct A {
    shared_ptr<B> ptr = nullptr;
    A() {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~A() {
        std::cout << __FUNCTION__ << std::endl;
    }
};

struct B {
    shared_ptr<A> ptr = nullptr;
    B() {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~B() {
        std::cout << __FUNCTION__ << std::endl;
    }
};

void Test_shared_ptr() {
    shared_ptr<A> pa(new A());  // note: the instance of A counts 1 in pa.
    shared_ptr<B> pb(new B());  // note: the instance of B counts 1 in pb.
    pa->ptr = pb;               // note: the instance of B counts 2 in pb.
    pb->ptr = pa;               // note: the instance of A counts 2 in pa.
    // note: the instance of B counts down to 1 in pb.
    // note: the instance of A counts down to 1 in pa.
    // note: neither pa nor pb will release the managed memory.
}

int main() {
    Test_shared_ptr();

    return 0;
}
