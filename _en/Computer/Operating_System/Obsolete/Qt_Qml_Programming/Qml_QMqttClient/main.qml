import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QMqttClient 1.0


Window {
    property var stating: mqttClient._Stating()
    id: window
    visible: true
    width: 800
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        // console.debug(`window:onCompleted`)

        mqttClient.signal_stateChanged.connect(function (stating) {
            console.debug(`mqttClient.stateChanged.connect(function (stating) {`)
            window.stating = stating

            var timestampUTC   = mqttClient._TimeStamp()
            var logging        = `${timestampUTC}, state = ${window.stating}\n`
            textarea_logging.insert(0, logging)
        })

        mqttClient.signal_messageReceived.connect(function (topic, message) {
            console.debug(`mqttClient.messageReceived.connect(function (topic, message) {`)
            var timestampUTC   = mqttClient._TimeStamp()
            var logging        = `${timestampUTC}, ${topic}: ${message}\n`
            textarea_logging.insert(0, logging)
        })

        mqttClient.signal_echoInfo.connect(function (info) {
            console.debug(`mqttClient.echoInfo.connect(function (info) {`)
            textarea_logging.insert(0, `${info}\n`)
        })

        mqttClient.signal_subscriptionState.connect(function (topic, state) {
            console.debug(`mqttClient.signal_topic.connect(function (topic) {`)
            if(state === "Subscribed") {
                var hitted_i = false
                for(var i = 0; i < listmodel_topics.count; i += 1) {
                    if(listmodel_topics.get(i)["topic"] === topic) {
                        hitted_i = true
                        break
                    }
                }
                if(hitted_i === false) {
                    listmodel_topics.append({ "topic": topic })
                }
            } else if(state === "Unsubscribed") {
                var hitted_j = false
                for(var j = 0; j < listmodel_topics.count; j += 1) {
                    if(listmodel_topics.get(j)["topic"] === topic) {
                        hitted_j = true
                        break
                    }
                }
                if(hitted_j === true) {
                    listmodel_topics.remove(j)
                }
            }
        })

        mqttClient.signal_echoPing.connect(function () {
            console.debug(`mqttClient.signal_echoPing.connect(function () {`)
            var timestampUTC   = mqttClient._TimeStamp()
            var logging        = `${timestampUTC}, ping responsed.\n`
            textarea_logging.insert(0, logging)
        })
    }

    Label {
        id: label_address
        width: 80
        height: 32
        anchors.left: parent.left
        anchors.top: parent.top
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        text: "Address: "
    }

    TextField {
        id: textfield_address
        height: 32
        anchors.left: label_address.right
        anchors.right: label_connect.left
        anchors.rightMargin: 8
        anchors.top: label_address.top
        placeholderText: "test.mosquitto.org:1883"
        text: "test.mosquitto.org:1883"
        selectByMouse: true
    }

    Label {
        id: label_connect
        width: 80
        height: 32
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: textfield_address.top
        background: Rectangle {
            radius: 4
            color: "lightblue"
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: {
            // console.debug(`window.stating = ${window.stating}, QMqttClient.Disconnected = ${QMqttClient.Disconnected}, QMqttClient.Connecting = ${QMqttClient.Connecting}, QMqttClient.Connected = ${QMqttClient.Connected}`)
            return (window.stating === QMqttClient.Disconnected) ? "Connect" : "Disconnect"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label_connect:onClicked`)
                if(window.stating === QMqttClient.Disconnected) {
                    var index = textfield_address.text.indexOf(":")
                    var ip    = ""
                    var port  = 0
                    if(0 <= index) {
                        ip   = textfield_address.text.slice(0, index)
                        port = parseInt(textfield_address.text.slice(index + 1))
                    } else {
                        ip   = textfield_address.text
                    }
                    if((0 <= port && port < 65536) === false) {
                        port = 1883
                    }
                    console.debug(`index = ${index}, ip = ${ip}, port = ${port}`)
                    mqttClient._ConnectToHost(ip, port)
                } else {
                    mqttClient._DisConnectFromHost()
                }
            }
        }
    }

    Label {
        id: label_topic
        width: 80
        height: 32
        anchors.left: parent.left
        anchors.top: label_address.bottom
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        text: "Topic: "
    }

    TextField {
        id: textfield_topic
        height: 32
        anchors.left: label_topic.right
        anchors.right: label_subscribe.left
        anchors.rightMargin: 8
        anchors.top: label_topic.top
        placeholderText: "qtmqtt/topic"
        text: "qtmqtt/topic"
        selectByMouse: true
    }

    Label {
        id: label_subscribe
        width: 80
        height: 32
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: textfield_topic.top
        background: Rectangle {
            radius: 4
            color: "lightblue"
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Subscribe"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label_subscribe:onClicked`)
                mqttClient._Subscribe(textfield_topic.text)
            }
        }
    }

    Label {
        id: label_message
        width: 80
        height: 32
        anchors.left: parent.left
        anchors.top: label_topic.bottom
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        text: "Message: "
    }

    TextField {
        id: textfield_message
        height: 32
        anchors.left: label_message.right
        anchors.right: label_publish.left
        anchors.rightMargin: 8
        anchors.top: label_message.top
        placeholderText: "This is a test message."
        text: "This is a test message."
        selectByMouse: true
    }

    Label {
        id: label_publish
        width: 80
        height: 32
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: textfield_message.top
        background: Rectangle {
            radius: 4
            color: "lightblue"
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Publish"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label_publish:onClicked`)
                mqttClient._Publish(textfield_topic.text, textfield_message.text)
            }
        }
    }

    Label {
        id: label_topics
        width: 80
        height: 32
        anchors.left: parent.left
        anchors.top: label_message.bottom
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        text: "Topics: "
    }

    Rectangle {
        id: rectangle_topics
        height: column_topics.height < 32 ? 32 : column_topics.height
        anchors.left: column_topics.left
        anchors.top: column_topics.top
        anchors.right: column_topics.right
        border.width: 1
        border.color: "grey"
    }

    Column {
        id: column_topics
        anchors.left: label_topics.right
        anchors.right: label_ping.left
        anchors.rightMargin: 8
        anchors.top: label_topics.top

        Repeater {
            model: ListModel {
                id: listmodel_topics
            }

            Label {
                id: label_topics_item
                width: column_topics.width
                height: 32
                leftPadding: 8
                rightPadding: 8
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                text: model["topic"]
            }
        }
    }

    Label {
        id: label_unsubscribe
        width: 80
        height: 32
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: column_topics.top
        background: Rectangle {
            radius: 4
            color: "lightblue"
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Unsubscribe"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label_unsubscribe:onClicked`)
                mqttClient._Unsubscribe(textfield_topic.text)
            }
        }
    }

    Label {
        id: label_log
        width: 80
        height: 32
        anchors.left: parent.left
        anchors.top: rectangle_topics.bottom
        text: "Log: "
    }

    ScrollView {
        id: scrollview_logging
        anchors.left: label_log.right
        anchors.right: label_ping.left
        anchors.rightMargin: 8
        anchors.top: label_log.top
        anchors.bottom: parent.bottom
        background: Rectangle {
            border.width: 1
            border.color: "grey"
        }
        clip: true

        onContentHeightChanged: {
            // console.debug(`scrollview_logging:onContentHeightChanged, contentHeight = ${contentHeight}, ScrollBar.vertical.position = ${ScrollBar.vertical.position}`)
            ScrollBar.vertical.position = 0.0  // 若子组件非Textarea则此处设置position可能无效
        }

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy  : ScrollBar.AlwaysOn

        TextArea {
            id: textarea_logging
            width: scrollview_logging.width
            wrapMode: Text.WrapAnywhere
            text: ""
        }
    }

    Label {
        id: label_ping
        width: 80
        height: 32
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: label_log.top
        background: Rectangle {
            radius: 4
            color: "lightblue"
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Ping"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label_ping:onClicked`)
                mqttClient._RequestPing();
            }
        }
    }

    Label {
        id: label_clear
        width: 80
        height: 32
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.top: label_ping.bottom
        background: Rectangle {
            radius: 4
            color: "lightblue"
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Clear"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label_clear:onClicked`)
                textarea_logging.clear()
            }
        }
    }
}
