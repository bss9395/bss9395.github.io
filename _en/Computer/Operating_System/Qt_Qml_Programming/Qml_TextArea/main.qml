import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    ScrollView {
        width: parent.width
        height: parent.height

        TextArea {
            width: parent.width
            height: parent.height
            wrapMode: Text.WrapAnywhere
            placeholderText: "可以在这里输入内容"
            background: Rectangle {
                color: "lightgrey"
            }
        }

        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        ScrollBar.horizontal.policy: ScrollBar.AsNeeded
    }

    footer: RowLayout {
        Label {
            font.pointSize: 7
            text: "姓名："
            background: Rectangle {
                color: "lightgrey"
            }

            Component.onCompleted: {
                console.debug(width)
            }
        }

        TextField {
            id: textfield
            placeholderText: "Enter name"
            Layout.fillWidth: true

            onAccepted: {
                console.debug(textfield.text)
                textfield.clear()
            }
        }
    }
}
