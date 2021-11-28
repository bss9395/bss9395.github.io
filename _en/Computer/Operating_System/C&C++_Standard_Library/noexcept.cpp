/* noexcept.cpp
Author: BSS9395
Update: 2021-11-28T17:29:00+08@China-Guangdong-Shen+08
Design: C++ Standard Keyword: noexcept
*/

#include <iostream>
#include <vector>
#include <utility>
#include <memory>

typedef intptr_t iptr;

class Shared {
public:
    iptr *_refer = nullptr;
    double *_value = nullptr;

public:
    Shared(double value) {
        std::cout << "Shared(double value)" << std::endl;
        _refer = new iptr(0);
        _value = new double(value);
        (*_refer) += 1;
    }

    Shared(const Shared& shared) {
        std::cout << "Shared(const Shared& shared)" << std::endl;
        _refer = shared._refer;
        _value = shared._value;
        (*_refer) += 1;
    }

    Shared &operator=(const Shared& shared) {
        std::cout << "Shared &operator=(const Shared& shared)" << std::endl;
        if (this != &shared) {
            this->~Shared();
            _refer = shared._refer;
            _value = shared._value;
            (*_refer) += 1;
        }
        return (*this);
    }

    Shared(Shared&& shared) noexcept {
        std::cout << "Shared(Shared&& shared) noexcept" << std::endl;
        _refer = shared._refer;
        _value = shared._value;
        (*_refer) += 1;
    }

    Shared &operator=(Shared&& shared) noexcept {
        std::cout << "Shared &operator=(Shared&& shared) noexcept" << std::endl;
        if (this != &shared) {
            this->~Shared();
            _refer = shared._refer;
            _value = shared._value;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Shared() noexcept {
        std::cout << "virtual ~Shared() noexcept" << std::endl;
        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            delete _refer;
            delete _value;
        }
    }
};


Shared Make_Shared(double value) {
    Shared shared = Shared(value);
    return shared;
}

void Test_Shared() {
    Shared shared = Shared(1);
    Shared make = Make_Shared(2);
    make = shared;
}

void Test_Vecotr() {
    Shared shared = Shared(1);
    std::vector<Shared> vec;
    vec.push_back(shared);
    vec.push_back(Shared(2));
}

void Test_Pointer() {
    Shared *shared = new Shared(1);
    std::vector<Shared *> vec;
    vec.push_back(shared);
    for (int i = 0; i < vec.size(); i += 1) {
        delete vec[i];
    }
}

void Test_Shared_Pointer() {
    Shared *shared = new Shared(1);
    std::vector<std::shared_ptr<Shared>> vec;
    vec.push_back(std::shared_ptr<Shared>(shared));
}


int main(int argc, char*argv[]) {
    Test_Shared();

    return 0;
}
