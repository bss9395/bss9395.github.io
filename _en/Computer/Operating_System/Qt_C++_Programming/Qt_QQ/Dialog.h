/* Dialog.h
Author: BSS9395
Update: 2023-08-16T19:02:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef Dialog_h
#define Dialog_h

#include <QWidget>
#include "ui_Dialog.h"
#include <QUdpSocket>
#include <QDateTime>
#include <QFileDialog>
#include <QColorDialog>
#include <QDebug>
#include <QDataStream>


class Dialog : public QWidget {
    Q_OBJECT

public:
    Ui::Dialog *_ui = nullptr;

    int _udp_port      = 9395;
    int _topic_login   = 0x01;
    int _topic_logout  = 0x02;
    int _topic_message = 0x03;

    QString     _username;
    QUdpSocket *_udp_socket = nullptr;
    short       _port       = 29395;


public:
    explicit Dialog(QString username, QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::Dialog) {
        qDebug() << __FUNCTION__;
        _ui->setupUi(this);
        _username = username;

        _udp_socket = new QUdpSocket(this);
        _udp_socket->bind(_port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            _Send_Message();
        });

        QObject::connect(_ui->PB_Close, &QPushButton::clicked, this, [this]() -> void {
            this->close();
        });

        QObject::connect(_udp_socket, &QUdpSocket::readyRead, this, &Dialog::_Receive);

        _Send_Login();
    }

    virtual ~Dialog() {
        qDebug() << __FUNCTION__;
        delete _ui;
        delete _udp_socket;
    }

    void closeEvent(QCloseEvent *event) override{
        _Send_Logout();
        emit _Closed();
        QWidget::closeEvent(event);
    }

public:
    void _Send_Login() {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << _topic_login;
        out << _username;
        _udp_socket->writeDatagram(data, data.length(), QHostAddress::Broadcast, _port);
    }

    void _Send_Logout() {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << _topic_logout;
        out << _username;
        _udp_socket->writeDatagram(data, data.length(), QHostAddress::Broadcast, _port);
    }

    void _Send_Message() {
        QByteArray data;
        QDataStream out(&data, QIODevice::WriteOnly);
        out << _topic_message;
        out << _username;
        out << _ui->TE_Message->toHtml();
        _ui->TE_Message->clear();
        _udp_socket->writeDatagram(data, data.length(), QHostAddress::Broadcast, _port);
    }

    void _Receive_Login(QString username) {
        QList<QTableWidgetItem *> find = _ui->TW_Users->findItems(username, Qt::MatchExactly);
        if(find.isEmpty() == true) {
            QTableWidgetItem *item = new QTableWidgetItem(username);
            _ui->TW_Users->insertRow(0);
            _ui->TW_Users->setItem(0, 0, item);
            _ui->TB_Chat->append(QString("%1在线！").arg(username));
            _Send_Login();
        }        
    }

    void _Receive_Logout(QString username) {
        QList<QTableWidgetItem*> find = _ui->TW_Users->findItems(username, Qt::MatchExactly);
        if(find.isEmpty() == false) {
            int row = find.first()->row();
            _ui->TW_Users->removeRow(row);
            _ui->TB_Chat->append(QString("%1离线！").arg(username));
        }
    }

    void _Receive_Message(QDataStream &in, QString username) {
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss");
        QString message;
        in >> message;
        _ui->TB_Chat->append(QString("[%1] %2").arg(username).arg(time));
        _ui->TB_Chat->append(message);
    }

public slots:
    void _Receive() {

        QByteArray data;
        data.resize(_udp_socket->pendingDatagramSize());
        _udp_socket->readDatagram(data.data(), data.size());

        QDataStream in(&data, QIODevice::ReadOnly);
        int topic;
        QString username;
        in >> topic;
        in >> username;

        if(topic == _topic_login) {
            _Receive_Login(username);
        } else if(topic == _topic_logout) {
            _Receive_Logout(username);
        } else if(topic == _topic_message) {
            _Receive_Message(in, username);
        }
    }

signals:
    void _Closed();
};

#endif // Dialog_h
