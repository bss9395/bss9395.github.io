/* FileSystem.h
Author: BSS9395
Update: 2022-06-23T21:53:00+08@China-Shanghai+08
Design: FileSystem
Encode: UTF-8
System: Qt 5.14.2
*/

#ifndef File_h
#define File_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "ui_FileSystem.h"
#include "Delegate.h"

class FileSystem : public QMainWindow {
    Q_OBJECT

public:
    typedef Sequence<iptr, const char *, const char *> Type;
    static inline const Type _Text = Type(0, "Text", "W_Text");
    static inline const Type _Binary = Type(1, "Binary", "W_Binary");
    static inline const Type _File = Type(2, "File", "W_File");
    static inline const QDataStream::Version _Version = QDataStream::Qt_5_9;
    static inline const QDataStream::ByteOrder _ByteOrder = QDataStream::BigEndian;

public:
    Ui::FileSystem *_ui = nullptr;
    QFileSystemWatcher _watcher;
    QComboBox_Delegate _gender_delegate = QComboBox_Delegate(QStringList(), this);

public:
    explicit FileSystem(QWidget *parent = nullptr)
        : QMainWindow(parent), _ui(new Ui::FileSystem) {
        _ui->setupUi(this);

        QObject::connect(_ui->PB_Open_Text, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Open_Text, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "打开文本";
            QString filter = "C++文件(*.h *.hpp *.cpp);;文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            QFile file(filename);
            if(file.open(QFile::ReadWrite | QFile::Text) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite | QFile::Text) == false) {", NULL);
                return;
            }
            _ui->PTE_Text->clear();
            QByteArray bytes = file.readAll();                         // note: read file by encoding UTF-8.
            _ui->PTE_Text->setPlainText(QString::fromUtf8(bytes));
            _ui->TW_File->setCurrentIndex(_Text.At<0>());
        });

        QObject::connect(_ui->PB_Save_Text, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Save_Text, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "保存文本";
            QString filter = "C++文件(*.h *.hpp *.cpp);;文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
            QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            QFile file(filename);
            if(file.open(QFile::ReadWrite | QFile::Text) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite | QFile::Text) == false) {", NULL);
                return;
            }
            QByteArray bytes = _ui->PTE_Text->toPlainText().toUtf8();
            file.write(bytes, bytes.length());
            _ui->TW_File->setCurrentIndex(_Text.At<0>());
        });

        QObject::connect(_ui->PB_Open_TextStream, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Open_TextStream, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "打开文本流";
            QString filter = "C++文件(*.h *.hpp *.cpp);;文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            QFile file(filename);
            if(file.open(QFile::ReadWrite | QFile::Text) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite | QFile::Text) == false) {", NULL);
                return;
            }
            QTextStream stream(&file);
            // stream.setAutoDetectUnicode(true);
            stream.setCodec("UTF-8");
            _ui->PTE_Text->clear();
            _ui->PTE_Text->setPlainText(stream.readAll());
            _ui->TW_File->setCurrentIndex(_Text.At<0>());
        });

        QObject::connect(_ui->PB_Save_TextStream, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Save_TextStream, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "保存文本流";
            QString filter = "C++文件(*.h *.hpp *.cpp);;文本文件(*.txt;*.text);; Markdown(*.md;*.markdown);; Html(*.html);; 所有文件(*.*)";
            QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return ;
            }
            QFile file(filename);
            if(file.open(QFile::ReadWrite | QFile::Text) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite | QFile::Text) == false) {", NULL);
                return;
            }
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream << _ui->PTE_Text->toPlainText();
            _ui->TW_File->setCurrentIndex(_Text.At<0>());
        });

        QObject::connect(_ui->PB_Open_DataStream, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Open_DataStream, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "打开格式流";
            QString filter = "格式流(*.stm);;所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            QFile file(filename);
            if(file.open(QFile::ReadWrite) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite) == false) {", NULL);
                return;
            }
            QDataStream stream(&file);
            stream.setVersion(_Version);
            stream.setByteOrder(_ByteOrder);
            _ui->TW_Binary->setColumnCount(0);
            _ui->TW_Binary->setRowCount(0);
            if(stream.atEnd() == false) {
                iptr cols = 0;
                iptr rows = 0;
                stream >> cols;
                stream >> rows;
                _ui->TW_Binary->setColumnCount(cols);
                _ui->TW_Binary->setRowCount(rows);

                QString text = "";
                iptr married = -1;
                for(iptr col = 0; col < cols; col += 1) {
                    stream >> text;
                    _ui->TW_Binary->setHorizontalHeaderItem(col, new QTableWidgetItem(text));
                    if(text == "Gender") {
                        _gender_delegate = QComboBox_Delegate(QStringList{"Male", "Female"}, this);
                        _ui->TW_Binary->setItemDelegateForColumn(col, &_gender_delegate);
                    }
                    else if(text == "Married") {
                        married = col;
                    }
                }

                for(iptr row = 0; row < rows; row += 1) {
                    for(iptr col = 0; col < cols; col += 1) {
                        stream >> text;
                        QTableWidgetItem *item = new QTableWidgetItem(text);
                        _ui->TW_Binary->setItem(row, col, item);
                        if(col == married) {
                            item->setCheckState(text == "yes" ? Qt::Checked : Qt::Unchecked);
                        }
                    }
                }
            }
            _ui->TW_File->setCurrentIndex(_Binary.At<0>());
        });

        auto save_datastream = [this](const QString &filename) -> void {
            QFile file(filename);
            if(file.open(QFile::ReadWrite | QFile::Truncate) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite | QFile::Truncate) == false) {", NULL);
                return;
            }
            QDataStream stream(&file);
            stream.setVersion(_Version);
            stream.setByteOrder(_ByteOrder);
            iptr cols = _ui->TW_Binary->columnCount();
            iptr rows = _ui->TW_Binary->rowCount();
            stream << cols;
            stream << rows;

            for(iptr col = 0; col < cols; col += 1) {
                stream << _ui->TW_Binary->horizontalHeaderItem(col)->text();
            }

            for(iptr row = 0; row < rows; row += 1) {
                for(iptr col = 0; col < cols; col += 1) {
                    stream << _ui->TW_Binary->item(row, col)->text();
                }
            }
        };
        QObject::connect(_ui->PB_Save_DataStream, &QPushButton::clicked, this, [this, &save_datastream]() -> void {
            System::Logging("QObject::connect(_ui->PB_Save_DataStream, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "保存格式流";
            QString filter = "格式流(*.stm);;所有文件(*.*)";
            QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            save_datastream(filename);
            _ui->TW_File->setCurrentIndex(_Binary.At<0>());
        });

        QObject::connect(_ui->PB_Open_Binary, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Open_Binary, &QPushButton::clicked, this, [this]() -> void {");
            auto read_string = [](QFile &file, QString &text) -> void {
                static QByteArray bytes = QByteArray(1024, '\0');
                int leng = 0;
                file.read((char *)&leng, sizeof(leng));
                if(bytes.length() < leng) {
                    bytes.reserve(leng);
                }
                file.read((char *)bytes.data(), leng);
                bytes.resize(leng);
                text = QString::fromUtf8(bytes);
            };

            QString caption = "打开二进制";
            QString filter = "二进制(*.dat);;所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            QFile file(filename);
            if(file.open(QFile::ReadWrite) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite) == false) {", NULL);
                return;
            }
            _ui->TW_Binary->setColumnCount(0);
            _ui->TW_Binary->setRowCount(0);
            if(file.atEnd() == false) {
                iptr cols = 0;
                iptr rows = 0;
                file.read((char *)&cols, sizeof(cols));
                file.read((char *)&rows, sizeof(rows));
                _ui->TW_Binary->setColumnCount(cols);
                _ui->TW_Binary->setRowCount(rows);

                QString text = "";
                iptr married = -1;
                for(iptr col = 0; col < cols; col += 1) {
                    read_string(file, text);
                    _ui->TW_Binary->setHorizontalHeaderItem(col, new QTableWidgetItem(text));
                    if(text == "Married") {
                        married = col;
                    }
                }
                for(iptr row = 0; row < rows; row += 1) {
                    for(iptr col = 0; col < cols; col += 1) {
                        read_string(file, text);
                        QTableWidgetItem *item = new QTableWidgetItem(text);
                        _ui->TW_Binary->setItem(row, col, item);
                        if(col == married) {
                            item->setCheckState(text == "yes" ? Qt::Checked : Qt::Unchecked);
                        }
                    }
                }
            }
        });

        auto save_binary = [this](const QString &filename) -> void {
            auto write_string = [](QFile& file, const QString& text) -> void {
                QByteArray bytes = text.toUtf8();
                int leng = bytes.length();
                file.write((char *)&leng, sizeof(leng));
                file.write((char *)bytes.data(), leng);
            };

            QFile file(filename);
            if(file.open(QFile::ReadWrite) == false) {
                System::Checking(true, System::_Error, "if(file.open(QFile::ReadWrite) == false) {", NULL);
                return;
            }
            iptr cols = _ui->TW_Binary->columnCount();
            iptr rows = _ui->TW_Binary->rowCount();
            file.write((char *)&cols, sizeof(cols));
            file.write((char *)&rows, sizeof(rows));

            for(iptr col = 0; col < cols; col += 1) {
                write_string(file, _ui->TW_Binary->horizontalHeaderItem(col)->text());
            }
            for(iptr row = 0; row < rows; row += 1) {
                for(iptr col = 0; col < cols; col += 1) {
                    write_string(file, _ui->TW_Binary->item(row, col)->text());
                }
            }
        };
        QObject::connect(_ui->PB_Save_Binary, &QPushButton::clicked, this, [this, &save_binary]() -> void {
            System::Logging("QObject::connect(_ui->PB_Save_Binary, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "保存二进制";
            QString filter = "二进制(*.dat);;所有文件(*.*)";
            QString filename = QFileDialog::getSaveFileName(this, caption, QDir::currentPath(), filter);
            if((0 < filename.size()) == false) {
                return;
            }
            save_binary(filename);
            _ui->TW_File->setCurrentIndex(_Binary.At<0>());
        });

        QObject::connect(_ui->PB_Open_File, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Open_File, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "打开文件";
            QString filter = "所有文件(*.*)";
            QString filename = QFileDialog::getOpenFileName(this, caption, QDir::currentPath(), filter);
            _ui->LE_Path->setText(filename);
        });

        QObject::connect(_ui->PB_Open_Directory, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Open_Directory, &QPushButton::clicked, this, [this]() -> void {");

            QString caption = "打开目录";
            QString directory = QFileDialog::getExistingDirectory(this, caption, QDir::currentPath());
            _ui->LE_Path->setText(directory);
        });

        QObject::connect(_ui->PB_QFileInfo, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_FileInfo, &QPushButton::clicked, this, [this]() -> void {");

            QFileInfo info(_ui->LE_Path->text());
            QString absoluteFilePath = info.absoluteFilePath();
            QString absolutePath = info.absolutePath();
            QString baseName = info.baseName();
            QString completeBaseName = info.completeBaseName();
            QString completeSuffix = info.completeSuffix();
            QString created = info.birthTime().toString("yyyy-MM-ddThh:mm:ss");
            QString fileName = info.fileName();
            QString filePath = info.filePath();
            QString lastModified = info.lastModified().toString("yyyy-MM-ddThh:mm:ss");
            QString lastRead = info.lastRead().toString("yyyy-MM-ddThh:mm:ss");
            QString path = info.path();
            QString suffix = info.suffix();
            bool static_exists = QFileInfo::exists(_ui->LE_Path->text());
            bool exists = info.exists();
            bool isDir = info.isDir();
            bool isExecutable = info.isExecutable();
            bool isFile = info.isFile();
            iptr size = info.size();

            QString text = "";
            text += "absoluteFilePath() = " + absoluteFilePath + "\n";
            text += "absolutePath()     = " + absolutePath + "\n";
            text += "baseName()         = " + baseName + "\n";
            text += "completeBaseName() = " + completeBaseName + "\n";
            text += "completeSuffix()   = " + completeSuffix + "\n";
            text += "create()           = " + created + "\n";
            text += "fileName()         = " + fileName + "\n";
            text += "filePath()         = " + filePath + "\n";
            text += "lastModified()     = " + lastModified + "\n";
            text += "lastRead()         = " + lastRead + "\n";
            text += "path()             = " + path + "\n";
            text += "suffix()           = " + suffix + "\n";
            text += "static_exists()    = " + (QString)(static_exists ? "true" : "false") + "\n";
            text += "exits()            = " + (QString)(exists ? "true" : "false") + "\n";
            text += "isDir()            = " + (QString)(isDir ? "true" : "false") + "\n";
            text += "isExecutable()     = " + (QString)(isExecutable ? "true" : "false") + "\n";
            text += "isFile()           = " + (QString)(isFile ? "true" : "false") + "\n";
            text += "size()             = " + QString::asprintf("%td", size) + "\n";
            _ui->PTE_File->clear();
            _ui->PTE_File->setPlainText(text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        QObject::connect(_ui->PB_QCoreApplication, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QCoreApplication, &QPushButton::clicked, this, [this]() -> void {");

            QString applicationDirPath = QCoreApplication::applicationDirPath();
            QString applicationFilePath = QCoreApplication::applicationFilePath();
            QString applicationName = QCoreApplication::applicationName();
            QStringList libraryPath = QCoreApplication::libraryPaths();
            QString organizationName = QCoreApplication::organizationName();

            QString text = "";
            text += "applicationDirPath()  = " + applicationDirPath + "\n";
            text += "applicationFilePath() = " + applicationFilePath + "\n";
            text += "applicationName()     = " + applicationName + "\n";
            for(iptr i = 0, count = libraryPath.count(); i < count; i += 1) {
                text += "libraryPath()         = " + libraryPath[i] + "\n";
            }
            text += "organizationName()    = " + organizationName + "\n";
            _ui->PTE_File->clear();
            _ui->PTE_File->setPlainText(text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        QObject::connect(_ui->PB_QFile, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QFile, &QPushButton::clicked, this, [this]() -> void {");

            QString text = "";
            QString filename = _ui->LE_Path->text();
            QFileInfo info(filename);
            if(info.isFile() == true) {
                QString filename_static_copy = info.path() + "/" + info.completeBaseName() + "_static_copy." + info.suffix();
                QString filename_static_rename = info.path() + "/" + info.completeBaseName() + "_static_rename." + info.suffix();

                bool static_exists = QFile::exists(filename);
                QFile::copy(filename, filename_static_copy);
                QFile::rename(filename_static_copy, filename_static_rename);
                QFile::remove(filename_static_rename);

                text += "    " + filename + "\n";
                text += " == " + (QString)(static_exists ? "true" : "false") + "\n";
                text += " => " + filename_static_copy + "\n";
                text += " -> " + filename_static_rename + "\n";
                text += " -- " + QString() + "\n";
            }

            _ui->PTE_File->clear();
            _ui->PTE_File->setPlainText(text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        QObject::connect(_ui->PB_QDir, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QDir, &QPushButton::clicked, this, [this]() -> void {");

            QFileInfoList drives = QDir::drives();
            QString currentPath = QDir::currentPath();
            QString homePath = QDir::homePath();
            QString rootPath = QDir::rootPath();
            QString tempPath = QDir::tempPath();

            QDir dir(_ui->LE_Path->text());
            QString absolutePath = dir.absolutePath();
            QString canonicalPath = dir.canonicalPath();
            QString dirName = dir.dirName();
            QStringList entryList = dir.entryList(QDir::AllEntries);
            bool exists = dir.exists();
            bool mkdir = dir.mkdir("temp/");
            bool rename = dir.rename("temp/", "tmp/");
            bool rmdir = dir.rmdir("tmp/");

            QString text = "";
            for(iptr i = 0; i < drives.count(); i += 1) {
                text += "drives()                    = " + drives[i].path() + "\n";
            }
            text += "currentPath()               = " + currentPath + "\n";
            text += "homePath()                  = " + homePath + "\n";
            text += "rootPath()                  = " + rootPath + "\n";
            text += "tempPath()                  = " + tempPath + "\n";
            text += "absolutePath()              = " + absolutePath + "\n";
            text += "canonicalPath()             = " + canonicalPath + "\n";
            text += "dirName()                   = " + dirName + "\n";
            for(iptr i = 0; i < entryList.count(); i += 1) {
                text += "entryList(QDir::AllEntries) = " + entryList[i] + "\n";
            }
            text += "exists()                    = " + (QString)(exists ? "true" : "false") + "\n";
            text += R"(mkdir("temp/")            = )" + (QString)(mkdir ? "true" : " false") + "\n";
            text += R"(rename("temp/", "tmp/")   = )" + (QString)(rename ? "true" : "false") + "\n";
            text += R"(rmdir("tmp/")             = )" + (QString)(rmdir ? "true" : "false") + "\n";

            _ui->PTE_File->clear();
            _ui->PTE_File->setPlainText(text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        QObject::connect(_ui->PB_QTemporayDir, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QTemporayDir, &QPushButton::clicked, this, [this]() -> void {");

            QTemporaryDir dir;
            dir.setAutoRemove(true);
            QString text = "";
            text += "temporary directory = " + dir.path() + "\n";

            _ui->PTE_File->clear();
            _ui->PTE_File->setPlainText(text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        QObject::connect(_ui->PB_QTemporaryFile, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_QTemporaryFile, &QPushButton::clicked, this, [this]() -> void {");

            QTemporaryFile file;
            file.setAutoRemove(true);
            file.open();
            QByteArray bytes = "Hello, World!\n";
            file.write(bytes, bytes.length());
            file.reset();
            bytes = file.readAll();
            _ui->PTE_File->clear();
            _ui->PTE_File->setPlainText(bytes);

            QString text = "";
            text += "temporary file = " + file.fileName() + "\n";
            _ui->PTE_File->setPlainText(_ui->PTE_File->toPlainText() + text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        QObject::connect(&_watcher, &QFileSystemWatcher::directoryChanged, this, [this](const QString &path) -> void {
            System::Logging("QObject::connect(&_watcher, &QFileSystemWatcher::directoryChanged, this, [this](const QString &path) -> void {");

            QString text = "";
            text += "directory changed: " + path + "\n";
            _ui->PTE_File->setPlainText(_ui->PTE_File->toPlainText() + text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });
        QObject::connect(&_watcher, &QFileSystemWatcher::fileChanged, this, [this](const QString &path) -> void {
            System::Logging("QObject::connect(&_watcher, &QFileSystemWatcher::fileChanged, this, [this](const QString &path) -> void {");

            QString text = "";
            text += "file changed     : " + path + "\n";
            _ui->PTE_File->setPlainText(_ui->PTE_File->toPlainText() + text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });
        QObject::connect(_ui->PB_Attach, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Attach, &QPushButton::clicked, this, [this]() -> void {");

            _watcher.addPath(_ui->LE_Path->text());
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });
        QObject::connect(_ui->PB_Detach, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Detach, &QPushButton::clicked, this, [this]() -> void {");

            _watcher.removePath(_ui->LE_Path->text());
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });
        QObject::connect(_ui->PB_Directories, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Directories, &QPushButton::clicked, this, [this]() -> void {");

            QStringList directories = _watcher.directories();
            QString text = "";
            for(iptr i = 0; i < directories.count(); i += 1) {
                text += "directory = " + directories[i] + "\n";
            }
            _ui->PTE_File->setPlainText(_ui->PTE_File->toPlainText() + text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });
        QObject::connect(_ui->PB_Files, &QPushButton::clicked, this, [this]() -> void {
            System::Logging("QObject::connect(_ui->PB_Files, &QPushButton::clicked, this, [this]() -> void {");

            QStringList files = _watcher.files();
            QString text = "";
            for(iptr i = 0; i < files.count(); i += 1) {
                text += "file =      " + files[i] + "\n";
            }
            _ui->PTE_File->setPlainText(_ui->PTE_File->toPlainText() + text);
            _ui->TW_File->setCurrentIndex(_File.At<0>());
        });

        ////////////////////////////////

        save_datastream(QDir::currentPath() + "/temp.stm");
        save_binary(QDir::currentPath() + "/temp.dat");
        _ui->TW_Binary->setColumnCount(0);
        _ui->TW_Binary->setRowCount(0);
    }

    virtual ~FileSystem() {
        delete _ui;
    }

public:

};

#endif // File_h
