################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Depend.h
SOURCES += Depend.cpp

################################################################################
win32-msvc {
    CONFIG(debug  , debug | release):equals(QT_ARCH, x86_64) {
        message([Depend] win32-msvc:debug:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Dependd
        DESTDIR         = $$Root_Working/Depend/x86_64/
    }
    CONFIG(debug  , debug | release):equals(QT_ARCH, i386) {
        message([Depend] win32-msvc:debug:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Dependd
        DESTDIR         = $$Root_Working/Depend/i386/
    }
    CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {
        message([Depend] win32-msvc:release:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Depend
        DESTDIR         = $$Root_Working/Depend/x86_64/
    }
    CONFIG(release, debug | release):equals(QT_ARCH, i386) {
        message([Depend] win32-msvc:release:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Depend
        DESTDIR         = $$Root_Working/Depend/i386/
    }
}
win32-g++ {
    message([Depend] win32-g++)
    TARGET          = Depend
    DESTDIR         = $$Root_Working/Depend/
}

#################################################################################
from = $$PWD/*.h
into = $$Root_Working/Depend/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Depend] $$QMAKE_POST_LINK)
