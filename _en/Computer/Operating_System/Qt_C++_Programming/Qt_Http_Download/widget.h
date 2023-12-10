#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDir>
#include <QFile>
#include <QTimer>
#include "ui_widget.h"

class Widget : public QWidget {
    Q_OBJECT

    void SetIntervalTimeOut(QNetworkReply *reply, const int &interval) {
        qDebug() << __FUNCTION__;
        QTimer *timer = new QTimer();
        timer->setSingleShot(true);

        reply->setProperty("isTimeOut", false);
        QObject::connect(timer, &QTimer::timeout, [reply]() -> void {
            // qDebug() << "QObject::connect(timer, &QTimer::timeout, [reply]() -> void {";
            reply->setProperty("isTimeOut", true);
            reply->abort();
        });
        QObject::connect(reply, &QNetworkReply::downloadProgress, [timer, interval](qint64 bytesReceived, qint64 bytesTotal) -> void {
            // qDebug() << "QObject::connect(reply, &QNetworkReply::downloadProgress, [timer, interval](qint64 bytesReceived, qint64 bytesTotal) -> void {";
            (void) bytesReceived;
            (void) bytesTotal;
            timer->start(interval);
        });
        QObject::connect(reply, &QNetworkReply::finished, [timer]() -> void {
           // qDebug() << "QObject::connect(reply, &QNetworkReply::finished, [timer]() -> void {";
           timer->stop();
           timer->deleteLater();
        });
        timer->start(interval);
    }

public:
    Ui::Widget           *_ui = nullptr;
    QNetworkAccessManager _networkAccessManager;
    QNetworkReply        *_reply = nullptr;
    QFile                *_file = nullptr;

public:
    Widget(QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::Widget) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {
            qDebug() << "QObject::connect(_ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {";

            QString directory = QDir::currentPath() + "/temp/";
            QDir().mkdir(directory);
            QUrl url = QUrl(_ui->LE_Url->text().trimmed());
            QString filepath = directory + url.fileName();
            qDebug() << filepath;

            _file = new QFile(filepath);
            bool result = _file->open(QFile::WriteOnly | QFile::Append);
            if(result == false) {
                qDebug() << "if(result == false) {";
                return;
            }
            int fileSize = _file->size();
            qDebug() << "fileSize = " << fileSize;

            ////////////////////////////////////////////////////////////////////

            QNetworkRequest request(url);
            QSslConfiguration sslConfiguration = QSslConfiguration::defaultConfiguration();
            sslConfiguration.setPeerVerifyMode(QSslSocket::AutoVerifyPeer);
            request.setSslConfiguration(sslConfiguration);
            request.setRawHeader("Range", QString("bytes=%1-").arg(fileSize).toUtf8());
            _reply = _networkAccessManager.get(request);
            SetIntervalTimeOut(_reply, 5000);

            QObject::connect(_reply, &QNetworkReply::readyRead, this, [this]() -> void {
                // qDebug() << "QObject::connect(_reply, &QNetworkReply::readyRead, this, [this]() -> void {";

                _file->write(_reply->readAll());
            });

            QObject::connect(_reply, &QNetworkReply::downloadProgress, this, [this, fileSize](qint64 bytesReceived, qint64 bytesTotal) -> void {
                // qDebug() << "QObject::connect(_reply, &QNetworkReply::downloadProgress, this, [this, fileSize](qint64 bytesReceived, qint64 bytesTotal) -> void {";

                if(bytesReceived <= 0 || bytesTotal <= 0) {
                    return;
                }
                _ui->PB_Progress->setMaximum(fileSize + bytesTotal);
                _ui->PB_Progress->setValue(fileSize + bytesReceived);
            });

            QObject::connect(_reply, &QNetworkReply::finished, this, [this]() -> void {
                qDebug() << "QObject::connect(_reply, &QNetworkReply::finished, this, [this]() -> void {";
                _file->close();

                int statusCode = _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                qDebug() << "statusCode = " << statusCode;

                if(200 <= statusCode && statusCode < 300) {                                                             // 没有错误
                    if(_reply->error() == QNetworkReply::NoError) {
                        qDebug() << "if(_reply->error() == QNetworkReply::NoError) {";
                        emit signal_downloadFinished(true);
                    } else if(_reply->error() == QNetworkReply::OperationCanceledError) {
                        qDebug() << "} else if(_reply->error() == QNetworkReply::OperationCanceledError) {";
                        if(_reply->property("isTimeOut").isValid() == true && _reply->property("isTimeOut") == true) {  // 连接超时
                            qDebug() << R"!(if(_reply->property("isTimeOut").isValid() == true && _reply->property("isTimeOut") == true) {)!";
                            emit signal_downloadTimeOut();
                        }
                    } else {                                                                                            // 剩余错误都归因于连接超时
                        qDebug() << "} else {, _reply->error() = " << _reply->error() << ", _reply->errorString() = " << _reply->errorString();
                        emit signal_downloadTimeOut();
                    }
                } else if(0 <= statusCode && statusCode < 100) {                                                        // 连接错误
                    qDebug() << "} else if(0 <= statusCode && statusCode < 100) {, _reply->error() = " << _reply->error() << ", _reply->errorString() = " << _reply->errorString();
                    emit signal_downloadTimeOut();
                } else {                                                                                                // 其它错误都归因于下载失败
                    qDebug() << "} else {, _reply->error() = " << _reply->error() << ", _reply->errorString() = " << _reply->errorString();
                    QFile::remove(_file->fileName());
                    emit signal_downloadFinished(false);
                }
                _file->deleteLater();  _file = nullptr;
                _reply->deleteLater(); _reply = nullptr;
            });
        });

        QObject::connect(_ui->PB_Abort, &QPushButton::clicked, this, [this]() -> void {
            qDebug() << "QObject::connect(_ui->PB_Abort, &QPushButton::clicked, this, [this]() -> void {";
            _reply->abort();
        });
    }

    virtual ~Widget() {
        delete _ui;
        _ui = nullptr;
    }

signals:
    void signal_downloadTimeOut();
    void signal_downloadFinished(const bool &status);
};
#endif // WIDGET_H
