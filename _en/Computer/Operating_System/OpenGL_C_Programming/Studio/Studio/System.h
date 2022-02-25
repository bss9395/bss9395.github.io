/* System.h
Author: BSS9395
Update: 2022-02-26T00:27:00+08@China-Guangdong-Zhanjiang+08
Design: Studio for OpenGL
Encode: UTF-8
*/

#ifndef System_h
#define System_h

#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <functional>

////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef size_t   uptr;
typedef wchar_t  wide;
////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef size_t   uptr;
typedef wchar_t  wide;

typedef const char* Bool;
static inline const Bool _None = "None";
static inline const Bool _Posi = "Posi";
static inline const Bool _Nega = "Nega";

////////////////////////////////////////////////////////////////////////////////

// note: the difference of two addresses can exceed the range of iptr type, although it's impossible.
#define Index_Class(Object, _member)   (((uptr)&((Object *)0)->_member - (uptr)0) / (uptr)sizeof(((Object *)0)->_member))
#define Index_Object(object, _member)  (((uptr)&object._member - (uptr)&object)   / (uptr)sizeof(object._member))
#define Offset_Class(Object, _member)   ((uptr)&((Object *)0)->_member - (uptr)0)
#define Offset_Object(object, _member)  ((uptr)&object._member - (uptr)&object)

////////////////////////////////////////////////////////////////////////////////

struct System {
    static inline iptr _Success = 0;
    static inline iptr _Failure = 1;
    static inline iptr _Deprecated = 2;

    typedef const char* Level;
    static inline const Level _Info = "Info";
    static inline const Level _Note = "Note";
    static inline const Level _Warn = "Warn";
    static inline const Level _Error = "Error";
    static inline const Level _Fatal = "Fatal";

    ////////////////////////////////////

    static iptr Log(iptr line, const char* format, ...) {
        fprintf(stderr, "[%td] ", line);

        va_list list;
        va_start(list, format);
        vfprintf(stderr, format, list);
        va_end(list);

        fprintf(stderr, "%ls", L";\n");
        fflush(stderr);
        return line;
    }
#define Logging(...) Log(__LINE__, __VA_ARGS__)

    static bool Check(bool failed, Level level, const char* file, iptr line, const char* function, const char* record, const char* extra, ...) {
        // Logging(__FUNCTION__);
        if (failed == true) {
            const char* sepa = NULL;
            (sepa = strrchr(file, '/')) || (sepa = strrchr(file, '\\'));
            fprintf(stderr, "[%s : %s : %td : %s] %s", (char*)level, (sepa == NULL) ? file : (sepa + 1), (iptr)line, function, record);

            if (extra != NULL) {
                fprintf(stderr, " : ");
                va_list list;
                va_start(list, extra);
                vfprintf(stderr, extra, list);
                va_end(list);
            }

            fprintf(stderr, ";\n");
            fflush(stderr);
        }
        return failed;
    }
#define Checking(failed, level, ...) Check(failed, level, __FILE__, __LINE__, __FUNCTION__, ""#failed, __VA_ARGS__)
};

////////////////////////////////////////////////////////////////////////////////

struct Format {
    template<typename TType>
    static TType Functor(TType type) {
        return type;
    }

    template<typename TBuffer = std::string>
    static TBuffer& Buffer(const iptr capacity = 1024, const iptr shrink = 2048) {
        // Logging(__FUNCTION__);
        static TBuffer buffer = TBuffer(capacity, 0);
        if ((iptr)buffer.capacity() > shrink) {
            buffer.shrink_to_fit();
        }
        if ((iptr)buffer.capacity() < capacity) {
            buffer.reserve(capacity);
        }
        return buffer;
    }

#define None
#define Print_Member(Member, TBuffer)                                                                                                            \
    [](const auto &container, TBuffer &buffer = Format::Buffer<std::string>(1024, 2048), const TBuffer &sepa = std::string(", ")) -> TBuffer & { \
        buffer.clear();                                                                                                                          \
        if (0 < container.size()) {                                                                                                              \
            auto beg = container.begin(), end = container.end();                                                                                 \
            for (buffer += (*beg)Member, beg++; beg != end; buffer += sepa, buffer += (*beg)Member, beg++);                                      \
        }                                                                                                                                        \
        return buffer;                                                                                                                           \
    }                                                                                                                                            \
// Leave Blank Space
#define Lambda_Print(Member, TBuffer) Functor(Print_Member(Member, TBuffer))    // note: here Function wrapper is necessary.
    static inline const auto Print = Functor(Print_Member(None, std::string));  // note: here Function wrapper is unnecessary.
};

