/* Qt_TCP_Server.h
Author: BSS9395
Update: 2023-09-01T10:14:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_TCP_SERVER_H
#define QT_TCP_SERVER_H

#include <QMainWindow>
#include "ui_Qt_TCP_Server.h"
#include <QtNetwork>

class Qt_TCP_Server : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt_TCP_Server *_ui = nullptr;
    QTcpServer *_tcp_server = new QTcpServer();
    QTcpSocket *_tcp_socket = nullptr;

public:
    Qt_TCP_Server(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt_TCP_Server) {
        _ui->setupUi(this);

        _ui->CB_IPv4->addItems(_Local_Addresses());
        _ui->A_Start->setEnabled(true);
        _ui->A_Stop->setEnabled(false);

        QObject::connect(_ui->A_Start, &QAction::triggered, this, [this]() -> void {
            QString ipv4 = _ui->CB_IPv4->currentText();
            quint16 port = _ui->SB_Port->value();
            _tcp_server->listen(QHostAddress(ipv4), port);
            QString text = QString("##开始监听##服务器地址: %1:%2").arg(_tcp_server->serverAddress().toString()).arg(_tcp_server->serverPort());
            _ui->PTE_Message->appendPlainText(text);

            _ui->A_Start->setEnabled(false);
            _ui->A_Stop->setEnabled(true);
        });

        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
            if(_tcp_socket != nullptr) {
                _tcp_socket->close();
                _tcp_socket->deleteLater();
                _tcp_socket = nullptr;
            }
            _tcp_server->close();
            _ui->PTE_Message->appendPlainText("##停止监听##");

            _ui->A_Start->setEnabled(true);
            _ui->A_Stop->setEnabled(false);            
        });

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            QString message = _ui->LE_Message->text();
            _ui->LE_Message->clear();
            _ui->LE_Message->setFocus();
            QByteArray data = (message + "\n").toUtf8();
            _tcp_socket->write(data);

            _ui->PTE_Message->appendPlainText("[out] " + message);
        });

        QObject::connect(_tcp_server, &QTcpServer::newConnection, this, [this]() -> void {
            _tcp_socket = _tcp_server->nextPendingConnection();

            auto lambda_connected = [this]() -> void {
                QString text = QString("##连接建立##对方地址: %1:%2").arg(_tcp_socket->peerAddress().toString()).arg(_tcp_socket->peerPort());
                _ui->PTE_Message->appendPlainText(text);
            };
            QObject::connect(_tcp_socket, &QTcpSocket::connected, this, lambda_connected);
            lambda_connected();


            QObject::connect(_tcp_socket, &QTcpSocket::disconnected, this, [this]() -> void {
                _ui->PTE_Message->appendPlainText("##断开连接##");
                _tcp_socket->deleteLater();
                _tcp_socket = nullptr;
            });

            auto lambda_statechanged = [this](QAbstractSocket::SocketState state) -> void{
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
            };
            QObject::connect(_tcp_socket, &QTcpSocket::stateChanged, this, lambda_statechanged);
            lambda_statechanged(_tcp_socket->state());

            QObject::connect(_tcp_socket, &QTcpSocket::readyRead, this, [this]() -> void {
                while(_tcp_socket->canReadLine()) {
                    QString line = _tcp_socket->readLine();
                    line.resize(line.size() - 1);
                    _ui->PTE_Message->appendPlainText("[in] " + line);
                }
            });
        });
    }

    virtual ~Qt_TCP_Server() {
        delete _ui;
        delete _tcp_server;
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
        if(_tcp_socket != nullptr) {
            _tcp_socket->close();
        }
        _tcp_server->close();
        return QMainWindow::closeEvent(event);
    }
};
#endif // QT_TCP_SERVER_H
