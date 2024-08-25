#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QException>
#include <QLibrary>
#include "Depend.h"
#include "Section/Section.h"
#include "Common.h"
#include "Shared.h"
#include "Plugin.h"


// 采用隐式链接可以直接创建类对象并调用类的函数
void _Implicit_Linking() {
    // 采用隐式链接，链接时需要链接.lib文件，在.pro中添加LIBS += -L$$Root_Working/Common/ -lCommon
    // 采用隐式链接，运行时需要加载.dll文件，在脚本中添加PATH = $$Root_Working/Common/;%PATH%
    Common common;
    common._Member_Operate("Operate");
    common._Virtual_Operate("Operate");

    Section section;
    section._Member_Pofile("Profile");
    section._Virtual_Profile("Profile");
}

////////////////////////////////////////////////////////////////////////////////

// 采用显式链接只能动态调用类的虚函数
void _Explicit_Linking_Load() {
    // 若动态库中有依赖库未加载，则会导致该动态库加载失败，并且无任何提示信息。
    QString sharedpath = QCoreApplication::applicationDirPath() + "/../Shared/";
    QLibrary sharedload(sharedpath + QString("/") + "Shared");  // 加载动态库名不需要附加前缀和后缀。
    if(sharedload.load() == true) {
        qDebug().noquote() << QString("加载Shared成功: %1").arg(QDir::cleanPath(sharedload.fileName()));
    } else {
        qDebug().noquote() << QString("加载Shared失败: %1").arg(sharedload.errorString());
        sharedload.unload();  // 加载失败的动态库应当卸载，否则会导致二次加载该动态库失败。
    }

    // 若动态库中有依赖库已加载，则可成功二次加载该动态库，前提是卸载该动态库。
    QString dependpath = QCoreApplication::applicationDirPath() + "/../Depend/";
    QLibrary dependload(dependpath + QString("/") + "Depend");  // 加载动态库名不需要附加前缀和后缀。
    if(dependload.load() == true) {
        qDebug().noquote() << QString("加载Depend成功: %1").arg(QDir::cleanPath(dependload.fileName()));
    } else {
        qDebug().noquote() << QString("加载Depend失败: %1").arg(dependload.errorString());
        dependload.unload();  // 加载失败的动态库应当卸载，否则会导致二次加载该动态库失败。
    }

    typedef Common *(*Func_Handle)();
    Func_Handle instance = (Func_Handle)sharedload.resolve("_Instance");
    qDebug().noquote() << QString("instance = 0x%1").arg((quint64)instance, 0, 16, QChar(' '));

    Shared *shared = (Shared *)instance();
    // shared->_Member_Greeting("Greeting");  // 采用显式链接只能动态调用类的虚函数
    shared->_Virtual_Dependence();
    delete shared, shared = nullptr;
}

void _Explicit_Linking_Path() {
    static auto _Add_EnvironmentPath = [](const QByteArray envi, const QByteArray& addon) -> void {
        QByteArray path = qgetenv(envi);
        path = addon + ";" + path;
        qputenv(envi, path);

        // qDebug().noquote() << QString("%1 = %2").arg(QString::fromLocal8Bit(envi), QString::fromLocal8Bit(qgetenv(envi)));
    };

    QString dependpath = QCoreApplication::applicationDirPath() + "/../Depend/";
    _Add_EnvironmentPath("PATH", dependpath.toLocal8Bit());

    // 若动态库中有依赖库未加载，则会导致该动态库加载失败，并且无任何提示信息。
    QString sharedpath = QCoreApplication::applicationDirPath() + "/../Shared/";
    QLibrary sharedload(sharedpath + QString("/") + "Shared");  // 加载动态库名不需要附加前缀和后缀。
    if(sharedload.load() == true) {
        qDebug().noquote() << QString("加载Shared成功: %1").arg(QDir::cleanPath(sharedload.fileName()));
    } else {
        qDebug().noquote() << QString("加载Shared失败: %1").arg(sharedload.errorString());
        sharedload.unload();  // 加载失败的动态库应当卸载，否则会导致二次加载该动态库失败。
    }

    typedef Common *(*Func_Handle)();
    Func_Handle instance = (Func_Handle)sharedload.resolve("_Instance");
    qDebug().noquote() << QString("instance = 0x%1").arg((quint64)instance, 0, 16, QChar(' '));

    Shared *shared = (Shared *)instance();
    // shared->_Member_Greeting("Greeting");  // 采用显式链接只能动态调用类的虚函数
    shared->_Virtual_Dependence();
    delete shared, shared = nullptr;
}

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);
	QByteArray path = qgetenv("Path");
	qDebug().noquote() << "PATH = " << path;

    _Implicit_Linking();
    // _Explicit_Linking_Load();
    // _Explicit_Linking_Path();

    return application.exec();
}

//////////////////////////////////////////////////////////////////////////////////

