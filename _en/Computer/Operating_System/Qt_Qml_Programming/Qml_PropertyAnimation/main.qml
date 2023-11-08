import QtQuick 2.14
import QtQuick.Window 2.14

Image {
    id: image_fengche
    visible: true
    width: 640
    height: 480
    source: "qrc:/images/fengche.png"
    opacity: 0.1

    MouseArea {
        anchors.fill: parent

        onClicked: {
            propertyanimation_opacity.start()
            numberanimation_rotation.start()
        }
    }

    PropertyAnimation {
        id: propertyanimation_opacity
        target: image_fengche
        properties: "opacity"
        to: 1.0
        duration: 2000
    }

    NumberAnimation {
        id: numberanimation_rotation
        target: image_fengche
        properties: "rotation"
        from: 0
        to: 360
        duration: 3000
        loops: Animation.Infinite
        easing.type: Easing.OutBack
    }
}
