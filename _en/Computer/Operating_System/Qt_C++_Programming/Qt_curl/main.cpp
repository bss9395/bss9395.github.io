
#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <QDateTime>
#include <cstdlib>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSslConfiguration>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString url = "https://kt-software-private-1313580039.cos.ap-beijing.myqcloud.com/BigFileSlice/manage/2023-11-17/46390f4bc6b24d67b2529eea9b524104.deb?sign=q-sign-algorithm%3Dsha1%26q-ak%3DAKIDRku06A3qDUdZJvMZ2NYZNE9wVu8uRqCQ%26q-sign-time%3D1701394270%3B1701567070%26q-key-time%3D1701394270%3B1701567070%26q-header-list%3Dhost%26q-url-param-list%3Dresponse-cache-control%3Bresponse-content-disposition%3Bresponse-content-language%26q-signature%3Df0c5c157e7e3471a78f09babe0c8b852a4fd9032&response-cache-control=no-cache&response-content-disposition=attachment%3Bfilename%3Ddianjureader_21.0728-3.0_amd64.deb&response-content-language=zh-CN";
    // QString url = "http://www.baidu.com";
    QProcess *process = new QProcess();
    QString command_reach = QString("curl --connect-timeout 5 --head --write-out %{http_code} --verbose --output /dev/null --stderr /dev/null '%1'").arg(url);
    qDebug() << "command_reach = " << command_reach;
    process->start("bash", QStringList() << "-c" << command_reach);
    process->waitForFinished();

    QString error = process->readAllStandardError();
    QString reach = process-> readAllStandardOutput();
    qDebug() << QDateTime::currentDateTime().toUTC() << "error = " << error;
    qDebug() << QDateTime::currentDateTime().toUTC() << "reach = " << reach;

    return a.exec();
}
