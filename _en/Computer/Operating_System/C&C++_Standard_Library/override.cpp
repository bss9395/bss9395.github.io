/* Override.cpp
Author: BSS9395
Update: 2021-09-22T21:37:00+08@China-Guangdong-Shenzhen+08
Design: C++ override keyword
*/

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    // overload
    void Overload() {
        cout << __FUNCTION__ << endl;
        return;
    }

    // overload
    virtual int Overload(int load) {
        cout << __FUNCTION__ << endl;
        return load;
    }

    virtual Base &Override(string ride) {
        cout << __FUNCTION__ << endl;
        return (*this);
    }
};

class Derived : public Base {
private:
    // redefine
    string Overload(string load) {
        cout << __FUNCTION__ << endl;
        Base::Overload();
        Base::Overload(1);
        return load;
    }

    // override
    virtual Derived &Override(string ride) override final {
        cout << __FUNCTION__ << endl;
        Base::Overload();
        Base::Overload(1);
        return (*this);
    }
};

int main(int argc, char *argv[]) {
    Derived derived;
    Base &ref = derived;
    ref.Override("derived");

    return 0;
}
