import QtQuick 2.12
import QtQuick.Window 2.12

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
            // numberanimation_rotation.start()
            propertyanimation_rotation.start()
        }
    }

    PropertyAnimation {
        id: propertyanimation_opacity
        target: image_fengche
        property: "opacity"
        to: 1.0
        duration: 2000
    }

//    NumberAnimation {
//        id: numberanimation_rotation
//        target: image_fengche
//        property: "rotation"
//        from: 0
//        to: 360
//        duration: 3000
//        loops: Animation.Infinite
//        easing.type: Easing.OutBack
//    }

    PropertyAnimation {
        id: propertyanimation_rotation
        target: image_fengche
        property: "rotation"
        from: 0
        to: 360
        duration: 3000
        loops: Animation.Infinite
        easing.type: Easing.OutBack
    }
}
