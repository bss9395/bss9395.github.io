/* Notebook.h
Author: BSS9395
Update: 2022-01-06T20:21:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.15.2
Notice: Bug on Visual Studio 2017
*/

#ifndef Notebook_h
#define Notebook_h

#define   Header_h
#include "Common.h"
#include "ui_Notebook.h"

class MW_Notebook : public QMainWindow {
    Q_OBJECT

public:
    Ui::MW_Notebook *_ui;
    QString _filename = QString("untitled.txt");

public:
    MW_Notebook(QWidget *parent = nullptr);
    ~MW_Notebook();

public:
    void Update_Status_Bar(const QString &filename);
    void Update_Theme();
};

#endif // Notebook_h
