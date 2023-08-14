/* Qt_QRegExp.h
Author: BSS9395
Update: 2023-08-11T15：37：00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_QREGEXP_H
#define QT_QREGEXP_H

#include <QDebug>
#include <QDialog>
#include "ui_Qt_QRegExp.h"
#include <QRegExp>
#include <QRegExpValidator>

class Qt_QRegExp : public QDialog {
    Q_OBJECT

private:
    Ui::Qt_QRegExp *_ui = nullptr;

public:
    Qt_QRegExp(QWidget *parent = nullptr)
        : QDialog(parent), _ui(new Ui::Qt_QRegExp) {
        qDebug() << __FUNCTION__;
        _ui->setupUi(this);

        QRegExp regexp("[A-Za-z0-9]{1,20}@[A-Za-z]{1,10}.com");
        _ui->LE_EMail->setValidator(new QRegExpValidator(regexp, this));

        _TextChanged();
        QObject::connect(_ui->LE_EMail, &QLineEdit::textChanged, this, &Qt_QRegExp::_TextChanged);
        QObject::connect(_ui->PB_Accept, &QPushButton::clicked, this, &QDialog::accept);
        QObject::connect(_ui->PB_Cancel, &QPushButton::clicked, this, &QDialog::reject);
    }

    ~Qt_QRegExp() {
        qDebug() << __FUNCTION__;
        delete _ui;
    }

public:
    void _TextChanged() {
        qDebug() << __FUNCTION__;
        _ui->PB_Accept->setEnabled(_ui->LE_EMail->hasAcceptableInput());
    }
};
#endif // QT_QREGEXP_H
