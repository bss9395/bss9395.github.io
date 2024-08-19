#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H

#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QLocalServer>
#include <QLocalSocket>
#include <QThread>
#include <QTimer>
#include "MainWindow.h"

class SingleApplication : public QApplication {
    Q_OBJECT

public:
    inline static const QString _local_server_name = "QLocalServer";

public:
    /*
    On Unix if the server crashes without closing listen will fail with AddressInUseError.
    To create a new server the file should be removed.
    On Windows two local servers can listen to the same pipe at the same time,
    but any connections will go to one of the server.
    */
    QLocalServer *_local_server = nullptr;
    long _count = 0;

public:
    void _Connect_Server() {
        QLocalSocket *local_client = new QLocalSocket();
        local_client->setProperty("_connected", false);

        QObject::connect(local_client, &QLocalSocket::connected, this, [this, local_client]() -> void {
            qDebug().noquote() << "QObject::connect(socket_local, &QLocalSocket::connected, this, [this, local_client]() -> void {";
            local_client->setProperty("_connected", true);

            QByteArray greeting = "Hello, Server!";
            local_client->write(greeting.data(), greeting.size());
            local_client->flush();

            // 进入主循环
            QTimer::singleShot(0, this, [this]() -> void {
                (void)this;
                QApplication::exit(0);  // 退出程序
            });
        });

        QObject::connect(local_client, &QLocalSocket::readyRead, this, [this, local_client]() -> void {
            qDebug().noquote() << "QObject::connect(socket_local, &QLocalSocket::readyRead, this, [this, local_client]() -> void {";
            QByteArray echo = local_client->readAll();
            qDebug().noquote() << echo;
            local_client->close();  // 关闭连接
        });

        QObject::connect(local_client, &QLocalSocket::disconnected, this, [this, local_client]() mutable -> void {
            qDebug().noquote() << "QObject::connect(socket_local, &QLocalSocket::disconnected, this, [this, local_client]() mutable -> void {";
            local_client->deleteLater(), local_client = nullptr;
        });

        QObject::connect(local_client, &QLocalSocket::stateChanged, this, [this, local_client](QLocalSocket::LocalSocketState state) -> void {
            // qDebug().noquote() << "QObject::connect(socket_local, &QLocalSocket::stateChanged, this, [this, local_client](QLocalSocket::LocalSocketState state) -> void {";
            if(state == QLocalSocket::UnconnectedState) {
                qDebug().noquote() << "[UnconnectedState]";
                if(local_client->property("_connected").toBool() == false) {
                    qDebug().noquote() << "连接服务端超时";
                    _Server_Listening();
                }
            } else if(state == QLocalSocket::ConnectingState) {
                qDebug().noquote() << "[ConnectingState]";
            } else if(state == QLocalSocket::ConnectedState) {
                qDebug().noquote() << "[ConnectedState]";
            } else if(state == QLocalSocket::ClosingState) {
                qDebug().noquote() << "[ClosingState]";
            }
        });

        local_client->connectToServer(_local_server_name);
        local_client->waitForConnected(100);
    }

