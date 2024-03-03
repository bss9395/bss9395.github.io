import QtQuick 2.0

Rectangle {
    default property alias defaultData: rectangle_default.data  // data==children+resources
    property alias background: rectangle_background.data        // data==children+resources
    id: rectangle
    color: "#00FFFFFF"

    Rectangle {
        id: rectangle_background
        anchors.fill: rectangle_default
        color: "#00FFFFFF"

        onChildrenChanged: {
            console.debug(`rectangle_background:onChildrenChanged`)
            for(var i = 0; i < children.length; i += 1) {
                children[i].width = width
                children[i].height = height
            }
        }

        onWidthChanged: {
            console.debug(`rectangle_background:onWidthChanged`)
            for(var i = 0; i < children.length; i += 1) {
                children[i].width = width
            }
        }

        onHeightChanged: {
            console.debug(`rectangle_background:onHeightChanged`)
            for(var i = 0; i < children.length; i += 1) {
                children[i].height = height
            }
        }
    }

    Rectangle {
        id: rectangle_default
        anchors.fill: parent
        color: "#00FFFFFF"

        onChildrenChanged: {
            console.debug(`rectangle_default:onChildrenChanged`)

        }
    }
}
