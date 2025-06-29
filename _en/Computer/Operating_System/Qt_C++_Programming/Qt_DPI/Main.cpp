#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QWindow>
#include <QScreen>

void _Resolution() {
    QWidget* widget = new QWidget();
    widget->show();
    // widget->hide();
    QScreen* screen = widget->windowHandle()->screen();

    QList<QScreen *> screens = QApplication::screens();
    screens.push_front(screen);
    for (int i = 0; i < screens.size(); i += 1) {
        QScreen *screen = screens[i];
        QSize size = screen->size();
        QRect geometry_available = screen->availableGeometry();
        QRect geometry_available_virtual = screen->availableVirtualGeometry();
        qDebug().nospace() << "Screen[" << i << "]"
                           << "  size: " << size
                           << ", geometry available: " << geometry_available
                           << ", geometry avaialble virtual: " << geometry_available_virtual;
    }
}

void _Scale() {
    QWidget* widget = new QWidget();
    widget->show();
    // widget->hide();
    QScreen* screen = widget->windowHandle()->screen();

    QList<QScreen *> screens = QApplication::screens();
    screens.push_front(screen);
    for (int i = 0; i < screens.size(); i += 1) {
        QScreen* screen = screens[i];
        double dpi_physical = screen->physicalDotsPerInch();
        double dpi_logical = screen->logicalDotsPerInch();
        double ratio_pixel = screen->devicePixelRatio();
        qDebug().nospace() << "Screen[" << i << "]"
                           << "  dpi physical: " << dpi_physical
                           << ", dpi logical: " << dpi_logical
                           << ", ratio pixel: " << ratio_pixel;
    }
}

void _Refresh() {
    QWidget* widget = new QWidget();
    widget->show();
    // widget->hide();
    QScreen* screen = widget->windowHandle()->screen();

    QList<QScreen *> screens = QApplication::screens();
    screens.push_front(screen);
    for (int i = 0; i < screens.size(); i += 1) {
        QScreen* screen = screens[i];
        qreal rate_refresh = screen->refreshRate();
        qDebug().nospace() << "Screen[" << i << "]"
                           << "  rate refresh: " <<rate_refresh << "Hz";
    }
}

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    // _Resolution();
    _Scale();
    // _Refresh();

    return application.exec();
}
