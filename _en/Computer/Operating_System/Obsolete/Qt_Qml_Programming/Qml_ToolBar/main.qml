import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar {
        Row {
            anchors.fill: parent

            ToolButton {
                text: "Action 1"
            }

            ToolButton {
                text: "Action 2"
            }

            ToolSeparator {

            }

            ToolButton {
                text: "Action 3"
            }

            ToolButton {
                text: "Action 4"
            }
        }
    }
}
