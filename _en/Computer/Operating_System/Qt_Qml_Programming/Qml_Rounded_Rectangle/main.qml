import QtQuick 2.14
import QtQuick.Window 2.14

Rectangle {
    visible: true
    width: 800
    height: 480
    // color: "blue"

    Row {
        spacing: 20
        anchors.centerIn: parent

        Rounded_Rectangle {
            width: 160
            height: 160
            radius: [20, 0, 20, 0]
            color: "cyan"
            borderColor: "grey"
            borderWidth: 1
        }

        Rounded_Rectangle {
            width: 160
            height: 160
            color: "green"
            radius: [30, 50, 40, 0]
        }

        Rounded_Rectangle {
            width: 160
            height: 160
            color: "blue"
            radius: [30, 0, 0, 30]
        }

        Rounded_Rectangle {
            width: 160
            height: 160
            color: "red"
            radius: [0, 20, 20, 0]
        }
    }
}
