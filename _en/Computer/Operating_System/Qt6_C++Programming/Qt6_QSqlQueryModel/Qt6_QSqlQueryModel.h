/* Qt6_QSqlQueryModel.h
Author: BSS9395
Update: 2023-09-11T16:12:00+08@China-Guangdong-Zhangjiang+08
*/

#ifndef QT6_QSQLQUERYMODEL_H
#define QT6_QSQLQUERYMODEL_H

#include <QMainWindow>
#include "ui_Qt6_QSqlQueryModel.h"
#include <QFileDialog>
#include <QtSql>
#include <QMessageBox>
#include <QDataWidgetMapper>

class Qt6_QSqlQueryModel : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QSqlQueryModel *_ui;
    QSqlDatabase _database;
    QSqlQueryModel *_model;
    QDataWidgetMapper *_mapper;

public:
    Qt6_QSqlQueryModel(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QSqlQueryModel) {
        _ui->setupUi(this);

        _ui->TV_Data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _ui->TV_Data->setSelectionBehavior(QAbstractItemView::SelectRows);
        _ui->TV_Data->setSelectionMode(QAbstractItemView::SingleSelection);
        _ui->TV_Data->setAlternatingRowColors(true);

        QObject::connect(_ui->A_Open_Database, &QAction::triggered, this, [this]() -> void{
            QString filename = QFileDialog::getOpenFileName(this, "打开数据库", "", "SQLite数据库(*.db3)");
            if(filename.isEmpty() == true) {
                return;
            }
            _database = QSqlDatabase::addDatabase("QSQLITE");
            _database.setDatabaseName(filename);
//            _database.setHostName();
//            _database.setPort();
//            _database.setUserName();
//            _database.setPort()
            if(_database.open() == false) {
                QMessageBox::warning(this, "错误消息", "打开数据库失败");
                return;
            }

            _model = new QSqlQueryModel(this);
            _model->setQuery(R"(
SELECT empNo, Name, Gender, Birthday, Province, Department, Salary
FROM employee
ORDER BY empNo
)");
            if(_model->lastError().isValid() == true) {
                QMessageBox::critical(this, "错误消息", "数据表查询错误！" + _model->lastError().text());
                return;
            }
            _ui->statusbar->showMessage(QString("记录条数%1").arg(_model->rowCount()));
            _ui->TV_Data->setModel(_model);

            QSqlRecord record = _model->record();
            _model->setHeaderData(record.indexOf("empNo"), Qt::Horizontal, "工号");
            _model->setHeaderData(record.indexOf("Name"), Qt::Horizontal, "姓名");
            _model->setHeaderData(record.indexOf("Gender"), Qt::Horizontal, "性别");
            _model->setHeaderData(record.indexOf("Brithday"), Qt::Horizontal, "出生");
            _model->setHeaderData(record.indexOf("Province"), Qt::Horizontal, "地址");
            _model->setHeaderData(record.indexOf("Department"), Qt::Horizontal, "部门");
            _model->setHeaderData(record.indexOf("Salary"), Qt::Horizontal, "工资");

            _mapper = new QDataWidgetMapper(this);
            _mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
            _mapper->setModel(_model);
            _mapper->addMapping(_ui->SB_ID, record.indexOf("empNo"));
            _mapper->addMapping(_ui->LE_Name, record.indexOf("Name"));
            _mapper->addMapping(_ui->CB_Gender, record.indexOf("Gender"));
            _mapper->addMapping(_ui->DE_Birthday, record.indexOf("Birthday"));
            _mapper->addMapping(_ui->CB_Address, record.indexOf("Province"));
            _mapper->addMapping(_ui->CB_Department, record.indexOf("Department"));
            _mapper->addMapping(_ui->SB_Salary, record.indexOf("Salary"));
            _mapper->toFirst();

            QObject::connect(_ui->TV_Data->selectionModel(), &QItemSelectionModel::currentRowChanged, this, [this](const QModelIndex &current, const QModelIndex &previous) -> void{
                if(current.isValid() == false) {
                    _ui->L_Avatar->clear();
                    _ui->PTE_Memo->clear();
                }

                _mapper->setCurrentIndex(current.row());

                bool first = (current.row() == 0);
                bool last  = (current.row() == _model->rowCount() - 1);
                _ui->A_First->setEnabled(first == false);
                _ui->A_Previous->setEnabled(first == false);
                _ui->A_Last->setEnabled(last == false);
                _ui->A_Next->setEnabled(last == false);

                QSqlRecord record = _model->record(current.row());
                int id = record.value("empNo").toInt();
                QSqlQuery query;
                query.prepare(R"(
SELECT EmpNo, Memo, Photo
FROM employee
Where EmpNo=:ID;
)");
                query.bindValue(":ID", id);
                query.exec();
                query.first();
                QVariant photo = query.value("Photo");
                if(photo.isValid() == false) {
                    _ui->L_Avatar->clear();
                } else {
                    QByteArray data = photo.toByteArray();
                    QPixmap pixmap;
                    pixmap.loadFromData(data);
                    _ui->L_Avatar->setPixmap(pixmap.scaled(_ui->L_Avatar->size(), Qt::KeepAspectRatio));
                }

                QVariant memo = query.value("Memo");
                _ui->PTE_Memo->setPlainText(memo.toString());
            });

            QObject::connect(_ui->A_First, &QAction::triggered, this, [this]() -> void{
                _mapper->toFirst();
                _Refresh_Table_View();
            });
            QObject::connect(_ui->A_Previous, &QAction::triggered, this, [this]() -> void{
                _mapper->toPrevious();
                _Refresh_Table_View();
            });
            QObject::connect(_ui->A_Next, &QAction::triggered, this, [this]() -> void {
                _mapper->toNext();
                _Refresh_Table_View();
            });
            QObject::connect(_ui->A_Last, &QAction::triggered, this, [this]() -> void {
                _mapper->toLast();
                _Refresh_Table_View();
            });
        });
    }

    ~Qt6_QSqlQueryModel() {
        delete _ui;
    }

public:
    void _Refresh_Table_View() {
        QModelIndex index = _model->index(_mapper->currentIndex(), 0);
        _ui->TV_Data->clearSelection();
        _ui->TV_Data->setCurrentIndex(index);
    }

};
#endif // QT6_QSQLQUERYMODEL_H
