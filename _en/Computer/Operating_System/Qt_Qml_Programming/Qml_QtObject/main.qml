import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    visible: true
    width: 640
    height: 480

    Item {
        width: 200
        height: 200

        Rectangle {
            anchors.fill: parent
            color: "red"
            objectName: "object_rectangle"
        }
    }
}
