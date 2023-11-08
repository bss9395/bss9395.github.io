import QtQuick 2.12
import QtQuick.Window 2.12

Column {
    visible: true
    width: 640
    height: 480
    spacing: 2
    focus: true
    move: Transition {
        NumberAnimation {
            properties: "x, y"
            duration: 1000
        }
    }

    Rectangle {
        color: "red"
        width: 50
        height: 50
    }

    Rectangle {
        id: rectangle_green
        color: "green"
        width: 20
        height: 50
    }

    Rectangle {
        color: "blue"
        width: 50
        height: 20
    }

    Keys.onSpacePressed: {
        rectangle_green.visible = !rectangle_green.visible
    }
}
