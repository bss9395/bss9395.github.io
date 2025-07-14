import QtQuick 2.0

Rectangle {
    property bool inited: false
    id: rectangle
    color: "#00FFFFFF"

    onChildrenRectChanged: {
        // console.debug(`rectangle:onChildrenRectChanged: childrenRect = ${childrenRect}`)
        if(inited === false) {
            return
        }
        childrenRectChanged()
    }

    Component.onCompleted: {
        // console.debug(`rectangle:onCompleted`)
        childrenRectChanged()
        rectangle.inited = true
        // console.debug(`rectangle:parent = ${parent}`)
    }

    function childrenRectChanged() {
        // console.debug(`function childrenRectChanged() {`)
        width = childrenRect.x + childrenRect.width
        height = childrenRect.y + childrenRect.height
    }
}
