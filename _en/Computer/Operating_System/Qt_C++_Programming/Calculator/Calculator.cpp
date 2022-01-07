/* Common.h
Author: BSS9395
Update: 2022-01-07T22:33:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#include "Common.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MW_Calculator) {
    ui->setupUi(this);
}

Calculator::~Calculator() {
    delete ui;
}
