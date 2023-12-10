import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: button
        x: 200
        y: 200
        text: "button"

        MouseArea {
            id: mousearea
            anchors.fill: parent

            onClicked: (mouse) => {
                console.debug(mouse)
                var popup_object = loadComponent(window, "Popup_Button.qml", { "father": window })
                popup_object.anchors.centerIn = undefined
                popup_object.x = button.x + button.width - popup_object.width
                popup_object.y = button.y + button.height + 10
                // popup_object.open()
            }
        }
    }

    function loadComponent(parent, qmlfile, parameters = {}) {
        var popup_object = undefined
        var popup_component = Qt.createComponent(qmlfile)
        if(popup_component.status === Component.Ready) {
            popup_object = popup_component.createObject(parent, parameters)
        }
        return popup_object
    }
}
