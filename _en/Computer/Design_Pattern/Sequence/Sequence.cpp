/* Sequence.cpp
Author: BSS9395
Update: 2022-02-23T23:57:00+08@China-Guangdong-Zhanjiang+08
Design: Sequence
Encode: UTF-8
*/

#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>
#include <type_traits>
typedef intptr_t iptr;

template<const iptr = 0, typename ...>
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

template<>
struct Sequence<> {
public:
    static inline const iptr _Argc = 0;
    static inline const iptr _Size = 0;

public:
    Sequence() {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);
    }

    virtual ~Sequence() {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);
    }

public:
    template<typename TType>
    Sequence &operator=(const TType &type) {
        // note: do nothing.
        return (*this);
    }

public:
    template<typename TType, typename ...TTypes>
    static auto Make(const TType &type, const TTypes &...types) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        return Sequence<TType, TTypes...>(type, types...);
    }
};
static Sequence<> _Ignore = Sequence<>();


template<typename TType, typename ...TTypes>
struct Sequence<TType, TTypes...> {
public:
    static inline const iptr _Argc = 1 + sizeof...(TTypes);
    static inline const iptr _Size = sizeof(TType) + Sequence<TTypes...>::_Size;

public:
    iptr *_refer = nullptr;
    char *_objects = nullptr;

public:
    // note: [const TType &] will transform the actual type, [TType &&] will not parse the actual type.
    explicit Sequence(const TType &type, const TTypes &...types) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        // std::cout << "_Argc = " << _Argc << ", _Size = " << _Size << std::endl;
        // std::cout << "typeid(TType).name() = " << typeid(TType).name() << std::endl;
        // std::cout << "typeid(TType &).name() = " << typeid(TType &).name() << std::endl;

        _refer = new iptr(0);
        _objects = (char *)::operator new(_Size);  // note: allocate memory.
        char *address = _objects;
        char *inplace[] = {
            // note: unwind the variadic parameter types.
            (Construct(address, type), address += sizeof(TType)),
            (Construct(address, types), address += sizeof(TTypes))...
        };
        (*_refer) += 1;
    }

    Sequence(const Sequence &sequence) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        _refer = sequence._refer;
        _objects = sequence._objects;
        (*_refer) += 1;
    }

    Sequence &operator=(const Sequence &sequence) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        if (this != &sequence) {
            this->~Sequence();
            _refer = sequence._refer;
            _objects = sequence._objects;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Sequence() {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            Reverse<TType, TTypes...>(_objects);
            ::operator delete(_objects);           // note: deallocate memory.
        }
    }

public:
    template<typename TAddress>
    void Construct(char *address, const TAddress &object) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        new (address) TAddress(object);
    }

    template<typename TAddress, const iptr numb>
    void Construct(char *address, const TAddress(&objects)[numb]) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        for (iptr i = 0; i < numb; i += 1) {
            Construct(address, objects[i]), address += sizeof(TAddress);
        }
    }

    template<const iptr = 0, const iptr = 0>
    void Reverse(char *address) {  // note: do nothing.
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        return;
    }

    template<typename TAddress, typename ...TAddresses>
    void Reverse(char *address) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        // std::cout << "typeid(TAddress).name()" << typeid(TAddress).name() << std::endl;
        // std::cout << "typeid(TAddress *).name()" << typeid(TAddress *).name() << std::endl;

        Reverse<TAddresses...>(address + sizeof(TAddress));
        Destruct((TAddress *)address);
    }

    template<typename TObject>
    void Destruct(TObject *object) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        object->~TObject();
    }

    template<typename TObject, const iptr numb>
    void Destruct(TObject(*objects)[numb]) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        // std::cout << "typeid(TObject).name() = " << typeid(TObject).name() << std::endl;
        // std::cout << "typeid(objects).name() = " << typeid(objects).name() << std::endl;

        for (iptr i = numb - 1; 0 <= i; i -= 1) {
            Destruct((TObject *)&(*objects)[i]);
        }
    }

public:
    template<const iptr Idx>
    auto &At() {  // note: [auto <= auto &], reference type will automatically transform to pointer type.
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        typedef typename Proto<Idx, TType, TTypes...>::Type Type;
        const iptr offset = Proto<Idx, TType, TTypes...>::_Offset;
        // std::cout << "typeid(Type).name() = " << typeid(Type).name() << std::endl;

        return *(Type *)(_objects + offset);
    }

public:
    template<typename TRefer, typename ...TRefers>
    void Unwind(TRefer &refer, TRefers &...refers) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        char *address = _objects;
        char *inplace[] = {
            // note: unwind the variadic parameter refers.
            (Assign(&refer, (TType *)address), address += sizeof(TType)),
            (Assign(&refers, (TTypes *)address), address += sizeof(TTypes))...
        };
    }

    template<typename TRefer, typename TObject>
    static void Assign(TRefer *refer, TObject *object) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        // std::cout << "typeid(refer).name() = " << typeid(refer).name() << std::endl;
        // std::cout << "typeid(object).name() = " << typeid(object).name() << std::endl;
        (*refer) = (*object);   // note: if left type is compatible with right type.
    }

    template<typename TRefer, const iptr numb, typename TObject, const iptr size>
    static void Assign(TRefer(*refers)[numb], TObject(*objects)[size]) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        if (numb > size) {
            throw std::string("if (numb > size) {");
        }
        for (iptr i = 0; i < numb; i += 1) {
            Assign((TRefer *)&(*refers)[i], (TObject *)&(*objects)[i]);
        }
    }

public:
    template<typename TRefer, typename ...TRefers>
    void Unpack(TRefer &refer, TRefers &...refers) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        Shift(_objects, &refer, &refers...);
    }

    template<const iptr = 0, const iptr = 0>
    static void Shift(char *address) {  // note: do nothing.
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        return;
    }

    template<typename TRefer, typename ...TRefers>
    static void Shift(char *address, TRefer *refer, TRefers *...refers) {
        fprintf(stderr, "[%td] %s""\n", __LINE__, __FUNCTION__);

        Assign(refer, (TType *)address);
        Sequence<TTypes...>::Shift(address + sizeof(TType), refers...);
    }
};

////////////////////////////////////////////////////////////////////////////////

void Test_Sequence() {
    std::string str3[3] = {
        "abc",
        "def",
        "ghi"
    };

    // Sequence<int, double, const char[3], std::string[3]> sequence(12, 23.45, "ab", strs);
    auto sequence = Sequence<>::Make(12, 23.45, "ab", str3);
    auto &object = sequence.At<3>();  // note: [auto <= auto &], reference type will automatically transform to pointer type.

    std::cout << typeid(object).name() << std::endl;
    for (iptr i = 0; i < sizeof(object) / sizeof(object[0]); i += 1) {
        std::cout << object[i] << std::endl;
    }
}

void Test_Unpack() {
    std::string str3[3] = {
    "abc",
    "def",
    "ghi"
    };
    std::string str2[2];

    // Sequence<int, double, const char[3]> sequence(12, 23.45, "ab");
    auto sequence = Sequence<>::Make(12, 23.45, "ab", str3);

    int i = 0;
    double d = 0.0;
    char lite[3] = { '\0' };
    sequence.Unwind(i, _Ignore, lite, str2);
    // sequence.Unwind(i, d, lite, str2);
    // sequence.Unpack(i, d);

    std::cout << "i = " << i << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "strs = " << lite << std::endl;
    for (iptr i = 0; i < 2; i += 1) {
        std::cout << str2[i] << std::endl;
    }
}

int main(int argc, char *argv[]) {
    // Test_Sequence();
    Test_Unpack();

    return 0;
}
