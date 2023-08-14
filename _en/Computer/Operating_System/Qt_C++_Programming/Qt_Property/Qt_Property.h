/* Qt_Property.h
Author: BSS9395
Update: 2023-08-13T19:43:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT_PROPERTY_H
#define QT_PROPERTY_H

#include <QMainWindow>
#include "ui_Qt_Property.h"
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>

class Person : public QObject {
    Q_OBJECT

    Q_CLASSINFO("author", "bss9395")

    Q_PROPERTY(int age READ _Get_Age WRITE _Set_Age NOTIFY _Changed_Age)
    Q_PROPERTY(QString sex MEMBER _sex)

public:
    int     _age = 0;
    QString _sex = "";
    Person() {
        this->setProperty("sex", "boy");
        this->setProperty("name", "bss9395");
    }

public:
    int _Get_Age() {
        qDebug() << __FUNCTION__;
        return _age;
    }

    void _Set_Age(int age) {
        qDebug() << __FUNCTION__;
        if(_age != age) {
            _age = age;
            emit _Changed_Age();
        }
    }

signals:
    void _Changed_Age();
};

class Qt_Property : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt_Property *_ui = nullptr;
    Person *_person = new Person();

public:
    Qt_Property(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt_Property) {
        qDebug() << __FUNCTION__;
        _ui->setupUi(this);

        QString style = R"(
*[required="true"] {
    background-color: lime;
}
        )";
        this->setStyleSheet(style);
        _ui->SB_Age->setProperty("required", "true");


        ////////////////////////////////

        _person->setProperty("age", _ui->SB_Age->value());
        QObject::connect(_person, &Person::_Changed_Age, this, [this]() -> void {
            qDebug() << "QObject::connect(_person, &Person::_Changed_Age, this, [this]() -> void {";

            int age = _person->property("age").toInt();
            QString info = QString("age = %1").arg(age);
            _ui->PTE_Info->appendPlainText(info);
        });

        QObject::connect(_ui->SB_Age, &QSpinBox::valueChanged, this, [this](int age) -> void {
            qDebug() << "QObject::connect(_ui->SB_Age, &QSpinBox::valueChanged, this, [this](int age) -> void {";

            (void) age;
            _person->setProperty("age", _ui->SB_Age->value());
        });

        QObject::connect(_ui->PB_Info, &QPushButton::clicked, this, [this]() -> void {
            qDebug() << "QObject::connect(_ui->PB_Info, &QPushButton::clicked, this, [this]() -> void {";

            _ui->PTE_Info->clear();

            const QMetaObject *meta = _person->metaObject();
            _ui->PTE_Info->appendPlainText(meta->className());

            _ui->PTE_Info->appendPlainText("\nClassInfo: ");
            for(int i = meta->classInfoOffset(); i < meta->classInfoCount(); i += 1) {
                QMetaClassInfo class_info = meta->classInfo(i);
                QString info = QString("name=%1, value=%2").arg(class_info.name()).arg(class_info.value());
                _ui->PTE_Info->appendPlainText(info);
            }

            _ui->PTE_Info->appendPlainText("\nProperties: ");
            for(int i = meta->propertyOffset(); i < meta->propertyCount(); i += 1) {
                const char *name = meta->property(i).name();
                QString value = _person->property(name).toString();
                QString info = QString("name=%1, value=%2").arg(name).arg(value);
                _ui->PTE_Info->appendPlainText(info);
            }
        });
    }

    ~Qt_Property() {
        qDebug() << __FUNCTION__;

        delete _ui;
        delete _person;
    }



};
#endif // QT_PROPERTY_H
