/* Calculator.h
Author: BSS9395
Update: 2022-01-07T22:33:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Calculator_h
#define Calculator_h

#include "Common.h"

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Ui::MW_Calculator *_ui;

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
};

#endif // Calculator_h
