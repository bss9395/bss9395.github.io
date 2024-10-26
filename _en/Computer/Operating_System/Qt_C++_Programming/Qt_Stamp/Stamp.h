#pragma once

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QDesktopServices>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDir>
#include <QFileInfo>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRegularExpression>
#include <QStyledItemDelegate>
#include <QTreeWidget>
#include <QUrl>
#include <QVector>

struct TreeWidgetDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    QVector<int> _columns;

    explicit TreeWidgetDelegate(QVector<int> columns, QObject *parent)
        : QStyledItemDelegate(parent) {
        _columns = columns;
    }

    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        for(int i = 0; i < _columns.length(); i += 1) {
            if(_columns[i] == index.column()) {
                return QStyledItemDelegate::createEditor(parent, option, index);
            }
        }
        return nullptr;
    }

    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        QStyledItemDelegate::setEditorData(editor, index);
    }

    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QStyledItemDelegate::setModelData(editor, model, index);

        emit ((TreeWidgetDelegate*)this)->_Signal_Edited(index.row(), index.column());
    }

signals:
    void _Signal_Edited(int row, int column);
};

class Stamp : public QDialog {
    Q_OBJECT

public:
    const QColor _color_forground_matched = 0xFFEB3B;
    const QColor _color_forground_replaced = 0x2196F3;
	const QColor _color_forground_renamed = 0x009688;
	const QColor _color_forground_failed = 0xF44336;
    const qint32 _role_filepath = Qt::UserRole + 0;
    const qint32 _role_flag = Qt::UserRole + 1;
    const qint32 _index_header_name = 0;
    const qint32 _index_header_birth = 1;
    const qint32 _index_header_modification = 2;
    const qint32 _index_header_access = 3;
    const qint32 _index_header_size = 4;
    const qint32 _index_header_type = 5;
    const QStringList _header_labels = {
        "名称", "创建时间", "修改时间", "访问时间", "大小", "类型"
    };

public:
    QTreeWidget *_tw_folderinfo = nullptr;
    TreeWidgetDelegate *_tw_delegate = nullptr;
    QLabel *_l_folderpath = nullptr;
    QLineEdit *_le_folderpath = nullptr;
    QPushButton *_pb_folderpath = nullptr;
    QLabel *_l_pattern = nullptr;
    QLineEdit *_le_pattern = nullptr;
    QPushButton *_pb_pattern = nullptr;
    QLabel *_l_replace = nullptr;
    QLineEdit *_le_replace = nullptr;
    QPushButton *_pb_replace = nullptr;
    QPushButton *_pb_confirm = nullptr;
    QPushButton *_pb_close = nullptr;

signals:
	void _Signal_Closed();

public:
    explicit Stamp(QWidget *parent = nullptr)
        : QDialog(parent) {
        _tw_folderinfo = new QTreeWidget();
        _tw_delegate = new TreeWidgetDelegate(QVector<int>{ 0 }, this);
        _tw_folderinfo->setItemDelegate(_tw_delegate);
        QObject::connect(_tw_delegate, &TreeWidgetDelegate::_Signal_Edited, this, [this](int row, int column) -> void {
            // 更新界面
            qDebug().noquote() << "hello, world!";
            QTreeWidgetItem* item = _tw_folderinfo->topLevelItem(row);
            if(_index_header_name == column) {
                item->setData(_index_header_name, _role_flag, "_posi");
                QBrush brush = QBrush(_color_forground_replaced, Qt::SolidPattern);
                item->setForeground(_index_header_name, brush);
            }
        });


        _tw_folderinfo->setEditTriggers(QTreeWidget::SelectedClicked);
        _tw_folderinfo->setHeaderLabels(_header_labels);
        _tw_folderinfo->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        _tw_folderinfo->setAlternatingRowColors(true);
        _tw_folderinfo->setIndentation(0);
        _tw_folderinfo->setSortingEnabled(true);
        _tw_folderinfo->sortByColumn(_index_header_name, Qt::AscendingOrder);
        _tw_folderinfo->header()->setCascadingSectionResizes(true);
        _tw_folderinfo->header()->setDropIndicatorShown(true);
        _tw_folderinfo->header()->setStretchLastSection(true);

        _l_folderpath = new QLabel("目录: ");
        _le_folderpath = new QLineEdit();
        _le_folderpath->setPlaceholderText("请输入目录");
        _pb_folderpath = new QPushButton("切换");
        _pb_folderpath->setAutoDefault(false);
        _l_pattern = new QLabel("模式: ");
        _le_pattern = new QLineEdit();
        _le_pattern->setPlaceholderText("请输入模式");
        _pb_pattern = new QPushButton("匹配");
        _pb_pattern->setAutoDefault(false);
        _l_replace = new QLabel("替换: ");
        _le_replace = new QLineEdit();
        _le_replace->setPlaceholderText("请输入替换");
        _pb_replace = new QPushButton("预览");
        _pb_replace->setAutoDefault(false);
        QGridLayout *gl_form = new QGridLayout();
        gl_form->addWidget(_l_folderpath, 0, 0);
        gl_form->addWidget(_le_folderpath, 0, 1);
        gl_form->addWidget(_pb_folderpath, 0, 2);
        gl_form->addWidget(_l_pattern, 1, 0);
        gl_form->addWidget(_le_pattern, 1, 1);
        gl_form->addWidget(_pb_pattern, 1, 2);
        gl_form->addWidget(_l_replace, 2, 0);
        gl_form->addWidget(_le_replace, 2, 1);
        gl_form->addWidget(_pb_replace, 2, 2);

        _pb_confirm = new QPushButton("确定");
        _pb_confirm->setAutoDefault(false);
        _pb_confirm->setDefault(false);
        _pb_close = new QPushButton("取消");
        _pb_close->setAutoDefault(false);
        _pb_close->setDefault(false);
        QDialogButtonBox *dbb_box = new QDialogButtonBox();
        dbb_box->setOrientation(Qt::Horizontal);
        dbb_box->addButton(_pb_confirm, QDialogButtonBox::YesRole);    // 设置为AcceptRole会自动设置default button
        dbb_box->addButton(_pb_close, QDialogButtonBox::NoRole);

        QGridLayout *gl_grid = new QGridLayout();
        gl_grid->addWidget(_tw_folderinfo, 0, 0);
        gl_grid->addLayout(gl_form, 1, 0);
        gl_grid->addWidget(dbb_box, 2, 0);
        this->setLayout(gl_grid);
        this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        this->resize(1000, 800);
        // Dialog会自动居中显示在父缘顶层窗口。

        ////////////////////////////////

        QObject::connect(_tw_folderinfo, &QTreeWidget::itemDoubleClicked, this, [this](QTreeWidgetItem *item, int column) -> void {
            (void)column;
            qDebug().noquote() << "QObject::connect(_tw_folderinfo, &QTreeWidget::itemDoubleClicked, this, [this](QTreeWidgetItem *item, int column) -> void {";
            QString filepath = item->data(_index_header_name, _role_filepath).toString();
            QString url = QString("file:///%1").arg(filepath);
            qDebug().noquote() << QString("url = %1").arg(url);
            QDesktopServices::openUrl(QUrl(url, QUrl::TolerantMode));
        });

        QObject::connect(_pb_folderpath, &QPushButton::clicked, this, [this]() -> void {
            qDebug().noquote() << "QObject::connect(_pb_folderpath, &QPushButton::clicked, this, [this]() -> void {";
            _tw_folderinfo->clear();
            QFileInfoList folderinfo = QDir(_le_folderpath->text()).entryInfoList(QStringList(), QDir::Files | QDir::NoDotAndDotDot, QDir::Name);
            for(auto iter = folderinfo.begin(); iter != folderinfo.end(); iter += 1) {
                const QFileInfo& fileinfo = (*iter);
                QTreeWidgetItem* item = new QTreeWidgetItem();
                item->setFlags(item->flags() | Qt::ItemIsEditable);
                item->setData(_index_header_name, _role_filepath, fileinfo.filePath());
				item->setData(_index_header_name, _role_flag, "_none");
                item->setText(_index_header_name, fileinfo.fileName());
                item->setText(_index_header_birth, fileinfo.fileTime(QFile::FileBirthTime).toString(Qt::ISODateWithMs));
                item->setText(_index_header_modification, fileinfo.fileTime(QFile::FileModificationTime).toString(Qt::ISODateWithMs));
                item->setText(_index_header_access, fileinfo.fileTime(QFile::FileAccessTime).toString(Qt::ISODateWithMs));
                item->setText(_index_header_size, _Reduce_Filesize(fileinfo.size()));
                item->setText(_index_header_type, _Reduce_Type(fileinfo));
                _tw_folderinfo->addTopLevelItem(item);
            }

            // 适配列宽
            for(int i = 0; i < _tw_folderinfo->columnCount(); i += 1) {
                _tw_folderinfo->resizeColumnToContents(i);
                _tw_folderinfo->setColumnWidth(i, _tw_folderinfo->columnWidth(i) + 10);
            }
        });

        QObject::connect(_pb_pattern, &QPushButton::clicked, this, [this]() -> void {
            qDebug().noquote() << "QObject::connect(_pb_pattern, &QPushButton::clicked, this, [this]() -> void {";
            QString pattern = _le_pattern->text();
            QBrush brush = QBrush(_color_forground_matched, Qt::SolidPattern);
            for(int i = 0, end = _tw_folderinfo->topLevelItemCount(); i < end; i += 1) {
                QTreeWidgetItem* item = _tw_folderinfo->topLevelItem(i);
                QRegularExpressionMatch match = QRegularExpression(pattern, QRegularExpression::DotMatchesEverythingOption).match(item->text(_index_header_name), 0, QRegularExpression::NormalMatch);
                if(match.hasMatch() == true) {
                    item->setForeground(_index_header_name, brush);
                }
            }
        });

        QObject::connect(_pb_replace, &QPushButton::clicked, this, [this]() -> void {
			/* 示例: 模式替换
			pattern: ^([0-9]{4,4})([0-9]{2,2})([0-9]{2,2})_([0-9]{2,2})([0-9]{2,2})([0-9]{2,2}).{0,}([.]{1,1}jpg)$
			replace: (1)-(2)-(3)T(4)-(5)-(6)@Shanghai(7)
			*/
            qDebug().noquote() << "QObject::connect(_pb_replace, &QPushButton::clicked, this, [this]() -> void {";
			_tw_folderinfo->setSortingEnabled(false);
            QBrush brush = QBrush(_color_forground_replaced, Qt::SolidPattern);
            QString pattern = _le_pattern->text();
            QString replace = _le_replace->text();            
            for(int i = 0, endi = _tw_folderinfo->topLevelItemCount(); i < endi; i += 1) {
                QTreeWidgetItem* item = _tw_folderinfo->topLevelItem(i);
                QRegularExpressionMatch match = QRegularExpression(pattern, QRegularExpression::DotMatchesEverythingOption).match(item->text(_index_header_name), 0, QRegularExpression::NormalMatch);
                if(match.hasMatch() == true) {
                    QString substitute = "";
					// 替换打印
                    for(int offset_head = 0, offset_tail = offset_head; offset_tail < replace.length(); ) {
                        QRegularExpressionMatch holder = QRegularExpression("[(]([0-9]{1,})[)]", QRegularExpression::DotMatchesEverythingOption).match(replace, offset_tail, QRegularExpression::NormalMatch);
                        if(holder.hasMatch() == true) {
                            int index = holder.captured(1).toUInt();
                            if((1 <= index && index <= match.lastCapturedIndex()) == false) {
                                offset_tail = holder.capturedEnd(0);
                                continue;
                            }
                            substitute += replace.mid(offset_head, holder.capturedStart(0) - offset_head);
                            substitute += match.captured(index);
                            offset_head = holder.capturedEnd(0);
                            offset_tail = offset_head;
                        } else {
                            substitute += replace.mid(offset_head, replace.length() - offset_head);
                            break;
                        }
                    }

					// 重名检测
					int increase = 1;
					for (bool hit = true; hit == true; ) {
						hit = false;
						for (int j = 0, endj = _tw_folderinfo->topLevelItemCount(); j < endj; j += 1) {
							QTreeWidgetItem *check = _tw_folderinfo->topLevelItem(j);
							if (check->text(_index_header_name) == substitute) {
								hit = true;
								QFileInfo fileinfo = QFileInfo(substitute);
								QString filename = fileinfo.baseName();
								QString filesuffix = fileinfo.completeSuffix();
								substitute = filename + QString("#%1").arg(increase) + (filesuffix.isEmpty() == false ? "." + filesuffix : "");
								break;
							}
						}
					}

					// 更新界面
                    item->setData(_index_header_name, _role_flag, "_posi");
                    item->setText(_index_header_name, substitute);
                    item->setForeground(_index_header_name, brush);

					// 适配列宽
					for (int i = 0; i < _tw_folderinfo->columnCount(); i += 1) {
						_tw_folderinfo->resizeColumnToContents(i);
						_tw_folderinfo->setColumnWidth(i, _tw_folderinfo->columnWidth(i) + 10);
					}
                }
            }
			_tw_folderinfo->setSortingEnabled(true);
        });

		QObject::connect(_pb_confirm, &QPushButton::clicked, this, [this]() -> void {
			qDebug().noquote() << "QObject::connect(_pb_confirm, &QPushButton::clicked, this, [this]() -> void {";
			QBrush brush_renamed = QBrush(_color_forground_renamed, Qt::SolidPattern);
			QBrush brush_failed = QBrush(_color_forground_failed, Qt::SolidPattern);
			for (int i = 0, endi = _tw_folderinfo->topLevelItemCount(); i < endi; i += 1) {
				QTreeWidgetItem* item = _tw_folderinfo->topLevelItem(i);
				if (item->data(_index_header_name, _role_flag).toString() == "_posi") {
                    QString filepath_old = item->data(_index_header_name, Qt::UserRole).toString();
                    QString folderpath = QFileInfo(filepath_old).path() + "/";
					QString filename_new = item->text(_index_header_name);
                    bool renamed = QFile::rename(filepath_old, folderpath + filename_new);
					if (renamed == true) {
						item->setData(_index_header_name, _role_flag, "_none");
						item->setForeground(_index_header_name, brush_renamed);
					} else if (renamed == false) {
						item->setForeground(_index_header_name, brush_failed);
					}
				}
			}
		});

        QObject::connect(_pb_close, &QPushButton::clicked, this, &QDialog::close);  // use QDialog::close instead of QDialog::reject
    }

