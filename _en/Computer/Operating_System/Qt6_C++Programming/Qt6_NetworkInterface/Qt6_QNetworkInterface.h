/* Qt6_QNetworkInterface.h
Author: BSS9395
Update: 2023-08-31T16:26:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QNETWORKINTERFACE_H
#define QT6_QNETWORKINTERFACE_H

#include <QMainWindow>
#include "ui_Qt6_QNetworkInterface.h"
#include <QHostInfo>
#include <QNetworkInterface>

class Qt6_QNetworkInterface : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Qt6_QNetworkInterface *_ui = nullptr;

public:
    Qt6_QNetworkInterface(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QNetworkInterface) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_AllAddresses, &QPushButton::clicked, this, [this]() -> void {
            _ui->PTE_Message->clear();
            QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
            for(int i = 0; i < addresses.size(); i += 1) {
                QHostAddress address = addresses.at(i);
                bool show = _ui->CB_IPv4->isChecked() ? (address.protocol() == QAbstractSocket::IPv4Protocol) : true;
                if(show == true) {
                    _ui->PTE_Message->appendPlainText("########################################");
                    _ui->PTE_Message->appendPlainText(QString("协议: %1").arg(_Protocol(address.protocol())));
                    _ui->PTE_Message->appendPlainText(QString("地址: %1").arg(address.toString()));
                    _ui->PTE_Message->appendPlainText(QString("isGlobal: %1").arg(address.isGlobal() ? "true": "false"));
                    _ui->PTE_Message->appendPlainText(QString("isBroadcast: %1").arg(address.isBroadcast() ? "true" : "false"));
                    _ui->PTE_Message->appendPlainText(QString("isLoopback: %1").arg(address.isLoopback() ? "true" : "false"));
                    _ui->PTE_Message->appendPlainText(QString("isMulticast: %1").arg(address.isMulticast() ? "true" : "false"));
                }
            }
        });

        QObject::connect(_ui->PB_AllInterfaces, &QPushButton::clicked, this, [this]() -> void {
            _ui->PTE_Message->clear();
            QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
            for(int i = 0; i < interfaces.size(); i += 1) {
                QNetworkInterface interface = interfaces.at(i);
                _ui->PTE_Message->appendPlainText("########################################");
                _ui->PTE_Message->appendPlainText("设备名称: " + interface.humanReadableName());
                _ui->PTE_Message->appendPlainText("硬件地址: " + interface.hardwareAddress());
                _ui->PTE_Message->appendPlainText("接口类型: " + _Interface_Type(interface.type()));
                QList<QNetworkAddressEntry> entries = interface.addressEntries();
                for(int i = 0; i < entries.size(); i += 1) {
                    _ui->PTE_Message->appendPlainText("####################");
                    QNetworkAddressEntry entry = entries.at(i);
                    _ui->PTE_Message->appendPlainText("IP地址: " + entry.ip().toString());
                    _ui->PTE_Message->appendPlainText("子网掩码: " + entry.netmask().toString());
                    _ui->PTE_Message->appendPlainText("广播地址: " + entry.broadcast().toString());
                }
            }
        });

    }

    ~Qt6_QNetworkInterface() {
        delete _ui;
    }


public:
    QString _Interface_Type(QNetworkInterface::InterfaceType type) {
        switch(type) {
        case QNetworkInterface::Unknown:
            return "Unknown";
        case QNetworkInterface::Loopback:
            return "Loopback";
        case QNetworkInterface::Wifi:
            return "Wifi";
        default:
            return "Unknown";
        }
    }

    QString _Protocol(QAbstractSocket::NetworkLayerProtocol protocol) {
        switch(protocol) {
        case QAbstractSocket::IPv4Protocol:
            return "IPv4";
        case QAbstractSocket::IPv6Protocol:
            return "IPv6";
        case QAbstractSocket::AnyIPProtocol:
            return "Any";
        default:
            return "Unkown";
        }
    }
};
#endif // QT6_QNETWORKINTERFACE_H
