/* Qt_Signal_Slot.h
Author: BSS9395
Update: 2023-08-14T08:24:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_SIGNAL_SLOT_H
#define QT_SIGNAL_SLOT_H

#include <QMainWindow>
#include "ui_Qt_Signal_Slot.h"
#include <QDebug>

class Qt_Signal_Slot : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt_Signal_Slot *_ui = nullptr;

public:
    Qt_Signal_Slot(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt_Signal_Slot) {
        qDebug() << __FUNCTION__;
        _ui->setupUi(this);

        QObject::connect(_ui->CB_Underline, &QCheckBox::clicked, this, &Qt_Signal_Slot::_Do_Font_Underline_Italic_Bold);
        QObject::connect(_ui->CB_Italic, &QCheckBox::clicked, this, &Qt_Signal_Slot::_Do_Font_Underline_Italic_Bold);
        QObject::connect(_ui->CB_Bold, &QCheckBox::clicked, this, &Qt_Signal_Slot::_Do_Font_Underline_Italic_Bold);

        QObject::connect(_ui->RB_Red, &QRadioButton::clicked, this, &Qt_Signal_Slot::_Do_Font_Red_Green_Blue);
        QObject::connect(_ui->RB_Green, &QRadioButton::clicked, this, &Qt_Signal_Slot::_Do_Font_Red_Green_Blue);
        QObject::connect(_ui->RB_Blue, &QRadioButton::clicked, this, &Qt_Signal_Slot::_Do_Font_Red_Green_Blue);

        QObject::connect(_ui->PB_Clear, &QPushButton::clicked, this, [this]() -> void {
            _ui->PTE_Edit->clear();
        });
        QObject::connect(_ui->PB_Ok, &QPushButton::clicked, this, [this]() -> void {
            this->close();
        });
        QObject::connect(_ui->PB_Cancel, &QPushButton::clicked, this, [this]() -> void {
            this->close();
        });
    }

    ~Qt_Signal_Slot() {
        qDebug() << __FUNCTION__;
        delete _ui;
    }

public slots:
    void _Do_Font_Underline_Italic_Bold() {
        qDebug() << __FUNCTION__;
        QFont font = _ui->PTE_Edit->font();
        font.setUnderline(_ui->CB_Underline->isChecked());
        font.setItalic(_ui->CB_Italic->isChecked());
        font.setBold(_ui->CB_Bold->isChecked());
        _ui->PTE_Edit->setFont(font);
    }

    void _Do_Font_Red_Green_Blue() {
        qDebug() << __FUNCTION__;
        QPalette palette = _ui->PTE_Edit->palette();
        if(_ui->RB_Red->isChecked()) {
            palette.setColor(QPalette::Text, Qt::red);
        } else if(_ui->RB_Green->isChecked()) {
            palette.setColor(QPalette::Text, Qt::green);
        } else if(_ui->RB_Blue->isChecked()) {
            palette.setColor(QPalette::Text, Qt::blue);
        }
        _ui->PTE_Edit->setPalette(palette);
    }

};
#endif // QT_SIGNAL_SLOT_H
