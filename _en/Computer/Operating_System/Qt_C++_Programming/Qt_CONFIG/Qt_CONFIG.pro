QT      += core gui widgets network
CONFIG  += c++11
SOURCES += \
    Main.cpp

win32-msvc {
    message("win32-msvc {")
    QMAKE_CXXFLAGS += /utf-8
    CONFIG(debug, debug | release) {
        INCLUDEPATH += D:/Poco/include
        LIBS += -LD:/Poco/lib -lPocoCryptod -lPocoDatad -lPocoEncodingsd -lPocoFoundationd -lPocoNetd -lPocoUtild
    }
    CONFIG(release, debug | release) {
        INCLUDEPATH += D:/Poco/include
        LIBS += -LD:/Poco/lib -lPocoCrypto -lPocoData -lPocoEncodings -lPocoFoundation -lPocoNet -lPocoUtil
    }
} else {
    message("} else {")
}

## 设置Windows环境变量，PATH=D:/Poco/bin;%PATH%
## 设置编译器环境变量 ，PATH=D:/Poco/bin;%PATH%，在visual studio中设置环境变量可能无效。
