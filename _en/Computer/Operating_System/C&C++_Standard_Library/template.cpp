/* template.cpp
Author: BSS9395
Update: 2022-02-22T23:45:00+08@China-Guangdong-Zhanjiang+08
Design: C++ Template
Encode: UTF-8
*/

#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>
typedef intptr_t iptr;

template<typename TType>
struct Emplace {
public:
    char buffer[sizeof(TType)];

public:
    // note: [const TType &] will transform the actual type, [TType &&] will not parse the actual type.
    explicit Emplace(const TType &type) {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        std::cout << "typeid(TType).name() = " << typeid(TType).name() << std::endl;
        std::cout << "typeid(TType &).name() = " << typeid(TType &).name() << std::endl;

        Construct((char *)buffer, type);
    }

    virtual ~Emplace() {
        fprintf(stderr, "%s""\n", __FUNCTION__);

        std::cout << "typeid(TType).name() = " << typeid(TType).name() << std::endl;
        std::cout << "typeid(TType *).name() = " << typeid(TType *).name() << std::endl;

        Destruct((TType *)buffer);
    }

public:
    template<typename TObject>
    void Construct(char *address, const TObject &object) {
        fprintf(stderr, "%s""\n", "void Construct(char *address, const TObject &object) {");

        new (address) TObject(object); // note: construct object, not copy object from memory to memory. 
    }

    template<typename TArray, const iptr numb>
    void Construct(char *address, const TArray(&array)[numb]) {
        fprintf(stderr, "%s""\n", "void Construct(char *address, const TArray(&array)[numb]) {");

        for (iptr i = 0; i < numb; i += 1) {
            Construct((char *)address, array[i]);
            address += sizeof(TArray);
        }
    }

    template<typename TObject>
    void Destruct(TObject *object) {
        fprintf(stderr, "%s""\n", "void Destruct(TObject *object) {");

        object->~TObject();
    }

    template<typename TArray, const iptr numb>
    void Destruct(TArray(*array)[numb]) {
        fprintf(stderr, "%s""\n", "void Destruct(TArray(*array)[numb]) {");

        std::cout << "typeid(TArray).name() = " << typeid(TArray).name() << std::endl;
        std::cout << "typeid(array).name() = " << typeid(array).name() << std::endl;

        for (iptr i = numb - 1; 0 <= i; i -= 1) {  // note: the order of destruction is the reversed order of construction.
            Destruct((TArray *)&(*array)[i]);
        }
    }
};

int main(int argc, char *argv[]) {
    std::string abc[3] = {
        "abc",
        "def",
        "ghi"
    };

    Emplace<std::string[3]> func(abc);
    // Emplace<const char[7]> func("abcdef");

    return 0;
}
