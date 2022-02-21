/*Pointer.hpp
* Author: BSS9395
* Update: 2020-01-13T18:22:00+08@ShenZhen
* Design: Automation
*/

#ifndef Pointer_hpp
#define Pointer_hpp

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using ::fprintf;
using ::free;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <functional>
#include <typeinfo>
using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::stringstream;
using std::exception;
using std::function;

////////////////////////////////////////////////////////////////////////////////

typedef const char *Tag;
typedef const char *Origin;
typedef const char *Level;
namespace EType {
    static const Tag Debug = "Debug";
    static const Tag Release = "Release";
    static const Tag Beta = "Beta";
    static const Tag Stable = "Stable";

    static const Origin CHeap = "CHeap";
    static const Origin Cstack = "CStack";
    static const Origin CppHeap = "CppHeap";
    static const Origin CppStack = "CppStack";

    static const Level Information = "Information";
    static const Level Incompleted = "Incompleted";
    static const Level Obsolete = "Obsolete";
    static const Level Warning = "Warning";
    static const Level Error = "Error";
    static const Level Fatal = "Fatal";
};

////////////////////////////////////////////////////////////////////////////////

template<typename ...>               class Pointer;
template<typename T>                 class Pointer<T>;
template<typename T, typename ...Ts> class Pointer<T, Ts...>;
template<typename T>                 decltype(auto) GetPointer(T *pointer, const int &size = 1);
template<typename T, typename ...Ts> decltype(auto) GetPointer(T *pointer, Ts *...pointers);

template<typename ...>               class Assembly;
template<typename T>                 class Assembly<T>;
template<typename T, typename ...Ts> class Assembly<T, Ts...>;

////////////////////////////////////////////////////////////////////////////////

template<typename ...>
class Pointer;

template<>
class Pointer<> {
public:
    typedef class Pointer<> Type;
    static const int _ARGC = 0;

public:
    Pointer() = delete;
    Pointer(const Pointer&) = delete;
    Pointer &operator=(const Pointer&) = delete;
    virtual ~Pointer() = delete;

public:
    template<const int I, typename ...Ts>
    struct GetType;

    template<typename T, typename ...Ts>
    struct GetType<0, T, Ts...> {
        typedef T Type;
        static const int _OFFSET = 0;
    };

    template<const int I, typename T, typename ...Ts>
    struct GetType<I, T, Ts...> {
        typedef typename GetType<I - 1, Ts...>::Type Type;
        static const int _OFFSET = sizeof(T) + GetType<I - 1, Ts...>::_OFFSET;
    };
};

template<typename T>
class Pointer<T> {
public:
    typedef class Pointer<T> Type;
    static const int _ARGC = 1;

public:
    Pointer(T *address = nullptr, int size = 1)
        : _address(address), _pointer(address), _count(new int(1)), _size(size) {
        // cerr << __FUNCTION__ << endl;
    }

    Pointer(T *address, int size, T *pointer, int *count = new int(1))
        : _address(address), _pointer(pointer), _count(count), _size(size) {
        *count += 1;
        // cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
    }

    Pointer(const Pointer &pointer) {
        _address = pointer._address;
        _pointer = pointer._pointer;
        _count = pointer._count;
        _size = pointer._size;
        *_count += 1;
        // cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
    }

    Pointer &operator=(const Pointer &pointer) {
        if (this != &pointer) {
            this->~Pointer();
            _address = (T *)pointer._address;
            _pointer = (T *)pointer._pointer;
            _count = pointer._count;
            _size = pointer._size;
            *_count += 1;
        }
        // cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
        return *this;
    }

    virtual ~Pointer() {
        // cerr << __FUNCTION__ << " " << *_count << " " << _size << endl;
        *_count -= 1;
        if (*_count <= 0) {
            _size <= 1 ? delete _address : delete[] _address;
            delete _count;
            //_address = nullptr;
            //_pointer = nullptr;
            //_count = nullptr;
            //_size = 0;
        }
    }

public:


    int capacity(const int &size = 0) {
        // cerr << __FUNCTION__ << endl;
        if (size == 1) {
            if (_size > 1) {
                T *address = new T{ _address[0] };
                delete[] _address;
                _address = address;
                _pointer = _address;
            }
            _size = size;
        } else if (size > 1) {
            if (_size < size) {
                T *address = new T[size];
                for (int i = 0; i < _size; i += 1) {
                    address[i] = _address[i];
                }
                _size <= 1 ? delete _address : delete[] _address;
                _pointer = address + (_pointer - _address);
                _address = address;
            }
            _size = size;
        }
        return _size;
    }

