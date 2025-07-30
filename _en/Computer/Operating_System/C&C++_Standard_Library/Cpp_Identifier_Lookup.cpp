/* Cpp_Identifier_Lookup.cpp
Author: bss9395
Update: 2025-07-25T15:01:00+08@China-GuangDong-ZhanJiang+08
*/

#include <iostream>

class Base {
public:
    virtual void Func() {
        fprintf(stdout, "Base$%s\n", __FUNCTION__);
    }
};

class Derive: public Base {
public:
    void Func() override {
        fprintf(stdout, "Derive$%s\n", __FUNCTION__);
    }
};

class Extend: public Derive {
public:
    void Function() {
        fprintf(stdout, "%s\n", __FUNCTION__);
    }
};

int main() {
    Base* base = new Extend();
    base->Func();

    return 0;
}