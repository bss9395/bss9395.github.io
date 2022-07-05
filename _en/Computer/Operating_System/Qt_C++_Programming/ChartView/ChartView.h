/* ChartView.h
Author: BSS9395
Update: 2022-07-05T14:13:00+08@China-Shanghai+08
Design: ChartView
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef ChartView_h
#define ChartView_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_ChartView.h"

class ChartView : public QMainWindow {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _ChartThemeLight        = Enume(this, QChart::ChartThemeLight       , "ChartThemeLight");
        Enume _ChartThemeBlueCerulean = Enume(this, QChart::ChartThemeBlueCerulean, "ChartThemeBlueCerulean");
        Enume _ChartThemeDark         = Enume(this, QChart::ChartThemeDark        , "ChartThemeDark");
        Enume _ChartThemeBrownSand    = Enume(this, QChart::ChartThemeBrownSand   , "ChartThemeBrownSand");
        Enume _ChartThemeBlueNcs      = Enume(this, QChart::ChartThemeBlueNcs     , "ChartThemeBlueNcs");
        Enume _ChartThemeHighContrast = Enume(this, QChart::ChartThemeHighContrast, "ChartThemeHighContrast");
        Enume _ChartThemeBlueIcy      = Enume(this, QChart::ChartThemeBlueIcy     , "ChartThemeBlueIcy");
        Enume _ChartThemeQt           = Enume(this, QChart::ChartThemeQt          , "ChartThemeQt");
    } _theme;

    struct : public Enume {
        Enume _name    = Enume(this, "_name"   , "姓名");
        Enume _math    = Enume(this, "_math"   , "数学");
        Enume _chinese = Enume(this, "_chinese", "语文");
        Enume _english = Enume(this, "_english", "英语");
        Enume _average = Enume(this, "_average", "平均分");
    } _record;

    struct : public Enume {
        Enume _upper60   = Enume(this, "_upper60"  , "00~59分");
        Enume _upper70   = Enume(this, "_upper70"  , "60~69分");
        Enume _upper80   = Enume(this, "_upper80"  , "70~79分");
        Enume _upper90   = Enume(this, "_upper90"  , "80~89分");
        Enume _upper100  = Enume(this, "_upper100" , "90~100分");
        Enume _min_score = Enume(this, "_min_score", "最低分");
        Enume _max_score = Enume(this, "_max_score", "最高分");
        Enume _avg_score = Enume(this, "_avg_score", "平均分");
    } _indicator;

public:
    Ui::ChartView *_ui = nullptr;
    QPen _pen = QPen();
    QBrush _brush = QBrush();
    iptr _rows = 30;
    iptr _numb = 20;
    qreal _width = 100.0;
    qreal _height = 100.0;

public:
    explicit ChartView(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::ChartView) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup_Data();
        _Analyze_Data();
        _Setup();
        _Setup_Bar();
        _Setup_Pie();
        _Setup_StackedBar();
        _Setup_PercentBar();
        _Setup_Scatter_Spline();

        QObject::connect(_ui->A_Generate_Data, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Generate_Data, &QAction::triggered, this, [this]() -> void {");

            _ui->TW_Data->blockSignals(true);
            _Setup_Data();
            _ui->TW_Data->blockSignals(false);
        });

        QObject::connect(_ui->A_Analyze_Data, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Analyze_Data, &QAction::triggered, this, [this]() -> void {");

            _ui->TW_Statistics->blockSignals(true);
            _Analyze_Data();
            _ui->TW_Statistics->blockSignals(false);
        });

        QObject::connect(_ui->TW_Data, &QTableWidget::itemChanged, this, [this](QTableWidgetItem *item) -> void {
            System::Logging("QObject::connect(_ui->TW_Data, &QTableWidget::itemChanged, this, [this](QTableWidgetItem *item) -> void {");

            if(_record._math._index <= item->column() && item->column() <= _record._english._index) {
                iptr row = item->row();
                qreal sum = 0.0;
                QTableWidgetItem *item = nullptr;
                for(iptr col = _record._math._index; col <= _record._english._index; col += 1) {
                    item = _ui->TW_Data->item(row, col);
                    sum += item->text().toDouble();
                }
                item = _ui->TW_Data->item(row, _record._average._index);
                item->setText(QString::asprintf("%.2f", sum / (_record._english._index - _record._math._index + 1)));
            }
        });

        QObject::connect(_ui->PB_Bar_Refresh, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Bar, &QPushButton::clicked, this, [this]() -> void {");

            _Setup_Bar();
        });

        QObject::connect(_ui->PB_Pie_Refresh, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Pie_Refresh, &QPushButton::clicked, this, [this]() -> void {");

            _Setup_Pie();
        });

        QObject::connect(_ui->CB_Subject, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Subject, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");
            (void)index;
            _Setup_Pie();
        });

        _ui->DSB_Hole->setRange(0.0, 0.7);
        _ui->DSB_Hole->setSingleStep(0.01);
        QObject::connect(_ui->DSB_Hole, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double ratio) -> void {
            System::Logging("QObject::connect(_ui->DSB_Hole, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double ratio) -> void {");

            QPieSeries *series = (QPieSeries *)_ui->CV_Pie->chart()->series().at(0);
            series->setHoleSize(ratio);
        });

        _ui->DSB_Size->setRange(0.0, 1.0);
        _ui->DSB_Size->setSingleStep(0.01);
        QObject::connect(_ui->DSB_Size, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double ratio) -> void {
            System::Logging("QObject::connect(_ui->DSB_Size, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double ratio) -> void {");

            QPieSeries *series = (QPieSeries *)_ui->CV_Pie->chart()->series().at(0);
            series->setPieSize(ratio);
        });

        QObject::connect(_ui->CB_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            _ui->CV_Pie->chart()->setTheme((QChart::ChartTheme)_theme[index]._enume);
        });

        QObject::connect(_ui->PB_StackedBar_Refresh, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_StackedBar_Refresh, &QPushButton::clicked, this, [this]() -> void {");

            _Setup_StackedBar();
        });

        QObject::connect(_ui->PB_PercentBar_Refresh, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_PercentBar_Refresh, &QPushButton::clicked, this, [this]() -> void {");

            _Setup_PercentBar();
        });

        QObject::connect(_ui->PB_Scatter_Spline_Refresh, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Scatter_Spline_Refresh, &QPushButton::clicked, this, [this]() -> void {");

            _Setup_Scatter_Spline();
        });
    }

    virtual ~ChartView() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _Setup_Data() {
        System::Logging(__FUNCTION__);

        _ui->TW_Data->setColumnCount(0);
        _ui->TW_Data->setRowCount(0);

        QStringList header = _record._Aliases();
        _ui->TW_Data->setColumnCount(header.count());
        _ui->TW_Data->setHorizontalHeaderLabels(header);

        _ui->TW_Data->setRowCount(_rows);
        for(iptr row = 0; row < _rows; row += 1) {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString::asprintf("学生%02d", (int)row + 1));
            item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            _ui->TW_Data->setItem(row, _record._name._index, item);

            qreal sum = 0.0;
            for(iptr col = _record._math._index; col <= _record._english._index; col += 1) {
                qreal score = qrand() / (qreal)RAND_MAX * 50.0 + 50.0;
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText(QString::asprintf("%5.2f", score));
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                _ui->TW_Data->setItem(row, col, item);
                sum += score;
            }

            item = new QTableWidgetItem();
            iptr count = _record._english._index - _record._math._index + 1;
            item->setText(QString::asprintf("%5.2f", sum / count));
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            _ui->TW_Data->setItem(row, _record._average._index, item);
        }
        _ui->TW_Data->resizeColumnsToContents();
        _ui->TW_Data->resizeRowsToContents();
    }

    void _Analyze_Data() {
        System::Logging(__FUNCTION__);

        _ui->TW_Statistics->setColumnCount(0);
        for(iptr row = 0, rows = _ui->TW_Statistics->topLevelItemCount(); row < rows; row += 1) {
            _ui->TW_Statistics->takeTopLevelItem(0);
        }

        QStringList header = _record._Aliases();
        header[0] = "统计";
        _ui->TW_Statistics->setColumnCount(header.count());
        _ui->TW_Statistics->setHeaderLabels(header);
        for(iptr row = 0; row < _indicator._index; row += 1) {
            QTreeWidgetItem *item = new QTreeWidgetItem();
            item->setText(0, _indicator[row]._alias);
            item->setTextAlignment(0, Qt::AlignLeft | Qt::AlignVCenter);
            _ui->TW_Statistics->addTopLevelItem(item);
        }

        for(iptr col = _record._math._index; col <= _record._average._index; col += 1) {
            iptr upper60 = 0;
            iptr upper70 = 0;
            iptr upper80 = 0;
            iptr upper90 = 0;
            iptr upper100 = 0;
            qreal min_score = 0.0;
            qreal max_score = 0.0;
            qreal sum_score = 0.0;
            QTreeWidgetItem *item = nullptr;

            if(1 <= _ui->TW_Data->rowCount()) {
                min_score = _ui->TW_Data->item(0, col)->text().toDouble();
                max_score = min_score;
                sum_score = min_score;
                for(iptr row = 1, rows = _ui->TW_Data->rowCount(); row < rows; row += 1) {
                    qreal score = _ui->TW_Data->item(row, col)->text().toDouble();
                    if(score < min_score) {
                        min_score = score;
                    } else if(max_score < score) {
                        max_score = score;
                    }
                    sum_score += score;
                    if(score < 60.0) {
                        upper60 += 1;
                    } else if(score < 70.0) {
                        upper70 += 1;
                    } else if(score < 80.0) {
                        upper80 += 1;
                    } else if(score < 90.0) {
                        upper90 += 1;
                    } else if(score <= 100.0) {
                        upper100 += 1;
                    }
                }
            }

            item = _ui->TW_Statistics->topLevelItem(_indicator._upper60._index);
            item->setText(col, QString::asprintf("%td", upper60));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._upper70._index);
            item->setText(col, QString::asprintf("%td", upper70));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._upper80._index);
            item->setText(col, QString::asprintf("%td", upper80));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._upper90._index);
            item->setText(col, QString::asprintf("%td", upper90));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._upper100._index);
            item->setText(col, QString::asprintf("%td", upper100));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._min_score._index);
            item->setText(col, QString::asprintf("%.2lf", min_score));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._max_score._index);
            item->setText(col, QString::asprintf("%.2lf", max_score));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);

            item = _ui->TW_Statistics->topLevelItem(_indicator._avg_score._index);
            item->setText(col, QString::asprintf("%.2lf", sum_score / _ui->TW_Data->rowCount()));
            item->setTextAlignment(col, Qt::AlignHCenter | Qt::AlignVCenter);
        }

        for(iptr col = 0, cols = _ui->TW_Statistics->columnCount(); col < cols; col += 1) {
            _ui->TW_Statistics->resizeColumnToContents(col);
        }
    }

    void _Setup() {
        System::Logging(__FUNCTION__);

        qsrand(QTime::currentTime().second());

        QStringList aliases = _record._Aliases();
        _ui->CB_Subject->addItems(QStringList(aliases.begin() + _record._math._index, aliases.begin() + _record._english._index + 1));
        _ui->CB_Theme->addItems(_theme._Aliases());

        _pen.setWidth(2);
        _pen.setColor(Qt::green);

        _brush.setColor(Qt::yellow);
        _brush.setStyle(Qt::SolidPattern);

        _ui->CV_Bar->setChart(new QChart());
        _ui->CV_Pie->setChart(new QChart());
        _ui->CV_StackedBar->setChart(new QChart());
        _ui->CV_PercentBar->setChart(new QChart());
        _ui->CV_Scatter_Spline->setChart(new QChart());
    }

    void _Setup_Bar(){
        System::Logging(__FUNCTION__);

        QChart *bar = _ui->CV_Bar->chart();
        if(1 <= bar->series().count()) {
            bar->removeAllSeries();
        }
        while(1 <= bar->axes(Qt::Horizontal).count()) {
            bar->removeAxis(bar->axes(Qt::Horizontal).at(0));
        }
        while(1 <= bar->axes(Qt::Vertical).count()) {
            bar->removeAxis(bar->axes(Qt::Vertical).at(0));
        }

        QStringList name = QStringList();
        QBarSet *math = new QBarSet(_record._math._alias);
        QBarSet *chinese = new QBarSet(_record._chinese._alias);
        QBarSet *english = new QBarSet(_record._english._alias);
        QLineSeries *line = new QLineSeries();
        line->setName(_record._average._alias);
        line->setPen(_pen);
        line->setPointsVisible(true);
        line->setPointLabelsFormat("@yPoint");
        for(iptr row = 0; row < _rows / 5; row += 1) {
            name.append(_ui->TW_Data->item(row, _record._name._index)->text());
            math->append(_ui->TW_Data->item(row, _record._math._index)->text().toDouble());
            chinese->append(_ui->TW_Data->item(row, _record._chinese._index)->text().toDouble());
            english->append(_ui->TW_Data->item(row, _record._english._index)->text().toDouble());
            line->append(QPointF(row, _ui->TW_Data->item(row, _record._average._index)->text().toDouble()));
        }

        QBarSeries *series = new QBarSeries();
        series->append(math);
        series->append(chinese);
        series->append(english);
        bar->addSeries(series);
        bar->addSeries(line);
        series->setLabelsVisible(true);
        series->setLabelsPosition(QAbstractBarSeries::LabelsCenter);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        bar->addAxis(axisX, Qt::AlignBottom);
        axisX->append(name);
        axisX->setRange(name.at(0), name.at(name.count() - 1));
        series->attachAxis(axisX);
        line->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        bar->addAxis(axisY, Qt::AlignLeft);
        axisY->setRange(0.0, 100.0);
        axisY->setTickCount(11);
        axisY->setLabelFormat("%.1f");
        axisY->setTitleText("分数");
        axisY->setGridLineVisible(true);
        series->attachAxis(axisY);
        line->attachAxis(axisY);

        bar->setTitle("柱状图");
        bar->legend()->setAlignment(Qt::AlignTop);
        bar->setAnimationOptions(QChart::SeriesAnimations);
    }

    void _Setup_Pie() {
        System::Logging(__FUNCTION__);

        QChart *pie = _ui->CV_Pie->chart();
        if(1 <= pie->series().count()) {
            pie->removeAllSeries();
        }

        QPieSeries *series = new QPieSeries();
        series->setHoleSize(_ui->DSB_Hole->value());
        iptr col = _ui->CB_Subject->currentIndex();
        for(iptr idx = 0; idx <= _indicator._upper100._index; idx += 1) {
            QTreeWidgetItem *item = _ui->TW_Statistics->topLevelItem(idx);
            QPieSlice *slice = new QPieSlice();
            slice->setValue(item->text(col + _record._math._index).toDouble());
            slice->setLabel(item->text(0));
            series->append(slice);
            QObject::connect(slice, &QPieSlice::hovered, this, [slice](bool show) -> void {
                System::Logging("QObject::connect(slice, &QPieSlice::hovered, this, [this, slice](bool show) -> void {");

                slice->setExploded(show);
            });
        }
        for(iptr idx = 0; idx <= _indicator._upper100._index; idx += 1) {
            QPieSlice *slice = series->slices().at(idx);
            slice->setLabel(slice->label() + QString::asprintf(": %.0f人，%.1f%%", slice->value(), slice->percentage() * 100));
        }
        series->setLabelsVisible(true);
        pie->addSeries(series);

        pie->setTitle("饼图 - " + _ui->CB_Subject->currentText());
        pie->setAnimationOptions(QChart::SeriesAnimations);
        pie->legend()->setVisible(true);
        pie->legend()->setAlignment(Qt::AlignRight);


        _ui->DSB_Hole->setValue(series->holeSize());
        _ui->DSB_Size->setValue(series->pieSize());

    }

    void _Setup_StackedBar() {
        System::Logging(__FUNCTION__);

        QChart *stackedbar = _ui->CV_StackedBar->chart();
        if(1 <= stackedbar->series().count()) {
            stackedbar->removeAllSeries();
        }
        while(1 <= stackedbar->axes(Qt::Horizontal).count()) {
            stackedbar->removeAxis(stackedbar->axes(Qt::Horizontal).at(0));
        }
        while(1 <= stackedbar->axes(Qt::Vertical).count()) {
            stackedbar->removeAxis(stackedbar->axes(Qt::Vertical).at(0));
        }

        QStringList name = QStringList();
        QBarSet *math = new QBarSet(_record._math._alias);
        QBarSet *chinese = new QBarSet(_record._chinese._alias);
        QBarSet *english = new QBarSet(_record._english._alias);
        for(iptr row = 0; row < _rows / 5; row += 1) {
            name.append(_ui->TW_Data->item(row, _record._name._index)->text());
            math->append(_ui->TW_Data->item(row, _record._math._index)->text().toDouble());
            chinese->append(_ui->TW_Data->item(row, _record._chinese._index)->text().toDouble());
            english->append(_ui->TW_Data->item(row, _record._english._index)->text().toDouble());
        }

        QStackedBarSeries *series = new QStackedBarSeries();
        series->append(math);
        series->append(chinese);
        series->append(english);
        series->setLabelsVisible(true);
        stackedbar->addSeries(series);

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        stackedbar->addAxis(axisX, Qt::AlignBottom);
        axisX->append(name);
        axisX->setRange(name.at(0), name.at(name.count() - 1));
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        stackedbar->addAxis(axisY, Qt::AlignLeft);
        axisY->setTitleText("总分");
        axisY->setRange(0, 100 * (_record._english._index - _record._math._index + 1));
        axisY->setTickCount(11);
        axisY->setLabelFormat("%.1f");
        series->attachAxis(axisY);

        stackedbar->setTitle("堆叠柱状图");
        stackedbar->setAnimationOptions(QChart::SeriesAnimations);
        stackedbar->legend()->setAlignment(Qt::AlignBottom);
    }

    void _Setup_PercentBar() {
        System::Logging(__FUNCTION__);

        QChart *percentbar = _ui->CV_PercentBar->chart();
        if(1 <= percentbar->series().count()) {
            percentbar->removeAllSeries();
        }
        while(1 <= percentbar->axes(Qt::Horizontal).count()) {
            percentbar->removeAxis(percentbar->axes(Qt::Horizontal).at(0));
        }
        while(1 <= percentbar->axes(Qt::Vertical).count()) {
            percentbar->removeAxis(percentbar->axes(Qt::Vertical).at(0));
        }

        QStringList name = QStringList();
        QBarSet *math = new QBarSet(_record._math._alias);
        QBarSet *chinese = new QBarSet(_record._chinese._alias);
        QBarSet *english = new QBarSet(_record._english._alias);
        for(iptr row = _indicator._upper60._index; row <= _indicator._upper100._index; row += 1) {
            QTreeWidgetItem *item = _ui->TW_Statistics->topLevelItem(row);
            name.append(item->text(0));
            math->append(item->text(_record._math._index).toDouble());
            chinese->append(item->text(_record._chinese._index).toDouble());
            english->append(item->text(_record._english._index).toDouble());
        }

        QPercentBarSeries *series = new QPercentBarSeries();
        series->append(math);
        series->append(chinese);
        series->append(english);
        percentbar->addSeries(series);
        series->setLabelsVisible(true);
        series->setLabelsFormat("@value人");

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        percentbar->addAxis(axisX, Qt::AlignBottom);
        axisX->append(name);
        axisX->setRange(name.at(0), name.at(name.count() - 1));
        series->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        percentbar->addAxis(axisY, Qt::AlignLeft);
        axisY->setRange(0, 100);
        axisY->setTickCount(6);
        axisY->setLabelFormat("%.1f");
        axisY->setTitleText("百分比");
        series->attachAxis(axisY);

        percentbar->setTitle("百分比柱状图");
        percentbar->legend()->setAlignment(Qt::AlignTop);
        percentbar->setAnimationOptions(QChart::SeriesAnimations);
    }

    void _Setup_Scatter_Spline() {
        System::Logging(__FUNCTION__);

        QChart *scatter_spline = _ui->CV_Scatter_Spline->chart();
        if(1 <= scatter_spline->series().count()) {
            scatter_spline->removeAllSeries();
        }
        while(1 <= scatter_spline->axes(Qt::Horizontal).count()) {
            scatter_spline->removeAxis(scatter_spline->axes(Qt::Horizontal).at(0));
        }
        while(1 <= scatter_spline->axes(Qt::Vertical).count()) {
            scatter_spline->removeAxis(scatter_spline->axes(Qt::Vertical).at(0));
        }

        QScatterSeries *scatter = new QScatterSeries();
        scatter_spline->addSeries(scatter);
        scatter->setName("散点");
        scatter->setBorderColor(Qt::black);
        scatter->setBrush(_brush);
        scatter->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        scatter->setMarkerSize(12);

        QSplineSeries *spline = new QSplineSeries();
        scatter_spline->addSeries(spline);
        spline->setName("样条");
        spline->setPen(_pen);

        for(iptr i = 0; i < _numb; i += 1) {
            iptr x = qrand() / (qreal)RAND_MAX * _width;
            iptr y = qrand() / (qreal)RAND_MAX * _height;
            scatter->append(x, y);
            spline->append(x, y);
        }

        QValueAxis *axisX = new QValueAxis();
        scatter_spline->addAxis(axisX, Qt::AlignBottom);
        axisX->setRange(-0.2 * _width, +1.2 * _width);
        axisX->setTickCount((iptr)_width / 10 + 5);
        axisX->setLabelFormat("%.1f");
        axisX->setTitleText("X");
        scatter->attachAxis(axisX);
        spline->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        scatter_spline->addAxis(axisY, Qt::AlignLeft);
        axisY->setRange(-0.2 * _width, +1.2 * _width);
        axisY->setTickCount((iptr)_height / 10 + 5);
        axisY->setLabelFormat("%.1f");
        axisY->setTitleText("Y");
        scatter->attachAxis(axisY);
        spline->attachAxis(axisY);

        scatter_spline->setTitle("散点图 - 样条图");
        scatter_spline->legend()->setAlignment(Qt::AlignTop);
        // scatter_spline->setAnimationOptions(QChart::SeriesAnimations);

        const QList<QLegendMarker*> &markers = scatter_spline->legend()->markers();
        for(auto iter = markers.begin(), end = markers.end(); iter != end; iter += 1) {
            // QObject::disconnect(*iter, &QLegendMarker::clicked, this, &ChartView::_QLegendMarker_clicked);
            // QObject::connect(*iter, &QLegendMarker::clicked, this, &ChartView::_QLegendMarker_clicked);
            QObject::connect(*iter, &QLegendMarker::clicked, this, [iter]() -> void {   // note: lambda is unique at the line.
                System::Logging("QObject::connect(*iter, &QLegendMarker::clicked, this, [iter]() -> void {");

                QLegendMarker *marker = (*iter);
                auto type = marker->type();
                if(type == QLegendMarker::LegendMarkerTypeXY) {
                    marker->series()->setVisible(!marker->series()->isVisible());
                    marker->setVisible(true);
                }
            });
        }
    }
};

#endif // ChartView_h
