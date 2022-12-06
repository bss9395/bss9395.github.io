/* Canvas.h
Author: BSS9395
Update: 2022-12-06T22:22:00+08@China-Shanghai+08
Design: Transform
Encode: UTF-8
System: Qt 5.15.2
*/

#ifndef Canvas_h
#define Canvas_h

#define Header_h
#include "Common.h"
#include "System.h"

class Scroll_Area : public QScrollArea {
    Q_OBJECT

public:
    explicit Scroll_Area(QWidget *parent = nullptr)
        : QScrollArea(parent) {
        System::Logging(__FUNCTION__);

    }

    virtual ~Scroll_Area() {
        System::Logging(__FUNCTION__);
    }

public:
    virtual void wheelEvent(QWheelEvent *event) override {
        System::Logging(__FUNCTION__);

        //QScrollArea::wheelEvent(event);
    }
};

////////////////////////////////////////////////////////////////////////////////

class Item : public QObject {
    Q_OBJECT

public:
    QPixmap _pixmap = QPixmap();
    QTransform _transform_translate = QTransform();
    QTransform _transform_scale = QTransform();
    QTransform _transform_rotate_from = QTransform();
    QTransform _transform_rotate_to = QTransform();
    QTransform _transform = QTransform();
    double _scale = 1.0;
    double _scale_step = 0.1;
    QPolygon _region = QPolygon();
    QRect _bounding = QRect();
    QPointF _center = QPoint();

public:
    explicit Item(const QPixmap &pixmap, const QPoint &center) {
        System::Logging(__FUNCTION__);

        _pixmap = pixmap;

        QPoint origin = center - _pixmap.rect().center();
        _transform_translate.translate(origin.x(), origin.y());

        _transform = _transform_rotate_to * _transform_scale * _transform_translate;
        _region = _transform.mapToPolygon(_pixmap.rect());
        _bounding = _transform.mapRect(_pixmap.rect());
    }

    virtual ~Item() {
        System::Logging(__FUNCTION__);
    }

public:
    void _Paint(QPainter &painter) {
        System::Logging(__FUNCTION__);
        painter.save();
        painter.setTransform(_transform);
        painter.drawPixmap(0, 0, _pixmap);
        painter.drawRect(_pixmap.rect());
        painter.restore();
    }

    void _Translate(QPointF translate) {
        System::Logging(__FUNCTION__);

        _transform_translate.translate(translate.x(), translate.y());

        _transform = _transform_rotate_to * _transform_scale * _transform_translate;
        _region = _transform.mapToPolygon(_pixmap.rect());
        _bounding = _transform.mapRect(_pixmap.rect());
    }

    void _Scale(QPointF center, int angle) {
        System::Logging(__FUNCTION__);

        double step = 0.0;
        if(0 < angle) {
            step = +_scale_step;
        } else if(angle < 0) {
            step = -_scale_step;
        }

        center = (_transform_scale * _transform_translate).inverted().map(center);
        _scale += step;
        _transform_scale = QTransform().scale(_scale, _scale);
        QPointF shift = center * step;
        _transform_translate.translate(-shift.x(), -shift.y());

        _transform = _transform_rotate_to * _transform_scale * _transform_translate;
        _region = _transform.mapToPolygon(_pixmap.rect());
        _bounding = _transform.mapRect(_pixmap.rect());
    }

    void _Rotate(QPointF center, double degree) {
        System::Logging(__FUNCTION__);

        if(_center != center) {
            _center = center;
            _transform_rotate_from = _transform_rotate_to;
        }

        center = _transform.inverted().map(center);
        _transform_rotate_to = _transform_rotate_from;
        _transform_rotate_to.translate(+center.x(), +center.y());
        _transform_rotate_to.rotate(degree);
        _transform_rotate_to.translate(-center.x(), -center.y());

        _transform = _transform_rotate_to * _transform_scale * _transform_translate;
        _region = _transform.mapToPolygon(_pixmap.rect());
        _bounding = _transform.mapRect(_pixmap.rect());
    }
};

////////////////////////////////////////////////////////////////////////////////

