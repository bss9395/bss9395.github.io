/* Sheet.h
Author: BSS9395
Update: 2022-01-14T00:04:00+08@China-Guangdong-Shenzhen+08
Design: Sheet
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Sheet_h
#define Sheet_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Sheet.h"
#include "Delegate.h"

class Sheet : public QMainWindow {
    Q_OBJECT

public:
    Ui::Sheet *_ui = nullptr;
    QString _filename = QString("untitled.sheet");
    QMenu *_menu = nullptr;
    QComboBox_Delegate _qcombobox_delegate = QComboBox_Delegate(QStringList(), this);
    QDoubleSpinBox_Delegate _qdoublespinbox_delegate = QDoubleSpinBox_Delegate(0.0, 100.0, this);

public:
    Sheet(QWidget *parent = nullptr);
    virtual ~Sheet();

public:
    void Update_Theme();
    // virtual void resizeEvent(QResizeEvent *event) override;
    virtual bool event(QEvent *event) override;
};

#endif // Sheet_h
