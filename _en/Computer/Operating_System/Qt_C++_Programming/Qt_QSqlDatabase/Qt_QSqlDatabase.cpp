/* Qt_QSqlDatabase.cpp
Author: bss9395
Update: 2025/10/08T18:35:00+08@China-GuangDong-ZhanJiang+08
Keepin: bss9395@yeah.net
*/

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFontMetrics>
#include <QDateTime>
#include <QFile>
#include <QWidget>
#include <QLabel>
#include "Viewer.h"

struct Format {
	template<typename Type_>
	struct Enum {
		Type_ _enum = Type_();
		Enum(const Type_ &that) {
			_enum = that;
		}
		operator const Type_&() const {
			return _enum;
		}

		// 不需要定义bool operator!=(const Enum &lhs, const Enum &rhs);
		friend bool operator==(const Enum &lhs, const Enum &rhs) {
			return (lhs._enum == rhs._enum);
		}
	};

	typedef Enum<unsigned int> Align;
	static inline const Align _enum_align_left = 0b0001;
	static inline const Align _enum_align_center = 0b0010;
	static inline const Align _enum_align_right = 0b0100;

	static QString _Format_Table(const QList<QVector<QString>> &table, const Align &align = _enum_align_center) {
		QFont font("Consolas", 12);
		QFontMetrics metrics(font);
		long width_Space = metrics.width(" ");

		QVector<QVector<long>> length_cells;
		QVector<long> length_columns_maxi;
		for (auto iter = table.begin(); iter != table.end(); ++iter) {
			const QVector<QString> &row = (*iter);
			length_cells.push_back(QVector<long>(row.size(), 0));
			QVector<long> &length_cell_row = length_cells[length_cells.size() - 1];

			if ((row.size() <= length_columns_maxi.size()) == false) {
				length_columns_maxi.resize(row.size());
			}
			for (long idx = 0; idx < row.size(); idx += 1) {
				long width_cell = metrics.width(row[idx]);
				long length_cell = width_cell / width_Space;
				if (width_cell % width_Space != 0) {
					length_cell += 1;
				}

				length_cell_row[idx] = length_cell;
				if ((length_cell <= length_columns_maxi[idx]) == false) {
					length_columns_maxi[idx] = length_cell;
				}
			}
		}

		QString formatted = "";
		long irow = 0;
		for (auto iter = table.begin(); iter != table.end(); ++iter, irow += 1) {
			const QVector<QString> &row = (*iter);
			if (irow != 0) {
				formatted += "\n";
			}
			formatted += "|";
			for (long idx = 0; idx < length_columns_maxi.size(); idx += 1) {
				if (idx != 0) {
					formatted += "|";
				}
				if (idx < row.size()) {
					long paddings = length_columns_maxi[idx] - length_cells[irow][idx];
					if (align == _enum_align_left) {
						formatted += row[idx];
						formatted += QString(paddings, QChar(' '));
					} else if (align == _enum_align_center) {
						int paddings_left = paddings / 2;
						int paddings_right = paddings - paddings_left;
						formatted += QString(paddings_left, QChar(' '));
						formatted += row[idx];
						formatted += QString(paddings_right, QChar(' '));
					} else if (align == _enum_align_right) {
						formatted += QString(paddings, QChar(' '));
						formatted += row[idx];
					}
				} else {
					formatted += QString(length_columns_maxi[idx], QChar(' '));
				}
			}
			formatted += "|";

			if (irow == 0) {
				formatted += "\n|";
				for (long idx = 0; idx < length_columns_maxi.size(); idx += 1) {
					if (idx != 0) {
						formatted += "|";
					}
					formatted += QString(length_columns_maxi[idx], QChar('-'));
				}
				formatted += "|";
			}
		}

		return formatted;
	}
};

void _Test_MySQL_Open() {
	qDebug().nospace() << QSqlDatabase::drivers();

	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Open");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	//database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");

	if (database.open() == false) {
		qDebug().nospace() << database.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "连接数据库成功！";
	database.close();
}

