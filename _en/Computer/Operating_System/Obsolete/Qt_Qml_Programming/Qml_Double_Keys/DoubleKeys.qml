import QtQuick 2.0

Rectangle {
    id: rectangle
    width: 200
    height: 200

    Keys.onPressed: (event) => {
        console.debug(`rectangle:onPressed`)
        event.accepted = true
    }

    Keys.onReleased: (event) => {
        console.debug(`rectangle:onReleased`)
        event.accepted = true
    }

    Rectangle {
        id: rectangle_inner
        width: 100
        height: 100
        color: "red"
        focus: true

        Keys.onPressed: (event) => {
            console.debug(`rectangle_inner:onPressed`)
            event.accepted = false
        }

        Keys.onReleased: (event) => {
            console.debug(`rectangle_inner:onReleased`)
            event.accepted = false
        }
    }
}
