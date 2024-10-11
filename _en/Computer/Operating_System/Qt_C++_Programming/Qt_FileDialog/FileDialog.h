#pragma once

#include <QApplication>
#include <QComboBox>
#include <QComboBox>
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QFormLayout>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QMessageBox>
#include <QPushButton>
#include <QRegularExpression>
#include <QTreeWidget>
#include <QVector>

class FileDialog : public QDialog {
	Q_OBJECT

public:
	inline static const quint32 _index_header_name = 0x0000;
	inline static const quint32 _index_header_modified = 0x0001;
	inline static const quint32 _index_header_size = 0x0002;
	inline static const quint32 _index_header_type = 0x0003;
	inline static const QStringList _header_labels = {
		"名称", "修改时间", "大小", "类型"
	};

public:
	QTreeWidget *_tw_folderinfo = nullptr;
	QLabel *_l_filename = nullptr;
	QLineEdit *_le_filename = nullptr;
	QLabel *_l_filters = nullptr;
	QComboBox *_cb_filters = nullptr;
	QPushButton *_pb_accept = nullptr;
	QPushButton *_pb_cancel = nullptr;
	QString _folderpath = "";
	QString _filepath = "";
	QMap<QString, bool> _options;

public:
	explicit FileDialog(QWidget *parent = nullptr)
		: QDialog(parent) {

		_tw_folderinfo = new QTreeWidget();
		_tw_folderinfo->setHeaderLabels(_header_labels);
		_tw_folderinfo->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
		_tw_folderinfo->setAlternatingRowColors(true);
		_tw_folderinfo->setIndentation(0);
		_tw_folderinfo->setSortingEnabled(true);
		_tw_folderinfo->sortByColumn(_index_header_name, Qt::AscendingOrder);
		_tw_folderinfo->header()->setCascadingSectionResizes(true);
		_tw_folderinfo->header()->setDropIndicatorShown(true);
		_tw_folderinfo->header()->setStretchLastSection(true);

		_l_filename = new QLabel("名称: ");
		_le_filename = new QLineEdit();
		_le_filename->setPlaceholderText("请输入名称");
		_l_filters = new QLabel("类型: ");
		_cb_filters = new QComboBox();
		QFormLayout *fl_form = new QFormLayout();
		fl_form->addRow(_l_filename, _le_filename);
		fl_form->addRow(_l_filters, _cb_filters);

		_pb_accept = new QPushButton("确定");
		_pb_accept->setAutoDefault(false);
		_pb_accept->setDefault(false);
		_pb_cancel = new QPushButton("取消");
		_pb_cancel->setAutoDefault(false);
		_pb_cancel->setDefault(false);
		QDialogButtonBox *dbb_box = new QDialogButtonBox();
		dbb_box->setOrientation(Qt::Horizontal);
		dbb_box->addButton(_pb_accept, QDialogButtonBox::YesRole);  // 设置为AcceptRole会自动设置default button
		dbb_box->addButton(_pb_cancel, QDialogButtonBox::NoRole);

		QGridLayout *gl_grid = new QGridLayout();
		gl_grid->addWidget(_tw_folderinfo, 0, 0);
		gl_grid->addLayout(fl_form, 1, 0);
		gl_grid->addWidget(dbb_box, 2, 0);
		this->setLayout(gl_grid);
		this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
		this->resize(400, 400);  // 使用resize()而非setFixedSize()
		// Dialog会自动居中显示在父缘顶层窗口。

		////////////////////////////////

		QObject::connect(_tw_folderinfo, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem *item, int column) -> void {
			QString filename = item->text(_index_header_name);
			_le_filename->setText(filename);
		});

		QObject::connect(_le_filename, &QLineEdit::textChanged, this, [this](const QString& text) -> void {
			qDebug().noquote() << "QObject::connect(_le_filename, &QLineEdit::textChanged, this, [this](const QString& text) -> void {";
			_pb_accept->setEnabled(text.isEmpty() == false);
		});
		emit _le_filename->textChanged(_le_filename->text());

		QObject::connect(_cb_filters, &QComboBox::currentTextChanged, this, [this](const QString &text) -> void {
			// qDebug().noquote() << "QObject::connect(_cb_filters, &QComboBox::currentTextChanged, this, [this](const QString &text) -> void {";

			_tw_folderinfo->clear();
			QStringList filters = _Reduce_Filters(text);
			QFileInfoList folderinfo = QDir(_folderpath).entryInfoList(filters, QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Name);
			for (auto iter = folderinfo.begin(); iter != folderinfo.end(); iter += 1) {
				const QFileInfo& fileinfo = (*iter);
				QTreeWidgetItem *item = new QTreeWidgetItem();
				item->setText(_index_header_name, fileinfo.fileName());
				item->setText(_index_header_modified, fileinfo.lastModified().toString(Qt::ISODateWithMs));
				item->setText(_index_header_size, _Reduce_Filesize(fileinfo.size()));
				item->setText(_index_header_type, _Reduce_Type(fileinfo));
				_tw_folderinfo->addTopLevelItem(item);
			}

			// 适配列宽
			for (int i = 0; i < _tw_folderinfo->columnCount(); i += 1) {
				_tw_folderinfo->resizeColumnToContents(i);
				_tw_folderinfo->setColumnWidth(i, _tw_folderinfo->columnWidth(i) + 10);
			}
		});

