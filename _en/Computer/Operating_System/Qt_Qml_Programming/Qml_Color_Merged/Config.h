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
    explicit Config(int &argc, char **argv)
        : QGuiApplication(argc, argv) {
        // qDebug().noquote() << __FUNCTION__;
    }

public:
    Q_INVOKABLE QPointF pos() {
        // qDebug() << __FUNCTION__;
        return QCursor::pos();  // 返回鼠标的全局坐标
    }

    Q_INVOKABLE QString colorReal(const QString &color_argb) {
        // qDebug().noquote() << __FUNCTION__;
        QColor color = QColor(color_argb);
        return QString("[%1, %2, %3, %4]").arg(color.alphaF(), 8, ' ').arg(color.redF(), 8, ' ').arg(color.greenF(), 8, ' ').arg(color.blueF(), 8, ' ');
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

    Q_INVOKABLE QString colorLinearize(const QString &from_argb, const QString &into_argb, const double &snap_a, const double &snap_r, const double &snap_g, const double &snap_b) {
        // qDebug().noquote() << __FUNCTION__;
        QColor from_color = QColor(from_argb);
        QColor into_color = QColor(into_argb);
        double alpha = from_color.alphaF() + snap_a * (into_color.alphaF() - from_color.alphaF());
        double red   = from_color.redF()   + snap_r * (into_color.redF()   - from_color.redF());
        double green = from_color.greenF() + snap_g * (into_color.greenF() - from_color.greenF());
        double blue  = from_color.blueF()  + snap_b * (into_color.blueF()  - from_color.blueF());
        return QColor::fromRgbF(red, green, blue, alpha).name(QColor::HexArgb);
    }

    Q_INVOKABLE QString colorMerge(const QString &back, const QString &front) {
        // qDebug().noquote() << __FUNCTION__;
        QColor color_back  = QColor(back);
        QColor color_front = QColor(front);

        // A_merged = A_front + A_back * (1 - A_front)
        // C_merged = C_front * A_front + C_back * A_back * (1 - A_front) = C_front * A_front + C_back * A_back - C_back * A_front * A_back
        // 采用方法：前本背补。前景色为本色，背景色为补色，前景色叠加背景色。
        double alpha = color_front.alphaF() + color_back.alphaF() * (1.0 - color_front.alphaF());
        double red   = color_front.redF()   * color_front.alphaF() + color_back.redF()   * (1.0 - color_front.alphaF());
        double green = color_front.greenF() * color_front.alphaF() + color_back.greenF() * (1.0 - color_front.alphaF());
        double blue  = color_front.blueF()  * color_front.alphaF() + color_back.blueF()  * (1.0 - color_front.alphaF());
        return QColor::fromRgbF(red, green, blue, alpha).name(QColor::HexArgb);
    }
};

#endif // CONFIG_H
