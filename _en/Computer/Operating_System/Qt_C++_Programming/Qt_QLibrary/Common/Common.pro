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
    message([Common] win32-msvc)
    QMAKE_CXXFLAGS += /utf-8
    TARGET          = Common
    DESTDIR         = $$Root_Working/Common/
}
win32-g++ {
    message([Common] win32-g++)
    TARGET          = Common
    DESTDIR         = $$Root_Working/Common/
}

#################################################################################
from = $$PWD/*.h
into = $$DESTDIR/
QMAKE_POST_LINK += xcopy /I /E /Y \"$$replace(from, /, \\)\" \"$$replace(into, /, \\)\"
message([Common] $$QMAKE_POST_LINK)
