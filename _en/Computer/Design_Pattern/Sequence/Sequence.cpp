/* Sequence.cpp
Author: BSS9395
Update: 2022-02-23T17:30:00+08@China-Guangdong-Zhanjiang+08
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

private:
    Sequence() {
        fprintf(stderr, "%s""\n", "Sequence() {");
    }

    virtual ~Sequence() {
        fprintf(stderr, "%s""\n", "virtual ~Sequence() {");
    }

public:
    template<typename TType, typename ...TTypes>
    static auto Make(const TType &type, const TTypes &...types) {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        return Sequence<TType, TTypes...>(type, types...);
    }
};

template<typename TType, typename ...TTypes>
struct Sequence<TType, TTypes...> {
public:
    static inline const iptr _Argc = 1 + sizeof...(TTypes);
    static inline const iptr _Size = sizeof(TType) + Sequence<TTypes...>::_Size; // note: it doesn't actually construct class.

public:
    iptr *_refer = nullptr;
    char *_objects = nullptr;

public:
    // note: [const TType &] will transform the actual type, [TType &&] will not parse the actual type.
    explicit Sequence(const TType &type, const TTypes &...types) {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        // std::cout << "_Argc = " << _Argc << ", _Size = " << _Size << std::endl;
        // std::cout << "typeid(TType).name() = " << typeid(TType).name() << std::endl;
        // std::cout << "typeid(TType &).name() = " << typeid(TType &).name() << std::endl;

        _refer = new iptr(0);
        _objects = (char *)::operator new(_Size);  // note: allocate memory.
        char *address = _objects;
        char *inplace[] = {
            (Construct(address, type), address += sizeof(TType)),
            (Construct(address, types), address += sizeof(TTypes))...
        };
        (*_refer) += 1;
    }

    Sequence(const Sequence &sequence) {
        fprintf(stderr, "%s""\n", "Sequence(const Sequence &sequence) {");

        _refer = sequence._refer;
        _objects = sequence._objects;
        (*_refer) += 1;
    }

    Sequence &operator=(const Sequence &sequence) {
        fprintf(stderr, "%s""\n", "Sequence &operator=(const Sequence &sequence) {");

        if (this != &sequence) {
            this->~Sequence();
            _refer = sequence._refer;
            _objects = sequence._objects;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Sequence() {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            Reverse<TType, TTypes...>(_objects);
            ::operator delete(_objects);           // note: deallocate memory.
        }
    }

public:
    template<typename TObject>
    void Construct(char *address, const TObject &object) {
        fprintf(stderr, "%s""\n", "void Construct(char *address, const TObject &object) {");

        new (address) TObject(object);
    }

    template<typename TArray, const iptr numb>
    void Construct(char *address, const TArray(&array)[numb]) {
        fprintf(stderr, "%s""\n", "void Construct(char *address, const TArray(&array)[numb]) {");

        for (iptr i = 0; i < numb; i += 1) {
            Construct(address, array[i]), address += sizeof(TArray);
        }
    }

    template<const iptr Idx = 0>
    void Reverse(char *address) {
        // fprintf(stderr, "%s""\n", "void Reverse(char *address) {");

        return;
    }

    template<typename TAddress, typename ...TAddresses>
    void Reverse(char *address) {
        fprintf(stderr, "%s""\n", "void Reverse(char *address) {");

        // std::cout << "typeid(TAddress).name()" << typeid(TAddress).name() << std::endl;
        // std::cout << "typeid(TAddress *).name()" << typeid(TAddress *).name() << std::endl;

        Reverse<TAddresses...>(address + sizeof(TAddress));
        Destruct((TAddress *)address);
    }

    template<typename TAddress>
    void Destruct(TAddress *address) {
        fprintf(stderr, "%s""\n", "void Destruct(TAddress *address) {");

        address->~TAddress();
    }

    template<typename TArray, const iptr numb>
    void Destruct(TArray(*array)[numb]) {
        fprintf(stderr, "%s""\n", "void Destruct(TArray(*array)[numb]) {");

        // std::cout << "typeid(TArray).name() = " << typeid(TArray).name() << std::endl;
        // std::cout << "typeid(array).name() = " << typeid(array).name() << std::endl;

        for (iptr i = numb - 1; 0 <= i; i -= 1) {
            Destruct((TArray *)&(*array)[i]);
        }
    }

public:
    template<const iptr Idx>
    auto &At() {  // note: [auto <= auto &], reference type will automatically transform to pointer type.
        fprintf(stderr, "%s""\n", __FUNCTION__);

        typedef typename Proto<Idx, TType, TTypes...>::Type Type;
        const iptr offset = Proto<Idx, TType, TTypes...>::_Offset;
        // std::cout << "typeid(Type).name() = " << typeid(Type).name() << std::endl;

        return *(Type *)(_objects + offset);
    }
};



int main(int argc, char *argv[]) {
    std::string strs[3] = {
        "abc",
        "def",
        "ghi"
    };

    // Sequence<int, double, const char[3], std::string[3]> sequence(12, 23.45, "ab", strs);
    auto sequence = Sequence<>::Make(12, 23.45, "ab", strs);
    auto &object = sequence.At<3>();  // note: [auto <= auto &], reference type will automatically transform to pointer type.

    std::cout << typeid(object).name() << std::endl;
    for (iptr i = 0; i < sizeof(object) / sizeof(object[0]); i += 1) {
        std::cout << object[i] << std::endl;
    }

    return 0;
}
