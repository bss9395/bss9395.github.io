/* Concurrent.h
Author: BSS9395
Update: 2022-12-23T22:19:00+08@China-Shanghai+08
Design: Concurrent
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Concurrent_h
#define Concurrent_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Concurrent.h"

static QString _Function_1(QString value) {
    System::Logging("%p:%s:%s", QThread::currentThreadId(), __FUNCTION__, value.toStdString().data());
    return QString(__FUNCTION__) + value;
}

class Concurrent : public QMainWindow {
    Q_OBJECT

private:
    Ui::Concurrent *_ui = nullptr;

public:
    explicit Concurrent(QWidget *parent = nullptr)
        : QMainWindow(parent)
        , _ui(new Ui::Concurrent) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Button, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Button, &QPushButton::clicked, this, [this]() -> void {");

            QFuture<QString> function_0 = QtConcurrent::run([this](QString value) -> QString {
                System::Logging("%p:%s:%s", QThread::currentThreadId(), __FUNCTION__, value.toStdString().data());
                return QString(__FUNCTION__) + value;
            }, QString("_value"));
            function_0.waitForFinished();
            System::Logging("%s:%s", "function_0", function_0.result().toStdString().data());


            QFuture<QString> function_1 = QtConcurrent::run(_Function_1, QString("_value"));
            function_1.waitForFinished();
            System::Logging("%s:%s", "function_1", function_1.result().toStdString().data());


            QFuture<QString> function_2 = QtConcurrent::run(Concurrent::_Function_2, QString("_value"));
            function_2.waitForFinished();
            System::Logging("%s:%s", "function_2", function_2.result().toStdString().data());


            QFuture<QString> function_3 = QtConcurrent::run(this, Concurrent::_Function_3, QString("_value"));
            function_3.waitForFinished();
            System::Logging("%s:%s", "function_3", function_3.result().toStdString().data());
        });
    }

    virtual ~Concurrent() {
        System::Logging(__FUNCTION__);
        delete _ui;
        _ui = nullptr;
    }

public:
    static QString _Function_2(QString value) {
        System::Logging("%p:%s:%s", QThread::currentThreadId(), __FUNCTION__, value.toStdString().data());
        return QString(__FUNCTION__) + value;
    }

    QString _Function_3(QString value) {
        System::Logging("%p:%s:%s", QThread::currentThreadId(), __FUNCTION__, value.toStdString().data());
        return QString(__FUNCTION__) + value;
    }
};

#endif // Concurrent_h
