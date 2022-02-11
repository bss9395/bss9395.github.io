/* System.h
Author: BSS9395
Update: 2022-02-08T17:48:00+08@China-Guangdong-Zhanjiang+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef System_h
#define System_h

#define   Header_h
#include "Common.h"

////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef size_t   uptr;
typedef wchar_t  wide;

typedef const char *Bool;
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

    typedef const char *Level;
    static inline const Level _Info = "Info";
    static inline const Level _Note = "Note";
    static inline const Level _Warn = "Warn";
    static inline const Level _Error = "Error";
    static inline const Level _Fatal = "Fatal";

    ////////////////////////////////////

    static iptr Logging(iptr line, const char *format, ...) {
        fprintf(stderr, "[%td] ", line);

        va_list list;
        va_start(list, format);
        vfprintf(stderr, format, list);
        va_end(list);

        fprintf(stderr, "%ls", L";\n");
        fflush(stderr);
        return line;
    }
#define Logging(...) Logging(__LINE__, __VA_ARGS__)

    static bool Checking(bool failed, Level level, const char *file, iptr line, const char *function, const char *record, const char *extra, ...) {
        // Logging(__FUNCTION__);
        if (failed == true) {
            const char *sepa = NULL;
            (sepa = strrchr(file, '/')) || (sepa = strrchr(file, '\\'));
            fprintf(stderr, "[%s : %s : %td : %s] %s", (char *)level, (sepa == NULL) ? file : (sepa + 1), (iptr)line, function, record);

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
#define Checking(failed, level, record, ...) Checking(failed, level, __FILE__, __LINE__, __FUNCTION__, record, __VA_ARGS__)
};

////////////////////////////////////////////////////////////////////////////////

struct Format {
    template<typename TType>
    static TType Function(TType type) {
        return type;
    }

    template<typename TBuffer = QString>
    static TBuffer &Buffer(const iptr capacity = 1024, const iptr shrink = 2048) {
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

#define Print_Member(Member, TBuffer)                                                                                                    \
    [](const auto &container, TBuffer &buffer = Format::Buffer<QString>(1024, 2048), const TBuffer &sepa = QString(", ")) -> TBuffer & { \
        buffer.clear();                                                                                                                  \
        if (0 < container.size()) {                                                                                                      \
            auto beg = container.begin(), end = container.end();                                                                         \
            for (buffer += (*beg)Member, beg++; beg != end; buffer += sepa, buffer += (*beg)Member, beg++);                              \
        }                                                                                                                                \
        return buffer;                                                                                                                   \
    }                                                                                                                                    \
// Leave Blank Space
#define Lambda_Print(Member, TBuffer) Function(Print_Member(Member, TBuffer)) // note: here Function wrapper is necessary.
    static inline const auto Print = Function(Print_Member(, QString));       // note: here Function wrapper is unnecessary.
};

////////////////////////////////////////////////////////////////////////////////

template<typename TType>
class Property {
public:
    typedef std::function<void(void)> Function;

    TType _value;
    Function _function;
    bool _once = false;

public:
    Property(const TType &value = TType(), const Function &function = Function()) {
        // System::Logging(__FUNCTION__);
        _value = value;
        _function = function;
    }

    TType &operator=(const TType &value) {
        // System::Logging(__FUNCTION__);
        _value = value;
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _function();
        }
        _once = false;
        return _value;
    }

    operator TType &() {
        // System::Logging(__FUNCTION__);
        return _value;
    }
};

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
        // System::Logging("Property(const Bool &value = _None, const Function &function = Function()) {");
        _value = value;
        _function = function;
    }

    Property(const bool &value = bool(), const Function &function = Function()) {
        // System::Logging("Property(const bool &value = bool(), const Function &function = Function()) {");
        _value = (value == true) ? _Posi : _Nega;
        _function = function;
    }

    Bool &operator=(const Bool &value) {
        // System::Logging("Bool &operator=(const Bool &value) {");
        _value = value;
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _function();
        }
        _once = false;
        return _value;
    }

    Bool &operator=(const bool &value) {
        // System::Logging("Bool &operator=(const bool &value) {");
        _value = (value == true) ? _Posi : _Nega;
        if (_once == false) {
            _once = true;    // note: call once at a time.
            _function();
        }
        _once = false;
        return _value;
    }

    operator Bool &() {
        // System::Logging(__FUNCTION__);
        return _value;
    }
};

////////////////////////////////////////////////////////////////////////////////

template<typename TRecord, typename TSolution> class Anomaly;
class Exception : public QException {
public:
    QString _report = QString();

public:
    virtual QString &Report() {
        return _report;
    }

    [[ deprecated("obsolete function what(), use Report() instead.") ]]
    virtual const char *what() const noexcept override final {
        System::Checking(true, System::_Info, "obsolete function what()", " use Report() instead.");
        exit(System::_Deprecated);
    }

public:
    template<typename TRecord = QString, typename TSolution = QString>
    static bool Excepting(bool failed, System::Level level, const QString &file, iptr line, const QString &function, const TRecord &record, const TSolution &solution = TSolution()) {
        if(failed == true) {
            throw Anomaly(level, file, line, function, record, solution);
        }
        return failed;
    }
#define Excepting(failed, level, record, solution) Excepting(failed, level, __FILE__, __LINE__, __FUNCTION__, record, solution)
};

template<typename TRecord = QString, typename TSolution = QString>
class Anomaly : public Exception {
public:
    System::Level _level = System::Level();
    QString _file = "";
    iptr _line = 0;
    QString _function = "";
    TRecord _record = TRecord();
    TSolution _solution = TSolution();

public:
    Anomaly(System::Level level, const QString &file, iptr line, const QString &function, const TRecord &record, const TSolution &solution = TSolution())
        : _level(level), _file(file), _line(line), _function(function), _record(record), _solution(solution) {
        // Logging(R"(Exception(System::Level level, const QString &file, iptr line, const QString &function, const TRecord &record, const TSolution &solution = TSolution()))");
    }

    Anomaly(System::Level level, const QString &file, iptr line, const QString &function, const char *record, const char *solution = "")
        : _level(level), _file(file), _line(line), _function(function), _record(record), _solution(solution) {
        // Logging(R"(Exception(System::Level level, const QString &file, iptr line, const QString &function, const char *record, const char *solution = ""))");
    }

    virtual ~Anomaly() {
        System::Logging(__FUNCTION__);
    }

public:
    virtual QString &Report() override {
        // Logging(__FUNCTION__);
        _report.reserve(512);
        int sepa = 0;
        ((sepa = _file.lastIndexOf('/')) < 0) && (sepa = _file.lastIndexOf('\\'));
        _report += QString("[%1 : %2 : %3 : %4] ").arg(_level).arg(_file.mid(sepa + 1)).arg(_line).arg(_function);
        _report += _record, _report += " : ";
        _report += _solution, _report += ";";
        return _report;
    }
};

////////////////////////////////////////////////////////////////////////////////

struct Configuration {
    static iptr Configure() {
        if ((char *)setlocale(LC_ALL, "") == NULL) { // ".936" for windows, "zh_CN.GBK" for linux.
            System::Logging("%s", "invalid locale");
        }

        // QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        // QTextCodec::setCodecForLocale(codec);

        ////////////////////////////////

        System::Logging("timestamp = %s; Qt_version = %s", __TIMESTAMP__, QT_VERSION_STR);

        // System::Logging("QTextCodec::availableCodecs() = \n{ %ls }", Format::Print(QTextCodec::availableCodecs()).toStdWString().data());

        // auto lambda = Format::Lambda_Print(.deviceName(), QString);
        // System::Logging("QAudioDeviceInfo::availableDevices(QAudio::AudioInput) = \n{ %ls }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioInput)).toStdWString().data());
        // System::Logging("QAudioDeviceInfo::availableDevices(QAudio::AudioOutput) = \n{ %ls }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)).toStdWString().data());

        return 0;
    }
    static inline iptr _configure = Configure();
};

#endif // System_h
