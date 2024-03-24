#ifndef CONFIG_H
#define CONFIG_H

#include <QDebug>
#include <QObject>
#include <QDateTime>
#include <QMqttSubscription>
#include <QMqttClient>


class MqttClient: public QObject
{
    Q_OBJECT

public:
    QMqttClient *_mqttClient = new QMqttClient(this);

public:
    explicit MqttClient(QObject *parent = nullptr)
        : QObject(parent) {
        // qDebug().noquote() << __FUNCTION__;

        connect(_mqttClient, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState state) -> void {
            qDebug().noquote() << "connect(_mqttClient, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState state) -> void {";

            if(state == QMqttClient::Connected) {
                qDebug().noquote() << "================================================================================";
                qDebug().noquote() << "_mqttClient->cleanSession()                                          = " << _mqttClient->cleanSession();
                qDebug().noquote() << "_mqttClient->clientId()                                              = " << _mqttClient->clientId();
                qDebug().noquote() << "_mqttClient->error()                                                 = " << _mqttClient->error();
                qDebug().noquote() << "_mqttClient->hostname()                                              = " << _mqttClient->hostname();
                qDebug().noquote() << "_mqttClient->keepAlive()                                             = " << _mqttClient->keepAlive();
                qDebug().noquote() << "_mqttClient->password()                                              = " << _mqttClient->password();
                qDebug().noquote() << "_mqttClient->port()                                                  = " << _mqttClient->port();
                qDebug().noquote() << "_mqttClient->protocolVersion()[MQTT_3_1=3, MQTT_3_1_1=4, MQTT_5_0=5] = " << _mqttClient->protocolVersion();
                qDebug().noquote() << "_mqttClient->username()                                              = " << _mqttClient->username();
                qDebug().noquote() << "_mqttClient->willMessage()                                           = " << _mqttClient->willMessage();
                qDebug().noquote() << "_mqttClient->willQoS()                                               = " << _mqttClient->willQoS();
                qDebug().noquote() << "_mqttClient->willRetain()                                            = " << _mqttClient->willRetain();
                qDebug().noquote() << "_mqttClient->willTopic()                                             = " << _mqttClient->willTopic();

                qDebug().noquote() << "================================================================================";
                QMqttConnectionProperties connectionProperties = _mqttClient->connectionProperties();
                qDebug().noquote() << "[QMqttConnectionProperties]";
                qDebug().noquote() << "connectionProperties.authenticationData()   = " << connectionProperties.authenticationData();
                qDebug().noquote() << "connectionProperties.authenticationMethod() = " << connectionProperties.authenticationMethod();
                qDebug().noquote() << "connectionProperties.maximumPacketSize()    = " << connectionProperties.maximumPacketSize();
                qDebug().noquote() << "connectionProperties.maximumReceive()       = " << connectionProperties.maximumReceive();
                qDebug().noquote() << "connectionProperties.maximumTopicAlias()    = " << connectionProperties.maximumTopicAlias();
                qDebug().noquote() << "connectionProperties.requestProblemInformation()       = " << connectionProperties.requestProblemInformation();
                qDebug().noquote() << "connectionProperties.requestResponseInformation()      = " << connectionProperties.requestResponseInformation();
                qDebug().noquote() << "connectionProperties.sessionExpiryInterval()           = " << connectionProperties.sessionExpiryInterval();

                qDebug().noquote() << "================================================================================";
                QMqttLastWillProperties lastWillProperties = _mqttClient->lastWillProperties();
                qDebug().noquote() << "[QMqttLastWillProperties]";
                qDebug().noquote() << "lastWillProperties.contentType()                                      = " << lastWillProperties.contentType();
                qDebug().noquote() << "lastWillProperties.correlationData()                                  = " << lastWillProperties.correlationData();
                qDebug().noquote() << "lastWillProperties.messageExpiryInterval()                            = " << lastWillProperties.messageExpiryInterval();
                qDebug().noquote() << "lastWillProperties.payloadFormatIndicator()[Unspecified, UTF8Encoded] = " << (int)lastWillProperties.payloadFormatIndicator();
                qDebug().noquote() << "lastWillProperties.responseTopic()                                    = " << lastWillProperties.responseTopic();
                qDebug().noquote() << "lastWillProperties.willDelayInterval()                                = " << lastWillProperties.willDelayInterval();

                qDebug().noquote() << "================================================================================";
                QMqttServerConnectionProperties serverConnectionProperties = _mqttClient->serverConnectionProperties();
                qDebug().noquote() << "serverConnectionProperties.availableProperties()             = " << (int)serverConnectionProperties.availableProperties();
                qDebug().noquote() << "serverConnectionProperties.clientIdAssigned()                = " << serverConnectionProperties.clientIdAssigned();
                qDebug().noquote() << "serverConnectionProperties.isValid()                         = " << serverConnectionProperties.isValid();
                qDebug().noquote() << "serverConnectionProperties.maximumQoS()                      = " << serverConnectionProperties.maximumQoS();
                qDebug().noquote() << "serverConnectionProperties.reason()                          = " << serverConnectionProperties.reason();
                qDebug().noquote() << "serverConnectionProperties.reasonCode()                      = " << (int)serverConnectionProperties.reasonCode();
                qDebug().noquote() << "serverConnectionProperties.responseInformation()             = " << serverConnectionProperties.responseInformation();
                qDebug().noquote() << "serverConnectionProperties.retainAvailable()                 = " << serverConnectionProperties.retainAvailable();
                qDebug().noquote() << "serverConnectionProperties.serverKeepAlive()                 = " << serverConnectionProperties.serverKeepAlive();
                qDebug().noquote() << "serverConnectionProperties.serverReference()                 = " << serverConnectionProperties.serverReference();
                qDebug().noquote() << "serverConnectionProperties.sharedSubscriptionSupported()     = " << serverConnectionProperties.sharedSubscriptionSupported();
                qDebug().noquote() << "serverConnectionProperties.subscriptionIdentifierSupported() = " << serverConnectionProperties.subscriptionIdentifierSupported();
                qDebug().noquote() << "serverConnectionProperties.wildcardSupported()               = " << serverConnectionProperties.wildcardSupported();
                qDebug().noquote() << "================================================================================";
            }
        });

