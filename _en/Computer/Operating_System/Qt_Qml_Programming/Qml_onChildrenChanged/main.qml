import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        id: label
        text: "label"
        background: Rectangle {
            color: "red"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.debug(`label:onClicked`)
                var label_load = component_load.createObject(label)
                label_load.x = label.x + label.width
                label_load.y = label.y + label.height
            }
        }

        Component.onCompleted: {
            console.debug(`label:onCompleted`)
        }

        onChildrenChanged: {
            console.debug(`label:onChildrenChanged`)
        }
    }

    Component {
        id: component_load

        Label {
            id: label_load
            text: "label_load"
            background: Rectangle {
                color: "green"
            }
        }
    }
}
