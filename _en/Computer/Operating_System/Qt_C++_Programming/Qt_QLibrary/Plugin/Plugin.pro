################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Plugin.h
SOURCES += Plugin.cpp

################################################################################
win32-msvc {
    message([Plugin] win32-msvc)
    QMAKE_CXXFLAGS += /utf-8
    TARGET          = Plugin
    INCLUDEPATH    += $$Root_Working/Common/
    LIBS           += -L$$Root_Working/Common/ -lCommon
    DESTDIR         = $$Root_Working/Plugin/
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
into = $$DESTDIR/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Plugin] $$QMAKE_POST_LINK)
