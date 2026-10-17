#pragma once

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QTimer>
#include <QTableWidget>
#include <QSortFilterProxyModel>
#include <QProxyStyle>
#include "EmployeeModel.h"
#include "EmployeeDelegate.h"

class MainWidget: public QWidget {
    Q_OBJECT

    QVector<Employee>*     _employees   = new QVector<Employee>();
    QTableView*            _tableView1  = new QTableView(this);
    QTableView*            _tableView2  = new QTableView(this);
    EmployeeModel*         _model       = new EmployeeModel(_employees, this);
    EmployeeDelegate*      _delegate    = new EmployeeDelegate(this);
    QTableWidget*          _tableWidget = new QTableWidget(this);

public:
    MainWidget(QWidget* parent = nullptr)
        : QWidget(parent) {
        this->resize(900, 600);
        _tableView1->resize(300, 400);
        _tableView2->resize(300, 400);
        _tableView2->move(300, 0);
        _tableWidget->resize(300, 400);
        _tableWidget->move(600, 0);

        _employees->append({ "Alice"  , 30, 45000.0 });
        _employees->append({ "Bob"    , 25, 72000.0 });
        _employees->append({ "Charlie", 35, 120000.0 });

        _SetModel();
        _TableView();
        _TableWidget();
    }

    void _SetModel() {
        QStandardItemModel* model = new QStandardItemModel(3, 3);
        model->setHorizontalHeaderLabels(QStringList() << "姓名" << "年龄" << "薪资");
        for(int i = 0; i < _employees->count(); i += 1) {
            QStandardItem* item0 = new QStandardItem();
            item0->setData((*_employees)[i]._name, Qt::EditRole);
            item0->setTextAlignment(Qt::AlignRight);  // 当使用ItemDelegate时失效
            model->setItem(i, 0, item0);
            QStandardItem* item1 = new QStandardItem();
            item1->setData((*_employees)[i]._age, Qt::EditRole);
            model->setItem(i, 1, item1);
            QStandardItem* item2 = new QStandardItem();
            item2->setData((*_employees)[i]._salary, Qt::EditRole);
            model->setItem(i, 2, item2);
        }
        _tableView1->setModel(model);
        _tableView1->setItemDelegate(_delegate);

        _tableView1->setSortingEnabled(true);
        _tableView1->sortByColumn(0, Qt::AscendingOrder);
        _tableView1->setFocusPolicy(Qt::NoFocus);
        _tableView1->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
        _tableView1->setSelectionBehavior(QAbstractItemView::SelectColumns);
    }

    void _TableView() {
        // _tableView2->setModel(_model);
        // _tableView2->setItemDelegate(_delegate);
        // _EmitDataChanged();

        QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
        proxy->setSourceModel(_model);
        proxy->setSortRole(Qt::DisplayRole);
        _tableView2->setModel(proxy);
        _tableView2->setItemDelegate(_delegate);
        _tableView2->setSortingEnabled(true);
        _tableView2->sortByColumn(0, Qt::AscendingOrder);

        _tableView2->setFocusPolicy(Qt::NoFocus);
        _tableView2->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
        _tableView2->setSelectionBehavior(QAbstractItemView::SelectColumns);
        _EmitDataChanged();
    }

    void _TableWidget() {
        _tableWidget->setColumnCount(_employees->count());
        _tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Age" << "Salary");
        _tableWidget->setRowCount(_employees->count());

        for(int row = 0; row < _employees->count(); row += 1) {
            QTableWidgetItem* item0 = new QTableWidgetItem();
            item0->setData(Qt::EditRole, (*_employees)[row]._name);
            item0->setTextAlignment(Qt::AlignHCenter);
            _tableWidget->setItem(row, 0, item0);
            QTableWidgetItem* item1 = new QTableWidgetItem();
            item1->setData(Qt::EditRole, (*_employees)[row]._age);
            _tableWidget->setItem(row, 1, item1);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setData(Qt::EditRole, (*_employees)[row]._salary);
            _tableWidget->setItem(row, 2, item2);
        }

        _tableWidget->setSortingEnabled(true);
        _tableWidget->sortByColumn(0, Qt::AscendingOrder);
        _tableWidget->setFocusPolicy(Qt::NoFocus);
        _tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
        _tableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    }

    virtual ~MainWidget() {
        qDebug() << "virtual ~MainWidget() {";
        delete _employees;
    }

public:
    void _EmitDataChanged() {
        QTimer::singleShot(5000, [this]() {
            std::sort(_employees->begin(), _employees->end(), [](const Employee& lhs, const Employee& rhs) {
                return lhs._age < rhs._age;
            });
            // 重置Model
            emit _model->dataChanged(_model->index(0, 0), _model->index(_model->rowCount() - 1, _model->columnCount() - 1));

            // 重置代理Model
            delete _tableView2->model();
            QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
            proxy->setSourceModel(_model);
            _tableView2->setModel(proxy);
        });
    }
};
