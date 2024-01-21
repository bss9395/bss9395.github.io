#ifndef QT6_QLINESERIES_H
#define QT6_QLINESERIES_H

#include <QMainWindow>
#include "ui_Qt6_QLineSeries.h"
#include <QtCharts>

class Qt6_QChart : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QChart *_ui = nullptr;
    QChartView *_view = nullptr;

public:
    Qt6_QChart(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QChart) {
        _ui->setupUi(this);

        _view = new QChartView(this);
        QChart *chart = _view->chart();
        _ui->widget->layout()->addWidget(_view);
        chart->setTitle("简单函数曲线");

        QLineSeries *series_sin = new QLineSeries();
        chart->addSeries(series_sin);
        series_sin->setName("sin曲线");
        QLineSeries *series_cos = new QLineSeries();
        chart->addSeries(series_cos);
        series_cos->setName("cos曲线");

        double step = 0.1;
        double t = 0.0;
        for(int i = 0; i < 100; i += 1) {
            double y_sin = qSin(t);
            series_sin->append(t, y_sin);
            double y_cos = qCos(t);
            series_cos->append(t, y_cos);
            t += step;
        }
        QPen pen;
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(2);
        pen.setColor(Qt::red);
        series_sin->setPen(pen);
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(2);
        pen.setColor(Qt::green);
        series_cos->setPen(pen);


        QValueAxis *axis_x = new QValueAxis();
        chart->addAxis(axis_x, Qt::AlignBottom);  // note: chart->addAxis, then attachAxis.
        series_sin->attachAxis(axis_x);
        series_cos->attachAxis(axis_x);
        axis_x->setTitleText("时间(秒)");
        axis_x->setRange(0, 10);
        axis_x->setLabelFormat("%.1f");
        axis_x->setTickCount(11);
        axis_x->setMinorTickCount(4);

        QValueAxis *axis_y = new QValueAxis();
        chart->addAxis(axis_y, Qt::AlignLeft);  // note: chart->addAxis, then attachAxis.
        series_sin->attachAxis(axis_y);
        series_cos->attachAxis(axis_y);
        axis_y->setTitleText("数值");
        axis_y->setRange(-2, 2);
        axis_y->setTickCount(5);
        axis_y->setMinorTickCount(4);
        axis_y->setLabelFormat("%.2f");
    }

    ~Qt6_QChart() {
        delete _ui;
    }


};
#endif // QT6_QLINESERIES_H
