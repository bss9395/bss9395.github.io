import QtQuick 2.0

Rectangle {
    property var initedWidth : false
    property var initedHeight: false
    property var inited      : false
    id    : rectangle
    width : 0
    height: 0
    color : "#FFFF0000"

    Component.onCompleted: {
        console.debug(`rectangle:onCompleted, childrenRect = ${JSON.stringify(childrenRect)}`)
        if(0 < width) {
            initedWidth  = true
        }
        if(0 < height) {
            initedHeight = true
        }

        slot_updateChildrenRect()
        func_childrenChanged()
        inited = true
    }

    onChildrenChanged: {
        if(inited === false) {
            return
        }
        console.debug(`onChildrenChanged`)
        func_childrenChanged()
    }

    function func_childrenChanged() {
        console.debug(`function func_childrenChanged() {`)
        for(var i = 0; i < children.length; i += 1) {
            children[i].visibleChanged.disconnect(slot_updateChildrenRect)
            children[i].widthChanged.disconnect(slot_updateChildrenRect)
            children[i].heightChanged.disconnect(slot_updateChildrenRect)
            children[i].xChanged.disconnect(slot_updateChildrenRect)
            children[i].yChanged.disconnect(slot_updateChildrenRect)
        }
        for(var j = 0; j < children.length; j += 1) {
            if(children[i] instanceof MouseArea) {  // MouseArea是visual组件
                console.debug(`if(children[i] instanceof MouseArea) {`)
                continue
            }
            children[j].visibleChanged.connect(function() {
                console.debug(`children[j].visibleChanged.connect(function() {`)
                slot_updateChildrenRect()
            })
            children[j].widthChanged.connect(function() {
                console.debug(`children[j].widthChanged.connect(function() {`)
                slot_updateChildrenRect()
            })
            children[j].heightChanged.connect(function() {
                console.debug(`children[j].heightChanged.connect(function() {`)
                slot_updateChildrenRect()
            })
            children[j].xChanged.connect(function() {
                console.debug(`children[j].xChanged.connect(function() {`)
                slot_updateChildrenRect()
            })
            children[j].yChanged.connect(function() {
                console.debug(`children[j].yChanged.connect(function() {`)
                slot_updateChildrenRect()
            })
        }
    }

    function slot_updateChildrenRect() {
        // console.debug(`function slot_updateChildrenRect() {`)
        var miniX = 0
        var maxiX = 0
        var miniY = 0
        var maxiY = 0
        for(var i = 0; i < children.length; i += 1) {
            if(children[i] instanceof MouseArea) {  // MouseArea是visual组件
                console.debug(`if(children[i] instanceof MouseArea) {`)
                continue
            } else if(children[i].visible === true) {
                if(children[i].x < miniX) {
                    miniX = children[i].x
                }
                if(maxiX < children[i].x + children[i].width) {
                    maxiX = children[i].x + children[i].width
                }
                if(children[i].y < miniY) {
                    miniY = children[i].y
                }
                if(maxiY < children[i].y + children[i].height) {
                    maxiY = children[i].y + children[i].height
                }
            }
        }
        if(initedWidth === false) {
            rectangle.width  = maxiX - miniX
        }
        if(initedHeight === false) {
            rectangle.height = maxiY - miniY
        }
        console.debug(`rectangle.width = ${rectangle.width}, rectangle.height = ${rectangle.height}`)
    }
}
