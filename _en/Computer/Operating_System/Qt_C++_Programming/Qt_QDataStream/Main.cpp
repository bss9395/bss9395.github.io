/* Qt_QDataStream
Author: bss9395
Update: 2024-08-19T11:06:42+08@China-Beijing+08
*/

#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

struct Data {
    QString _name;
    int _id;
    double _value;

    friend QDataStream& operator<<(QDataStream& os, const Data &data) {
        os << data._name;
        os << data._id;
        os << data._value;
        return os;
    }

    friend QDataStream& operator>>(QDataStream& is, Data &data) {
        is >> data._name;
        is >> data._id;
        is >> data._value;
        return is;
    }

    friend QDebug& operator<<(QDebug& debug, const Data& data) {
        debug << QString("[%1, %2, %3]").arg(data._name).arg(data._id).arg(data._value);
        return debug;
    }
};

void _Dump_Data_File() {
    Data data;
    data._name = "bss9395";
    data._id = 9395;
    data._value = 3.1415;

    QFile file("data.dat");
    file.open(QFile::WriteOnly | QFile::Truncate);
    QDataStream os(&file);
    os.setByteOrder(QDataStream::LittleEndian);
    os.setVersion(QDataStream::Qt_5_12);
    os << data;
    file.close();
}

void _Load_Data_File() {
    Data data;
    QFile file("data.dat");
    file.open(QFile::ReadOnly);
    QDataStream os(&file);
    os.setByteOrder(QDataStream::LittleEndian);
    os.setVersion(QDataStream::Qt_5_12);
    os >> data;

    qDebug().noquote() << data;
}

QByteArray _Dump_Data_QByteArray() {
    Data data;
    data._name = "bss9395";
    data._id = 9395;
    data._value = 3.1415;

    QByteArray buffer = "";
    QDataStream os(&buffer, QIODevice::ReadWrite);
    os.setByteOrder(QDataStream::LittleEndian);
    os.setVersion(QDataStream::Qt_5_12);
    os << data;
    return buffer;
}

void _Load_Data_QByteArray(QByteArray& buffer) {
    Data data;
    QDataStream is(&buffer, QIODevice::ReadWrite);
    is.setByteOrder(QDataStream::LittleEndian);
    is.setVersion(QDataStream::Qt_5_12);
    is >> data;

    qDebug().noquote() << data;
}

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);

    _Dump_Data_File();
    _Load_Data_File();

    QByteArray buffer = _Dump_Data_QByteArray();
    _Load_Data_QByteArray(buffer);

    return application.exec();
}
