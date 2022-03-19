/* Lookup.h
Author: BSS9395
Update: 2022-03-19T16:46:00+08@China-Shanghai+08
Design: Lookup
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Lookup_h
#define Lookup_h

#define Header_h
#include "Common.h"
#include "ui_Lookup.h"
#include "System.h"


class Lookup : public QMainWindow {
    Q_OBJECT

public:
    Ui::Lookup *_ui = nullptr;

public:
    explicit Lookup(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Lookup) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Information->clear();
        });

        QObject::connect(_ui->A_Hostname, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Host, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Information->appendPlainText("========================================");
            QString hostname = QHostInfo::localHostName();                              // note: retrive local host name.
            _ui->PTE_Information->appendPlainText(QString("本机名: %1").arg(hostname));
            _ui->PTE_Information->appendPlainText(QString("本机域名: %1").arg(QHostInfo::localDomainName()));
            QHostInfo hostinfo = QHostInfo::fromName(hostname);                         // note: retrive host info by name.
            QList<QHostAddress> addresses = hostinfo.addresses();                       // note: retrive ip addresses.
            for(auto beg = addresses.begin(), end = addresses.end(); beg != end; beg += 1) {
                _ui->PTE_Information->appendPlainText("====================");
                QHostAddress address = (*beg);
                _ui->PTE_Information->appendPlainText(QString("协议: %1").arg(Protocol_String(address.protocol())));
                _ui->PTE_Information->appendPlainText(address.toString());
            }
        });

        QObject::connect(_ui->A_Lookup, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Lookup, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Information->appendPlainText("========================================");
            QString hostname = _ui->LE_Hostname->text();
            _ui->PTE_Information->appendPlainText(QString("查找主机: %1").arg(hostname));
            QHostInfo::lookupHost(hostname, this, [this](QHostInfo hostinfo) -> void {
                System::Logging("QHostInfo::lookupHost(hostname, this, [this](QHostInfo hostinfo) -> void {");

                QList<QHostAddress> addresses = hostinfo.addresses();
                for(auto beg = addresses.begin(), end = addresses.end(); beg != end; beg += 1) {
                    _ui->PTE_Information->appendPlainText("====================");
                    QHostAddress address = (*beg);
                    _ui->PTE_Information->appendPlainText(QString("协议: %1").arg(Protocol_String(address.protocol())));
                    _ui->PTE_Information->appendPlainText(address.toString());
                }
            });
        });

        QObject::connect(_ui->A_Interface, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Interface, &QAction::triggered, this, [this]() -> void {");

            _ui->PTE_Information->appendPlainText("========================================");
            QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
            for(auto beg = interfaces.begin(), end = interfaces.end(); beg != end; beg += 1) {
                QNetworkInterface interface = (*beg);
                if(interface.isValid() == false) {
                    continue;
                }
                _ui->PTE_Information->appendPlainText("====================");
                _ui->PTE_Information->appendPlainText(QString("设备名: %1").arg(interface.humanReadableName()));
                _ui->PTE_Information->appendPlainText(QString("连接名: %1").arg(interface.name()));
                _ui->PTE_Information->appendPlainText(QString("硬件名: %1").arg(interface.hardwareAddress()));
                QList<QNetworkAddressEntry> entries = interface.addressEntries();
                for(auto beg = entries.begin(), end = entries.end(); beg != end; beg += 1) {
                    QNetworkAddressEntry entry = (*beg);
                    _ui->PTE_Information->appendPlainText(QString("IP 地址：%1").arg(entry.ip().toString()));
                    _ui->PTE_Information->appendPlainText(QString("子网掩码：%1").arg(entry.netmask().toString()));
                    _ui->PTE_Information->appendPlainText(QString("广播地址：%1").arg(entry.broadcast().toString()));
                }
            }
        });

    }

    virtual ~Lookup() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    const QString &Protocol_String(const QAbstractSocket::NetworkLayerProtocol &protocol) {
        System::Logging(__FUNCTION__);

        typedef const QString Type;
        static const Type IPv4 = Type("IPv4");
        static const Type IPv6 = Type("IPv6");
        static const Type Auto = Type("Auto");
        static const Type Unknown = Type("Unknown");

        if(protocol == QAbstractSocket::IPv4Protocol) {
            return IPv4;
        } else if(protocol == QAbstractSocket::IPv6Protocol) {
            return IPv6;
        } else if(protocol == QAbstractSocket::AnyIPProtocol) {
            return Auto;
        } else {
            return Unknown;
        }
        return Unknown;
    }

};
#endif // Lookup_h
