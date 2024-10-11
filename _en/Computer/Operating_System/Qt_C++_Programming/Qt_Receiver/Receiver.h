#pragma once

#include <QObject>

class Sender : public QObject {
    Q_OBJECT

signals:
    void _Signal(const QString& text);
};

class Receiver : public QObject {
    Q_OBJECT
};
