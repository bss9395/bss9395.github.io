import QtQuick 2.14
import QtQuick.Window 2.14

Item {
    visible: true
    width: 640
    height: 480


    Rectangle {
        id: rect
        width: 100
        height: 100
        color: "red"

        PropertyAnimation on x {
            to: 100
        }

        PropertyAnimation on y {
            to: 100
        }

        SequentialAnimation on color {
            ColorAnimation {
                to: "yellow"
                duration: 1000
            }

            ColorAnimation {
                to: "blue"
                duration: 1000
            }
        }
    }
}
