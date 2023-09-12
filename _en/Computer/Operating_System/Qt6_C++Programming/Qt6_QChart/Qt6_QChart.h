#ifndef QT6_QCHART_H
#define QT6_QCHART_H

#include <QMainWindow>
#include "ui_Qt6_QChart.h"
#include <QtCharts>
#include <QRandomGenerator64>
#include "QChartView_Handler.h"

class Qt6_QChart : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_QChart *_ui = nullptr;
    QLabel *L_Chart   = nullptr;
    QLabel *L_Hover   = nullptr;
    QLabel *L_Clicked = nullptr;

public:
    Qt6_QChart(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_QChart) {
        _ui->setupUi(this);

        L_Chart = new QLabel();
        L_Chart->setMinimumWidth(150);
        _ui->SB_Status->addWidget(L_Chart);
        L_Hover = new QLabel();
        L_Hover->setMinimumWidth(150);
        _ui->SB_Status->addWidget(L_Hover);
        L_Clicked = new QLabel();
        L_Clicked->setMinimumWidth(150);
        _ui->SB_Status->addWidget(L_Clicked);

        _Setup();
    }

    ~Qt6_QChart() {
        delete _ui;
    }

public:
    void _Setup() {
        _ui->CV_ChartView->setCursor(Qt::CrossCursor);

        QLineSeries *series0 = new QLineSeries();
        _ui->CV_ChartView->chart()->addSeries(series0);
        series0->setName("折线");
        series0->setPointsVisible(true);
        series0->setMarkerSize(4);
        series0->setSelectedColor(Qt::blue);
        QPen pen0;
        pen0.setColor(Qt::black);
        pen0.setStyle(Qt::DotLine);
        pen0.setWidth(2);
        series0->setPen(pen0);

        QSplineSeries *series1 = new QSplineSeries();
        _ui->CV_ChartView->chart()->addSeries(series1);
        series1->setName("曲线");
        series1->setPointsVisible(true);
        series1->setMarkerSize(4);
        series1->setSelectedColor(Qt::blue);
        QPen pen1;
        pen1.setColor(Qt::black);
        pen1.setStyle(Qt::SolidLine);
        pen1.setWidth(2);
        series1->setPen(pen1);

        double t = 0;
        double step = 1.0 * (10 - 0) / (21 - 1);
        for(int i = 0; i < 21; i += 1) {
            double err0 = QRandomGenerator::global()->bounded(-5, 5) / 50.0;
            double y0 = qSin(t) + err0;
            series0->append(t, y0);

            double err1 = QRandomGenerator::global()->bounded(-5, 5) / 50.0;
            double y1 = qCos(t) + err1;
            series1->append(t, y1);
            t += step;
        }

        QValueAxis *axis_x = new QValueAxis();
        _ui->CV_ChartView->chart()->addAxis(axis_x, Qt::AlignBottom);
        series0->attachAxis(axis_x);
        series1->attachAxis(axis_x);
        axis_x->setRange(0, 10);
        axis_x->setLabelFormat("%.1f");
        axis_x->setTickCount(11);
        axis_x->setMinorTickCount(2);
        axis_x->setTitleText("time/secs");

        QValueAxis *axis_y = new QValueAxis();
        _ui->CV_ChartView->chart()->addAxis(axis_y, Qt::AlignLeft);
        series0->attachAxis(axis_y);
        series1->attachAxis(axis_y);
        axis_y->setRange(-2, +2);
        axis_y->setLabelFormat("%.2f");
        axis_y->setTickCount(5);
        axis_y->setMinorTickCount(2);
        axis_y->setTitleText("value/1");

        QObject::connect(series0, &QLineSeries::clicked, this, &Qt6_QChart::_Do_Series_Clicked);
        QObject::connect(series1, &QSplineSeries::clicked, this, &Qt6_QChart::_Do_Series_Clicked);
        QObject::connect(series0, &QLineSeries::hovered, this, &Qt6_QChart::_Do_Series_Hovered);
        QObject::connect(series1, &QSplineSeries::hovered, this, &Qt6_QChart::_Do_Series_Hovered);

        auto markers = _ui->CV_ChartView->chart()->legend()->markers();
        for(int i = 0 ; i < markers.size(); i += 1) {
            QObject::connect(markers.at(i), &QLegendMarker::clicked, this, [this]() -> void {
                QLegendMarker *marker = static_cast<QLegendMarker *>(sender());
                marker->series()->setVisible(!marker->series()->isVisible());
                marker->setVisible(true);

                double alpha = 1.0;
                if(marker->series()->isVisible() == false) {
                    alpha = 0.5;
                }

                QBrush brush = marker->labelBrush();
                QColor color = brush.color();
                color.setAlphaF(alpha);
                brush.setColor(color);
                marker->setLabelBrush(brush);

                brush = marker->brush();
                color = brush.color();
                color.setAlphaF(alpha);
                brush.setColor(color);
                marker->setBrush(brush);
            });
        }

        QObject::connect(_ui->CV_ChartView, &QChartView_Handler::_Mouse_Move, this, [this](QPoint point) -> void {
            QPointF value = _ui->CV_ChartView->chart()->mapToValue(point);
            QString str = QString::asprintf("Value[%.1f, %.2f]", value.x(), value.y());
            L_Chart->setText(str);
        });

        QObject::connect(_ui->A_Zoom_In, &QAction::triggered, this, [this]() -> void {
            _ui->CV_ChartView->chart()->zoom(1.0 * 1.1);
        });

        QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, this, [this]() -> void {
            _ui->CV_ChartView->chart()->zoom(1.0 / 1.1);
        });

        QObject::connect(_ui->A_Reset, &QAction::triggered, this, [this]() -> void {
            _ui->CV_ChartView->chart()->zoomReset();
        });

        QObject::connect(_ui->CB_Drag_Mode, &QComboBox::currentIndexChanged, this, [this](int index) -> void {
            switch(index) {
            case 0:
                _ui->CV_ChartView->setDragMode(QGraphicsView::NoDrag);
                break;
            case 1:
                _ui->CV_ChartView->setDragMode(QGraphicsView::ScrollHandDrag);
                break;
            case 2:
                _ui->CV_ChartView->setDragMode(QGraphicsView::RubberBandDrag);
                break;
            }
        });

        QObject::connect(_ui->CB_Rubber_Band, &QComboBox::currentIndexChanged, this, [this](int index) -> void {
            QChartView::RubberBands flags = QChartView::ClickThroughRubberBand;
            switch (index) {
            case 0:
                flags |= QChartView::NoRubberBand;
                break;
            case 1:
                flags |= QChartView::VerticalRubberBand;
                break;
            case 2:
                flags |= QChartView::HorizontalRubberBand;
                break;
            case 3:
                flags |= QChartView::RectangleRubberBand;
            }

            _ui->CV_ChartView->setRubberBand(flags);
        });
    }

    int _Get_Index_By_X(QXYSeries *series, double x, double err = 0.05) {
        auto points = series->points();
        int index = -1;
        for(int i = 0; i < points.size(); i += 1) {
            double dx = x - points.at(i).x();
            if(qAbs(dx) <= err) {
                index = i;
                break;
            }
        }
        return index;
    }

public slots:
    void _Do_Series_Clicked(const QPointF &point) {
        QString str = QString::asprintf("Clicked[%.1f, %.2f]", point.x(), point.y());
        L_Clicked->setText(str);

        QLineSeries *series = static_cast<QLineSeries *>(sender());
        int index = _Get_Index_By_X(series, point.x());
        if(index < 0) {
            return;
        }
        series->setPointSelected(index, !series->isPointSelected(index));
    }

    void _Do_Series_Hovered(const QPointF &point, bool state) {
        QLineSeries *series = static_cast<QLineSeries *>(sender());
        if(state == true) {
            QString str = QString::asprintf("Hovered[%.1f, %.2f]", point.x(), point.y());
            L_Hover->setText(str);
            QPen pen;
            pen.setColor(Qt::red);
            series->setPen(pen);
        } else {
            QPen pen;
            pen.setColor(Qt::black);
            series->setPen(pen);
        }
    }
};
#endif // QT6_QCHART_H
