import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    DoubleKeys {
        id: doublekeys

        Keys.onPressed: (event) => {
            console.debug(`doublekeys:onPressed`)
            event.accepted = true
        }

        Keys.onReleased: (event) => {
            console.debug(`doublekeys:onReleased`)
            event.accepted = true
        }

        Rectangle {
            id: rectangle_keys
            width: 100
            height: 100
            x: 100
            y: 100
            color: "green"

            Keys.onPressed: (event) => {
                console.debug(`rectangle_keys:onPressed`)
                event.accepted = false
            }

            Keys.onReleased: (event) => {
                console.debug(`rectangle_keys:onReleased`)
                event.accepted = false
            }
        }
    }
}
