import QtQuick 2.12
import QtQuick.Window 2.12
import "create_component.js" as Create_Component

Rectangle {
    id: appWindow
    visible: true
    width: 640
    height: 480

    component LabeledImage: Column {
        property alias source: image.source
        property alias caption: text.text

        Image {
            id: image
            width: 50
            height: 50
        }
        Text {
            id: text
            font.bold: true
        }
    }

    Row {
        id: row
        LabeledImage {
            source: "after.png"
            caption: "Before"
        }

        LabeledImage {
            source: "before.png"
            caption: "After"
        }
    }

    Component {
        id: redSquare

        Rectangle {
            color: "red"
            width: 10
            height: 10
        }
    }

    Loader {
        sourceComponent: redSquare
        x: 0
        anchors.top: row.bottom
    }

    Loader {
        sourceComponent: redSquare
        x: 20
        anchors.top: row.bottom
    }

    Component.onCompleted: {
        Create_Component.createSpriteObjects();

        var sprite = Qt.createQmlObject('
            import QtQuick 2.9
            Rectangle {
                color: "red"
                width: 20
                height: 20
                x: 200
                y: 200
            }
        ', appWindow)
        sprite.destroy(1000)

        var component = Qt.createComponent("SelfDestroyRectangle.qml")
        for(var i = 0; i < 5; i += 1) {
            var object = component.createObject(appWindow)
            object.x = (object.width + 10) * i
        }
    }
}
