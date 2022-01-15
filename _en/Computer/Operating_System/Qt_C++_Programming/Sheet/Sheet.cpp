/* Sheet.cpp
Author: BSS9395
Update: 2022-01-16T02:26:00+08@China-Guangdong-Shenzhen+08
Design: Sheet
Encode: UTF-8
System: Qt 5.15.2
*/

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
    double _score = 99.99;
};

////////////////////////////////////////////////////////////////////////////////

void Sheet::Update_Theme() {
    Logging(__FUNCTION__);

    static float font_size = 6.0;
    QString filename = _filename.mid(_filename.lastIndexOf('/') + 1);
    iptr padding = this->width() / font_size - filename.size();
    this->setWindowTitle(QString(padding / 2, ' ') + filename);
}

bool Sheet::event(QEvent *event) {
    // Logging(__FUNCTION__);

    if (event->type() == QEvent::Resize) {
        Update_Theme();
        return true;
    }
    return QWidget::event(event);
}

Sheet::Sheet(QWidget *parent)
    : QMainWindow(parent), _ui(new Ui::Sheet) {
    Logging(__FUNCTION__);
    _ui->setupUi(this);   // note: first line
    _ui->SB_Status_Bar->addWidget(_ui->GB_Status_Bar);

    _menu = new QMenu(this);
    _menu->addAction(_ui->A_Adjuct_Width);
    _menu->addAction(_ui->A_Adjust_Height);
    _ui->TB_Adjust->setDefaultAction(_ui->A_Adjuct_Width);
    _ui->TB_Adjust->setMenu(_menu);

    _menu = new QMenu(this);
    _menu->addAction(_ui->A_Insert_Row);
    _menu->addAction(_ui->A_Insert_Column);
    _menu->addAction(_ui->A_Delete_Row);
    _menu->addAction(_ui->A_Delete_Column);
    _ui->TB_Manipulate->setDefaultAction(_ui->A_Insert_Row);
    _ui->TB_Manipulate->setMenu(_menu);

    _menu = new QMenu(this);
    _menu->addAction(_ui->A_Select_Cell);
    _menu->addAction(_ui->A_Select_Row);
    _menu->addAction(_ui->A_Select_Column);
    _ui->TB_Select->setDefaultAction(_ui->A_Select_Cell);
    _ui->TB_Select->setMenu(_menu);

    _menu= new QMenu(this);
    _menu->addAction(_ui->A_Horizontal_Header);
    _menu->addAction(_ui->A_Vertical_Header);
    _ui->TB_Set->setDefaultAction(_ui->A_Set);
    _ui->TB_Set->setMenu(_menu);

    _ui->TB_Tool_Bar->addWidget(_ui->GB_Tool_Bar);

    ////////////////////////////////////

    QObject::connect(_ui->A_Testing, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Testing, &QAction::triggered, [this]() -> void {");
        _filename = QString("untitled.sheet");
        Update_Theme();

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
            datum._name.resize(3);
            datum._name[0] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);  // basic chinese character encoded from 0x4E00 to 0x9FA5.
            datum._name[1] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
            datum._name[2] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
            datum._gender = (rand() % 2 == 0) ? "男" : "女";
            datum._date = datum._date.addYears(rand() % 12 + 0).addMonths(rand() % 12 + 0).addDays(rand() % 31 + 0);
            datum._nationality.resize(1);
            datum._nationality[0] = (QChar)(rand() % (0x9FA5 - 0x4E00) + 0x4E00);
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

        _qcombobox_delegate = QComboBox_Delegate(QStringList{"男", "女"}, this);
        _qdoublespinbox_delegate = QDoubleSpinBox_Delegate( 0.0, 100.0, this);
        _ui->TW_Sheet->setItemDelegateForColumn(Index_Class(Datum::EMark, _Gender), &_qcombobox_delegate);
        _ui->TW_Sheet->setItemDelegateForColumn(Index_Class(Datum::EMark, _Score), &_qdoublespinbox_delegate);
    });

    QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Open, &QAction::triggered, [this]() -> void {");

        QString filename = QFileDialog::getOpenFileName(this, "打开文件", QDir::currentPath(), "文本文件(*.txt);;表单文件(*.sheet);;所有文件(*.*)");
        if (0 < filename.size()) {
            _filename = filename;
            Update_Theme();

            QFile file(filename);
            if (file.open(QFile::ReadWrite | QFile::Text)) {
                _ui->TW_Sheet->setColumnCount(0);
                _ui->TW_Sheet->setRowCount(0);

                QTextStream stream(&file);
                stream.setCodec("UTF-8");
                QRegularExpression reg = QRegularExpression("[ \t\n\r\f]+");
                if(!stream.atEnd()){
                    QStringList header = stream.readLine().split(reg, QString::SkipEmptyParts);
                    _ui->TW_Sheet->setColumnCount(header.size());
                    _ui->TW_Sheet->setHorizontalHeaderLabels(header);
                    iptr row = 0, capability = 20;
                    _ui->TW_Sheet->setRowCount(capability);
                    for(row = 0; !stream.atEnd(); row += 1) {
                        if(!(row < capability)){
                            capability += 20;
                            _ui->TW_Sheet->setRowCount(capability);
                        }
                        QStringList items = stream.readLine().split(reg, QString::SkipEmptyParts);
                        for(iptr col = 0, count = items.size(); col < count; col += 1) {
                            _ui->TW_Sheet->setItem(row, col, new QTableWidgetItem(items[col]));
                        }
                    }
                    _ui->TW_Sheet->setRowCount(row);
                    _ui->TW_Sheet->resizeColumnsToContents();
                    _ui->TW_Sheet->resizeRowsToContents();
                }
                // Update_Status_Bar(filename);
            }
        }
    });

    _ui->TW_Sheet->setAlternatingRowColors(true);
    _ui->TW_Sheet->setEditTriggers(QTableWidget::DoubleClicked);
    QObject::connect(_ui->A_Set, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->PB_Set, &QPushButton::clicked, [this]() -> void {");

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

    QObject::connect(_ui->A_Adjuct_Width, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Adjuct_Width, &QAction::triggered, [this]() -> void {");

        _ui->TW_Sheet->resizeColumnsToContents();
    });

    QObject::connect(_ui->A_Adjust_Height, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Adjust_Height, &QAction::triggered, [this]() -> void {");

        _ui->TW_Sheet->resizeRowsToContents();
    });

    QObject::connect(_ui->A_Select_Cell, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Select_Cell, &QAction::triggered, [this]() -> void {");

        _ui->TW_Sheet->setSelectionBehavior(QTableWidget::SelectItems);
    });

    QObject::connect(_ui->A_Select_Row, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Select_Row, &QAction::triggered, [this]() -> void {");

        _ui->TW_Sheet->setSelectionBehavior(QTableWidget::SelectRows);
    });

    QObject::connect(_ui->A_Select_Column, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Select_Column, &QAction::triggered, [this]() -> void {");

        _ui->TW_Sheet->setSelectionBehavior(QTableWidget::SelectColumns);
    });

    QObject::connect(_ui->A_Horizontal_Header, &QAction::toggled, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->A_Horizontal_Header, &QAction::toggled, [this](bool checked) -> void {");

        _ui->TW_Sheet->horizontalHeader()->setVisible(checked);
    });

    QObject::connect(_ui->A_Vertical_Header, &QAction::toggled, [this](bool checked) -> void {
        Logging("QObject::connect(_ui->A_Vertical_Header, &QAction::toggled, [this](bool checked) -> void {");

        _ui->TW_Sheet->verticalHeader()->setVisible(checked);
    });

    _ui->TW_Sheet->setSelectionMode(QTableWidget::ExtendedSelection);
    QObject::connect(_ui->A_Insert_Row, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Insert_Row, &QAction::triggered, [this]() -> void {");

        iptr row = _ui->TW_Sheet->currentRow();
        if(0 <= row) {
            row += 1;
            _ui->TW_Sheet->insertRow(row);
            iptr col = _ui->TW_Sheet->currentColumn();
            _ui->TW_Sheet->setCurrentCell(row, col);
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString("R%1").arg(row + 1));
            _ui->TW_Sheet->setVerticalHeaderItem(row, item);
            row += 1;
            for(iptr count = _ui->TW_Sheet->rowCount(); row < count; row += 1){
                QTableWidgetItem *item = _ui->TW_Sheet->verticalHeaderItem(row);
                item->setText(QString("R%1").arg(row + 1));
            }
        }
    });

    QObject::connect(_ui->A_Insert_Column, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Insert_Column, &QAction::triggered, [this]() -> void {");

        iptr col = _ui->TW_Sheet->currentColumn();
        if(0 <= col) {
            col += 1;
            _ui->TW_Sheet->insertColumn(col);
            iptr row = _ui->TW_Sheet->currentRow();
            _ui->TW_Sheet->setCurrentCell(row, col);
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString("C%1").arg(col + 1));
            _ui->TW_Sheet->setHorizontalHeaderItem(col, item);
            col += 1;
            for(iptr count = _ui->TW_Sheet->columnCount(); col < count; col += 1) {
                QTableWidgetItem *item = _ui->TW_Sheet->horizontalHeaderItem(col);
                item->setText(QString("C%1").arg(col + 1));
            }
        }
    });

    QObject::connect(_ui->A_Delete_Row, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Delete_Row, &QAction::triggered, [this]() -> void {");

        iptr row = _ui->TW_Sheet->currentRow();
        if(0 <= row) {
            _ui->TW_Sheet->removeRow(row);
            iptr col = _ui->TW_Sheet->currentColumn();
            _ui->TW_Sheet->setCurrentCell(row, col);
            for(iptr count = _ui->TW_Sheet->rowCount(); row < count; row += 1) {
                QTableWidgetItem *item = _ui->TW_Sheet->verticalHeaderItem(row);
                item->setText(QString("R%1").arg(row + 1));
            }
        }
    });

    QObject::connect(_ui->A_Delete_Column, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Delete_Column, &QAction::triggered, [this]() -> void {");

        iptr col = _ui->TW_Sheet->currentColumn();
        if(0 <= col) {
            _ui->TW_Sheet->removeColumn(col);
            iptr row = _ui->TW_Sheet->currentRow();
            _ui->TW_Sheet->setCurrentCell(row, col);
            for(iptr count = _ui->TW_Sheet->columnCount(); col < count; col += 1) {
                QTableWidgetItem *item = _ui->TW_Sheet->horizontalHeaderItem(col);
                item->setText(QString("C%1").arg(col + 1));
            }
        }
    });

    QObject::connect(_ui->TW_Sheet, &QTableWidget::currentCellChanged, [this](iptr current_row, iptr current_column, iptr previous_row, iptr previous_column) -> void {
        Logging("QObject::connect(_ui->TW_Sheet, &QTableWidget::currentCellChanged, [this](iptr current_row, iptr current_column, iptr previous_row, iptr previous_column) -> void {");

        (void)previous_row;
        (void)previous_column;
        if(0 <= current_row && 0 <= current_column) {
            _ui->L_Status_Bar->setText(QString("%1行，%2列").arg(current_row).arg(current_column));
        }
    });

    QObject::connect(_ui->A_Save_Sheet, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Save_Sheet, &QAction::triggered, [this]() -> void {");

        QString buffer = ""; buffer.reserve(1024);
        for(iptr row = 0, row_count = _ui->TW_Sheet->rowCount(); row < row_count; row += 1) {
            for(iptr col = 0, col_count = _ui->TW_Sheet->columnCount(); col < col_count; col += 1) {
                QTableWidgetItem *item = _ui->TW_Sheet->item(row, col);
                buffer += item->text(), buffer += "; ";
            }
            buffer += "\n";
        }

        ////////////////////////////////

        QFile file(_filename);
        if(file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream << buffer;
        }
    });

    QObject::connect(_ui->A_Align_Left, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Align_Left, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                (*beg)->setTextAlignment(Qt::AlignLeft | ((*beg)->textAlignment() & (~Qt::AlignHorizontal_Mask)));
            }
        }
    });

    QObject::connect(_ui->A_Align_Horizontal, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Align_Horizontal, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                (*beg)->setTextAlignment(Qt::AlignHCenter | ((*beg)->textAlignment() & (~Qt::AlignHorizontal_Mask)));
            }
        }
    });

    QObject::connect(_ui->A_Align_Right, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Align_Right, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                (*beg)->setTextAlignment(Qt::AlignRight | ((*beg)->textAlignment() & (~Qt::AlignHorizontal_Mask)));
            }
        }
    });

    QObject::connect(_ui->A_Align_Top, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Align_Top, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                (*beg)->setTextAlignment(Qt::AlignTop | ((*beg)->textAlignment() & (~Qt::AlignVertical_Mask)));
            }
        }
    });

    QObject::connect(_ui->A_Align_Vertical, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Align_Vertical, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                (*beg)->setTextAlignment(Qt::AlignVCenter | ((*beg)->textAlignment() & (~Qt::AlignVertical_Mask)));
            }
        }
    });

    QObject::connect(_ui->A_Align_Bottom, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Align_Bottom, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                (*beg)->setTextAlignment(Qt::AlignBottom | ((*beg)->textAlignment() & (~Qt::AlignVertical_Mask)));
            }
        }
    });

    QObject::connect(_ui->A_Bold, &QAction::triggered, [this]() -> void {
        Logging("QObject::connect(_ui->A_Bold, &QAction::triggered, [this]() -> void {");

        QList<QTableWidgetItem *> selected = _ui->TW_Sheet->selectedItems();
        if(0 < selected.size()) {
            for(auto beg = selected.begin(), end = selected.end(); beg != end; beg += 1) {
                QFont font = (*beg)->font();
                font.setBold(true);
                (*beg)->setFont(font);
            }
        }
    });

}

Sheet::~Sheet() {
    Logging(__FUNCTION__);

    delete _ui;
}

