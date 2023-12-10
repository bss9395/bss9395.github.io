#include <QDebug>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString jsonString = R"!(
{
    "msg": "操作成功",
    "code": 200,
    "data": {
        "softwareName": "name",
        "softwareVersion": "version"
    }
}
    )!";

    QJsonObject jsonObject = QJsonDocument::fromJson(jsonString.toUtf8()).object();
    qDebug() << jsonObject.contains("data");
    QJsonObject data = jsonObject["data"].toObject();
    qDebug() << data.isEmpty();
    QString link = data["link"].toString();
    qDebug() << link;

    return a.exec();
}
