import QtQuick 2.14
import QtQuick.Window 2.14

Rectangle {
    visible: true
    width: 640
    height: 480


    Rectangle {
        width: 25
        height: 25
        color: "blue"
    }

    Rectangle {
        width: 25
        height: 25
        x: 25
        y: 25
        color: "red"
        scale: 1.6
        // transformOrigin: "Center"
    }

    Rectangle {
        width: 25
        height: 25
        x: 25
        y: 0
        color: "yellow"
        transformOrigin: "TopLeft"
        scale: 1.6
    }
}
