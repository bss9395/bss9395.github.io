#ifndef Calculator_h
#define Calculator_h

#include "Common.h"

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Ui::Calculator *ui;

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
};

#endif // Calculator_h
