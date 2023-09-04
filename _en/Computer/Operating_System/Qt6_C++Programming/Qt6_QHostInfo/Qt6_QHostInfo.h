/* Qt6_QHostInfo.h
Author: BSS9395
Update: 2023-08-31T15:28:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QHOSTINFO_H
#define QT6_QHOSTINFO_H

#include <QMainWindow>
#include "ui_Qt6_QHostInfo.h"
#include <QHostInfo>
#include <QNetworkInterface>

class Qt6_QHostInfo : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Qt6_QHostInfo *_ui = nullptr;

public:
    Qt6_QHostInfo(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QHostInfo) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_HostInfo, &QPushButton::clicked, this, [this]() -> void {
            _ui->PTE_Message->clear();
            QString hostname = QHostInfo::localHostName();
            _ui->PTE_Message->appendPlainText(QString("本机主机名: %1").arg(hostname));

            QHostInfo hostinfo = QHostInfo::fromName(hostname);
            QList<QHostAddress> addresses = hostinfo.addresses();
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

        QObject::connect(_ui->PB_Lookup, &QPushButton::clicked, this, [this]() -> void {
            _ui->PTE_Message->clear();
            QString hostname = _ui->LE_Domain->text().trimmed();
            _ui->PTE_Message->appendPlainText(QString("主机信息: %1").arg(hostname));
            QHostInfo::lookupHost(hostname, this, [this](const QHostInfo &host) -> void {
                QList<QHostAddress> addresses = host.addresses();
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
        });
    }

    ~Qt6_QHostInfo() {
        delete _ui;
    }

public:
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
#endif // QT6_QHOSTINFO_H
