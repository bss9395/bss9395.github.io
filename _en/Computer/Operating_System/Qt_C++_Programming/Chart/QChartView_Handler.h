/* QChartView_Handler.h
Author: BSS9395
Update: 2022-07-05T22:56:00+08@China-Shanghai+08
Design: Chart
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef QChartView_Handler_h
#define QChartView_Handler_h

#define   Header_h
#include "Common.h"
#include "System.h"

class QChartView_Handler : public QChartView {
    Q_OBJECT

public:
    static inline double _zoom_ratio = 0.1;
    static inline double _scroll_step = 10.0;
    static inline double _page_step = 50.0;

public:
    QPoint _start = QPoint();
    QPoint _cease = QPoint();

public:
    explicit QChartView_Handler(QWidget *parent = nullptr)
        : QChartView(parent) {
        System::Logging(__FUNCTION__);

        this->setMouseTracking(true);
        this->setDragMode(QGraphicsView::RubberBandDrag);
        this->setRubberBand(QChartView::RectangleRubberBand);
    }

    virtual ~QChartView_Handler() {
        System::Logging(__FUNCTION__);
    }

public:
    virtual void mousePressEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        if(event->button() == Qt::LeftButton) {
            _start = event->pos();
        }
        QChartView::mouseMoveEvent(event);
    }

    virtual void mouseMoveEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        emit _Mouse_Pos(event->pos());
        QChartView::mouseMoveEvent(event);
    }

    virtual void mouseReleaseEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        if(event->button() == Qt::LeftButton) {
            _cease = event->pos();
            this->chart()->zoomIn(QRectF(_start, _cease));
        } else if(event->button() == Qt::RightButton) {
            this->chart()->zoomReset();
        }
        QChartView::mouseReleaseEvent(event);
    }

    virtual void keyPressEvent(QKeyEvent *event) override {
        System::Logging(__FUNCTION__);

        int key = event->key();
        if(key == Qt::Key_Plus) {            // note: shift+
            this->chart()->zoom(1 + _zoom_ratio);
        } else if(key == Qt::Key_Minus) {    // note: -
            this->chart()->zoom(1 - _zoom_ratio);
        } else if(key == Qt::Key_Left) {
            this->chart()->scroll(+_scroll_step, 0);
        } else if(key == Qt::Key_Right) {
            this->chart()->scroll(-_scroll_step, 0);
        } else if(key == Qt::Key_Up) {
            this->chart()->scroll(0, -_scroll_step);
        } else if(key == Qt::Key_Down) {
            this->chart()->scroll(0, +_scroll_step);
        } else if(key == Qt::Key_PageUp) {
            this->chart()->scroll(0, +_page_step);
        } else if(key == Qt::Key_PageDown) {
            this->chart()->scroll(0, -_page_step);
        } else if(key == Qt::Key_Home) {
            this->chart()->zoomReset();
        }
        QChartView::keyPressEvent(event);
    }

signals:
    void _Mouse_Pos(QPoint pos);
};

#endif // QChartView_Handler_h
