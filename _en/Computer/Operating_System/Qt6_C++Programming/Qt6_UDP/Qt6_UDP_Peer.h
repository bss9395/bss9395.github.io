/* Qt6_UDP_Peer.h
Author: BSS9395
Update: 2023-09-01T14:45:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_UDP_PEER
#define QT6_UDP_PEER

#include <QMainWindow>
#include "ui_Qt6_UDP_Peer.h"
#include <QtNetwork>

class Qt6_UDP_Peer : public QMainWindow {
    Q_OBJECT

public:
    Ui::Qt6_UDP_Peer *_ui   = nullptr;
    QUdpSocket *_udp_socket = new QUdpSocket();

public:
    Qt6_UDP_Peer(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_UDP_Peer) {
        _ui->setupUi(this);

        _ui->A_Bind->setEnabled(true);
        _ui->A_Unbind->setEnabled(false);
        QObject::connect(_ui->A_Bind, &QAction::triggered, this, [this]() -> void {
            quint16 port = _ui->SB_Port_Bound->value();
            if(_udp_socket->bind(port) == true) {
                _ui->PTE_Message->appendPlainText(QString("##绑定端口成功，端口号%1##").arg(port));
                _ui->A_Bind->setEnabled(false);
                _ui->A_Unbind->setEnabled(true);
            } else {
                _ui->PTE_Message->appendPlainText(QString("##绑定端口失败，端口号%1##").arg(port));
            }
        });

        QObject::connect(_ui->A_Unbind, &QAction::triggered, this, [this]() -> void {
            _udp_socket->close();
            _ui->A_Bind->setEnabled(true);
            _ui->A_Unbind->setEnabled(false);
        });

        QObject::connect(_ui->PB_Send, &QPushButton::clicked, this, [this]() -> void {
            QString message = _ui->LE_Message->text();
            QString peer_ipv4 = _ui->CB_IPv4->currentText();
            quint16 peer_port = _ui->SB_Port_Destination->value();
            _udp_socket->writeDatagram(message.toUtf8(), QHostAddress(peer_ipv4), peer_port);
            _ui->LE_Message->clear();
            _ui->LE_Message->setFocus();
            QString local_ipv4 = _udp_socket->localAddress().toString();
            quint16 local_port = _udp_socket->localPort();
            QString out = QString("[out, %1:%2] ").arg(local_ipv4).arg(local_port);
            _ui->PTE_Message->appendPlainText(out + message);
        });

        QObject::connect(_ui->PB_Broadcast, &QPushButton::clicked, this, [this]() -> void {
            QString message = _ui->LE_Message->text();
            quint16 port = _ui->SB_Port_Destination->value();
            _udp_socket->writeDatagram(message.toUtf8(), QHostAddress::Broadcast, port);
            _ui->LE_Message->clear();
            _ui->LE_Message->setFocus();
            _ui->PTE_Message->appendPlainText("[broadcast] " + message);
        });

        QObject::connect(_udp_socket, &QUdpSocket::readyRead, this, [this]() -> void {
            while(_udp_socket->hasPendingDatagrams()) {
                QByteArray datagram;
                datagram.resize(_udp_socket->pendingDatagramSize());

                QHostAddress peer_ipv4;
                quint16 peer_port = 0;
                _udp_socket->readDatagram(datagram.data(), datagram.size(), &peer_ipv4, &peer_port);
                QString in = QString("[in , %1:%2] ").arg(peer_ipv4.toString()).arg(peer_port);
                _ui->PTE_Message->appendPlainText(in + QString::fromUtf8(datagram));
            }
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
        QObject::connect(_udp_socket, &QUdpSocket::stateChanged, this, lambda_statechanged);
        lambda_statechanged(_udp_socket->state());
    }

    ~Qt6_UDP_Peer() {
        delete _ui;
        delete _udp_socket;
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
};
#endif // QT6_UDP_PEER
