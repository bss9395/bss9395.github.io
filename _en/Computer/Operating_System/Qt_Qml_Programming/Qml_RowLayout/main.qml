import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

Rectangle {
    width: 400
    height: 300

    RowLayout {
        id: rowlayout
        anchors.fill: parent
        spacing: 6

        Rectangle {
            color: "lightgrey"

            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100
            Layout.maximumWidth: 300
            Layout.minimumHeight: 150

            Text {
                anchors.centerIn: parent
                text: parent.width + "x" + parent.height
            }
        }

        Rectangle {
            color: "black"

            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 200
            Layout.preferredHeight: 100

            Text {
                anchors.centerIn: parent
                color: "white"
                text: parent.width + "x" + parent.height
            }
        }
    }
}
