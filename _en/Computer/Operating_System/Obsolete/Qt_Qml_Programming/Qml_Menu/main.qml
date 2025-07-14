import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        Menu {
            id: menu_popup

            MenuItem {
                text: "Cut"
            }

            MenuItem {
                text: "Copy"
            }

            MenuItem {
                text: "Paste"
            }
        }

        onClicked: (mouse) => {
            if(mouse.button === Qt.RightButton) {
                menu_popup.popup()
            }
        }
    }

    Button {
        id: button
        x: 100
        y: 100
        text: "File"

        Menu {
            id: menu_open
            y: 0

            MenuItem {
                text: "New"
            }

            MenuItem {
                text: "Open"
            }

            MenuItem {
                text: "Save"
            }
        }

        onClicked: {
            menu_open.y = button.height
            menu_open.open()
        }
    }
}
