import QtQuick 2.12
import QtQuick.Window 2.12

Grid {
    visible: true
    width: 640
    height: 480
    columns: 2

    Rectangle {
        id: rectangle_topleft
        width: 50
        height: 50
        color: focus ? "red" : "lightgrey"

        Text {
            anchors.centerIn: parent
            text: rectangle_topleft.focus ? "focus" : "no focus"
        }

        KeyNavigation.right: rectangle_topright
        KeyNavigation.down: rectangle_bottomleft
    }

    Rectangle {
        id: rectangle_topright
        width: 50
        height: 50
        color: focus ? "red" : "lightgrey"

        Text {
            anchors.centerIn: parent
            text: rectangle_topright.focus ? "focus" : "no focus"
        }

        KeyNavigation.left: rectangle_topleft
        KeyNavigation.down: rectangle_bottomright
    }

    Rectangle {
        id: rectangle_bottomleft
        width: 50
        height: 50
        color: focus ? "red" : "lightgrey"
        focus: true

        Text {
            anchors.centerIn: parent
            text: rectangle_bottomleft.focus ? "focus" : "no focus"
        }

        KeyNavigation.up: rectangle_topleft
        KeyNavigation.right: rectangle_bottomright
    }

    Rectangle {
        id: rectangle_bottomright
        width: 50
        height: 50
        color: focus ? "red" : "lightgrey"

        Text {
            anchors.centerIn: parent
            text: rectangle_bottomright.focus ? "focus" : "no focus"
        }

        KeyNavigation.up: rectangle_topright
        KeyNavigation.left: rectangle_bottomleft
    }

    Keys.onPressed: (event) => {
        if(event.key === Qt.Key_Left) {
            console.debug('Qt.Key_Left')
            event.accepted = true;
        } else if(event.key === Qt.Key_A) {
            console.debug('Qt.Key_A')
        } else if(event.key === Qt.Key_B) {
            console.debug('Qt.Key_B')
        } else if(event.key === Qt.Key_C) {
            console.debug('Qt.Key_C')
        }
    }

    Keys.onReturnPressed: {
        console.debug('Keys.onReturnPressed')
    }
}
