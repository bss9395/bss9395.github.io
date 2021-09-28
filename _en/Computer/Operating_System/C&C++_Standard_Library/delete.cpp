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
        // ptr = del.ptr;              /* shallow copy: potential fatal error. */
        _ptr = new string(*del._ptr);  /* deep copy */
    }

    virtual ~Delete() {
        cout << "virtual ~Delete()" << endl;
        delete _ptr;
        _ptr = nullptr;
    }
};

void Double_Delete(Delete del) {
    // invoke copy constructor of Delete.
}


int main(int argc, char *argv[]) {
    Delete del;
    Double_Delete(del);

    return 0;
}
