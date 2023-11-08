import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    id: rectangle_window
    width: 160
    height: 200
    color: "lightgrey"

    states: State {
        name: "reanchored"

        AnchorChanges {
            target: rectangle
            anchors.top: rectangle_window.top
            anchors.bottom: rectangle_window.bottom
        }

        PropertyChanges {
            target: rectangle
            anchors.topMargin: 10
            anchors.bottomMargin: 10
        }
    }

    transitions: Transition {
        AnchorAnimation {
            duration: 1000
        }
    }

    Rectangle {
        id: rectangle
        width: 100
        height: 100
        color: "grey"
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            rectangle_window.state = "reanchored"
        }
    }
}