    int size() {
        // cerr << __FUNCTION__ << endl;
        return (int)(_address + _size - _pointer);
    }

    int offset() {
        // cerr << __FUNCTION__ << endl;
        return (int)(_pointer - _address);
    }

    Pointer<T> &reset() {
        // cerr << __FUNCTION__ << endl;
        _pointer = _address;
        return *this;
    }

    template<const int I = 0>
    Pointer<T> at() const {
        // cerr << __FUNCTION__ << endl;
        return *this;
    }

public:
    Pointer<T> &operator+=(int incr) {
        // cerr << __FUNCTION__ << endl;
        int idx = (int)(_pointer + incr - _address);
        Check(_pointer == nullptr || !(0 <= idx && idx <= _size), __FILE__, __LINE__, __FUNCTION__, errno, "(_pointer == nullptr || !(0 <= idx && idx < _size))");
        _pointer += incr;
        return *this;
    }

    Pointer<T> operator+(int incr) const {
        // cerr << __FUNCTION__ << endl;
        int idx = (int)(_pointer + incr - _address);
        Check(_pointer == nullptr || !(0 <= idx && idx <= _size), __FILE__, __LINE__, __FUNCTION__, errno, "(_pointer == nullptr || !(0 <= idx && idx < _size))");
        return Pointer<T>(_address, _size, _pointer + incr, _count);
    }

    Pointer<T> &operator-=(int decr) {
        // cerr << __FUNCTION__ << endl;
        int idx = (int)(_pointer - decr - _address);
        Check(_pointer == nullptr || !(0 <= idx && idx <= _size), __FILE__, __LINE__, __FUNCTION__, errno, "(_pointer == nullptr || !(0 <= idx && idx < _size))");
        _pointer -= decr;
        return *this;
    }

    Pointer<T> operator-(int decr) const {
        // cerr << __FUNCTION__ << endl;
        int idx = (int)(_pointer - decr - _address);
        Check(_pointer == nullptr || !(0 <= idx && idx <= _size), __FILE__, __LINE__, __FUNCTION__, errno, "(_pointer == nullptr || !(0 <= idx && idx < _size))");
        return Pointer<T>(_address, _size, _pointer - decr, _count);
    }

    int checkCapacity(int reserved) {
        int ret = 0;
        if (_address + _size - _pointer <= reserved) {
            int size = _size + reserved;
            T *address = new T[size];
            for (int i = 0; i < _size; i += 1) {
                address[i] = _address[i];
            }
            _size <= 1 ? delete _address : delete[] _address;
            _pointer = address + (_pointer - _address);
            _address = address;
            _size = size;
            ret += 1;
        }
        return ret;
    }

    T &operator[](int index) {
        // cerr << __FUNCTION__ << endl;
        int idx = _pointer + index - _address;

        // Check(_pointer == nullptr || !(0 <= idx), __FILE__, __LINE__, __FUNCTION__, errno, "(_pointer == nullptr || !(0 <= idx))");
        if (idx >= _size) {
            int size = _size * 2;
            T *address = new T[size];
            for (int i = 0; i < _size; i += 1) {
                address[i] = _address[i];
            }
            _size <= 1 ? delete _address : delete[] _address;
            _pointer = address + (_pointer - _address);
            _address = address;
            _size = size;
        }

        return _pointer[index];
    }

    T &operator*() const {
        // cerr << __FUNCTION__ << endl;
        Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
        return *_pointer;
    }

    T *operator->() const {
        // cerr << __FUNCTION__ << endl;
        Check(_pointer == nullptr, __FILE__, __LINE__, __FUNCTION__, errno, "_pointer == nullptr");
        return &(*_pointer);
    }

    operator T *() const {
        //cerr << __FUNCTION__ << endl;
        return (T *)_pointer;
    }

    template<typename P>
    operator P*() const {
        //cerr << __FUNCTION__ << endl;
        return (P *)_pointer;
    }

public:
    T *_address;
    T *_pointer;
    int *_count;
    int _size;
};

template<typename T, typename ...Ts>
class Pointer<T, Ts...> {
public:
    typedef class Pointer<T, Ts...> Type;
    static const int _ARGC = 1 + sizeof...(Ts);

public:
    Pointer(T *pointer, Ts*...pointers)
        : _pointers{ { pointer, pointer, new int(1), 1 }, { pointers, pointers, new int(1), 1 }... }, _count(new int(1)) {
        // cerr << __FUNCTION__ << " " << *_count << endl;
    }

