/* Playback.h
Author: BSS9395
Update: 2022-07-17T16:42:00+08@China-Shanghai+08
Design: Playback
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Playback_h
#define Playback_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_Playback.h"

class Playback : public QMainWindow {
    Q_OBJECT


public:
    Ui::Playback *_ui = nullptr;
    QPen _pen;
    QBrush _brush;

public:
    explicit Playback(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Playback) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _pen.setWidth(1);
        _pen.setColor(Qt::black);
        _pen.setStyle(Qt::SolidLine);
        _pen.setCapStyle(Qt::FlatCap);
        _pen.setJoinStyle(Qt::BevelJoin);
        _brush.setColor(Qt::blue);
        _brush.setStyle(Qt::SolidPattern);


        QPixmap pixmap(400, 300);
        pixmap.fill(Qt::white);
        QPainter painter_pixmap(&pixmap);
        painter_pixmap.setPen(_pen);
        painter_pixmap.setBrush(_brush);
        painter_pixmap.drawEllipse(0, 0, 400, 300);
        pixmap.save("pixmap.png");


        QImage image(400, 300, QImage::Format_ARGB32);
        image.fill(Qt::white);
        QPainter painter_image(&image);
        painter_image.setPen(_pen);
        painter_image.setBrush(_brush);
        painter_image.drawEllipse(0, 0, 400, 300);
        image.save("image.png");


        QPicture picture;
        QPainter painter_picture;
        painter_picture.begin(&picture);
        painter_picture.setPen(_pen);
        painter_picture.setBrush(_brush);
        painter_picture.drawEllipse(0, 0, 400, 300);
        painter_picture.end();
        picture.save("picture.dat");
    }

    virtual ~Playback() {
        System::Logging(__FUNCTION__);
        Delete(_ui);
    }

public:
    virtual void paintEvent(QPaintEvent *event) override {
        (void) event;
        System::Logging(__FUNCTION__);

        QPixmap pixmap(":/images/butterfly_transparent.png");
        QPainter painter_pixmap(this);
        painter_pixmap.drawPixmap(0, 0, pixmap);


        QImage image;
        image.load(":/images/butterfly_transparent.png");
        for(int width = 60; width < 100; width += 1) {
            for(int height = 70; height < 100; height += 1) {
                image.setPixelColor(width, height, QColor(0, 255, 0));
            }
        }
        QPainter painter_image(this);
        painter_image.drawImage(400, 0, image);


        QPicture picture;
        picture.load("picture.dat");
        QPainter painter_picture(this);
        painter_picture.drawPicture(0, 300, picture);
    }
};
#endif // Playback_h
