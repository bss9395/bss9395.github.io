/* Qt_CONFIG
Author: bss9395
Update: 2024-08-19T11:10:00+08@China-Beijing+08
*/

/* .pro配置文件
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
*/

#include <QApplication>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QThread>
#include <QTcpServer>
#include <QHostAddress>
#include <QDateTime>
#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <QTextCodec>
#include <iostream>

std::string _ToLocal(const QString& text_utf8) {
    return text_utf8.toLocal8Bit().toStdString();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

#ifdef Q_OS_WIN
    qDebug().noquote() << "Q_OS_WIN";
#endif
#ifdef Q_OS_WINDOWS
    qDebug().noquote() << "Q_OS_WINDOWS";
#endif
#ifdef Q_OS_WIN32
    qDebug().noquote() << "Q_OS_WIN32";
#endif
#ifdef Q_OS_WIN64
    qDebug().noquote() << "Q_OS_WIN64";
#endif

    Poco::AutoPtr<Poco::ConsoleChannel> console_channel(new Poco::ConsoleChannel());
    Poco::Logger::root().setChannel(console_channel);
    Poco::Logger::root().setLevel(Poco::Message::PRIO_TRACE);

    qDebug().noquote() << "你好，世界";
    qDebug().noquote() << QString("你好，世界");
    std::cout << "你好，世界" << std::endl;
    std::cout << _ToLocal("你好，世界") << std::endl;
    Poco::Logger::root().information("你好，世界");
    Poco::Logger::root().information(_ToLocal("你好，世界"));

    return a.exec();
}

