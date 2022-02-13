/* Clean.cpp
Author: BSS9395
Update: 2022-02-13T16:24:00+08@China-Guangdong-Zhanjiang+08
Design: Smart Auto Pointer for C++
Encode: UTF-8
*/

#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <set>
#include <map>

typedef intptr_t iptr;

class Clean {
public:
    typedef std::function<void(void)> Function;
    typedef const char *Done;
    static inline const Done _Hitted = "Hitted";
    static inline const Done _Missed = "Missed";

public:
    struct Class {
        virtual ~Class() {

        }
    };
    static inline std::set<std::list<Class *> *> _Set;

public:
    iptr *_refer = nullptr;
    Function *_function = nullptr;
    std::list<Class *> *_pointers = nullptr;

public:
    Clean() {
        fprintf(stderr, "%s""\n", "Clean() {");
        _refer = new iptr(0);
        (*_refer) += 1;
    }

    Clean(const Function &function) {
        fprintf(stderr, "%s""\n", "Clean(const Function &function) {");
        _refer = new iptr(0);
        _function = new Function(function);
        (*_refer) += 1;
    }

    Clean(const Clean &clean) {
        fprintf(stderr, "%s""\n", "Clean(const Clean &clean) {");
        _refer = clean._refer;
        _function = clean._function;
        _pointers = clean._pointers;
        (*_refer) += 1;
    }

    Clean &operator=(const Clean &clean) {
        fprintf(stderr, "%s""\n", "Clean &operator=(const Clean &clean) {");
        if (this != &clean) {
            _refer = clean._refer;
            _function = clean._function;
            _pointers = clean._pointers;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Clean() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        if (_function != nullptr) {
            (*_function)();
        }

        ////////////////////////////////

        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            if (_function != nullptr) {
                delete _function;
            }
            if (_pointers != nullptr) {
                if (0 < (*_pointers).size()) {
                    for (auto beg = (*_pointers).begin(), end = (*_pointers).end(); beg != end; beg++) {
                        delete (*beg);
                    }
                }
                Clean::_Set.erase(_pointers);
                delete _pointers;
            }
        }
    }

public:
    Clean &Auto_Pointer(void *pointer) {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        if (_pointers == nullptr) {
            _pointers = new std::list<Class *>();
            Clean::_Set.insert(_pointers);
        }
        _pointers->push_front((Class *)pointer);
        return (*this);
    }

    Done Clean_Pointer(void *pointer) {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        if (_pointers != nullptr && 0 < (*_pointers).size()) {
            for (auto beg = (*_pointers).begin(), end = (*_pointers).end(); beg != end; beg++) {
                if ((*beg) == pointer) {
                    _pointers->erase(beg);
                    delete pointer;
                    return _Hitted;
                }
            }
        }
        return _Missed;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Base {
public:
    Base() {

    }

    virtual ~Base() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
    }
};

class Derived : public Base {
public:
    Derived() {

    }

    virtual ~Derived() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
    }
};



int main(int argc, char *argv[]) {
    Base *base = new Base();
    Base *child = new Derived();
    auto clean = Clean([base]() -> void {
        delete base;
    });
    clean.Auto_Pointer(child);

    return 0;
}
