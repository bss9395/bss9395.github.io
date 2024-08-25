#include <QCoreApplication>
#include <QDebug>

void _qputenv() {
    QString path = QString::fromLocal8Bit(qgetenv("PATH"));
    qDebug().noquote() << QString("PATH = %1").arg(path);

    QString workpath = QCoreApplication::applicationDirPath();
    path = workpath + ";" + path;

    qputenv("PATH", path.toLocal8Bit());
    qDebug().noquote() << QString("PATH = %1").arg(QString::fromLocal8Bit(qgetenv("PATH")));
}

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);

    _qputenv();

    return application.exec();
}
