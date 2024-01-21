/* Qt6_UDP_Multicast.h
Author: BSS9395
Update: 2023-09-01T17:13:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_UDP_MULTICAST_H
#define QT6_UDP_MULTICAST_H

#include <QMainWindow>
#include "ui_Qt6_UDP_Multicast.h"
#include <QtNetwork>

class Qt6_UDP_Multicast : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_UDP_Multicast *_ui = nullptr;
    QUdpSocket *_udp_socket = new QUdpSocket();

public:
    Qt6_UDP_Multicast(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_UDP_Multicast) {
        _ui->setupUi(this);

        _ui->A_Join->setEnabled(true);
        _ui->A_Leave->setEnabled(false);
        QObject::connect(_ui->A_Join, &QAction::triggered, this, [this]() -> void {
            quint16 port = _ui->SB_Port->value();
            if(true == _udp_socket->bind(QHostAddress::AnyIPv4, port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint)) {
                QString ipv4 = _ui->CB_IPv4->currentText();
                _udp_socket->joinMulticastGroup(QHostAddress(ipv4));
                _udp_socket->setSocketOption(QAbstractSocket::MulticastTtlOption, 255);
                _ui->PTE_Message->appendPlainText(QString("##加入组播成功%1:%2##").arg(ipv4).arg(port));
                _ui->A_Join->setEnabled(false);
                _ui->A_Leave->setEnabled(true);
                _ui->CB_IPv4->setEnabled(false);
                _ui->SB_Port->setEnabled(false);
            } else {
                _ui->PTE_Message->appendPlainText("##绑定端口失败##");
            }
        });

        QObject::connect(_ui->A_Leave, &QAction::triggered, this, [this]() -> void {
            QString ipv4 = _ui->CB_IPv4->currentText();
            _udp_socket->leaveMulticastGroup(QHostAddress(ipv4));
            _udp_socket->close();
            _ui->A_Join->setEnabled(true);
            _ui->A_Leave->setEnabled(false);
            _ui->CB_IPv4->setEnabled(true);
            _ui->SB_Port->setEnabled(true);
            _ui->PTE_Message->appendPlainText(QString("##已退出组播%1##").arg(ipv4));
        });

        QObject::connect(_ui->PB_Multicast, &QPushButton::clicked, this, [this]() -> void{
            QString message = _ui->LE_Message->text();
            QString ipv4 = _ui->CB_IPv4->currentText();
            quint16 port = _ui->SB_Port->value();
            _udp_socket->writeDatagram(message.toUtf8(), QHostAddress(ipv4), port);
            _ui->LE_Message->clear();
            _ui->LE_Message->setFocus();
            _ui->PTE_Message->appendPlainText("[multicast] " + message);
        });

        QObject::connect(_udp_socket, &QUdpSocket::readyRead, this, [this]() -> void {
            while(true == _udp_socket->hasPendingDatagrams()) {
                QByteArray datagram;
                datagram.resize(_udp_socket->pendingDatagramSize());
                QHostAddress ipv4;
                quint16      port = 0;
                _udp_socket->readDatagram(datagram.data(), datagram.size(), &ipv4, &port);
                QString in = QString("[in, %1:%2]").arg(ipv4.toString()).arg(port);
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

    ~Qt6_UDP_Multicast() {
        delete _ui;
        delete _udp_socket;
    }


};
#endif // QT6_UDP_MULTICAST_H
