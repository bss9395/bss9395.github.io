import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true

    Popup {
        id: popup
        visible: true
        anchors.centerIn: Overlay.overlay
        margins: 0
        padding: 0
        background: Rectangle {
            color: "#00FFFFFF"
        }
        closePolicy: popup.NoAutoClose
        modal: false
        dim: true

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
                width: 48
                height: 48
                anchors.centerIn: parent
                running: (parent.visible === true) && (image.status === Image.Loading)  // note: be cautious with running
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


}

