import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: 50
        height: 50
        color: "lightsteelblue"

        Behavior on color {
            animation: PropertyAnimation {
                duration: 800
            }
        }

        Behavior on x {
            animation: PropertyAnimation {
                easing.type: Easing.OutElastic
                easing.amplitude: 1.0
                easing.period: 0.5
                duration: 800
            }
        }

        Behavior on y {
            animation: PropertyAnimation {
                easing.type: Easing.OutElastic
                easing.amplitude: 1.0
                easing.period: 0.5
                duration: 800
            }
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                rectangle.color = Qt.rgba(Math.random(256), Math.random(256), Math.random(256), 1)
                rectangle.x += 50
                rectangle.y += 50
            }
        }
    }
}
