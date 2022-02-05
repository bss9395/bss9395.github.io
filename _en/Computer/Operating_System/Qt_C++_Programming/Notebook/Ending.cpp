/* Ending.cpp
Author: BSS9395
Update: 2022-02-05T21:02:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14
Notice: Bug on Visual Studio 2017
*/

#include "Common.h"

bool Ending::event(QEvent *event) {
    // Logging(__FUNCTION__);

    if(event->type() == QEvent::FocusIn || event->type() == QEvent::Leave) {
        Logging("if(event->type() == QEvent::FocusIn) {");
        this->grabMouse();
        return true;
    } else if(event->type() == QEvent::Enter) {
        Logging("} else if(event->type() == QEvent::Enter) {");
        this->releaseMouse();
        return true;
    } else if(event->type() == QEvent::MouseButtonPress) {
        Logging("} else if(event->type() == QEvent::MouseButtonPress) {");
        this->releaseMouse();
        delete this; // note: mouse button press outside this widget.
        return true;
    }
    return QWidget::event(event);
}


Ending::Ending(QString platform, QWidget *parent)
    : QDialog(parent), _ui(new Ui::Ending) {
    Logging(__FUNCTION__);
    _ui->setupUi(this);

    if(platform == "LF") {
        _ui->RB_Unix->setChecked(true);
    } else if(platform == "CRLF") {
        _ui->RB_Windows->setChecked(true);
    } else if(platform == "CR") {
        _ui->RB_Mac->setChecked(true);
    }

    this->setWindowFlag(Qt::FramelessWindowHint, true);
    this->setWindowFlag(Qt::WindowStaysOnTopHint, true);
    this->resize(_ui->GB_Ending->sizeHint().width(), _ui->GB_Ending->sizeHint().height());

    QPoint pos = (parent == nullptr) ? QCursor::pos() : parent->parentWidget()->mapToGlobal(parent->pos());
    QScreen *screen = QGuiApplication::screenAt(pos);
    if(screen->geometry().width() < pos.x() + this->size().width()) {
        pos.setX(screen->geometry().width() - this->size().width());
    }
    pos.setY(pos.y() - this->size().height());
    this->move(pos);

    QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->RB_Unix, &QRadioButton::clicked, [this]() -> void {");
        (void) checked;
        emit Update_Ending("LF");
        delete this;
    });

    QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->RB_Windows, &QRadioButton::clicked, [this]() -> void {");
        (void) checked;
        emit Update_Ending("CRLF");
        delete this;
    });

    QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->RB_Mac, &QRadioButton::clicked, [this](bool checked) -> void {");
        (void) checked;
        emit Update_Ending("CR");
        delete this;
    });

    // this->setFocus();  // note: unnecessary.
    // this->grabMouse(); // note: unknown bug. comment this line out.
}

Ending::~Ending() {
    Logging(__FUNCTION__);

    delete _ui;
}
