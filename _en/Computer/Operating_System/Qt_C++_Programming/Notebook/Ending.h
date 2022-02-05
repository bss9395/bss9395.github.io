/* Notebook.h
Author: BSS9395
Update: 2022-02-05T00:05:00+08@China-Guangdong-Shenzhen+08
Design: Notebook
Encode: UTF-8
System: Qt 5.14
Notice: Bug on Visual Studio 2017
*/

#ifndef Ending_h
#define Ending_h

#define Header_h
#include "Common.h"
#include "ui_Ending.h"

class Ending : public QDialog {
    Q_OBJECT

public:
    Ui::Ending *_ui = nullptr;

public:
    explicit Ending(QString platform, QWidget *parent = nullptr);
    virtual ~Ending();

public:
    virtual bool event(QEvent *event) override;

signals:
    void Update_Ending(QString platform);
};

#endif // Ending_h
