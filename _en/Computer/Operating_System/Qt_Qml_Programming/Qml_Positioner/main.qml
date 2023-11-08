import QtQuick 2.12
import QtQuick.Window 2.12

Grid {
    padding: 5

    Repeater {
        model: 16

        Rectangle {
            id: rectangle
            width: 40
            height: 40
            border.width: 1
            color: rectangle.Positioner.index === 3 ? "yellow" : "lightsteelblue"

            Text {
                anchors.centerIn: parent
                text: rectangle.Positioner.index;
            }
        }
    }
}
