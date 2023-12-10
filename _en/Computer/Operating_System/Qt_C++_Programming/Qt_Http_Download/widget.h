#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDir>
#include <QFile>
#include "ui_widget.h"

class Widget : public QWidget {
    Q_OBJECT

public:
    Ui::Widget *ui = nullptr;
    QNetworkAccessManager networkAccessManager;
    QNetworkReply *reply = nullptr;
    QFile *file = nullptr;

public:
    Widget(QWidget *parent = nullptr)
        : QWidget(parent), ui(new Ui::Widget) {
        ui->setupUi(this);

        qDebug() << "QDir::home()     = " << QDir::home();
        qDebug() << "QDir::homePath() = " << QDir::homePath();

        QObject::connect(ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {
            qDebug() << "QObject::connect(ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {";

            QUrl url = QUrl(ui->LE_Url->text().trimmed());
            QString directory = QDir::currentPath() + "/temp/";
            QDir().mkdir(directory);
            QString filepath = directory + url.fileName();
            qDebug() << filepath;

            file = new QFile(filepath);
            qDebug() << "file->fileName() = " << file->fileName();
            bool result = file->open(QFile::WriteOnly | QFile::Append);
            if(result == false) {
                qDebug() << "if(result == false) {";
                return;
            }
            int fileSize = file->size();
            qDebug() << "fileSize = " << fileSize;

            ////////////////////////////

            QNetworkRequest request(url);
            QSslConfiguration sslConfiguration = QSslConfiguration::defaultConfiguration();
            sslConfiguration.setPeerVerifyMode(QSslSocket::AutoVerifyPeer);
            request.setSslConfiguration(sslConfiguration);
            request.setRawHeader("Range", QString("bytes=%1-").arg(fileSize).toUtf8());
            reply = networkAccessManager.get(request);

            QObject::connect(reply, &QNetworkReply::readyRead, this, [this]() -> void {
                qDebug() << "QObject::connect(reply, &QNetworkReply::readyRead, this, [this]() -> void {";

                file->write(reply->readAll());
            });
            QObject::connect(reply, &QNetworkReply::downloadProgress, this, [this, fileSize](qint64 bytesReceived, qint64 bytesTotal) -> void {
                qDebug() << "QObject::connect(reply, &QNetworkReply::downloadProgress, this, [this, fileSize](qint64 bytesReceived, qint64 bytesTotal) -> void {";

                ui->PB_Progress->setMaximum(bytesTotal + fileSize);
                ui->PB_Progress->setValue(fileSize + bytesReceived);
            });
            QObject::connect(reply, (void (QNetworkReply::*)(QNetworkReply::NetworkError))&QNetworkReply::error, this, [](QNetworkReply::NetworkError networkError) -> void {
                qDebug() << "QObject::connect(reply, (void (QNetworkReply::*)(QNetworkReply::NetworkError))&QNetworkReply::error, this, [](QNetworkReply::NetworkError networkError) -> void {";
                qDebug() << networkError;
            });
            QObject::connect(reply, &QNetworkReply::finished, this, [this]() -> void {
                qDebug() << "QObject::connect(reply, &QNetworkReply::finished, this, [this]() -> void {";
                int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                qDebug() << "statusCode = " << statusCode;

                if(reply->error() == QNetworkReply::NoError) {
                    qDebug() << "if(reply->error() == QNetworkReply::NoError) {";
                } else {
                    qDebug() << reply->error() << ", " << reply->errorString();
                }
                file->close();
                file->deleteLater();
                reply->deleteLater();
            });
        });

        QObject::connect(ui->PB_Abort, &QPushButton::clicked, this, [this]() -> void {
            qDebug() << "QObject::connect(ui->PB_Abort, &QPushButton::clicked, this, [this]() -> void {";

            reply->abort();
        });
    }

    ~Widget() {
        delete ui;
        ui = nullptr;
    }
};
#endif // WIDGET_H
