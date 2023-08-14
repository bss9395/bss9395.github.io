#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "ui_Qt_QTreewidget.h"


class Qt_QTreeWidget : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *_ui = nullptr;

public:
    Qt_QTreeWidget(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::MainWindow) {
        qDebug() << __FUNCTION__;

        _ui->setupUi(this);

        _ui->TW_Tree->clear();
        QTreeWidgetItem *group0 = new QTreeWidgetItem(_ui->TW_Tree);
        group0->setText(0, "Group0");
        // group0->setFlags(Qt::ItemIsAutoTristate | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        group0->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        group0->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *item00 = new QTreeWidgetItem(group0);
        item00->setText(0, "item00");
        // item00->setFlags(Qt::ItemIsAutoTristate | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item00->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item00->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *item01 = new QTreeWidgetItem(group0);
        item01->setText(0, "item01");
        // item01->setFlags(Qt::ItemIsAutoTristate | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item01->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item01->setCheckState(0, Qt::Unchecked);

        QTreeWidgetItem *group1 = new QTreeWidgetItem(_ui->TW_Tree);
        group1->setText(0, "group1");
        // group1->setFlags(Qt::ItemIsAutoTristate | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        group1->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        group1->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *item10 = new QTreeWidgetItem(group1);
        item10->setText(0, "item10");
        // item10->setFlags(Qt::ItemIsAutoTristate | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item10->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item10->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *item11 = new QTreeWidgetItem(group1);
        item11->setText(0, "item11");
        // item11->setFlags(Qt::ItemIsAutoTristate | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item11->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item11->setCheckState(0, Qt::Unchecked);

        QObject::connect(_ui->TW_Tree, &QTreeWidget::itemChanged, this, &Qt_QTreeWidget::_ItemChanged);
    }

    ~Qt_QTreeWidget() {
        qDebug() << __FUNCTION__;

        delete _ui;
    }

public:
    void _ItemChanged(QTreeWidgetItem *item, int column) {
        qDebug() << __FUNCTION__;

        _ui->TW_Tree->blockSignals(true);
        for(int i = 0, size = item->childCount(); i < size; i += 1) {
            item->child(i)->setCheckState(0, item->checkState(0));
        }

        QTreeWidgetItem *parent = item->parent();
        if(parent != nullptr) {
            int count = 0;
            int size = parent->childCount();
            for(int i = 0; i < size; i += 1) {
                if(Qt::Checked == parent->child(i)->checkState(0)) {
                    count += 1;
                }
            }


            if(count <= 0) {
                parent->setCheckState(0, Qt::Unchecked);
            } else if(size <= count) {
                parent->setCheckState(0, Qt::Checked);
            } else {
                parent->setCheckState(0, Qt::PartiallyChecked);
            }

        }
        _ui->TW_Tree->blockSignals(false);
    }
};

#endif // MAINWINDOW_H