void _Test_MySQL_Create_Database() {
	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Create_Database");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	// database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");
	if (database.open() == false) {
		qDebug().nospace() << database.lastError();
		database.close();
		return;
	}

	QString sql_drop_database = R"!(
DROP DATABASE IF EXISTS test_schema;
	)!";
	QSqlQuery query_drop_database(database);
	query_drop_database.prepare(sql_drop_database);
	if (query_drop_database.exec() == false) {
		qDebug().nospace() << query_drop_database.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "删除数据库成功！";

	QString sql_create_database = R"!(
CREATE DATABASE test_schema; 
-- DEFAULT CHARACTER SET utf8mb3 COLLATE utf8mb3_unicode_ci
-- DEFAULT ENCRYPTION='N'
    )!";
	QSqlQuery query_create_database(database);
	query_create_database.prepare(sql_create_database);
	if (query_create_database.exec() == false) {
		qDebug().nospace() << query_create_database.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "创建数据库成功！";
	database.close();
}

void _Test_MySQL_Create_Table() {
	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Create_Table");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");
	if (database.open() == false) {
		qDebug().nospace() << database.lastError();
		database.close();
		return;
	}

	QString sql_drop_table = R"!(
DROP TABLE IF EXISTS test_table;
	)!";
	QSqlQuery query_drop_table(database);
	query_drop_table.prepare(sql_drop_table);
	if (query_drop_table.exec() == false) {
		qDebug().nospace() << query_drop_table.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "删除数据表成功！";

	QString sql_create_table = R"!(
CREATE TABLE test_table (
  _id       BIGINT         NOT NULL AUTO_INCREMENT,
  _int      BIGINT         NULL,
  _float    DOUBLE         NULL,
  _decimal  DECIMAL(16,8)  NULL,
  _char     CHAR(255)      NULL,
  _varchar  VARCHAR(16046) NULL,
  _text     LONGTEXT       NULL,
  _date     DATE           NULL,
  _time     TIME(4)        NULL,
  _datetime DATETIME(4)    NULL,
  _bina     BINARY(128)    NULL,
  _blob     LONGBLOB       NULL,
  PRIMARY KEY (_id),
  UNIQUE INDEX _Unique_id(_id ASC)
)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;
    )!";
	QSqlQuery query_create_table(database);
	query_create_table.prepare(sql_create_table);
	if (query_create_table.exec() == false) {
		qDebug().nospace() << query_create_table.lastError().text();
		database.close();
		return;
	}
	qDebug().noquote() << "创建数据表成功！";

	database.close();
}

void _Test_MySQL_Insert() {
	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Insert");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");
	if (database.open() == false) {
		qDebug().nospace() << database.lastError();
		database.close();
		return;
	}

	QString sql_truncate = R"!(
TRUNCATE TABLE test_table;
	)!";
	QSqlQuery query_truncate(database);
	query_truncate.prepare(sql_truncate);
	if (query_truncate.exec() == false) {
		qDebug().nospace() << query_truncate.lastError().text();
		// 忽略错误
	}
	qDebug().nospace() << "截断数据表成功！";

	QString sql_insert = R"!(
