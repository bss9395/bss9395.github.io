#include <QApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void _Parse_Stream() {
    qDebug() << __FUNCTION__;

    static QString response = R"!(
{"requestType": 1, "defaultParameter": "", "responseText": "我", "scene": "other", "urlList": []}
{"requestType": 1, "defaultParameter": "", "responseText": "我是一个名为", "scene": "other", "urlList": []}
{"requestType": 1, "defaultParameter": "", "responseText": "我是一个名为开天智能助手", "scene": "other", "urlList": []}
{"requestType": 1, "defaultParameter": "", "responseText": "我是一个名为开天智能助手的人工智能程序。", "scene": "other", "urlList": []}
)!";


    QString       *streamResponse = new QString(response);
    qint64        *lastPos        = new qint64(0);

    QJsonDocument jsonDocument = QJsonDocument();
    qint64 miniLen = 0;
    QRegularExpression expression = QRegularExpression();   // 注意换行匹配模式只匹配\n不匹配\r\n，注意使用懒惰匹配模式，注意开启.匹配换行符
    QRegularExpressionMatch match = QRegularExpressionMatch();
    while(expression = QRegularExpression(QString(R"!((\{.{%1,}?\})\n)!").arg(miniLen), QRegularExpression::DotMatchesEverythingOption), match = expression.match(*streamResponse, *lastPos), match.hasMatch() == true) {
        QString jsonString = match.captured(1);
        // qDebug().noquote() << "jsonString = " << jsonString;

        jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8());
        if(jsonDocument.isObject() == true) {               // 解析成功
            *lastPos = match.capturedEnd(0);
            miniLen = 0;
            // processCopilot(uid, jsonDocument.object());  // 每个数据包只处理最后一个匹配的项
        } else {                                            // 解析失败
            miniLen = jsonString.length() - 2 + 1;          // 去掉左右圆括号长度增加1
        }
    }
    if(jsonDocument.isObject() == true) {                   // 每个数据包只处理最后一个匹配的项
        qDebug().noquote() << "jsonDocument.object() = " << jsonDocument.object();
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    _Parse_Stream();

    return a.exec();
}
