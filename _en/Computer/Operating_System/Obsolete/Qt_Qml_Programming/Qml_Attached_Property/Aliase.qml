import QtQuick 2.0

Rectangle {
    property alias inner: rectangle_inner
    property var json: {
        "key0": 10,
        "key1": "Hello",
        "key2": true
    }
    id: rectangle
    clip: false

    Rectangle {
        property var prop: "prop"
        id: rectangle_inner
        color: "red"
        clip: false

        onPropChanged: {
            console.debug(`rectangle_inner:onPropChanged`)
            color = prop
        }
    }
}
