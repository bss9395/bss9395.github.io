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

    Component.onCompleted: {
        // console.debug(`rectangle:onCompleted`)
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

    onChildrenChanged: {
        // console.debug(`onChildrenChanged`)
        if(inited === false) {
            return
        }
        func_childrenChanged_disconnect()
        func_childrenChanged_connect()
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
            children[i].widthChanged.connect(slot_updateChildrenRect)
            children[i].heightChanged.connect(slot_updateChildrenRect)
            children[i].xChanged.connect(slot_updateChildrenRect)
            children[i].yChanged.connect(slot_updateChildrenRect)
        }
    }

//    function func_childrenChanged_connect_debug() {
//        console.debug(`function func_childrenChanged_connect() {`)
//        slot_updateChildrenRect()
//        for(var i = 0; i < children.length; i += 1) {
//            if(children[i] instanceof MouseArea) {     // MouseArea是visual组件
//                console.debug(`if(children[i] instanceof MouseArea) {`)
//                continue
//            } else if(children[i] instanceof Popup) {  // Popup是外围组件
//                console.debug(`} else if(children[i] instanceof Popup) {`)
//                continue
//            }
//            // 注意调试时slot_updateChildrenRect有外包
//            children[i].visibleChanged.connect(function() {
//                console.debug(`children[i].visibleChanged.connect(function() {`)
//                slot_updateChildrenRect()
//            })
//            children[i].widthChanged.connect(function() {
//                console.debug(`children[i].widthChanged.connect(function() {`)
//                slot_updateChildrenRect()
//            })
//            children[i].heightChanged.connect(function() {
//                console.debug(`children[i].heightChanged.connect(function() {`)
//                slot_updateChildrenRect()
//            })
//            children[i].xChanged.connect(function() {
//                console.debug(`children[i].xChanged.connect(function() {`)
//                slot_updateChildrenRect()
//            })
//            children[i].yChanged.connect(function() {
//                console.debug(`children[i].yChanged.connect(function() {`)
//                slot_updateChildrenRect()
//            })
//        }
//    }


    function slot_updateChildrenRect() {
        // console.debug(`function slot_updateChildrenRect() {`)
        var miniX = 0
        var maxiX = 0
        var miniY = 0
        var maxiY = 0
        for(var i = 0; i < children.length; i += 1) {
            if(children[i] instanceof MouseArea) {     // MouseArea是visual组件
                // console.debug(`if(children[i] instanceof MouseArea) {`)
                continue
            } else if(children[i] instanceof Popup) {  // Popup是外围组件
                // console.debug(`} else if(children[i] instanceof Popup) {`)
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
        // console.debug(`rectangle.width = ${rectangle.width}, rectangle.height = ${rectangle.height}`)
    }
}
