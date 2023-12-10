
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QDesktopServices>
#include <QFileInfo>
#include <QUrl>


Q_INVOKABLE void openFileFolder(const QString &filepath) {
    qDebug() << __FUNCTION__;

    QFileInfo fileinfo(filepath);
    if(fileinfo.exists() == false) {
        qDebug() << "if(fileinfo.exists() == false) {";
        return;
    }

    QString url = "";
    if(fileinfo.isFile() == true) {
        url = QString("file://%1").arg(fileinfo.path());
    } else {
        url = QString("file://%1").arg(fileinfo.filePath());
    }
    qDebug() << "url = " << url;
    QDesktopServices::openUrl(QUrl(url, QUrl::TolerantMode));  // 返回值无效果
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    openFileFolder("/home/chenwc6/下载/tempfile_download.json");

    return a.exec();
}
