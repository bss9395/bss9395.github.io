import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true


    Pane {
        width: 400
        height: 300
        anchors.centerIn: parent

        Image {
            id: image
            anchors.fill: parent
            source: "https://www.qter.org/temp/back.png"
        }

        BusyIndicator {
            id: busyindicator
            anchors.centerIn: parent
            running: image.status === Image.Loading
        }

        ProgressBar {
            width: parent.width - 20
            anchors.top: busyindicator.bottom
            anchors.horizontalCenter: busyindicator.horizontalCenter
            visible: image.status === Image.Loading
            value: image.progress
        }
    }
}

