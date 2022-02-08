/* Property.cpp
Author: BSS9395
Update: 2022-02-08T16:24:00+08@China-Guangdong-Zhanjiang+08
Design: three states boolean type
Encode: UTF-8
*/

#include <iostream>
#include <string>
#include <functional>

template<typename TType>
class Property {
public:
    typedef std::function<void(void)> Function;

public:
    TType _value = TType();
    Function _function = Function();
    bool _once = false;

public:
    Property(const TType &value = TType(), const Function &function = Function()) {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        _value = value;
        _function = function;
    }

    TType &operator=(const TType &value) {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        _value = value;
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _function();
        }
        _once = false;
        return _value;
    }

    operator TType &() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        return _value;
    }
};


typedef const char *Bool;
static inline const Bool _None = "None";
static inline const Bool _Posi = "Posi";
static inline const Bool _Nega = "Nega";

template<>
class Property<Bool> {
public:
    typedef std::function<void(void)> Function;

public:
    Bool _value = _None;
    Function _function = Function();
    bool _once = false;

public:
    Property(const Bool &value = _None, const Function &function = Function()) {
        fprintf(stderr, "%s""\n", "Property(const Bool &value = _None, const Function &function = Function()) {");
        _value = value;
        _function = function;
    }

    Property(const bool &value = bool(), const Function &function = Function()) {
        fprintf(stderr, "%s""\n", "Property(const bool &value = bool(), const Function &function = Function()) {");
        _value = (value == true) ? _Posi : _Nega;
        _function = function;
    }

    Bool &operator=(const Bool &value) {
        fprintf(stderr, "%s""\n", "Bool &operator=(const Bool &value) {");
        _value = value;
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _function();
        }
        _once = false;
        return _value;
    }

    Bool &operator=(const bool &value) {
        fprintf(stderr, "%s""\n", "Bool &operator=(const bool &value) {");
        _value = (value == true) ? _Posi : _Nega;
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _function();
        }
        _once = false;
        return _value;
    }

    operator Bool &() {
        fprintf(stderr, "%s""\n", __FUNCTION__);
        return _value;
    }
};

struct Lang {
    static inline std::string _member = "abc";

    Property<double> _value = Property<double>(0.0, [this]() {
        fprintf(stderr, "%s""\n", "Property<double> _value = Property<double>(0.0, [this]() {");
        _value = 456.789;
        _member = "def";
    });

    void Assign() {
        _value = 123.456;

        std::cout << _value << std::endl;
        fprintf(stderr, "%lf""\n", (double)(_value));
    }
};

int main(int argc, char *argv[]) {
    Lang lang;
    lang.Assign();

    return 0;
}