        connect(_mqttClient, &QMqttClient::stateChanged, this, &MqttClient::signal_stateChanged);

        connect(_mqttClient, &QMqttClient::messageReceived, this, [this](const QByteArray &byteArray, const QMqttTopicName &topic) -> void {
            qDebug().noquote() << "connect(_mqttClient, &QMqttClient::messageReceived, this, [this](const QByteArray &byteArray, const QMqttTopicName &topic) -> void {";
            emit signal_messageReceived(topic.name(), QString::fromUtf8(byteArray));
        });

        connect(_mqttClient, &QMqttClient::pingResponseReceived, this, &MqttClient::signal_echoPing);
    }

public:
    Q_INVOKABLE QString _TimeStamp() {
        // qDebug().noquote() << __FUNCTION__;
        QDateTime datetimeUTC  = QDateTime::currentDateTimeUtc();
        QString   timestampUTC = datetimeUTC.toString("yyyy-MM-ddThh:mm:ss.zzzzzz");
        qint64    offsetUTC    = QDateTime::currentDateTime().offsetFromUtc();
        QString   timezone     = (0 <= offsetUTC)
            ?                          QString("+%1:%2").arg(offsetUTC / 3600, 2, 10, QChar('0')).arg(offsetUTC % 3600 / 60, 2, 10, QChar('0'))
            : (offsetUTC = -offsetUTC, QString("-%1:%2").arg(offsetUTC / 3600, 2, 10, QChar('0')).arg(offsetUTC % 3600 / 60, 2, 10, QChar('0')));
        timestampUTC += timezone;
        return timestampUTC;
    }

    // 注意此处qml不能正确处理返回函数类型。
    Q_INVOKABLE int _Stating() {
        qDebug().noquote() << __FUNCTION__;
        return _mqttClient->state();
    }

    Q_INVOKABLE void _ConnectToHost(const QString &ip, const int &port) {
        qDebug().noquote() << __FUNCTION__;
        _mqttClient->setProtocolVersion(QMqttClient::ProtocolVersion::MQTT_5_0);
        _mqttClient->setHostname(ip);
        _mqttClient->setPort(port);
        _mqttClient->connectToHost();
    }

    Q_INVOKABLE void _DisConnectFromHost() {
        qDebug().noquote() << __FUNCTION__;
        _mqttClient->disconnectFromHost();
    }

    Q_INVOKABLE void _Subscribe(const QString &topic) {
        qDebug().noquote() << __FUNCTION__ << ", topic = " << topic;
        QMqttSubscription *subscription = _mqttClient->subscribe(topic);
        if(!subscription) {
            emit signal_echoInfo("subscribe failed");
        } else {
            connect(subscription, &QMqttSubscription::stateChanged, this, [this, subscription](QMqttSubscription::SubscriptionState state) -> void {
                if(state == QMqttSubscription::Subscribed) {
                    emit signal_echoInfo("subscribe success");
                    emit signal_subscriptionState(subscription->topic().filter(), "Subscribed");
                } else if(state == QMqttSubscription::Unsubscribed) {
                    emit signal_subscriptionState(subscription->topic().filter(), "Unsubscribed");
                }
            });
        }
    }

    Q_INVOKABLE void _Publish(const QString &topic, const QString &message) {
        qDebug().noquote() << __FUNCTION__;

        qint32 len = _mqttClient->publish(topic, message.toUtf8());
        if(len < 0) {
            emit signal_echoInfo("publish failed");
        } else {
            emit signal_echoInfo("publish success");
        }
    }

    Q_INVOKABLE void _Unsubscribe(const QString &topic) {
        qDebug().noquote() << __FUNCTION__ << ", topic = " << topic;
        _mqttClient->unsubscribe(topic);
    }

    Q_INVOKABLE void _RequestPing() {
        qDebug().noquote() << __FUNCTION__;
        _mqttClient->requestPing();
    }

signals:
    void signal_stateChanged(const QMqttClient::ClientState &state);
    void signal_messageReceived(const QString &topic, const QString &message);
    void signal_echoInfo(const QString &info);
    void signal_subscriptionState(const QString &topic, const QString &state);
    void signal_echoPing();
};

#endif // CONFIG_H
