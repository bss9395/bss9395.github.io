#include <QApplication>
#include <QProcess>
#include <QDebug>

void _QProcess_Asynchronous() {
    qDebug() << __FUNCTION__;

    QProcess *process = new QProcess();
    QObject::connect(process, &QProcess::errorOccurred, [process](QProcess::ProcessError error) -> void {
        qDebug() << "QObject::connect(process, &QProcess::errorOccurred, [process](QProcess::ProcessError error) -> void {";

        qDebug() << "error = " << error;
    });
    QObject::connect(process, (void (QProcess::*)(int, QProcess::ExitStatus))&QProcess::finished, [process](int exitCode, QProcess::ExitStatus exitStatus) -> void {
        qDebug() << "QObject::connect(process, (void (QProcess::*)(int, QProcess::ExitStatus))&QProcess::finished, [process](int exitCode, QProcess::ExitStatus exitStatus) -> void {";

        qDebug() << "exitCode = " << exitCode << ", exitStatus = " << exitStatus;
        QString output = (exitCode == 0) ? QString(process->readAllStandardOutput()).split("\n")[0] : QString();
        qDebug() << "output = " << output;

        qDebug() << "process->readChannel() = " << process->readChannel() << ", process->readChannelMode() = " << process->readChannelMode();
        QString error = QString(process->readAllStandardError());
        qDebug() << "error = " << error;

        process->deleteLater();
    });
    QString command = R"!(ls "/home/$(whoami)" | grep 桌面)!";
    process->start("bash", QStringList() << "-c" << command);
}

void _QProcess_Synchronous() {
    qDebug() << __FUNCTION__;

    QProcess process;
    QString command = R"!(ls "/home/$(whoami)" | grep 桌面)!";
    process.start("bash", QStringList() << "-c" << command);
    bool ret = process.waitForFinished();
    qDebug() << "ret = " << ret << ", exitCode() = " << process.exitCode() << ", error() = " << process.error();
    QString output = (ret == true && process.exitCode() == 0) ? QString(process.readAllStandardOutput()).split("\n")[0] : QString();
    qDebug() << "output = " << output;

    qDebug() << "process.readChannel() = " << process.readChannel() << ", process.readChannelMode() = " << process.readChannelMode();
    QString error = (ret == true) ? QString(process.readAllStandardError()) : QString();
    qDebug() << "error = " << error;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 注意Windows Qt，QProcess.start()方法可能启动不了程序，参考https://www.cnblogs.com/tingtaishou/p/14714990.html
    _QProcess_Asynchronous();
    _QProcess_Synchronous();

    return a.exec();
}
