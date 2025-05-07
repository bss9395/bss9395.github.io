#pragma once

#include <QMainWindow>
#include <QSharedMemory>
#include <QFileDialog>
#include <QDataStream>
#include <QDebug>
#include <QBuffer>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Ui::MainWindow *_ui;
    QSharedMemory _sharedMemory;

public:
    MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
        _ui->setupUi(this);
        _sharedMemory.setKey("bss9395");

        QObject::connect(_ui->_loadFromFile, &QPushButton::clicked, this, [this]() {
            QString filename = QFileDialog::getOpenFileName(nullptr, "请选择图片", QApplication::applicationDirPath(), "Image (*.png *.jpg)");
            if(filename.isEmpty()) {
                return;
            }
            QImage image;
            image.load(filename);
            _ui->_label->setPixmap(QPixmap::fromImage(image));

            QBuffer buffer;
            buffer.open(QBuffer::ReadWrite);
            QDataStream out(&buffer);
            out << image;

            _sharedMemory.create(buffer.size());
            _sharedMemory.lock();
            memcpy((char*)_sharedMemory.data(), (char*)buffer.data().data(), _sharedMemory.size());
            _sharedMemory.unlock();
        });

        QObject::connect(_ui->_loadFromSharedMemory, &QPushButton::clicked, this, [this]() {
            QBuffer buffer;
            QDataStream in(&buffer);
            QImage image;
            _sharedMemory.lock();
            buffer.setData((char*)_sharedMemory.data(), _sharedMemory.size());
            buffer.open(QBuffer::ReadOnly);
            in >> image;
            _sharedMemory.unlock();
            _ui->_label->setPixmap(QPixmap::fromImage(image));
        });
    }

    ~MainWindow() {
        delete _ui;
    }
};

