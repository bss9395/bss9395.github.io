import QtQuick 2.14
import QtQuick.Window 2.14

Rectangle {
    visible: true
    width: 640
    height: 480
    color: "lightgrey"

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
        color: "yellow"
        transformOrigin: "TopLeft"
        scale: 2.0
    }

    Rectangle {
        width: 25
        height: 25
        x: 100
        y: 100
        color: "yellow"
        rotation: 30
    }
}
