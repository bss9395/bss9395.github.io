import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: flickable.width
        height: flickable.height
        anchors.centerIn: parent
        color: "yellow"
    }

    Flickable {
        id: flickable
        width: 200
        height: 200
        anchors.centerIn: parent
        contentWidth: image.width
        contentHeight: image.height

        Image {
            id: image
            width: flickable.width / 2
            height: flickable.height / 2
            x: (flickable.width - width) / 2
            y: (flickable.height - height) / 2
            source: "qrc:/images/m31.png"

            Component.onCompleted: {
                console.debug(`flickable = ${flickable}, image.parent = ${image.parent}`)
            }
        }
    }
}
