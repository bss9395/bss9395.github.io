/* Chart.h
Author: BSS9395
Update: 2022-07-05T22:56:00+08@China-Shanghai+08
Design: Chart
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Chart_h
#define Chart_h

#define  Header_h
#include "Common.h"
#include "System.h"
#include "ui_Chart.h"
#include "QChartView_Handler.h"

class Chart : public QMainWindow {
    Q_OBJECT

    struct : public Enume {
        Enume _AlignTop    = Enume(this, Qt::AlignTop   , "上侧");
        Enume _AlignBottom = Enume(this, Qt::AlignBottom, "下侧");
        Enume _AlignLeft   = Enume(this, Qt::AlignLeft  , "左侧");
        Enume _AlignRight  = Enume(this, Qt::AlignRight , "右侧");
    } _alignment;

    struct : public Enume {
        Enume _ChartThemeLight        = Enume(this, QChart::ChartThemeLight       , "ChartThemeLight");
        Enume _ChartThemeBlueCerulean = Enume(this, QChart::ChartThemeBlueCerulean, "ChartThemeBlueCerulean");
        Enume _ChartThemeDark         = Enume(this, QChart::ChartThemeDark        , "ChartThemeDark");
        Enume _ChartThemeBrownSand    = Enume(this, QChart::ChartThemeBrownSand   , "ChartThemeBrownSand");
        Enume _ChartThemeBlueNcs      = Enume(this, QChart::ChartThemeBlueNcs     , "ChartThemeBlueNcs");
        Enume _ChartThemeHighContrast = Enume(this, QChart::ChartThemeHighContrast, "ChartThemeHighContrast");
        Enume _ChartThemeBlueIcy      = Enume(this, QChart::ChartThemeBlueIcy     , "ChartThemeBlueIcy");
        Enume _ChartThemeQt           = Enume(this, QChart::ChartThemeQt          , "ChartThemeQt");
    } _theme;

    struct : public Enume {
        Enume _NoAnimation        = Enume(this, QChart::NoAnimation       , "NoAnimation");
        Enume _GridAxisAnimations = Enume(this, QChart::GridAxisAnimations, "GridAxisAnimations");
        Enume _SeriesAnimations   = Enume(this, QChart::SeriesAnimations  , "SeriesAnimations");
        Enume _AllAnimations      = Enume(this, QChart::AllAnimations     , "AllAnimations");
    } _animation;

    struct : public Enume {
        Enume _NoPen          = Enume(this, Qt::NoPen         , "   ");
        Enume _SolidLine      = Enume(this, Qt::SolidLine     , "-  ");
        Enume _DashLine       = Enume(this, Qt::DashLine      , "-- ");
        Enume _DotLine        = Enume(this, Qt::DotLine       , ".. ");
        Enume _DashDotLine    = Enume(this, Qt::DashDotLine   , "-. ");
        Enume _DashDotDotLine = Enume(this, Qt::DashDotDotLine, "-..");
    } _penstyle;

public:
    Ui::Chart   *_ui   = nullptr;
    QLabel    *_status = nullptr;
    QLineSeries *_line = nullptr;
    QValueAxis  *_axis = nullptr;
    QPen _pen_dotted   = QPen();
    QPen _pen_solid    = QPen();
    QBrush _brush      = QBrush();

    qreal _x_min  = 0.0;
    qreal _x_max  = 10.0;
    qreal _x_step = 0.5;
    qreal _y_min  = -1.0;
    qreal _y_max  = +1.0;

public:
    explicit Chart(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Chart) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup();
        _Setup_Data();

        ////////////////////////////////

        QObject::connect(_ui->A_Refresh, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Refresh, &QAction::triggered, this, [this]() -> void {");

            _Setup_Data();
        });

        QObject::connect(_ui->A_Zoom_In, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Zoom_In, &QAction::triggered, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->zoom(1 + QChartView_Handler::_zoom_ratio);
        });

        QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Zoom_Out, &QAction::triggered, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->zoom(1 - QChartView_Handler::_zoom_ratio);
        });

        QObject::connect(_ui->A_Restore, &QAction::triggered, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->A_Restore, &QAction::triggered, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->zoomReset();
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Legend_Label_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Legend_Label_Font, &QPushButton::clicked, this, [this]() -> void {");

            _Get_Font(_ui->PB_Legend_Label_Font);
        });

        QObject::connect(_ui->PB_Legend_Label_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Legend_Label_Color, &QPushButton::clicked, this, [this]() -> void {");

            _Get_Color(_ui->PB_Legend_Label_Color);
        });

        QObject::connect(_ui->PB_Legend_Label_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Legend_Label_Submit, &QPushButton::clicked, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->setTitle(_ui->LE_Legend_Label_Title->text());
            _ui->CV_ChartView->chart()->setTitleFont(_ui->PB_Legend_Label_Font->font());
            _ui->CV_ChartView->chart()->setTitleBrush(_ui->PB_Legend_Label_Color->palette().color(QPalette::Button));
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Legend_Metrics_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Legend_Metrics_Submit, &QPushButton::clicked, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->legend()->setAlignment((Qt::AlignmentFlag)_alignment[_ui->CB_Legend_Metrics_Location->currentIndex()]._enume);

            QMargins margins = QMargins();
            margins.setLeft(_ui->SB_Legend_Metrics_Left->value());
            margins.setRight(_ui->SB_Legend_Metrics_Right->value());
            margins.setTop(_ui->SB_Legend_Metrics_Top->value());
            margins.setBottom(_ui->SB_Legend_Metrics_Bottom->value());
            _ui->CV_ChartView->chart()->setMargins(margins);
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Legend_Effect_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Legend_Effect_Submit, &QPushButton::clicked, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->setTheme((QChart::ChartTheme)_theme[_ui->CB_Legend_Effect_Theme->currentIndex()]._enume);
            _ui->CV_ChartView->chart()->setAnimationOptions((QChart::AnimationOption)_animation[_ui->CB_Legend_Effect_Animation->currentIndex()]._enume);
        });

        QObject::connect(_ui->PB_Legend_Display_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Legend_Display_Submit, &QPushButton::clicked, this, [this]() -> void {");

            _ui->CV_ChartView->chart()->legend()->setVisible(_ui->CB_Legend_Display_Legend->isChecked());
            _ui->CV_ChartView->chart()->legend()->setBackgroundVisible(_ui->CB_Legend_Display_Border->isChecked());
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Curve_Sequence_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Curve_Sequence_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_line != nullptr) {
                _line->setName(_ui->LE_Curve_Sequence_Name->text());
                _line->setOpacity(_ui->S_Curve_Sequence_Opacity->value() / 255.0);
                QPen pen = QPen();
                pen.setStyle((Qt::PenStyle)_penstyle[_ui->CB_Curve_Sequence_Style->currentIndex()]._enume);
                pen.setWidth(_ui->SB_Curve_Sequence_Width->value());
                pen.setColor(_ui->PB_Curve_Sequence_Color->palette().color(QPalette::Button));
                _line->setPen(pen);
            }
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Curve_Label_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Curve_Label_Font, &QPushButton::clicked, this, [this]() -> void {");

            QFont font = _ui->PB_Curve_Label_Font->font();
            bool ok = false;
            font = QFontDialog::getFont(&ok, font);
            _ui->PB_Curve_Label_Font->setFont(font);
        });

        QObject::connect(_ui->PB_Curve_Label_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Curve_Label_Color, &QPushButton::clicked, this, [this]() -> void {");

            _ui->PB_Curve_Label_Color->setAutoFillBackground(true);
            _ui->PB_Curve_Label_Color->setFlat(true);

            QPalette palette = _ui->PB_Curve_Label_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
            }
            _ui->PB_Curve_Label_Color->setPalette(palette);
        });

        QObject::connect(_ui->PB_Curve_Label_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Curve_Label_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_line != nullptr) {
                _line->setPointLabelsFormat(_ui->CB_Curve_Label_Format->currentText());
                _line->setPointLabelsFont(_ui->PB_Curve_Label_Font->font());
                _line->setPointLabelsColor(_ui->PB_Curve_Label_Color->palette().color(QPalette::Button));
            }
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Curve_Display_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Curve_Display_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_line != nullptr) {
                _line->setVisible(_ui->CB_Curve_Display_Curve->isChecked());
                _line->setPointsVisible(_ui->CB_Curve_Display_Point->isChecked());
                _line->setPointLabelsVisible(_ui->CB_Curve_Display_Label->isChecked());
            }
        });

        ////////////////////////////////

        auto Fetch_Axis = [this]() -> void {
            System::Logging("auto Axis = [this]() -> void {");

            if(_ui->RB_Metrics_Direction_XAxis->isChecked() == true) {
                _axis = (QValueAxis *)_ui->CV_ChartView->chart()->axes(Qt::Horizontal)[0];
            } else if(_ui->RB_Metrics_Direction_ZAxis->isChecked() == true) {
                _axis = (QValueAxis *)_ui->CV_ChartView->chart()->axes(Qt::Vertical)[0];
            }
            if(_axis != nullptr) {
                _ui->LE_Metrics_Label_Name->setText(_axis->titleText());
                _ui->PB_Metrics_Label_Font->setFont(_axis->titleFont());
                QPalette palette = _ui->PB_Metrics_Label_Color->palette();
                palette.setColor(QPalette::Button, _axis->titleBrush().color());
                _ui->PB_Metrics_Label_Color->setPalette(palette);

                _ui->DSB_Metrics_Range_Min->setValue(_axis->min());
                _ui->DSB_Metrics_Range_Max->setValue(_axis->max());
                _ui->LE_Metrics_Range_Format->setText(_axis->labelFormat());

                _ui->SB_Metrics_Interval_Major_Count->setValue(_axis->tickCount() - 1);
                _ui->SB_Metrics_Interval_Minor_Count->setValue(_axis->minorTickCount() + 1);
                _ui->CB_Metrics_Interval_Major_Style->setCurrentText(_penstyle._Alias(_axis->gridLinePen().style()));
                _ui->SB_Metrics_Interval_Major_Width->setValue(_axis->gridLinePen().width());
                palette = _ui->PB_Metrics_Interval_Major_Color->palette();
                palette.setColor(QPalette::Button, _axis->gridLineColor());
                _ui->PB_Metrics_Interval_Major_Color->setPalette(palette);
                _ui->CB_Metrics_Interval_Minor_Style->setCurrentText(_penstyle._Alias(_axis->minorGridLinePen().style()));
                _ui->SB_Metrics_Interval_Minor_Width->setValue(_axis->minorGridLinePen().width());
                palette = _ui->PB_Metrics_Interval_Minor_Color->palette();
                palette.setColor(QPalette::Button, _axis->minorGridLineColor());
                _ui->PB_Metrics_Interval_Minor_Color->setPalette(palette);
                _ui->CB_Metrics_Interval_Axis_Style->setCurrentText(_penstyle._Alias(_axis->linePen().style()));
                _ui->SB_Metrics_Interval_Axis_Width->setValue(_axis->linePen().width());
                palette = _ui->PB_Metrics_Interval_Axis_Color->palette();
                palette.setColor(QPalette::Button, _axis->linePenColor());
                _ui->PB_Metrics_Interval_Axis_Color->setPalette(palette);

                _ui->CB_Metrics_Display_Axis->setChecked(_axis->isVisible());
                _ui->CB_Metrics_Display_Label->setChecked(_axis->labelsVisible());
                _ui->CB_Metrics_Display_Title->setChecked(_axis->isTitleVisible());
                _ui->CB_Metrics_Display_Major_Grid->setChecked(_axis->isGridLineVisible());
                _ui->CB_Metrics_Display_Minor_Grid->setChecked(_axis->isMinorGridLineVisible());
                _ui->CB_Metrics_Display_Line->setChecked(_axis->isLineVisible());
            }
        };
        QObject::connect(_ui->RB_Metrics_Direction_XAxis, &QRadioButton::clicked, this, Fetch_Axis);
        QObject::connect(_ui->RB_Metrics_Direction_YAxis, &QRadioButton::clicked, this, Fetch_Axis);
        QObject::connect(_ui->RB_Metrics_Direction_ZAxis, &QRadioButton::clicked, this, Fetch_Axis);

        ////////////////////////////////

        QObject::connect(_ui->PB_Metrics_Label_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Label_Font, &QPushButton::clicked, this, [this]() -> void {");

            bool ok = false;
            QFont font = QFontDialog::getFont(&ok, _ui->PB_Metrics_Label_Font->font(), this);
            if(ok == true) {
                _ui->PB_Metrics_Label_Font->setFont(font);
            }
        });

        QObject::connect(_ui->PB_Metrics_Label_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Label_Color, &QPushButton::clicked, this, [this]() -> void {");

            QPalette palette = _ui->PB_Metrics_Label_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
                _ui->PB_Metrics_Label_Color->setPalette(palette);
            }
        });

        QObject::connect(_ui->PB_Metrics_Label_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Label_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_axis != nullptr) {
                _axis->setTitleText(_ui->LE_Metrics_Label_Name->text());
                _axis->setTitleFont(_ui->PB_Metrics_Label_Font->font());
                _axis->setTitleBrush(_ui->PB_Metrics_Label_Color->palette().color(QPalette::Button));
            }
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Metrics_Range_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Range_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_axis != nullptr) {
                _axis->setMin(_ui->DSB_Metrics_Range_Min->value());
                _axis->setMax(_ui->DSB_Metrics_Range_Max->value());
                _axis->setLabelFormat(_ui->LE_Metrics_Range_Format->text());
            }
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Metrics_Interval_Major_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Interval_Major_Color, &QPushButton::clicked, this, [this]() -> void {");

            _Get_Color(_ui->PB_Metrics_Interval_Major_Color);
        });

        QObject::connect(_ui->PB_Metrics_Interval_Minor_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Interval_Minor_Color, &QPushButton::clicked, this, [this]() -> void {");

            _Get_Color(_ui->PB_Metrics_Interval_Minor_Color);
        });

        QObject::connect(_ui->PB_Metrics_Interval_Axis_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Interval_Axis_Color, &QPushButton::clicked, this, [this]() -> void {");

            _Get_Color(_ui->PB_Metrics_Interval_Axis_Color);
        });

        QObject::connect(_ui->PB_Metrics_Interval_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Interval_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_axis != nullptr) {
                _axis->setTickCount(_ui->SB_Metrics_Interval_Major_Count->value() + 1);
                _axis->setMinorTickCount(_ui->SB_Metrics_Interval_Minor_Count->value() - 1);

                QPen pen = QPen();
                pen.setStyle((Qt::PenStyle)_penstyle[_ui->CB_Metrics_Interval_Major_Style->currentIndex()]._enume);
                pen.setWidth(_ui->SB_Metrics_Interval_Major_Width->value());
                _axis->setGridLinePen(pen);
                _axis->setGridLineColor(_ui->PB_Metrics_Interval_Major_Color->palette().color(QPalette::Button));
                pen.setStyle((Qt::PenStyle)_penstyle[_ui->CB_Metrics_Interval_Minor_Style->currentIndex()]._enume);
                pen.setWidth(_ui->SB_Metrics_Interval_Minor_Width->value());
                _axis->setMinorGridLinePen(pen);
                _axis->setMinorGridLineColor(_ui->PB_Metrics_Interval_Minor_Color->palette().color(QPalette::Button));
                pen.setStyle((Qt::PenStyle)_penstyle[_ui->CB_Metrics_Interval_Axis_Style->currentIndex()]._enume);
                pen.setWidth(_ui->SB_Metrics_Interval_Axis_Width->value());
                _axis->setLinePen(pen);
                _axis->setLinePenColor(_ui->PB_Metrics_Interval_Axis_Color->palette().color(QPalette::Button));
            }
        });

        ////////////////////////////////

        QObject::connect(_ui->PB_Metrics_Display_Submit, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Metrics_Display_Submit, &QPushButton::clicked, this, [this]() -> void {");

            if(_axis != nullptr) {
                _axis->setVisible(_ui->CB_Metrics_Display_Axis->isChecked());
                _axis->setLabelsVisible(_ui->CB_Metrics_Display_Label->isChecked());
                _axis->setTitleVisible(_ui->CB_Metrics_Display_Title->isChecked());
                _axis->setGridLineVisible(_ui->CB_Metrics_Display_Major_Grid->isChecked());
                _axis->setMinorGridLineVisible(_ui->CB_Metrics_Display_Minor_Grid->isChecked());
                _axis->setLineVisible(_ui->CB_Metrics_Display_Line->isChecked());
            }
        });
    }

    virtual ~Chart() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _Setup() {
        System::Logging(__FUNCTION__);

        qsrand(QTime::currentTime().second());

        _pen_dotted.setWidth(1);
        _pen_dotted.setColor(Qt::black);
        _pen_dotted.setStyle(Qt::DotLine);

        _pen_solid.setWidth(1);
        _pen_solid.setColor(Qt::black);
        _pen_solid.setStyle(Qt::SolidLine);

        _ui->CV_ChartView->setChart(new QChart());
        _ui->CB_Legend_Metrics_Location->addItems(_alignment._Aliases());
        _ui->CB_Legend_Effect_Theme->addItems(_theme._Aliases());
        _ui->CB_Legend_Effect_Animation->addItems(_animation._Aliases());
        _ui->CB_Curve_Sequence_Style->addItems(_penstyle._Aliases());
        _ui->CB_Metrics_Interval_Major_Style->addItems(_penstyle._Aliases());
        _ui->CB_Metrics_Interval_Minor_Style->addItems(_penstyle._Aliases());
        _ui->CB_Metrics_Interval_Axis_Style->addItems(_penstyle._Aliases());

        _ui->CB_Curve_Label_Format->addItems(QStringList {
            "@yPoint",
            "(@xPoint, @yPoint)",
            "@xPoint, @yPoint"
        });

        _status = new QLabel();
        _ui->SB_Status->addWidget(_status);
        QObject::connect(_ui->CV_ChartView, &QChartView_Handler::_Mouse_Pos, this, [this](QPoint pos) -> void {
            System::Logging("QObject::connect(_ui->CV_ChartView, &QChartView_Handler::_Mouse_Pos, this, [this]() -> void {");

            QPointF value = _ui->CV_ChartView->chart()->mapToValue(pos);
            _status->setText(QString::asprintf("value[%-5.2f, %-5.2f]", value.x(), value.y()));
        });
    }

    void _Setup_Data() {
        System::Logging(__FUNCTION__);

        QChart *chart = _ui->CV_ChartView->chart();
        if(1 <= chart->series().count()) {
            chart->removeAllSeries();
        }
        while(1 <= chart->axes(Qt::Horizontal).count()) {
            chart->removeAxis(chart->axes(Qt::Horizontal).at(0));
        }
        while(1 <= chart->axes(Qt::Vertical).count()) {
            chart->removeAxis(chart->axes(Qt::Vertical).at(0));
        }

        QLineSeries *line_0 = new QLineSeries();
        QLineSeries *line_1 = new QLineSeries();
        chart->addSeries(line_0);
        chart->addSeries(line_1);
        line_0->setName("y = sin(x)");
        line_1->setName("y = cos(x)");
        qreal y = 0.0;
        qreal err = 0.0;
        for(qreal x = _x_min; x <= _x_max; x += _x_step) {
            err = ((qrand() % 10) - 5) / 50.0;
            y = qSin(x) + err;
            line_0->append(x, y);

            err = ((qrand() % 10) - 5) / 50.0;
            y = qCos(x) + err;
            line_1->append(x, y);
        }

        QValueAxis *axis_x = new QValueAxis();
        chart->addAxis(axis_x, Qt::AlignBottom);
        axis_x->setRange(0, 10);
        axis_x->setTitleText("x /sec");
        axis_x->setTickCount(11);
        axis_x->setMinorTickCount(4);
        axis_x->setLabelFormat("%.1f");
        line_0->attachAxis(axis_x);
        line_1->attachAxis(axis_x);

        QValueAxis *axis_y = new QValueAxis();
        chart->addAxis(axis_y, Qt::AlignLeft);
        axis_y->setRange(-2, +2);
        axis_y->setTitleText("y /1");
        axis_y->setTickCount(5);
        axis_y->setMinorTickCount(4);
        axis_y->setLabelFormat("%.2f");
        line_0->attachAxis(axis_y);
        line_1->attachAxis(axis_y);

        chart->setTitle("三角曲线");
        chart->legend()->setVisible(true);

        auto markers = chart->legend()->markers();
        System::Logging("markers.count() = %d", markers.count());
        for(auto iter = markers.begin(), end = markers.end(); iter != end; iter += 1) {
            QObject::connect(*iter, &QLegendMarker::clicked, this, [this]() -> void {
                System::Logging("QObject::connect(*iter, &QLegendMarker::clicked, this, [iter]() -> void {");

                // QLegendMarker *marker = (*iter);                 // note: iter is transient.
                QLegendMarker *marker = (QLegendMarker *)sender();
                int type = marker->type();

                if(type == QLegendMarker::LegendMarkerTypeXY) {
                    bool visible = marker->series()->isVisible();
                    marker->series()->setVisible(!visible);
                    marker->setVisible(true);
                    qreal alpha = (visible == true ? 0.5 : 1.0);

                    QPen pen = marker->pen();
                    QColor color = pen.color();
                    color.setAlphaF(alpha);
                    pen.setColor(color);
                    marker->setPen(pen);

                    QBrush brush = marker->labelBrush();
                    color = brush.color();
                    color.setAlphaF(alpha);
                    brush.setColor(color);
                    marker->setLabelBrush(brush);

                    brush = marker->brush();
                    color = brush.color();
                    color.setAlphaF(alpha);
                    brush.setColor(color);
                    marker->setBrush(brush);
                }
            });
        }

        auto LineSeries = [this](QLineSeries *line) -> void {
            QObject::connect(line, &QLineSeries::clicked, this, [this, line]() -> void {
                System::Logging("QObject::connect(line, &QLineSeries::clicked, this, [this](QLineSeries *line) -> void {");

                _ui->PB_Curve_Sequence_Color->setAutoFillBackground(true);
                _ui->PB_Curve_Sequence_Color->setFlat(true);
                _ui->S_Curve_Sequence_Opacity->setRange(0, 255);
                _ui->S_Curve_Sequence_Opacity->setSingleStep(1);

                _ui->LE_Curve_Sequence_Name->setText(line->name());
                _ui->S_Curve_Sequence_Opacity->setValue(line->opacity() * 255);
                _ui->CB_Curve_Sequence_Style->setCurrentText(_penstyle._Alias(line->pen().style()));
                _ui->SB_Curve_Sequence_Width->setValue(line->pen().width());
                QPalette palette = _ui->PB_Curve_Sequence_Color->palette();
                palette.setColor(QPalette::Button, line->color());
                _ui->PB_Curve_Sequence_Color->setPalette(palette);

                _ui->CB_Curve_Label_Format->setCurrentText(line->pointLabelsFormat());
                _ui->PB_Curve_Label_Font->setFont(line->pointLabelsFont());
                palette = _ui->PB_Curve_Label_Color->palette();
                palette.setColor(QPalette::Button, line->pointLabelsColor());
                _ui->PB_Curve_Label_Color->setPalette(palette);

                _ui->CB_Curve_Display_Curve->setChecked(line->isVisible());
                _ui->CB_Curve_Display_Point->setChecked(line->pointsVisible());
                _ui->CB_Curve_Display_Label->setChecked(line->pointLabelsVisible());
            });
        };
        LineSeries(line_0);
        LineSeries(line_1);

        _ui->LE_Legend_Label_Title->setText(_ui->CV_ChartView->chart()->title());
        _ui->PB_Legend_Label_Font->setFont(_ui->CV_ChartView->chart()->titleFont());
        QPalette palette = _ui->PB_Legend_Label_Color->palette();
        palette.setColor(QPalette::Button, _ui->CV_ChartView->chart()->titleBrush().color());
        _ui->PB_Legend_Label_Color->setPalette(palette);

        _ui->CB_Legend_Metrics_Location->setCurrentText(_alignment._Alias(_ui->CV_ChartView->chart()->legend()->alignment()));
        QMargins margins = _ui->CV_ChartView->chart()->margins();
        _ui->SB_Legend_Metrics_Left->setValue(margins.left());
        _ui->SB_Legend_Metrics_Right->setValue(margins.right());
        _ui->SB_Legend_Metrics_Top->setValue(margins.top());
        _ui->SB_Legend_Metrics_Bottom->setValue(margins.bottom());

        _ui->CB_Legend_Effect_Theme->setCurrentText(_theme._Alias(_ui->CV_ChartView->chart()->theme()));
        _ui->CB_Legend_Effect_Animation->setCurrentText(_animation._Alias(_ui->CV_ChartView->chart()->animationOptions()));

        _ui->CB_Legend_Display_Legend->setChecked(_ui->CV_ChartView->chart()->legend()->isVisible());
        _ui->CB_Legend_Display_Border->setChecked(_ui->CV_ChartView->chart()->legend()->isBackgroundVisible());
    }

public:
    template<typename Type>
    void _Get_Font(Type *type) {
        System::Logging(__FUNCTION__);

        bool ok = false;
        QFont font = QFontDialog::getFont(&ok, type->font(), this);
        if(ok == true) {
            type->setFont(font);
        }
    }

    template<typename Type>
    void _Get_Color(Type *type) {
        System::Logging(__FUNCTION__);

        type->setAutoFillBackground(true);
        type->setFlat(true);

        QPalette palette = type->palette();
        QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
        if(color.isValid() == true) {
            palette.setColor(QPalette::Button, color);
            type->setPalette(palette);
        }
    };
};

#endif // Chart_h
