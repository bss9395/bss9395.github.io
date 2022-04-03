/* Chat.h
Author: BSS9395
Update: 2022-04-03T17:45:00+08@China-Shanghai+08
Design: Chat
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Chat_h
#define Chat_h

#define Header_h
#include "Common.h"
#include "ui_Chat.h"
#include "System.h"

class Chat : public QMainWindow {
    Q_OBJECT

public:
    static inline const QStringList _Multi = {
        "239.255.43.21",
        "239.255.100.1",
        "239.255.255.100",
        "238.238.238.238"
    };
    static inline const iptr _Port = 9395;

public:
    Ui::Chat *_ui = nullptr;
    QUdpSocket _socket = QUdpSocket(this);
    QString _address = QString();
    iptr _port = 0;

public:
    explicit Chat(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Chat) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        Setup();

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Log->clear();
        });

        QObject::connect(_ui->A_Join, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Join, &QAction::triggered, this, [this]() -> void {");

            _address = _ui->CB_Address->currentText();
            _port = _ui->SB_Port->value();
            if(_socket.bind(QHostAddress::AnyIPv4, _port, QUdpSocket::ShareAddress) == true) {
                _socket.joinMulticastGroup(QHostAddress(_address));
                _ui->PTE_Log->appendPlainText(QString("已加入组播%1:%2").arg(_address).arg(_port));
            } else {
                _ui->PTE_Log->appendPlainText(QString("未加入组播%1:%2").arg(_address).arg(_port));
            }
        });

        QObject::connect(_ui->A_Leave, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Leave, &QAction::triggered, this, [this]() -> void {");

            _socket.leaveMulticastGroup(QHostAddress(_address));
            _socket.close();
            _ui->PTE_Log->appendPlainText(QString("已离开组播%1:%2").arg(_address).arg(_port));
        });

        // note: for udpsocket, it is useless.
        QObject::connect(&_socket, &QUdpSocket::connected, this, [this]() -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::connected, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText("socket is connected.");
        });

        // note: for udpsocket, it is useless.
        QObject::connect(&_socket, &QUdpSocket::disconnected, this, [this]() -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::disconnected, this, [this]() -> void {");

            _ui->PTE_Log->appendPlainText("socket is disconnected.");
        });

        QObject::connect(&_socket, &QUdpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {
            System::Logging("QObject::connect(_socket, &QUdpSocket::stateChanged, this, [this](QAbstractSocket::SocketState state) -> void {");

            Socket_State(state);
        });

        QObject::connect(&_socket, &QUdpSocket::readyRead, this, [this]() -> void {
            System::Logging("QObject::connect(&_socket, &QUdpSocket::readyRead, this, [this]() -> void {");

            QByteArray data = QByteArray();
            iptr leng = 0;
            QHostAddress address = QHostAddress();
            quint16 port = 0;
            while(_socket.hasPendingDatagrams() == true) {
                leng = data.size();
                data.resize(leng + _socket.pendingDatagramSize());
                _socket.readDatagram(data.data() + leng, _socket.pendingDatagramSize(), &address, &port);
            }
            _ui->PTE_Log->appendPlainText(QString("[%1:%2] %3").arg(address.toString()).arg(port).arg(QString(data)));
        });

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {");

            QByteArray message = _ui->PTE_Message->toPlainText().toUtf8();
            _socket.writeDatagram(message, QHostAddress(_address), _port);
            _ui->PTE_Log->appendPlainText("[multicast] " + message);
            _ui->PTE_Message->clear();
            _ui->PTE_Message->setFocus();
        });
    }

    virtual ~Chat() override {
        System::Logging(__FUNCTION__);

        _socket.close();
        delete _ui;
    }

    void Setup() {
        System::Logging(__FUNCTION__);

        _socket.setSocketOption(QAbstractSocket::MulticastTtlOption, 128);  // note: TTL=1, udp datagrams only transfer on local subnet.
        _ui->CB_Address->addItems(_Multi);
        _ui->SB_Port->setValue(_Port);
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

#endif // Chat_h
