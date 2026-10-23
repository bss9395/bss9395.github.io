#pragma once

#include <QTabWidget>
#include <QTreeWidget>
#include <QtCharts>

class MainWidget: public QWidget {
    Q_OBJECT

    QTabWidget* _tabWidget = nullptr;
    QWidget* _tab0 = nullptr;
    QWidget* _tab1 = nullptr;
    QTreeWidget* _treeWidget0 = nullptr;
    QTreeWidget* _treeWidget1 = nullptr;
    QStandardItemModel* _model = nullptr;
    QComboBox* _comboBox = nullptr;
    QChartView*  _chartView  = nullptr;
    QChart* _chart = nullptr;

public:
    MainWidget(QWidget* parent = nullptr)
        : QWidget(parent) {
        this->resize(600, 600);
        QVBoxLayout* layout0 = new QVBoxLayout(this);
        layout0->setContentsMargins(0, 0, 0, 0);

        _tabWidget = new QTabWidget(this);
        layout0->addWidget(_tabWidget);

        _tab0 = new QWidget(_tabWidget);
        _tabWidget->addTab(_tab0, QString("tab0"));

        _tab1 = new QWidget(_tabWidget);
        _tabWidget->addTab(_tab1, QString("tab1"));

        QVBoxLayout* layout1 = new QVBoxLayout(_tab0);
        layout1->setContentsMargins(0, 0, 0, 0);
        _treeWidget0 = new QTreeWidget(_tab0);
        layout1->addWidget(_treeWidget0);
        _treeWidget1 = new QTreeWidget(_tab0);
        layout1->addWidget(_treeWidget1);

        _GenerateModel();
        _StatisticsModel();

        QVBoxLayout* layout2 = new QVBoxLayout(_tab1);
        layout2->setContentsMargins(0, 0, 0, 0);
        _comboBox = new QComboBox(_tab1);
        _comboBox->addItems(QStringList() << "数学" << "语文" << "英语");
        QObject::connect(_comboBox, &QComboBox::currentTextChanged, this, &MainWidget::_DrawPie);

        layout2->addWidget(_comboBox);
        _chartView = new QChartView(_tab1);
        layout2->addWidget(_chartView);

        _chart = _chartView->chart();
        _chart->setAnimationOptions(QChart::SeriesAnimations);
        _chartView->setChart(_chart);
        _chartView->setRenderHint(QPainter::Antialiasing);

        _tabWidget->setCurrentIndex(1);
        _DrawPie();
    }

public:
    void _GenerateModel() {
        _model = new QStandardItemModel(this);
        QStringList header;
        header << "姓名" << "数学" << "语文" << "英语" << "平均分";
        _model->setHorizontalHeaderLabels(header);

        int count = 15;
        QStandardItem* item = nullptr;
        for(int row = 0; row < count; row += 1) {
            QList<QStandardItem*> list;
            item = new QStandardItem();
            item->setData(QString("学生%1").arg(row));
            // item->setText(QString("测试"));
            list << item;

            qreal average = 0.0;
            for(int column = 1; column < header.count() - 1; column += 1) {
                qreal score = 40.0 + QRandomGenerator::global()->bounded(0, 50);
                average += score;
                item = new QStandardItem();
                item->setData(QString::asprintf("%.0f", score));
                list << item;
            }

            item = new QStandardItem();
            item->setData(QString::asprintf("%.0f", average / 3));
            list << item;

            _model->appendRow(list);
        }

        _treeWidget0->setHeaderLabels(header);
        for(int row = 0; row < _model->rowCount();  row += 1) {
            QTreeWidgetItem* item = new QTreeWidgetItem();
            for(int column = 0; column < _model->columnCount(); column += 1) {
                item->setText(column, _model->item(row, column)->data().toString());
            }
            _treeWidget0->addTopLevelItem(item);
        }
    }

    void _StatisticsModel() {
        QStringList header;
        header << "分数段" << "数学" << "语文" << "英语";
        _treeWidget1->setHeaderLabels(header);

        QStringList vertical;
        vertical << "60分以下" << "60分~70分" << "70分~80分" << "80分~90分" << "90分以上";
        for(int row = 0; row < vertical.count(); row += 1) {
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0, vertical[row]);
            _treeWidget1->addTopLevelItem(item);
        }

        for(int column = 1; column < header.count(); column += 1) {
            int count50 = 0;
            int count60 = 0;
            int count70 = 0;
            int count80 = 0;
            int count90 = 0;
            for(int row = 0; row < _model->rowCount(); row += 1) {
                qreal value = _model->item(row, column)->data().toDouble();
                if(value < 60) {
                    count50 += 1;
                } else if(60 <= value && value < 70) {
                    count60 += 1;
                } else if(70 <= value && value < 80) {
                    count70 += 1;
                } else if(80 <= value && value < 90) {
                    count80 += 1;
                } else if(90 <= value && value <= 100) {
                    count90 += 1;
                }
            }
            QTreeWidgetItem* item0 = _treeWidget1->topLevelItem(0);  // 60分以下
            item0->setText(column, QString::asprintf("%d", count50));
            QTreeWidgetItem* item1 = _treeWidget1->topLevelItem(1);  // 60分~70分
            item1->setText(column, QString::asprintf("%d", count60));
            QTreeWidgetItem* item2 = _treeWidget1->topLevelItem(2);  // 70分~80分
            item2->setText(column, QString::asprintf("%d", count70));
            QTreeWidgetItem* item3 = _treeWidget1->topLevelItem(3);  // 80分~90分
            item3->setText(column, QString::asprintf("%d", count80));
            QTreeWidgetItem* item4 = _treeWidget1->topLevelItem(4);  // 90分以上
            item4->setText(column, QString::asprintf("%d", count90));
        }
    }

    void _DrawPie() {
        _chart->removeAllSeries();                 // 删除所有序列

        // 添加分块数据
        QPieSeries* pieSeries = new QPieSeries();
        pieSeries->setHoleSize(0.03);              // 设置饼图中心空心的大小
        int column = _comboBox->currentIndex() + 1;
        for(int level = 0; level < 5; level += 1) {
            QTreeWidgetItem* item = _treeWidget1->topLevelItem(level);
            pieSeries->append(item->text(0), item->text(column).toDouble());
        }

        QPieSlice* pieSlice = nullptr;
        for(int level = 0; level < 5; level += 1) {
            pieSlice = pieSeries->slices().at(level);
            pieSlice->setLabel(pieSlice->label() + QString::asprintf(": %.0f人，%.1f%%", pieSlice->value(), pieSlice->percentage() * 100));
        }

        pieSeries->setLabelsVisible(true);
        _chart->addSeries(pieSeries);
        _chart->setAcceptHoverEvents(true);
        _chart->setTitle(_comboBox->currentText());
        _chart->legend()->setAlignment(Qt::AlignRight);
    }
};
