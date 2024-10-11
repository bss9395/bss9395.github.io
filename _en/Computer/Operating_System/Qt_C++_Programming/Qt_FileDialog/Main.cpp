/* Main.cpp
Author: bss9395
Update: 2024-09-24T11:50:00+08@China-Beijing+08
*/


#include <QApplication>
#include "FileDialog.h"

static void _Test_QFileDialog_getSaveFileName() {
    QString caption = "保存文件";
    QString folderpath = QCoreApplication::applicationDirPath() + QString("/") + "Main.c";  // Main.c识别为文件名
    QString filters = "所有文件 (*);;源代码文件(*.h *.cpp);;可执行文件(*.exe)";
    QString filepath = QFileDialog::getSaveFileName(nullptr, caption, folderpath, filters);
    qDebug().noquote() << "filepath = " << filepath;
}

static void _Test_QFileDialog_Save() {
    QFileDialog filedialog;
    filedialog.setAcceptMode(QFileDialog::AcceptSave);
    filedialog.setFileMode(QFileDialog::AnyFile);  // what the user may select in the file dialog, what the dialog will return
    filedialog.setViewMode(QFileDialog::Detail);
    filedialog.setOption(QFileDialog::DontUseNativeDialog, true);
    filedialog.setOption(QFileDialog::DontConfirmOverwrite, false);
    filedialog.setDirectory(QCoreApplication::applicationDirPath());
    filedialog.setNameFilter("所有文件 (*);;源代码文件 (*.h *.cpp);;可执行文件(*.exe)");
    filedialog.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);

    QStringList filenames;
    if (filedialog.exec()) {
        filenames = filedialog.selectedFiles();
    }
    qDebug().noquote() << filenames;
}

static void _Test_FileDialog() {
	QString caption = "保存文件";
	QString folderpath = "E:/source/repos/FileDialog/FileDialog/";
	QString filename = "untitled";
	QStringList filters = {
		"所有文件 (*)",
		"源代码文件 (*.h, *.cpp)",
		"图像文件 (*.png, *.jpg)"
	};
	FileDialog::_Get_Filepath_Save(nullptr, caption, folderpath, filename, filters);
}

int main(int argc, char *argv[]) {
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication application(argc, argv);

    // _Test_QFileDialog_getSaveFileName();
    // _Test_QFileDialog_Save();
    _Test_FileDialog();

    return application.exec();
}
