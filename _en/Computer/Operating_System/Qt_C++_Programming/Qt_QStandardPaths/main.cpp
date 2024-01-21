#include <QDebug>
#include <QGuiApplication>
#include <QStandardPaths>

void _QStandardPaths() {
    qDebug().noquote() << __FUNCTION__;

    QString     filepath  = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    QStringList filepaths = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    qDebug().noquote() << "filepath  = " << filepath;
    qDebug().noquote() << "filepaths = " << filepaths;
}

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    _QStandardPaths();

    return app.exec();
}