INSERT INTO test_table
(_id, _int, _float, _decimal, _char, _varchar, _text, _date, _time, _datetime, _bina, _blob)
VALUES
(101, 1234, 5678.90, 1234.5678, '昵称', '评论', '全文', '2025-10-07', NOW(3), UTC_TIMESTAMP(3), 0x12345678, 0x12345678),
(:id, :int, :float, :decimal, :char, :varchar, :text, :date, :time, :datetime, UNHEX(:bina), :blob);
	)!";
	QSqlQuery query_insert(database);
	query_insert.prepare(sql_insert);
	query_insert.bindValue(":id", QVariant());
	query_insert.bindValue(":int", 1234);
	query_insert.bindValue(":float", 5678.90);
	query_insert.bindValue(":decimal", 1234.5678);
	query_insert.bindValue(":char", "昵称");
	query_insert.bindValue(":varchar", "评论");
	query_insert.bindValue(":text", "全文");
	query_insert.bindValue(":date", QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd"));
	query_insert.bindValue(":time", QDateTime::currentDateTimeUtc().toString("HH:mm:ss.zzz"));  // MySQL报错格式yyyy-MM-ddTHH:mm:ss.zzz
	query_insert.bindValue(":datetime", QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddTHH:mm:ss.zzz"));
	query_insert.bindValue(":bina", 12345678);

	qDebug().nospace() << QApplication::applicationFilePath();
    QString filepath = "E:/QtProjects/Qt_QSqlDatabase/images/M31.svg";
	QFile file = QFile(filepath);
	if (file.open(QFile::ReadOnly) == false) {
		qDebug().nospace() << file.errorString();
		// 事务回滚
		return;
	}
	QByteArray blob = file.readAll();
	query_insert.bindValue(":blob", blob);
	if (query_insert.exec() == false) {
		qDebug().nospace() << query_insert.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "插入数据行成功！";
	database.close();
}

void _Test_MySQL_Transaction() {
	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Transaction");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");
	if (database.open() == false) {
		qDebug().nospace() << database.lastError();
		database.close();
		return;
	}

	if (database.transaction() == false) {
		qDebug().nospace() << database.lastError().text();  // 数据库驱动不支持事务
		qDebug().nospace() << "启动事务失败！";
	} else {
		qDebug().nospace() << "启动事务成功！";
	}

	try {
		QString sql_truncate = R"!(
TRUNCATE TABLE test_table;
	)!";
		QSqlQuery query_truncate(database);
		query_truncate.prepare(sql_truncate);
		if (query_truncate.exec() == false) {
			qDebug().nospace() << query_truncate.lastError().text();
			// 忽略错误
		}
		qDebug().nospace() << "截断数据表成功！";

		QString sql_insert = R"!(
INSERT INTO test_table
(_id, _int, _float, _decimal, _char, _varchar, _text, _date, _time, _datetime, _bina)
VALUES
(101, 1234, 5678.90, 1234.5678, '昵称', '评论', '全文', '2025-10-07', NOW(3), UTC_TIMESTAMP(3), 0x12345678),
(:id, :int, :float, :decimal, :char, :varchar, :text, :date, :time, :datetime, UNHEX(:bina));
	)!";
		QSqlQuery query_insert(database);
		query_insert.prepare(sql_insert);
		query_insert.bindValue(":id", QVariant());
		query_insert.bindValue(":int", 1234);
		query_insert.bindValue(":float", 5678.90);
		query_insert.bindValue(":decimal", 1234.5678);
		query_insert.bindValue(":char", "昵称");
		query_insert.bindValue(":varchar", "评论");
		query_insert.bindValue(":text", "全文");
		query_insert.bindValue(":date", QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd"));
		query_insert.bindValue(":time", QDateTime::currentDateTimeUtc().toString("HH:mm:ss.zzz"));  // MySQL报错格式yyyy-MM-ddTHH:mm:ss.zzz
		query_insert.bindValue(":datetime", QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddTHH:mm:ss.zzz"));
		query_insert.bindValue(":bina", 12345678);
		if (query_insert.exec() == false) {
			qDebug().nospace() << query_insert.lastError().text();
			throw QString("插入数据行失败！");
		}
		qDebug().nospace() << "插入数据行成功！";

		// 插入数据blob
		qDebug().nospace() << QApplication::applicationFilePath();
        QString filepath = "E:/QtProjects/Qt_QSqlDatabase/images/M31.svg";
		QFile file = QFile(filepath);
		if (file.open(QFile::ReadOnly) == false) {
			qDebug().nospace() << file.errorString();
			throw QString("打开文件失败！");
		}
		QByteArray blob = file.readAll();

		QString sql_update_blob = R"!(
UPDATE test_table
SET    _blob = :blob
WHERE  _id = :id;
		)!";
		QSqlQuery query_update_blob(database);
		query_update_blob.prepare(sql_update_blob);
		query_update_blob.bindValue(":blob", blob);
		query_update_blob.bindValue(":id", "102");
		if (query_update_blob.exec() == false) {
			qDebug().nospace() << query_update_blob.lastError().text();
			throw QString("更新数据段失败！");
		}
		qDebug().nospace() << "更新数据段成功！";
	} catch (const QString &except) {
		database.rollback();
		qDebug().nospace() << except;
	}

	if (database.commit() == false) {
		qDebug().nospace() << database.lastError().text();  // 数据库驱动不支持事务。
		qDebug().nospace() << "执行事务失败！";
	} else {
		qDebug().nospace() << "执行事务成功！";
	}
	database.close();
}