////////////////////////////////////////////////////////////////////////////////

template<typename TType>
class Property {
public:
    typedef std::function<void(void)> Functor;

    TType _value;
    Functor _function;
    bool _once = false;

public:
    Property(const TType& value = TType(), const Functor& function = Functor()) {
        // System::Logging(__FUNCTION__);
        _value = value;
        _function = function;
    }

    TType& operator=(const TType& value) {
        // System::Logging(__FUNCTION__);
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = value;
            _function();
        }
        _once = false;
        return _value;
    }

    operator TType& () {
        // System::Logging(__FUNCTION__);
        return _value;
    }
};

template<>
class Property<Bool> {
public:
    typedef std::function<void(void)> Functor;

public:
    Bool _value = _None;
    Functor _function = Functor();
    bool _once = false;

public:
    Property(const Bool& value = _None, const Functor& function = Functor()) {
        // System::Logging("Property(const Bool &value = _None, const Function &function = Function()) {");
        _value = value;
        _function = function;
    }

    Property(const bool& value = bool(), const Functor& function = Functor()) {
        // System::Logging("Property(const bool &value = bool(), const Function &function = Function()) {");
        _value = (value == true) ? _Posi : _Nega;
        _function = function;
    }

    Bool& operator=(const Bool& value) {
        // System::Logging("Bool &operator=(const Bool &value) {");
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = value;
            _function();
        }
        _once = false;
        return _value;
    }

    Bool& operator=(const bool& value) {
        // System::Logging("Bool &operator=(const bool &value) {");
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _value = (value == true) ? _Posi : _Nega;
            _function();
        }
        _once = false;
        return _value;
    }

    operator Bool& () {
        // System::Logging(__FUNCTION__);
        return _value;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Clean {
public:
    typedef std::function<void(void)> Functor;
    typedef const char* Done;
    static inline const Done _Hitted = "Hitted";
    static inline const Done _Missed = "Missed";

public:
    struct Class {
        virtual ~Class() {

        }
    };
    static inline std::set<std::vector<Class*>*> _Set;

public:
    iptr* _refer = nullptr;
    Functor* _function = nullptr;
    std::vector<Class*>* _pointers = nullptr;

public:
    Clean() {
        System::Logging("Clean() {");

        _refer = new iptr(0);
        (*_refer) += 1;
    }

    Clean(const Functor& function) {
        System::Logging("Clean(const Function &function) {");

        _refer = new iptr(0);
        _function = new Functor(function);
        (*_refer) += 1;
    }

    Clean(const Clean& clean) {
        System::Logging("Clean(const Clean &clean) {");

        _refer = clean._refer;
        _function = clean._function;
        _pointers = clean._pointers;
        (*_refer) += 1;
    }

    Clean& operator=(const Clean& clean) {
        System::Logging("Clean &operator=(const Clean &clean) {");

        if (this != &clean) {
            this->~Clean();
            _refer = clean._refer;
            _function = clean._function;
            _pointers = clean._pointers;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Clean() {
        System::Logging(__FUNCTION__);

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
                    for (iptr i = 0, size = (*_pointers).size(); i < size; i += 1) {
                        delete (*_pointers)[i];
                    }
                }
                Clean::_Set.erase(_pointers);
                delete _pointers;
            }
        }
    }

public:
    Clean& Auto_Pointer(void* pointer) {
        System::Logging(__FUNCTION__);

        if (_pointers == nullptr) {
            _pointers = new std::vector<Class*>();
            Clean::_Set.insert(_pointers);
        }
        _pointers->push_back((Class*)pointer);
        return (*this);
    }

    Done Clean_Pointer(void* pointer) {
        System::Logging(__FUNCTION__);

        if (_pointers != nullptr && 0 < (*_pointers).size()) {
            for (iptr i = 0, size = (*_pointers).size(); i < size; i += 1) {
                if ((*_pointers)[i] == pointer) {
                    delete (*_pointers)[i];
                    (*_pointers)[i] = nullptr;
                    return _Hitted;
                }
            }
        }
        return _Missed;
    }
};

