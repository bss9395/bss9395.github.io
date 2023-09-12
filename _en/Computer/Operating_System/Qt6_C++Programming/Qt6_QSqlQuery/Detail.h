/* Detail.h
Author: BSS9395
Update: 2023-09-12T12:20:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef DETAIL_H
#define DETAIL_H

#include "ui_Detail.h"
#include <QtSql>
#include <QFileDialog>

class Detail : public QDialog {
    Q_OBJECT
public:
    Ui::Detail *_ui;
    QSqlRecord _record;

public:
    Detail(QWidget *parent = nullptr)
        : QDialog(parent), _ui(new Ui::Detail) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Accept,&QPushButton::clicked, this, [this]() -> void {
            this->accept();
        });
        QObject::connect(_ui->PB_Cancel, &QPushButton::clicked, this, [this]() -> void {
            this->reject();
        });

        QObject::connect(_ui->PB_Set_Avatar, &QPushButton::clicked, this, [this]() -> void {
            QString filename = QFileDialog::getOpenFileName(this, "选择图片", "", "图片(*.jpg *.png)");
            if(filename.isEmpty() == true) {
                return;
            }

            QFile *file = new QFile(filename);
            file->open(QIODevice::ReadOnly);
            QByteArray data = file->readAll();
            file->close();
            _record.setValue("Photo", data);

            QPixmap pixmap;
            pixmap.loadFromData(data);
            _ui->L_Avatar->setPixmap(pixmap.scaled(_ui->L_Avatar->size(), Qt::KeepAspectRatio));
        });

        QObject::connect(_ui->PB_Clear_Avatar, &QPushButton::clicked, this, [this]() -> void {
            _ui->L_Avatar->clear();
            _record.setNull("Photo");
        });
    }

    ~Detail() {
        delete _ui;
    }

public:
    void _Insert_Record(const QSqlRecord &record) {
        _record = record;
    }

    QSqlRecord _Get_Record() {
        _record.setValue("empNo", _ui->SB_ID->value());
        _record.setValue("Name", _ui->LE_Name->text());
        _record.setValue("Gender", _ui->CB_Gender->currentText());
        _record.setValue("Birthday", _ui->DE_Birthday->date().toString("yyyy-MM-dd"));
        _record.setValue("Province", _ui->CB_Address->currentText());
        _record.setValue("Department", _ui->CB_Department->currentText());
        _record.setValue("Salary", _ui->SB_Salary->value());
        _record.setValue("Memo",  _ui->PTE_Memo->toPlainText());
        return _record;
    }

    void _Update_Record(const QSqlRecord &record) {
        _record = record;
        _ui->SB_ID->setValue(record.value("empNo").toInt());
        _ui->LE_Name->setText(record.value("Name").toString());
        _ui->CB_Gender->setCurrentText(record.value("Gender").toString());
        _ui->DE_Birthday->setDate(record.value("Birthday").toDate());
        _ui->CB_Address->setCurrentText(record.value("Province").toString());
        _ui->CB_Department->setCurrentText(record.value("Department").toString());
        _ui->SB_Salary->setValue(record.value("Salary").toInt());
        _ui->PTE_Memo->setPlainText(record.value("Memo").toString());
        QVariant variant = record.value("Photo");
        if(variant.isValid() == false) {
            _ui->L_Avatar->clear();
        } else {
            QByteArray data = variant.toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(data);
            _ui->L_Avatar->setPixmap(pixmap.scaled(_ui->L_Avatar->size(), Qt::KeepAspectRatio));
        }
    }

};

#endif // DETAIL_H
