#ifndef SOFTWARECENTER_H
#define SOFTWARECENTER_H

#include "ui_widget.h"
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusPendingCall>
#include <QDBusPendingCallWatcher>
#include <QDBusPendingReply>
#include <QDateTime>

class Widget : public QWidget {
    Q_OBJECT

public:
    Ui::Widget *_ui = nullptr;

public:
    explicit Widget(QWidget *parent = nullptr)
        : QWidget(parent), _ui(new Ui::Widget) {
        _ui->setupUi(this);
    }

    virtual ~Widget() {
        delete _ui;
    }
};

class SoftwareCenter: public QObject {
    Q_OBJECT

public:
    explicit SoftwareCenter() {
        // 操作系统安装软件进度
        QDBusConnection::systemBus().connect("com.kylin.systemupgrade", "/com/kylin/systemupgrade", "com.kylin.systemupgrade.interface", "InstalldebStatusChanged", this, SIGNAL(signal_installDebStatusChanged(const int &, const QString&, const QString &)));
        QObject::connect(this, &SoftwareCenter::signal_installDebStatusChanged, this, [](const int &progress, const QString &state, const QString &detail) -> void {
            // qDebug() << "QObject::connect(this, &SoftwareCenter::signal_installDebStatusChanged, this, [](const int &progress, const QString &state, const QString &detail) -> void {";
            qDebug() << "progress = " << progress << ", state = " << state << ", detail = " << detail;

        });

        // 操作系统安装软件完成
        QDBusConnection::systemBus().connect("com.kylin.systemupgrade", "/com/kylin/systemupgrade", "com.kylin.systemupgrade.interface", "InstalldebFinished", this, SIGNAL(signal_installDebFinished(const bool&, const QString &, const QString &)));
        QObject::connect(this, &SoftwareCenter::signal_installDebFinished, this, [](const bool &status, const QString &error, const QString &description) -> void {
            qDebug() << "QObject::connect(this, &SoftwareCenter::signal_installDebFinished, this, [](const bool &status, const QString &error, const QString &description) -> void {";
            qDebug() << "status = " << status << ", error = " << error << ", description = " << description;

        });
    }

public:
    void systemBusCall(const QString &debpath) {
        qDebug() << __FUNCTION__;

        class InstallingSoftware: public QThread {
        public:
            SoftwareCenter *_softwarecenter = nullptr;
            QString         _debpath;

        public:
            explicit InstallingSoftware(SoftwareCenter *softwarecenter, const QString &debpath) {
                qDebug() << __FUNCTION__;
                _softwarecenter = softwarecenter;
                _debpath = debpath;
            }

        public:
            void run() override {
                qDebug() << __FUNCTION__;
                qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss.zzz");

                QDBusMessage methodCall = QDBusMessage::createMethodCall("com.kylin.systemupgrade", "/com/kylin/systemupgrade", "com.kylin.systemupgrade.interface", "InstallDebFile");
                methodCall.setArguments(QList<QVariant>() << "kylin-installer" << _debpath << 0 << 1 << "zh_CN");
                QDBusMessage dbusMessage = QDBusConnection::systemBus().call(methodCall, QDBus::Block);
                if(dbusMessage.type() == QDBusMessage::ReplyMessage) {  // QDBusMessage::ReplyMessage或者QDBusMessage::ErrorMessage
                    int ret = dbusMessage.arguments()[0].toInt();
                    QString str = dbusMessage.arguments()[1].toString();
                    qDebug() << "ret = " << ret << ", str = " << str;
                } else {
                    qDebug().noquote() << "dbusMessage.arguments() = " << dbusMessage.arguments() << ", dbusMessage.errorName() = " << dbusMessage.errorName() << ", dbusMessage.errorMessage() = " << dbusMessage.errorMessage();
                }
            }
        };

        InstallingSoftware *thread = new InstallingSoftware(this, debpath);
        QObject::connect(thread, &QThread::finished, this, [thread]() -> void {
            qDebug() << "QObject::connect(thread, &QThread::finished, this, [thread]() -> void {";
            qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss.zzz");

            thread->deleteLater();
        });
        thread->start();
    }

    void systemBusAsyncCall(const QString &debpath) {
        qDebug() << __FUNCTION__;
        qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss.zzz");

        QDBusMessage methodCall = QDBusMessage::createMethodCall("com.kylin.systemupgrade", "/com/kylin/systemupgrade", "com.kylin.systemupgrade.interface", "InstallDebFile");
        methodCall.setArguments(QList<QVariant>() << "kylin-installer" << debpath << 0 << 1 << "zh_CN");
        QDBusPendingCall dbusPendingCall = QDBusConnection::systemBus().asyncCall(methodCall);
        QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(dbusPendingCall);
        QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, [](QDBusPendingCallWatcher *call) -> void {
            qDebug() << "QObject::connect(watcher, &QDBusPendingCallWatcher::finished, this, [](QDBusPendingCallWatcher *call) -> void {";
            qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-ddThh:mm:ss.zzz");

            QDBusPendingReply<int, QString> reply = (*call);
            if (reply.isError()) {
                qDebug().noquote() << "reply.error() = " << reply.error();
            } else {
                int ret = reply.argumentAt(0).toInt();
                QString str = reply.argumentAt(1).toString();
                qDebug().noquote() << "ret = " << ret << ", str = " << str;
            }
            call->deleteLater();
        });
    }

signals:
    void signal_installDebStatusChanged(const int &progress, const QString &status, const QString &detail);
    void signal_installDebFinished(const bool &status, const QString &error, const QString &description);
    void signal_installSoftwareStatusChanged(const QString &uuid, const int &progress, const QString &state, const QString &detail);
    void signal_installSoftwareFinished(const QString &uuid, const bool &status, const QString &description);
};

#endif // SOFTWARECENTER_H
