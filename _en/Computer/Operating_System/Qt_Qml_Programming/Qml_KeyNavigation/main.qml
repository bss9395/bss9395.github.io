import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid {
        width: 100
        height: 100
        columns: 2

        Rectangle {
            id: topLeft
            width: 50
            height: 50
            color: activeFocus ? "red" : "lightgrey"
            focus: true

            KeyNavigation.right: topRight
            KeyNavigation.down: bottomLeft
        }

        Rectangle {
            id: topRight
            width: 50
            height: 50
            color: activeFocus ? "red" : "lightgrey"

            KeyNavigation.left: topLeft
            KeyNavigation.down: bottomRight
        }

        Rectangle {
            id: bottomLeft
            width: 50
            height: 50
            color: activeFocus ? "red" : "lightgrey"

            KeyNavigation.right: bottomRight
            KeyNavigation.up: topLeft
        }

        Rectangle {
            id: bottomRight
            width: 50
            height: 50
            color: activeFocus ?"red":"lightgrey"
            KeyNavigation.left: bottomLeft
            KeyNavigation.up: topRight
        }
    }
}
