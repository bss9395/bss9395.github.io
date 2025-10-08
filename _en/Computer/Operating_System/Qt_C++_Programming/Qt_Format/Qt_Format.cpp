/* Qt_Format.cpp
Author: bss9395
Update: 2025/10/07T18:07:00+08@China-GuangDong-ZhanJiang+08
Keepin: bss9395@yeah.net
*/

#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QFontMetrics>
#include <QList>
#include <QString>
#include <QVector>

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

void _Test_Format_Table() {
	QList<QVector<QString>> table;
	table.append(QVector<QString>{
		"column0", "column1"
	});
	table.append(QVector<QString>{
		"0", "你好！世界！", "I don't konw \"why\"."
	});

	QString formatted = Format::_Format_Table(table, Format::_enum_align_center);
	qDebug().nospace().noquote() << formatted;
}

int main(int argc, char *argv[]) {
	QApplication application(argc, argv);
	_Test_Format_Table();
	return application.exec();
}
