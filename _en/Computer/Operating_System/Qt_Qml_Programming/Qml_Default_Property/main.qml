import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Group {
        title: "title"

        Rectangle {
            width: 100
            height: 50
            color: "red"
        }

        Rectangle {
            width: 100
            height: 50
            color: "lightblue"
        }
    }
}
