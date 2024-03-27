#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>
#include <QApplication>
#include <QMouseEvent>


class Config: public QGuiApplication {
    Q_OBJECT

public:
    explicit Config(int &argc, char *argv[])
        : QGuiApplication(argc, argv) {
        // qDebug().noquote() << __FUNCTION__;
    }

public:
    Q_INVOKABLE QPointF cursorPos() {
        // qDebug().noquote() << __FUNCTION__;
        return QCursor::pos();  // 返回鼠标的全局坐标
    }
};

#endif // CONFIG_H
