################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Shared.h
SOURCES += Shared.cpp

################################################################################
win32-msvc {
    CONFIG(debug  , debug | release):equals(QT_ARCH, x86_64) {
        message([Shared] win32-msvc:debug:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Sharedd
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Depend/x86_64/ -lDependd
        LIBS           += -L$$Root_Working/Common/x86_64/ -lCommond
        DESTDIR         = $$Root_Working/Shared/x86_64/
    }
    CONFIG(debug  , debug | release):equals(QT_ARCH, i386) {
        message([Shared] win32-msvc:debug:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Sharedd
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Depend/i386/ -lDependd
        LIBS           += -L$$Root_Working/Common/i386/ -lCommond
        DESTDIR         = $$Root_Working/Shared/i386/
    }
    CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {
        message([Shared] win32-msvc:release:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Shared
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Depend/x86_64/ -lDepend
        LIBS           += -L$$Root_Working/Common/x86_64/ -lCommon
        DESTDIR         = $$Root_Working/Shared/x86_64/
    }
    CONFIG(release, debug | release):equals(QT_ARCH, i386) {
        message([Shared] win32-msvc:release)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Shared
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Depend/i386/ -lDepend
        LIBS           += -L$$Root_Working/Common/i386/ -lCommon
        DESTDIR         = $$Root_Working/Shared/i386/
    }
}
win32-g++ {
    message([Shared] win32-g++)
    TARGET          = Shared
    INCLUDEPATH    += $$Root_Working/Depend/
    INCLUDEPATH    += $$Root_Working/Common/
    LIBS           += -L$$Root_Working/Depend/ -lDepend
    LIBS           += -L$$Root_Working/Common/ -lCommon
    DESTDIR         = $$Root_Working/Shared/
}

#################################################################################
from = $$PWD/*.h
into = $$Root_Working/Shared/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Shared] $$QMAKE_POST_LINK)
