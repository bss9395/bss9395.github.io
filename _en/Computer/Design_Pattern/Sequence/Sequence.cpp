/* Sequence.cpp
Author: BSS9395
Update: 2022-02-21T23:46:00+08@China-Guangdong-Zhanjiang+08
Design: Sequence
Encode: UTF-8
*/


#include <iostream>
#include <string>
typedef intptr_t iptr;

struct Test {
    double _value = 0.0;
    Test(const double &value) {
        fprintf(stderr, "%s""\n", "Test(const double &value) {");
        _value = value;
    }

    Test(const Test &test) {
        fprintf(stderr, "%s""\n", "Test(const Test &test) {");
        _value = test._value;
    }

    Test &operator=(const Test &test) {
        fprintf(stderr, "%s""\n", "Test &operator=(const Test &test) {");
        if (this != &test) {
            this->~Test();
            _value = test._value;
        }
        return (*this);
    }

    ~Test() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
    }
};

////////////////////////////////////////////////////////////////////////////////

template<const iptr Idx, typename ...>
struct Proto;

template<typename TType, typename ...TTypes>
struct Proto<0, TType, TTypes...> {
    typedef typename TType Type;
    static inline const iptr _Offset = 0;
};

template<const iptr Idx, typename TType, typename ...TTypes>
struct Proto<Idx, TType, TTypes...> {
    typedef typename Proto<Idx - 1, TTypes...>::Type Type;
    static inline const iptr _Offset = sizeof(TType) + Proto<Idx - 1, TTypes...>::_Offset;
};

////////////////////////////////////////////////////////////////////////////////

template<typename ...>
struct Sequence;

template<typename TType>
struct Sequence<TType> {
public:
    static inline const iptr _Argc = 1;
    static inline const iptr _Size = sizeof(TType);

    //    TType _value = TType();
    //
    //public:
    //    explicit Sequence(const TType &value) {
    //        fprintf(stderr, "%s""\n", "explicit Sequence(const TType &value) {");
    //        _value = value;
    //    }
    //
    //    explicit Sequence(const Sequence &sequence) {
    //        fprintf(stderr, "%s""\n", "explicit Sequence(const Sequence &sequence) {");
    //        _value = sequence._value;
    //    }
    //
    //    Sequence &operator=(const Sequence &sequence) {
    //        fprintf(stderr, "%s""\n", "Sequence &operator=(const Sequence &sequence) {");
    //        if (this != &sequence) {
    //            this->~Sequence();
    //            _value = sequence._value;
    //        }
    //        return (*this);
    //    }
    //
    //    virtual ~Sequence() {
    //        fprintf(stderr, "%s""\n", "virtual ~Sequence() {");
    //    }
    //
    //public:
    //    template<const iptr Idx = 0>
    //    TType &At() {
    //        return _value;
    //    }
};

template<typename TType, typename ...TTypes>
struct Sequence<TType, TTypes...> {
public:
    //struct Class {
    //    virtual ~Class() {
    //        fprintf(stderr, "%s""\n", __FUNCTION__);
    //    }
    //};

public:
    static inline const iptr _Argc = 1 + sizeof...(TTypes);
    static inline const iptr _Size = sizeof(TType) + Sequence<TTypes...>::_Size;

public:
    iptr *_refer = nullptr;
    char *_values = nullptr;;

public:
    explicit Sequence(const TType &value, const TTypes &...values) {
        fprintf(stderr, "%s""\n", "explicit Sequence(const TType &value, const TTypes &values) {");
        _refer = new iptr(0);
        _values = new char[_Size];
        char *address = _values;
        char *inplace[] = {
            (new (address) TType(value), address += sizeof(TType)),
            (new (address) TTypes(values), address += sizeof(TTypes))...
        };

        char *_address = _values;
        char *_inplace[] = {
            //(((Test *)address)->~Test(), address += sizeof(TType)),
            //(((TTypes *)address)->~TTypes(), address += sizeof(TTypes))...
            (Destruct((TType *)_address), _address += sizeof(TType)),
            (Destruct((TTypes *)_address),  _address += sizeof(TTypes))...
        };

        (*_refer) += 1;
    }

    template<typename TPointer>
    void Destruct(TPointer *pointer) {
        pointer->~TPointer();
    }

    //Sequence(const Sequence &sequence) {
    //    fprintf(stderr, "%s""\n", "Sequence(const Sequence &sequence) {");
    //
    //}
    //
    //Sequence &operator=(const Sequence &sequence) {
    //    fprintf(stderr, "%s""\n", "Sequence &operator=(const Sequence &sequence) {");
    //
    //}

    ~Sequence() {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            char *address = _values;
            char *inplace[] = {
                //(((Test *)address)->~Test(), address += sizeof(Test)),
                //(((Test *)address)->~Test(), address += sizeof(Test)),
                //(((Test *)address)->~Test(), address += sizeof(Test))

                //(((TType *)address)->~TType(), address += sizeof(TType)),
                //(((TTypes *)address)->~TTypes(), address += sizeof(TTypes))...

                (address += sizeof(TType)),
                (address += sizeof(TTypes))...
            };
            for (iptr i = 0; i < _Argc; i += 1) {
                // ((Class *)(inplace[i]))->~Class();
            }

            delete _values;
        }
    }

public:
    template<const iptr Idx>
    auto At() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        typedef typename Proto<Idx, TType, TTypes...>::Type Type;
        iptr offset = Proto<Idx, TType, TTypes...>::_Offset;
        return *(Type *)((char *)_values + offset);
    }

};

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    Test test1(1.1);
    Test test2(2.2);
    Test test3(3.3);
    Sequence<Test, Test, Test> sequence(test1, test2, test3);
    //Test test = sequence.At<2>();
    //std::cout << test._value << std::endl;

    return 0;
}
