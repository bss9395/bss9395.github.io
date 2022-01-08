/* Calculator.cpp
Author: BSS9395
Update: 2022-01-08T13:45:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::MW_Calculator) {
    Logger(__FUNCTION__);

    _ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/view_in_ar.png"));
    this->setWindowTitle(QString("Calculator"));
    this->statusBar()->addWidget(_ui->GB_Status_Bar);

    // QDateTime datetime = QDateTime::fromString("2022-01-08T16:00:00.123", "yyyy-MM-ddThh:mm:ss.zzz");
    // datetime.setTimeZone(QTimeZone("Asia/Shanghai"));
    QDateTime datetime = QDateTime::currentDateTime();
    datetime.setTimeSpec(Qt::TimeZone); // Qt::LocalTime, Qt::TimeZone.
    QString timezone = datetime.timeZone().displayName(QTimeZone::StandardTime, QTimeZone::OffsetName).right(6).remove(':');
    _ui->L_Data_Time->setText(datetime.toString("yyyy-MM-ddThh:mm:ss.zzz") + timezone);
}

Calculator::~Calculator() {
    Logger(__FUNCTION__);

    delete _ui;
}
