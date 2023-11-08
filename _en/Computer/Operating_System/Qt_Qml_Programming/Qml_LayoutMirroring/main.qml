import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    width: 300
    height: 60
    color: "lightyellow"
    border.width: 1
    LayoutMirroring.enabled: true
    LayoutMirroring.childrenInherit: true

    Row {
        anchors.left: parent.left
        anchors.margins: 5
        y: 5
        spacing: 5
        padding: 5

        Repeater {
            model: 5

            Rectangle {
                id: rectangle
                width: 40
                height: 40
                color: "grey"
                opacity: (5 - index) / 5

                Text {
                    anchors.centerIn: parent
                    text: rectangle.Positioner.index + 1
                    font.bold: true
                }
            }
        }
    }
}
