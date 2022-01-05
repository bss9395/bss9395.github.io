/* Notebook
Author: BSS9395
Update: 2022-01-05T23:10:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
*/

#ifndef Notebook_h
#define Notebook_h

#include "Common.h"

class MW_Notebook : public QMainWindow {
    Q_OBJECT

public:
    Ui::MW_Notebook *ui;

public:
    MW_Notebook(QWidget *parent = nullptr);
    ~MW_Notebook();

public:
    void Update_Status_Bar(const QString &filename);
};

#endif // Notebook_h
