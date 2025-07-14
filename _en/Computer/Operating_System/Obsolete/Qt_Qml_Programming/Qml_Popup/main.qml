import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Rectangle {
    signal test()
    id: rectangle
    width: 400
    height: 300

    Button {
        text: "Popup"

        onClicked: {
            var popup_component = Qt.createComponent("Popup_Button.qml")
            if(popup_component.status === Component.Ready) {
                var popup_object = popup_component.createObject(rectangle, { "father": rectangle })
                popup_object.open()
            }
        }
    }

    onTest: {
        console.debug('onTest')
    }

    Component.onCompleted: {
        console.debug('onCompleted')
        var jsonItem = { "father": rectangle }
        console.debug(JSON.stringify(jsonItem))

    }
}
