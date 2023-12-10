#ifndef SOFTWARECENTER_H
#define SOFTWARECENTER_H

#include <QDebug>
#include <QObject>
#include <QProcess>
#include <QFile>

class SoftwareCenter: public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE void launchSoftware(const QString &uuid, const QString &debpath, const QString &debname_alternative) {
        qDebug() << __FUNCTION__;

        QProcess process;
        QString  debname = QString();
        if(QFile::exists(debpath) == true) {
            QString command_debname = QString(R"!(dpkg -I '%1' | awk '{if($1=="Package:") {print $2}}')!").arg(debpath);
            qDebug().noquote() << "command_debname = " << command_debname;
            process.start("bash", QStringList() << "-c" << command_debname);
            int ret_debname = process.waitForFinished();
            debname = (ret_debname == true && process.exitCode() == 0) ? QString::fromUtf8(process.readAllStandardOutput()).split("\n")[0] : QString();
            qDebug() << "debname = " << debname;
        } else {
            debname = debname_alternative;
        }

        //通过dpkg获取软件启动路径
        QString command_launchpath = QString("which '%1'").arg(debname);
        qDebug() << "command_launchpath = " << command_launchpath;
        process.start("bash", QStringList() << "-c" << command_launchpath);
        int ret_launchpath = process.waitForFinished();
        QString launch = (ret_launchpath == true && process.exitCode() == 0) ? QString::fromUtf8(process.readAllStandardOutput()).split("\n")[0] : QString();
        qDebug() << "launch = " << launch;

        // 通过桌面启动栏获取软件启动路径
        if(launch.isEmpty() == true) {
            QString command_desktop = QString(R"!(dpkg -L '%1' | awk '{if($0~/^\/usr\/share\/applications\/.*desktop$/) {print $0}}')!").arg(debname);
            qDebug() << "command_desktop = " << command_desktop;
            process.start("bash", QStringList() << "-c" << command_desktop);
            int ret_desktop = process.waitForFinished();
            QStringList desktopList = (ret_desktop == true && process.exitCode() == 0) ? QString::fromUtf8(process.readAllStandardOutput()).split("\n") : QStringList();
            qDebug() << "desktopList = " << desktopList;

            if(desktopList.isEmpty() == false) {
                QString command_launch = QString(R"!(cat '%1' | awk '{if($0~/^Exec=/) print $0}')!").arg(desktopList[0]);
                qDebug().noquote() << "command_launch = " << command_launch;
                process.start("bash", QStringList() << "-c" << command_launch);
                int ret_launch = process.waitForFinished();
                launch = (ret_launch == true && process.exitCode() == 0) ? QString::fromUtf8(process.readAllStandardOutput()).split("\n")[0] : QString();

                launch = launch.mid(QString("Exec=").length());   // 注意mid()函数的参数
                launch = launch.mid(0, launch.lastIndexOf("%"));  // 注意执行路径中可能使用url，并且包含=与%
                qDebug() << "launch = " << launch;
            }
        }

        // 通过启动路径启动软件
        if(launch.isEmpty() == true) {
            emit signal_launchSoftwareFailed(uuid, "此软件未安装！");
        } else {
            bool ret = process.startDetached(launch);
            if(ret == false) {
                emit signal_launchSoftwareFailed(uuid, "此软件启动失败！");
            }
        }
    }

signals:
    void signal_launchSoftwareFailed(const QString &uuid, const QString &information);
};

#endif // SOFTWARECENTER_H
