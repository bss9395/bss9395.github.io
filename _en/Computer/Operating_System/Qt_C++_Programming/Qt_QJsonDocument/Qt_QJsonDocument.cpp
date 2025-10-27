/* Qt_QJsonDocument.cpp
Author: bss9395
Update: 2025/10/28T00:24:00+08@China-BeiJing+08
Keepin: bss9395@yeah.net
*/

#include <QDebug>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

void _Test_FromJson() {
    QString json = R"!(
{
    "code": 200,
    "hint": "操作成功",
    "info": {
        "nickname": "璀璨星辰",
        "birthday": "1993/09/05"
    },
    "list": [
        null, true, 1, 2.3, "hello"
    ]
}
    )!";

    QJsonObject object = QJsonDocument::fromJson(json.toUtf8()).object();
    if(object.contains("info") == true) {
        QJsonObject info = object["info"].toObject();
        qDebug().nospace() << "isEmpty     = " << info.isEmpty();
        qDebug().nospace() << "isUndefined = " << info["nickname"].isUndefined();
        qDebug().nospace() << "isNull      = " << info["nickname"].isNull();
        if(info.contains("nickname") == true) {
            qDebug() << info["nickname"].toString("");
        }
    }
    if(object.contains("list") == true) {
        QJsonArray list = object["list"].toArray();
        for(long idx = 0; idx < list.size(); idx += 1) {
            if(list[idx].isUndefined() == true) {
                qDebug().nospace() << list[idx];
            } else if(list[idx].isNull() == true) {
                qDebug().nospace() << list[idx];
            } else if(list[idx].isBool() == true) {
                qDebug().nospace() << list[idx].toBool(false);
            } else if(list[idx].isDouble() == true) {
                qDebug().nospace() << list[idx].toInteger(0) << ", " << list[idx].toDouble(0.0);
            } else if(list[idx].isString() == true) {
                qDebug().nospace() << list[idx].toString("");
            } else if(list[idx].isObject() == true) {
                qDebug().nospace() << list[idx].toObject();
            } else if(list[idx].isArray() == true) {
                qDebug().nospace() << list[idx].toArray();
            }
        }
    }
}

void _Test_ToJson() {
    QJsonObject object = QJsonObject();
    object["code"] = 200;
    object["hint"] = "操作成功";
    QJsonObject info = QJsonObject();
    info["nickname"] = "璀璨星辰";
    info["birthday"] = "1993/09/05";
    object["info"] = info;
    QJsonArray list = QJsonArray();
    list.insert(0, QJsonValue());
    list.insert(1, true);
    list.insert(2, 1);
    list.insert(3, 2.3);
    list.insert(4, "hello");
    object["list"] = list;

    QByteArray json = QJsonDocument(object).toJson(QJsonDocument::Indented);
    qDebug().nospace().noquote() << json;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // _Test_FromJson();
    _Test_ToJson();

    return a.exec();
}
