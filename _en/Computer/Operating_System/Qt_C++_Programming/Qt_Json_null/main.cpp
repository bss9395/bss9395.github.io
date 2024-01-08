
#include <QApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

void Json_long() {
    qDebug().noquote() << __FUNCTION__;

    qint64 abc = 123456789012;
    qDebug().noquote() << "abc = " << (qint32)abc;  // abc = -1097262572

    QJsonObject jsonObject = QJsonObject();
    jsonObject["abc"] = abc;
    qDebug().noquote() << "jsonObject = " << jsonObject;

    QJsonObject json = QJsonObject();
    json["def1"] = jsonObject["abc"].toInt();     // json = QJsonObject({"def1":0})
    json["def2"] = jsonObject["abc"].toString();  // json = QJsonObject({"def2":""})
    json["def3"] = jsonObject["abc"].toDouble();  // json = QJsonObject({"def3":123456789012})
    qDebug().noquote() << "json = " << json;
}

void Json_null() {
    qDebug().noquote() << __FUNCTION__;

    QJsonObject json = QJsonObject();
    json["abc"] = QJsonValue::Null;  // null值
    json["def"] = QJsonValue();      // null值
    qDebug().noquote() << "json = " << json;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Json_long();
//    json_null();

    return a.exec();
}
