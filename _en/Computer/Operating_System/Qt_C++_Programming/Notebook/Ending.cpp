/* Ending.cpp
Author: BSS9395
Update: 2022-02-05T00:05:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14
Notice: Bug on Visual Studio 2017
*/

#include "Common.h"

Ending::Ending(QWidget *parent)
    : QDialog(parent), _ui(new Ui::Ending) {
    Logging(__FUNCTION__);
    _ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint, true);
    // this->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    this->resize(_ui->GB_Ending->sizeHint().width(), _ui->GB_Ending->sizeHint().height());

    QPoint pos = (parent == nullptr) ? QCursor::pos() : parent->parentWidget()->mapToGlobal(parent->pos());
    pos.setY(pos.y() - this->size().height());
    this->move(pos);

    QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this]() -> void {");
        (void) checked;
        emit Update_Ending("LF");
    });

    QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this]() -> void {");
        (void) checked;
        emit Update_Ending("CRLF");
    });

    QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {");
        (void) checked;
        emit Update_Ending("CR");
    });
}

Ending::~Ending() {
    Logging(__FUNCTION__);

    delete _ui;
}
