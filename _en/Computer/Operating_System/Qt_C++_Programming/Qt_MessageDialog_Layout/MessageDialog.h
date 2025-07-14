#pragma once

#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QDebug>
#include <QDialog>
#include <QFontDatabase>
#include <QFontInfo>
#include <QFontMetrics>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QGuiApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QRadioButton>
#include <QRegularExpression>
#include <QScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QStyle>
#include <QTimer>
#include <QWindow>
#include "HWidget.h"
#include "VWidget.h"
#include "FHWidget.h"

class MessageDialog : public QDialog {
    Q_OBJECT

struct CustomScrollBar : public QScrollBar {
    explicit CustomScrollBar(QWidget *parent = nullptr)
        : QScrollBar(parent) {
        static QString qss = R"!(
        QScrollBar:horizontal {
            background-color: #00FFFFFF;
            height: 10px;
            margin: 0px 0px 0px 0px;
        }

        QScrollBar::handle:horizontal {
            background-color: #FFC0C0C0;
            min-width: 20px;
            border-radius: 6px;
        }

        QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
            background: none;
        }

        QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {
            background: none;
        }

        /***********************************/

        QScrollBar:vertical {
            background-color: #00FFFFFF;
            width: 10px;
            margin: 0px 0px 0px 0px;
        }

        QScrollBar::handle:vertical {
            background-color: #FFC0C0C0;
            min-height: 20px;
            border-radius: 6px;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            background: none;
        }

        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
            background: none;
        }
        )!";
        this->setStyleSheet(qss);
    }

    virtual ~CustomScrollBar() {

    }
};

public:
enum EIcon {
    _eicon_none = 0x0000,
    _eicon_information = 0x0001,
    _eicon_question = 0x0002,
    _eicon_warning = 0x0003,
    _eicon_correct = 0x0004,
    _eicon_error = 0x0005
};

signals:
    void signalClose();
    void signalCheckbox(const QString& checkbox, bool checked);
    void signalRadiobutton(const QString& radiobutton, bool checked);
    void signalButton(const QString& button);

