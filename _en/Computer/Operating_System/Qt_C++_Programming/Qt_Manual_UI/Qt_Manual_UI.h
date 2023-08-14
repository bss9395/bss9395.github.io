/* Qt_Manual_UI.h
Author: BSS9395
Update: 2023-08-14T08:27:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_MANUAL_UI_H
#define QT_MANUAL_UI_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class Qt_Manual_UI : public QDialog {
    Q_OBJECT

public:
    QCheckBox *_CB_Underline  = nullptr;
    QCheckBox *_CB_Italic     = nullptr;
    QCheckBox *_CB_Bold       = nullptr;
    QRadioButton *_RB_Red     = nullptr;
    QRadioButton *_RB_Green   = nullptr;
    QRadioButton *_RB_Blue    = nullptr;
    QPlainTextEdit *_PTE_Edit = nullptr;
    QPushButton *_PB_Clear    = nullptr;
    QPushButton *_PB_Ok       = nullptr;
    QPushButton *_PB_Cancel   = nullptr;


public:
    Qt_Manual_UI(QWidget *parent = nullptr)
        : QDialog(parent) {
        qDebug() << __FUNCTION__;

        _Setup_Ui();
        _Setup_Connection();
    }

    ~Qt_Manual_UI() {
        qDebug() << __FUNCTION__;
    }

public:
    void _Setup_Ui() {
        qDebug() << __FUNCTION__;
        _CB_Underline = new QCheckBox("Underline");
        _CB_Italic = new QCheckBox("Italic");
        _CB_Bold = new QCheckBox("Bold");
        QHBoxLayout *hbl_layout0 = new QHBoxLayout();
        hbl_layout0->addWidget(_CB_Underline);
        hbl_layout0->addWidget(_CB_Italic);
        hbl_layout0->addWidget(_CB_Bold);

        _RB_Red = new QRadioButton("Red");
        _RB_Green = new QRadioButton("Green");
        _RB_Blue = new QRadioButton("Blue");
        QHBoxLayout *hbl_layout1 = new QHBoxLayout();
        hbl_layout1->addWidget(_RB_Red);
        hbl_layout1->addWidget(_RB_Green);
        hbl_layout1->addWidget(_RB_Blue);

        _PTE_Edit = new QPlainTextEdit();
        _PTE_Edit->setPlainText("Hello, World!");
        QFont font = _PTE_Edit->font();
        font.setPointSize(14);
        _PTE_Edit->setFont(font);

        _PB_Clear = new QPushButton("清空");
        _PB_Ok = new QPushButton("确定");
        _PB_Cancel = new QPushButton("取消");
        QHBoxLayout *hbl_layout2 = new QHBoxLayout();
        hbl_layout2->addStretch();
        hbl_layout2->addWidget(_PB_Clear);
        hbl_layout2->addWidget(_PB_Ok);
        hbl_layout2->addWidget(_PB_Cancel);
        hbl_layout2->addStretch();

        QVBoxLayout *vbl_layout3 = new QVBoxLayout();
        vbl_layout3->addLayout(hbl_layout0);
        vbl_layout3->addLayout(hbl_layout1);
        vbl_layout3->addWidget(_PTE_Edit);
        vbl_layout3->addLayout(hbl_layout2);
        this->setLayout(vbl_layout3);  // note: work for QDialog.
    }

    void _Setup_Connection() {
        qDebug() << __FUNCTION__;
        QObject::connect(_CB_Underline, &QCheckBox::clicked, this, &Qt_Manual_UI::_Do_Font_Underline_Italic_Bold);
        QObject::connect(_CB_Italic, &QCheckBox::clicked, this, &Qt_Manual_UI::_Do_Font_Underline_Italic_Bold);
        QObject::connect(_CB_Bold, &QCheckBox::clicked, this, &Qt_Manual_UI::_Do_Font_Underline_Italic_Bold);

        QObject::connect(_RB_Red, &QRadioButton::clicked, this, &Qt_Manual_UI::_Do_Font_Red_Green_Blue);
        QObject::connect(_RB_Green, &QRadioButton::clicked, this, &Qt_Manual_UI::_Do_Font_Red_Green_Blue);
        QObject::connect(_RB_Blue, &QRadioButton::clicked, this, &Qt_Manual_UI::_Do_Font_Red_Green_Blue);

        QObject::connect(_PB_Clear, &QPushButton::clicked, this, [this]() -> void {
            _PTE_Edit->clear();
        });
        QObject::connect(_PB_Ok, &QPushButton::clicked, this, [this]() -> void {
            this->close();
        });
        QObject::connect(_PB_Cancel, &QPushButton::clicked, this, [this]() -> void {
            this->close();
        });
    }

public:
    void _Do_Font_Underline_Italic_Bold() {
        qDebug() << __FUNCTION__;
        QFont font = _PTE_Edit->font();
        font.setUnderline(_CB_Underline->isChecked());
        font.setItalic(_CB_Italic->isChecked());
        font.setBold(_CB_Bold->isChecked());
        _PTE_Edit->setFont(font);
    }

    void _Do_Font_Red_Green_Blue() {
        qDebug() << __FUNCTION__;
        QPalette palette = _PTE_Edit->palette();
        if(_RB_Red->isChecked()) {
            palette.setColor(QPalette::Text, Qt::red);
        } else if(_RB_Green->isChecked()) {
            palette.setColor(QPalette::Text, Qt::green);
        } else if(_RB_Blue->isChecked()) {
            palette.setColor(QPalette::Text, Qt::blue);
        }
        _PTE_Edit->setPalette(palette);
    }
};
#endif // QT_MANUAL_UI_H
