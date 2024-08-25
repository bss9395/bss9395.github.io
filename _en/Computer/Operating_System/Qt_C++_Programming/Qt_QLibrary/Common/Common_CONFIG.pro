################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Common.h
HEADERS += Section/Section.h
SOURCES += Common.cpp
SOURCES += Section/Section.cpp

################################################################################
win32-msvc {
    CONFIG(debug  , debug | release):equals(QT_ARCH, x86_64) {
        message([Common] win32-msvc:debug:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Commond
        DESTDIR         = $$Root_Working/Common/x86_64/
    }
    CONFIG(debug  , debug | release):equals(QT_ARCH, i386) {
        message([Common] win32-msvc:debug:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Commond
        DESTDIR         = $$Root_Working/Common/i386/
    }
    CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {
        message([Common] win32-msvc:release:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Common
        DESTDIR         = $$Root_Working/Common/x86_64/
    }
    CONFIG(release, debug | release):equals(QT_ARCH, i386) {
        message([Common] win32-msvc:release:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Common
        DESTDIR         = $$Root_Working/Common/i386/
    }
}
win32-g++ {
    message([Common] win32-g++)
    TARGET          = Common
    DESTDIR         = $$Root_Working/Common/
}

#################################################################################
from = $$PWD/*.h
into = $$Root_Working/Common/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Common] $$QMAKE_POST_LINK)