    Pointer(const Pointer &pointer) {
        memcpy(_pointers, pointer._pointers, sizeof(_pointers));
        _count = pointer._count;
        for (int i = 0; i < _ARGC; i += 1) {
            *(_pointers[i]._count) += 1;
        }
        *_count += 1;
        // cerr << __FUNCTION__ << " " << *_count << endl;
    }

    Pointer &operator=(const Pointer &pointer) {
        if (this != &pointer) {
            this->~Pointer();
            memcpy(_pointers, pointer._pointers, sizeof(_pointers));
            _count = pointer._count;
            for (int i = 0; i < _ARGC; i += 1) {
                *(_pointers[i]._count) += 1;
            }
            *_count += 1;
        }
        // cerr << __FUNCTION__ << " " << *_count << endl;
        return *this;
    }

    virtual ~Pointer() {
        // cerr << __FUNCTION__ << " " << *_count << "#";
        int i = 0;
        int argc[] = {
            (deleted<T>(i), i += 1), (deleted<Ts>(i), i += 1)...
        };
        if (sizeof(argc) / sizeof(*argc) != _ARGC) {
            // cerr << "\033[33m" << __FUNCTION__ << " " << *_count << "#" << "sizeof(argc) != _ARGC" << "\033[0m" << endl;
        }

        *_count -= 1;
        if (*_count <= 0) {
            delete _count;
            _count = nullptr;
        }
    }

protected:
    template<typename T>
    void deleted(const int i) {
        // cerr << *_pointers[i]._count << ":" << _pointers[i]._size << ":" << *(T*)(_pointers[i]._pointer) << " ";
        if (i == _ARGC - 1) {
            // cerr << endl;
        }
        *(_pointers[i]._count) -= 1;
        if (*(_pointers[i]._count) <= 0) {
            _pointers[i]._size <= 1 ? delete (T *)(_pointers[i]._address) : delete[](T *)(_pointers[i]._address);
            delete _pointers[i]._count;
            //_pointers[i]._address = nullptr;
            //_pointers[i]._pointer = nullptr;
            //_pointers[i]._count = nullptr;
            //_pointers[i]._size = 0;
        }
    }

public:
    int capacity(const int &size = 0, const int &index = 0) {
        // cerr << __FUNCTION__ << endl;
        if (1 <= size) {
            _pointers[index]._size = size;
        }
        Check(!(0 <= index && index < _ARGC), __FILE__, __LINE__, __FUNCTION__, errno, "(!(0 <= index && index < _ARGC))");
        return _pointers[index]._size;
    }

    int length(const int &index = 0) {
        // cerr << __FUNCTION__ << endl;
        Check(!(0 <= index && index < _ARGC), __FILE__, __LINE__, __FUNCTION__, errno, "(!(0 <= index && index < _ARGC))");
        return (int)(_pointers[index]._address + _pointers[index]._size - _pointers[index]._pointer);
    }

    template<const int I>
    decltype(auto) at() const {
        typedef typename Pointer<>::GetType<I, T, Ts...>::Type Base;
        // cerr << __FUNCTION__ << "<" << I << ">()#" << typeid(Base).name() << endl;
        return Pointer<Base>((Base*)(_pointers[I]._address), _pointers[I]._size, (Base*)(_pointers[I]._pointer), _pointers[I]._count);
    }

public:
    struct {
        void *_address;
        void *_pointer;
        int *_count;
        int _size;
    } _pointers[_ARGC];
    int *_count;
};

template<typename T>
decltype(auto) GetPointer(T *pointer, const int &size) {
    // cerr << __FUNCTION__ << "(const T *pointer)" << endl;
    return Pointer<T>(pointer, size);
}

template<typename T, typename ...Ts>
decltype(auto) GetPointer(T *pointer, Ts*...pointers) {
    // cerr << __FUNCTION__ << "(const Ts *...pointers)" << endl;
    return Pointer<T, Ts...>(pointer, pointers...);
}

////////////////////////////////////////////////////////////////////////////////

template<typename ...>
class Assembly;

template<typename T>
class Assembly<T> {
public:
    typedef class Assembly<T> Type;
    static const int _ARGC = 1;
    static const int _SIZE = sizeof(T);

public:
    Assembly(const T &element)
        :_element(element) {
        // cerr << __FUNCTION__ << endl;
    }

