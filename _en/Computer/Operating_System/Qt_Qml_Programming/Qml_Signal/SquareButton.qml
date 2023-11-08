import QtQuick 2.0

Rectangle {
    id: root

    signal activated(xPosition: var, yPosition: var)
    signal deactivated()
    signal messageReceived(string person, string notice)
    signal send(mouse: var)

    property int side: 100
    width: side
    height: side
    color: "red"

    MouseArea {
        id: mouseArea

        anchors.fill: parent

        onClicked: {
            console.log("Mouse Area clicked")
        }

        onPressed: (mouse) => {
            root.activated(mouse.x, mouse.y)
        }

        onReleased: {
            root.deactivated()
        }
    }

    Connections {
        target: mouseArea

        onClicked: {
            root.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0)
        }
    }

    Component.onCompleted: {
        root.messageReceived.connect(sendToPost)
        root.messageReceived.connect(sendToTelegraph)
        root.messageReceived.connect(sendToEmail)
        root.messageReceived("Tom", "Happy birthday")

        mouseArea.clicked.connect(send)
    }

    onActivated: function(xPosition, yPosition) {
        console.log("Activated at ", xPosition, ", ", yPosition)
    }

    onDeactivated: {
        console.log("Deactivated")
    }

    onSend: {
        console.log("Send Clicked")
    }

    function sendToPost(person, notice) {
        console.log("sending to post: ", person, ", ", notice)
    }

    function sendToTelegraph(person, notice) {
        console.log("sending to telegraph: ", person, ", ", notice)
    }

    function sendToEmail(person, notice) {
        console.log("sending to Email: ", person, ", ", notice)
    }
}
