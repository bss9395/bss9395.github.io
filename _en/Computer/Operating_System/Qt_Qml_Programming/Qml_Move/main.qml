import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    flags: Qt.FramelessWindowHint | Qt.Window
    title: qsTr("Hello World")
    color: "lightblue"

    TitleBar {
        id: titlebar
    }
}
