/* System.h
Author: BSS9395
Update: 2022-01-10T02:16:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef System_h
#define System_h

#include "Common.h"

////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef wchar_t wide;

////////////////////////////////////////////////////////////////////////////////

struct System {
    typedef const char *Level;
    static inline const Level _Info = "Info";
    static inline const Level _Note = "Note";
    static inline const Level _Warn = "Warn";
    static inline const Level _Error = "Error";
    static inline const Level _Fatal = "Fatal";

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

template<typename TRecord = QString, typename TSolution = QString>
class Exception : public QException {
public:
    System::Level _level = System::Level();
    QString _file = "";
    iptr _line = 0;
    QString _function = "";
    TRecord _record = TRecord();
    TSolution _solution = TSolution();
    QString _report = QString();

public:
    Exception(System::Level level, const QString &file, iptr line, const QString &function, const TRecord &record, const TSolution &solution = TSolution())
        : _level(level), _file(file), _line(line), _function(function), _record(record), _solution(solution) {
        Logging(R"(Exception(System::Level level, const QString &file, iptr line, const QString &function, const TRecord &record, const TSolution &solution = TSolution()))");
    }

    Exception(System::Level level, const QString &file, iptr line, const QString &function, const char *record, const char *solution = "")
        : _level(level), _file(file), _line(line), _function(function), _record(record), _solution(solution) {
        Logging(R"(Exception(System::Level level, const QString &file, iptr line, const QString &function, const char *record, const char *solution = ""))");
    }

    virtual ~Exception() {
        Logging(__FUNCTION__);
    }

public:
    virtual QString &Report() {
        Logging(__FUNCTION__);
        _report.reserve(512);
        int sepa = 0;
        ((sepa = _file.lastIndexOf('/')) < 0) && (sepa = _file.lastIndexOf('\\'));
        _report += QString("[%s : %s : %td : %s] ").arg(_level).arg(_file[sepa + 1]).arg(_line).arg(_function);
        _report += _record, _report += " : ";
        _report += _solution, _report += ";";
        return _report;
    }
};

////////////////////////////////////////////////////////////////////////////////

struct Configuration {
    static inline iptr _configuration = []() -> iptr {
        Logging("%s; %s;", __TIMESTAMP__, QT_VERSION_STR);

        //Logging("QTextCodec::availableCodecs() = \n{ %s }", Format::Print(QTextCodec::availableCodecs()).toStdString().data());

        //auto lambda = Lambda_Print(.deviceName(), QString);
        //Logging("QAudioDeviceInfo::availableDevices(QAudio::AudioInput) = \n{ %s }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioInput)).toStdString().data());
        //Logging("QAudioDeviceInfo::availableDevices(QAudio::AudioOutput) = \n{ %s }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)).toStdString().data());

        return 0;
    }();
};

#endif // System_h