    Assembly(const Assembly &assembly) {
        _element = assembly._element;
        // cerr << __FUNCTION__ << endl;
    }

    Assembly &operator=(const Assembly &assembly) {
        if (this != &assembly) {
            this->~Assembly();
            _element = assembly._element;
        }
        // cerr << __FUNCTION__ << endl;
        return *this;
    }

    virtual ~Assembly() {
        // cerr << __FUNCTION__ << endl;
    }

public:
    template<const int I = 0>
    T at() {
        // cerr << __FUNCTION__ << endl;
        return _element;
    }

public:
    T _element;
};

/*PLEASE
* Es is NOT eX, emplace is Not inplace, assembly is NOT ass, B b is NOT Baby.
*/
template<typename T, typename ...Ts>
class Assembly<T, Ts...> {
public:
    typedef class Assembly<T, Ts...> Type;
    static const int _ARGC = 1 + sizeof...(Ts);
    static const int _SIZE = sizeof(T) + Assembly<Ts...>::_SIZE;

public:
    Assembly(const T &element, const Ts &...elements)
        : _pointer(_elements), _pointers{
            (_pointer + 0),
            (emplace(element, _pointer), _pointer += sizeof(T)),
            (emplace(elements, _pointer), _pointer += sizeof(Ts))
            ...
    }{
        // cerr << endl;
        // cerr << __FUNCTION__ << endl;
    }

    Assembly(const Assembly &assembly) {
        memcpy(_elements, assembly._elements, sizeof(_elements));
        memcpy(_pointers, assembly._pointers, sizeof(_pointers));
        // cerr << __FUNCTION__ << endl;
    }

    Assembly &operator=(const Assembly &assembly) {
        if (this != &assembly) {
            this->~Assembly();
            memcpy(_elements, assembly._elements, sizeof(_elements));
            memcpy(_pointers, assembly._pointers, sizeof(_pointers));
        }
        // cerr << __FUNCTION__ << endl;
        return *this;
    }

    virtual ~Assembly() {
        // cerr << __FUNCTION__ << endl;
    }

protected:
    template<typename E>
    void emplace(const E &e, char *pointer) {
        if (pointer == _elements) {
            // cerr << __FUNCTION__ << "#";
        }
        // cerr << e << " ";
        *((E*)pointer) = e;
    }

public:
    template<const int I>
    decltype(auto) at() {
        // cerr << __FUNCTION__ << endl;
        typedef typename Pointer<>::GetType<I, T, Ts...>::Type Base;
        return *((Base*)_pointers[I]);
    }

public:
    char *_pointer;
    char _elements[_SIZE];
    void *_pointers[_ARGC + 1];
};

#endif // Pointer_hpp

////////////////////////////////////////////////////////////////////////////////

// #define Main
#ifdef Main
void TestAnomaly() {
    auto anomaly = Anomaly<string, string>(true, __FILE__, __LINE__, __FUNCTION__, EType::Information, "An abnomal exception.", "Leave me alone.");
    anomaly.check();
    cerr << anomaly.issue() << endl;
    cerr << anomaly.report() << endl;
    cerr << anomaly.solution() << endl;

    Exception(true, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "To be implemented.", "Pick up me later.").check();
    // throw Exception(true, __FILE__, __LINE__, __FUNCTION__, EType::Incompleted, "To be implemented.", "Pick up me later.");
}

void TestCleanup() {
    char *ptr = new char[10];
    auto lamb = [](char *ptr) -> int {
        delete[] ptr;
        return 1;
    };
    Cleanup clean_lamb(lamb, ptr);

    int *l = new int(12);
    double *d = new double(23.0);
    Cleanup clean_ptr(EType::Delete, l, d);
}


decltype(auto) TestPointer() {
    int *l = new int(11);
    char *s = new char[12]{ 'a', 'b', 'c' };
    Pointer<int, double, char> ptr(l, new double(11.12), s);
    ptr.setLength<2>(12);
    return ptr.at<2>();
}

decltype(auto) TestAssembly() {
    Assembly<int, double, const char*> assembly(11, 12, "ass");
    return assembly.at<1>();
}


int main(int argc, char *argv[]) {
    // TestAnomaly();

    TestCleanup();

    // auto str = TestPointer();
    // cout << str << endl;

    // auto ass = TestAssembly();
    // cout << ass << endl;

    return 0;
}

#endif // Main
