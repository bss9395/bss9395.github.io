#include "Common.h"



struct Datum {
    static inline struct EMark {
        const char *_ID = "ID";
        const char *_Name = "Name";
        const char *_Gender = "Gender";
        const char *_Date = "Date";
        const char *_Nationality = "Nationality";
        const char *_Score = "Score";

        EMark() {

        }
    } _Mark;

    // note: data of whatever type all could be represented as string.
    QString _ID = "20220112173800";
    QString _name = "璀璨星辰";
    QString _gender = "男";
    QDate _date = QDate(1993, 9, 5);
    QString _nationality = "汉";
    double _score = 99.9;
};

Sheet::Sheet(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::Sheet) {
    Logging(__FUNCTION__);

    _ui->setupUi(this);
    _ui->SB_Status_Bar->addWidget(_ui->GB_Status_Bar);

    QObject::connect(_ui->A_Testing, &QAction::triggered, [this]() -> void {
        _ui->TW_Sheet->setRowCount(0);
        _ui->TW_Sheet->setColumnCount(0);

        QStringList header = {
            "标识", "姓名", "性别", "生日", "民族", "成绩"
        };
        _ui->TW_Sheet->setColumnCount(header.size());
        for(iptr col = 0, numb = _ui->TW_Sheet->columnCount(); col < numb; col += 1) {
            QTableWidgetItem *item = new QTableWidgetItem(header[col]);
            item->setTextAlignment(Qt::AlignCenter);
            _ui->TW_Sheet->setHorizontalHeaderItem(col, item);
        }

        _ui->TW_Sheet->setRowCount(10);
        srand(time(NULL));
        for(iptr row = 0, numb = _ui->TW_Sheet->rowCount(); row < numb; row += 1) {
            Datum datum = Datum();
            datum._ID = QString("20220112") + QTime(rand() % 24 + 0, rand() % 60 + 0, rand() % 60 + 0).toString("hhmmss");
            datum._name[0] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
            datum._name[1] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
            datum._name[2] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
            datum._name[3] = (QChar)(0);        // basic chinese character encoded from 0x4E00 to 0x9FA5.
            datum._gender = (rand() % 2 == 0) ? "男" : "女";
            datum._date = datum._date.addYears(rand() % 12 + 0).addMonths(rand() % 12 + 0).addDays(rand() % 31 + 0);
            datum._nationality[0] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
            datum._nationality[1] = (QChar)(0);
            datum._score = (rand() % 10000 / 100.0);

            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(datum._ID);
            item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            _ui->TW_Sheet->setItem(row, Index_Class(Datum::EMark, _ID), item);
            item = new QTableWidgetItem();
            item->setText(datum._name);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            _ui->TW_Sheet->setItem(row, Index_Class(Datum::EMark, _Name), item);
            item = new QTableWidgetItem();
            item->setText(datum._gender);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            _ui->TW_Sheet->setItem(row, Index_Class(Datum::EMark, _Gender), item);
            item = new QTableWidgetItem();
            item->setText(datum._date.toString("yyyy-MM-dd"));
            item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            _ui->TW_Sheet->setItem(row, Index_Class(Datum::EMark, _Date), item);
            item = new QTableWidgetItem();
            item->setText(datum._nationality);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            _ui->TW_Sheet->setItem(row, Index_Class(Datum::EMark, _Nationality), item);
            item=new QTableWidgetItem();
            item->setText(QString("%1").arg(datum._score, 6, 'f', 2));
            item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            _ui->TW_Sheet->setItem(row, Index_Class(Datum::EMark, _Score), item);
        }
        _ui->TW_Sheet->resizeColumnsToContents();
        _ui->TW_Sheet->resizeRowsToContents();
    });

    _ui->TW_Sheet->setAlternatingRowColors(true);
    _ui->TW_Sheet->setEditTriggers(QTableWidget::DoubleClicked);
    QObject::connect(_ui->PB_Set, &QPushButton::clicked, [this]() -> void {
        _ui->TW_Sheet->setColumnCount(_ui->SB_Column->value());
        for(iptr col = 0, numb = _ui->TW_Sheet->columnCount(); col < numb; col += 1) {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString("C%1").arg(col + 1)); // shift 1
            item->setTextAlignment(Qt::AlignCenter);
            _ui->TW_Sheet->setHorizontalHeaderItem(col, item);
        }
        _ui->TW_Sheet->setRowCount(_ui->SB_Row->value());
        for(iptr row = 0, numb = _ui->TW_Sheet->rowCount(); row < numb; row += 1) {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString("R%1").arg(row + 1)); // shift 1
            item->setTextAlignment(Qt::AlignCenter);
            _ui->TW_Sheet->setVerticalHeaderItem(row, item);
        }
    });

    QObject::connect(_ui->A_Select_Cell, &QAction::triggered, [this]() -> void {
        _ui->TW_Sheet->setSelectionBehavior(QTableWidget::SelectItems);
    });

    QObject::connect(_ui->A_Select_Row, &QAction::triggered, [this]() -> void {
        _ui->TW_Sheet->setSelectionBehavior(QTableWidget::SelectRows);
    });

    QObject::connect(_ui->A_Select_Column, &QAction::triggered, [this]() -> void {
        _ui->TW_Sheet->setSelectionBehavior(QTableWidget::SelectColumns);
    });
}

Sheet::~Sheet() {
    Logging(__FUNCTION__);

    delete _ui;
}

