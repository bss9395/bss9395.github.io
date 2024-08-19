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
