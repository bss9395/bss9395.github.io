
TEMPLATE = app
CONFIG  += c++17 console

SOURCES += Main.cpp

## [严格]不同编译器的库不可混用
## [通常]release库和debug库不可混用
## [严格]Win32库与x64库不可混用
win32-msvc {
    message("win32-msvc")
    CONFIG(release, debug | release):equals(QT_ARCH, i386) {
        message("CONFIG(release, debug | release):equals(QT_ARCH, i386) {")
        QMAKE_CXXFLAGS += /utf-8 # /source-charset:utf-8  /execution-charset:gbk
        INCLUDEPATH    += D:/Poco/Poco_MSVC_Win32/include/
        LIBS           += -LD:/Poco/Poco_MSVC_Win32/bin/ -lPocoFoundation   # QtCreator添加到环境变量PATH
    }
    CONFIG(debug, debug | release):equals(QT_ARCH, i386) {
        message("CONFIG(debug, debug | release):equals(QT_ARCH, i386) {")
        QMAKE_CXXFLAGS += /utf-8 # /source-charset:utf-8  /execution-charset:gbk
        INCLUDEPATH    += D:/Poco/Poco_MSVC_Win32/include/
        LIBS           += -LD:/Poco/Poco_MSVC_Win32/bin/ -lPocoFoundationd  # QtCreator添加到环境变量PATH
    }
    CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {
        message("CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {")
        QMAKE_CXXFLAGS += /utf-8  # /source-charset:utf-8  /execution-charset:gbk
        INCLUDEPATH    += D:/Poco/Poco_MSVC_x64/include/
        LIBS           += -LD:/Poco/Poco_MSVC_x64/bin/ -lPocoFoundation     # QtCreator添加到环境变量PATH
    }
    CONFIG(debug, debug | release):equals(QT_ARCH, x86_64) {
        message("CONFIG(debug, debug | release):equals(QT_ARCH, x86_64) {")
        QMAKE_CXXFLAGS += /utf-8  # /source-charset:utf-8  /execution-charset:gbk
        INCLUDEPATH    += D:/Poco/Poco_MSVC_x64/include/
        LIBS           += -LD:/Poco/Poco_MSVC_x64/bin/ -lPocoFoundationd    # QtCreator添加到环境变量PATH
    }
    # 设置环境变量PATH为动态库路径目录
    # 设置Windows系统为中文显示，设置Windows终端为chcp 936，则Windows终端编码为GBK
}

win32-g++ {
    message("win32-g++ {")
    CONFIG(release, debug | release):equals(QT_ARCH, i386) {
        message("CONFIG(release, debug | release):equals(QT_ARCH, i386) {")
        INCLUDEPATH += D:/Poco/Poco_MinGW_32bit/include/
        LIBS        += -LD:/Poco/Poco_MinGW_32bit/bin/ -lFoundation
    }
    CONFIG(debug, debug | release):equals(QT_ARCH, i386) {
        message("CONFIG(debug, debug | release):equals(QT_ARCH, i386) {")
        INCLUDEPATH += D:/Poco/Poco_MinGW_32bit/include/
        LIBS        += -LD:/Poco/Poco_MinGW_32bit/bin/ -lFoundationd
    }
    CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {
        message("CONFIG(release, debug | release):equals(QT_ARCH, x86_64) {")
        INCLUDEPATH += D:/Poco/Poco_MinGW_64bit/include/
        LIBS        += -LD:/Poco/Poco_MinGW_64bit/bin/ -lFoundation
    }
    CONFIG(debug, debug | release):equals(QT_ARCH, x86_64) {
        message("CONFIG(debug, debug | release):equals(QT_ARCH, x86_64) {")
        INCLUDEPATH += D:/Poco/Poco_MinGW_64bit/include/
        LIBS        += -LD:/Poco/Poco_MinGW_64bit/bin/ -lFoundationd
    }
    # 设置环境变量PATH为动态库路径目录
    # 设置Windows系统为中文显示，设置Windows终端为chcp 936，则Windows终端编码为GBK
}