    void _Server_Listening() {
        _local_server = new QLocalServer();  // 自建服务端

        QObject::connect(_local_server, &QLocalServer::newConnection, this, [this]() -> void {
            QLocalSocket *local_client = _local_server->nextPendingConnection();

            QObject::connect(local_client, &QLocalSocket::connected, this, [this, local_client]() -> void {
                qDebug().noquote() << "QObject::connect(local_client, &QLocalSocket::connected, this, [this, local_client]() -> void {";
                QByteArray greeting = "Hello, Client!";
                local_client->write(greeting);
                local_client->flush();

                _count += 1;
                emit _Signal_Connected();
            });
            emit local_client->connected();  // QLocalSocket缺失状态connected

            QObject::connect(local_client, &QLocalSocket::readyRead, this, [this, local_client]() -> void {
                qDebug().noquote() << "QObject::connect(local_client, &QLocalSocket::readyRead, this, [this, local_client]() -> void {";
                QByteArray echo = local_client->readAll();
                qDebug().noquote() << echo;
                emit _Signal_Echo(QString("[%1] %2").arg(_count).arg(QString(echo)));
                local_client->close();  // 关闭连接
            });

            QObject::connect(local_client, &QLocalSocket::disconnected, this, [this, local_client]() mutable -> void {
                qDebug().noquote() << "QObject::connect(local_client, &QLocalSocket::disconnected, this, [this, local_client]() mutable -> void {";
                local_client->deleteLater(), local_client = nullptr;
            });

            QObject::connect(local_client, &QLocalSocket::stateChanged, this, [this, local_client](QLocalSocket::LocalSocketState state) -> void {
                // qDebug().noquote() << "QObject::connect(socket_local, &QLocalSocket::stateChanged, this, [this, local_client](QLocalSocket::LocalSocketState state) -> void {";
                if(state == QLocalSocket::UnconnectedState) {
                    qDebug().noquote() << "[UnconnectedState]";
                } else if(state == QLocalSocket::ConnectingState) {
                    qDebug().noquote() << "[ConnectingState]";
                } else if(state == QLocalSocket::ConnectedState) {
                    qDebug().noquote() << "[ConnectedState]";
                } else if(state == QLocalSocket::ClosingState) {
                    qDebug().noquote() << "[ClosingState]";
                }
            });
        });

        QLocalServer::removeServer(_local_server_name);
        _local_server->listen(_local_server_name);
    }

public:
    void _Connect_Server_Wait() {
        QLocalSocket local_client;
        local_client.connectToServer(_local_server_name);

        if(local_client.waitForConnected(10) == true) {
            qDebug().noquote() << QString("%1:%2在运行中").arg(_local_server_name).arg(local_client.serverName());
            local_client.waitForReadyRead();
            QByteArray greeting = local_client.readAll();
            if(0 < greeting.size()) {
                qDebug().noquote() << greeting;
            }

            QByteArray echo = "Hello, Server!";
            local_client.write(echo);
            local_client.flush();

            // 进入主事件循环
            QTimer::singleShot(0, this, [this]() -> void {
                (void)this;
                QApplication::exit(0);  // 退出程序
            });
        } else {
            _local_server = new QLocalServer();

            QObject::connect(_local_server, &QLocalServer::newConnection, this, [this]() -> void {
                qDebug().noquote() << "QObject::connect(_local_server, &QLocalServer::newConnection, this, [this]() -> void {";

                QLocalSocket *local_client = _local_server->nextPendingConnection();
                _count += 1;
                emit _Signal_Connected();

                QByteArray greeting = "Hello, Client!";
                local_client->write(greeting);
                local_client->flush();

                QElapsedTimer elapsedTimer;
                elapsedTimer.start();
                local_client->waitForReadyRead();
                QByteArray echo = local_client->readAll();
                if(0 < echo.size()) {
                    qDebug().noquote() << "echo = " << echo;
                    emit _Signal_Echo(QString("[%1] %2").arg(_count).arg(QString(echo)));
                }
                qDebug().noquote() << "elapsedTimer.elapsed() = " << elapsedTimer.elapsed();

                local_client->deleteLater(), local_client = nullptr;
            });

            QLocalServer::removeServer(_local_server_name);
            _local_server->listen(_local_server_name);
        }
    }

    void _Connect_Server_Lite() {
        QLocalSocket local_client;
        local_client.connectToServer(_local_server_name);

        if(local_client.waitForConnected(10) == true) {
            qDebug().noquote() << QString("%1:%2在运行中").arg(_local_server_name).arg(local_client.serverName());

            // 进入主事件循环
            QTimer::singleShot(0, this, [this]() -> void {
                (void)this;
                QApplication::exit(0);  // 退出程序
            });
        } else {
            _local_server = new QLocalServer();

            QObject::connect(_local_server, &QLocalServer::newConnection, this, [this]() -> void {
                qDebug().noquote() << "QObject::connect(_local_server, &QLocalServer::newConnection, this, [this]() -> void {";

                QLocalSocket *local_client = _local_server->nextPendingConnection();
                _count += 1;
                emit _Signal_Connected();
                emit _Signal_Echo(QString("[%1] %2").arg(_count).arg("echo"));

                local_client->deleteLater(), local_client = nullptr;
            });

            QLocalServer::removeServer(_local_server_name);
            _local_server->listen(_local_server_name);
        }
    }

public:
    SingleApplication(int argc, char *argv[])
        : QApplication(argc, argv) {

        // _Connect_Server();
        // _Connect_Server_Wait();
        _Connect_Server_Lite();
    }

signals:
    void _Signal_Connected();
    void _Signal_Echo(const QString& echo);
};

#endif // SINGLEAPPLICATION_H
