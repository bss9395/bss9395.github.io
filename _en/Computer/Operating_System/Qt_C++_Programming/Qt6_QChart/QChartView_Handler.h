#ifndef QCHARTVIEW_HANDLER_H
#define QCHARTVIEW_HANDLER_H

#include <QChartView>

class QChartView_Handler : public QChartView {
    Q_OBJECT

public:
    QPoint _point_beg;
    QPoint _point_end;
    bool   _zoom_custom = false;

public:
    QChartView_Handler(QWidget *parent = nullptr)
        : QChartView(parent) {
        this->setMouseTracking(true);
        this->setDragMode(QGraphicsView::NoDrag);
        this->setRubberBand(QChartView::NoRubberBand);
        auto flags = this->rubberBand();
        flags |= QChartView::ClickThroughRubberBand;
        this->setRubberBand(flags);
    }

    ~QChartView_Handler() {

    }

public:
    void mousePressEvent(QMouseEvent *event) override {
        if(event->button() == Qt::LeftButton) {
            _point_beg = event->pos();
        }
        QChartView::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        QPoint point = event->pos();
        emit _Mouse_Move(point);
        QChartView::mouseMoveEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        if(event->button() == Qt::LeftButton) {
            _point_end = event->pos();
            if(this->dragMode() == QGraphicsView::ScrollHandDrag) {
                if(this->rubberBand() == (QChartView::NoRubberBand | QChartView::ClickThroughRubberBand)) {
                    this->chart()->scroll(_point_beg.x() - _point_end.x(), _point_end.y() - _point_beg.y());
                }
            }
        }
        return QChartView::mouseReleaseEvent(event);
    }

    void keyPressEvent(QKeyEvent *event) override {
        switch(event->key()) {
        case Qt::Key_Left:
            this->chart()->scroll(+10, 0);
            break;
        case Qt::Key_Right:
            this->chart()->scroll(-10, 0);
            break;
        case Qt::Key_Up:
            this->chart()->scroll(0, -10);
            break;
        case Qt::Key_Down:
            this->chart()->scroll(0, +10);
            break;
        case Qt::Key_Escape:
            chart()->zoomReset();
            break;
        }
        return QChartView::keyPressEvent(event);
    }

    void wheelEvent(QWheelEvent *event) override {
        QPoint step = event->angleDelta() / 8 / 15;
        if(0 < step.y()) {
            chart()->zoom(+step.y() * 1.1);
        } else {
            chart()->zoom(-step.y() / 1.1);
        }
        QChartView::wheelEvent(event);
    }
signals:
    void _Mouse_Move(QPoint point);
};

#endif // QCHARTVIEW_HANDLER_H
