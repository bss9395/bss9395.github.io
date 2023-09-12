/* SID_Delegate.h
Author: BSS9395
Update: 2023-09-11T14:30:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef SID_DELEGATE_H
#define SID_DELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>
#include <QDateEdit>

class SID_Delegate_DateEdit : public QStyledItemDelegate {
    Q_OBJECT

public:
    SID_Delegate_DateEdit() {

    }

public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QDateEdit *editor = new QDateEdit(parent);
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QString str = index.model()->data(index, Qt::EditRole).toString();
        QDateEdit *edit = static_cast<QDateEdit *>(editor);
        edit->setDate(QDate::fromString(str, "yyyy-MM-dd"));
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QDateEdit *edit = static_cast<QDateEdit *>(editor);
        QString str = edit->date().toString("yyyy-MM-dd");
        model->setData(index, str, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        editor->setGeometry(option.rect);
    }
};

class SID_Delegate_ComboBox : public QStyledItemDelegate {
    Q_OBJECT

public:
    QStringList _items;
    bool _editable = false;

public:
    SID_Delegate_ComboBox() {

    }

    void _Setup(QStringList items, bool editable) {
        _items = items;
        _editable = editable;
    }

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QComboBox *editor = new QComboBox(parent);
        editor->setEditable(_editable);
        editor->addItems(_items);
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QString str = index.model()->data(index, Qt::EditRole).toString();
        QComboBox *combo = static_cast<QComboBox *>(editor);
        combo ->setCurrentText(str);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QComboBox *combo = static_cast<QComboBox *>(editor);
        QString str = combo->currentText();
        model->setData(index, str, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        editor->setGeometry(option.rect);
    }
};

#endif // SID_DELEGATE_H

