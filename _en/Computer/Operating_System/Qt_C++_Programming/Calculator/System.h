/* System.h
Author: BSS9395
Update: 2022-01-06T20:21:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef System_h
#define System_h

#include "Common.h"

struct System {
    typedef const char *Level;
    static inline const Level _Info = "Info";
    static inline const Level _Note = "Note";
    static inline const Level _Warn = "Warn";
    static inline const Level _Error = "Error";
    static inline const Level _Fatal = "Fatal";

    static iptr Logger_(iptr line, const char *format, ...) {
        fprintf(stderr, "[%td] ", line);

        va_list list;
        va_start(list, format);
        vfprintf(stderr, format, list);
        va_end(list);

        fprintf(stderr, "\n");
        fflush(stderr);
        return line;
    }
#define Logger(...) System::Logger_(__LINE__, __VA_ARGS__)

    static bool Check_(bool failed, Level level, const char *file, iptr line, const char *function, const char *record, const char *extra, ...) {
        if (failed == true) {
            const char *sepa = NULL;
            (sepa = strrchr(file, '/')) || (sepa = strrchr(file, '\\'));
            fprintf(stderr, "[%s : %s : %td] %s : %s ", level, (sepa == NULL) ? file : (sepa + 1), line, function, record);

            if (extra != NULL) {
                va_list list;
                va_start(list, extra);
                vfprintf(stderr, extra, list);
                va_end(list);
            }

            fprintf(stderr, "\n");
            fflush(stderr);
        }
        return failed;
    }
#define Check(failed, level, record, ...) System::Check_(failed, level, __FILE__, __LINE__, __FUNCTION__, record, __VA_ARGS__)

    static iptr Configuration() {
        fprintf(stderr, "[%s] %s""\n", __TIMESTAMP__, QT_VERSION_STR);
        fflush(stderr);

        Logger("QTextCodec::availableCodecs() = \n{ %s }", Format::Print(QTextCodec::availableCodecs()).toStdString().data());

        auto lambda = Lambda_Print(.deviceName(), QString);
        Logger("QAudioDeviceInfo::availableDevices(QAudio::AudioInput) = \n{ %s }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioInput)).toStdString().data());
        Logger("QAudioDeviceInfo::availableDevices(QAudio::AudioOutput) = \n{ %s }", lambda(QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)).toStdString().data());

        return 0;
    }

    static inline iptr _configuration = []() -> iptr {
        static iptr configuration = Configuration(); // note: bug on Visual Studio 2017
        return (configuration += 1);
    }();
};

#endif // System_h
