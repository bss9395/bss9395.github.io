
#include <iostream>
#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMutex>
#include <QDateTime>
#include <QDir>


void _Logging(QtMsgType type, const QMessageLogContext &context, const QString &message) {
    static auto  lambda = []() -> QFile * {
        QString filedire = QDir::homePath() + "/brilliant";
        QString filename =  filedire + "/logging.%1.log";
        QString filepath = "";
        int     index    = 0;
        while(filepath = QString(filename).arg(index), QFileInfo::exists(filepath) == true) {
            // 检查文件容量
            if(10 * 1024 * 1024 <= QFileInfo(filepath).size()) {
                index += 1;
            } else {
                break;
            }
        }
        QDir dir = QDir();
        bool ret = dir.mkpath(filedire);  // 创建目录
        if(ret == false) {
            std::cout << "if(ret == false) {" << std::endl << std::flush;
            QCoreApplication::quit();
        }

        QFile *file = new QFile(filepath);
        file->open(QFile::WriteOnly | QFile::Append);
        if(file->error() != QFile::NoError) {
            std::cout << "if(file->error() != QFile::NoError) {, file->errorString().toStdString() = " << file->errorString().toStdString() << std::endl << std::flush;
            QCoreApplication::quit();
        }
        file->write( "================================================================================\n"), file->flush();  // 输出到文件
        std::cout << "================================================================================\n" << std::flush;    // 输出到控制台
        return file;
    };
    static QFile *file  = lambda();
    static QMutex mutex;
    mutex.lock();

    QString timestampUTC = QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddThh:mm:ss.zzz");
    QString level = (type == QtInfoMsg    ) ? "Info"
                  : (type == QtDebugMsg   ) ? "Debug"
                  : (type == QtWarningMsg ) ? "Warning"
                  : (type == QtCriticalMsg) ? "Critical"
                  : (type == QtFatalMsg   ) ? "Fatal"
                  : (type == QtSystemMsg  ) ? "System"
                  :                           "Unknown";
    QString output = QString("[%1@%2@%3@%4] %5\n").arg(timestampUTC).arg(level, -8, ' ').arg(QString(context.file).right(12), -12, ' ').arg(context.line).arg(message);
    // 检查文件容量
    if(10 * 1024 * 1024 <= file->size()) {
        file->close();
        file->deleteLater();
        file = lambda();
    }
    file->write(output.toUtf8()), file->flush();      // 输出到文件
    std::cout << output.toStdString() << std::flush;  // 输出到控制台

    mutex.unlock();
}


int main(int argc, char *argv[]) {
    qInstallMessageHandler(_Logging);
    qDebug().noquote() << __FUNCTION__;
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}