public:
    explicit MessageDialog(QWidget* parent, const QString& title, EIcon eicon, const QString& info, const QPair<QString, QVector<QString>>& checks, const QPair<QString, QVector<QString>>& radios, const QVector<QString>& buttons)
        : QDialog(parent) {
        dpiChange();
        dpiAuto();

		// this
        this->setObjectName("this");
        this->setWindowFlag(Qt::FramelessWindowHint, true);
        this->setAttribute(Qt::WA_TranslucentBackground, true);
        this->setMouseTracking(true);

        // _this
        _this = new VWidget(this);
        _this->setObjectName("_this");
        _this->setSaturateH(VWidget::_esaturate_box);
		QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(_this);
		shadowEffect->setColor(QColor("#28000000"));
		shadowEffect->setBlurRadius(20);
		shadowEffect->setOffset(0, 0);
		_this->setGraphicsEffect(shadowEffect);

        // _titlebar
        _titlebar = new HWidget(_this);
        _this->addWidget(_titlebar, 0.0);
        _titlebar->setObjectName("_titlebar");
        _titlebar->setSaturateV(HWidget::_esaturate_none);

        // _titlebar_logo
        _titlebar_logo = new QLabel(_titlebar);
        _titlebar->addWidget(_titlebar_logo, 0.0);
        _titlebar_logo->setObjectName("_titlebar_logo");
        _titlebar_logo->setPixmap(QPixmap(":/images/weixin.svg"));
        _titlebar_logo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        _titlebar_logo->setScaledContents(true);

        // _titlebar_title
        QString title_replaced = title;
        _titlebar_title = new QLabel(_titlebar);
        _titlebar->addWidget(_titlebar_title, 1.0);
        _titlebar_title->setObjectName("_titlebar_title");
        _titlebar_title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        _titlebar_title->setWordWrap(true);
        _titlebar_title->setAttribute(Qt::WA_TransparentForMouseEvents, true);    // 设置鼠标穿透
        _titlebar_title->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + title_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
        _titlebar_title->setProperty("_lineHeightRatio", _line_height_ratio);

        // _titlebar_close
        _titlebar_close = new QLabel(_titlebar);
        _titlebar->addWidget(_titlebar_close, 0.0);
        _titlebar_close->setObjectName("_titlebar_close");
        _titlebar_close->setPixmap(QPixmap(":/images/close.svg"));
        _titlebar_close->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        _titlebar_close->setScaledContents(true);
        _titlebar_close->installEventFilter(this);

        // _scrollarea
        _scrollarea = new QScrollArea(_this);
        _this->addWidget(_scrollarea, 1.0);       // 设置自动拉伸
        _scrollarea->setObjectName("_scrollarea");
        _scrollarea->setFrameShape(QFrame::NoFrame);
        _scrollarea->setWidgetResizable(false);   // 设置内部frame手动调整大小
        _scrollarea->setHorizontalScrollBar(new CustomScrollBar(_scrollarea));
        _scrollarea->setVerticalScrollBar(new CustomScrollBar(_scrollarea));
        _scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        _scrollarea->installEventFilter(this);    // 监听_scrollarea->resizeEvent()

        // _scrollarea_frame
        _scrollarea_frame = new HWidget(_scrollarea);
        _scrollarea->setWidget(_scrollarea_frame);
        _scrollarea_frame->setObjectName("_scrollarea_frame");
        _scrollarea_frame->setSaturateV(HWidget::_esaturate_line);
        _scrollarea_frame->setAlignments({Qt::AlignHCenter | Qt::AlignTop, Qt::AlignHCenter | Qt::AlignTop});
        QObject::connect(_scrollarea_frame, &HWidget::signalRelayout, _scrollarea, [this]() {
            qDebug().nospace() << "QObject::connect(_scrollarea_frame, &HWidget::signalRelayout, _scrollarea, [this]() {";
			if(_inited == false && _scrollarea_frame_content_checkflow_inited == true && _scrollarea_frame_content_radioflow_inited == true) {
                _inited = true;
                _scrollarea->setProperty("_sizeHint", _scrollarea_frame->sizeHint());
                _this->setStretchV(_scrollarea, 0.0);    // 设置固定拉伸值
                _this->doLayout();                       // 计算_this->sizeHint()

                QSize thisSizeHint = _this->sizeHint();
                int width = _edge_length + thisSizeHint.width() + _edge_length;
                int height = _edge_length + thisSizeHint.height() + _edge_length;
                this->resize(width, height);                          // 重置初始大小
                // 先执行this->resizeEvent()，再顺序执行
                _scrollarea->setProperty("_sizeHint", QVariant());    // 重置为无效值
                _this->setStretchV(_scrollarea, 1.0);                 // 还原拉伸值

                ////////////////////////////////

                // 居中对齐在父级顶层控件中央
                QWidget *parentWidget = this->parentWidget();
                QRect toplevelGeometry = (parentWidget == nullptr)? this->windowHandle()->screen()->geometry() : parentWidget->topLevelWidget()->frameGeometry();    // frameGeometry()包含标题栏
                this->move(toplevelGeometry.x() + (toplevelGeometry.width() - this->width()) / 2, toplevelGeometry.y() + (toplevelGeometry.height() - this->height()) / 2);
            }

            // _scrollarea_frame_content_firstLabel，调整_scrollarea_frame_content_icon与_scrollarea_frame_content的相对高度
            if (_scrollarea_frame_content_firstLabel != nullptr) {
                int scrollarea_frame_icon_offsetY = 0;
                if (_scrollarea_frame_content_firstLabel->inherits("QLabel") == true) {
                    _scrollarea_frame_content_firstLabel->style()->unpolish(_scrollarea_frame_content_firstLabel);
                    _scrollarea_frame_content_firstLabel->style()->polish(_scrollarea_frame_content_firstLabel);
                    QFontMetrics firstLabel_fontMetrics = _scrollarea_frame_content_firstLabel->fontMetrics();
                    scrollarea_frame_icon_offsetY = (firstLabel_fontMetrics.height() - _scrollarea_frame_icon->height()) / 2;
                } else {
                    scrollarea_frame_icon_offsetY = (_scrollarea_frame_content_firstLabel->height() - _scrollarea_frame_icon->height()) / 2;
                }

                _scrollarea_frame_icon->move(_scrollarea_frame_icon->x(), _scrollarea_frame_icon->y() + scrollarea_frame_icon_offsetY);
            }
        });

        // _scrollarea_frame_icon
        QString icon_path = "";
        if (eicon == MessageDialog::_eicon_information) {
            icon_path = ":/images/information.svg";
        } else if (eicon == MessageDialog::_eicon_question) {
            icon_path = ":/images/question.svg";
        } else if (eicon == MessageDialog::_eicon_warning) {
            icon_path = ":/images/warning.svg";
        } else if (eicon == MessageDialog::_eicon_correct) {
            icon_path = ":/images/correct.svg";
        } else if (eicon == MessageDialog::_eicon_error) {
            icon_path = ":/images/error.svg";
        }
        _scrollarea_frame_icon = new QLabel(_scrollarea_frame);
        _scrollarea_frame->addWidget(_scrollarea_frame_icon, 0.0);
        _scrollarea_frame_icon->setObjectName("_scrollarea_frame_icon");
        _scrollarea_frame_icon->setPixmap(QPixmap(icon_path));
        _scrollarea_frame_icon->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        _scrollarea_frame_icon->setScaledContents(true);

        // _scrollarea_frame_content
        _scrollarea_frame_content = new VWidget(_scrollarea_frame);
        _scrollarea_frame->addWidget(_scrollarea_frame_content, 1.0);
        _scrollarea_frame_content->setObjectName("_scrollarea_frame_content");
        _scrollarea_frame_content->setSaturateH(VWidget::_esaturate_box);
        _scrollarea_frame_content->setAlignments({Qt::AlignHCenter | Qt::AlignTop, Qt::AlignHCenter | Qt::AlignVCenter});
        QObject::connect(_scrollarea_frame_content, &VWidget::signalRelayout, _scrollarea_frame, [this]() {
            // qDebug().nospace() << "QObject::connect(_scrollarea_frame_content, &VWidget::signalRelayout, _scrollarea_frame, [this]() {";
            _scrollarea_frame->resize(_scrollarea_frame->sizeHint());
            _scrollarea_frame->setMinimumSize(_scrollarea_frame->sizeHint());    // 显隐QScrollArea的滚动条
        });
    
		if (info.isEmpty() == false) {
			// _scrollarea_frame_content_info
            QString info_replaced = info;
			_scrollarea_frame_content_info = new QLabel(_scrollarea_frame_content);
			_scrollarea_frame_content->addWidget(_scrollarea_frame_content_info, 0.0);
			_scrollarea_frame_content_info->setObjectName("_scrollarea_frame_content_info");
			_scrollarea_frame_content_info->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
			_scrollarea_frame_content_info->setWordWrap(true);
            _scrollarea_frame_content_info->setAttribute(Qt::WA_TransparentForMouseEvents, true);    // 设置鼠标穿透
            _scrollarea_frame_content_info->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + info_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
            _scrollarea_frame_content_info->setProperty("_lineHeightRatio", _line_height_ratio);
			if (_scrollarea_frame_content_firstLabel == nullptr) {
				_scrollarea_frame_content_firstLabel = _scrollarea_frame_content_info;
			}
		}

		if (checks.first.isEmpty() == false) {
			// _scrollarea_frame_content_checktip
            QString checktip_replaced = checks.first;
			_scrollarea_frame_content_checktip = new QLabel(_scrollarea_frame_content);
			_scrollarea_frame_content->addWidget(_scrollarea_frame_content_checktip, 0.0);
			_scrollarea_frame_content_checktip->setObjectName("_scrollarea_frame_content_checktip");
			_scrollarea_frame_content_checktip->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
			_scrollarea_frame_content_checktip->setWordWrap(true);
            _scrollarea_frame_content_info->setAttribute(Qt::WA_TransparentForMouseEvents, true);
            _scrollarea_frame_content_checktip->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + checktip_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
            _scrollarea_frame_content_checktip->setProperty("_lineHeightRatio", _line_height_ratio);
			if(_scrollarea_frame_content_firstLabel == nullptr) {
				_scrollarea_frame_content_firstLabel = _scrollarea_frame_content_checktip;
			}
		}

		if (checks.second.empty() == false) {
			// _scrollarea_frame_content_checkflow
			_scrollarea_frame_content_checkflow = new FHWidget(_scrollarea_frame_content);
			_scrollarea_frame_content->addWidget(_scrollarea_frame_content_checkflow, 0.0);
			_scrollarea_frame_content_checkflow->setObjectName("_scrollarea_frame_content_checkflow");
			_scrollarea_frame_content_checkflow->setSaturateV(FHWidget::_esaturate_none);
			_scrollarea_frame_content_checkflow->setAlignments({Qt::AlignLeft | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignVCenter});
			QObject::connect(_scrollarea_frame_content_checkflow, &FHWidget::signalRelayout, _scrollarea_frame_content, [this]() {
				// qDebug().nospace() << "QObject::connect(_scrollarea_frame_content_checkflow, &FHWidget::signalRelayout, _scrollarea_frame_content, [this]() {";
				_scrollarea_frame_content_checkflow_inited = true;
				_scrollarea_frame_content->resize(_scrollarea_frame_content->sizeHint());
			});
		
			// _scrollarea_frame_content_checkboxflow_checkboxes
			for (int i = 0; i < checks.second.size(); i += 1) {
				QCheckBox* checkbox = new QCheckBox(_scrollarea_frame_content);
				_scrollarea_frame_content_checkflow_checkboxes.push_back(checkbox);
				_scrollarea_frame_content_checkflow->addWidget(checkbox, 0.0);
				checkbox->setText(checks.second[i]);
				checkbox->installEventFilter(this);
			}
            if (_scrollarea_frame_content_firstLabel == nullptr && _scrollarea_frame_content_checkflow_checkboxes.empty() == false) {
				_scrollarea_frame_content_firstLabel = _scrollarea_frame_content_checkflow_checkboxes[0];
			}
		}

		if (radios.first.isEmpty() == false) {
			// _scrollarea_frame_content_radiotip
            QString radiotip_replaced = radios.first;
			_scrollarea_frame_content_radiotip = new QLabel(_scrollarea_frame_content);
			_scrollarea_frame_content->addWidget(_scrollarea_frame_content_radiotip, 0.0);
			_scrollarea_frame_content_radiotip->setObjectName("_scrollarea_frame_content_radiotip");
			_scrollarea_frame_content_radiotip->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
			_scrollarea_frame_content_radiotip->setWordWrap(true);
            _scrollarea_frame_content_radiotip->setAttribute(Qt::WA_TransparentForMouseEvents, true);    // 设置鼠标穿透
            _scrollarea_frame_content_radiotip->setText(QString("<p style='line-height: %1'>").arg(_line_height_ratio) + radiotip_replaced.replace("\n", "<br/>") + "</p>");  // 此样式会拦截鼠标事件
            _scrollarea_frame_content_radiotip->setProperty("_lineHeightRatio", _line_height_ratio);
			if (_scrollarea_frame_content_firstLabel == nullptr) {
				_scrollarea_frame_content_firstLabel = _scrollarea_frame_content_radiotip;
			}
		}
		
		if (radios.second.isEmpty() == false) {
			// _scrollarea_frame_content_radioflow
			_scrollarea_frame_content_radioflow = new FHWidget(_scrollarea_frame_content);
			_scrollarea_frame_content->addWidget(_scrollarea_frame_content_radioflow, 0.0);
			_scrollarea_frame_content_radioflow->setObjectName("_scrollarea_frame_content_radioflow");
			_scrollarea_frame_content_radioflow->setSaturateV(FHWidget::_esaturate_none);
			_scrollarea_frame_content_radioflow->setAlignments({ Qt::AlignLeft | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignCenter });
			QObject::connect(_scrollarea_frame_content_radioflow, &FHWidget::signalRelayout, _scrollarea_frame_content, [this]() {
				// qDebug().nospace() << "QObject::connect(_scrollarea_frame_content_radioflow, &FHWidget::signalRelayout, _scrollarea_frame_content, [this]() {";
				_scrollarea_frame_content_radioflow_inited = true;
				_scrollarea_frame_content->resize(_scrollarea_frame_content->sizeHint());
			});

			// _scrollarea_frame_content_radioflow_radiobuttons
			QButtonGroup *radiobuttonGroup = new QButtonGroup(_scrollarea_frame_content_radioflow);
			for (int i = 0; i < radios.second.size(); i += 1) {
				QRadioButton* radiobutton = new QRadioButton(_scrollarea_frame_content_radioflow);
				radiobuttonGroup->addButton(radiobutton);
				_scrollarea_frame_content_radioflow_radiobuttons.push_back(radiobutton);
				_scrollarea_frame_content_radioflow->addWidget(radiobutton, 0.0);
				radiobutton->setObjectName(QString("_scrollarea_frame_content_radioflow_radiobutton%1").arg(i));
				radiobutton->setText(radios.second[i]);
				radiobutton->installEventFilter(this);
			}
            if (_scrollarea_frame_content_firstLabel == nullptr && _scrollarea_frame_content_radioflow_radiobuttons.empty() == false) {
				_scrollarea_frame_content_firstLabel = _scrollarea_frame_content_radioflow_radiobuttons[0];
			}
		}

        // _buttonbox
        _buttonbox = new HWidget(_this);
        _this->addWidget(_buttonbox, 0.0);
        _buttonbox->setObjectName("_buttonbox");
		_buttonbox->setSaturateV(HWidget::_esaturate_none);
		_buttonbox->setAlignments({ Qt::AlignRight | Qt::AlignVCenter, Qt::AlignHCenter | Qt::AlignVCenter });
	
		// _buttonbox_buttons
		for (int i = 0; i < buttons.size(); i += 1) {
			QLabel* button = new QLabel(_buttonbox);
			_buttonbox_buttons.push_back(button);
			_buttonbox->addWidget(button, 0.0);
			button->setObjectName(QString("_buttonbox_button%1").arg(i));
			button->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			button->setText(buttons[i]);
            button->installEventFilter(this);
		}
    }

    virtual ~MessageDialog() {

    }

