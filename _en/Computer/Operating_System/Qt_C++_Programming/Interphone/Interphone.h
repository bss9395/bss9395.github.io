/* Interphone.h
Author: BSS9395
Update: 2022-03-21T20:58:00+08@China-Shanghai+08
Design: Interphone
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Interphone_h
#define Interphone_h

#define Header_h
#include "Common.h"
#include "ui_Interphone.h"
#include "System.h"

class Interphone : public QMainWindow {
    Q_OBJECT

public:
    typedef const char *Type;
    static inline const Type _Talkie = Type("Talkie");
    static inline const Type _Walkie = Type("Walkie");

    static inline const QString _Talkie_Address = "127.0.0.1";
    static inline const iptr _Talkie_Port = 1200;
    static inline const QString _Walkie_Address = "127.0.0.1";
    static inline const iptr _Walkie_Port = 3355;

public:
    Type _type = Type();
    Ui::Interphone *_ui = nullptr;
    QUdpSocket *_socket = nullptr;

public:
    explicit Interphone(const Type &type, QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Interphone) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _type = type;
        Setup();

        _socket = new QUdpSocket();
        Socket_State(_socket->state());

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Log->clear();
        });

        QObject::connect(_ui->A_Bind, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Bind, &QAction::triggered, this, [this]() -> void {");

            iptr port = _ui->SB_Bind->value();
            if(_socket->bind(port) == true) {
                _ui->PTE_Log->appendPlainText(QString("已绑定端口%1").arg(_socket->localPort()));
            } else {
                _ui->PTE_Log->appendPlainText(QString("未绑定端口%1").arg(port));
            }
        });

        QObject::connect(_ui->A_Unbind, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Unbind, &QAction::triggered, this, [this]() -> void {");

            _socket->close();
        });

        // note: for udpsocket, it is useless.
        QObject::connect(_socket, &QUdpSocket::connected, this, [this]() -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::connected, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText("socket is connected.");
        });

        // note: for udpsocket, it is useless.
        QObject::connect(_socket, &QUdpSocket::disconnected, this, [this]() -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::disconnected, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText("socket is disconnected.");
        });

        QObject::connect(_socket, &QUdpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {");

            Socket_State(state);
        });

        QObject::connect(_socket, &QUdpSocket::readyRead, this, [this]() -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::readyRead, this, [this]() -> void {");

            QByteArray data = QByteArray();
            iptr leng = 0;
            QHostAddress address = QHostAddress();
            quint16 port = quint16();
            while(_socket->hasPendingDatagrams() == true) {
                leng = data.size();
                data.resize(leng + _socket->pendingDatagramSize());
                _socket->readDatagram(data.data() + leng, _socket->pendingDatagramSize(), &address, &port);
            }
            if(address.toString().size() > 0 && port > 0) { // note: to avoid useless echo.
                _ui->PTE_Log->appendPlainText(QString("[%1:%2] ").arg(address.toString()).arg(port) + data);
            }
        });

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {");

            QString address = _ui->CB_Address->currentText();
            iptr port = _ui->SB_Port ->value();
            QByteArray message = _ui->PTE_Message->toPlainText().toUtf8();
            _socket->writeDatagram(message, QHostAddress(address), port);
            _ui->PTE_Log->appendPlainText("[out] " + message);
            _ui->PTE_Message->clear();
            _ui->PTE_Message->setFocus();
        });

        QObject::connect(_ui->PB_Broadcast, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Broadcast, &QPushButton::clicked, this, [this]() -> void {");

            iptr port = _ui->SB_Port ->value();
            QByteArray message = _ui->PTE_Message->toPlainText().toUtf8();
            _socket->writeDatagram(message, QHostAddress(QHostAddress::Broadcast), port);
            _ui->PTE_Log->appendPlainText("[broadcast] " + message);
            _ui->PTE_Message->clear();
            _ui->PTE_Message->setFocus();
        });
    }

    virtual ~Interphone() override {
        System::Logging(__FUNCTION__);

        _socket->close();
        // _socket->abort();
        delete _ui;
    }

    void Setup() {
        System::Logging(__FUNCTION__);

        if(_type == _Talkie) {
            _ui->SB_Bind->setValue(_Talkie_Port);
            _ui->CB_Address->addItem(_Walkie_Address);
            QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
            for(auto beg = addresses.begin(), end = addresses.end(); beg != end; beg += 1) {
                QHostAddress address = (*beg);
                if(address.protocol() == QAbstractSocket::IPv4Protocol) {
                    _ui->CB_Address->addItem(address.toString());
                }
            }
            _ui->CB_Address->setCurrentText(_Walkie_Address);
            _ui->SB_Port->setValue(_Walkie_Port);
        } else if (_type == _Walkie) {
            _ui->SB_Bind->setValue(_Walkie_Port);
            _ui->CB_Address->addItem(_Talkie_Address);
            QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
            for(auto beg = addresses.begin(), end = addresses.end(); beg != end; beg += 1) {
                QHostAddress address = (*beg);
                if(address.protocol() == QAbstractSocket::IPv4Protocol) {
                    _ui->CB_Address->addItem(address.toString());
                }
            }
            _ui->CB_Address->setCurrentText(_Talkie_Address);
            _ui->SB_Port->setValue(_Talkie_Port);
        }
    }

public:
    void Socket_State(const QAbstractSocket::SocketState &state) {
        System::Logging(__FUNCTION__);

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
    }
};

#endif // Interphone_h
