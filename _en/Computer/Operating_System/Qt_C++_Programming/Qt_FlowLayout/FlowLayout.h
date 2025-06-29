#pragma once

#include <QDebug>
#include <QLayout>
#include <QRect>
#include <QStyle>

class FlowLayout : public QLayout {
public:
    explicit FlowLayout(QWidget *parent)
        : QLayout(parent) {
        QLayout::setContentsMargins(0, 0, 0, 0);
        QLayout::setSpacing(0);
    }

    virtual ~FlowLayout() {
        for(auto iter = _items.begin(); iter != _items.end(); ++iter) {
            delete (*iter);
        }
        _items.clear();
    }

public:
    int count() const override {
        qDebug().nospace() << __FUNCTION__;
        return _items.size();
    }

    void addItem(QLayoutItem* item) override {
        qDebug().nospace() << __FUNCTION__;
        _items.append(item);
    }

    QLayoutItem *itemAt(int index) const override {
        qDebug().nospace() << __FUNCTION__;
        return _items.value(index);
    }

    QLayoutItem* takeAt(int index) override {
        qDebug().nospace() << __FUNCTION__;
        if (0 <= index && index < _items.size()) {
            return _items.takeAt(index);
        }
        return nullptr;
    }

    void setSpacing(int spacing) = delete;

    void setHorizontalSpacing(int spacingH) {
        qDebug().nospace() << __FUNCTION__;
        _spacingH = spacingH;
    }

    void setVerticalSpacing(int spacingV) {
        qDebug().nospace() << __FUNCTION__;
        _spacingV = spacingV;
    }

    int horizontalSpacing() const {
        qDebug().nospace() << __FUNCTION__;
        return _spacingH;
    }

    int verticalSpacing() const {
        qDebug().nospace() << __FUNCTION__;
        return _spacingV;
    }

    Qt::Orientations expandingDirections() const override {
        qDebug().nospace() << __FUNCTION__;
        return { };
    }

    QSize minimumSize() const override {
        // qDebug().nospace() << __FUNCTION__;
        QSize size;
        for (QLayoutItem *item : _items) {
            size = size.expandedTo(item->minimumSize());
        }

        const QMargins margins = QLayout::contentsMargins();
        size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
        qDebug().nospace() << __FUNCTION__ << ", size = " << size;
        return size;
    }

    QSize sizeHint() const override {
        qDebug().nospace() << __FUNCTION__;
        return parentWidget()->size();
    }

    bool hasHeightForWidth() const override {
        qDebug().nospace() << __FUNCTION__;
        return true;
    }

    int heightForWidth(int width) const override {
        qDebug().nospace() << __FUNCTION__;
        int height = doLayout(QRect(0, 0, width, 0), true);
        return height;
    }

    void setGeometry(const QRect &rect) override {
        qDebug().nospace() << __FUNCTION__ << ", rect = " << rect;
        QLayout::setGeometry(rect);
        doLayout(rect, false);
    }

private:
    int doLayout(const QRect &rect, bool dryrun) const {
        qDebug().nospace() << __FUNCTION__ << ", rect = " << rect << ", dryrun = " << dryrun;
        int marginL = 0;
        int marginT = 0;
        int marginR = 0;
        int marginB = 0;
        QLayout::getContentsMargins(&marginL, &marginT, &marginR, &marginB);
        int lastL = rect.x() + marginL;
        int lastT = rect.y() + marginT;
        int lineHeight = 0;
        for(QLayoutItem* item : _items) {
            if((lastL + item->sizeHint().width() < rect.width() - marginR) == false) {
                lastL = marginL;
                if(0 < lineHeight) {
                    lastT += lineHeight + _spacingV;
                }
                lineHeight = 0;
            }
            item->setGeometry(QRect(lastL, lastT, item->sizeHint().width(), item->sizeHint().height()));
            lastL += item->sizeHint().width() + _spacingH;
            lineHeight = qMax(lineHeight, item->sizeHint().height());
        }
        return (-rect.y() + lastT + lineHeight + marginB);
    }

private:
    QList<QLayoutItem*> _items;
    int _spacingH = 0;
    int _spacingV = 0;
};
