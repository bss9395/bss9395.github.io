/* QLibrary_Use.h
Author: BSS9395
Update: 2022-07-25T01:45:00+08@China-Shanghai+08
Design: QLibrary_Use
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef QLibrary_Use_h
#define QLibrary_Use_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_QLibrary_Use.h"

class QLibrary_Use : public QMainWindow {
    Q_OBJECT

private:
    Ui::QLibrary_Use *_ui = nullptr;
    QLabel *_status = new QLabel(this);

public:
    explicit QLibrary_Use(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::QLibrary_Use) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _ui->SB_Status->addWidget(_status);

        QObject::connect(_ui->PB_Addition, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Addition, &QPushButton::clicked, this, [this]() -> void {");

            QLibrary library = QLibrary("E:/Downloads/QtProjects/QLibrary_Use/include/QLibrary_Dll.dll");
            library.load();
            if(library.isLoaded() == true) {
                typedef double (*Addition)(double lhs, double rhs);
                Addition addition = (Addition)(library.resolve("_Addition"));
                if(addition == nullptr) {
                    System::Logging("if(addition == nullptr) {");
                    return;
                }

                double result = (*addition)(_ui->LE_Left->text().toDouble(), _ui->LE_Right->text().toDouble());
                _ui->PB_Addition->setText(QString::asprintf("%lf", result));
            } else {
                QString title = "错误";
                QString text = "未加载动态库";
                QMessageBox::information(this, title, text);
            }
        });
    }

    virtual QLibrary_Use::~QLibrary_Use() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

};

#endif // QLibrary_Use_h
