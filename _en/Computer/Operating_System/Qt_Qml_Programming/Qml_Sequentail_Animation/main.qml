import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12

Control  {
    visible: true
    width: 640
    height: 480

    Rectangle {
        id: rectangle_circle
        width: 50
        height: 50
        color: "red"
        radius: width / 2
        anchors.centerIn: parent

        SequentialAnimation {
            id: sequentialanimation
            running: true
            loops: Animation.Infinite

            PropertyAnimation {
                target: rectangle_circle
                properties: "opacity"
                to: 0
                duration: 1000
                easing.type: Easing.InOutQuad
            }

            PropertyAnimation {
                target: rectangle_circle
                properties: "opacity"
                to: 1
                duration: 1000
                easing.type: Easing.InOutQuad
            }
        }
    }
}
