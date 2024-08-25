################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Shared.h
SOURCES += Shared.cpp

################################################################################
win32-msvc {
    message([Shared] win32-msvc)
    QMAKE_CXXFLAGS += /utf-8
    TARGET          = Shared
    INCLUDEPATH    += $$Root_Working/Depend/
    INCLUDEPATH    += $$Root_Working/Common/
    LIBS           += -L$$Root_Working/Depend/ -lDepend
    LIBS           += -L$$Root_Working/Common/ -lCommon
    DESTDIR         = $$Root_Working/Shared/
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
into = $$DESTDIR/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Shared] $$QMAKE_POST_LINK)
