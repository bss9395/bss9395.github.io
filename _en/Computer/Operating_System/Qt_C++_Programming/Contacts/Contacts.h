/* Contacts.h
Author: BSS9395
Update: 2022-03-02T20:10:00+08@China-Guangdong-Shenzhen+08
Design: Contacts
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Contacts_h
#define Contacts_h

#define Header_h
#include "Common.h"
#include "ui_Contacts.h"
#include "System.h"
#include "Settings.h"

class Contacts : public QMainWindow {
    Q_OBJECT

public:
    Ui::Contacts *_ui = nullptr;
    QString _caption = QString();
    QString _label = QString();
    QString _filter = QString();
    QSqlDatabase _database = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery _query = QSqlQuery();      // note: by default this will check if database was opened.
    QSqlRecord _fields = QSqlRecord();
    std::vector<QTableWidgetItem *> _updates;
    std::vector<QTableWidgetItem *> _inserts;
    std::vector<QString> _deletes;
    bool _dirty = false;
    bool _guard = false;

public:
    explicit Contacts(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Contacts) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        QObject::connect(_ui->A_Load, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Load, &QAction::triggered, [this]() -> void {");

            _caption = "加载数据库文件";
            _filter = "SQLite(*.db *.db3)";
            QString filename = QFileDialog::getOpenFileName(this, _caption, QDir::currentPath(), _filter);
            if(filename.size() <= 0){
                return ;
            }

            _database.setDatabaseName(filename);
            if(System::Checking(_database.open() == false, System::_Error, NULL)) {
                _caption = "加载数据库失败";
                _label = _database.lastError().text();
                QMessageBox::critical(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                Exception::Excepting(true, System::_Fatal, _label, QString(""));
                return ;
            }

            Populate(true);
        });

        QObject::connect(_ui->A_Insert, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Insert, &QAction::triggered, [this]() -> void {");

            iptr row = _ui->TW_People->currentRow();     // note: if no current selection, should return -1.
            iptr col = _ui->TW_People->currentColumn();
            // System::Logging("row = %td, col = %td", row, col);
            if(row < 0) {
                row = 0;
            }
            if(col < 0) {
                col = 0;
            }
            _ui->TW_People->insertRow(row);
            _ui->TW_People->setCurrentCell(row, col);
            for(iptr col = 0, cols = _ui->TW_People->columnCount(); col < cols; col += 1) {
                QTableWidgetItem *item = new QTableWidgetItem();
                _ui->TW_People->setItem(row, col, item);
            }
            _inserts.push_back(_ui->TW_People->item(row, _fields.indexOf("_Identity")));
        });

        QObject::connect(_ui->A_Delete, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Delete, &QAction::triggered, [this]() -> void {");

            iptr row = _ui->TW_People->currentRow();
            iptr col = _ui->TW_People->currentColumn();
            // System::Logging("row = %td, col = %td", row, col);
            if(0 <= row && 0 <= col) {
                QTableWidgetItem *item = _ui->TW_People->item(row, Settings::_Primary.At<0>());
                _deletes.push_back(item->text());
                _ui->TW_People->removeRow(row);
                if(1 <= _ui->TW_People->rowCount()) {
                    _ui->TW_People->setCurrentCell(row, col);
                }

                for(iptr i = 0, numb = _inserts.size(); i < numb; i += 1) {
                    if(_inserts[i] == item) {
                        _inserts[i] = nullptr;
                    }
                }
                for(iptr i = 0, numb = _updates.size(); i < numb; i += 1) {
                    if(_updates[i] == item) {
                        _updates[i] = nullptr;
                    }
                }
            }
        });

        QObject::connect(_ui->A_Submit, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Submit, &QAction::triggered, [this]() -> void {");

            static QString query_delete = R"(
DELETE FROM [People]
WHERE [_Identity]=:Identity;
)";
            static QString query_insert = R"(
INSERT INTO [People]
([_Identity], [_Name],   [_Gender],  [_Birthday],   [_Homepage],
 [_Mobile],   [_Email],  [_Company], [_Department], [_Title],
 [_Employee], [_Degree], [_Address], [_Memo])
VALUES
(:Identity, :Name,   :Gender,  :Birthday,   :Homepage,
 :Mobile,   :Email,  :Company, :Department, :Title,
 :Employee, :Degree, :Address, :Memo);
)";
            static QString query_update = R"(
UPDATE [People]
SET    [_Identity]=:Identity, [_Name]=:Name,     [_Gender]=:Gender,   [_Birthday]=:Birthday,     [_Homepage]=:Homepage,
       [_Mobile]=:Mobile,     [_Email]=:Email,   [_Company]=:Company, [_Department]=:Department, [_Title]=:Title,
       [_Employee]=:Employee, [_Degree]=:Degree, [_Address]=:Address, [_Memo]=:Memo
WHERE  [_Identity]=:Original;
)";

            ////////////////////////////

            QSqlDatabase::database().transaction();
            QSqlQuery _query = QSqlQuery();
            _query.prepare(query_delete);
            for(iptr i = 0, numb = _deletes.size(); i < numb; i += 1) {
                _query.bindValue(":Identity", _deletes[i]);
                _query.exec();
            }

            ////////////////////////////

            _query.prepare(query_insert);
            for(iptr i = 0, numb = _inserts.size(); i < numb; i += 1) {
                if(_inserts[i] == nullptr) {
                    continue;
                }
                iptr row = _inserts[i]->row();
                _query.bindValue(":Identity", _ui->TW_People->item(row, _fields.indexOf("_Identity"))->text());
                _query.bindValue(":Name", _ui->TW_People->item(row, _fields.indexOf("_Name"))->text());
                _query.bindValue(":Gender", _ui->TW_People->item(row, _fields.indexOf("_Gender"))->text());
                _query.bindValue(":Birthday", _ui->TW_People->item(row, _fields.indexOf("_Birthday"))->text());
                _query.bindValue(":Homepage", _ui->TW_People->item(row, _fields.indexOf("_Homepage"))->text());
                _query.bindValue(":Mobile", _ui->TW_People->item(row, _fields.indexOf("_Mobile"))->text());
                _query.bindValue(":Email", _ui->TW_People->item(row, _fields.indexOf("_Email"))->text());
                _query.bindValue(":Company", _ui->TW_People->item(row, _fields.indexOf("_Company"))->text());
                _query.bindValue(":Department", _ui->TW_People->item(row, _fields.indexOf("_Department"))->text());
                _query.bindValue(":Title", _ui->TW_People->item(row, _fields.indexOf("_Title"))->text());
                _query.bindValue(":Employee", _ui->TW_People->item(row, _fields.indexOf("_Employee"))->text());
                _query.bindValue(":Degree", _ui->TW_People->item(row, _fields.indexOf("_Degree"))->text());
                _query.bindValue(":Address", _ui->TW_People->item(row, _fields.indexOf("_Address"))->text());
                _query.bindValue(":Memo", _ui->TW_People->item(row, _fields.indexOf("_Memo"))->text());
                _query.exec();
            }

            ////////////////////////////

            _query.prepare(query_update);
            for(iptr i = 0, numb = _updates.size(); i < numb; i += 1) {
                if(_updates[i] == nullptr) {
                    continue;
                }
                iptr row = _updates[i]->row();
                QString identity = _ui->TW_People->item(row, _fields.indexOf("_Identity"))->text();
                _query.bindValue(":Identity", identity);
                _query.bindValue(":Name", _ui->TW_People->item(row, _fields.indexOf("_Name"))->text());
                _query.bindValue(":Gender", _ui->TW_People->item(row, _fields.indexOf("_Gender"))->text());
                _query.bindValue(":Birthday", _ui->TW_People->item(row, _fields.indexOf("_Birthday"))->text());
                _query.bindValue(":Homepage", _ui->TW_People->item(row, _fields.indexOf("_Homepage"))->text());
                _query.bindValue(":Mobile", _ui->TW_People->item(row, _fields.indexOf("_Mobile"))->text());
                _query.bindValue(":Email", _ui->TW_People->item(row, _fields.indexOf("_Email"))->text());
                _query.bindValue(":Company", _ui->TW_People->item(row, _fields.indexOf("_Company"))->text());
                _query.bindValue(":Department", _ui->TW_People->item(row, _fields.indexOf("_Department"))->text());
                _query.bindValue(":Title", _ui->TW_People->item(row, _fields.indexOf("_Title"))->text());
                _query.bindValue(":Employee", _ui->TW_People->item(row, _fields.indexOf("_Employee"))->text());
                _query.bindValue(":Degree", _ui->TW_People->item(row, _fields.indexOf("_Degree"))->text());
                _query.bindValue(":Address", _ui->TW_People->item(row, _fields.indexOf("_Address"))->text());
                _query.bindValue(":_Memo", _ui->TW_People->item(row, _fields.indexOf("_Memo"))->text());
                QString original = _ui->TW_People->item(row, _fields.indexOf("_Identity"))->data(Qt::UserRole).toString();
                _query.bindValue(":Original", original);
                _ui->TW_People->item(row, _fields.indexOf("_Identity"))->setData(Qt::UserRole, identity);
                _query.exec();
            }

            ////////////////////////////

            if(System::Checking(QSqlDatabase::database().commit() == false, System::_Error, NULL)) {
                _caption = "提交数据表失败";
                _label = _query.lastError().text();
                QMessageBox::critical(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                QSqlDatabase::database().rollback();
            }
            //            if(_query.lastError().isValid() == true) {
            //                qDebug() << "if(prepare.lastError().isValid() == true) {";
            //            }
            //            System::Logging("_query.executedQuery() = %ls", _query.executedQuery().toStdWString().data());
            _deletes.clear();
            _inserts.clear();
            _updates.clear();
            _dirty = true;
        });

        QObject::connect(_ui->A_Revert, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Revert, &QAction::triggered, [this]() -> void {");

            Populate(_dirty == true);
        });


        QObject::connect(_ui->TW_People, &QTableWidget::cellEntered, [this](int row, int column) -> void {
            System::Logging("QObject::connect(_ui->TW_People, &QTableWidget::cellEntered, [this](int row, int column) -> void {");

            if(column == _fields.indexOf("_Identity")) {
                QTableWidgetItem *item = _ui->TW_People->item(row, _fields.indexOf("_Identity"));
                for(iptr i = 0, numb = _inserts.size(); i < numb; i += 1) {
                    if(_inserts[i] == item) {
                        return;
                    }
                }
                item->setData(Qt::UserRole, item->text());
            }
        });

        QObject::connect(_ui->TW_People, &QTableWidget::cellChanged, [this](int row, int column) -> void {
            System::Logging("QObject::connect(_ui->TW_People, &QTableWidget::cellChanged, [this]() -> void {");

            System::Logging("row = %td, col = %td", row, column);
            if(_guard == true) {
                return ;
            }

            QTableWidgetItem *item = _ui->TW_People->item(row, _fields.indexOf("_Identity"));
            if(item->data(Qt::UserRole).isValid() == false) {
                item->setData(Qt::UserRole, item->text());
                _updates.push_back(item);
            }
        });
    }

    virtual ~Contacts() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void Populate(bool select) {
        System::Logging(__FUNCTION__);
        _guard = true;

        static QString query_select = R"(
SELECT [_Identity], [_Name], [_Gender], [_Birthday], [_Homepage],
       [_Mobile], [_Email], [_Company], [_Department], [_Title],
       [_Employee], [_Degree], [_Address], [_Memo]
FROM   [People];
)";

        if(select == true) {
            _query.prepare(query_select);
            if(System::Checking(_query.exec() == false, System::_Error, NULL)) {
                _caption = "查询数据表失败";
                _label = _query.lastError().text();
                QMessageBox::warning(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                Exception::Excepting(true, System::_Error, _label, QString(""));
                return ;
            }

            /* set horizontal header */
            _fields = _query.record();
            iptr cols = _fields.count();
            _ui->TW_People->setColumnCount(cols);
            for(iptr col = 0; col < cols; col += 1) {
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText(_fields.fieldName(col));
                item->setTextAlignment(Qt::AlignCenter);
                _ui->TW_People->setHorizontalHeaderItem(col, item);
            }
        }

        /* set table items */
        iptr row = 0, capacity = 20;
        _ui->TW_People->setRowCount(capacity);  // note: maybe unsupported, size() for SELECT, numRowsAffected() for others.
        for(_query.first(); _query.isValid(); row += 1) {
            if(!(row < capacity)) {
                capacity += 20;
                _ui->TW_People->setRowCount(capacity);
            }
            QSqlRecord record = _query.record();
            for(iptr col = 0, cols = _fields.count(); col < cols; col += 1) {
                QTableWidgetItem *item = new QTableWidgetItem();
                QVariant variant = record.value(col);
                if(variant.isNull() == true) {
                    item->setText("NULL");
                } else {
                    item->setText(variant.toString());
                }
                item->setTextAlignment(Qt::AlignCenter);
                _ui->TW_People->setItem(row, col, item);
            }
            _query.next();
        }
        _ui->TW_People->setRowCount(row);
        _ui->TW_People->resizeColumnsToContents();
        _ui->TW_People->resizeRowsToContents();

        _guard = false;
    }

};

#endif // Contacts_h
