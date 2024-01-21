/* Qt6_QDataWidgetMapper.h
Author: BSS9395
Update: 2023-09-11T14:30:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QDATAWIDGETMAPPER_H
#define QT6_QDATAWIDGETMAPPER_H

#include <QMainWindow>
#include "ui_Qt6_QDataWidgetMapper.h"
#include <QTableView>
#include <QFileDialog>
#include <QtSql>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include "SID_Delegate.h"

class Qt6_QSqlDatabase : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QSqlDatabase *_ui = nullptr;
    QSqlDatabase _database;
    QSqlTableModel *_model = nullptr;
    QDataWidgetMapper *_mapper = nullptr;
    SID_Delegate_ComboBox _delegate_gender;
    SID_Delegate_ComboBox _delegate_department;
    SID_Delegate_DateEdit _delegate_birthday;

public:
    Qt6_QSqlDatabase(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QSqlDatabase) {
        _ui->setupUi(this);

        _ui->TV_Data->setSelectionBehavior(QAbstractItemView::SelectItems);
        _ui->TV_Data->setSelectionMode(QAbstractItemView::SingleSelection);
        _ui->TV_Data->setAlternatingRowColors(true);
        _ui->A_Increase_Salary->setEnabled(false);
        _ui->A_Append->setEnabled(false);
        _ui->A_Insert->setEnabled(false);
        _ui->A_Delete->setEnabled(false);
        _ui->A_Setup_Avatar->setEnabled(false);
        _ui->A_Clear_Avatar->setEnabled(false);
        _ui->A_Save->setEnabled(false);
        _ui->A_Cancel->setEnabled(false);

        QObject::connect(_ui->A_Open_Database, &QAction::triggered, this, [this]() -> void {
            QString filename = QFileDialog::getOpenFileName(this, "打开数据库", "", "SQLite数据库(*.db3)");
            if(filename.isEmpty() == true) {
                return;
            }
            _database = QSqlDatabase::addDatabase("QSQLITE", "connectionName");
            _database.setDatabaseName(filename);
//            _database.setHostName();
//            _database.setPort()
//            _database.setUserName();
//            _database.setPassword();
            if(_database.open() == false) {
                QMessageBox::warning(this, "错误", "打开数据库失败");
                return;
            }

            _model = new QSqlTableModel(this, _database);
            _model->setTable("employee");
            _model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            _model->setSort(_model->fieldIndex("empNo"), Qt::AscendingOrder);
            if(_model->select() == false) {
                QMessageBox::critical(this, "错误信息", "打开数据表失败");
                return;
            }

            this->statusBar()->showMessage(QString("记录条数: %1").arg(_model->rowCount()));
//            _model->setHeaderData(_model->fieldIndex("empNo"), Qt::Horizontal, "工号");
//            _model->setHeaderData(_model->fieldIndex("Name"), Qt::Horizontal, "姓名");
//            _model->setHeaderData(_model->fieldIndex("Gender"), Qt::Horizontal, "性别");
//            _model->setHeaderData(_model->fieldIndex("Birthday"), Qt::Horizontal, "出生日期");
//            _model->setHeaderData(_model->fieldIndex("Province"), Qt::Horizontal, "省份");
//            _model->setHeaderData(_model->fieldIndex("Department"), Qt::Horizontal, "部门");
//            _model->setHeaderData(_model->fieldIndex("Salary"), Qt::Horizontal, "工资");
//            _model->setHeaderData(_model->fieldIndex("Memo"), Qt::Horizontal, "备注");
//            _model->setHeaderData(_model->fieldIndex("Photo"), Qt::Horizontal, "照片");

            _ui->TV_Data->setModel(_model);
            _ui->TV_Data->setColumnHidden(_model->fieldIndex("Memo"), true);
            _ui->TV_Data->setColumnHidden(_model->fieldIndex("Photo"), true);

            QObject::connect(_ui->TV_Data->selectionModel(), &QItemSelectionModel::currentChanged, this, [this](const QModelIndex &current, const QModelIndex &previous) -> void {
                _ui->A_Save->setEnabled(_model->isDirty());
                _ui->A_Cancel->setEnabled(_model->isDirty());
            });

            QObject::connect(_ui->TV_Data->selectionModel(), &QItemSelectionModel::currentRowChanged, this, [this](const QModelIndex &current, const QModelIndex &previous) -> void{
                _ui->A_Delete->setEnabled(current.isValid());
                _ui->A_Setup_Avatar->setEnabled(current.isValid());
                _ui->A_Clear_Avatar->setEnabled(current.isValid());

                if(current.isValid() == false) {
                    _ui->L_Avatar->clear();
                    return;
                }

                _mapper->setCurrentIndex(current.row());
                QSqlRecord record = _model->record(current.row());
                if(record.isNull("Photo")) {
                    _ui->L_Avatar->clear();
                } else {
                    QByteArray data = record.value("Photo").toByteArray();
                    QPixmap pixmap;
                    pixmap.loadFromData(data);
                    _ui->L_Avatar->setPixmap(pixmap.scaled(_ui->L_Avatar->size(), Qt::KeepAspectRatio));
                }
            });

            _mapper = new QDataWidgetMapper(this);
            _mapper->setModel(_model);
            _mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
            _mapper->addMapping(_ui->SB_ID, _model->fieldIndex("empNo"));
            _mapper->addMapping(_ui->LE_Name, _model->fieldIndex("Name"));
            _mapper->addMapping(_ui->CB_Gender, _model->fieldIndex("Gender"));
            _mapper->addMapping(_ui->DE_Birthday, _model->fieldIndex("Birthday"));
            _mapper->addMapping(_ui->CB_Address, _model->fieldIndex("Province"));
            _mapper->addMapping(_ui->CB_Department, _model->fieldIndex("Department"));
            _mapper->addMapping(_ui->SB_Salary, _model->fieldIndex("Salary"));
            _mapper->toFirst();


            QSqlRecord record = _model->record();
            for(int i = 0; i < record.count(); i += 1) {
                _ui->CB_Sort->addItem(record.fieldName(i));
            }

            _ui->A_Increase_Salary->setEnabled(true);
            _ui->A_Append->setEnabled(true);
            _ui->A_Insert->setEnabled(true);
            _ui->A_Delete->setEnabled(true);
            _ui->A_Setup_Avatar->setEnabled(true);
            _ui->A_Clear_Avatar->setEnabled(true);


            QStringList items;
            items.clear();
            for(int i = 0; i < _ui->CB_Gender->count(); i += 1) {
                items << _ui->CB_Gender->itemText(i);
            }
            _delegate_gender._Setup(items, false);
            _ui->TV_Data->setItemDelegateForColumn(_model->fieldIndex("Gender"), &_delegate_gender);

            items.clear();
            for(int i = 0; i < _ui->CB_Department->count(); i += 1) {
                items << _ui->CB_Department->itemText(i);
            }
            _delegate_department._Setup(items, true);
            _ui->TV_Data->setItemDelegateForColumn(_model->fieldIndex("Department"), &_delegate_department);

            _ui->TV_Data->setItemDelegateForColumn(_model->fieldIndex("Birthday"), &_delegate_birthday);
        });

        QObject::connect(_ui->A_Append, &QAction::triggered, this, [this]() -> void {
            _model->insertRow(_model->rowCount());

            _ui->TV_Data->clearSelection();
            QModelIndex index = _model->index(_model->rowCount() - 1, 0);
            _ui->TV_Data->setCurrentIndex(index);

            _ui->SB_Status->showMessage(QString("记录条数%1").arg(_model->rowCount()));
        });

        QObject::connect(_ui->A_Insert, &QAction::triggered, this, [this]() -> void {
            QModelIndex index = _ui->TV_Data->currentIndex();
            _model->insertRow(index.row());

            _ui->TV_Data->clearSelection();
            _ui->TV_Data->setCurrentIndex(index);
            _ui->SB_Status->showMessage(QString("记录条数%1").arg(_model->rowCount()));
        });

        QObject::connect(_ui->A_Delete, &QAction::triggered, this, [this]() -> void {
            QModelIndex index = _ui->TV_Data->currentIndex();
            _model->removeRow(index.row());

            _ui->SB_Status->showMessage(QString("记录条数%1").arg(_model->rowCount()));
        });

        QObject::connect(_ui->A_Save, &QAction::triggered, this, [this]() -> void{
            bool result = _model->submitAll();
            if(result == false) {
                QMessageBox::information(this, "错误消息", "数据保存错误！" + _model->lastError().text());
                return;
            }

            _ui->SB_Status->showMessage(QString("记录条数%1").arg(_model->rowCount()));
        });

        QObject::connect(_ui->A_Cancel, &QAction::triggered, this, [this]() -> void {
            _model->revertAll();
            _ui->SB_Status->showMessage(QString("记录条数%1").arg(_model->rowCount()));
        });

        QObject::connect(_ui->A_Setup_Avatar, &QAction::triggered, this, [this]() -> void {
            QString filename = QFileDialog::getOpenFileName(this, "选择图片", "", "图片(*.jpg *.png)");
            if(filename.isEmpty() == true) {
                return;
            }

            QFile file = QFile(filename);
            file.open(QIODevice::ReadOnly);
            QByteArray data = file.readAll();
            file.close();

            int row = _ui->TV_Data->currentIndex().row();
            QSqlRecord record = _model->record(row);
            record.setValue("Photo", data);
            _model->setRecord(row, record);

            QPixmap pixmap;
            pixmap.load(filename);
            _ui->L_Avatar->setPixmap(pixmap.scaled(_ui->L_Avatar->size(), Qt::KeepAspectRatio));
        });

        QObject::connect(_ui->A_Clear_Avatar, &QAction::triggered, this, [this]() -> void {
            int row = _ui->TV_Data->currentIndex().row();
            QSqlRecord record = _model->record(row);
            record.setNull("Photo");
            _model->setRecord(row, record);
            _ui->L_Avatar->clear();
        });

        QObject::connect(_ui->CB_Sort, &QComboBox::currentIndexChanged, this, [this]() -> void {
            if(_ui->RB_Ascending->isChecked()) {
                _model->sort(_ui->CB_Sort->currentIndex(), Qt::AscendingOrder);
            } else if(_ui->RB_Descending->isChecked()) {
                _model->sort(_ui->CB_Sort->currentIndex(), Qt::DescendingOrder);
            }
        });
        QObject::connect(_ui->RB_Ascending, &QRadioButton::clicked, this, [this]() -> void {
            _model->sort(_ui->CB_Sort->currentIndex(), Qt::AscendingOrder);
        });

        QObject::connect(_ui->RB_Descending, &QRadioButton::clicked, this, [this]() -> void {
            _model->sort(_ui->CB_Sort->currentIndex(), Qt::DescendingOrder);
        });

        QObject::connect(_ui->RB_Man, &QRadioButton::clicked, this, [this]() -> void {
            _model->setFilter(" Gender='男' ");
        });
        QObject::connect(_ui->RB_Woman, &QRadioButton::clicked, this, [this]() -> void {
            _model->setFilter(" Gender='女' ");
        });
        QObject::connect(_ui->RB_All, &QRadioButton::clicked, this, [this]() -> void {
            _model->setFilter("");
        });

        QObject::connect(_ui->A_Increase_Salary, &QAction::triggered, this, [this]() -> void {
            for(int i = 0; i < _model->rowCount(); i += 1) {
                QSqlRecord record = _model->record(i);
                float salary = record.value("Salary").toFloat();
                salary = salary * 1.1;
                record.setValue("Salary", salary);
                _model->setRecord(i, record);
            }
        });

    }

    ~Qt6_QSqlDatabase() {
        delete _ui;
    }


};
#endif // QT6_QDATAWIDGETMAPPER_H
