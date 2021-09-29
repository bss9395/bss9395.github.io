/* delete.cpp
Author: BSS9395
Update: 2021-09-28T23:40:00+08@China-Guangdong-Shenzhen+08
Design: C++ Keyword delete
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Delete {
private:
    string *_ptr = nullptr;

public:
    Delete() {
        cout << "Delete()" << endl;
        _ptr = new string("string");
    }

    Delete(const Delete &del) {
        cout << "Delete(const Delete &del)" << endl;
        // _ptr = del._ptr;                                              /* shallow copy: potential fatal error. */
        _ptr = (del._ptr == nullptr) ? nullptr : new string(*del._ptr);  /* deep copy */
    }

    Delete &operator=(const Delete &del) {
        cout << "Delete &operator=(const Delete &del)" << endl;
        if (this != &del) {
            // _ptr = del._ptr;                                              /* shallow copy: potential fatal error. */
            _ptr = (del._ptr == nullptr) ? nullptr : new string(*del._ptr);  /* deep copy */
        }
        return (*this);
    }

    virtual ~Delete() {
        cout << "virtual ~Delete()" << endl;
        delete _ptr;
        _ptr = nullptr;
    }

public:
    void Delete_Self() {
        delete this;
    }
};

// invoke copy constructor
void Double_Delete(Delete del) {
    Delete dou;
    // invoke copy assignment operator.
    dou = del;
}


int main(int argc, char *argv[]) {
    Delete del;
    Double_Delete(del);

    ////////////////////////////////////

    Delete *self = new Delete;
    self->Delete_Self();

    return 0;
}
