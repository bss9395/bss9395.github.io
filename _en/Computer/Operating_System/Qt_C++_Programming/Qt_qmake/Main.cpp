#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);

#define _str "1.2.3"
    qDebug().nospace().noquote() << _str;

#ifdef VERSION
    qDebug().nospace().noquote() << VERSION;
    QCoreApplication::setApplicationVersion(VERSION);
    qDebug().nospace().noquote() << QCoreApplication::applicationVersion();
#endif

#if defined(_version_major) && defined(_version_minor) && defined(_version_patch)
    int version_major = _version_major;
    int version_minor = _version_minor;
    int version_patch = _version_patch;
    QString version = QString("%1.%2.%3").arg(version_major).arg(version_minor).arg(version_patch);
    qDebug().nospace().noquote() << version;
#endif

#ifdef _feature_x
    qDebug().nospace().noquote() << "_feature_x";
#endif

    return application.exec();
}
