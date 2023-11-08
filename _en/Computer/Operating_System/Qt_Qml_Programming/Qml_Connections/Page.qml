import QtQuick 2.0

Rectangle {
    id: rectangle_message
    width: 100
    height: 100
    color: "red"

    signal signal_message(string msg)

    MouseArea {
        anchors.fill: parent

        onClicked: {
            rectangle_message.signal_message("clicked")
        }
    }
}
