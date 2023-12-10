#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QFile>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    Ui::MainWindow *ui = nullptr;
    QNetworkAccessManager manager;

public:
    MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);

        qDebug() << "QSslSocket = "   << QSslSocket::sslLibraryBuildVersionString();
        qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();

        QObject::connect(ui->pushButton, &QPushButton::clicked, this, [this]() -> void {
            QUrl url = QUrl(ui->lineEdit->text());
            QNetworkRequest request;
            request.setUrl(url);
            QNetworkReply *reply = manager.get(request);
            connect(reply, &QNetworkReply::finished, this, [this, reply]() -> void {
                if(reply->error() == QNetworkReply::NoError) {
                    QByteArray bytes = reply->readAll();
                    QPixmap pixmap;
                    pixmap.loadFromData(bytes);
                    ui->label->setPixmap(pixmap);

                    pixmap.save("temp.png", "png");
                } else {
                    qDebug() << "error";
                }
                reply->deleteLater();
            });
        });
    }

    ~MainWindow() {
        delete ui;
    }
};
#endif // MAINWINDOW_H
