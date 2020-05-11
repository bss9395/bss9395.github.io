#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    _networkAccessManager = new QNetworkAccessManager(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_getBaidu_clicked()
{
    QNetworkRequest request(QUrl("http://www.baidu.com"));
    QNetworkReply *reply = _networkAccessManager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if(reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->errorString();
            reply -> deleteLater();
            return ;
        }
        QByteArray array = reply->readAll();
        ui->textEdit->setText(array);
    });
}

void Widget::on_postEcho_clicked()
{
    QNetworkRequest request(QUrl("http://192.168.12.128/echo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QString postJson = "{"
            "\"user\": \"itcast\","
            "\"age\": 18"
            "}";

    QNetworkReply *reply = _networkAccessManager->post(request, postJson.toUtf8());

    connect(reply, &QNetworkReply::finished, [=]() {
       if(reply -> error() != QNetworkReply::NoError) {
           qDebug() << reply->errorString();
           reply->deleteLater();
           return;
       }

       QByteArray array = reply->readAll();
       ui->textEdit->setText(array);
       reply->deleteLater();
    });
}


