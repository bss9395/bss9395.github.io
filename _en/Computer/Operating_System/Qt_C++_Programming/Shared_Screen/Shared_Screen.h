/* Shared_Screen.h
Author: BSS9395
Update: 2023-09-04T09:10:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef SHARED_SCREEN_H
#define SHARED_SCREEN_H

#include <QBuffer>
#include <QCursor>
#include <QCursor>#include <QDebug>
#include <QDateTime>
#include <QDebug>
#include <QGuiApplication>
#include <QHostAddress>
#include <QImageReader>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QMutex>
#include <QNetworkDatagram>
#include <QObject>
#include <QPixmap>
#include <QQueue>
#include <QScreen>
#include <QThread>
#include <QTimer>
#include <QUdpSocket>
#include <QtNetwork>
#include "ui_Shared_Screen.h"

static const int     _size_prefix   = 10;
static const int     _size_datagram = 10000;
static const int     _size_maxi     = 2000 * 1200;
static const int     _image_quality = 50;
static const QString _ipv4_group    = "239.255.43.21";
static const int     _port_group    = 9395;


class Thread_Recv : public QThread {
    Q_OBJECT

public:
    QUdpSocket *_udp_socket = nullptr;

public:
    Thread_Recv(QUdpSocket *udp_socket) {
        _udp_socket = udp_socket;
    }

public:
    void run() override {
        static char buffer_maxi[_size_maxi];
        static char buffer_frame[_size_prefix + _size_datagram + 10];

        while(true) {
            if(_udp_socket->hasPendingDatagrams() == true) {
                qDebug() << "_udp_socket->pendingDatagramSize() = " << _udp_socket->pendingDatagramSize();

                int leng = _udp_socket->readDatagram(buffer_frame, _size_prefix + _size_datagram);
                int count_frames = buffer_frame[3];
                int count_frame  = buffer_frame[4];

                memcpy(buffer_maxi + count_frame * _size_datagram, buffer_frame + _size_prefix, leng - _size_prefix);
                if(count_frame == count_frames - 1) {
                    QByteArray frame = QByteArray(buffer_maxi, count_frame * _size_datagram + leng - _size_prefix);
                    emit _New_Frame(frame);
                }
            }
        }
    }

signals:
    void _New_Frame(QByteArray frame);

};

class Thread_Send : public QThread {
    Q_OBJECT

public:
    QUdpSocket *_udp_socket = nullptr;

public:
    Thread_Send(QUdpSocket *udp_socket) {
        _udp_socket = udp_socket;
    }

public:
    void run() override {
        qDebug() << __FUNCTION__;
        while(true) {
            qDebug() << "while(_state == _state_send) {";

            QScreen *screen = QGuiApplication::primaryScreen();
            QPixmap pixmap = screen->grabWindow(0);
            QByteArray bytes;
            QBuffer buffer(&bytes);
            pixmap.save(&buffer, "jpg", _image_quality);
            int size = bytes.size();
            int count_frames = size / _size_datagram;
            (size % _size_datagram == 0) ? count_frames : (count_frames += 1);

            static char buffer_send[_size_prefix + _size_datagram + 10];
            buffer_send[0] = 'J';
            buffer_send[1] = 'P';
            buffer_send[2] = 'G';
            buffer_send[3] = count_frames;
            buffer_send[4] = 0;

            int offset = 0;
            while(offset < size) {
                int leng = (offset + _size_datagram <= size) ? _size_datagram : (size - offset);
                memcpy(buffer_send + _size_prefix, bytes.data() + offset, leng);
                _udp_socket->writeDatagram(buffer_send, _size_prefix + leng, QHostAddress(_ipv4_group), _port_group);
                _udp_socket->waitForBytesWritten();
                buffer_send[4] += 1;
                offset += _size_datagram;
                usleep(5);
            }
        }
    }
};


class Shared_Screen : public QMainWindow {
    Q_OBJECT
public:
    Ui::Shared_Screen *_ui = nullptr;
    QUdpSocket  *_udp_socket = new QUdpSocket();
    Thread_Recv *_thread_recv;
    Thread_Send *_thread_send;

public:
    Shared_Screen(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Shared_Screen) {
        _ui->setupUi(this);

        qDebug() << "绑定端口" << _udp_socket->bind(QHostAddress::AnyIPv4, _port_group, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
        qDebug() << "加入组播" << _udp_socket->joinMulticastGroup(QHostAddress(_ipv4_group));
        _udp_socket->setSocketOption(QUdpSocket::MulticastTtlOption, 255);

        _thread_recv = new Thread_Recv(_udp_socket);
        _thread_recv->start();
        QObject::connect(_thread_recv, &Thread_Recv::_New_Frame, this, [this](QByteArray frame) -> void {
            qDebug() << "QObject::connect(_thread_recv, &Thread_Recv::_New_Frame, this, [this](QByteArray frame) -> void {";
            QPixmap pixmap;
            pixmap.loadFromData((uchar *)frame.data(), frame.length());

            QSize size = _ui->L_Share->size();
            size.setWidth(size.width() - 10);
            size.setHeight(size.height() - 10);
            pixmap = pixmap.scaled(size, Qt::KeepAspectRatio);
            _ui->L_Share->setPixmap(pixmap);

            static int counter = 0;
            static qint64 time_last = QDateTime::currentMSecsSinceEpoch();
            if(counter += 1, counter == 10) {
                qint64 time_curr = QDateTime::currentMSecsSinceEpoch();
                int fps = 10 * 1000 / (time_curr - time_last);
                counter = 0;
                time_last = time_curr;
                _ui->SB_Status->showMessage(QString("FPS: %1, 每帧%2KB").arg(fps).arg(frame.size() / 1024));
            }
        });


        _thread_send = new Thread_Send(_udp_socket);
        QObject::connect(_ui->A_Share, &QAction::triggered, this, [this]() -> void {
             _thread_send->start();
        });
        QObject::connect(_ui->A_Stop, &QAction::triggered, this, [this]() -> void {
             _thread_send->terminate();
             _thread_send->wait();
            _ui->L_Share->setPixmap(QPixmap());
        });

        QObject::connect(_ui->A_Full_Screen, &QAction::triggered, this, [this]() -> void {
            this->showFullScreen();
        });

    }

    ~Shared_Screen() {
        delete _ui;

        _udp_socket->leaveMulticastGroup(QHostAddress(_ipv4_group));
        _udp_socket->close();
        delete _udp_socket;

        _thread_recv->terminate();
        delete _thread_recv;

        _thread_send->terminate();
        delete _thread_send;
    }

public:
    void keyPressEvent(QKeyEvent *event) {
        if (event->key() == Qt::Key_Escape) {
            this->showNormal();
        }
    }

};
#endif // SHARED_SCREEN_H
