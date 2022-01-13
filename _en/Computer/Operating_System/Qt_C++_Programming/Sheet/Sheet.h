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

class Delegate : public QStyledItemDelegate {
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        Logging(__FUNCTION__);

        (void)option;
        (void)index;
        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setFrame(false);
        editor->setRange(0.00, 100.00);
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const {
        double value = index.data(Qt::EditRole).toDouble();
        ((QDoubleSpinBox *)editor)->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
        double value = ((QDoubleSpinBox *)editor)->value();
        model->setData(index, value, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        (void)index;
        editor->setGeometry(option.rect);
    }
};

////////////////////////////////////////////////////////////////////////////////

class Sheet : public QMainWindow {
    Q_OBJECT

public:
    Ui::Sheet *_ui = nullptr;
    QMenu *menu = nullptr;
    Delegate _qdoublespinbox_delegate = Delegate();

public:
    Sheet(QWidget *parent = nullptr);
    ~Sheet();
};

#endif // Sheet_h
