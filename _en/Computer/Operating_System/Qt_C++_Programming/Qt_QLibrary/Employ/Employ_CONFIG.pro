################################################################################
TEMPLATE = app
CONFIG  += c++17 console

SOURCES += Main.cpp

################################################################################
win32-msvc {
    CONFIG(debug  , debug | release):equals(QT_ARCH, x86_64) {
        message([Employ] win32-msvc:debug:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Employd
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        INCLUDEPATH    += $$Root_Working/Shared/
        INCLUDEPATH    += $$Root_Working/Plugin/
        LIBS           += -L$$Root_Working/Common/x86_64/ -lCommond
        DESTDIR         = $$Root_Working/Employ/x86_64/
    }
    CONFIG(debug  , debug | release):equals(QT_ARCH, i386) {
        message([Employ] win32-msvc:debug:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Employd
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        INCLUDEPATH    += $$Root_Working/Shared/
        INCLUDEPATH    += $$Root_Working/Plugin/
        LIBS           += -L$$Root_Working/Common/i386/ -lCommond
        DESTDIR         = $$Root_Working/Employ/i386/
    }
    CONFIG(release  , debug | release):equals(QT_ARCH, x86_64) {
        message([Employ] win32-msvc:release:x86_64)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Employ
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        INCLUDEPATH    += $$Root_Working/Shared/
        INCLUDEPATH    += $$Root_Working/Plugin/
        LIBS           += -L$$Root_Working/Common/x86_64/ -lCommon
        DESTDIR         = $$Root_Working/Employ/x86_64/
    }
    CONFIG(release  , debug | release):equals(QT_ARCH, i386) {
        message([Employ] win32-msvc:release:i386)
        QMAKE_CXXFLAGS += /utf-8
        TARGET          = Employ
        INCLUDEPATH    += $$Root_Working/Depend/
        INCLUDEPATH    += $$Root_Working/Common/
        INCLUDEPATH    += $$Root_Working/Shared/
        INCLUDEPATH    += $$Root_Working/Plugin/
        LIBS           += -L$$Root_Working/Common/i386/ -lCommon
        DESTDIR         = $$Root_Working/Employ/i386/
    }
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
