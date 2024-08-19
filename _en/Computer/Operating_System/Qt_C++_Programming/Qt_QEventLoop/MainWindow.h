#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QEventLoop>
#include <QMainWindow>
#include <QThread>
#include "ui_MainWindow.h"

// 主页面线程
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    Ui::MainWindow *_ui = nullptr;
    QEventLoop _eventLoop;

public:
    explicit MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
        _ui->setupUi(this);

        QObject::connect(_ui->_pb_for, &QPushButton::clicked, this, [this]() -> void {
            if(_eventLoop.isRunning() == true) {
                return;
            }
            qDebug().noquote() << "enter";
            // 点击For Loop按钮，连续10次进入EventLoop，点击Exit EventLoop按钮，单次退出EventLoop。
            for(int i = 0; i < 10; i += 1) {
                qDebug().noquote() << i;
                _ui->_l_label->setText(QString("%1").arg(i));
                _eventLoop.exec();
            }
            qDebug().noquote() << "leave";
        });

        QObject::connect(_ui->_pb_exit, &QPushButton::clicked, this, [this]() -> void {
            qDebug().noquote() << "exit";
            _eventLoop.exit();
        });
    }

    virtual ~MainWindow() {
        delete _ui;
        _ui = nullptr;
    }
};

#endif // MAINWINDOW_H
