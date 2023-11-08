import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12
import Qt.labs.settings 1.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    SplitView {
        id: splitview
        anchors.fill: parent
        orientation: Qt.Horizontal

        Rectangle {
            implicitWidth: 200
            color: "lightblue"
            SplitView.maximumWidth: 400

            Label {
                anchors.centerIn: parent
                text: "View 1"
            }
        }

        Rectangle {
            id: rectangle_center
            color: "lightgray"
            SplitView.minimumWidth: 50
            SplitView.fillWidth: true

            Label {
                anchors.centerIn: parent
                text: "View 2"
            }
        }

        Rectangle {
            implicitWidth: 200
            color: "lightgreen"

            Label {
                anchors.centerIn: parent
                text: "View 3"
            }
        }
    }

    Settings {
        id: settings
        fileName: "settings.ini"

        property var splitview_settings
    }

    Component.onCompleted: {
        splitview.restoreState(settings.splitview_settings)
    }

    Component.onDestruction: {
        settings.splitview_settings = splitview.saveState()
    }
}