class Canvas : public QWidget {
    Q_OBJECT

public:
    QPen _pen = QPen();
    QBrush _brush = QBrush();
    QList<Item *> _items = QList<Item *>();
    Item *_selected = nullptr;
    QPoint _pressed_ = QPoint();
    QPoint *_pressed = nullptr;
    QPoint _center_ = QPoint();
    QPoint *_center = nullptr;


public:
    explicit Canvas(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        : QWidget(parent, flags) {
        System::Logging(__FUNCTION__);

        _pen.setWidth(1);
        _pen.setColor(Qt::black);
        _pen.setStyle(Qt::SolidLine);
        _brush.setColor(Qt::green);
        _brush.setStyle(Qt::SolidPattern);

        this->setAcceptDrops(true);
    }

    virtual ~Canvas() {
        System::Logging(__FUNCTION__);
    }

public:
    virtual void dragEnterEvent(QDragEnterEvent *event) override {
        System::Logging(__FUNCTION__);

        event->acceptProposedAction();
        QWidget::dragEnterEvent(event);
    }

    virtual void dropEvent(QDropEvent *event) override {
        System::Logging(__FUNCTION__);

        QList<QUrl> urls = event->mimeData()->urls();
        if(urls.isEmpty() == true || urls[0].isLocalFile() == false) {
            return;
        }

        QPixmap pixmap = QPixmap(urls[0].toLocalFile());
        if(pixmap.isNull() == true) {
            return;
        }

        Item *item = new Item(pixmap, event->pos());
        _items.append(item);

        update();
        QWidget::dropEvent(event);
    }

    virtual void paintEvent(QPaintEvent *event) override {
        System::Logging(__FUNCTION__);

        QPainter painter = QPainter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::TextAntialiasing, true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

        for(auto beg = _items.begin(), end = _items.end(); beg != end; beg += 1) {
            (*beg)->_Paint(painter);
            if(_selected == (*beg)) {
                painter.drawRect((*beg)->_bounding);
                emit _Bounding((*beg)->_bounding);
            }
        }

        if(_center != nullptr) {
            painter.setBrush(_brush);
            painter.drawEllipse(*_center, 2, 2);
        }
        return QWidget::paintEvent(event);
    }

    virtual void mousePressEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        this->setMouseTracking(true);
        if(event->button() == Qt::LeftButton) {
            _pressed = &(_pressed_ = event->pos());
            _selected = nullptr;
            for(auto beg = _items.begin(), end = _items.end(); beg != end; beg += 1) {
                if(_pressed != nullptr && (*beg)->_region.containsPoint(*_pressed, Qt::WindingFill) == true) {
                    _selected = (*beg);
                }
            }
            update();
        } else if(event->button() == Qt::RightButton) {
            _center = &(_center_ = event->pos());
            emit _Center(*_center);
            update();
        }
        return QWidget::mousePressEvent(event);
    }

    virtual void mouseMoveEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        if(_selected != nullptr && _pressed != nullptr) {
            QPoint shift = event->pos() - (*_pressed);
            _selected->_Translate(shift);
            _pressed = &(_pressed_ = event->pos());
            update();
        }
        return QWidget::mouseMoveEvent(event);
    }

    virtual void mouseReleaseEvent(QMouseEvent *event) {
        System::Logging(__FUNCTION__);

        this->setMouseTracking(false);
        _pressed = nullptr;
        return QWidget::mouseReleaseEvent(event);
    }

    virtual void wheelEvent(QWheelEvent *event) override {
        System::Logging(__FUNCTION__);

        if(_selected != nullptr && _center != nullptr && _selected->_region.containsPoint(*_center, Qt::WindingFill) == true){
            _selected->_Scale(*_center, event->angleDelta().y());
            update();
        }
        return QWidget::wheelEvent(event);
    }

public:
    void _Rotate(double degree) {
        System::Logging(__FUNCTION__);

        if(_selected != nullptr && _center != nullptr) {
            _selected->_Rotate(*_center, degree);
            update();
        }
    }

signals:
    void _Bounding(QRect bounding);
    void _Center(QPoint center);
};

#endif // Canvas_h
