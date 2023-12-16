#include <QApplication>
#include <QDebug>
#include <QUuid>
#include <QDateTime>

Q_INVOKABLE QString generateUUID() {
    qDebug() << __FUNCTION__;

    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}

Q_INVOKABLE QString generateTimestampUTC() {
    qDebug() << __FUNCTION__;

    QDateTime datetimeUTC = QDateTime::currentDateTimeUtc();
    QString timestampUTC = datetimeUTC.toString("yyyy-MM-ddThh:mm:ss.zzzzzz");
    // qDebug() << "timestampUTC = " << timestampUTC;

    qint64 offsetUTC = datetimeUTC.offsetFromUtc();
    QString timezone = (0 <= offsetUTC)
            ?                          QString("+%1:%2").arg(offsetUTC / 3600, 2, 10, QChar('0')).arg(offsetUTC % 3600 / 60, 2, 10, QChar('0'))
            : (offsetUTC = -offsetUTC, QString("-%1:%2").arg(offsetUTC / 3600, 2, 10, QChar('0')).arg(offsetUTC % 3600 / 60, 2, 10, QChar('0')));
    // qDebug() << "timezone = " << timezone;

    timestampUTC += timezone;
    // qDebug() << "timestampUTC = " << timestampUTC;
    return timestampUTC;
}

Q_INVOKABLE QString generateTimestamp() {
    qDebug() << __FUNCTION__;

    QDateTime datetime = QDateTime::currentDateTime();
    QString timestamp = datetime.toString("yyyy-MM-ddThh:mm:ss.zzzzzz");
    // qDebug() << "timestamp = " << timestamp;

    qint64 offsetUTC = datetime.offsetFromUtc();
    QString timezone = (0 <= offsetUTC)
            ?                          QString("+%1:%2").arg(offsetUTC / 3600, 2, 10, QChar('0')).arg(offsetUTC % 3600 / 60, 2, 10, QChar('0'))
            : (offsetUTC = -offsetUTC, QString("-%1:%2").arg(offsetUTC / 3600, 2, 10, QChar('0')).arg(offsetUTC % 3600 / 60, 2, 10, QChar('0')));
    // qDebug() << "timezone = " << timezone;

    timestamp += timezone;
    // qDebug() << "timestamp = " << timestamp;
    return timestamp;
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    for(int i = 0; i < 20; i += 1) {
        QString uuid = generateUUID();
        qDebug() << "uuid = " << uuid;
    }

    for(int i = 0; i < 20; i += 1) {
        QString timestampUTC = generateTimestampUTC();
        qDebug() << "timestampUTC = " << timestampUTC;
    }

    for(int i = 0; i < 20; i += 1) {
        QString timestamp = generateTimestamp();
        qDebug() << "timestamp = " << timestamp;
    }

    return a.exec();
}
