#pragma once

#include <QObject>
#include <QDebug>

class Sender : public QObject {
    Q_OBJECT

signals:
    void _Signal(const QString& text);
};

class Receiver : public QObject {
    Q_OBJECT

public:
    virtual ~Receiver() {
        qDebug().nospace().noquote() << __FUNCTION__;
    }
};
