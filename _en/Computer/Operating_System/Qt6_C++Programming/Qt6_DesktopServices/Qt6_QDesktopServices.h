/* Qt6_QDesktopServices.h
Author: BSS9395
Update: 2023-09-04T15:45:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QDESKTOPSERVICES_H
#define QT6_QDESKTOPSERVICES_H

#include <QMainWindow>
#include "ui_Qt6_QDesktopServices.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDesktopServices>
#include <QNetworkAccessManager>

class Qt6_QNetworkServices : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QNetworkServices *_ui = nullptr;
    QNetworkAccessManager _manager;
    QFile *_file = nullptr;
    QNetworkReply *_reply = nullptr;

public:
    Qt6_QNetworkServices(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QNetworkServices) {
        _ui->setupUi(this);

        _ui->LE_URL->setClearButtonEnabled(true);
        _ui->LE_Save->setClearButtonEnabled(true);
        _ui->LE_URL->setText("https://www.cnblogs.com/aiguona/p/9999507.html");
        _ui->LE_Save->setText(QDir::currentPath());
        _ui->PB_Download->setEnabled(true);
        _ui->PB_Abort->setEnabled(false);
        _ui->PB_Progress->setValue(0);

        QObject::connect(_ui->PB_Download, &QPushButton::clicked, this, [this]() -> void {
            QString url = _ui->LE_URL->text().trimmed();
            QString dir = _ui->LE_Save->text().trimmed();

            QUrl uri = QUrl(url);
            if(uri.isValid() == false) {
                QMessageBox::information(this, "错误提示", "无效的链接");
                return;
            }

            QString filepath = dir + "/" + uri.fileName();
            if(QFile::exists(filepath) == true) {
                QFile::remove(filepath);
            }

            _file = new QFile(filepath);
            if(false == _file->open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, "错误提示", "文件打开错误");
                return ;
            }

            _ui->PB_Download->setEnabled(false);
            _ui->PB_Abort->setEnabled(true);

            _reply = _manager.get(QNetworkRequest(uri));

            QObject::connect(_reply, &QNetworkReply::readyRead, this, [this]() -> void {
                _file->write(_reply->readAll());
            });

            QObject::connect(_reply, &QNetworkReply::downloadProgress, this, [this](qint64 bytesReceived, qint64 bytesTotal) -> void {
                _ui->PB_Progress->setMaximum(bytesTotal);
                _ui->PB_Progress->setValue(bytesReceived);
            });

            QObject::connect(_reply, &QNetworkReply::finished, this, [this]() -> void {
                QFileInfo info = QFileInfo(_file->fileName());
                _reply->deleteLater();
                _file->close();
                delete _file;

                if(_ui->CB_Open->isChecked()) {
                    QDesktopServices::openUrl(QUrl::fromLocalFile(info.absoluteFilePath()));
                }

                _ui->PB_Download->setEnabled(true);
                _ui->PB_Abort->setEnabled(false);
            });
        });

        QObject::connect(_ui->PB_Abort, &QPushButton::clicked, this, [this]() -> void {
            _reply->abort();
            _reply->deleteLater();
            _file->close();
            delete _file;
        });
    }

    ~Qt6_QNetworkServices() {
        delete _ui;
    }


};
#endif // QT6_QDESKTOPSERVICES_H
