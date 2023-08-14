/* Qt_SQLite.cpp
Author: BSS9395
Update: 2023-08-11T23:04:00+08@China-Guangdong-Zhanjiang+08
*/

#include <iostream>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextCodec>
#include <QTime>
#include <QElapsedTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


class Qt_SQLite {
public:
    inline static QString _table_create = R"(
CREATE TABLE [information] (
    [id]          INTEGER NOT NULL,
    [name]        TEXT,
    [birthday]    TEXT,
    PRIMARY KEY("id" AUTOINCREMENT)
);
    )";

    inline static QString _table_insert = R"(
INSERT INTO [information]
([name], [birthday])
VALUES (:name, :birthday);
    )";

    inline static QString _table_update = R"(
UPDATE [information]
SET [birthday] = :birthday
WHERE [name] = :name;
    )";

    inline static QString _table_delete = R"(
DELETE FROM [information]
WHERE [name] = :name;
    )";

    inline static QString _table_query = R"(
SELECT [id], [name], [birthday]
FROM [information];
    )";

public:
    static void _Qt_SQLite() {
        QFile::remove("temp.db");
        QElapsedTimer timer;
        timer.start();


        QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "conn");
        database.setHostName("192.168.23.128");
        database.setPort(3306);
        database.setDatabaseName("temp");      // note: for SQLite, the filename, for MySQL, the database name.
        database.setUserName("root");          // note: useless
        database.setPassword("Password9395");  // note: useless
        if(database.open() == true) {
            fwprintf(stdout, L"database open success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"database open failed, time elapsed = %lldms\n", timer.elapsed());
        }


        QSqlQuery query(QSqlDatabase::database("conn"));
        if(query.exec(_table_create) == true) {
            fwprintf(stdout, L"table create success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"table create failed, %ls\n", query.lastError().text().toStdWString().c_str());
        }


        query.prepare(_table_insert);
        query.bindValue(":name", "Zhigui Huang");
        query.bindValue(":birthday", "1993-09-05");
        if(query.exec() == true) {
            fwprintf(stdout, L"table insert success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"table insert failed, %ls\n", query.lastError().text().toStdWString().c_str());
        }

        query.bindValue(":name", "Huang Zhigui");
        query.bindValue(":birthday", "1993-08-05");
        if(query.exec() == true) {
            fwprintf(stdout, L"table insert success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"table insert failed, %ls\n", query.lastError().text().toStdWString().c_str());
        }


        query.prepare(_table_update);
        query.bindValue(":name", "Huang Zhigui");
        query.bindValue(":birthday", "1993-09-05");
        if(query.exec() == true) {
            fwprintf(stdout, L"table update success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"table update failed, %ls\n", query.lastError().text().toStdWString().c_str());
        }


        query.prepare(_table_delete);
        query.bindValue(":name", "Huang Zhigui");
        if(query.exec() == true) {
            fwprintf(stdout, L"table delete success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"table delete failed, %ls\n", query.lastError().text().toStdWString().c_str());
        }


        query.prepare(_table_query);
        if(query.exec() == true) {
            fwprintf(stdout, L"table query success, time elapsed = %lldms\n", timer.elapsed());
        } else {
            fwprintf(stdout, L"table query failed, %ls\n", query.lastError().text().toStdWString().c_str());
        }
        for(query.first(); query.isValid(); query.next()) {
            QSqlRecord record = query.record();
            for(int i = 0; i < record.count(); i += 1) {
                (i == 0) ? fwprintf(stdout, L"%ls", record.value(i).toString().toStdWString().c_str()) : fwprintf(stdout, L", %ls", record.value(i).toString().toStdWString().c_str());
            }
            fwprintf(stdout, L"\n");
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    Qt_SQLite::_Qt_SQLite();

    return application.exec();
}
