import QtQuick 2.12

Rectangle {
    property bool inited: false
    id: rectangle
    color: "#00FFFFFF"

    onChildrenRectChanged: {
        console.debug(`rectangle:onChildrenRectChanged: childrenRect = ${childrenRect}`)
        if(inited === false) {
            return
        }
        childrenRectChanged()
    }

    Component.onCompleted: {
        console.debug(`rectangle:onCompleted`)
        childrenRectChanged()
        rectangle.inited = true
    }

    function childrenRectChanged() {
        console.debug(`function childrenRectChanged() {`)
        width = childrenRect.width
        height = childrenRect.height
    }
}
