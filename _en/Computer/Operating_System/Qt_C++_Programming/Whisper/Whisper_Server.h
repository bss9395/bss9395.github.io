/* Whisper_Server.h
Author: BSS9395
Update: 2022-03-20T21:35:00+08@China-Shanghai+08
Design: Whisper
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Whisper_Server_h
#define Whisper_Server_h

#define Header_h
#include "Common.h"
#include "ui_Whisper_Server.h"
#include "System.h"

class Whisper_Server : public QMainWindow {
    Q_OBJECT

public:
    // static inline const QString _Server_Address = "127.0.0.1";
    static inline const QString _Server_Address = "0.0.0.0";
    static inline const iptr _Server_Port = 1200;

public:
    Ui::Whisper_Server *_ui = nullptr;
    QTcpServer _server = QTcpServer();
    QTcpSocket *_client = nullptr;

public:
    explicit Whisper_Server(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Whisper_Server) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        Setup();

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Log->clear();
        });

        QObject::connect(_ui->A_Running, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Running, &QAction::triggered, this, [this]() -> void {");

            QString address = _ui->CB_Address->currentText();
            iptr port = _ui->SB_Port->value();

            _server.listen(QHostAddress(address), port);
            // _server.listen(QHostAddress(QHostAddress::LocalHost), port);
            // _server.listen(QHostAddress(QHostAddress::AnyIPv4), port);

            _ui->PTE_Log->appendPlainText("================================================================================");
            _ui->PTE_Log->appendPlainText(QString("server is listening on %1:%2").arg(_server.serverAddress().toString()).arg(_server.serverPort()));
        });

        QObject::connect(_ui->A_Stopped, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Stopped, &QAction::triggered, this, [this]() -> void {");

            if(_server.isListening() == true) {
                _client->close();
                _ui->PTE_Log->appendPlainText(QString("server is stopped on %1:%2").arg(_server.serverAddress().toString()).arg(_server.serverPort()));
                _server.close();
            }
        });

        QObject::connect(&_server, &QTcpServer::newConnection, this, [this]() -> void {
            System::Logging("QObject::connect(&_server, &QTcpServer::newConnection, this, [this]() -> void {");

            _client = _server.nextPendingConnection();

            QObject::connect(_client, &QTcpSocket::connected, this, [this]() -> void {
                System::Logging("QObject::connect(&_client, &QTcpSocket::connected, this, [this]() -> void {");

                _ui->PTE_Log->appendPlainText(QString("client is connected on %1:%2").arg(_client->peerAddress().toString()).arg(_client->peerPort()));
            });
            _ui->PTE_Log->appendPlainText(QString("client is connected on %1:%2").arg(_client->peerAddress().toString()).arg(_client->peerPort()));

            QObject::connect(_client, &QTcpSocket::disconnected, this, [this]() -> void {
                System::Logging("QObject::connect(socket, &QTcpSocket::disconnected, this, [this]() -> void {");

                _ui->PTE_Log->appendPlainText(QString("client is disconnected on %1:%2").arg(_client->peerAddress().toString()).arg(_client->peerPort()));
                _client->deleteLater();
            });

            Socket_State(_client->state());
            QObject::connect(_client, &QTcpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {
                System::Logging("QObject::connect(socket, &QTcpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {");

                Socket_State(state);
            });

            QObject::connect(_client, &QTcpSocket::readyRead, this, [this]() -> void {
                System::Logging("QObject::connect(socket, &QTcpSocket::readyRead, this, [this]() -> void {");

                _ui->PTE_Log->appendPlainText("[in] " + _client->readAll());
            });

            QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
                System::Logging("QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {");

                QString message = _ui->PTE_Message->toPlainText();
                _ui->PTE_Log->appendPlainText("[out] " + message);
                _client->write(message.toUtf8());
                _ui->PTE_Message->clear();
                _ui->PTE_Message->setFocus();
            });
        });
    }

    virtual ~Whisper_Server() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

    void Setup() {
        System::Logging(__FUNCTION__);

        _ui->CB_Address->addItem(_Server_Address);
        QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
        for(auto beg = addresses.begin(), end = addresses.end(); beg != end; beg += 1) {
            QHostAddress address = (*beg);
            if(address.protocol() == QAbstractSocket::IPv4Protocol) {
                _ui->CB_Address->addItem(address.toString());
            }
        }
        _ui->CB_Address->setCurrentText(_Server_Address);
        _ui->SB_Port->setValue(_Server_Port);
    }

public:
    bool virtual event(QEvent *event) override {
        // System::Logging(__FUNCTION__);
        if(event->type() == QEvent::Close) {
            if(_server.isListening() == true) {
                _server.close();
            }

            event->accept();
            return true;
        }
        return QWidget::event(event);
    }

public:
    void Socket_State(QAbstractSocket::SocketState state) {
        QString info = "";
        if(state == QAbstractSocket::UnconnectedState) {
            info += "The socket is not connected.";
        } else if(state == QAbstractSocket::HostLookupState) {
            info += "The socket is performing a host name lookup.";
        } else if(state == QAbstractSocket::ConnectingState) {
            info += "The socket has started establishing a connection.";
        } else if(state == QAbstractSocket::ConnectedState) {
            info += "A connection is established.";
        } else if(state == QAbstractSocket::BoundState) {
            info += "The socket is bound to an address and port.";
        } else if(state == QAbstractSocket::ClosingState) {
            info += "The socket is about to close (data may still be waiting to be written).";
        } else if(state == QAbstractSocket::ListeningState) {
            info += "For internal use only.";
        } else {
            info += "unkown state.";
        }
        _ui->PTE_Log->appendPlainText(info);
    };
};

#endif // Whisper_Server_h
