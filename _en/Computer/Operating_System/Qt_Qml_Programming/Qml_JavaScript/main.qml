import QtQuick 2.12
import QtQuick.Window 2.12
import "Function.js" as FunctionJs

Item {
    visible: true
    width: 640
    height: 480

    Row {
        Button {
            color: "red"
        }

        Button {
            color: "blue"
        }

        Button {
            color: "green"
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        propagateComposedEvents: true

        onClicked: {
            console.log(FunctionJs.factorial(10))
            mouse.accepted = false
        }
    }

    Component.onCompleted: {
        mouseArea.clicked.connect(FunctionJs.jsFunction)
    }
}