    virtual ~Stamp() {

    }

public:
	virtual void closeEvent(QCloseEvent *event) override {
		(void)event;
		emit _Signal_Closed();
	}

public:
    void _Set_Folderpath(const QString& folderpath) {
        _le_folderpath->setText(folderpath);
    }

    void _Set_Pattern(const QString& pattern) {
        _le_pattern->setText(pattern);
    }

    void _Set_Replace(const QString& replace) {
        _le_replace->setText(replace);
    }

public:
    static QString _Reduce_Filesize(double filesize) {
        static QVector<QString> suffixes = {
            "B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"
        };
        int i = 0;
        for (; i < suffixes.size() && 1024 <= filesize; i += 1) {
            filesize /= 1024;
        }
        return (i == 0) ? QString("%1 %2").arg((qint64)filesize).arg(suffixes[i]) : QString("%1 %2").arg(filesize, 0, 'f', 2, ' ').arg(suffixes[i]);
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
};

static void _Test_Stamp() {
	Stamp *stamp = new Stamp();
	QObject::connect(stamp, &Stamp::_Signal_Closed, stamp, [stamp]() mutable -> void {
		delete stamp; stamp = nullptr;
	});

    stamp->_Set_Folderpath("E:/Pictures/");
	stamp->_Set_Pattern("^([0-9]{4,4})([0-9]{2,2})([0-9]{2,2})_([0-9]{2,2})([0-9]{2,2})([0-9]{2,2}).{0,}([.]{1,1}jpg)$");
    stamp->_Set_Replace("(1)-(2)-(3)T(4)-(5)-(6)@ShangHai(7)");
	stamp->show();
}
