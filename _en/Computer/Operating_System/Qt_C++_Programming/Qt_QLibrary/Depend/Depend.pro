################################################################################
TEMPLATE = lib
CONFIG  += shared c++17
DEFINES += QLIBRARY_EXPORT

HEADERS += Depend.h
SOURCES += Depend.cpp

################################################################################
win32-msvc {
    message([Depend] win32-msvc)
    QMAKE_CXXFLAGS += /utf-8
    TARGET          = Depend
    DESTDIR         = $$Root_Working/Depend/
}
win32-g++ {
    message([Depend] win32-g++)
    TARGET          = Depend
    DESTDIR         = $$Root_Working/Depend/
}

#################################################################################
from = $$PWD/*.h
into = $$DESTDIR/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Depend] $$QMAKE_POST_LINK)
