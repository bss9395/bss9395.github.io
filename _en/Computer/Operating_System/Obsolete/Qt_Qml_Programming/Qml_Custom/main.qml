import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Controls.Universal 2.12 as Material

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        SpinBox {
            background: Rectangle {
                color: "lightblue"
            }
        }

        Button {
            id: button
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 80
                border.color: button.down ? "#17a81a" : "#21be2b"
                border.width: 1
                radius: 2
            }
            contentItem: Text {
                // anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: button.down ? "#17a81a" : "#21be2b"
                text: "Button"
                elide: Text.ElideRight
            }
        }
    }
}