////////////////////////////////////////////////////////////////////////////////

template<typename TRecord, typename TSolution> class Anomaly;
class Exception : public std::exception {
public:
    virtual std::string& Report() {
        static std::string report = std::string(__FUNCTION__);
        return report;
    }

    [[deprecated("obsolete function what(), use Report() instead.")]]
    virtual const char* what() const noexcept override final {
        System::Check(true, System::_Info, __FILE__, __LINE__, __FUNCTION__, "obsolete function what()", " use Report() instead.");
        exit((int)System::_Deprecated);
    }

public:
    template<typename TRecord = std::string, typename TSolution = std::string>
    static bool Except(bool failed, System::Level level, const std::string& file, iptr line, const std::string& function, const TRecord& record, const TSolution& solution = TSolution()) {
        if (failed == true) {
            throw Anomaly(level, file, line, function, record, solution);
        }
        return failed;
    }
#define Excepting(failed, level, record, solution)    Except(failed, level, __FILE__, __LINE__, __FUNCTION__, record, solution)
};

template<typename TRecord = std::string, typename TSolution = std::string>
class Anomaly : public Exception {
public:
    iptr* _refer = nullptr;
    struct Datum {
        System::Level _level = System::Level();
        std::string _file = "";
        iptr _line = 0;
        std::string _function = "";
        TRecord _record = TRecord();
        TSolution _solution = TSolution();
    } *_datum = nullptr;

public:
    Anomaly(System::Level level, const std::string& file, iptr line, const std::string& function, const TRecord& record, const TSolution& solution = TSolution()) {
        System::Logging(__FUNCTION__);
        _refer = new iptr(0);
        _datum = new Datum();
        _datam->_level = level;
        _datum->_file = file;
        _datum->_line = line;
        _datum->_function = function;
        _datum->_record = record;
        _datum->_solution = solution;
        (*_refer) += 1;
    }

    Anomaly(System::Level level, const std::string& file, iptr line, const std::string& function, const char* record, const char* solution = "") {
        System::Logging(__FUNCTION__);

        _refer = new iptr(0);
        _datum = new Datum();
        _datam->_level = level;
        _datum->_file = file;
        _datum->_line = line;
        _datum->_function = function;
        _datum->_record = record;
        _datum->_solution = solution;
        (*_refer) += 1;
    }

    Anomaly(const Anomaly& anomaly) {
        System::Logging(__FUNCTION__);

        _refer = anomaly._refer;
        _datum = anomaly._datum;
        (*_refer) += 1;
    }

    Anomaly& operator=(const Anomaly& anomaly) {
        System::Logging(__FUNCTION__);

        if (this != &anomaly) {
            this->~Anomaly();
            _refer = anomaly._refer;
            _datum = anomaly._datum;
            (*_refer) += 1;
        }
        return (*this);
    }

    virtual ~Anomaly() {
        System::Logging(__FUNCTION__);
        (*_refer) -= 1;
        if ((*_refer) <= 0) {
            delete _refer;
            delete _datum;
        }
    }

public:
    virtual std::string& Report() override {
        // System::Logging(__FUNCTION__);
        std::string report = ""; report.reserve(512);

        iptr sepa = -1;
        ((sepa = _file.find_last_of('/')) == -1) && (sepa = _file.find_last_of('\\'));
        report += std::string(&_file[sepa + 1]);
        report += _record, report += " : ";
        report += _solution, report += ";";
        return report;
    }
};

////////////////////////////////////////////////////////////////////////////////

class Configuration {
public:
    static iptr Configure() {
        System::Logging(__FUNCTION__);

        iptr ret = 0;

        // ".936" for windows, "zh_CN.GBK" for linux.
        if ((char*)setlocale(LC_ALL, "") == NULL) {
            System::Logging("%s", "invalid locale");
            exit((int)System::_Failure);
        }
        ret += 1;

        System::Logging("timestamp = %s", __TIMESTAMP__);
        ret += 1;

        return ret;
    }
    static inline iptr _configure = Configure();
};

#endif // System_h
