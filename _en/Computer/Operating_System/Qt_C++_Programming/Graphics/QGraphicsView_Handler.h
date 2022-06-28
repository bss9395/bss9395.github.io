/* QGraphicsView_Handler.h
Author: BSS9395
Update: 2022-06-28T23:53:00+08@China-Shanghai+08
Design: Graphics
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef QGraphicsView_Handler_h
#define QGraphicsView_Handler_h

#define  Header_h
#include "Common.h"
#include "System.h"


class QGraphicsView_Handler : public QGraphicsView {
    Q_OBJECT

public:
    QGraphicsScene _scene = QGraphicsScene();
    QFont _font = QFont();
    QPen _pen = QPen();
    QBrush _brush = QBrush();

    struct {
        iptr _z_out = 0;
        iptr _z_in = 0;
        iptr _id = 0;
        iptr _item_id = 0;
        iptr _item_desc = 1;
    } _type;
    double _scale_step = 0.05;
    double _rotate_step = 5.0;

public:
    explicit QGraphicsView_Handler(QWidget *parent = nullptr)
        : QGraphicsView(parent) {
        System::Logging(__FUNCTION__);
    }

    virtual ~QGraphicsView_Handler() {
        System::Logging(__FUNCTION__);
    }

public:
    void _Attach_Rectangle() {
        System::Logging(__FUNCTION__);

        QGraphicsRectItem *item = new QGraphicsRectItem(-50, -25, 100, 50);
        item->setPen(_pen);
        item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "矩形");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Attach_Circle() {
        System::Logging(__FUNCTION__);

        QGraphicsEllipseItem *item = new QGraphicsEllipseItem(-50, -50, 100, 100);
        item->setPen(_pen);
        item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "圆形");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Attach_Triangle() {
        System::Logging(__FUNCTION__);

        QPolygonF points = QPolygonF();
        points.append(QPointF(0, -40));
        points.append(QPointF(60, 40));
        points.append(QPointF(-60, 40));

        QGraphicsPolygonItem *item = new QGraphicsPolygonItem(points);
        item->setPen(_pen);
        item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "三角");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Attach_Line() {
        System::Logging(__FUNCTION__);

        QGraphicsLineItem *item = new QGraphicsLineItem(-100, 0, 100, 0);
        item->setPen(_pen);
        // item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "直线");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Attach_Text() {
        System::Logging(__FUNCTION__);

        QString title = " ";
        QString label = "请输入文字: ";
        QString text = QInputDialog::getText(this, title, label);
        if((0 < text.size()) == false) {
            return;
        }

        QGraphicsTextItem *item = new QGraphicsTextItem(text);
        item->setFont(_font);
        // item->setPen(_pen);
        // item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "文字");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Attach_Trapezoid() {
        System::Logging(__FUNCTION__);

        QPolygonF points = QPolygonF();
        points.append(QPointF(-40, -40));
        points.append(QPointF(+40, -40));
        points.append(QPointF(+100, +40));
        points.append(QPointF(-100, +40));

        QGraphicsPolygonItem *item = new QGraphicsPolygonItem(points);
        item->setPen(_pen);
        item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "梯形");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Attach_Ellipse() {
        System::Logging(__FUNCTION__);

        QGraphicsEllipseItem *item = new QGraphicsEllipseItem(-50, -30, 100, 60);
        item->setPen(_pen);
        item->setBrush(_brush);
        item->setPos(qrand() % 100 - 50, qrand() % 100 - 50);
        item->setZValue(_type._z_out);                                            _type._z_out += 1;
        item->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        item->setData(_type._item_desc, "椭圆");
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(item);
        _scene.clearSelection();
        item->setSelected(true);
    }

    void _Zoom_In() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            this->scale(1 + _scale_step, 1 + _scale_step);  // note: scale by ratio.
            return ;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(i);
            item->setScale(item->scale() + _scale_step);    // note: scale by step.
        }
    }

    void _Zoom_Out() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            this->scale(1 - _scale_step, 1 - _scale_step);
            return;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(0);
            item->setScale(item->scale() - _scale_step);
        }
    }

    void _Rotate_Posi() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            this->rotate(-_rotate_step);
            return;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(0);
            item->setRotation(item->rotation() - _rotate_step);
        }
    }

    void _Rotate_Nega() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            this->rotate(+_rotate_step);
            return;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(0);
            item->setRotation(item->rotation() + _rotate_step);
        }
    }

    void _Restore() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            this->resetTransform();
            return;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(0);
            item->setScale(1.0);
            item->setRotation(0);
            // item->resetTransform();  // note: the transform matrix of item is related to its parent item.
        }
    }

    void _Z_Out() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            return ;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(i);
            item->setZValue(_type._z_out); _type._z_out += 1;
        }
    }

    void _Z_In() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            return ;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(i);
            _type._z_in -= 1; item->setZValue(_type._z_in);
        }
    }

    void _Group() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() <= 1) {
            return;
        }
        QGraphicsItemGroup *group = new QGraphicsItemGroup();
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(0);
            item->setSelected(false);                            // note: remove selected item.
            item->clearFocus();
            group->addToGroup(item);
        }
        group->setZValue(_type._z_out);                                            _type._z_out += 1;
        group->setData(_type._item_id, QString::asprintf("%td", (iptr)_type._id)); _type._id += 1;
        group->setData(_type._item_desc, "组合");
        group->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
        _scene.addItem(group);
        _scene.clearSelection();
        group->setSelected(true);
    }

    void _Break() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            return;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *group = _scene.selectedItems().at(0);  // note: remove selected item.
            if(group->type() == QGraphicsItemGroup::Type) {
                _scene.destroyItemGroup((QGraphicsItemGroup *)group);
            }
        }
    }

    void _Delete() {
        System::Logging(__FUNCTION__);

        if(_scene.selectedItems().count() < 1) {
            return;
        }
        for(iptr i = 0, count = _scene.selectedItems().count(); i < count; i += 1) {
            QGraphicsItem *item = _scene.selectedItems().at(0);  // note: remove selected item.
            _scene.removeItem(item);
        }
    }

public:
    virtual void showEvent(QShowEvent *event) override {
        System::Logging(__FUNCTION__);
        (void) event;

        this->setMouseTracking(true);
        this->setCursor(Qt::CrossCursor);

        iptr width = this->width();
        iptr height = this->height();
        _scene.setSceneRect(-width / 2, -height / 2, width, height);  // note: change the origin point and the dimension of the canvas.
        this->setScene(&_scene);                                      // note: the proportion of the logical coordinate to the device coordinate is 1:1.
        this->setInteractive(true);
        this->setDragMode(QGraphicsView::RubberBandDrag);

        _font.setFamily("Consolas");
        _font.setPointSize(12);
        // _font.setBold(true);

        _pen.setWidth(1);
        _pen.setColor(Qt::black);

        _brush.setColor(Qt::green);
        _brush.setStyle(Qt::SolidPattern);
    }

    virtual void mouseMoveEvent(QMouseEvent *event) override {
        // System::Logging(__FUNCTION__);

        QPoint view_pos = event->pos();
        QPointF scene_pos = this->mapToScene(view_pos);
        QPointF *item_pos = nullptr;
        QString *info = nullptr;
        QGraphicsItem *item = this->itemAt(view_pos);
        if(item != nullptr) {
            item_pos = new QPointF(item->mapFromScene(scene_pos));
            info = new QString(QString::asprintf("[%s: %s]", item->data(_type._item_desc).toString().toStdString().data(), item->data(_type._item_id).toString().toStdString().data()));
        }
        emit _Info(view_pos, scene_pos, item_pos, info);
        QGraphicsView::mouseMoveEvent(event);   // note: this is neccessary.
    }

    virtual void mouseDoubleClickEvent(QMouseEvent *event) override {
        System::Logging(__FUNCTION__);

        if(event->button() == Qt::LeftButton) {
            QGraphicsItem *item = this->itemAt(event->pos());
            if(item == nullptr) {
                return ;
            }

            int type = item->type();
            if(type == QGraphicsRectItem::Type
            || type == QGraphicsEllipseItem::Type
            || type == QGraphicsPolygonItem::Type) {
                QAbstractGraphicsShapeItem *shape = (QGraphicsRectItem *)item;
                QColor color = shape->brush().color();
                color = QColorDialog::getColor(color, this, "请选择颜色: ");
                if(color.isValid() == true) {
                    shape->setBrush(QBrush(color));
                }
            } else if(type == QGraphicsLineItem::Type) {
                QGraphicsLineItem *line = (QGraphicsLineItem *)item;
                QColor color = line->pen().color();
                color = QColorDialog::getColor(color, this, "请选择颜色: ");
                if(color.isValid() == true) {
                    line->setPen(QPen(color));
                }
            } else if(type == QGraphicsTextItem::Type) {
                QGraphicsTextItem *text = (QGraphicsTextItem *)item;
                QFont font = text->font();
                bool ok = false;
                font = QFontDialog::getFont(&ok, font, this, "请选择字体: ");
                if(ok == true) {
                    text->setFont(font);
                }
            }
        }
        QGraphicsView::mouseDoubleClickEvent(event);
    }

    virtual void keyPressEvent(QKeyEvent *event) override {
        System::Logging(__FUNCTION__);

        iptr count = _scene.selectedItems().count();
        if(1 <= count) {
            int key = event->key();
            if(key == Qt::Key_Delete) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(0);
                    _scene.removeItem(item);
                }
            }
            else if(key == Qt::Key_Space) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setRotation(item->rotation() - 90);
                }
            }
            else if(key == Qt::Key_PageUp) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setScale(item->scale() + _scale_step);
                }
            }
            else if(key == Qt::Key_PageDown) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setScale(item->scale() - _scale_step);
                }
            }
            else if(key == Qt::Key_Left) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setX(item->x() - 1);
                }
            }
            else if(key == Qt::Key_Right) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setX(item->x() + 1);
                }
            }
            else if(key == Qt::Key_Up) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setY(item->y() - 1);
                }
            }
            else if(key == Qt::Key_Down) {
                for(iptr i = 0; i < count; i += 1) {
                    QGraphicsItem *item = _scene.selectedItems().at(i);
                    item->setY(item->y() + 1);
                }
            }
        }
        QGraphicsView::keyPressEvent(event);
    }

signals:
    void _Info(QPoint view_pos, QPointF scene_pos, QPointF *item_pos, QString *info);
};

#endif // QGraphicsView_Handler_h
