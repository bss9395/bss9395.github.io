import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: 50
        height: 40
        x: 100
        y: 100
        color: "red"

        Control {
            width: 40
            height: 30
            topPadding: 5
            leftPadding: 2
            topInset: -2
            leftInset: -2
            rightInset: -6
            bottomInset: -6

            background: Rectangle {
                color: "green"
            }

            contentItem: Rectangle {
                color: "yellow"
            }
        }
    }
}
