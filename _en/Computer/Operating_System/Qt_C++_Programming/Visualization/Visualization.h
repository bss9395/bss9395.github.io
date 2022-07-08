/* Visualization.h
Author: BSS9395
Update: 2022-07-08T20:00:00+08@China-Shanghai+08
Design: Visualization
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef Visualization_h
#define Visualization_h

#define   Header_h
#include "Common.h"
#include "System.h"
#include "ui_Visualization.h"
using namespace QtDataVisualization;

class Visualization : public QMainWindow {
    Q_OBJECT

public:
    struct : public Enume {
        Enume _CameraPresetNone               = Enume(this, Q3DCamera::CameraPresetNone              , "CameraPresetNone");
        Enume _CameraPresetFrontLow           = Enume(this, Q3DCamera::CameraPresetFrontLow          , "CameraPresetFrontLow");
        Enume _CameraPresetFront              = Enume(this, Q3DCamera::CameraPresetFront             , "CameraPresetFront");
        Enume _CameraPresetFrontHigh          = Enume(this, Q3DCamera::CameraPresetFrontHigh         , "CameraPresetFrontHigh");
        Enume _CameraPresetLeftLow            = Enume(this, Q3DCamera::CameraPresetLeftLow           , "CameraPresetLeftLow");
        Enume _CameraPresetLeft               = Enume(this, Q3DCamera::CameraPresetLeft              , "CameraPresetLeft");
        Enume _CameraPresetLeftHigh           = Enume(this, Q3DCamera::CameraPresetLeftHigh          , "CameraPresetLeftHigh");
        Enume _CameraPresetRightLow           = Enume(this, Q3DCamera::CameraPresetRightLow          , "CameraPresetRightLow");
        Enume _CameraPresetRight              = Enume(this, Q3DCamera::CameraPresetRight             , "CameraPresetRight");
        Enume _CameraPresetRightHigh          = Enume(this, Q3DCamera::CameraPresetRightHigh         , "CameraPresetRightHigh");
        Enume _CameraPresetBehindLow          = Enume(this, Q3DCamera::CameraPresetBehindLow         , "CameraPresetBehindLow");
        Enume _CameraPresetBehind             = Enume(this, Q3DCamera::CameraPresetBehind            , "CameraPresetBehind");
        Enume _CameraPresetBehindHigh         = Enume(this, Q3DCamera::CameraPresetBehindHigh        , "CameraPresetBehindHigh");
        Enume _CameraPresetIsometricLeft      = Enume(this, Q3DCamera::CameraPresetIsometricLeft     , "CameraPresetIsometricLeft");
        Enume _CameraPresetIsometricLeftHigh  = Enume(this, Q3DCamera::CameraPresetIsometricLeftHigh , "CameraPresetIsometricLeftHigh");
        Enume _CameraPresetIsometricRight     = Enume(this, Q3DCamera::CameraPresetIsometricRight    , "CameraPresetIsometricRight");
        Enume _CameraPresetIsometricRightHigh = Enume(this, Q3DCamera::CameraPresetIsometricRightHigh, "CameraPresetIsometricRightHigh");
        Enume _CameraPresetDirectlyAbove      = Enume(this, Q3DCamera::CameraPresetDirectlyAbove     , "CameraPresetDirectlyAbove");
        Enume _CameraPresetDirectlyAboveCW45  = Enume(this, Q3DCamera::CameraPresetDirectlyAboveCW45 , "CameraPresetDirectlyAboveCW45");
        Enume _CameraPresetDirectlyAboveCCW45 = Enume(this, Q3DCamera::CameraPresetDirectlyAboveCCW45, "CameraPresetDirectlyAboveCCW45");
        Enume _CameraPresetFrontBelow         = Enume(this, Q3DCamera::CameraPresetFrontBelow        , "CameraPresetFrontBelow");
        Enume _CameraPresetLeftBelow          = Enume(this, Q3DCamera::CameraPresetLeftBelow         , "CameraPresetLeftBelow");
        Enume _CameraPresetRightBelow         = Enume(this, Q3DCamera::CameraPresetRightBelow        , "CameraPresetRightBelow");
        Enume _CameraPresetBehindBelow        = Enume(this, Q3DCamera::CameraPresetBehindBelow       , "CameraPresetBehindBelow");
        Enume _CameraPresetDirectlyBelow      = Enume(this, Q3DCamera::CameraPresetDirectlyBelow     , "CameraPresetDirectlyBelow");
    } _CameraPreset;

    struct : public Enume {
        Enume _ThemeQt            = Enume(this, Q3DTheme::ThemeQt           , "ThemeQt");
        Enume _ThemePrimaryColors = Enume(this, Q3DTheme::ThemePrimaryColors, "ThemePrimaryColors");
        Enume _ThemeDigia         = Enume(this, Q3DTheme::ThemeDigia        , "ThemeDigia");
        Enume _ThemeStoneMoss     = Enume(this, Q3DTheme::ThemeStoneMoss    , "ThemeStoneMoss");
        Enume _ThemeArmyBlue      = Enume(this, Q3DTheme::ThemeArmyBlue     , "ThemeArmyBlue");
        Enume _ThemeRetro         = Enume(this, Q3DTheme::ThemeRetro        , "ThemeRetro");
        Enume _ThemeEbony         = Enume(this, Q3DTheme::ThemeEbony        , "ThemeEbony");
        Enume _ThemeIsabelle      = Enume(this, Q3DTheme::ThemeIsabelle     , "ThemeIsabelle");
        Enume _ThemeUserDefined   = Enume(this, Q3DTheme::ThemeUserDefined  , "ThemeUserDefined");
    } _Theme;

    struct : public Enume {
        Enume _MeshBar       = Enume(this, QAbstract3DSeries::MeshBar      , "MeshBar");
        Enume _MeshCube      = Enume(this, QAbstract3DSeries::MeshCube     , "MeshCube");
        Enume _MeshPyramid   = Enume(this, QAbstract3DSeries::MeshPyramid  , "MeshPyramid");
        Enume _MeshCone      = Enume(this, QAbstract3DSeries::MeshCone     , "MeshCone");
        Enume _MeshCylinder  = Enume(this, QAbstract3DSeries::MeshCylinder , "MeshCylinder");
        Enume _MeshBevelBar  = Enume(this, QAbstract3DSeries::MeshBevelBar , "MeshBevelBar");
        Enume _MeshBevelCube = Enume(this, QAbstract3DSeries::MeshBevelCube, "MeshBevelCube");
        Enume _MeshSphere    = Enume(this, QAbstract3DSeries::MeshSphere   , "MeshSphere");
        Enume _MeshMinimal   = Enume(this, QAbstract3DSeries::MeshMinimal  , "MeshMinimal");
        Enume _MeshArrow     = Enume(this, QAbstract3DSeries::MeshArrow    , "MeshArrow");
        Enume _MeshPoint     = Enume(this, QAbstract3DSeries::MeshPoint    , "MeshPoint");
    } _Mesh;

    struct : public Enume {
        Enume _SelectionNone                = Enume(this, QAbstract3DGraph::SelectionNone                                            , "None");
        Enume _SelectionItem                = Enume(this, QAbstract3DGraph::SelectionItem                                            , "Item");
        Enume _SelectionRow                 = Enume(this, QAbstract3DGraph::SelectionRow                                             , "Row");
        Enume _SelectionItemAndRow          = Enume(this, QAbstract3DGraph::SelectionItemAndRow                                      , "ItemAndRow");
        Enume _SelectionItemAndRow_Slice    = Enume(this, QAbstract3DGraph::SelectionItemAndRow | QAbstract3DGraph::SelectionSlice   , "ItemAndRow_Slice");
        Enume _SelectionColumn              = Enume(this, QAbstract3DGraph::SelectionColumn                                          , "Column");
        Enume _SelectionItemAndColumn       = Enume(this, QAbstract3DGraph::SelectionItemAndColumn                                   , "ItemAndColumn");
        Enume _SelectionItemAndColumn_Slice = Enume(this, QAbstract3DGraph::SelectionItemAndColumn | QAbstract3DGraph::SelectionSlice, "ItemAndColumn_Slice");
        Enume _SelectionRowAndColumn        = Enume(this, QAbstract3DGraph::SelectionRowAndColumn                                    , "RowAndColumn");
        Enume _SelectionItemRowAndColumn    = Enume(this, QAbstract3DGraph::SelectionItemRowAndColumn                                , "ItemRowAndColumn");
        Enume _SelectionSlice               = Enume(this, QAbstract3DGraph::SelectionSlice                                           , "Slice");
        Enume _SelectionMultiSeries         = Enume(this, QAbstract3DGraph::SelectionMultiSeries                                     , "MultiSeries");
    } _SelectionFlag;

    struct : public Enume {
        Enume _DrawWireframe           = Enume(this, QSurface3DSeries::DrawWireframe          , "DrawWireframe");
        Enume _DrawSurface             = Enume(this, QSurface3DSeries::DrawSurface            , "DrawSurface");
        Enume _DrawSurfaceAndWireframe = Enume(this, QSurface3DSeries::DrawSurfaceAndWireframe, "DrawSurfaceAndWireframe");
    } _DrawFlag;

public:
    Ui::Visualization *_ui  = nullptr;
    QLinearGradient _linear = QLinearGradient();
    Q3DBars    *_bars       = nullptr;
    Q3DScatter *_scatter    = nullptr;
    Q3DSurface *_surface    = nullptr;
    Q3DSurface *_height_map = nullptr;
    QGroupBox *_panel = nullptr;

    iptr  _x_rows = 30;
    iptr  _y_cols = 40;
    qreal _x_min  = -10.0;
    qreal _x_max  = +10.0;
    qreal _x_step = 0.5;
    qreal _y_min  = -10.0;
    qreal _y_max  = +10.0;
    qreal _y_step = 0.5;

public:
    explicit Visualization(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::Visualization) {
        System::Logging(__FUNCTION__);
        _ui->setupUi(this);

        _Setup_Q3DBars();
        _Setup_Q3DBars_Attributes();
        _Setup_Q3DScatter();
        _Setup_Q3DScatter_Attributes();
        _Setup_Q3DSurface();
        _Setup_Q3DSurface_Attributes();
        _Setup_QHeightMap();
        _Setup_QHeightMap_Attributes();

        _ui->TW_Visualization->setCurrentIndex(0);
        _panel = _ui->GB_Q3DBars_Panel;
        _panel->show();
        QObject::connect(_ui->TW_Visualization, &QTabWidget::currentChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->TW_Visualization, &QTabWidget::currentChanged, this, [this](int index) -> void {");

            QString tabtext = _ui->TW_Visualization->tabText(index);
            if(tabtext == "Q3DBars") {
                _panel->hide();
                _panel = _ui->GB_Q3DBars_Panel;
                _panel->show();
            } else if(tabtext == "Q3DScatter") {
                _panel->hide();
                _panel = _ui->GB_Q3DScatter_Panel;
                _panel->show();
            } else if(tabtext == "Q3DSurface") {
                _panel->hide();
                _panel = _ui->GB_Q3DSurface_Panel;
                _panel->show();
            } else if(tabtext == "QHeightMap") {
                _panel->hide();
                _panel = _ui->GB_QHeightMap_Panel;
                _panel->show();
            }
        });
    }

    virtual ~Visualization() {
        System::Logging(__FUNCTION__);
        delete _ui;
    }

public:
    void _Setup_Q3DBars() {
        System::Logging(__FUNCTION__);

        _bars = new Q3DBars();
        _ui->W_Q3DBars->layout()->addWidget(QWidget::createWindowContainer(_bars));

        QBar3DSeries *series = new QBar3DSeries();
        _bars->addSeries(series);
        series->setMesh(QAbstract3DSeries::MeshCylinder);
        series->setItemLabelFormat("[@colLabel, @rowLabel, @valueLabel]");

        QBarDataArray *data = new QBarDataArray();
        series->dataProxy()->resetArray(data);
        data->reserve(_x_rows);
        for(iptr row = 0; row < _x_rows; row += 1) {
            QBarDataRow *datarow = new QBarDataRow();    // note: should be QBarDataColumn
            for(iptr col = 0; col < _y_cols; col += 1) {
                datarow->append((col + 1) * (row + 1));
            }
            data->append(datarow);
        }

        QStringList label_col = QStringList();
        for(iptr col = 0; col < _y_cols; col += 1) {
            label_col.append(QString::asprintf("col%td", col));
        }
        QStringList label_row = QStringList();
        for(iptr row = 0; row < _x_rows; row += 1) {
            label_row.append(QString::asprintf("row%td", row));
        }

        QCategory3DAxis *axisX = new QCategory3DAxis();
        _bars->setColumnAxis(axisX);
        axisX->setTitle("col");
        axisX->setLabels(label_col);
        axisX->setTitleVisible(true);

        QCategory3DAxis *axisY = new QCategory3DAxis();
        _bars->setRowAxis(axisY);
        axisY->setTitle("row");
        axisY->setLabels(label_row);
        axisY->setTitleVisible(true);

        QValue3DAxis *axisZ = new QValue3DAxis();
        _bars->setValueAxis(axisZ);
        axisZ->setTitle("value");
        axisZ->setTitleVisible(true);
    }

    void _Setup_Q3DBars_Attributes() {
        System::Logging(__FUNCTION__);

        _ui->GB_Panel->layout()->addWidget(_ui->GB_Q3DBars_Panel);
        _ui->GB_Q3DBars_Panel->hide();

        _ui->CB_Q3DBars_Camera->addItems(_CameraPreset._Aliases());
        _ui->CB_Q3DBars_Theme->addItems(_Theme._Aliases());
        _ui->CB_Q3DBars_Style->addItems(_Mesh._Aliases());
        _ui->CB_Q3DBars_Select->addItems(_SelectionFlag._Aliases());

        ////////////////////////////////

        _ui->CB_Q3DBars_Camera->setCurrentIndex(_CameraPreset._CameraPresetFrontHigh._index);
        _bars->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[_ui->CB_Q3DBars_Camera->currentIndex()]._enume);

        _ui->S_Q3DBars_Rotate_Z->setRange(-180, +180);
        _ui->S_Q3DBars_Rotate_Z->setSingleStep(1);
        _ui->S_Q3DBars_Rotate_Z->setValue(_bars->scene()->activeCamera()->xRotation());
        _bars->scene()->activeCamera()->setXRotation(_ui->S_Q3DBars_Rotate_Z->value());

        _ui->S_Q3DBars_Rotate_X->setRange(-360, +360);
        _ui->S_Q3DBars_Rotate_X->setSingleStep(1);
        _ui->S_Q3DBars_Rotate_X->setValue(_bars->scene()->activeCamera()->yRotation());
        _bars->scene()->activeCamera()->setYRotation(_ui->S_Q3DBars_Rotate_X->value());

        _ui->S_Q3DBars_Zoom->setRange(20, 500);
        _ui->S_Q3DBars_Zoom->setSingleStep(1);
        _bars->scene()->activeCamera()->setZoomLevel(100.0);
        _ui->S_Q3DBars_Zoom->setValue(_bars->scene()->activeCamera()->zoomLevel());

        _ui->CB_Q3DBars_Theme->setCurrentIndex(_Theme._Alias(_bars->activeTheme()->type()));
        _ui->CB_Q3DBars_Style->setCurrentIndex(_Mesh._Alias(_bars->seriesList().at(0)->mesh()));
        _ui->CB_Q3DBars_Select->setCurrentIndex(_SelectionFlag._Alias(_bars->selectionMode()));

        _ui->PB_Q3DBars_Font->setFont(_bars->activeTheme()->font());

        _ui->PB_Q3DBars_Color->setAutoFillBackground(true);
        _ui->PB_Q3DBars_Color->setFlat(true);
        QPalette palette = _ui->PB_Q3DBars_Color->palette();
        palette.setColor(QPalette::Button, _bars->seriesList().at(0)->baseColor());
        _ui->PB_Q3DBars_Color->setPalette(palette);

        _ui->CB_Q3DBars_Background->setChecked(_bars->activeTheme()->isBackgroundEnabled());
        _ui->CB_Q3DBars_Grid->setChecked(_bars->activeTheme()->isGridEnabled());
        _ui->CB_Q3DBars_Reflection->setChecked(_bars->isReflection());
        _ui->CB_Q3DBars_Shadow->setChecked(_bars->shadowQuality() == QAbstract3DGraph::ShadowQualityNone);
        _ui->CB_Q3DBars_Item_Label->setChecked(_bars->seriesList().at(0)->isItemLabelVisible());
        _ui->CB_Q3DBars_Axis_Title->setChecked(_bars->columnAxis()->isTitleVisible() && _bars->rowAxis()->isTitleVisible() && _bars->valueAxis()->isTitleVisible());
        _ui->CB_Q3DBars_Axis_Background->setChecked(_bars->activeTheme()->isLabelBackgroundEnabled());
        _ui->CB_Q3DBars_Smooth->setChecked(_bars->seriesList().at(0)->isMeshSmooth());

        ////////////////////////////////

        QObject::connect(_ui->CB_Q3DBars_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            _bars->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[index]._enume);
        });

        QObject::connect(_ui->S_Q3DBars_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {");

            _bars->scene()->activeCamera()->setXRotation(value);
        });

        QObject::connect(_ui->S_Q3DBars_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Rotate_Y, &QSlider::valueChanged, this, [this](int value) -> void {");

            _bars->scene()->activeCamera()->setYRotation(value);
        });

        QObject::connect(_ui->S_Q3DBars_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {");

            _bars->scene()->activeCamera()->setZoomLevel(value);
        });

        QObject::connect(_ui->CB_Q3DBars_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _bars->activeTheme()->setType((Q3DTheme::Theme)_Theme[value]._enume);
        });

        QObject::connect(_ui->CB_Q3DBars_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _bars->seriesList().at(0)->setMesh((QAbstract3DSeries::Mesh)_Mesh[value]._enume);
        });

        QObject::connect(_ui->CB_Q3DBars_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _bars->setSelectionMode((QAbstract3DGraph::SelectionFlag)_SelectionFlag[value]._enume);
        });

        QObject::connect(_ui->PB_Q3DBars_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Font, &QPushButton::clicked, this, [this]() -> void {");

            bool ok = false;
            QFont font = QFontDialog::getFont(&ok, _ui->PB_Q3DBars_Font->font(), this);
            if(ok == true) {
                _ui->PB_Q3DBars_Font->setFont(font);
                _bars->activeTheme()->setFont(font);
            }
        });

        QObject::connect(_ui->PB_Q3DBars_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Color, &QPushButton::clicked, this, [this]() -> void {");

            QPalette palette = _ui->PB_Q3DBars_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
                _ui->PB_Q3DBars_Color->setPalette(palette);
                _bars->seriesList().at(0)->setBaseColor(color);
            }
        });

        QObject::connect(_ui->CB_Q3DBars_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->activeTheme()->setBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DBars_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->activeTheme()->setGridEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DBars_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->setReflection(checked);
        });

        QObject::connect(_ui->CB_Q3DBars_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            QAbstract3DGraph::ShadowQuality shadow = checked ? QAbstract3DGraph::ShadowQualityMedium : QAbstract3DGraph::ShadowQualityNone;
            _bars->setShadowQuality(shadow);
        });

        QObject::connect(_ui->CB_Q3DBars_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->seriesList().at(0)->setItemLabelVisible(checked);
        });

        QObject::connect(_ui->CB_Q3DBars_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->columnAxis()->setTitleVisible(checked);
            _bars->rowAxis()->setTitleVisible(checked);
            _bars->valueAxis()->setTitleVisible(checked);
        });

        QObject::connect(_ui->CB_Q3DBars_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->activeTheme()->setLabelBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DBars_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _bars->seriesList().at(0)->setMeshSmooth(checked);
        });
    }

////////////////////////////////////////////////////////////////////////////////

    void _Setup_Q3DScatter() {
        System::Logging(__FUNCTION__);

        _scatter = new Q3DScatter();
        _ui->W_Q3DScatter->layout()->addWidget(QWidget::createWindowContainer(_scatter));

        QScatter3DSeries *series = new QScatter3DSeries();
        _scatter->addSeries(series);
        series->setMesh(QAbstract3DSeries::MeshSphere);
        series->setItemLabelFormat("[@xLabel, @yLabel, @zLabel]");
        series->setMeshSmooth(true);
        series->setItemSize(0.1);

        QScatterDataArray *data = new QScatterDataArray();
        iptr cols = (iptr)((_x_max - _x_min) / _x_step + 1);
        iptr rows = (iptr)((_y_max - _y_min) / _y_step + 1);
        data->reserve((cols + 1) * (rows + 1));
        for(qreal x = _x_min; x <= _x_max; x += _x_step) {
            for(qreal y = _y_min; y <= _y_max; y += _y_step) {
                qreal z = qSqrt(x * x + y * y);
                data->append(QVector3D(x, z, y));  // note: should be data->append(QVector3D(x, y, z));
            }
        }
        series->dataProxy()->resetArray(data);

        _scatter->axisX()->setTitle("X");
        _scatter->axisX()->setTitleVisible(true);
        _scatter->axisY()->setTitle("Z");          // note: should be _scatter->axisY()->setTitle("Y");
        _scatter->axisY()->setTitleVisible(true);
        _scatter->axisZ()->setTitle("Y");          // note: should be _scatter->axisZ()->setTitle("Z");
        _scatter->axisZ()->setTitleVisible(true);
        _scatter->activeTheme()->setLabelBackgroundEnabled(false);
    }

    void _Setup_Q3DScatter_Attributes() {
        System::Logging(__FUNCTION__);

        _ui->GB_Panel->layout()->addWidget(_ui->GB_Q3DScatter_Panel);
        _ui->GB_Q3DScatter_Panel->hide();

        _ui->CB_Q3DScatter_Camera->addItems(_CameraPreset._Aliases());
        _ui->CB_Q3DScatter_Theme->addItems(_Theme._Aliases());
        _ui->CB_Q3DScatter_Style->addItems(_Mesh._Aliases());
        _ui->CB_Q3DScatter_Select->addItems(_SelectionFlag._Aliases());

        ////////////////////////////////

        _ui->CB_Q3DScatter_Camera->setCurrentIndex(_CameraPreset._CameraPresetFrontHigh._index);
        _scatter->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[_ui->CB_Q3DScatter_Camera->currentIndex()]._enume);

        _ui->S_Q3DScatter_Rotate_Z->setRange(-180, +180);
        _ui->S_Q3DScatter_Rotate_Z->setSingleStep(1);
        _ui->S_Q3DScatter_Rotate_Z->setValue(_scatter->scene()->activeCamera()->xRotation());
        _scatter->scene()->activeCamera()->setXRotation(_ui->S_Q3DScatter_Rotate_Z->value());

        _ui->S_Q3DScatter_Rotate_X->setRange(-360, +360);
        _ui->S_Q3DScatter_Rotate_X->setSingleStep(1);
        _ui->S_Q3DScatter_Rotate_X->setValue(_scatter->scene()->activeCamera()->yRotation());
        _scatter->scene()->activeCamera()->setYRotation(_ui->S_Q3DScatter_Rotate_X->value());

        _ui->S_Q3DScatter_Zoom->setRange(20, 500);
        _ui->S_Q3DScatter_Zoom->setSingleStep(1);
        _scatter->scene()->activeCamera()->setZoomLevel(100.0);
        _ui->S_Q3DScatter_Zoom->setValue(_scatter->scene()->activeCamera()->zoomLevel());

        _ui->CB_Q3DScatter_Theme->setCurrentIndex(_Theme._Alias(_scatter->activeTheme()->type()));
        _ui->CB_Q3DScatter_Style->setCurrentIndex(_Mesh._Alias(_scatter->seriesList().at(0)->mesh()));
        _ui->CB_Q3DScatter_Select->setCurrentIndex(_SelectionFlag._Alias(_scatter->selectionMode()));

        _ui->DSB_Q3DScatter_Size->setRange(0.0, 1.0);
        _ui->DSB_Q3DScatter_Size->setSingleStep(0.01);
        _ui->DSB_Q3DScatter_Size->setValue(_scatter->seriesList().at(0)->itemSize());

        _ui->PB_Q3DScatter_Font->setFont(_scatter->activeTheme()->font());

        _ui->PB_Q3DScatter_Color->setAutoFillBackground(true);
        _ui->PB_Q3DScatter_Color->setFlat(true);
        QPalette palette = _ui->PB_Q3DScatter_Color->palette();
        palette.setColor(QPalette::Button, _scatter->seriesList().at(0)->baseColor());
        _ui->PB_Q3DScatter_Color->setPalette(palette);

        _ui->CB_Q3DScatter_Background->setChecked(_scatter->activeTheme()->isBackgroundEnabled());
        _ui->CB_Q3DScatter_Grid->setChecked(_scatter->activeTheme()->isGridEnabled());
        _ui->CB_Q3DScatter_Reflection->setChecked(_scatter->isReflection());
        _ui->CB_Q3DScatter_Shadow->setChecked(_scatter->shadowQuality() != QAbstract3DGraph::ShadowQualityNone);
        _ui->CB_Q3DScatter_Item_Label->setChecked(_scatter->seriesList().at(0)->isItemLabelVisible());
        _ui->CB_Q3DScatter_Axis_Title->setChecked(_scatter->axisX()->isTitleVisible() && _scatter->axisY()->isTitleVisible() && _scatter->axisZ()->isTitleVisible());
        _ui->CB_Q3DScatter_Axis_Background->setChecked(_scatter->activeTheme()->isLabelBackgroundEnabled());
        _ui->CB_Q3DScatter_Smooth->setChecked(_scatter->seriesList().at(0)->isMeshSmooth());

        ////////////////////////////////

        QObject::connect(_ui->CB_Q3DScatter_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            _scatter->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[index]._enume);
        });

        QObject::connect(_ui->S_Q3DScatter_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Q3DScatter_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {");

            _scatter->scene()->activeCamera()->setXRotation(value);
        });

        QObject::connect(_ui->S_Q3DScatter_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Q3DScatter_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {");

            _scatter->scene()->activeCamera()->setYRotation(value);
        });

        QObject::connect(_ui->S_Q3DScatter_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Q3DScatter_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {");

            _scatter->scene()->activeCamera()->setZoomLevel(value);
        });

        QObject::connect(_ui->CB_Q3DScatter_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _scatter->activeTheme()->setType((Q3DTheme::Theme)_Theme[value]._enume);
        });

        QObject::connect(_ui->CB_Q3DScatter_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _scatter->seriesList().at(0)->setMesh((QAbstract3DSeries::Mesh)_Mesh[value]._enume);
        });

        QObject::connect(_ui->CB_Q3DScatter_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _scatter->setSelectionMode((QAbstract3DGraph::SelectionFlag)_SelectionFlag[value]._enume);       // note: only none and item selection modes are supported.
        });

        QObject::connect(_ui->DSB_Q3DScatter_Size, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double value) -> void {
            System::Logging("QObject::connect(_ui->DSB_Q3DScatter_Size, (void (QDoubleSpinBox::*)(double))&QDoubleSpinBox::valueChanged, this, [this](double value) -> void {");

            _scatter->seriesList().at(0)->setItemSize(value);
        });

        QObject::connect(_ui->PB_Q3DScatter_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Q3DScatter_Font, &QPushButton::clicked, this, [this]() -> void {");

            bool ok = false;
            QFont font = QFontDialog::getFont(&ok, _ui->PB_Q3DScatter_Font->font(), this);
            if(ok == true) {
                _ui->PB_Q3DScatter_Font->setFont(font);
                _scatter->activeTheme()->setFont(font);
            }
        });

        QObject::connect(_ui->PB_Q3DScatter_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Q3DScatter_Color, &QPushButton::clicked, this, [this]() -> void {");

            QPalette palette = _ui->PB_Q3DScatter_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
                _ui->PB_Q3DScatter_Color->setPalette(palette);
                _scatter->seriesList().at(0)->setBaseColor(color);
            }
        });

        QObject::connect(_ui->CB_Q3DScatter_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->activeTheme()->setBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DScatter_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->activeTheme()->setGridEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DScatter_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->setReflection(checked);      // note: no effect.
        });

        QObject::connect(_ui->CB_Q3DScatter_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            QAbstract3DGraph::ShadowQuality shadow = checked ? QAbstract3DGraph::ShadowQualityMedium : QAbstract3DGraph::ShadowQualityNone;
            _scatter->setShadowQuality(shadow);
        });

        QObject::connect(_ui->CB_Q3DScatter_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->seriesList().at(0)->setItemLabelVisible(checked);
        });

        QObject::connect(_ui->CB_Q3DScatter_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->axisX()->setTitleVisible(checked);
            _scatter->axisY()->setTitleVisible(checked);
            _scatter->axisZ()->setTitleVisible(checked);
        });

        QObject::connect(_ui->CB_Q3DScatter_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->activeTheme()->setLabelBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DScatter_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DScatter_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _scatter->seriesList().at(0)->setMeshSmooth(checked);
        });
    }

////////////////////////////////////////////////////////////////////////////////

    void _Setup_Q3DSurface() {
        System::Logging(__FUNCTION__);

        _surface = new Q3DSurface();
        _ui->W_Q3DSurface->layout()->addWidget(QWidget::createWindowContainer(_surface));

        QSurface3DSeries *series = new QSurface3DSeries();
        _surface->addSeries(series);
        series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
        series->setItemLabelFormat("[@xLabel, @yLabel, @zLabel]");
        series->setMeshSmooth(true);

        QSurfaceDataArray *data = new QSurfaceDataArray();
        for(qreal y = _y_min; y <= _y_max; y += _y_step) {
            QSurfaceDataRow *datarow = new QSurfaceDataRow();
            for(qreal x = _x_min; x <= _x_max; x += _x_step) {
                qreal z = qSqrt(x * x + y * y);
                datarow->append(QVector3D(x, z, y));
            }
            data->append(datarow);
        }
        series->dataProxy()->resetArray(data);

        QValue3DAxis *axisX = new QValue3DAxis();
        _surface->setAxisX(axisX);
        axisX->setTitle("X");
        axisX->setTitleVisible(true);

        QValue3DAxis *axisY = new QValue3DAxis();
        _surface->setAxisY(axisY);
        axisY->setTitle("Z");
        axisY->setTitleVisible(true);

        QValue3DAxis *axisZ = new QValue3DAxis();
        _surface->setAxisZ(axisZ);
        axisZ->setTitle("Y");
        axisZ->setTitleVisible(true);
    }

    void _Setup_Q3DSurface_Attributes() {
        System::Logging(__FUNCTION__);

        _ui->GB_Panel->layout()->addWidget(_ui->GB_Q3DSurface_Panel);
        _ui->GB_Q3DSurface_Panel->hide();

        _ui->CB_Q3DSurface_Camera->addItems(_CameraPreset._Aliases());
        _ui->CB_Q3DSurface_Theme->addItems(_Theme._Aliases());
        // _ui->CB_Q3DSurface_Style->addItems(_Mesh._Aliases());
        _ui->CB_Q3DSurface_Style->addItems(_DrawFlag._Aliases());
        _ui->CB_Q3DSurface_Select->addItems(_SelectionFlag._Aliases());

        QSize size = QSize(_ui->PB_Q3DSurface_Gradient->width() - 12, _ui->PB_Q3DSurface_Gradient->height() - 12);
        _linear = QLinearGradient(0, 0, size.width(), 0);
        _linear.setColorAt(0.0, Qt::white);
        _linear.setColorAt(0.2, Qt::red);
        _linear.setColorAt(0.4, Qt::yellow);
        _linear.setColorAt(0.6, Qt::green);
        _linear.setColorAt(0.8, Qt::cyan);
        _linear.setColorAt(1.0, Qt::blue);
        QPixmap pixmap = QPixmap(size.width(), size.height());
        QPainter painter = QPainter(&pixmap);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(_linear));
        painter.drawRect(0, 0, size.width(), size.height());
        _ui->PB_Q3DSurface_Gradient->setIcon(pixmap);
        _ui->PB_Q3DSurface_Gradient->setIconSize(size);

        ////////////////////////////////

        _ui->CB_Q3DSurface_Camera->setCurrentIndex(_CameraPreset._CameraPresetFrontHigh._index);
        _surface->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[_ui->CB_Q3DSurface_Camera->currentIndex()]._enume);

        _ui->S_Q3DSurface_Rotate_Z->setRange(-180, +180);
        _ui->S_Q3DSurface_Rotate_Z->setSingleStep(1);
        _ui->S_Q3DSurface_Rotate_Z->setValue(_surface->scene()->activeCamera()->xRotation());
        _surface->scene()->activeCamera()->setXRotation(_ui->S_Q3DSurface_Rotate_Z->value());

        _ui->S_Q3DSurface_Rotate_X->setRange(-360, +360);
        _ui->S_Q3DSurface_Rotate_X->setSingleStep(1);
        _ui->S_Q3DSurface_Rotate_X->setValue(_surface->scene()->activeCamera()->yRotation());
        _surface->scene()->activeCamera()->setYRotation(_ui->S_Q3DSurface_Rotate_X->value());

        _ui->S_Q3DSurface_Zoom->setRange(20, 500);
        _ui->S_Q3DSurface_Zoom->setSingleStep(1);
        _surface->scene()->activeCamera()->setZoomLevel(100.0);
        _ui->S_Q3DSurface_Zoom->setValue(_surface->scene()->activeCamera()->zoomLevel());

        _ui->CB_Q3DSurface_Theme->setCurrentIndex(_Theme._Alias(_surface->activeTheme()->type()));
        // _ui->CB_Q3DSurface_Style->setCurrentIndex(_Mesh._Alias(_surface->seriesList().at(0)->mesh()));
        _ui->CB_Q3DScatter_Style->setCurrentIndex(_DrawFlag._Alias(_surface->seriesList().at(0)->drawMode()));
        _ui->CB_Q3DSurface_Select->setCurrentIndex(_SelectionFlag._Alias(_surface->selectionMode()));

        _ui->PB_Q3DSurface_Font->setFont(_surface->activeTheme()->font());

        _ui->PB_Q3DSurface_Color->setAutoFillBackground(true);
        _ui->PB_Q3DSurface_Color->setFlat(true);
        QPalette palette = _ui->PB_Q3DSurface_Color->palette();
        palette.setColor(QPalette::Button, _surface->seriesList().at(0)->baseColor());
        _ui->PB_Q3DSurface_Color->setPalette(palette);

        _ui->CB_Q3DSurface_Background->setChecked(_surface->activeTheme()->isBackgroundEnabled());
        _ui->CB_Q3DSurface_Grid->setChecked(_surface->activeTheme()->isGridEnabled());
        _ui->CB_Q3DSurface_Reflection->setChecked(_surface->isReflection());
        _ui->CB_Q3DSurface_Shadow->setChecked(_surface->shadowQuality() != QAbstract3DGraph::ShadowQualityNone);
        _ui->CB_Q3DSurface_Item_Label->setChecked(_surface->seriesList().at(0)->isItemLabelVisible());
        _ui->CB_Q3DSurface_Axis_Title->setChecked(_surface->axisX()->isTitleVisible() && _surface->axisY()->isTitleVisible() && _surface->axisZ()->isTitleVisible());
        _ui->CB_Q3DSurface_Axis_Background->setChecked(_surface->activeTheme()->isLabelBackgroundEnabled());
        _ui->CB_Q3DSurface_Smooth->setChecked(_surface->seriesList().at(0)->isMeshSmooth());

        ////////////////////////////////

        QObject::connect(_ui->CB_Q3DSurface_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            _surface->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[index]._enume);
        });

        QObject::connect(_ui->S_Q3DSurface_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Q3DSurface_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {");

            _surface->scene()->activeCamera()->setXRotation(value);
        });

        QObject::connect(_ui->S_Q3DSurface_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Q3DSurface_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {");

            _surface->scene()->activeCamera()->setYRotation(value);
        });

        QObject::connect(_ui->S_Q3DSurface_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_Q3DSurface_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {");

            _surface->scene()->activeCamera()->setZoomLevel(value);
        });

        QObject::connect(_ui->CB_Q3DSurface_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _surface->activeTheme()->setType((Q3DTheme::Theme)_Theme[value]._enume);
        });

        QObject::connect(_ui->CB_Q3DSurface_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            // _surface->seriesList().at(0)->setMesh((QAbstract3DSeries::Mesh)_Mesh[value]._enume);
            _surface->seriesList().at(0)->setDrawMode((QSurface3DSeries::DrawFlag)_DrawFlag[value]._enume);
        });

        QObject::connect(_ui->CB_Q3DSurface_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _surface->setSelectionMode((QAbstract3DGraph::SelectionFlag)_SelectionFlag[value]._enume);       // note: only none and item selection modes are supported.
        });

        QObject::connect(_ui->PB_Q3DSurface_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Q3DSurface_Font, &QPushButton::clicked, this, [this]() -> void {");

            bool ok = false;
            QFont font = QFontDialog::getFont(&ok, _ui->PB_Q3DSurface_Font->font(), this);
            if(ok == true) {
                _ui->PB_Q3DSurface_Font->setFont(font);
                _surface->activeTheme()->setFont(font);
            }
        });

        QObject::connect(_ui->PB_Q3DSurface_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Q3DSurface_Color, &QPushButton::clicked, this, [this]() -> void {");

            _ui->PB_Q3DSurface_Color->setAutoFillBackground(true);
            _ui->PB_Q3DSurface_Color->setFlat(true);
            QPalette palette = _ui->PB_Q3DSurface_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
                _ui->PB_Q3DSurface_Color->setPalette(palette);
                _surface->seriesList().at(0)->setBaseColor(color);
                _surface->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleUniform);
            }
        });

        QObject::connect(_ui->PB_Q3DSurface_Gradient, &QCheckBox::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Q3DSurface_Gradient, &QCheckBox::clicked, this, [this]() -> void {");

            _surface->seriesList().at(0)->setBaseGradient(_linear);
            _surface->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
        });

        QObject::connect(_ui->CB_Q3DSurface_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->activeTheme()->setBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DSurface_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->activeTheme()->setGridEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DSurface_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->setReflection(checked);      // note: no effect.
        });

        QObject::connect(_ui->CB_Q3DSurface_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            QAbstract3DGraph::ShadowQuality shadow = checked ? QAbstract3DGraph::ShadowQualityMedium : QAbstract3DGraph::ShadowQualityNone;
            _surface->setShadowQuality(shadow);
        });

        QObject::connect(_ui->CB_Q3DSurface_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->seriesList().at(0)->setItemLabelVisible(checked);
        });

        QObject::connect(_ui->CB_Q3DSurface_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->axisX()->setTitleVisible(checked);
            _surface->axisY()->setTitleVisible(checked);
            _surface->axisZ()->setTitleVisible(checked);
        });

        QObject::connect(_ui->CB_Q3DSurface_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->activeTheme()->setLabelBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_Q3DSurface_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_Q3DSurface_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _surface->seriesList().at(0)->setMeshSmooth(checked);  // note: no effect.
        });
    }

////////////////////////////////////////////////////////////////////////////////

    void _Setup_QHeightMap() {
        System::Logging(__FUNCTION__);

        _height_map = new Q3DSurface();
        _ui->W_QHeightMap->layout()->addWidget(QWidget::createWindowContainer(_height_map));


        QImage height_map = QImage(":/images/data/mountain.png");
        // QImage height_map = QImage(":/images/data/sea.png");
        // QImage height_map = QImage(":/images/data/sea_gray.png");
        QSurface3DSeries *series = new QSurface3DSeries(new QHeightMapSurfaceDataProxy(height_map));
        _height_map->addSeries(series);
        series->setDrawMode(QSurface3DSeries::DrawSurface);
        series->setItemLabelFormat("[@xLabel, @yLabel, @zLabel]");
        series->setFlatShadingEnabled(false);
        series->setMeshSmooth(true);


        QValue3DAxis *axisX = new QValue3DAxis();
        _height_map->setAxisX(axisX);
        axisX->setTitle("东--西");
        axisX->setTitleVisible(true);
        axisX->setLabelFormat("%.1f /m");
        // axisX->setRange();

        QValue3DAxis *axisY = new QValue3DAxis();
        _height_map->setAxisY(axisY);
        axisY->setTitle("深度");
        axisY->setTitleVisible(true);
        //axisY->setAutoAdjustRange(true);

        QValue3DAxis *axisZ = new QValue3DAxis();
        _height_map->setAxisZ(axisZ);
        axisZ->setTitle("南--北");
        axisZ->setTitleVisible(true);
        axisZ->setLabelFormat("%.1f /m");

        _height_map->activeTheme()->setLabelBorderEnabled(false);
    }

    void _Setup_QHeightMap_Attributes() {
        System::Logging(__FUNCTION__);

        _ui->GB_Panel->layout()->addWidget(_ui->GB_QHeightMap_Panel);
        _ui->GB_QHeightMap_Panel->hide();

        _ui->CB_QHeightMap_Camera->addItems(_CameraPreset._Aliases());
        _ui->CB_QHeightMap_Theme->addItems(_Theme._Aliases());
        // _ui->CB_QHeightMap_Style->addItems(_Mesh._Aliases());
        _ui->CB_QHeightMap_Style->addItems(_DrawFlag._Aliases());
        _ui->CB_QHeightMap_Select->addItems(_SelectionFlag._Aliases());

        QSize size = QSize(_ui->PB_QHeightMap_Gradient->width() - 12, _ui->PB_QHeightMap_Gradient->height() - 12);
        _linear = QLinearGradient(0, 0, size.width(), 0);
        _linear.setColorAt(0.0, Qt::white);
        _linear.setColorAt(0.2, Qt::red);
        _linear.setColorAt(0.4, Qt::yellow);
        _linear.setColorAt(0.6, Qt::green);
        _linear.setColorAt(0.8, Qt::cyan);
        _linear.setColorAt(1.0, Qt::blue);
        QPixmap pixmap = QPixmap(size.width(), size.height());
        QPainter painter = QPainter(&pixmap);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(_linear));
        painter.drawRect(0, 0, size.width(), size.height());
        _ui->PB_QHeightMap_Gradient->setIcon(pixmap);
        _ui->PB_QHeightMap_Gradient->setIconSize(size);

        ////////////////////////////////

        _ui->CB_QHeightMap_Camera->setCurrentIndex(_CameraPreset._CameraPresetFrontHigh._index);
        _height_map->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[_ui->CB_QHeightMap_Camera->currentIndex()]._enume);

        _ui->S_QHeightMap_Rotate_Z->setRange(-180, +180);
        _ui->S_QHeightMap_Rotate_Z->setSingleStep(1);
        _ui->S_QHeightMap_Rotate_Z->setValue(_height_map->scene()->activeCamera()->xRotation());
        _height_map->scene()->activeCamera()->setXRotation(_ui->S_QHeightMap_Rotate_Z->value());

        _ui->S_QHeightMap_Rotate_X->setRange(-360, +360);
        _ui->S_QHeightMap_Rotate_X->setSingleStep(1);
        _ui->S_QHeightMap_Rotate_X->setValue(_height_map->scene()->activeCamera()->yRotation());
        _height_map->scene()->activeCamera()->setYRotation(_ui->S_QHeightMap_Rotate_X->value());

        _ui->S_QHeightMap_Zoom->setRange(20, 500);
        _ui->S_QHeightMap_Zoom->setSingleStep(1);
        _height_map->scene()->activeCamera()->setZoomLevel(100.0);
        _ui->S_QHeightMap_Zoom->setValue(_height_map->scene()->activeCamera()->zoomLevel());

        _ui->CB_QHeightMap_Theme->setCurrentIndex(_Theme._Alias(_height_map->activeTheme()->type()));
        // _ui->CB_QHeightMap_Style->setCurrentIndex(_Mesh._Alias(_surface->seriesList().at(0)->mesh()));
        _ui->CB_Q3DScatter_Style->setCurrentIndex(_DrawFlag._Alias(_height_map->seriesList().at(0)->drawMode()));
        _ui->CB_QHeightMap_Select->setCurrentIndex(_SelectionFlag._Alias(_height_map->selectionMode()));

        _ui->PB_QHeightMap_Font->setFont(_height_map->activeTheme()->font());

        _ui->PB_QHeightMap_Color->setAutoFillBackground(true);
        _ui->PB_QHeightMap_Color->setFlat(true);
        QPalette palette = _ui->PB_QHeightMap_Color->palette();
        palette.setColor(QPalette::Button, _height_map->seriesList().at(0)->baseColor());
        _ui->PB_QHeightMap_Color->setPalette(palette);

        _ui->CB_QHeightMap_Background->setChecked(_height_map->activeTheme()->isBackgroundEnabled());
        _ui->CB_QHeightMap_Grid->setChecked(_height_map->activeTheme()->isGridEnabled());
        _ui->CB_QHeightMap_Reflection->setChecked(_height_map->isReflection());
        _ui->CB_QHeightMap_Shadow->setChecked(_height_map->shadowQuality() != QAbstract3DGraph::ShadowQualityNone);
        _ui->CB_QHeightMap_Item_Label->setChecked(_height_map->seriesList().at(0)->isItemLabelVisible());
        _ui->CB_QHeightMap_Axis_Title->setChecked(_height_map->axisX()->isTitleVisible() && _height_map->axisY()->isTitleVisible() && _height_map->axisZ()->isTitleVisible());
        _ui->CB_QHeightMap_Axis_Background->setChecked(_height_map->activeTheme()->isLabelBackgroundEnabled());
        _ui->CB_QHeightMap_Smooth->setChecked(_height_map->seriesList().at(0)->isMeshSmooth());

        ////////////////////////////////

        QObject::connect(_ui->CB_QHeightMap_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Camera, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int index) -> void {");

            _height_map->scene()->activeCamera()->setCameraPreset((Q3DCamera::CameraPreset)_CameraPreset[index]._enume);
        });

        QObject::connect(_ui->S_QHeightMap_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_QHeightMap_Rotate_Z, &QSlider::valueChanged, this, [this](int value) -> void {");

            _height_map->scene()->activeCamera()->setXRotation(value);
        });

        QObject::connect(_ui->S_QHeightMap_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_QHeightMap_Rotate_X, &QSlider::valueChanged, this, [this](int value) -> void {");

            _height_map->scene()->activeCamera()->setYRotation(value);
        });

        QObject::connect(_ui->S_QHeightMap_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->S_QHeightMap_Zoom, &QSlider::valueChanged, this, [this](int value) -> void {");

            _height_map->scene()->activeCamera()->setZoomLevel(value);
        });

        QObject::connect(_ui->CB_QHeightMap_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Theme, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _height_map->activeTheme()->setType((Q3DTheme::Theme)_Theme[value]._enume);
        });

        QObject::connect(_ui->CB_QHeightMap_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Style, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            // _surface->seriesList().at(0)->setMesh((QAbstract3DSeries::Mesh)_Mesh[value]._enume);
            _height_map->seriesList().at(0)->setDrawMode((QSurface3DSeries::DrawFlag)_DrawFlag[value]._enume);
        });

        QObject::connect(_ui->CB_QHeightMap_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Select, (void (QComboBox::*)(int))&QComboBox::currentIndexChanged, this, [this](int value) -> void {");

            _height_map->setSelectionMode((QAbstract3DGraph::SelectionFlag)_SelectionFlag[value]._enume);       // note: only none and item selection modes are supported.
        });

        QObject::connect(_ui->PB_QHeightMap_Font, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QHeightMap_Font, &QPushButton::clicked, this, [this]() -> void {");

            bool ok = false;
            QFont font = QFontDialog::getFont(&ok, _ui->PB_QHeightMap_Font->font(), this);
            if(ok == true) {
                _ui->PB_QHeightMap_Font->setFont(font);
                _height_map->activeTheme()->setFont(font);
            }
        });

        QObject::connect(_ui->PB_QHeightMap_Color, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QHeightMap_Color, &QPushButton::clicked, this, [this]() -> void {");

            _ui->PB_QHeightMap_Color->setAutoFillBackground(true);
            _ui->PB_QHeightMap_Color->setFlat(true);
            QPalette palette = _ui->PB_QHeightMap_Color->palette();
            QColor color = QColorDialog::getColor(palette.color(QPalette::Button), this, "请选择颜色");
            if(color.isValid() == true) {
                palette.setColor(QPalette::Button, color);
                _ui->PB_QHeightMap_Color->setPalette(palette);
                _height_map->seriesList().at(0)->setBaseColor(color);
                _height_map->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleUniform);
            }
        });

        QObject::connect(_ui->PB_QHeightMap_Gradient, &QCheckBox::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QHeightMap_Gradient, &QCheckBox::clicked, this, [this]() -> void {");

            _height_map->seriesList().at(0)->setBaseGradient(_linear);
            _height_map->seriesList().at(0)->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
        });

        QObject::connect(_ui->CB_QHeightMap_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->activeTheme()->setBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_QHeightMap_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Grid, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->activeTheme()->setGridEnabled(checked);
        });

        QObject::connect(_ui->CB_QHeightMap_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Reflection, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->setReflection(checked);      // note: no effect.
        });

        QObject::connect(_ui->CB_QHeightMap_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Shadow, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            QAbstract3DGraph::ShadowQuality shadow = checked ? QAbstract3DGraph::ShadowQualityMedium : QAbstract3DGraph::ShadowQualityNone;
            _height_map->setShadowQuality(shadow);
        });

        QObject::connect(_ui->CB_QHeightMap_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Item_Label, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->seriesList().at(0)->setItemLabelVisible(checked);
        });

        QObject::connect(_ui->CB_QHeightMap_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Axis_Title, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->axisX()->setTitleVisible(checked);
            _height_map->axisY()->setTitleVisible(checked);
            _height_map->axisZ()->setTitleVisible(checked);
        });

        QObject::connect(_ui->CB_QHeightMap_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Axis_Background, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->activeTheme()->setLabelBackgroundEnabled(checked);
        });

        QObject::connect(_ui->CB_QHeightMap_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {
            System::Logging("QObject::connect(_ui->CB_QHeightMap_Smooth, &QCheckBox::clicked, this, [this](bool checked) -> void {");

            _height_map->seriesList().at(0)->setMeshSmooth(checked);  // note: no effect.
        });
    }
};

#endif // Visualization_h
