#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

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
#include <QScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QStyle>
#include <QTimer>
#include <QWindow>

class MessageDialog : public QDialog {
    Q_OBJECT

private:
struct CustomScrollBar : public QScrollBar {
	explicit CustomScrollBar(QWidget *parent = nullptr);
	virtual ~CustomScrollBar();
};

struct LabelFit : public QLabel {
	explicit LabelFit(QWidget* parent = nullptr);
	virtual ~LabelFit();
	virtual void adjustSizeFit(double lineHeightRatio);
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
	void _Signal_Close();
	void _Signal_Checkbox(const QString& checkbox, bool checked);
	void _Signal_Radiobutton(const QString& radiobutton, bool checked);
	void _Signal_Button(const QString& button);

public:
	explicit MessageDialog(QWidget* parent, const QString& title, EIcon eicon, const QString& info, const QPair<QString, QVector<QString>>& checks, const QPair<QString, QVector<QString>>& radios, const QVector<QString>& buttontexts);
	virtual ~MessageDialog();

private:
	void _Fonts_Avaliable();
	QString _Format(const QString &format, const QVector<QPair<QString, QVariant>> &values);
	void _Dpi_Change();
	void _Dpi_Auto();
	int _OffsetFore(int boxLen, int selfLen);
	int _Resizing_Enable(const QPoint& local);
	bool _Dragging_Enable(const QPoint& local);
	bool eventFilter(QObject *watched, QEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;

public:
	static void _InformationDialog(QWidget* parent, const QString& title, MessageDialog::EIcon eicon, const QString& info, const QString& button);
	static QVector<QString> _OptionCheckDialog(QWidget* parent, const QString& title, const QString& checktip, const QVector<QString>& checkboxs, const QPair<QString, QString>& buttons);
	static QString _OptionRadioDialog(QWidget* parent, const QString& title, const QString& radiotip, const QVector<QString>& radiobuttons, const QPair<QString, QString>& buttons);
    static void _Test_MessageDialog(QWidget* parent);
    static void _Test_InformationDialog(QWidget* parent);
    static void _Test_OptionCheckDialog(QWidget* parent);
    static void _Test_OptionRadioDialog(QWidget* parent);

private:
	static const int _edge_none = 0b0000;
	static const int _edge_left = 0b0001;
	static const int _edge_top = 0b0010;
	static const int _edge_right = 0b0100;
	static const int _edge_bottom = 0b1000;

private:
	QString _this_qss = "";
	double _scale = 0;
	int _edge_length = 0;
	int _this_minWidth = 0;
	int _this_minHeight = 0;
	int _titlebar_height = 0;
	int _titlebar_paddingL = 0;
	int _titlebar_paddingR = 0;
	int _titlebar_logo_width = 0;
	int _titlebar_logo_height = 0;
	int _titlebar_title_marginL = 0;
	int _titlebar_close_width = 0;
	int _titlebar_close_height = 0;
	int _titlebar_close_marginL = 0;
	int _mainbody_scrollarea_frame_paddingL = 0;
	int _mainbody_scrollarea_frame_paddingT = 0;
	int _mainbody_scrollarea_frame_paddingR = 0;
	int _mainbody_scrollarea_frame_paddingB_inited = 0;
	int _mainbody_scrollarea_frame_spacing = 0;
	int _mainbody_scrollarea_frame_icon_width = 0;
	int _mainbody_scrollarea_frame_icon_height = 0;
	int _mainbody_scrollarea_frame_content_marginL = 0;
	int _mainbody_scrollarea_frame_content_checkbox_spacing = 0;
	int _mainbody_scrollarea_frame_content_radiobutton_spacing = 0;
	int _mainbody_buttonbox_height = 0;
	int _mainbody_buttonbox_paddingL = 0;
	int _mainbody_buttonbox_paddingR = 0;
	int _mainbody_buttonbox_button_width = 0;
	int _mainbody_buttonbox_button_height = 0;
	int _mainbody_buttonbox_button_spacing = 0;
	double _line_height_ratio = 0.0;

    QWidget* _this = nullptr;
    QWidget* _titlebar = nullptr;
	QLabel* _titlebar_logo = nullptr;
	LabelFit* _titlebar_title = nullptr;
	QLabel* _titlebar_close = nullptr;
    QWidget* _mainbody = nullptr;
	QScrollArea* _mainbody_scrollarea = nullptr;
    QWidget* _mainbody_scrollarea_frame = nullptr;
	QLabel* _mainbody_scrollarea_frame_icon = nullptr;
    QWidget* _mainbody_scrollarea_frame_content = nullptr;
	LabelFit* _mainbody_scrollarea_frame_content_info = nullptr;
	LabelFit* _mainbody_scrollarea_frame_content_checktip = nullptr;
	QVector<QCheckBox*> _mainbody_scrollarea_frame_content_checkboxs;
	LabelFit* _mainbody_scrollarea_frame_content_radiotip = nullptr;
	QVector<QRadioButton*> _mainbody_scrollarea_frame_content_radiobuttons;
    QWidget* _mainbody_buttonbox = nullptr;
	QVector<QLabel*> _mainbody_buttonbox_buttons;

	bool _first_inited = false;
	int _resizing = _edge_none;
	bool _dragging = false;
	QRect _titlebar_geometry;
	QPoint _press_global;
	QRect _press_geometry;
};

#endif // MESSAGEDIALOG_H