void _Test_MySQL_Select(long offset = 0, long limit = 10) {
	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Select");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");
	if (database.open() == false) {
		qDebug().nospace() << database.lastError();
		database.close();
		return;
	}

	QString sql_select = R"!(
SELECT _id, _int, _float, _decimal, _char, _varchar, _text, _date, _time, _datetime, HEX(_bina), (CASE WHEN _blob IS NULL THEN 'NULL' ELSE 'BLOB' END) AS _blob
FROM test_table
LIMIT :limit OFFSET :offset;
	)!";
	QSqlQuery query_select(database);
	query_select.prepare(sql_select);
	query_select.bindValue(":limit", limit);
	query_select.bindValue(":offset", offset);
	if (query_select.exec() == false) {
		qDebug().nospace() << query_select.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "查询数据表成功！";

	QList<QVector<QString>> records;
	QSqlRecord header = query_select.record();
	// 提取数据头
	{
		QVector<QString> record{ (long)header.count() };
		for (long col = 0, cols = (long)header.count(); col < cols; col += 1) {
			record[col] = header.fieldName(col);
		}
		records.push_back(record);
	}
	// 提取数据行
	for (query_select.first(); query_select.isValid() == true; query_select.next()) {
		QVector<QString> record{ (long)header.count() };
		for (long col = 0, cols = (long)header.count(); col < cols; col += 1) {
			if (query_select.value(col).isNull() == true) {
				record[col] = "NULL";
				continue;
			}
			record[col] = query_select.value(col).toString();
		}
		records.push_back(record);
	}

	qDebug().nospace().noquote() << Format::_Format_Table(records);
	database.close();
}

void _Test_MySQL_Select_Blob(const QString &id = "102") {
	QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "MySQL_Select_Blob");
	database.setHostName("127.0.0.1");
	database.setPort(3306);
	database.setDatabaseName("test_schema");
	database.setUserName("root");
	database.setPassword("Password");
	if (database.open() == false) {
		qDebug().nospace() << database.lastError();
		database.close();
		return;
	}

	QString sql_select_blob = R"!(
SELECT _blob
FROM test_table
WHERE _id = :id;
	)!";
	QSqlQuery query_select_blob(database);
	query_select_blob.prepare(sql_select_blob);
	query_select_blob.bindValue(":id", id);
	if (query_select_blob.exec() == false) {
		qDebug().nospace() << query_select_blob.lastError().text();
		database.close();
		return;
	}
	qDebug().nospace() << "查询数据段成功！";

	query_select_blob.first();
	QByteArray blob = query_select_blob.value(0).toByteArray();
	Viewer *viewer = new Viewer(200, 200);	
	viewer->_Display_Image("图像", blob);
	viewer->show();

	database.close();
}

int main(int argc, char* argv[]) {
	QApplication application(argc, argv);

	// _Test_MySQL_Open();
	// _Test_MySQL_Create_Database();
	// _Test_MySQL_Create_Table();
	// _Test_MySQL_Insert();
	_Test_MySQL_Transaction();
	_Test_MySQL_Select();
	_Test_MySQL_Select_Blob();

	return application.exec();
}
