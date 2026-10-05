import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 500
    height: 400
    visible: true

    Column {
        spacing: 10
        anchors.centerIn: parent

        Image {
            width: 100
            height: 100
            source: "image://myprovider/circle"
        }

        Image {
            width: 100
            height: 100
            source: "image://myprovider/square"
        }

        Image {
            width: 400
            height: 180
            source: "image://myprovider/Hello World"
        }
    }
}
