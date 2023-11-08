import QtQuick 2.0
import "Button.js" as ButtonJs

Rectangle {
    id: rectangle
    width: 200
    height: 100
    color: "red"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            ButtonJs.onClicked(rectangle)
        }
    }
}
