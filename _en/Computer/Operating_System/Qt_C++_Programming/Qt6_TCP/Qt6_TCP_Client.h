/* Qt6_TCP_Client.h
Author: BSS9395
Update: 2023-09-01T10:14:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_TCP_CLIENT_H
#define QT6_TCP_CLIENT_H

#include <QMainWindow>
#include "ui_Qt6_TCP_Client.h"
#include <QtNetwork>

class Qt6_TCP_Client : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_TCP_Client *_ui = nullptr;
    QTcpSocket *_tcp_socket = new QTcpSocket();

public:
    explicit Qt6_TCP_Client(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_TCP_Client) {
        _ui->setupUi(this);

        _ui->CB_IPv4->addItems(_Local_Addresses());
        _ui->A_Connect->setEnabled(true);
        _ui->A_Disconnect->setEnabled(false);

        QObject::connect(_ui->A_Connect, &QAction::triggered, this, [this]() -> void {
            QString ipv4 = _ui->CB_IPv4->currentText();
            quint16 port = _ui->SB_Port->value();
            _tcp_socket->connectToHost(ipv4, port);
        });

        QObject::connect(_ui->A_Disconnect, &QAction::triggered, this, [this]() -> void {
            _tcp_socket->close();
        });

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            QString message = _ui->LE_Message->text();
            _ui->LE_Message->clear();
            _ui->LE_Message->setFocus();
            QByteArray data = (message + "\n").toUtf8();
            _tcp_socket->write(data);

            _ui->PTE_Message->appendPlainText("[out] " + message);
        });

        QObject::connect(_tcp_socket, &QTcpSocket::connected, this, [this]() -> void {
            QString text = QString("##连接建立##对方地址: %1:%2").arg(_tcp_socket->peerAddress().toString()).arg(_tcp_socket->peerPort());
            _ui->PTE_Message->appendPlainText(text);

            _ui->A_Connect->setEnabled(false);
            _ui->A_Disconnect->setEnabled(true);
        });

        QObject::connect(_tcp_socket, &QTcpSocket::disconnected, this, [this]() -> void {
            _ui->PTE_Message->appendPlainText("##连接断开##");

            _ui->A_Connect->setEnabled(true);
            _ui->A_Disconnect->setEnabled(false);
        });

        QObject::connect(_tcp_socket, &QTcpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {
            switch(state) {
            case QAbstractSocket::UnconnectedState:
                _ui->PTE_Message->appendPlainText("##UnconnectedState##");
                break;
            case QAbstractSocket::HostLookupState:
                _ui->PTE_Message->appendPlainText("##HostLookupState##");
                break;
            case QAbstractSocket::ConnectingState:
                _ui->PTE_Message->appendPlainText("##ConnectingState##");
                break;
            case QAbstractSocket::ConnectedState:
                _ui->PTE_Message->appendPlainText("##ConnectedState##");
                break;
            case QAbstractSocket::BoundState:
                _ui->PTE_Message->appendPlainText("##BoundState##");
                break;
            case QAbstractSocket::ClosingState:
                _ui->PTE_Message->appendPlainText("##ClosingState##");
                break;
            case QAbstractSocket::ListeningState:
                _ui->PTE_Message->appendPlainText("##ListeningState");
                break;
            }
        });

        QObject::connect(_tcp_socket, &QTcpSocket::readyRead, this, [this]() -> void {
            while(_tcp_socket->canReadLine()) {
                QString line = _tcp_socket->readLine();
                line.resize(line.size() - 1);
                _ui->PTE_Message->appendPlainText("[in] " + line);
            }
        });
    }

    ~Qt6_TCP_Client() {
        delete _ui;
        delete _tcp_socket;
    }

public:
    QStringList _Local_Addresses() {
        QStringList local_addresses;

        QString hostname = QHostInfo::localHostName();
        QHostInfo hostinfo = QHostInfo::fromName(hostname);
        QList<QHostAddress> addresses = hostinfo.addresses();
        for(int i = 0; i < addresses.size(); i += 1) {
            QHostAddress address = addresses.at(i);
            if(address.protocol() == QAbstractSocket::IPv4Protocol) {
                local_addresses += address.toString();
            }
        }
        return local_addresses;
    }

public:
    void closeEvent(QCloseEvent *event) override {
        _tcp_socket->close();
        return QMainWindow::closeEvent(event);
    }
};

#endif // QT6_TCP_CLIENT_H
