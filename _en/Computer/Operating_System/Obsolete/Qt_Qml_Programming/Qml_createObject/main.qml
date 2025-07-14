import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQml 2.12

Rectangle {
    id: rectangle_root
    width: 800
    height: 600
    visible: true

    Grid {
        columns: 2
        spacing: 10

        Repeater {
            model: 2

            delegate: Rectangle {
                id: rectangle_item
                width: 200
                height: 200
                color: "blue"

                Button {
                    text: "button"

                    onClicked: {
                        var popup_component = Qt.createComponent("Rectangle_Button.qml")
                        if(popup_component.status === Component.Ready) {
                            var popup_object = popup_component.createObject(rectangle_root, { "father": rectangle_item })
                            popup_object.open()
                        }
                    }
                }
            }
        }
    }
}
