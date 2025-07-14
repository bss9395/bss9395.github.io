import QtQuick 2.0

Rectangle {
    id: rectangle
    width: 20
    height: 20
    color: "red"

    Drag.active: mousearea.drag.active
    Drag.hotSpot.x: rectangle.width / 2
    Drag.hotSpot.y: rectangle.height / 2
    Drag.source: rectangle

    MouseArea {
        id: mousearea
        anchors.fill: parent
        drag.target: parent
    }
}
