################################################################################
TEMPLATE = app
CONFIG  += c++17 console

SOURCES += Main.cpp

################################################################################
win32-msvc {
    message([Employ] win32-msvc)
    QMAKE_CXXFLAGS += /utf-8
    INCLUDEPATH    += $$Root_Working/Depend/
    INCLUDEPATH    += $$Root_Working/Common/
    INCLUDEPATH    += $$Root_Working/Shared/
    INCLUDEPATH    += $$Root_Working/Plugin/
    LIBS           += -L$$Root_Working/Common/ -lCommon
    DESTDIR         = $$Root_Working/Employ/
}
win32-g++ {
    message([Employ] win32-g++)
    INCLUDEPATH    += $$Root_Working/Depend/
    INCLUDEPATH    += $$Root_Working/Common/
    INCLUDEPATH    += $$Root_Working/Shared/
    INCLUDEPATH    += $$Root_Working/Plugin/
    LIBS           += -L$$Root_Working/Common/ -lCommon
    DESTDIR         = $$Root_Working/Employ/
}

################################################################################
PATH=E:/QtProjects/Qt_QLibrary_copy_copy/Working/Common/x86_64/;E:/QtProjects/Qt_QLibrary_copy_copy/Working/Common/i386/;$(QtDllPath);%PATH%
