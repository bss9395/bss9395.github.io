import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    width: 600
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 200
        height: 40
        radius: height / 2
        border.color: "blue"
        border.width: 2

        TextField {
            id: textfield
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: parent.height / 3
            anchors.right: image.left
            anchors.verticalCenter: parent.verticalCenter
            placeholderText: "Type here"

            padding: 0
            background: Rectangle {
                color: "#00FFFFFF"
            }

            Keys.onReturnPressed: {
                console.log("Enter key pressed")
                // 在这里处理按下 Enter 键的逻辑
            }
        }

        Image {
            id: image
            width: parent.height * 2 / 3
            height: parent.height * 2 / 3
            anchors.right: parent.right
            anchors.rightMargin: parent.height / 3
            anchors.verticalCenter: parent.verticalCenter
            source: "images/zoom_in.png"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    console.debug('onClicked')
                }
            }
        }
    }
}
