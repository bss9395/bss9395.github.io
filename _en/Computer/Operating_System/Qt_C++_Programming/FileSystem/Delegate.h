/* Delegate.h
Author: BSS9395
Update: 2022-06-23T21:53:00+08@China-Shanghai+08
Design: FileSystem
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Delegate_h
#define Delegate_h

#define   Header_h
#include "Common.h"
#include "System.h"

class QComboBox_Delegate : public QStyledItemDelegate {
public:
    QStringList _items = QStringList();

public:
    QComboBox_Delegate(const QStringList &items, QObject *parent = nullptr)
        : QStyledItemDelegate(parent) {
        System::Logging(__FUNCTION__);
        _items = items;
    }

    QComboBox_Delegate(const QComboBox_Delegate &delegate, QObject *parent = nullptr)
        : QStyledItemDelegate(parent) {
        System::Logging(__FUNCTION__);
        _items = delegate._items;
    }

    QComboBox_Delegate &operator=(const QComboBox_Delegate &delegate) {
        System::Logging(__FUNCTION__);
        if(this != &delegate) {
            _items = delegate._items;
        }
        return (*this);
    }

    virtual ~QComboBox_Delegate() {
        System::Logging(__FUNCTION__);
    }

public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);
        (void)option;
        (void)index;

        QComboBox *editor = new QComboBox(parent);
        editor->setFrame(false);  // note: no effect.
        editor->addItems(_items);
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);

        QString value = index.data(Qt::EditRole).toString();
        ((QComboBox *)editor)->setCurrentText(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);

        QString value = ((QComboBox *)editor)->currentText();
        model->setData(index, value, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);

        (void)index;
        editor->setGeometry(option.rect);
    }
};

////////////////////////////////////////////////////////////////////////////////

class QDoubleSpinBox_Delegate : public QStyledItemDelegate {
public:
    double _value_mini = 0.00;
    double _value_maxi = 100.00;
    iptr _width = 6;

public:
    QDoubleSpinBox_Delegate(double value_mini, double value_maxi, QObject *parent = nullptr)
        : QStyledItemDelegate(parent) {
        System::Logging(__FUNCTION__);
        _value_mini = value_mini;
        _value_maxi = value_maxi;
        _width = QString("%1").arg(value_maxi, 4, 'f', 2).size();
    }

    QDoubleSpinBox_Delegate(const QDoubleSpinBox_Delegate &delegate, QObject *parent = nullptr)
        : QStyledItemDelegate(parent) {
        _value_mini = delegate._value_mini;
        _value_maxi = delegate._value_maxi;
        _width = delegate._width;
    }

    QDoubleSpinBox_Delegate &operator=(const QDoubleSpinBox_Delegate &delegate) {
        if(this != &delegate) {
            _value_mini = delegate._value_mini;
            _value_maxi = delegate._value_maxi;
            _width = delegate._width;
        }
        return (*this);
    }

    virtual ~QDoubleSpinBox_Delegate() {
        System::Logging(__FUNCTION__);
    }

public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);
        (void)option;
        (void)index;

        QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
        editor->setFrame(false);
        editor->setRange(_value_mini, _value_maxi);
        editor->setDecimals(2);   // note: two digits precision.
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);

        double value = index.data(Qt::EditRole).toDouble();
        ((QDoubleSpinBox *)editor)->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);

        QString value = QString("%1").arg(((QDoubleSpinBox *)editor)->value(), _width, 'f', 2); // note: save as string to eliminate ambiguity.
        model->setData(index, value, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        System::Logging(__FUNCTION__);
        (void)index;

        editor->setGeometry(option.rect);
    }
};

#endif // Delegate_h
