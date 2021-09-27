/* const.cpp
Author: BSS9395
Update: 2021-09-27T18:30:00@China-Guangdong-Shenzhen+08
Design: C++ keyword const
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Const {
public:
    static const long _Size;
    static long _Count;

private:
    mutable long _count = 0;
    string _data = "data";

public:
    void ptr_char(char *ptr) {
        cout << "void ptr_char(char *ptr)" << endl;
    }

    void ptr_const_char(char const *ptr) {
        cout << "void ptr_const_char(char const *ptr)" << endl;
    }

    void const_ptr_char(char *const ptr) {
        cout << "void const_ptr_char(char *const ptr)" << endl;
    }

    void const_ptr_const_char(char const *const *ptr) {
        cout << "void const_ptr_const_char(char const *const *ptr)" << endl;
    }

    ////////////////////////////////////
public:
    void ptr_ptr_char(char **ptr_ptr) {
        cout << "void ptr_ptr_char(char **ptr_ptr)" << endl;
    }

    void ptr_ptr_const_char(char const **ptr_ptr) {
        cout << "void ptr_ptr_const_char(char const **ptr_ptr)" << endl;
    }

    void ptr_const_ptr_char(char *const *ptr_ptr) {
        cout << "void ptr_const_ptr_char(char *const *ptr_ptr)" << endl;
    }

    void const_ptr_ptr_char(char **const ptr_ptr) {
        cout << "void const_ptr_ptr_char(char **const ptr_ptr)" << endl;
    }

    void ptr_const_ptr_const_char(char const *const *ptr_ptr) {
        cout << "void ptr_const_ptr_const_char(char const *const *ptr_ptr)" << endl;
    }

    void const_ptr_const_ptr_char(char *const *const ptr_ptr) {
        cout << "void const_ptr_const_ptr_char(char *const *const ptr_ptr)" << endl;
    }

    void const_ptr_ptr_const_char(char const **const ptr_ptr) {
        cout << "void const_ptr_ptr_const_char(char const **const ptr_ptr)" << endl;
    }

    void const_ptr_const_ptr_const_char(char const *const *const ptr_ptr) {
        cout << "void const_ptr_const_ptr_const_char(char const *const *const ptr_ptr)" << endl;
    }

    ////////////////////////////////////
public:
    long const_this() {
        cout << "long const_this()" << endl;
        _data = "const_this";
        _Count += 1;
        return _Count;
    }

    long const_this() const {
        cout << "long const_this() const" << endl;
        // _data = "const_this_const";  /* Error */
        _Count += 1;
        _count += 1;
        return _count;
    }
};
const long Const::_Size = sizeof(Const);
long Const::_Count = 0;


int main(int argc, char *argv[]) {
    char ch = 'c';
    char *ptr = &ch;
    char **ptr_ptr = &ptr;
    Const cls;
    cls.ptr_ptr_char(ptr_ptr);
    // cls.ptr_ptr_const_char(ptr_ptr);     /* Error */
    cls.ptr_const_ptr_char(ptr_ptr);
    cls.const_ptr_ptr_char(ptr_ptr);
    cls.ptr_const_ptr_const_char(ptr_ptr);
    cls.const_ptr_const_ptr_char(ptr_ptr);
    // cls.const_ptr_ptr_const_char(ptr);   /* Error */
    cls.const_ptr_const_ptr_char(ptr_ptr);

    ////////////////////////////////////

    Const non;
    const Const con;
    non.const_this();
    con.const_this();

    return 0;
}
