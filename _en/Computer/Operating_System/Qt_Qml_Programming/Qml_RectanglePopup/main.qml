import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12




Window {
    id: window_root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        x: 300
        y: 300
        id: button
        text: "button"

        onClicked: {
            var rectanglepopup = compo.createObject(window_root)
            rectanglepopup.open()
        }
    }

    Component {
        id: compo

        RectanglePopup {
            width: 400
            height: 400
            background: Rectangle {
                color: "#FF00FF00"
            }

            Column {
                TextField {
                    property var name: "textfield"
                    text: "textfield"
                }
                Label {
                    property var name: "label"
                    text: "label"
                }
            }
        }
    }
}
