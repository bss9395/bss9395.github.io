#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QFile>
#include <QDir>

class Config: public QObject {
    Q_OBJECT

public:
    QNetworkAccessManager _networkAccessManager = QNetworkAccessManager();

public:
    Q_INVOKABLE void updateAvatar_people() {
        qDebug().noquote() << __FUNCTION__;

        QString filepath = QString("%1/QtProjects/Qt_QHttpMultiPart/main.qml").arg(QDir::homePath());
        qDebug().noquote() << "filepath = " << filepath;

        QFile *file = new QFile(filepath); // 注意: 使用实际的文件路径
        file->open(QIODevice::ReadOnly);
        if(file->error() != QFile::NoError) {
            qDebug().noquote() << "if(file->error() != QFile::NoError) {";
            return;
        }

        ////////////////////////////////////////////////////////////////////////

        QString url = "http://www.people.com.cn";
        qDebug().noquote() << "url = " << url;

        QNetworkRequest request   = QNetworkRequest(QUrl(url, QUrl::TolerantMode));
        QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        QHttpPart       part      = QHttpPart();
        part.setRawHeader("Content-Disposition", QString(R"!(form-data;name="file";filename="%1";)!").arg(filepath).toUtf8());
        part.setBodyDevice(file);
        multiPart->append(part);
        QNetworkReply *reply = _networkAccessManager.put(request, multiPart);
        file->setParent(reply);
        multiPart->setParent(reply);

        QObject::connect(reply, &QNetworkReply::finished, this, [reply]() -> void {
            qDebug().noquote() << "QObject::connect(reply, &QNetworkReply::finished, this, [reply]() -> void {";
            int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug().noquote() << "statusCode = " << statusCode;

            if(reply->error() == QNetworkReply::NoError) {
                qDebug().noquote() << "if(reply->error() == QNetworkReply::NoError) {";
                QString echo = reply->readAll();
                qDebug().noquote() << "echo = " << echo;
            } else {
                qDebug().noquote() << "error: reply->error() = " << reply->error() << ", reply->errorString() = " << reply->errorString();
            }
            reply->deleteLater();
        });
    }
};

#endif // CONFIG_H
