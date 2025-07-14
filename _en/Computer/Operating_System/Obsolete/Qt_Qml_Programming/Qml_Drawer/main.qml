import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    header: ToolBar {
        ToolButton {
            text: "⋮"

            onClicked: {
                console.debug(drawer.opened)  // note: bug on Qt5
                if(drawer.position == 1.0) {
                    drawer.close()
                } else {
                    drawer.open()
                }
            }
        }
    }

    Drawer {
        id: drawer
        y: header.height
        width: parent.width * 0.6
        height: parent.height - header.height
        modal: true
        dim: true
        // closePolicy: Popup.CloseOnPressOutside
        closePolicy: Popup.NoAutoClose
        leftPadding: 10

        Text {
            anchors.centerIn: parent
            text: "Content goes here!"
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "red"
//        transform: Translate {
//            x: drawer.position * label.width * 0.33
//        }

        Text {
            id: label
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 60
            text: "Content"
        }
    }
}
