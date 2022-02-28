/* Contacts.h
Author: BSS9395
Update: 2022-03-01T02:06:00+08@China-Guangdong-Shenzhen+08
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
#include "Setting.h"

class Contacts : public QMainWindow {
    Q_OBJECT

public:
    Ui::Contacts *_ui = nullptr;
    QString _caption = QString();
    QString _label = QString();
    QString _filter = QString();
    QSqlDatabase _database = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery _query = QSqlQuery();   // note: by default this will check if database was opened.

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
                QMessageBox::warning(this, _caption, _label, QMessageBox::Ok, QMessageBox::NoButton);
                return ;
            }

            _query.prepare(R"(
SELECT [_Identity], [_Name], [_Gender], [_Birthday], [_Homepage],
       [_Mobile], [_Email], [_Company], [_Department], [_Title],
       [_Employee], [_Degree], [_Address], [_Memo]
FROM   [People];
)");
            if(System::Checking(_query.exec() == false, System::_Error, NULL)) {
                _caption = "查询数据表失败";
            }

            QSqlRecord fields = _query.record();
            _ui->TW_People->setColumnCount(fields.count());
            for(iptr col = 0, count = fields.count(); col < count; col += 1) {
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText(fields.fieldName(col));
                item->setTextAlignment(Qt::AlignCenter);
                _ui->TW_People->setHorizontalHeaderItem(col, item);
            }

            for(_query.first(); _query.isValid(); ) {


                _query.next();
            }


        });


    }

    virtual ~Contacts() override {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:


};

#endif // Contacts_h