private:
    QString _Format(const QString& format, const QVector<QPair<QString, QVariant>>& values) {
        QString result = format;
        for (int i = 0; i < values.size(); i += 1) {
            QRegularExpression expression = QRegularExpression("[{]{1,1}[ ]{0,}" + values[i].first + "[ ]{0,}[}]{1,1}", QRegularExpression::DotMatchesEverythingOption);
            result.replace(expression, values[i].second.toString());
        }
        return result;
    }

    // 监听所有显示器的屏幕变动
	void dpiChange() {
		QList<QScreen*> screens = QApplication::screens();
		for (int i = 0; i < screens.size(); i += 1) {
			QScreen* screen = screens[i];
			QObject::connect(screen, &QScreen::logicalDotsPerInchChanged, [this, i, screen](qreal dpi_logical) {
                // qDebug().nospace() << "Screen[" << i << "]" << "  dpi logical = " << dpi_logical;
                (void)dpi_logical;
                update();
			});
		}
	}

    // 动态计算当前显示器的参数
	void dpiAuto() {
		// 加载json变量表
		static const QJsonObject this_json = [](const QString& json_file) -> QJsonObject {
			QJsonObject this_json;
			QFile file(json_file);
			bool retu = file.open(QFile::ReadOnly | QFile::Text);
			if (retu == false) {
				// qDebug() << "加载json变量表失败！";
				return this_json;
			}
			QString json_string = file.readAll();
			file.close();
			// qDebug().noquote() << "json_string = " << json_string;
			QJsonDocument json_document = QJsonDocument::fromJson(json_string.toUtf8());
			if (json_document.isObject() == false) {
				qDebug() << "加载json变量表失败！";
				return this_json;
			}
			this_json = json_document.object();
			return this_json;
		}(":/styles/this.json");

		// 加载qss样式表
		static const QString this_qss = [](const QString& qss_file) -> QString {
			QString this_qss = "";
			QFile file(qss_file);
			bool retu = file.open(QFile::ReadOnly | QFile::Text);
			if (retu == false) {
				// qDebug() << "加载qss样式表失败！";
				return this_qss;
			}
			this_qss = file.readAll();
			file.close();
			// qDebug().noquote() << "this_qss = " << this_qss;
			return this_qss;
		}(":/styles/this.qss");

		// 加载json变量值
		static const int edge_length = this_json["_edge_length"].toInt(0);
		static const int this_miniWidth = this_json["_this_miniWidth"].toInt(0);
		static const int this_miniHeight = this_json["_this_miniHeight"].toInt(0);
		static const int titlebar_height = this_json["_titlebar_height"].toInt(0);
		static const int titlebar_marginL = this_json["_titlebar_marginL"].toInt(0);
		static const int titlebar_marginR = this_json["_titlebar_marginR"].toInt(0);
		static const int titlebar_spacingH = this_json["_titlebar_spacingH"].toInt(0);
		static const int titlebar_logo_width = this_json["_titlebar_logo_width"].toInt(0);
		static const int titlebar_logo_height = this_json["_titlebar_logo_height"].toInt(0);
		static const int titlebar_close_width = this_json["_titlebar_close_width"].toInt(0);
		static const int titlebar_close_height = this_json["_titlebar_close_height"].toInt(0);
		static const int scrollarea_frame_marginL = this_json["_scrollarea_frame_marginL"].toInt(0);
		static const int scrollarea_frame_marginT = this_json["_scrollarea_frame_marginT"].toInt(0);
		static const int scrollarea_frame_marginR = this_json["_scrollarea_frame_marginR"].toInt(0);
		static const int scrollarea_frame_marginB = this_json["_scrollarea_frame_marginB"].toInt(0);
		static const int scrollarea_frame_spacingH = this_json["_scrollarea_frame_spacingH"].toInt(0);
		static const int scrollarea_frame_icon_width = this_json["_scrollarea_frame_icon_width"].toInt(0);
		static const int scrollarea_frame_icon_height = this_json["_scrollarea_frame_icon_height"].toInt(0);
		static const int scrollarea_frame_content_spacingV = this_json["_scrollarea_frame_content_spacingV"].toInt(0);
		static const int scrollarea_frame_content_checkflow_spacingH = this_json["_scrollarea_frame_content_checkflow_spacingH"].toInt(0);
		static const int scrollarea_frame_content_checkflow_spacingV = this_json["_scrollarea_frame_content_checkflow_spacingV"].toInt(0);
		static const int scrollarea_frame_content_radioflow_spacingH = this_json["_scrollarea_frame_content_radioflow_spacingH"].toInt(0);
		static const int scrollarea_frame_content_radioflow_spacingV = this_json["_scrollarea_frame_content_radioflow_spacingV"].toInt(0);
		static const int buttonbox_height = this_json["_buttonbox_height"].toInt(0);
		static const int buttonbox_marginL = this_json["_buttonbox_marginL"].toInt(0);
		static const int buttonbox_marginR = this_json["_buttonbox_marginR"].toInt(0);
		static const int buttonbox_spacingH = this_json["_buttonbox_spacingH"].toInt(0);
		static const int buttonbox_button_width = this_json["_buttonbox_button_width"].toInt(0);
		static const int buttonbox_button_height = this_json["_buttonbox_button_height"].toInt(0);

		static const double line_height_ratio = this_json["_line_height_ratio"].toDouble(0.0);
		static const int titlebar_title_fontsize = this_json["_titlebar_title_fontsize"].toInt(0);
		static const int scrollarea_frame_content_info_fontsize = this_json["_scrollarea_frame_content_info_fontsize"].toInt(0);
		static const int scrollarea_frame_content_checktip_fontsize = this_json["_scrollarea_frame_content_checktip_fontsize"].toInt(0);
		static const int scrollarea_frame_content_checkflow_checkbox_fontsize = this_json["_scrollarea_frame_content_checkflow_checkbox_fontsize"].toInt(0);
		static const int scrollarea_frame_content_radiotip_fontsize = this_json["_scrollarea_frame_content_radiotip_fontsize"].toInt(0);
		static const int scrollarea_frame_content_radioflow_radiobutton_fontsize = this_json["_scrollarea_frame_content_radioflow_radiobutton_fontsize"].toInt(0);
		static const int buttonbox_button_fontsize = this_json["_buttonbox_button_fontsize"].toInt(0);

        // 获取显示器dpi
		QWindow* window = this->windowHandle();
		if (window != nullptr) {
			double dpi_logical = window->screen()->logicalDotsPerInch();
			_scale = dpi_logical / 96.0;
			// qDebug() << "_scale = " << _scale;

			// 设置变量值
			_edge_length = edge_length * _scale;
			_this_miniWidth = this_miniWidth * _scale;     // 建议宽度
			_this_miniHeight = this_miniHeight * _scale;   // 建议高度
			_titlebar_height = titlebar_height * _scale;
			_titlebar_marginL = titlebar_marginL * _scale;
			_titlebar_marginR = titlebar_marginR * _scale;
			_titlebar_spacingH = titlebar_spacingH * _scale;
		    _titlebar_logo_width = titlebar_logo_width * _scale;
			_titlebar_logo_height = titlebar_logo_height * _scale;
			_titlebar_close_width = titlebar_close_width * _scale;
			_titlebar_close_height = titlebar_close_height * _scale;
			_scrollarea_frame_marginL = scrollarea_frame_marginL * _scale;
			_scrollarea_frame_marginT = scrollarea_frame_marginT * _scale;
			_scrollarea_frame_marginR = scrollarea_frame_marginR * _scale;
			_scrollarea_frame_marginB = scrollarea_frame_marginB * _scale;
			_scrollarea_frame_spacingH = scrollarea_frame_spacingH * _scale;
			_scrollarea_frame_icon_width = scrollarea_frame_icon_width * _scale;
			_scrollarea_frame_icon_height = scrollarea_frame_icon_height * _scale;
			_scrollarea_frame_content_spacingV = scrollarea_frame_content_spacingV * _scale;
			_scrollarea_frame_content_checkflow_spacingH = scrollarea_frame_content_checkflow_spacingH * _scale;
			_scrollarea_frame_content_checkflow_spacingV = scrollarea_frame_content_checkflow_spacingV * _scale;
			_scrollarea_frame_content_radioflow_spacingH = scrollarea_frame_content_radioflow_spacingH * _scale;
			_scrollarea_frame_content_radioflow_spacingV = scrollarea_frame_content_radioflow_spacingV * _scale;
			_buttonbox_height = buttonbox_height * _scale;
			_buttonbox_marginL = buttonbox_marginL * _scale;
			_buttonbox_marginR = buttonbox_marginR * _scale;
			_buttonbox_spacingH = buttonbox_spacingH * _scale;
			_buttonbox_button_width = buttonbox_button_width * _scale;
			_buttonbox_button_height = buttonbox_button_height * _scale;

			// 设置qss样式
			_this_qss = _Format(this_qss, {
				{ "_titlebar_title_fontsize", (int)(titlebar_title_fontsize * _scale) },
				{ "_scrollarea_frame_content_info_fontsize", (int)(scrollarea_frame_content_info_fontsize * _scale) },
				{ "_scrollarea_frame_content_checktip_fontsize", (int)(scrollarea_frame_content_checktip_fontsize * _scale) },
				{ "_scrollarea_frame_content_checkflow_checkbox_fontsize", (int)(scrollarea_frame_content_checkflow_checkbox_fontsize * _scale) },
				{ "_scrollarea_frame_content_radiotip_fontsize", (int)(scrollarea_frame_content_radiotip_fontsize * _scale) },
				{ "_scrollarea_frame_content_radioflow_radiobutton_fontsize", (int)(scrollarea_frame_content_radioflow_radiobutton_fontsize * _scale) },
				{ "_buttonbox_button_fontsize", (int)(buttonbox_button_fontsize * _scale) }
			});
		}
		_line_height_ratio = line_height_ratio;
	}

	int _Resizing_Enable(const QPoint& local) {
		int resizing = _edge_none;
		if (this->width() - _edge_length <= local.x() && local.x() < this->width()) {
			resizing |= _edge_right;
		} else if (0 <= local.x() && local.x() < _edge_length) {
			resizing |= _edge_left;
		}
		if (this->height() - _edge_length <= local.y() && local.y() < this->height()) {
			resizing |= _edge_bottom;
		} else if (0 <= local.y() && local.y() < _edge_length) {
			resizing |= _edge_top;
		}
		return resizing;
	}

	bool _Dragging_Enable(const QPoint& local) {
		bool dragging = false;
        QPoint topLeft = _titlebar->mapTo(this, _titlebar->rect().topLeft());
        QPoint bottomRight = _titlebar->mapTo(this, _titlebar->rect().bottomRight());
        if (topLeft.x() <= local.x() && local.x() < bottomRight.x() && topLeft.y() <= local.y() && local.y() < bottomRight.y()) {
			dragging = true;
		}
		return dragging;
	}

    bool eventFilter(QObject *watched, QEvent *event) override {
        if(event->type() == QEvent::Resize && watched == _scrollarea) {
            qDebug().nospace() << __FUNCTION__ << ", if(event->type() == QEvent::Resize && watched == _scrollarea) {";
            _scrollarea_frame->resize(_scrollarea->size());
		} else if (event->type() == QEvent::MouseButtonRelease) {
			if (watched == _titlebar_close) {
				emit this->signalClose();
			} else if (watched->objectName().startsWith("_scrollarea_frame_content_checkflow_checkbox")) {
				QCheckBox* checkbox = qobject_cast<QCheckBox*>(watched);
				bool checked = !checkbox->isChecked();       // checkbox还未更新其checked状态
				emit this->signalCheckbox(checkbox->text(), checked);
			} else if (watched->objectName().startsWith("_scrollarea_frame_content_radioflow_radiobutton")) {
				QRadioButton* radiobutton = qobject_cast<QRadioButton*>(watched);
				bool checked = !radiobutton->isChecked();    // radiobutton还未更新其checked状态
				emit this->signalRadiobutton(radiobutton->text(), checked);
			} else if (watched->objectName().startsWith("_buttonbox_button")) {
				QLabel* button = qobject_cast<QLabel*>(watched);
				emit this->signalButton(button->text());
			}
		}
        return QDialog::eventFilter(watched, event);
    }

    void resizeEvent(QResizeEvent* event) override {
        qDebug().nospace() << __FUNCTION__ << ", event = " << event;
        (void)event;
		dpiAuto();
		this->setStyleSheet(_this_qss);

        // _titlebar
        _titlebar->setFixedHeight(_titlebar_height);
        _titlebar->setMargins({_titlebar_marginL, 0, _titlebar_marginR, 0});
        _titlebar->setSpacingH(_titlebar_spacingH);

        // _titlebar_logo
        _titlebar_logo->setFixedWidth(_titlebar_logo_width);
        _titlebar_logo->setFixedHeight(_titlebar_logo_height);

        // _titlebar_close
        _titlebar_close->setFixedWidth(_titlebar_close_width);
        _titlebar_close->setFixedHeight(_titlebar_close_height);

        // _scrollarea_frame
        _scrollarea_frame->setMinimumSize(0, 0);    // 显隐QScrollArea的滚动条
        _scrollarea_frame->setMargins({_scrollarea_frame_marginL, _scrollarea_frame_marginT, _scrollarea_frame_marginR, _scrollarea_frame_marginB});
        _scrollarea_frame->setSpacingH(_scrollarea_frame_spacingH);

        // _scrollarea_frame_icon
        _scrollarea_frame_icon->setFixedWidth(_scrollarea_frame_icon_width);
        _scrollarea_frame_icon->setFixedHeight(_scrollarea_frame_icon_height);

        // _scrollarea_frame_content
        _scrollarea_frame_content->setMargins({0, 0, 0, 0});
        _scrollarea_frame_content->setSpacingV(_scrollarea_frame_content_spacingV);

        // _scrollarea_frame_content_checkflow
        _scrollarea_frame_content_checkflow->setMargins({ 0, 0, 0, 0 });
        _scrollarea_frame_content_checkflow->setSpacings({_scrollarea_frame_content_checkflow_spacingH, _scrollarea_frame_content_checkflow_spacingV});

        // _scrollarea_frame_content_radioflow
        _scrollarea_frame_content_radioflow->setMargins({ 0, 0, 0, 0 });
        _scrollarea_frame_content_radioflow->setSpacings({ _scrollarea_frame_content_radioflow_spacingH, _scrollarea_frame_content_radioflow_spacingV});

        // _buttonbox
        _buttonbox->setFixedHeight(_buttonbox_height);
        _buttonbox->setMargins({ _buttonbox_marginL, 0, _buttonbox_marginR, 0 });
        _buttonbox->setSpacingH(_buttonbox_spacingH);

        // _buttonbox_buttons
        for (int i = 0; i < _buttonbox_buttons.size(); i += 1) {
            QLabel* button = _buttonbox_buttons[i];
            button->setFixedWidth(_buttonbox_button_width);
            button->setFixedHeight(_buttonbox_button_height);
        }

        ////////////////////////////////

        // 执行resize()操作
        this->setMinimumWidth(_edge_length + _this_miniWidth + _edge_length);
        this->setMinimumHeight(_edge_length + _this_miniHeight + _edge_length);  // 初始高度根据宽度设定
        _this->resize(this->width() - _edge_length - _edge_length, this->height() - _edge_length - _edge_length);
        _this->move(_edge_length, _edge_length);
    }

	void paintEvent(QPaintEvent *event) override {
		qDebug() << __FUNCTION__ << ", event = " << event;
		(void)event;
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing);

		QBrush brush;
		brush.setStyle(Qt::BrushStyle::SolidPattern);
		brush.setColor("#01FFFFFF");
		painter.setBrush(brush);
		painter.setPen(QPen(Qt::NoPen));
		painter.drawRoundedRect(this->rect(), 2, 2);  // 绘制透明背景，无边框

		QPen pen;
		pen.setWidth(2);
		pen.setStyle(Qt::PenStyle::SolidLine);
		pen.setColor(QColor("#FFC7CDD5"));
		painter.setBrush(QBrush(Qt::NoBrush));
		painter.setPen(pen);
		painter.drawRect(_this->geometry());  // 绘制边框线，无填充
	}

	void mousePressEvent(QMouseEvent *event) override {
		qDebug().noquote() << __FUNCTION__ << ", event = " << event;
		if (event->button() == Qt::LeftButton) {
			_resizing = _edge_none;    // 重置缩放状态
			_dragging = false;         // 重置拖拽状态
			if ((_resizing = _Resizing_Enable(event->pos())) != _edge_none ||
				(_dragging = _Dragging_Enable(event->pos()) == true)) {
				_press_global = event->globalPos();
				_press_geometry = this->geometry();
			}
		}
	}

	void mouseMoveEvent(QMouseEvent *event) override {
		qDebug().nospace() << __FUNCTION__ << ", event = " << event;
		if (event->buttons() & Qt::LeftButton) {
			if (_resizing != _edge_none) {
				QPoint move_global = event->globalPos();
				int driftX = move_global.x() - _press_global.x();
				int driftY = move_global.y() - _press_global.y();
				int x = _press_geometry.x();
				int y = _press_geometry.y();
				int width = _press_geometry.width();
				int height = _press_geometry.height();
				if (_resizing & _edge_right) {
					width = width + driftX;
					if (width < _edge_length + _this_miniWidth + _edge_length) {
						width = _edge_length + _this_miniWidth + _edge_length;
					}
				} else if (_resizing & _edge_left) {
					width = width - driftX;
					if (width < _edge_length + _this_miniWidth + _edge_length) {
						width = _edge_length + _this_miniWidth + _edge_length;
					}
					x = x + _press_geometry.width() - width;
				}
				if (_resizing & _edge_bottom) {
					height = height + driftY;
					if (height < _edge_length + _this_miniHeight + _edge_length) {
						height = _edge_length + _this_miniHeight + _edge_length;
					}
				} else if (_resizing & _edge_top) {
					height = height - driftY;
					if (height < _edge_length + _this_miniHeight + _edge_length) {
						height = _edge_length + _this_miniHeight + _edge_length;
					}
					y = y + _press_geometry.height() - height;
				}
				this->setFixedWidth(width);
				this->setFixedHeight(height);
				this->move(x, y);
			} else if (_dragging == true) {
				QPoint move_global = event->globalPos();
				int driftX = move_global.x() - _press_global.x();
				int driftY = move_global.y() - _press_global.y();
				this->move(_press_geometry.x() + driftX, _press_geometry.y() + driftY);
			}
		}

		// 更改鼠标样式
		if (_resizing == _edge_none) {
			this->grabMouse();
			int resizing = _Resizing_Enable(event->pos());
			if (resizing == _edge_left || resizing == _edge_right) {
				this->setCursor(Qt::SizeHorCursor);
			} else if (resizing == _edge_top || resizing == _edge_bottom) {
				this->setCursor(Qt::SizeVerCursor);
			} else if (resizing == (_edge_left | _edge_top) || resizing == (_edge_right | _edge_bottom)) {
				this->setCursor(Qt::SizeFDiagCursor);
			} else if (resizing == (_edge_left | _edge_bottom) || resizing == (_edge_right | _edge_top)) {
				this->setCursor(Qt::SizeBDiagCursor);
			} else {
				this->releaseMouse();
				this->setCursor(Qt::ArrowCursor);
			}
		}
	}

	void mouseReleaseEvent(QMouseEvent *event) override {
		qDebug().noquote() << __FUNCTION__ << ", event = " << event;
		if (event->button() == Qt::LeftButton) {
			_resizing = _edge_none;
			_dragging = false;
			this->setCursor(Qt::ArrowCursor);
		}
	}
	
