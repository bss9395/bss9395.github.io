#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFontMetrics>
#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    Ui::MainWindow *_ui = nullptr;

public:
    explicit MainWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
        _ui->setupUi(this);
    }

    virtual ~MainWindow() {
        delete _ui;
        _ui = nullptr;
    }

public:
    void _SetText(QString text) {
        QFontMetrics fontMetrics(_ui->L_label->font());
        _ui->L_label->setText(text);
        _ui->L_label->setFixedWidth(fontMetrics.width(text));
    }
};
#endif // MAINWINDOW_H
