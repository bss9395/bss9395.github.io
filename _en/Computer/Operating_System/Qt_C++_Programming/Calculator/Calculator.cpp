/* Calculator.cpp
Author: BSS9395
Update: 2022-01-08T13:45:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MW_Calculator) {
    Logger(__FUNCTION__);

    ui->setupUi(this);
    this->setWindowTitle(QString("Calculator"));
    this->statusBar()->addWidget(ui->GB_Status_Bar);

    QDateTime datetime = QDateTime::currentDateTime();
    QString timezone = datetime.timeZone().displayName(QTimeZone::StandardTime, QTimeZone::OffsetName).right(6).remove(':');
    ui->L_Data_Time->setText(datetime.toString("yyyy-MM-ddThh:mm:ss.zzz") + timezone);
}

Calculator::~Calculator() {
    Logger(__FUNCTION__);

    delete ui;
}
