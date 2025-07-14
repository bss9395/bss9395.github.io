import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    visible: true
    width: 640
    height: 480

    Rectangle {
        width: 50
        height: width * 2
        color: "red"
        anchors.centerIn: parent
        focus: true

        MouseArea {
            anchors.fill: parent

            onClicked: {
                parent.width += 10
            }
        }

        Keys.onSpacePressed: {
            height = Qt.binding(function () {
                return width * 3
            })
        }
    }
}
