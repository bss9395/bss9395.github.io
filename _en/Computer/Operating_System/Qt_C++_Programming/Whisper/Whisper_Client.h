/* Whisper_Client.h
Author: BSS9395
Update: 2022-03-20T21:35:00+08@China-Shanghai+08
Design: Whisper
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Whisper_Client_h
#define Whisper_Client_h

#define Header_h
#include "Common.h"
#include "ui_Whisper_Client.h"
#include "System.h"

class Whisper_Client : public QMainWindow {
    Q_OBJECT

public:
    // static inline const QString _Server_Address = "127.0.0.1";
    static inline const iptr _Server_Port = 1200;

public:
    Ui::Whisper_Client *_ui = nullptr;
    QTcpSocket _client = QTcpSocket();

public:
    explicit Whisper_Client(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Whisper_Client) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        Setup();

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Log->clear();
        });

        QObject::connect(_ui->A_Connect, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Connect, &QAction::triggered, this, [this]() -> void {");

            QString address = _ui->CB_Address->currentText();
            iptr port = _ui->SB_Port->value();
            _client.connectToHost(address, port);
        });

        QObject::connect(_ui->A_Disconnect, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Disconnect, &QAction::triggered, this, [this]() -> void {");

            if(_client.state() == QAbstractSocket::ConnectedState) {
                // _client.disconnectFromHost();
                _client.close();
            }
        });

        QObject::connect(&_client, &QTcpSocket::connected, this, [this]() -> void {
            System::Logging("QObject::connect(&_client, &QTcpSocket::connected, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText(QString("client is connected on %1:%2").arg(_client.peerAddress().toString()).arg(_client.peerPort()));
        });

        QObject::connect(&_client, &QTcpSocket::disconnected, this, [this]() -> void {
            System::Logging("QObject::connect(&_client, &QTcpSocket::disconnected, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText(QString("client is disconnected on %1:%2").arg(_client.peerAddress().toString()).arg(_client.peerPort()));
        });

        QObject::connect(&_client, &QTcpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {
            System::Logging("QObject::connect(&_client, &QTcpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {");

            Socket_State(state);
        });

        QObject::connect(&_client, &QTcpSocket::readyRead, this, [this]() -> void {
            System::Logging("QObject::connect(&_client, &QTcpSocket::readyRead, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText("[in] " + _client.readAll()); // note: here, readLine() includes '\n'.
        });

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {");

            QString message = _ui->PTE_Message->toPlainText();
            _ui->PTE_Log->appendPlainText("[out] " + message);
            _client.write(message.toUtf8());
            _ui->PTE_Message->clear();
            _ui->PTE_Message->setFocus();
        });
    }

    virtual ~Whisper_Client() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void Setup() {
        System::Logging(__FUNCTION__);

        QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
        for(auto beg = addresses.begin(), end = addresses.end(); beg != end; beg += 1) {
            QHostAddress address = (*beg);
            if(address.protocol() == QAbstractSocket::IPv4Protocol) {
                // _ui->CB_Address->addItem(address.toString());
                _ui->PTE_Log->appendPlainText(address.toString());
            }
        }
        _ui->SB_Port->setValue(_Server_Port);
    }

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

public:
    bool virtual event(QEvent *event) override {
        // System::Logging(__FUNCTION__);
        if(event->type() == QEvent::Close) {
            if(_client.state() == QAbstractSocket::ConnectedState) {
                _client.close();
            }
            event->accept();
            return true;
        }
        return QWidget::event(event);
    }
};

#endif // Whisper_Client_h
