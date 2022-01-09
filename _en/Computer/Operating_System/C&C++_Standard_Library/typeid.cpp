/* typeid.cpp
Author: bss9395
Update: 2022-01-09T23:08:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Keyword: typeid
Encode: UTF-8
*/

/*
#include <typeinfo>
std::type_info::name;
const char* name() const noexcept;
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <functional>
#include <typeinfo>

typedef intptr_t iptr;
typedef const char *Level;

template<typename TRecord = std::string, typename TSolution = std::string>
class Exception : public std::exception {
public:
    Level _level = Level();
    std::string _file = std::string();
    iptr _line = 0;
    std::string _function = std::string();
    TRecord _record = TRecord();
    TSolution _solution = TSolution();
    std::string _report = std::string();

public:
    Exception(Level level, const std::string &file, iptr line, const std::string &function, const TRecord &record, const TSolution &solution = TSolution())
        : _level(level), _file(file), _line(line), _function(function), _record(record), _solution(solution) {
        // fprintf(stderr, "[%td] %s"";\n", (iptr)__LINE__, __FUNCTION__); fflush(stderr);

        fprintf(stderr, "[%td] typeid(record).name() = %s""\n", (iptr)__LINE__, typeid(record).name());
    }

    Exception(Level level, const std::string &file, iptr line, const std::string &function, const char *record, const char *solution = "")
        : _level(level), _file(file), _line(line), _function(function), _record(record), _solution(solution) {
        // fprintf(stderr, "[%td] %s"";\n", (iptr)__LINE__, __FUNCTION__); fflush(stderr);

        fprintf(stderr, "[%td] typeid(record).name() = %s""\n", (iptr)__LINE__, typeid(record).name());
    }

    virtual ~Exception() {
        // fprintf(stderr, "[%td] %s"";\n", (iptr)__LINE__, __FUNCTION__); fflush(stderr);
    }

public:
    virtual std::string &Report() {
        _report.reserve(512);
        iptr numb = snprintf(&_report[0], _report.capacity(), "[%s : %s : %td : %s] ", _level, &_file[(iptr)(_file.find_last_of("/\\")) + 1], _line, &_function[0]);
        _report.resize(numb);
        _report += _record, _report += " : ";
        _report += _solution, _report += ";";
        return _report;
    }

    virtual const char *what() const noexcept override {
        (*(Exception *)this).Report(); // discard const qualifier.
        return &_report[0];
    }
};


int main(int argc, char *argv[]) {
    try {
        if (true) {
            throw Exception("Debug", __FILE__, __LINE__, __FUNCTION__, "record", "solution");
        }
    }
    catch (std::exception &except) {
        fprintf(stderr, "%s""\n", except.what());
    }

    return 0;
}
