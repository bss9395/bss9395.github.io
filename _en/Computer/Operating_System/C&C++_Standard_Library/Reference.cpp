/* Reference.cpp
Author: BSS9395
Update: 2021-09-25T18:00:00+08@China-Guangdong-Shenzhen+08
Design: C++ Reference
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::move;

class Reference {
private:
    string &_stri;
    vector<double> _data;

public:
    Reference(string &stri)
        : _stri(stri) {
        cout << "Reference(string &stri)" << endl;
    }

    Reference(string &&stri = string("default"))
        : _stri(stri) {
        cout << "Reference(string &&stri)" << endl;
    }

    Reference(const Reference &ref)
        : _stri(ref._stri), _data(ref._data) {
        cout << "Reference(const Reference &ref)" << endl;
    }

    Reference &operator=(const Reference &ref) {
        cout << "Reference &operator=(const Reference &ref)" << endl;
        this->~Reference();
        _stri = ref._stri;
        _data = ref._data;
        return (*this);
    }

    Reference(Reference &&ref)
        : _stri(ref._stri), _data(move(ref._data)) {
        cout << "Reference(Reference &&ref)" << endl;
    }

    Reference &operator=(Reference &&ref) {
        cout << "Reference &operator=(Reference &&ref)" << endl;
        if (this != &ref) {
            this->~Reference();
            _stri = ref._stri;
            _data = move(ref._data);
        }
        return (*this);
    }

    virtual ~Reference() {
        cout << "virtual ~Reference()" << endl;
    }

public:
    vector<double> Get_Data() & {
        cout << "vector<double> Get_Data() &" << endl;
        return _data;
    }
    vector<double> Get_Data() && {
        cout << "vector<double> Get_Data() &&" << endl;
        return move(_data);
    }
};

int main(int argc, char *argv[]) {
    // Variables are lvalue.
    // Expressions are rvalue.
    double value = 123.456;
    double &lref = value;
    double &&rref = value * value;
    const double &clref = value * value;
    const double &&crref = value * value;

    ////////////////////////////////////

    string stri("stri");
    Reference reference(stri);
    auto lambda = []() -> Reference {
        Reference temp;
        return temp;
    };

    Reference lrefe(reference);
    lrefe = reference;
    Reference rrefe(move(reference));
    rrefe = move(reference);

    Reference rlamb(lambda());
    rlamb = lambda();
    Reference &&rlambda = lambda();

    ////////////////////////////////////

    vector<double> ldata = reference.Get_Data();
    vector<double> rdata = Reference().Get_Data();

    return 0;
}
