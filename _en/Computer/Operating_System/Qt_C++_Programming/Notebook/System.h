/* System.h
Author: BSS9395
Update: 2022-01-12T22:14:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
Notice: Bug on Visual Studio 2017
*/

#ifndef System_h
#define System_h

#include "Common.h"

////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef wchar_t wide;

#define Index_Class(Object, _member)   (((iptr)&((Object *)0)->_member - (iptr)0) / (iptr)sizeof(((Object *)0)->_member))
#define Index_Object(object, _member)  (((iptr)&object._member - (iptr)&object)   / (iptr)sizeof(object._member))
#define Offset_Class(Object, _member)  ((iptr)&((Object *)0)->_member - (iptr)0)
#define Offset_Object(object, _member) ((iptr)&object._member - (iptr)&object)

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

    static iptr Log(iptr line, const char *format, ...) {
        fprintf(stderr, "[%td] ", line);

        va_list list;
        va_start(list, format);
        vfprintf(stderr, format, list);
        va_end(list);

        fprintf(stderr, ";\n");
        fflush(stderr);
        return line;
    }
#define Logging(...) System::Log(__LINE__, __VA_ARGS__)

    static bool Check(bool failed, Level level, const char *file, iptr line, const char *function, const char *record, const char *extra, ...) {
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
#define Checking(failed, level, record, ...) System::Check(failed, level, __FILE__, __LINE__, __FUNCTION__, record, __VA_ARGS__)
};

////////////////////////////////////////////////////////////////////////////////

struct Format {
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

#define Lambda_Print(Member, TBuffer)                                                                                                    \
    [](const auto &container, TBuffer &buffer = Format::Buffer<QString>(1024, 2048), const TBuffer &sepa = QString(", ")) -> TBuffer & { \
        /* Logging(__FUNCTION__); */                                                                                                     \
        buffer.clear();                                                                                                                  \
        if (0 < container.size()) {                                                                                                      \
            auto beg = container.begin(), end = container.end();                                                                         \
            for (buffer += (*beg)Member, beg++; beg != end; buffer += sepa, buffer += (*beg)Member, beg++);                              \
        }                                                                                                                                \
        return buffer;                                                                                                                   \
    }                                                                                                                                    \
// Leave Blank Space
    static inline const auto &Print = Lambda_Print(, QString);  // note: struct Format, bug on Visual Studio 2017.
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
        Checking(true, System::_Info, "obsolete function what()", " use Report() instead.");
        exit(System::_Deprecated);
    }

public:
    template<typename TRecord = QString, typename TSolution = QString>
    static bool Except(bool failed, System::Level level, const QString &file, iptr line, const QString &function, const TRecord &record, const TSolution &solution = TSolution()) {
        if(failed == true) {
            throw Anomaly(level, file, line, function, record, solution);
        }
        return failed;
    }
#define Excepting(failed, level, record, solution) Exception::Except(failed, level, __FILE__, __LINE__, __FUNCTION__, record, solution)
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
        Logging(__FUNCTION__);
    }

public:
    virtual QString &Report() override {
        // Logging(__FUNCTION__);
        _report.reserve(512);
        int sepa = 0;
        ((sepa = _file.lastIndexOf('/')) < 0) && (sepa = _file.lastIndexOf('\\'));
        _report += QString("[%1 : %2 : %3 : %4] ").arg(_level).arg(_file.midRef(sepa + 1)).arg(_line).arg(_function);
        _report += _record, _report += " : ";
        _report += _solution, _report += ";";
        return _report;
    }
};

////////////////////////////////////////////////////////////////////////////////

struct Configuration {
    static inline iptr _configuration = []() -> iptr {
        Logging("%s; %s", __TIMESTAMP__, QT_VERSION_STR);

        //Logging("QTextCodec::availableCodecs() = \n{ %s }", Format::Print(QTextCodec::availableCodecs()).toStdString().data());

        //auto lambda = Lambda_Print(.deviceName(), QString);
        //Logging("QAudioDeviceInfo::availableDevices(QAudio::AudioInput) = \n{ %s }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioInput)).toStdString().data());
        //Logging("QAudioDeviceInfo::availableDevices(QAudio::AudioOutput) = \n{ %s }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)).toStdString().data());

        return 0;
    }();
};

#endif // System_h
