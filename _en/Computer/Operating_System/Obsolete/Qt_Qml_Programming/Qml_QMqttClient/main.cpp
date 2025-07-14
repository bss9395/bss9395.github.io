#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MqttClient.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    MqttClient mqttClient;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    qmlRegisterType<QMqttClient>("QMqttClient", 1, 0, "QMqttClient");
    engine.rootContext()->setContextProperty("mqttClient", &mqttClient);
    engine.load(url);


    return app.exec();
}
