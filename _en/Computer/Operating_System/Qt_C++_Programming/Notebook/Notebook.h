/* Notebook.h
Author: BSS9395
Update: 2022-01-06T20:21:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14
Notice: Bug on Visual Studio 2017
*/

#ifndef Notebook_h
#define Notebook_h

#define   Header_h
#include "Common.h"
#include "ui_Notebook.h"
#include "Ending.h"

class Notebook : public QMainWindow {
    Q_OBJECT

public:
    Ui::Notebook *_ui = nullptr;

public:
    QString _filename = QString("untitled.txt");
    bool _modified = false;

public:
    Notebook(QWidget *parent = nullptr);
    ~Notebook();

public:
    virtual bool event(QEvent *event) override;

public:
    void Update_Status_Bar(const QString &filename);
    void Update_Theme();
};

#endif // Notebook_h
