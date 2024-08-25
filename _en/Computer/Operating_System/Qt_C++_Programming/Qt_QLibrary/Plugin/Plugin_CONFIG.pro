################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Plugin.h
SOURCES += Plugin.cpp

################################################################################
win32-msvc {
    CONFIG(debug  , debug | release):equals(QT_ARCH, x86_64) {
        message([Plugin] win32-msvc:debug:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Plugind
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Common/x86_64/ -lCommond
        DESTDIR         = $$Root_Working/Plugin/x86_64/
    }
    CONFIG(debug  , debug | release):equals(QT_ARCH, i386) {
        message([Plugin] win32-msvc:debug:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Plugind
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Common/i386/ -lCommond
        DESTDIR         = $$Root_Working/Plugin/i386/
    }
    CONFIG(release  , debug | release):equals(QT_ARCH, x86_64) {
        message([Plugin] win32-msvc:release:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Plugin
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Common/x86_64/ -lCommon
        DESTDIR         = $$Root_Working/Plugin/x86_64/
    }
    CONFIG(release  , debug | release):equals(QT_ARCH, i386) {
        message([Plugin] win32-msvc:release:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Plugin
        INCLUDEPATH    += $$Root_Working/Common/
        LIBS           += -L$$Root_Working/Common/i386/ -lCommon
        DESTDIR         = $$Root_Working/Plugin/i386/
    }
}
win32-g++ {
    message([Plugin] win32-g++)
    TARGET          = Plugin
    INCLUDEPATH    += $$Root_Working/Common/
    LIBS           += -L$$Root_Working/Common/ -lCommon
    DESTDIR         = $$Root_Working/Plugin/
}

#################################################################################
from = $$PWD/*.h
into = $$Root_Working/Plugin/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Plugin] $$QMAKE_POST_LINK)
