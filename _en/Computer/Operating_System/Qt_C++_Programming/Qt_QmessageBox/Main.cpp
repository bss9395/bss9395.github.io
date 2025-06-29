#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>
#include <iostream>

void _Test_Information(QWidget* parent) {
    QString title = "information消息框";
    QString info = "文件已经打开，字体大小已设置";
    QMessageBox::information(parent, title, info, QMessageBox::Ok, QMessageBox::NoButton);
}

void _Test_Question(QWidget* parent) {
    QString title = "question消息框";
    QString info = "文件已被修改，是否保存修改？";
    QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
    int result = QMessageBox::question(parent, title, info, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, defaultBtn);
    if (result==QMessageBox::Yes) {
        std::cout << "Question消息框: Yes 被选择" << std::endl;
    }
    else if(result==QMessageBox::No) {
        std::cout << "Question消息框: No 被选择" << std::endl;
    }
    else if(result==QMessageBox::Cancel) {
        std::cout << "Question消息框: Cancel 被选择" << std::endl;
    }
    else {
        std::cout << "Question消息框: 无选择" << std::endl;
    }
}

void _Test_Warning(QWidget* parent) {
    QString title = "warning消息框";
    QString info = "文件内容已经被修改";
    QMessageBox::warning(parent, title, info);
}

void _Test_Critical(QWidget* parent) {
    QString title = "critical消息框";
    QString info = "有不明程序访问网路";
    QMessageBox::critical(parent, title, info);
}

void _Test_About(QWidget* parent) {
    QString title = "about消息框";
    QString info = "我开发的数据查看软件 V1.0 \n 保留所有版权";
    QMessageBox::about(parent, title, info);
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMainWindow mainWindow;
    mainWindow.show();

    _Test_Information(&mainWindow);
//    _Test_Question(&mainWindow);
//    _Test_Warning(&mainWindow);
//    _Test_Critical(&mainWindow);
//    _Test_About(&mainWindow);

    return a.exec();
}
