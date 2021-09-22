/* Override.cpp
Author: BSS9395
Update: 2021-09-22T21:37:00+08@China-Guangdong-Shenzhen+08
Design: C++ override keyword
*/

#include <iostream>
using namespace std;

class Base {
public:
    // overload
    void Overload() {
        cout << __FUNCTION__ << endl;
    }

    // overload
    int Overload(int load) {
        cout << __FUNCTION__ << endl;
    }

public:
    virtual void Override(int ride) {
        cout << __FUNCTION__ << endl;
    }
};

class Derived : public Base {
private:
    // override
    virtual void Override(int ride) override {
        cout << __FUNCTION__ << endl;
    }

    // redefine
    double Overload(double load) {
        cout << __FUNCTION__ << endl;
        Base::Overload();
        Base::Overload(1);
    }
};

int main(int argc, char *argv[]) {
    Derived derived;
    Base &ref = derived;
    ref.Override(2);

    return 0;
}
