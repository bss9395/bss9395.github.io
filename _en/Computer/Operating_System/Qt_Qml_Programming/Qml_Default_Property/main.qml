import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Container {
        id: container
        width: 400
        height: 400
        background: Rectangle {
            color: "red"
        }

        onChildrenChanged: {
            console.debug(`container:onChildrenChanged`)

        }

        Rectangle {
            width: 100
            height: 100
            color: "green"
        }

        Text {
            anchors.centerIn: parent
            text: "text"
        }
    }
}
