/* Qt6_QSqlQuery.h
Author: BSS9395
Update: 2023-09-12T12:20:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QSQLQUERY_H
#define QT6_QSQLQUERY_H

#include <QMainWindow>
#include "ui_Qt6_QSqlQuery.h"
#include <QFileDialog>
#include <QtSql>
#include <QMessageBox>
#include "Detail.h"

class Qt6_QSqlQuery : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QSqlQuery *_ui;
    QSqlDatabase _database;
    QSqlQueryModel *_model;


public:
    Qt6_QSqlQuery(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QSqlQuery) {
        _ui->setupUi(this);

        _ui->A_Insert->setEnabled(false);
        _ui->A_Edit->setEnabled(false);
        _ui->A_Delete->setEnabled(false);

        _ui->TV_Data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _ui->TV_Data->setSelectionBehavior(QAbstractItemView::SelectItems);
        _ui->TV_Data->setSelectionMode(QAbstractItemView::SingleSelection);
        _ui->TV_Data->setAlternatingRowColors(true);

        QObject::connect(_ui->A_Open_Database, &QAction::triggered, this, [this]() -> void {
            QString filename = QFileDialog::getOpenFileName(this, "打开数据库", "", "SQLite数据库(*.db3)");
            if(filename.isEmpty() == true) {
                return;
            }

            _database = QSqlDatabase::addDatabase("QSQLITE");
            _database.setDatabaseName(filename);
//            _database.setHostName();
//            _database.setPort();
//            _database.setUserName();
//            _database.setPassword();

            if(_database.open() == false) {
                QMessageBox::warning(this, "错误消息", "打开数据库失败");
                return;
            }

            _model = new QSqlQueryModel(this);
            _ui->TV_Data->setModel(_model);

            _model->setQuery(R"(
SELECT empNo, Name, Gender, Birthday, Province, Department, Salary
FROM employee
ORDER BY empNo;
)");
            if(_model->lastError().isValid() == true) {
                QMessageBox::information(this, "错误消息", "数据表查询错误！" + _model->lastError().text());
                return;
            }

            QSqlRecord record = _model->record();
            _model->setHeaderData(record.indexOf("empNo"), Qt::Horizontal, "工号");
            _model->setHeaderData(record.indexOf("Name"), Qt::Horizontal, "姓名");
            _model->setHeaderData(record.indexOf("Gender"), Qt::Horizontal, "性别");
            _model->setHeaderData(record.indexOf("Birthday"), Qt::Horizontal, "出生日期");
            _model->setHeaderData(record.indexOf("Province"), Qt::Horizontal, "省份");
            _model->setHeaderData(record.indexOf("Department"), Qt::Horizontal, "部门");
            _model->setHeaderData(record.indexOf("Salary"), Qt::Horizontal, "工资");


            _ui->A_Insert->setEnabled(true);
            _ui->A_Edit->setEnabled(true);
            _ui->A_Delete->setEnabled(true);
        });



        QObject::connect(_ui->A_Insert, &QAction::triggered, this, [this]() -> void {
            QSqlQuery query(_database);
            query.exec(R"(
SELECT *
FROM employee
Where empNo=-1;
)");
            QSqlRecord record = query.record();
            Detail *detail = new Detail(this);
            detail->_Insert_Record(record);
            if(detail->exec() == QDialog::Accepted) {
                record = detail->_Get_Record();
                query.prepare(R"(
INSERT INTO employee
(EmpNo, Name, Gender, Birthday, Province, Department, Salary, Memo, Photo)
VALUES(:EmpNo, :Name, :Gender, :Birthday, :Province, :Department, :Salary, :Memo, :Photo);
)");
                query.bindValue(":EmpNo", record.value("EmpNo"));
                query.bindValue(":Name", record.value("Name"));
                query.bindValue(":Gender", record.value("Gender"));
                query.bindValue(":Birthday", record.value("Birthday"));
                query.bindValue(":Province", record.value("Province"));
                query.bindValue(":Department", record.value("Department"));
                query.bindValue(":Salary", record.value("Salary"));
                query.bindValue(":Memo", record.value("Memo"));
                query.bindValue(":Photo", record.value("Photo"));
                if(query.exec() == false) {
                    QMessageBox::critical(this, "错误消息", "插入记录错误！" + query.lastError().text());
                } else {
                    QString str = _model->query().executedQuery();
                    _model->setQuery(str);
                }
            }
            delete detail;
        });


        QObject::connect(_ui->A_Delete, &QAction::triggered, this, [this]() -> void {
            QModelIndex index = _ui->TV_Data->currentIndex();
            if(index.isValid() == false) {
                return;
            }
            QSqlRecord record = _model->record(index.row());
            int id = record.value("empNo").toInt();
            QSqlQuery query(_database);
            query.prepare(R"(
DELETE FROM employee
WHERE empNo=:empNo;
)");
            query.bindValue(":empNo", id);
            if(query.exec() == false) {
                QMessageBox::critical(this, "错误消息", "删除记录错误！" + query.lastError().text());
            } else {
                QString str = _model->query().executedQuery();
                _model->setQuery(str);
            }
        });

        QObject::connect(_ui->A_Edit, &QAction::triggered, this, [this]() -> void {
            QModelIndex index = _ui->TV_Data->currentIndex();
            if(index.isValid() == false) {
                return;
            }

            QSqlRecord record = _model->record(index.row());
            int id = record.value("empNo").toInt();
            QSqlQuery query(_database);
            query.prepare(R"(
SELECT *
FROM employee
WHERE EmpNo=:ID;
)");
            query.bindValue(":ID", id);
            query.exec();
            query.first();
            if(query.isValid() == false) {
                return;
            }

            Detail *detail = new Detail(this);
            detail->_Update_Record(query.record());
            if(detail->exec() == QDialog::Accepted) {
                record = detail->_Get_Record();
                query.prepare(R"(
update employee
set Name=:Name, Gender=:Gender, Birthday=:Birthday, Province=:Province,
    Department=:Department, Salary=:Salary, Memo=:Memo, Photo=:Photo
where EmpNo=:ID;
)");
                query.bindValue(":Name", record.value("Name"));
                query.bindValue(":Gender", record.value("Gender"));
                query.bindValue(":Birthday", record.value("Birthday"));
                query.bindValue(":Province", record.value("Province"));
                query.bindValue(":Department", record.value("Department"));
                query.bindValue(":Salary", record.value("Salary"));
                query.bindValue(":Memo", record.value("Memo"));
                query.bindValue(":Photo", record.value("Photo"));
                query.bindValue(":ID", id);
                if(query.exec() == false) {
                    QMessageBox::critical(this, "错误消息", "记录更新错误！" + query.lastError().text());
                } else{
                    QString str = _model->query().executedQuery();
                    _model->setQuery(str);
                }
            }
            delete detail;


        });
    }


    ~Qt6_QSqlQuery() {
        delete _ui;
    }


};
#endif // QT6_QSQLQUERY_H
