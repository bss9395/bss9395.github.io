import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle_window
        width: 640
        height: 480
        color: "white"

        RectangleDrawer {
            id: rectangledrawer
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 20
            dock: enum_right

            Rectangle {
                id: rectangle
                width: parent.width
                height: parent.height
                color: "blue"
            }

            Component.onCompleted: {
//                rectangledrawer.open()
            }
        }
    }
}
