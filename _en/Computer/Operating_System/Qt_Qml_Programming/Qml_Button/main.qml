import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        anchors.centerIn: parent
        spacing: 10

        Button {
            text: "普通按钮"
        }

        Button {
            text: "flat按钮"
            flat: true
        }

        Button {
            text: "高亮按钮"
            highlighted: true
        }

        RoundButton {
            text: "圆角按钮"
            radius: 5
        }

        RoundButton {
            text: "圆形按钮"
            implicitWidth: 60
            implicitHeight: 60
            radius: width / 2
        }

        Button {
            id: button2
            width: 80
            height: 32
            background: Rectangle {
                radius: 8
                border.color: "#FF4399F3"
                border.width: 1
                color: "#FFFFFFFF"
            }
            contentItem: Text {
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 12
                color: "#FF4399F3"
                text: "Button"
            }

            onClicked: {
                console.debug(`button2:onClicked`)
            }
        }
    }
}
