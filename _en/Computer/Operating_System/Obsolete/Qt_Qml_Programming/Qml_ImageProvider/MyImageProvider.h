#include <QQuickImageProvider>
#include <QImage>
#include <QPainter>

class MyImageProvider : public QQuickImageProvider {
public:
    MyImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Image) {}

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override {
        // id 是 image://provider/后面的部分
        int width = requestedSize.width()   > 0 ? requestedSize.width()  : 100;
        int height = requestedSize.height() > 0 ? requestedSize.height() : 100;

        if (size) {
            *size = QSize(width, height);
        }

        QImage image(width, height, QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing);

        if (id == "circle") {
            painter.setBrush(Qt::red);
            painter.drawEllipse(0, 0, width, height);
        } else if (id == "square") {
            painter.setBrush(Qt::blue);
            painter.drawRect(0, 0, width, height);
        } else {  // 绘制文本
            painter.setPen(Qt::black);
            painter.drawText(image.rect(), Qt::AlignCenter, id);
        }

        return image;
    }
};