		QObject::connect(_pb_accept, &QPushButton::clicked, this, [this]() -> void {
			qDebug().noquote() << "QObject::connect(_pb_accept, &QPushButton::clicked, this, [this]() -> void {";

			QString filename = _le_filename->text();
			QStringList filters = _Reduce_Filters(_cb_filters->currentText());
			bool hitted = false;
			for (auto iter = filters.begin(); iter != filters.end(); iter += 1) {
				QString expression = QString("^") + (*iter) + QString("$");
				expression.replace(".", "[.]{1,1}").replace("*", ".{0,}").replace("?", ".{0,1}");
				QRegularExpressionMatch match = QRegularExpression(expression, QRegularExpression::DotMatchesEverythingOption).match(filename, 0, QRegularExpression::NormalMatch);
				if (match.hasMatch() == true) {
					hitted = true;
					break;
				}
			}
			if (hitted == true || filters.size() == 0) {
				_filepath = _folderpath + QString("/") + filename;
			} else {
				QString suffix_complete = QFileInfo(filters.at(0)).completeSuffix();
				while (suffix_complete.contains("*") == true || suffix_complete.contains("?") == true) {
					suffix_complete = QFileInfo(suffix_complete).completeSuffix();
				}
				if (suffix_complete.isEmpty() == false) {
					suffix_complete = QString(".") + suffix_complete;
				}
				_filepath = _folderpath + QString("/") + filename + suffix_complete;
			}

			_filepath = QDir::cleanPath(_filepath);
			qDebug().noquote() << "_filepath = " << _filepath;

			if (_options.value("_alert_overwrite", false) == true && QFileInfo(_filepath).exists() == true) {
				if (QMessageBox::question(this, "提示", "文件已存在。\n覆盖文件吗？", "确定", "取消") == 1) {  // 默认Qt::WindowModal
					_filepath = "";
					return;
				}
			}
			this->accept();
		});

		QObject::connect(_pb_cancel, &QPushButton::clicked, this, &QDialog::reject);
	}

	virtual ~FileDialog() {

	}

public:
	void _Set_Option(const QString& option, bool value) {
		_options[option] = value;
	}

	void _Set_Caption(const QString& caption) {
		this->setWindowTitle(caption);
	}

	void _Set_Folderpath(const QString& folderpath) {
		_folderpath = folderpath;
	}

	void _Set_Filename(const QString& filename) {
		_le_filename->setText(filename);
	}

	QString _Get_Filepath() {
		return _filepath;
	}

	void _Set_Filters(const QStringList& filters) {
		_cb_filters->addItems(filters);
		_cb_filters->setCurrentIndex(0);
	}

	static QString _Reduce_Filesize(double filesize) {
		static QVector<QString> suffixes = {
			"B", "KB", "MB", "GB", "TB"
		};
		int i = 0;
		for (; i < suffixes.size() && 1024 <= filesize; i += 1) {
			filesize /= 1024;
		}
		return (i == 0) ? QString("%1 %2").arg((qint64)filesize).arg(suffixes[i]) : QString("%1 %2").arg(filesize, 0, 'f', 2, ' ').arg(suffixes[i]);
	}

public:
	static QStringList _Reduce_Filters(const QString& filter) {
		/* 示例filter
		QString     filter  = "源代码文件 (*.h, *.cpp)"
		QStringList filters = {
			"*.h", "*.cpp"
		};
		*/
		QStringList filters;
		QRegularExpressionMatch match = QRegularExpression(R"!(^.{1,}[(](.{1,})[)].{0,}$)!", QRegularExpression::DotMatchesEverythingOption).match(filter, 0, QRegularExpression::NormalMatch);
		if (match.hasMatch() == true) {
			// qDebug().noquote() << "match.captured(1) = " << match.captured(1);
			filters = match.captured(1).split(QRegularExpression(R"!([ \t\n\r\v\f]{0,}[,][ \t\n\r\v\f]{0,})!"), QString::SkipEmptyParts);
		}
		return filters;
	}

	static QString _Reduce_Type(const QFileInfo& fileinfo) {
		if (fileinfo.isDir() == true) {
			return "文件夹";
		} else if (fileinfo.isFile() == true) {
			return "文件";
		} else if (fileinfo.isSymLink() == true) {
			return "链接";
		}
		return "";
	}

	static QString _Get_Filepath_Save(QWidget* parent = nullptr, const QString& caption = "", const QString& folderpath = "", const QString& filename = "", const QStringList& filters = QStringList()) {
		/* 示例filters，符号.等价于[.]{1,1}，通配符*等价于.{0,}，通配符?等价于.{0,1}
		QStringList filters = {
			"所有文件 (*)", "源代码文件 (*.h, *.cpp)", "图像文件 (*.png, *.jpg)"
		};
		*/
		FileDialog filedialog(parent);
		filedialog._Set_Option("_alert_overwrite", true);
		filedialog._Set_Caption(caption);
		filedialog._Set_Folderpath(folderpath);
		filedialog._Set_Filename(filename);
		filedialog._Set_Filters(filters);

		filedialog.setWindowModality(Qt::WindowModal);
		QString filepath = "";
		if (filedialog.exec() == QDialog::Accepted) {
			filepath = filedialog._Get_Filepath();
		}
		return filepath;
	}
};
