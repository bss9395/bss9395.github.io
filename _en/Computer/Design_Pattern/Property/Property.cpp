/* Property.cpp
Author: BSS9395
Update: 2022-02-08T16:24:00+08@China-Guangdong-Zhanjiang+08
Design: class member as property
Encode: UTF-8
*/

#include <iostream>
#include <string>
#include <functional>

template<typename TType>
class Property {
public:
    typedef TType Type;
    typedef std::function<void(void)> Function;

    TType _value;
    Function _function;
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

struct Lang {
    Property<double> _value = Property<double>(0.0, [this]() {
        fprintf(stderr, "%s""\n", "Property<double> _value = Property<double>(0.0, [this]() {");
        _value = 456.789;
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
