/* C++_Array.cpp
Author: BSS9395
Update: 2022-01-20T01:54:00+08@China-Guangdong-Shenzhen+08
Design: dynamic array for C++
Encode: UTF-8
*/

#include <iostream>
#include <string>

typedef intptr_t iptr;

template<typename TType>
class Array {
    iptr _dimen = 0;
    iptr *_bound = nullptr;
    iptr *_const = nullptr;
    TType *_array = nullptr;
    iptr _index = 0;
    iptr *_refer = nullptr;

public:
    Array() {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        _refer = new iptr(1);
    }

    Array(const Array &array) {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        _dimen = array._dimen;
        _bound = array._bound;
        _const = array._const;
        _array = array._array;
        _index = array._index;
        _refer = array._refer;
        (*_refer) += 1;
    }

    Array &operator=(const Array &array) {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        if (this != &array) {
            _dimen = array._dimen;
            _bound = array._bound;
            _const = array._const;
            _array = array._array;
            _index = array._index;
            _refer = array._refer;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Array() {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        (*_refer) -= 1;
        if (*_refer <= 0) {
            delete[]_bound;
            delete[]_const;
            delete[]_array;
            delete _refer;
        }
    }

    template<typename ...TIptrs>
    Array(iptr bound, TIptrs ...bounds) {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        _dimen = 1 + sizeof...(bounds);
        _bound = new iptr[_dimen];
        _const = new iptr[_dimen];
        _array = new TType[(iptr)Init(0, bound, bounds...)];
        _index = 0;
        _refer = new iptr(1);
    }

    iptr Init(iptr idx, iptr bound) {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "iptr Init(iptr idx, Iptr bound) {");
        _bound[idx] = (iptr)bound;
        _const[idx] = (iptr)1;
        return (_bound[idx] * _const[idx]);
    }

    template<typename ...TIptrs>
    iptr Init(iptr idx, iptr bound, TIptrs ...bounds) {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "iptr Init(iptr idx, Iptr bound, TIptrs ...bounds) {");
        _bound[idx] = (iptr)bound;
        _const[idx] = (iptr)Init(idx + 1, bounds...);
        return (_bound[idx] * _const[idx]);
    }

public:
    // note: fresh state, copy last state.
    Array operator[](iptr idx) & {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "Array operator[](iptr idx) & {");
        if (!(_index < _dimen && 0 <= idx && idx <= _bound[_index])) {
            throw std::string("[" + std::to_string(__LINE__) + "] !(0 <= idx && idx <= _dimen)");
        }

        Array array = (*this);
        array._array = _array + idx * _const[_index];
        array._index = _index + 1;
        return array;
    }

    // note: transient state, modify last state.
    Array &operator[](iptr idx) && {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, "Array &operator[](iptr idx) && {");
        if (!(_index < _dimen && 0 <= idx && idx <= _bound[_index])) {
            throw std::string("[" + std::to_string(__LINE__) + "] !(0 <= idx && idx <= _dimen)");
        }
        _array += idx * _const[_index];
        _index += 1;
        return (*this);
    }

    // note: assign value.
    Array &operator=(const TType &value) {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        if (_index == _dimen) {
            (*_array) = value;
            return (*this);
        }
        throw std::string("[" + std::to_string(__LINE__) + "] !(_index == _dimen)""\n");
    }

    // note: retrive value.
    operator TType &() {
        //fprintf(stderr, "[%td] %s""\n", (iptr)__LINE__, __FUNCTION__);
        if (_index == _dimen) {
            return (*_array);
        }
        throw std::string("[" + std::to_string(__LINE__) + "] !(_index == _dimen)""\n");
    }
};

////////////////////////////////////////////////////////////////////////////////

int main(iptr argc, char *argv[]) {
    Array<double> arr(2, 3);
    try {
        for (iptr i = 0; i < 2; i += 1) {
            for (iptr j = 0; j < 3; j += 1) {
                arr[i][j] = 0.0 + i * 3 + j;
            }
        }

        for (iptr i = 0; i < 2; i += 1) {
            for (iptr j = 0; j < 3; j += 1) {
                fprintf(stderr, "%lf, ", (double)arr[i][j]);
            }
            fprintf(stderr, "\n");
        }
    }
    catch (const std::string &str) {
        fprintf(stderr, "%s""\n", str.data());
    }

    return 0;
}
