#pragma once

#include <QDebug>
#include <QString>
#include <QAbstractTableModel>

struct Employee {
    QString _name;
    int     _age;
    double  _salary;
};

class EmployeeModel: public QAbstractTableModel {
    Q_OBJECT

private:
    QVector<Employee>* _data;

public:
    explicit EmployeeModel(QVector<Employee>* data, QObject* parent = nullptr)
        : QAbstractTableModel(parent), _data(data) {
        //
    }

public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return parent.isValid() ? 0 : _data->size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return parent.isValid() ? 0 : 3;  // Name, Age, Salary
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if(orientation == Qt::Horizontal && role == Qt::DisplayRole) {
            switch(section) {
            case 0:
                return QString("Name");
            case 1:
                return QString("Age");
            case 2:
                return QString("Salary");
            }
        }
        return QVariant();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if(index.isValid() == false || index.row() >= _data->size()) {
            return QVariant();
        }

        const Employee& employee = _data->at(index.row());
        if(role == Qt::DisplayRole || role == Qt::EditRole) {
            switch(index.column()) {
            case 0:  // Name
                return employee._name;
            case 1:  // Age
                return employee._age;
            case 2:  // Salary
                return employee._salary;
            }
        }
        return QVariant();
    }

    Qt::ItemFlags flags(const QModelIndex &index) const override {
        if(index.isValid() == false) {
            return Qt::NoItemFlags;
        }
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;  // 支持编辑
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override {
        if(index.isValid() == true && role == Qt::EditRole) {
            Employee& employee = (*_data)[index.row()];
            switch(index.column()) {
            case 0:
                employee._name = value.toString();
                break;
            case 1:
                employee._age = value.toInt();
                break;
            case 2:
                employee._salary = value.toDouble();
                break;
            }
            emit dataChanged(index, index, {role});
            return true;
        }
        return false;
    }

public:
};
