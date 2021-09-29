/* default.cpp
Author: BSS9395
Update: 2021-09-29T20:22:00+08@China-Guangdong-Shenzhen+08
Design: C++ Keyword default
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Default {
public:
    Default() = default;

public:
    virtual void Virtual(string def = string("Default")) {
        cout << __FUNCTION__ << " => " << def << endl;
    }

    virtual void Invoke_Polymorphism() {
        cout << __FUNCTION__ << endl;
        Virtual();
    }

    virtual void Invoke_Default() {
        cout << __FUNCTION__ << endl;
        Virtual();
    }
};

class Polymorphism : public Default {
public:
    virtual void Virtual(string def = string("Polymorphism")) override {
        cout << __FUNCTION__ << " => " << def << endl;
    }

    virtual void Invoke_Polymorphism() override {
        cout << __FUNCTION__ << endl;
        Virtual();
    }
};

int main(int argc, char* argv[]) {
    Default *poly = new Polymorphism;
    poly->Invoke_Polymorphism();
    poly->Invoke_Default();

    return 0;
}
