#ifndef CONFIG_H
#define CONFIG_H

#include <QApplication>
#include <QMouseEvent>
#include <QMainWindow>
#include <QDebug>


class Config : public QGuiApplication
{
    Q_OBJECT

public:
    int _cursorStackDepth = 0;

public:
    explicit Config(int &argc, char **argv)
        : QGuiApplication(argc, argv) {
        qDebug().noquote() << __FUNCTION__;
    }

public:
    Q_INVOKABLE QPointF cursorPos() {
        // qDebug() << __FUNCTION__;
        return QCursor::pos();  // 返回鼠标的全局坐标
    }

    Q_INVOKABLE void restoreCursorShape() {
        qDebug().noquote() << __FUNCTION__;
        while(0 < _cursorStackDepth) {
            QGuiApplication::restoreOverrideCursor();
            _cursorStackDepth -= 1;
        }
    }

    Q_INVOKABLE void overrideCursorShape(Qt::CursorShape cursorShape) {
        qDebug().noquote() << __FUNCTION__;
        QCursor cursor = QCursor(cursorShape);
        QGuiApplication::setOverrideCursor(cursor);
        _cursorStackDepth += 1;
    }

    Q_INVOKABLE QString colorLinearize(const QString &from_argb, const QString &into_argb, const double &snap) {
        // qDebug().noquote() << __FUNCTION__;
        QColor from_color = QColor(from_argb);
        QColor into_color = QColor(into_argb);
        double alpha = from_color.alphaF() + snap * (into_color.alphaF() - from_color.alphaF());
        double red   = from_color.redF()   + snap * (into_color.redF()   - from_color.redF());
        double green = from_color.greenF() + snap * (into_color.greenF() - from_color.greenF());
        double blue  = from_color.blueF()  + snap * (into_color.blueF()  - from_color.blueF());
        return QColor::fromRgbF(red, green, blue, alpha).name(QColor::HexArgb);
    }
};


#endif // CONFIG_H