public:
    static void informationDialog(QWidget* parent, const QString& title, MessageDialog::EIcon eicon, const QString& info, const QString& button) {
        QPair<QString, QVector<QString>> checks;
        QPair<QString, QVector<QString>> radios;
        MessageDialog* messageDialog = new MessageDialog(parent, title, eicon, info, checks, radios, { button });

        QObject::connect(messageDialog, &MessageDialog::signalClose, [messageDialog]() {
            messageDialog->close();
        });
        QObject::connect(messageDialog, &MessageDialog::signalButton, [messageDialog](const QString& button) {
            (void)button;
            messageDialog->close();
        });

        messageDialog->exec();
        messageDialog->deleteLater();
    }

    static QVector<QString> optionCheckDialog(QWidget* parent, const QString& title, const QString& checktip, const QVector<QString>& checkboxs, const QPair<QString, QString>& buttons) {
        MessageDialog::EIcon eicon = MessageDialog::_eicon_question;
        QString info = "";
        QPair<QString, QVector<QString>> radios;
        MessageDialog* messageDialog = new MessageDialog(parent, title, eicon, info, { checktip, checkboxs }, radios, { buttons.first, buttons.second });

        QVector<QString> options;
        QObject::connect(messageDialog, &MessageDialog::signalClose, [messageDialog, &options]() {
            options.clear();
            messageDialog->close();
        });
        QObject::connect(messageDialog, &MessageDialog::signalCheckbox, [messageDialog, &options](const QString& checkbox, bool checked) {
            // qDebug() << checkbox << ": " << checked;
            if (checked == true) {
                bool hit = false;
                for (int i = 0; i < options.size(); i += 1) {
                    if (options[i] == checkbox) {
                        hit = true;
                        break;
                    }
                }
                if (hit == false) {
                    options.push_back(checkbox);
                }
            } else {
                for (auto iter = options.begin(); iter != options.end();) {
                    if (*iter == checkbox) {
                        iter = options.erase(iter);
                        continue;
                    }
                    ++iter;
                }
            }
        });
        QObject::connect(messageDialog, &MessageDialog::signalButton, [messageDialog, &buttons, &options](const QString& button) {
            if (buttons.second == button) {
                options.clear();
            }
            messageDialog->close();
        });

        messageDialog->exec();
        messageDialog->deleteLater();
        return options;
    }

    static QString optionRadioDialog(QWidget* parent, const QString& title, const QString& radiotip, const QVector<QString>& radiobuttons, const QPair<QString, QString>& buttons) {
        MessageDialog::EIcon eicon = MessageDialog::_eicon_question;
        QString info = "";
        QPair<QString, QVector<QString>> checks;
        MessageDialog* messageDialog = new MessageDialog(parent, title, eicon, info, checks, { radiotip, radiobuttons }, { buttons.first, buttons.second });

        QString option;
        QObject::connect(messageDialog, &MessageDialog::signalClose, [messageDialog, &option]() {
            option = "";
            messageDialog->close();
        });
        QObject::connect(messageDialog, &MessageDialog::signalRadiobutton, [messageDialog, &option](const QString& radiobutton, bool checked) {
            // qDebug() << radiobutton << ": " << checked;
            if (checked == true) {
                option = radiobutton;
            }
        });
        QObject::connect(messageDialog, &MessageDialog::signalButton, [messageDialog, &buttons, &option](const QString& button) {
            if (buttons.second == button) {
                option = "";
            }
            messageDialog->close();
        });

        messageDialog->exec();
        messageDialog->deleteLater();
        return option;
    }

    static void _Test_MessageDialog(QWidget* parent) {
        QString title = "Title";
        MessageDialog::EIcon eicon = MessageDialog::_eicon_information;
        QString info = "This large piece of text may be too long, so use a 425px Size Model. \nThis large piece of text may be too long, so use a 425px Size Model.";
        QPair<QString, QVector<QString>> checks = {
            "Do you want to save project changes?",
            { "Check1", "Check2", "Check3", "Check4", "Check5", "Check6", "Check7" }
        };
        QPair<QString, QVector<QString>> radios = {
            "Please Select: ",
            { "Radio1", "Radio2", "Radio3", "Radio4", "Radio5", "Radio6", "Radio7" }
        };
        QVector<QString> buttons = { "Ok", "Cancel" };
        MessageDialog *messagedialog = new MessageDialog(parent, title, eicon, info, checks, radios, buttons);

        QObject::connect(messagedialog, &MessageDialog::signalClose, [messagedialog]() {
            qDebug() << "Close";
            messagedialog->close();
        });
        QObject::connect(messagedialog, &MessageDialog::signalCheckbox, [messagedialog](const QString& checkbox, bool checked) {
            qDebug() << checkbox << ": " << checked;
        });
        QObject::connect(messagedialog, &MessageDialog::signalRadiobutton, [messagedialog](const QString& radiobutton, bool checked) {
            qDebug() << radiobutton << ": " << checked;
        });
        QObject::connect(messagedialog, &MessageDialog::signalButton, [messagedialog](const QString& button) {
            qDebug() << button;
            messagedialog->close();
        });

        messagedialog->exec();
        messagedialog->deleteLater();
    }

    static void _Test_InformationDialog(QWidget* parent) {
        MessageDialog::informationDialog(parent, "Title", MessageDialog::_eicon_information, "This large piece of text may be too long, so use a 425px Size Model. ", { "Ok" });
    }

    static void _Test_OptionCheckDialog(QWidget* parent) {
        QVector<QString> options = MessageDialog::optionCheckDialog(parent, "Title", "Do you want to save project changes? ", { "Option1", "Option2", "Option3", "Option4", "Option5", "Option6", "Option7" }, { "Ok", "Cancel" });
        qDebug() << __FUNCTION__ << ", options = " << options;
    }

    static void _Test_OptionRadioDialog(QWidget* parent) {
        QString option = MessageDialog::optionRadioDialog(parent, "Title", "Please select: ", { "Option1", "Option2", "Option3", "Option4", "Option5", "Option6", "Option7" }, { "Ok", "Cancel" });
        qDebug() << __FUNCTION__ << ", option = " << option;
    }

