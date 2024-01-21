/* Qt6_QPrinter.h
Author: BSS9395
Update: 2023-09-07T10:48:00+08@China-Guangdong-Zhanjiang+08
*/

#ifndef QT6_QPRINTER_H
#define QT6_QPRINTER_H

#include <QMainWindow>
#include "ui_Qt6_QPrinter.h"
#include <QDir>
#include <QFileDialog>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextBlock>

class Qt6_Qimage : public QMainWindow {
    Q_OBJECT

private:
    Ui::Qt6_Qimage *_ui = nullptr;
    QString _filename;
    QImage _image;

public:
    Qt6_Qimage(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Qt6_Qimage) {
        _ui->setupUi(this);

        QObject::connect(_ui->A_Open, &QAction::triggered, this, [this]() -> void {
            QString path = QDir::currentPath();
            QString filter = "图片文件(*.bmp *.jpg *.png);;";
            _filename = QFileDialog::getOpenFileName(this, "选择图片文件", path, filter);
            if(_filename.isEmpty() == true) {
                return;
            }

            QFileInfo info(_filename);
            QDir::setCurrent(info.absolutePath());
            _image.load(_filename);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Reload, &QAction::triggered, this, [this]() -> void {
            QFileInfo info(_filename);
            QDir::setCurrent(info.absolutePath());
            _image.load(_filename);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Zoom_In, &QAction::triggered, this, [this]() -> void {
            int width= _image.width();
            int height = _image.height();
            _image = _image.scaled(width * 1.1, height * 1.1, Qt::KeepAspectRatio);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, this, [this]() -> void {
            int width= _image.width();
            int height = _image.height();
            _image = _image.scaled(width / 1.1, height / 1.1, Qt::KeepAspectRatio);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Rotate_Posi, &QAction::triggered, this, [this]() -> void {
            QTransform transform;
            transform.rotate(-90);
            _image = _image.transformed(transform);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Rotate_Nega, &QAction::triggered, this, [this]() -> void {
            QTransform transform;
            transform.rotate(90);
            _image = _image.transformed(transform);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Flip_UP_Down, &QAction::triggered, this, [this]() -> void {
            _image.mirror(false, true);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->A_Flip_Left_Right, &QAction::triggered, this, [this]() -> void {
            _image.mirror(true,false);
            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->PB_Convert, &QPushButton::clicked, this, [this]() -> void {
            QString text = _ui->CB_Convert->currentText();
            if(text == "Format_RGB16") {
                _image.convertTo(QImage::Format_RGB16);
            } else if(text == "Format_RGB888") {
                _image.convertTo(QImage::Format_RGB888);
            } else if(text == "Format_RGB32") {
                _image.convertTo(QImage::Format_RGB32);
            } else if(text == "Format_Grayscale8") {
                _image.convertTo(QImage::Format_Grayscale8);
            } else if(text == "Format_Grayscale16") {
                _image.convertTo(QImage::Format_Grayscale16);
            } else if(text == "Format_Indexed8") {
                _image.convertTo(QImage::Format_Indexed8);
            }

            QPixmap pixmap = QPixmap::fromImage(_image);
            _ui->L_Image->setPixmap(pixmap);

            _Show_Attribute();
        });

        QObject::connect(_ui->PB_RGB565_Convert, &QPushButton::clicked, this, [this]() -> void {
            _ui->PTE_RGB565->clear();

            int width  = _image.width();
            int height = _image.height();
            int total  = 2 * width * height;
            QString name = QFileInfo(_filename).baseName();
            _ui->PTE_RGB565->appendPlainText(QString("const unsigned char RGB565_%1[%2] = {").arg(name).arg(total));

            QString line;
            int count = 0;
            for(int y = 0; y < height; y += 1) {
                for(int x = 0; x < width; x += 1) {
                    QRgb rgb = _image.pixel(x, y);
                    quint16 red     = qRed(rgb)   & 0x00F8;
                    quint16 green   = qGreen(rgb) & 0x00FC;
                    quint16 blue    = qBlue(rgb)  & 0x00F8;
                    quint16 rgb565  = (red << 8) | (green << 3) | (blue >> 3);
                    quint8 byte_lsb = rgb565 & 0x00FF;
                    quint8 byte_msb = rgb565 >> 8;
                    line += QString::asprintf("0x%02X, 0x%02X, ", byte_lsb, byte_msb);

                    count += 1;
                    if(count == 8) {
                        _ui->PTE_RGB565->appendPlainText(line);
                        line = "";
                        count = 0;
                    }
                }
            }
            if(0 < count) {
                _ui->PTE_RGB565->appendPlainText(line);
            }
            _ui->PTE_RGB565->appendPlainText("};");
            _ui->TW_Tab->setCurrentIndex(1);
        });

        QObject::connect(_ui->PB_RGB565_Save, &QPushButton::clicked, this, [this]() -> void {
            QString name = QFileInfo(_filename).baseName() + ".h";
            QString filter = "C语言头文件(*.h);;C语言程序文件(*.c);;文本文件(*.txt)";
            QString filename = QFileDialog::getSaveFileName(this, "保存文件", name, filter);
            if(filename.isEmpty() == true) {
                return;
            }

            QFile file(filename);
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QString str = _ui->PTE_RGB565->toPlainText();
            QByteArray bytes = str.toUtf8();
            file.write(bytes, bytes.length());
            file.close();
        });

        QObject::connect(_ui->A_Save_As, &QAction::triggered, this, [this]() -> void {
            QString filter = "图片文件(*.bmp *.jpg *.png);;BMP文件(*.bmp);;JPG文件(*.jpg);;PNG文件(*.png)";
            QString filename = QFileDialog::getSaveFileName(this, "保存文件", _filename, filter);
            if(filename.isEmpty() == true) {
                return;
            }
            _image.save(filename);
        });

        QObject::connect(_ui->A_Print_Preview, &QAction::triggered, this, [this]() -> void {
            QPrintPreviewDialog preview(this);
            preview.setWindowFlag(Qt::WindowMaximizeButtonHint);
            QObject::connect(&preview, &QPrintPreviewDialog::paintRequested, this, [this](QPrinter *printer) -> void {
                if(_ui->TW_Tab->currentIndex() == 0) {
                    _Print_Image(printer);
                } else {
                    _Print_RGB565(printer);
                }
            });
            preview.exec();
        });

        QObject::connect(_ui->A_Print, &QAction::triggered, this, [this]() -> void {
            QPrinter printer;
            QPrintDialog dialog(&printer, this);
            if(dialog.exec() == QDialog::Accepted) {
                if(_ui->TW_Tab->currentIndex() == 0) {
                    _Print_Image(&printer);
                } else {
                    _Print_RGB565(&printer);
                }
            }
        });
    }



    ~Qt6_Qimage() {
        delete _ui;
    }

public:
    void _Show_Attribute() {
        QImage::Format format = _image.format();
        if(format == QImage::Format_RGB32) {
            _ui->LE_Format->setText("32bits RGB");
        } else if(format == QImage::Format_RGB16) {
            _ui->LE_Format->setText("16bits RGB565");
        } else if(format == QImage::Format_RGB888) {
            _ui->LE_Format->setText("24bits RGB888");
        } else if(format == QImage::Format_Grayscale8) {
            _ui->LE_Format->setText("8bits grayscale");
        } else if(format == QImage::Format_Grayscale16) {
            _ui->LE_Format->setText("16bits grayscale");
        } else if(format == QImage::Format_ARGB32) {
            _ui->LE_Format->setText("32bits ARGB");
        } else if(format == QImage::Format_Indexed8) {
            _ui->LE_Format->setText("8bits indexes");
        } else {
            _ui->LE_Format->setText(QString("其它格式%1").arg(format));
        }

        _ui->LE_Width->setText(QString("%1pixels").arg(_image.width()));
        _ui->LE_Height->setText(QString("%1pixels").arg(_image.height()));
        _ui->LE_Depth->setText(QString("%1bits/pixel").arg(_image.depth()));
        _ui->LE_Bits->setText(QString("%1bits").arg(_image.bitPlaneCount()));
        _ui->LE_Size->setText(QString("%1KB").arg(_image.sizeInBytes() / 1024));
        _ui->LE_DPI->setText(QString("[%1, %2]").arg(_image.dotsPerMeterX() * 0.0254).arg(_image.dotsPerMeterY() * 0.0254));;

        _ui->CB_Gray->setChecked(_image.isGrayscale());
        _ui->CB_Alpha->setChecked(_image.hasAlphaChannel());
    }

    void _Print_Image(QPrinter *printer) {
        QPixmap pixmap = _ui->TW_Tab->widget(0)->grab();
        QPainter painter(printer);
        QMargins margin(20, 40, 20, 40);
        QRectF rect = printer->pageRect(QPrinter::DevicePixel);
        int width = rect.width();
        int height = rect.height();
        int line_height = 20;
        int current_x = margin.left();
        int current_y = margin.top();
        painter.drawText(current_x, current_y, _filename);
        current_y += line_height;
        painter.drawText(current_x, current_y, QString("page width = %1, page height = %2").arg(width).arg(height));
        current_y += line_height;
        painter.drawText(current_x, current_y, QString("image width = %1, image height = %2").arg(_image.width()).arg(_image.height()));
        current_y += line_height;

        int remain_y = height - current_y;
        if(pixmap.width() <= width && pixmap.height() <= remain_y) {
            current_x = (width - pixmap.width()) / 2;
            painter.drawPixmap(current_x, current_y, pixmap);
        } else {
            if((1.0 * remain_y / width) <= (1.0 * pixmap.height() / pixmap.width())) {
                QPixmap scaled = pixmap.scaledToHeight(remain_y);
                current_x = (width - scaled.width()) / 2;
                painter.drawPixmap(current_x, current_y, scaled);
            } else{
                QPixmap scaled = pixmap.scaledToWidth(width);
                current_x = (width - scaled.width()) / 2;
                painter.drawPixmap(current_x, current_y, scaled);
            }
        }



//        QPainter painter(printer);
//        QMargins margin(20, 40, 20, 40);
//        QRectF rect = printer->pageRect(QPrinter::DevicePixel);
//        int width = rect.width();
//        int height = rect.height();
//        int line_height = 20;
//        int current_x = margin.left();
//        int current_y = margin.top();
//        painter.drawText(current_x, current_y, _filename);
//        current_y += line_height;
//        painter.drawText(current_x, current_y, QString("page width = %1, page height = %2").arg(width).arg(height));
//        current_y += line_height;
//        painter.drawText(current_x, current_y, QString("image width = %1, image height = %2").arg(_image.width()).arg(_image.height()));
//        current_y += line_height;
//
//        int remain_y = height - current_y;
//        if(_image.width() <= width && _image.height() <= remain_y) {
//            current_x = (width - _image.width()) / 2;
//            painter.drawImage(current_x, current_y, _image);
//        } else {
//            if((1.0 * remain_y / width) <= (1.0 * _image.height() / _image.width())) {
//                QImage scaled = _image.scaledToHeight(remain_y);
//                current_x = (width - scaled.width()) / 2;
//                painter.drawImage(current_x, current_y, scaled);
//            } else{
//                QImage scaled = _image.scaledToWidth(width);
//                current_x = (width - scaled.width()) / 2;
//                painter.drawImage(current_x, current_y, scaled);
//            }
//        }
    }

    void _Print_RGB565(QPrinter *printer) {
        QPainter painter(printer);
        QMargins margin(20, 40, 20, 40);
        QRectF rect = printer->pageRect(QPrinter::DevicePixel);
        int width = rect.width();
        int height = rect.height();
        int line_height = 25;
        int current_x = margin.left();
        int current_y = margin.top();

        int page = 1;
        QFont font = _ui->PTE_RGB565->font();
        painter.setFont(font);

        painter.drawLine(margin.left(), height - margin.bottom() + 1, width - margin.right(), height - margin.bottom() + 1);
        painter.drawText(width - 5 * margin.right(), height - margin.bottom() + 20, QString("第%1页").arg(page));
        QTextDocument *document = _ui->PTE_RGB565->document();
        int count = document->blockCount();
        for(int i = 0; i < count; i += 1) {
            QTextBlock line = document->findBlockByNumber(i);
            QString text = line.text();
            painter.drawText(current_x, current_y, text);
            current_y += line_height;

            if(current_y >= height - margin.bottom()) {
                printer->newPage();
                current_y = margin.top();
                page += 1;
                painter.drawLine(margin.left(), height - margin.bottom() + 1, width - margin.right(), height - margin.bottom() + 1);
                painter.drawText(width - 5 * margin.right(), height - margin.bottom() + 20, QString("第%1页").arg(page));
            }
        }
    }
};
#endif // QT6_QPRINTER_H
