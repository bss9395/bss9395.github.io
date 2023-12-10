#ifndef CURSORPOS_H
#define CURSORPOS_H

#include <QDebug>
#include <QObject>
#include <QCursor>

class CursorPos: public QObject {
    Q_OBJECT
public:
    explicit CursorPos(QObject *parent = nullptr)
        : QObject(parent) {
        qDebug() << __FUNCTION__;
    }

    virtual ~CursorPos() {
        qDebug() << __FUNCTION__;
    }

public:
    Q_INVOKABLE QPointF pos() {
        return QCursor::pos();
    }
};

#endif // CURSORPOS_H