private:
    static const int _edge_none = 0b0000;
    static const int _edge_left = 0b0001;
    static const int _edge_top = 0b0010;
    static const int _edge_right = 0b0100;
    static const int _edge_bottom = 0b1000;

private:
	QString _this_qss = "";
    bool _scrollarea_frame_content_checkflow_inited = false;
    bool _scrollarea_frame_content_radioflow_inited = false;
    bool _inited = false;
    double _scale = 1.0;
    int _edge_length = 5 * _scale;
    int _this_miniWidth = 425 * _scale;
    int _this_miniHeight = 100 * _scale;
    int _titlebar_height = 36 * _scale;
    int _titlebar_marginL = 12 * _scale;
    int _titlebar_marginR = 12 * _scale;
    int _titlebar_spacingH = 8 * _scale;
    int _titlebar_logo_width = 20 * _scale;
    int _titlebar_logo_height = 20 * _scale;
    int _titlebar_close_width = 20 * _scale;
    int _titlebar_close_height = 20 * _scale;
    int _scrollarea_frame_marginL = 16 * _scale;
    int _scrollarea_frame_marginT = 12 * _scale;
    int _scrollarea_frame_marginR = 16 * _scale;
    int _scrollarea_frame_marginB = 16 * _scale;
    int _scrollarea_frame_spacingH = 6 * _scale;
    int _scrollarea_frame_icon_width = 20 * _scale;
    int _scrollarea_frame_icon_height = 20 * _scale;
    int _scrollarea_frame_content_spacingV = 12 * _scale;
    int _scrollarea_frame_content_checkflow_spacingH = 12 * _scale;
    int _scrollarea_frame_content_checkflow_spacingV = 12 * _scale;
	int _scrollarea_frame_content_radioflow_spacingH = 12 * _scale;
	int _scrollarea_frame_content_radioflow_spacingV = 12 * _scale;
    int _buttonbox_height = 44 * _scale;
    int _buttonbox_marginL = 8 * _scale;
    int _buttonbox_marginR = 8 * _scale;
    int _buttonbox_spacingH = 8 * _scale;
    int _buttonbox_button_width = 80 * _scale;
    int _buttonbox_button_height = 28 * _scale;
	double _line_height_ratio = 0.0;

    VWidget* _this = nullptr;
    HWidget* _titlebar = nullptr;
    QLabel* _titlebar_logo = nullptr;
    QLabel* _titlebar_title = nullptr;
    QLabel* _titlebar_close = nullptr;
    QScrollArea* _scrollarea = nullptr;
    HWidget* _scrollarea_frame = nullptr;
    QLabel* _scrollarea_frame_icon = nullptr;
    VWidget* _scrollarea_frame_content = nullptr;
	QWidget* _scrollarea_frame_content_firstLabel = nullptr;
    QLabel* _scrollarea_frame_content_info = nullptr;
    QLabel* _scrollarea_frame_content_checktip = nullptr;
    FHWidget* _scrollarea_frame_content_checkflow = nullptr;
    QVector<QCheckBox*> _scrollarea_frame_content_checkflow_checkboxes;
	QLabel* _scrollarea_frame_content_radiotip = nullptr;
	FHWidget* _scrollarea_frame_content_radioflow = nullptr;
	QVector<QRadioButton*> _scrollarea_frame_content_radioflow_radiobuttons;
    HWidget* _buttonbox = nullptr;
	QVector<QLabel*> _buttonbox_buttons;

    int _resizing = _edge_none;
    bool _dragging = false;
    QPoint _press_global;
    QRect _press_geometry;
};
