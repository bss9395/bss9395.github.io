/* Calculator.h
Author: BSS9395
Update: 2022-01-07T22:33:00+08@China-Guangdong-Shenzhen+08
Design: Calculator
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Calculator_h
#define Calculator_h

#define   Header_h
#include "Common.h"
#include "ui_Calculator.h"

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Ui::MW_Calculator *_ui;

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

public:
    bool event(QEvent *event) override;
};

#endif // Calculator_h
