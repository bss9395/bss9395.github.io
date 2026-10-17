#pragma once

#include <QStyledItemDelegate>
#include <QSpinBox>
#include <QPainter>

class EmployeeDelegate: public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit EmployeeDelegate(QObject* parent = nullptr)
        : QStyledItemDelegate(parent) {
        //
    }

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        if(index.column() == 1) {  // Age
            QSpinBox* editor = new QSpinBox(parent);
            editor->setRange(18, 100);
            return editor;
        }
        return QStyledItemDelegate::createEditor(parent, option, index);  // createEditor会根据单元格的数据类型自动创建相对应的组件
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        if(index.column() == 1) {  // Age
            int value = index.model()->data(index, Qt::EditRole).toInt();
            QSpinBox* spinBox = (QSpinBox*)(editor);
            spinBox->setValue(value);
            return;
        }
        QStyledItemDelegate::setEditorData(editor, index);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        if(index.column() == 1) {  // Age
            QSpinBox* spinBox = (QSpinBox*)(editor);
            spinBox->interpretText();
            model->setData(index, spinBox->value(), Qt::EditRole);
            return;
        }
        QStyledItemDelegate::setModelData(editor, model, index);
    }

    // 自定义单元格外观
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        if(index.column() == 0) {
            painter->drawText(option.rect, Qt::AlignCenter, index.data().toString());
            return;
        } else if(index.column() == 2) {  // Salary
            double salary = index.data().toDouble();
            int width     = option.rect.width();
            int fillWidth = (int)(width * (salary / 100000.0));  // 假设最大10万元

            // 绘制背景
            painter->fillRect(option.rect, option.palette.base());

            // 绘制进度条
            QRect barRect = option.rect.adjusted(2, 2, -2, -2);
            barRect.setWidth(fillWidth);
            QColor color = 50000.0 < salary ? QColor(200, 100, 100) : QColor(100, 200, 100);
            painter->fillRect(barRect, color);

            // 绘制文字
            QString text = QString::number(salary, 'f', 2);
            painter->drawText(option.rect, Qt::AlignCenter, text);
            return;
        }
        QStyledItemDelegate::paint(painter, option, index);
    }
};
