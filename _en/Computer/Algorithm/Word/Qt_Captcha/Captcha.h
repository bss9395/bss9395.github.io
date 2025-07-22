#pragma once

#include <QChar>
#include <QDebug>
#include <QFrame>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QtGlobal>
#include <QRandomGenerator>


class Captcha : public QWidget {
    Q_OBJECT

public:
    explicit Captcha() {
        static QString style = R"!(
        [objectName = "_this"] {
            background-color: #FFFFFFFF;
        }
        )!";
        this->setObjectName("_this");
        this->setStyleSheet(style);

        this->resize(200, 100);
        _captcha = _GenerateCaptcha(4, this->width(), this->height());
        _captcha.save("captcha.png");
    }

public:
    void paintEvent(QPaintEvent *paintEvent) override {
        qDebug().nospace() << __FUNCTION__ << ", paintEvent = " << paintEvent;
        (void)paintEvent;
        QPainter painter(this);
        painter.drawPixmap(0, 0, this->width(), this->height(), _captcha);
    }

    void mousePressEvent(QMouseEvent *mouseEvent) {
        (void)mouseEvent;
        qDebug().nospace() << __FUNCTION__ << ", mouseEvent = " << mouseEvent;
        _captcha = _GenerateCaptcha(4, this->width(), this->height());
        _captcha.save("captcha.png");
        repaint();
    }

public:
    QPixmap _GenerateCaptcha(int count, int width, int height) {
        static QString characters = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";

        QString code = "";
        for (int i = 0; i < count; i += 1) {
            code += characters[QRandomGenerator::global()->generate() % characters.size()];
        }

        ////////////////////////////////////////////////////////////////////////

        QPixmap captcha(width, height);
        captcha.fill(QColor(0x00FFFFFF));    // 设置背景透明
        QPainter painter(&captcha);

        //画点
        for (int i = 0; i < 100; i += 1) {
            QPen pen = QPen(QColor(QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256));
            painter.setPen(pen);
            painter.drawPoint(QRandomGenerator::global()->generate() % captcha.width(), QRandomGenerator::global()->generate() % captcha.height());
        }

        //画线
        for (int i = 0; i < 5; i += 1) {
            QPen pen = QPen(QColor(QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256));
            painter.setPen(pen);
            painter.drawLine(QRandomGenerator::global()->generate() % captcha.width(), QRandomGenerator::global()->generate() % captcha.height(), QRandomGenerator::global()->generate() % captcha.width(), QRandomGenerator::global()->generate() % captcha.height());
        }

        // 绘制验证码
        QFont font = QFont("Consolas", 25, QFont::Bold, false);  // family, pointSize, weight, italic
        painter.setFont(font);
        QFontMetrics fontMetrics = QFontMetrics(font);
        int widthTotal = fontMetrics.tightBoundingRect(code).width();
        int marginH  = (2 <= code.size()) ? fontMetrics.height() / 3 : (captcha.width() - widthTotal) / 2;    // 由于rotate而设置marginH
        int spacingH = (2 <= code.size()) ? (captcha.width() - marginH * 2 - widthTotal) / (code.size() - 1) : 0;
        int marginV  = (1 <= code.size()) ? widthTotal / code.size() / 2 : 0;                                 // 由于rotate而设置marginV
        int lastL = marginH;
        for (int i = 0; i < code.size(); i += 1) {
            QPen pen = QPen(QColor(QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256, QRandomGenerator::global()->generate() % 256));
            painter.setPen(pen);
            QRect bounding = fontMetrics.tightBoundingRect(QString(code[i]));    // tightRect.y==baseline, tightRect.height-tightRect.y==leading
            // qDebug().nospace() << "bounding = " << bounding;
            int denominator = captcha.height() - bounding.height() - marginV * 2;
            int lastB = 0;
            if(1 <= denominator) {
                lastB = captcha.height() - (bounding.height() - (-bounding.y())) - marginV - QRandomGenerator::global()->generate() % denominator;
            } else {
                lastB = captcha.height() - (captcha.height() - bounding.height()) / 2 - (bounding.height() - (-bounding.y()));    // 居中显示
            }
            QTransform transform;
            transform.translate(lastL + bounding.width() / 2, lastB);
            transform.rotate(QRandomGenerator::global()->bounded(-45, +45));
            transform.translate(-bounding.width() / 2, 0);
            painter.setTransform(transform);
            painter.drawText(bounding.x(), 0, QString(code[i]));    // 以基线中点为原点，tightBounding.x应该为0
            lastL += bounding.width() + spacingH;
        }

        painter.end();
        return captcha;
    }

private:
    QPixmap _captcha;
};
