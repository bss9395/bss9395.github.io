#ifndef System_h
#define System_h

#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef intptr_t iptr;

class System {
public:
    typedef const char *Level;
    static inline const Level _Info = "Info";
    static inline const Level _Warn = "Warn";
    static inline const Level _Debug = "Debug";
    static inline const Level _Error = "Error";
    static inline const Level _Fatal = "Fatal";

public:
    static inline iptr Logger_(iptr line, const char *format, ...) {
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

    static inline bool Check_(bool failed, Level level, const char *file, iptr line, const char *function, const char *record, const char *extra, ...) {
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

    static inline iptr Configuration() {
        // note: bug on Visual Studio 2017
        static bool once = false;
        if (once == false) {
            once = true;
            fprintf(stderr, "%s""\n", __TIMESTAMP__);
            fflush(stderr);
            return 0;
        }
        return (_configuration + 1);
    }
    static inline iptr _configuration = Configuration();
};

#endif // System_h
