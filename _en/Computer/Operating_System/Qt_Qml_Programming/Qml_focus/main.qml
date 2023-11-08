import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    width: 200
    height: 200

    Rectangle {
        id: rectangle
        width: 50
        height: 50
        color: "green"
        focus: true

        Keys.onPressed: (event) => {
            console.log("Rectangle onPressed: " + event.text)
            event.accepted = false
        }
    }

    Loader {
        id: loader
        anchors.centerIn: parent
        focus: true
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            loader.source = "Page.qml"
            // rectangle.focus = false
            loader.focus = true
        }
    }

    Keys.onPressed: (event) => {
        console.log("onPressed: " + event.text)
    }
}
