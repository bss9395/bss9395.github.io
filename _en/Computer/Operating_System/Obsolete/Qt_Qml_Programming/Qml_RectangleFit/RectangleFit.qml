import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    property var initedWidth : false
    property var initedHeight: false
    property var inited      : false
    id    : rectangle
    width : 0
    height: 0
    color : "#00FFFFFF"

    onChildrenChanged: {
        console.debug(`rectangle:onChildrenChanged`)
        if(inited === false) {
            return
        }
        func_childrenChanged_disconnect()
        func_childrenChanged_connect()
    }

    Component.onCompleted: {
        console.debug(`rectangle:onCompleted, width = ${width}`)
        if(0 < width) {
            initedWidth  = true
        }
        if(0 < height) {
            initedHeight = true
        }
        inited = true

        func_childrenChanged_connect()
    }

    Component.onDestruction: {
        console.debug(`rectangle:onDestruction`)
        func_childrenChanged_disconnect()
    }

    function func_childrenChanged_disconnect() {
        // console.debug(`function func_childrenChanged_disconnect() {`)
        for(var i = 0; i < children.length; i += 1) {
            // 注意调试时slot_updateChildrenRect有外包
            children[i].visibleChanged.disconnect(slot_updateChildrenRect)
            children[i].widthChanged.disconnect(slot_updateChildrenRect)
            children[i].heightChanged.disconnect(slot_updateChildrenRect)
            children[i].xChanged.disconnect(slot_updateChildrenRect)
            children[i].yChanged.disconnect(slot_updateChildrenRect)
        }
    }

    function func_childrenChanged_connect() {
        // console.debug(`function func_childrenChanged_connect() {`)
        slot_updateChildrenRect()
        for(var i = 0; i < children.length; i += 1) {
            if(children[i] instanceof MouseArea) {     // MouseArea是visual组件
                // console.debug(`if(children[i] instanceof MouseArea) {`)
                continue
            } else if(children[i] instanceof Popup) {  // Popup是外围组件
                // console.debug(`} else if(children[i] instanceof Popup) {`)
                continue
            }
            // 注意调试时slot_updateChildrenRect有外包
            children[i].visibleChanged.connect(slot_updateChildrenRect)
            if(initedWidth === false) {
                children[i].xChanged.connect(slot_updateChildrenRect)
                children[i].widthChanged.connect(slot_updateChildrenRect)
            }
            if(initedHeight === false) {
                children[i].yChanged.connect(slot_updateChildrenRect)
                children[i].heightChanged.connect(slot_updateChildrenRect)
            }
        }
    }

    function slot_updateChildrenRect() {
        // console.debug(`function slot_updateChildrenRect() {`)
        var miniX = null
        var maxiX = null
        var miniY = null
        var maxiY = null
        for(var i = 0; i < children.length; i += 1) {
            if(children[i] instanceof MouseArea) {     // MouseArea是visual组件
                // console.debug(`if(children[i] instanceof MouseArea) {`)
                continue
            } else if(children[i] instanceof Popup) {  // Popup是外围组件
                // console.debug(`} else if(children[i] instanceof Popup) {`)
                continue
            } else if(children[i].visible === true) {
                console.debug(`children[i] = ${children[i].name}, ${children[i].x}, ${children[i].y}, ${children[i].width}, ${children[i].height}, ${children[i].visible}`)
                var headX = children[i].x - children[i].anchors.leftMargin                         // 瞬态水平锚点
                var tailX = children[i].x + children[i].width  + children[i].anchors.rightMargin   // 瞬态右边界
                var headY = children[i].y - children[i].anchors.topMargin                          // 瞬态垂直锚点
                var tailY = children[i].y + children[i].height + children[i].anchors.bottomMargin  // 瞬态下边界
                if(miniX === null || headX < miniX) {
                    miniX = headX
                }
                if(maxiX === null || maxiX < tailX) {
                    maxiX = tailX
                }
                if(miniY === null || headY < miniY) {
                    miniY = headY
                }
                if(maxiY === null || maxiY < tailY) {
                    maxiY = tailY
                }
            }
        }

        console.debug(`before :rectangle.width = ${maxiX - miniX}, rectangle.height = ${rectangle.height}`)
        if(initedWidth === false) {
            rectangle.width  = maxiX - miniX
        }
        if(initedHeight === false) {
            rectangle.height = maxiY - miniY
        }
        console.debug(`after :rectangle.width = ${rectangle.width}, rectangle.height = ${rectangle.height}`)
    }
}
