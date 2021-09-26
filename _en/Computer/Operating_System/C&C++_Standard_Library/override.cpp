/* Override.cpp
Author: BSS9395
Update: 2021-09-22T21:37:00+08@China-Guangdong-Shenzhen+08
Design: C++ keyword override
*/

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    // overload
    void Overload() {
        cout << "void Overload()" << endl;
        return;
    }

    // overload
    virtual int Overload(int load) {
        cout << "virtual int Overload(int load)" << endl;
        return load;
    }

    virtual Base &Override(string ride) {
        cout << "virtual Base &Override(string ride)" << endl;
        return (*this);
    }
};

double Overload(double load) {
    cout << "double Overload(double str)" << endl;
    return load;
}

class Derived final : public Base {
private:
    // redefine
    string Overload(string load) {
        cout << "string Overload(string load)" << endl;
        Base::Overload();
        Base::Overload(1);
        ::Overload(1.0);
        return load;
    }

    // override
    virtual Derived &Override(string ride) override final {
        cout << "virtual Derived &Override(string ride) override final" << endl;
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
