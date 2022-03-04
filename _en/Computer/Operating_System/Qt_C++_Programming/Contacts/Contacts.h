/* Contacts.h
Author: BSS9395
Update: 2022-03-04T00:49:00+08@China-Guangdong-Shenzhen+08
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
    bool _dirty = true;
    iptr _row = -1;
    iptr _col = -1;
    QByteArray _avatar = QByteArray();

public:
    explicit Contacts(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Contacts) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);
        _ui->CB_Gender->addItems(Settings::_Genders);
        _ui->CB_Gender->setCurrentIndex(-1);
        _ui->CB_Degree->addItems(Settings::_Degrees);
        _ui->CB_Degree->setCurrentIndex(-1);
        _ui->DE_Birthday->setSpecialValueText("          ");
        _ui->DE_Birthday->setDate(QDate::fromString("0001-01-01", "yyyy-MM-dd"));
        Enable(false);

        ////////////////////////////////

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

            Populate();
        });

        QObject::connect(_ui->A_Insert, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Insert, &QAction::triggered, [this]() -> void {");
            Block_Signals(true);

            _row = _ui->TW_People->currentRow();     // note: if no current selection, should return -1.
            _col = _ui->TW_People->currentColumn();
            // System::Logging("_row = %td, _col = %td", _row, _col);
            if(_row < 0) {
                _row = 0;
            }
            if(_col < 0) {
                _col = 0;
            }
            _ui->TW_People->insertRow(_row);
            for(iptr col = 0, cols = _ui->TW_People->columnCount(); col < cols; col += 1) {
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText("");
                item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                _ui->TW_People->setItem(_row, col, item);   // note: (_row, col)
            }
            QTableWidgetItem *avatar = _ui->TW_People->item(_row, _fields.indexOf("_Avatar"));
            avatar->setText("VOID");
            avatar->setData(Qt::UserRole, "");
            _ui->TW_People->setCurrentCell(_row, _col);
            _inserts.push_back(_ui->TW_People->item(_row, _fields.indexOf("_Identity")));

            Block_Signals(false);
        });

        QObject::connect(_ui->A_Delete, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Delete, &QAction::triggered, [this]() -> void {");

            _row = _ui->TW_People->currentRow();
            _col = _ui->TW_People->currentColumn();
            // System::Logging("_row = %td, _col = %td", _row, _col);
            if(0 <= _row && 0 <= _col) {
                QTableWidgetItem *item = _ui->TW_People->item(_row, _fields.indexOf("_Identity"));
                if(1 <= _ui->TW_People->rowCount()) {
                    _ui->TW_People->setCurrentCell(_row, _col);
                }

                for(iptr i = 0, numb = _inserts.size(); i < numb; i += 1) {
                    if(_inserts[i] == item) {
                        _inserts[i] = nullptr;
                        _ui->TW_People->removeRow(_row);
                        return ;
                    }
                }
                for(iptr i = 0, numb = _updates.size(); i < numb; i += 1) {
                    if(_updates[i] == item) {
                        _updates[i] = nullptr;
                        _deletes.push_back(item->data(Qt::UserRole).toString());
                        _ui->TW_People->removeRow(_row);
                        return ;
                    }
                }
                _deletes.push_back(item->text());
                _ui->TW_People->removeRow(_row);
            }
        });

        QObject::connect(_ui->A_Submit, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Submit, &QAction::triggered, [this]() -> void {");

            static QString query_delete = R"(
delete from [People]
where [_Identity]=:Identity;
)";
            static QString query_insert = R"(
insert into [People]
([_Identity], [_Name],   [_Gender],  [_Birthday],   [_Homepage],
 [_Mobile],   [_Email],  [_Company], [_Department], [_Title],
 [_Employee], [_Degree], [_Address], [_Memo],
 [_Avatar])
values
(:Identity, :Name,   :Gender,  :Birthday,   :Homepage,
 :Mobile,   :Email,  :Company, :Department, :Title,
 :Employee, :Degree, :Address, :Memo,
 :Avatar);
)";
            static QString query_update = R"(
update [People]
set    [_Identity]=:Identity, [_Name]=:Name,     [_Gender]=:Gender,   [_Birthday]=:Birthday,     [_Homepage]=:Homepage,
       [_Mobile]=:Mobile,     [_Email]=:Email,   [_Company]=:Company, [_Department]=:Department, [_Title]=:Title,
       [_Employee]=:Employee, [_Degree]=:Degree, [_Address]=:Address, [_Memo]=:Memo,
       [_Avatar]=:Avatar
where  [_Identity]=:Original;
)";

            ////////////////////////////

            QSqlDatabase::database().transaction();
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
                _query.bindValue(":Avatar", _ui->TW_People->item(row, _fields.indexOf("_Avatar"))->data(Qt::UserRole));
                _query.exec();
            }

            ////////////////////////////

            _query.prepare(query_update);
            for(iptr i = 0, numb = _updates.size(); i < numb; i += 1) {
                if(_updates[i] == nullptr) {
                    continue;
                }
                iptr row = _updates[i]->row();
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
                _query.bindValue(":Avatar", _ui->TW_People->item(row, _fields.indexOf("_Avatar"))->data(Qt::UserRole));
                _query.bindValue(":Original", _ui->TW_People->item(row, _fields.indexOf("_Identity"))->data(Qt::UserRole).toString());
                _query.exec();
            }

            ////////////////////////////

            if(System::Checking(QSqlDatabase::database().commit() == false, System::_Error, NULL)) {
                _caption = "提交数据表失败";
                _label = _query.lastError().text();
                QMessageBox::critical(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                QSqlDatabase::database().rollback();
            }

            for(iptr i = 0, numb = _updates.size(); i < numb; i += 1) {
                if(_updates[i] == nullptr) {
                    continue;
                }
                QTableWidgetItem *item = _ui->TW_People->item(_updates[i]->row(), _fields.indexOf("_Identity"));
                item->setData(Qt::UserRole, QVariant::String);                                           // note: set NULL.
                item=_ui->TW_People->item(_updates[i]->row(), _fields.indexOf("_Avatar"));
                item->setText((item->data(Qt::UserRole).toByteArray().length() <= 0) ? "VOID" : "BLOB"); // note: reset UI.
            }
            _deletes.clear();
            _inserts.clear();
            _updates.clear();
            _dirty = true;
        });

        QObject::connect(_ui->A_Revert, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Revert, &QAction::triggered, [this]() -> void {");

            Populate();
        });

        ////////////////////////////////

        QObject::connect(_ui->TW_People, &QTableWidget::cellDoubleClicked, [this](int row, int column) -> void {
            System::Logging("QObject::connect(_ui->TW_People, &QTableWidget::cellDoubleClicked, [this](int row, int column) -> void {");

            (void) row;
            if(column == _fields.indexOf("_Identity")) {
                Update_Identity();
            }
        });

        QObject::connect(_ui->TW_People, &QTableWidget::cellChanged, [this](int row, int column) -> void {
            System::Logging("QObject::connect(_ui->TW_People, &QTableWidget::cellChanged, [this]() -> void {");

            (void) row;
            (void) column;
            Update_Identity();
        });

        QItemSelectionModel *model = _ui->TW_People->selectionModel();
        QObject::connect(model, &QItemSelectionModel::currentRowChanged, [this](const QModelIndex &current, const QModelIndex &previous) -> void {
            System::Logging("QObject::connect(model, &QItemSelectionModel::currentRowChanged, [this]() -> void {");
            Block_Signals(true);

            (void) current;
            (void) previous;
            if(current.isValid() == false) {
                return ;
            }
            _row = _ui->TW_People->currentRow();
            _col = _ui->TW_People->currentColumn();

            static const QString query_avatar = R"(
select [_Avatar]
from   [People]
where  [_Identity]=:Identity;
)";

            QTableWidgetItem *identity = nullptr;
            QTableWidgetItem *item = nullptr;
            identity = item = _ui->TW_People->item(_row, _fields.indexOf("_Identity"));
            _ui->LE_Identity->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Name"));
            _ui->LE_Name->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Gender"));
            (item->text().size() <= 0) ? _ui->CB_Gender->setCurrentIndex(-1) : _ui->CB_Gender->setCurrentText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Birthday"));
            _ui->DE_Birthday->setDate(QDate::fromString((item->text().size() <= 0) ? "0001-01-01" : item->text(), "yyyy-MM-dd"));
            item = _ui->TW_People->item(_row, _fields.indexOf("_Homepage"));
            _ui->LE_Homepage->setText( item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Mobile"));
            _ui->LE_Mobile->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Email"));
            _ui->LE_Email->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Company"));
            _ui->LE_Company->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Department"));
            _ui->LE_Department->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Title"));
            _ui->LE_Title->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Employee"));
            _ui->LE_Employee->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Degree"));
            (item->text().size() <= 0) ? _ui->CB_Degree->setCurrentIndex(-1) : _ui->CB_Degree->setCurrentText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Address"));
            _ui->LE_Address->setText(item->text());
            item = _ui->TW_People->item(_row, _fields.indexOf("_Memo"));
            _ui->PLE_Memo->setPlainText(item->text());

            ////////////////////////

            item = _ui->TW_People->item(_row, _fields.indexOf("_Avatar"));
            if(item->text() == "Update") {    // note: retrive avatar from cache.
                Set_Avatar(item->data(Qt::UserRole).toByteArray());
            } else {                          // note: retrive avatar from database.
                _query.prepare(query_avatar);
                _query.bindValue(":Identity", identity->text());
                if(System::Checking(_query.exec() == false, System::_Error, NULL)) {
                    _caption = "查询数据表失败";
                    _label = _query.lastError().text();
                    QMessageBox::warning(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                    Exception::Excepting(true, System::_Error, _label, QString(""));
                    return ;
                }
                _query.first();               // note: move record cursor to the first one.
                _avatar = _query.record().value("_Avatar").toByteArray();
                Set_Avatar(_avatar);
            }
            Block_Signals(false);
        });

        ////////////////////////////////

        _ui->TB_Avatar->addAction(_ui->A_Update_Avatar);
        _ui->TB_Avatar->addAction(_ui->A_Clear_Avatar);
        _ui->TB_Avatar->setDefaultAction(_ui->A_Update_Avatar);
        QObject::connect(_ui->A_Update_Avatar, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Update_Avatar, &QAction::triggered, [this]() -> void {");

            _caption = "加载图片";
            _filter = "图片(*.svg *.png *.jpg *.jpeg)";
            QString filename = QFileDialog::getOpenFileName(this, _caption, QDir::currentPath(), _filter);
            if(filename.size() <= 0) {
                return ;
            }

            QFile file = QFile(filename);
            if(System::Checking(file.open(QFile::ReadOnly) == false, System::_Warn, NULL)) {
                _caption = "加载文件失败";
                _label = "file.open(QFile::ReadOnly) == false";
                QMessageBox::warning(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                return ;
            }
            _avatar = file.readAll();
            Set_Avatar(_avatar);
            QTableWidgetItem *item = _ui->TW_People->item(_row, _fields.indexOf("_Avatar"));
            item->setData(Qt::UserRole, _avatar);
            item->setText("Update");
        });

        QObject::connect(_ui->A_Clear_Avatar, &QAction::triggered, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Clear_Avatar, &QAction::triggered, [this]() -> void {");

            _avatar.clear();
            Set_Avatar(_avatar);
            QTableWidgetItem *item = _ui->TW_People->item(_row, _fields.indexOf("_Avatar"));
            item->setData(Qt::UserRole, _avatar);
            item->setText("Update");
        });

        QObject::connect(_ui->LE_Identity, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Identity, &QLineEdit::editingFinished, [this]() -> void {");

            Update_Identity();
            _ui->TW_People->item(_row, _fields.indexOf("_Identity"))->setText(_ui->LE_Identity->text());
        });

        QObject::connect(_ui->LE_Name, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Name, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Name"))->setText(_ui->LE_Name->text());
        });

        QObject::connect(_ui->CB_Gender, &QComboBox::currentTextChanged, [this]() -> void {
            System::Logging("QObject::connect(_ui->CB_Gender, &QComboBox::currentTextChanged, [this](QString text) -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Gender"))->setText(_ui->CB_Gender->currentText());
        });

        QObject::connect(_ui->DE_Birthday, &QDateEdit::dateChanged, [this]() -> void {
            System::Logging("QObject::connect(_ui->DE_Birthday, &QDateEdit::dateChanged, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Birthday"))->setText(_ui->DE_Birthday->text());
        });

        QObject::connect(_ui->LE_Homepage, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Homepage, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Homepage"))->setText(_ui->LE_Homepage->text());
        });

        QObject::connect(_ui->LE_Mobile, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Mobile, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Mobile"))->setText(_ui->LE_Mobile->text());
        });

        QObject::connect(_ui->LE_Email, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Email, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Email"))->setText(_ui->LE_Email->text());
        });

        QObject::connect(_ui->LE_Company, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Company, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Company"))->setText(_ui->LE_Company->text());
        });

        QObject::connect(_ui->LE_Department, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Department, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Department"))->setText(_ui->LE_Department->text());
        });

        QObject::connect(_ui->LE_Title, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Title, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("Title"))->setText(_ui->LE_Title->text());
        });

        QObject::connect(_ui->LE_Employee, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Employee, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Employee"))->setText(_ui->LE_Employee->text());
        });

        QObject::connect(_ui->LE_Address, &QLineEdit::editingFinished, [this]() -> void {
            System::Logging("QObject::connect(_ui->LE_Address, &QLineEdit::editingFinished, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Address"))->setText(_ui->LE_Address->text());
        });

        QObject::connect(_ui->PLE_Memo, &QPlainTextEdit::textChanged, [this]() -> void {
            System::Logging("QObject::connect(_ui->PLE_Memo, &QPlainTextEdit::textChanged, [this]() -> void {");

            _ui->TW_People->item(_row, _fields.indexOf("_Memo"))->setText(_ui->PLE_Memo->toPlainText());
        });
    }

    virtual ~Contacts() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void Set_Avatar(const QByteArray &avatar) {
        System::Logging(__FUNCTION__);

        if(0 < avatar.size()) {
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(avatar);
            _ui->TB_Avatar->setIcon(pixmap);
        } else {
            _ui->TB_Avatar->setDefaultAction(_ui->A_Update_Avatar);  // note: if avatar is VOID, reset UI.
        }
    }

    void Update_Identity() {
        System::Logging(__FUNCTION__);

        QTableWidgetItem *item = _ui->TW_People->item(_row, _fields.indexOf("_Identity"));
        if(item->data(Qt::UserRole).isValid() == false) {  // note: set once.
            item->setData(Qt::UserRole, item->text());     // note: update row.
            _ui->TW_People->item(_row, _fields.indexOf("_Avatar"))->setData(Qt::UserRole, _avatar);
            _updates.push_back(item);
        }
    }

    void Populate() {
        System::Logging(__FUNCTION__);
        Block_Signals(true);

        static QString query_select = R"(
select [_Identity], [_Name], [_Gender], [_Birthday], [_Homepage],
       [_Mobile], [_Email], [_Company], [_Department], [_Title],
       [_Employee], [_Degree], [_Address], [_Memo],
       (case when [_Avatar]!='' then 'BLOB' else 'VOID' end) as [_Avatar]
from   [People];
)";

        if(_dirty == true) {
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
        _ui->TW_People->setRowCount(capacity);             // note: maybe unsupported, size() for SELECT, numRowsAffected() for others.
        for(_query.first(); _query.isValid(); row += 1) {  // note: _query.first() moves record cursor to the first one.
            if((row < capacity) == false) {
                capacity *= 2;
                _ui->TW_People->setRowCount(capacity);
            }
            QSqlRecord record = _query.record();
            for(iptr col = 0, cols = record.count(); col < cols; col += 1) {
                QTableWidgetItem *item = new QTableWidgetItem();
                QVariant variant = record.value(col);
                item->setText(variant.toString());
                item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
                _ui->TW_People->setItem(row, col, item);
            }
            _query.next();
        }
        _ui->TW_People->setRowCount(row);
        _ui->TW_People->resizeColumnsToContents();
        _ui->TW_People->resizeRowsToContents();

        Block_Signals(false);
        _ui->TW_People->selectRow(0);
        _dirty = false;
        Enable(true);
    }

    void Block_Signals(bool block) {
        System::Logging("Block_Signals(%s)", (block == true) ? "true" : "false");

        _ui->TW_People->blockSignals(block);
        _ui->TW_People->selectionModel()->blockSignals(block);
        _ui->TB_Avatar->blockSignals(block);
        _ui->LE_Identity->blockSignals(block);
        _ui->LE_Name->blockSignals(block);
        _ui->CB_Gender->blockSignals(block);
        _ui->DE_Birthday->blockSignals(block);
        _ui->LE_Homepage->blockSignals(block);
        _ui->LE_Mobile->blockSignals(block);
        _ui->LE_Email->blockSignals(block);
        _ui->LE_Company->blockSignals(block);
        _ui->LE_Department->blockSignals(block);
        _ui->LE_Title->blockSignals(block);
        _ui->LE_Employee->blockSignals(block);
        _ui->CB_Degree->blockSignals(block);
        _ui->LE_Address->blockSignals(block);
        _ui->PLE_Memo->blockSignals(block);
    }

    void Enable(bool enable) {
        System::Logging(__FUNCTION__);

        _ui->A_Insert->setEnabled(enable);
        _ui->A_Delete->setEnabled(enable);
        _ui->A_Submit->setEnabled(enable);
        _ui->A_Revert->setEnabled(enable);
        _ui->A_Update_Avatar->setEnabled(enable);
        _ui->A_Clear_Avatar->setEnabled(enable);
        _ui->W_Information->setEnabled(enable);
    }
};

#endif // Contacts_h
