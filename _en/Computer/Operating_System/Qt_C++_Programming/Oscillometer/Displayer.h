/* Displayer.h
Author: BSS9395
Update: 2022-07-12T23:00:00+08@China-Shanghai+08
Design: Oscillometer
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Displayer_h
#define Displayer_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Oscillometer.h"

class Displayer : public QIODevice {
    Q_OBJECT

public:
    QAudioInput *_input = nullptr;
    Ui::Oscillometer *_ui = nullptr;
    QLineSeries *_series = nullptr;  // QScatterSeries *_series = nullptr;
    iptr _samples = 4000;
    iptr _resolution = 4;

public:
    explicit Displayer(Ui::Oscillometer *ui, QAudioInput *input, QWidget *parent = nullptr)
        : QIODevice(parent), _input(input), _ui(ui) {
        System::Logging(__FUNCTION__);

        _Setup();
        this->open(QIODevice::WriteOnly);
    }

    virtual ~Displayer() {
        System::Logging(__FUNCTION__);
        _ui->CV_Displayer->setChart(new QChart());
    }

public:
    void _Setup() {
        _ui->CV_Displayer->setChart(new QChart());
        _ui->CV_Displayer->chart()->setTitle("音频输入信号");

        _series = new QLineSeries();  // _series = new QScatterSeries();
        _ui->CV_Displayer->chart()->addSeries(_series);

        QValueAxis *axisY = new QValueAxis();
        _ui->CV_Displayer->chart()->addAxis(axisY, Qt::AlignBottom);
        _series->attachAxis(axisY);
        axisY->setRange(0, _samples);
        axisY->setLabelFormat("%d");
        axisY->setTitleText("Samples");

        QValueAxis *axisZ = new QValueAxis();
        _ui->CV_Displayer->chart()->addAxis(axisZ, Qt::AlignLeft);
        _series->attachAxis(axisZ);
        axisZ->setRange(0, 256);
        axisZ->setLabelFormat("%d");
        axisZ->setTitleText("Level");

        _ui->CV_Displayer->chart()->legend()->hide();

        QVector<QPointF> points;
        points.reserve(_samples);
        for(iptr i = 0; i < _samples; i += 1) {
            points.append(QPointF(i, (quint8)128));
        }
        _series->replace(points);
    }

public:
    virtual qint64 readData(char *data, qint64 maxlen) override {
        System::Logging(__FUNCTION__);

        (void)data;
        (void)maxlen;
        return -1;
    }

    virtual qint64 writeData(const char *data, qint64 len) override {
        System::Logging(__FUNCTION__);

        // note: len <= _samples <= _series->pointsVector().count()
        QVector<QPointF> points = _series->pointsVector().mid(len, -1);
        for(iptr i = 0, count = points.count(); i < count; i += 1) {
            points[i].setX(points[i].x() - len);
        }
        for(iptr head = points.count(), i = 0; i < len; i += 1) {
            points.append(QPointF(head + i, (quint8)data[i]));
        }
        _series->replace(points);
        _ui->SB_Block_Size->setRange(len, len);
        _ui->SB_Buffer_Size->setRange(_input->bufferSize(), _input->bufferSize());
        return len;
    }

signals:
    void _Block_Size(iptr size);
};

#endif // Displayer_h
