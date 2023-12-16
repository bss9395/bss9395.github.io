import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle_childrenRect
        width: childrenRect.x + childrenRect.width
        height: childrenRect.y + childrenRect.height
        color: "lightblue"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug('childrenRect:onClicked')
            }
        }

        Label {
            id: label_close
            width: 16
            height: 16
            anchors.right: parent.right
            anchors.rightMargin: 10
            text: "×"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('label_close:onClicked')
                }
            }
        }

        Rectangle {
            width: 24
            height: 24
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
            color: "red"
        }

        Rectangle {
            width: 48
            height: 48
            x: 100
            y: 100
            color: "green"
            transform: [
                Rotation {
                    angle: 30
                }
            ]
        }

        Rectangle {
            width: 36
            height: 36
            anchors.horizontalCenter: parent.horizontalCenter
            color: "blue"
        }

        Text {
            id: text_vary
            anchors.verticalCenter: parent.verticalCenter
            text: "abcd"

            Timer {
                id: timer_vary
                running: true
                repeat: false
                interval: 3000

                onTriggered: {
                    text_vary.text = "abcdefghijklmnopqrstuvwxyz"
                }
            }
        }

        onChildrenRectChanged: {
            console.debug('onChildrenRectChanged')
            width = childrenRect.x + childrenRect.width
            height = childrenRect.y + childrenRect.height
        }
    }
}
