import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    width: 200
    height: 200

    Component {
        id: component
        Rectangle {
            width: 50
            height: 50
            color: "green"
        }
    }

    Loader {
        id: loader
        anchors.centerIn: parent
        sourceComponent: component
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            loader.source = "Page.qml"
        }
    }
}
