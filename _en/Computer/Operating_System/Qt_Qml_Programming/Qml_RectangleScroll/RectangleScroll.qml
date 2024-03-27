import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Rectangle {
    property var enum_scrollWidth : 0b0001
    property var enum_scrollHeight: 0b0010
    property var enum_scrollPane  : 0b0100

    ////////////////////////////////////////////////////////////////////////////

    default property var defaultData  : undefined
    readonly property real ratioWidth : rectangle.width  / rectangle_content.width
    readonly property real ratioHeight: rectangle.height / rectangle_content.height
    property var background    : undefined
    property var scrollType    : enum_scrollPane
    property var scrollDrag    : true
    property var canvasWidth   : 0
    property var canvasHeight  : 0
    property var locationWidth : 0.0
    property var locationHeight: 1.0 - ratioHeight
    property var magnifyMouse  : 1.0
    id: rectangle
    width : parent.width
    height: parent.height
    color: "#00FFFFFF"
    clip: true

    onDefaultDataChanged: {
        // console.debug(`rectangle:onDefaultDataChanged, defaultData = ${defaultData}`)
        if(defaultData) {
            rectangle_content.data.push(defaultData)
        }
    }

    onBackgroundChanged: {
        // console.debug(`rectangle:onBackgroundChanged, background = ${background}`)
        if(background) {
            rectangle_background.data.push(background)
        }
    }

    // 监听鼠标滚轮事件
    MouseArea {
        anchors.fill: parent

        // 鼠标每刻为15角度，鼠标delta值每刻为15*8=120
        // 鼠标顺指滚(屏幕上滚)为负值，鼠标逆指滚（屏幕下滚）为正值，鼠标只可滚动Y轴
        onWheel: (event) => {
            // console.debug(`rectangle:onWheel, event = ${JSON.stringify(event)}`)
            var deltaX = event.angleDelta.x / 8 * rectangle.magnifyMouse
            var deltaY = event.angleDelta.y / 8 * rectangle.magnifyMouse
            rectangle.locationWidth  = rectangle_content.locationWidth  + deltaX / rectangle_content.width
            rectangle.locationHeight = rectangle_content.locationHeight + deltaY / rectangle_content.height

            rectangle_content.stillY = rectangle_content.y  // 转为定位模式
        }
    }

    // 背景组件
    Rectangle {
        id: rectangle_background
        anchors.fill: rectangle
        color: "#00FFFFFF"
        clip: false

        onChildrenChanged: {
            // console.debug(`rectangle_background:onChildrenChanged, children.length = ${children.length}, rectangle_background.width = ${rectangle_background.width}, rectangle_background.height = ${rectangle_background.height}`)
            for(var i = 0; i < children.length; i += 1) {
                if(children[i].width <= 0) {
                    children[i].width = Qt.binding(function () {
                        return rectangle_background.width
                    })
                }
                if(children[i].height <= 0) {
                    children[i].height = Qt.binding(function () {
                        return rectangle_background.height
                    })
                }
            }
        }
    }

    // 内容组件
    RectangleFit {
        property var stillX: null
        property var stillY: null
        property var ratioWidth : {
            var ratio = rectangle.ratioWidth
            if((0.05 <= ratio) === false) {  // 限制把柄最小宽度
                ratio = 0.0
            }
            if((ratio <= 1.0) === false) {
                ratio = 1.0
            }
            // console.debug(`rectangle_content:property var ratioWidth: {, rectangle_content.ratioWidth = ${ratio}`)
            return ratio
        }
        property var ratioHeight: {
            var ratio = rectangle.ratioHeight
            if((0.05 <= ratio) === false) {  // 限制把柄最小高度
                ratio = 0.0
            }
            if((ratio <= 1.0) === false) {
                ratio = 1.0
            }
            // console.debug(`rectangle_content:property var ratioHeight: {, rectangle_content.ratioHeight = ${ratio}`)
            return ratio
        }
        property var locationWidth : {
            var location = stillX ? (-stillX / rectangle_content.width) : rectangle.locationWidth
            if((0.0 <= location) === false) {
                location = 0.0
            }
            if((location <= 1.0 - rectangle_content.ratioWidth) === false) {
                location = 1.0 - rectangle_content.ratioWidth
            }
            // console.debug(`rectangle_content:property var locationWidth: {, stillX = ${stillX}, rectangle_content.locationWidth = ${location}`)
            return location
        }
        property var locationHeight: {
            var location = stillY ? (-stillY / rectangle_content.height) : rectangle.locationHeight
            if((0.0 <= location) === false) {
                location = 0.0
            } else if((location <= 1.0 - rectangle_content.ratioHeight) === false) {
                location = 1.0 - rectangle_content.ratioHeight  // 当rectangle_content.ratioHeight减小时，转为底部跟踪模式
            }
            // console.debug(`rectangle_content:property var locationHeight: {, stillY = ${stillY}, rectangle_content.locationHeight = ${location}`)
            return location
        }
        id: rectangle_content
        width : rectangle.canvasWidth
        height: rectangle.canvasHeight
        x: -(rectangle_content.width  * rectangle_content.locationWidth )
        y: -(rectangle_content.height * rectangle_content.locationHeight)
        color: "#00FFFFFF"
        clip: false

    }

    // 水平滚动条
    Rectangle {
        id: rectangle_width_shadow
        visible: (rectangle.scrollType & rectangle.enum_scrollWidth) === rectangle.enum_scrollWidth
        width : rectangle.width - height
        height: 10
        anchors.left: rectangle.left
        anchors.bottom: rectangle.bottom
        color: "#20000000"

        // 水平滚动条把柄
        Rectangle {
            id: rectangle_width_handle
            width : rectangle_width_shadow.width * rectangle_content.ratioWidth
            height: rectangle_width_shadow.height - 2
            x: rectangle_width_shadow.width * rectangle_content.locationWidth
            y: (rectangle_width_shadow.height - height) / 2
            radius: height / 5 * 2
            color: "#A000FF00"

            MouseArea {
                property var mouse_pressed: ({})
                anchors.fill: parent

                onPressed: {
                    // console.debug(`rectangle_width_handle:onPressed`)
                    rectangle_content.stillX = null  // 转为跟踪模式
                    var mouse_global = config.cursorPos()
                    mouse_pressed.locationWidth = rectangle_content.locationWidth
                    mouse_pressed.x = mouse_global.x
                }

                onPositionChanged: {
                    // console.debug(`rectangle_height_handle:onPositionChanged`)
                    var mouse_global = config.cursorPos()
                    var mouse_drift_x = mouse_global.x - mouse_pressed.x
                    rectangle.locationWidth = mouse_pressed.locationWidth + mouse_drift_x / rectangle_width_shadow.width
                }

                onReleased: (event) => {
                    // console.debug(`rectangle_height_handle:onReleased`)
                    rectangle_content.stillX = rectangle_content.x  // 转为定位模式
                }
            }
        }
    }

    // 垂直滚动条
    Rectangle {
        id: rectangle_height_shadow
        visible: (rectangle.scrollType & rectangle.enum_scrollHeight) === rectangle.enum_scrollHeight
        width : 10
        height: rectangle.height - width
        anchors.right: rectangle.right
        anchors.top: rectangle.top
        color: "#20000000"

        // 垂直滚动条把柄
        Rectangle {
            id: rectangle_height_handle
            width : rectangle_height_shadow.width - 2
            height: rectangle_height_shadow.height * rectangle_content.ratioHeight
            x: (rectangle_height_shadow.width - width) / 2
            y: rectangle_height_shadow.height * rectangle_content.locationHeight
            radius: width / 5 * 2
            color: "#A000FF00"

            MouseArea {
                property var mouse_pressed: ({})
                anchors.fill: parent

                onPressed: (event) => {
                    // console.debug(`rectangle_height_handle:onPressed`)
                    rectangle_content.stillY = null  // 转为跟踪模式
                    var mouse_global = config.cursorPos()
                    mouse_pressed.locationHeight = rectangle_content.locationHeight
                    mouse_pressed.y = mouse_global.y
                }

                onPositionChanged: (event) => {
                    // console.debug(`rectangle_height_handle:onPositionChanged`)
                    var mouse_global = config.cursorPos()
                    var mouse_drift_y = mouse_global.y - mouse_pressed.y
                    rectangle.locationHeight = mouse_pressed.locationHeight + mouse_drift_y / rectangle_height_shadow.height
                }

                onReleased: (event) => {
                    // console.debug(`rectangle_height_handle:onReleased`)
                    rectangle_content.stillY = rectangle_content.y  // 转为定位模式
                }
            }
        }
    }

    // 平面缩略图
    Rectangle {
        id: rectangle_thumbnail_shadow
        visible: (rectangle.scrollType & rectangle.enum_scrollPane) === rectangle.enum_scrollPane
        width : rectangle.width / rectangle.height * height
        height: {
            var height_prefered = rectangle.height / 10 * 2
            if((height_prefered <= 100) === false) {
                height_prefered = 100
            }
            return height_prefered
        }
        x: rectangle.x + rectangle.width  - width
        y: rectangle.y + rectangle.height - height
        color: "#20000000"

        MouseArea {
            property var mouse_pressed: ({})
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton  // 注意MouseArea默认只监听Qt.LeftButton

            onPressed: (event) => {
                // console.debug(`rectangle_thumbnail_shadow:onPressed, event = ${JSON.stringify(event)}`)
                if(scrollDrag === true) {
                    var mouse_global = config.cursorPos()
                    mouse_pressed.shadow_x = rectangle_thumbnail_shadow.x
                    mouse_pressed.shadow_y = rectangle_thumbnail_shadow.y
                    mouse_pressed.x = mouse_global.x
                    mouse_pressed.y = mouse_global.y
                }
            }

            onPositionChanged: (event) => {
                // console.debug(`rectangle_thumbnail_shadow:onPositionChanged, event = ${JSON.stringify(event)}`)
                if(scrollDrag === true) {
                    var mouse_global = config.cursorPos()
                    var mouse_drift_x = mouse_global.x - mouse_pressed.x
                    var mouse_drift_y = mouse_global.y - mouse_pressed.y
                    rectangle_thumbnail_shadow.x = mouse_pressed.shadow_x + mouse_drift_x
                    rectangle_thumbnail_shadow.y = mouse_pressed.shadow_y + mouse_drift_y
                }
            }

            onReleased: (event) => {
                // console.debug(`rectangle_thumbnail_shadow:onReleased, event = ${JSON.stringify(event)}`)
                if(event.button === Qt.RightButton) {
                    rectangle_content.stillX = rectangle_content.stillX ? null : rectangle_content.x  // 若为定位模式则转为跟踪模式，反之亦然。
                    rectangle_content.stillY = rectangle_content.stillY ? null : rectangle_content.y  // 若为定位模式则转为跟踪模式，反之亦然。
                }
            }
        }

        // 平面缩略图把柄
        Rectangle {
            id: rectangle_thumbnail_handle
            width : rectangle_thumbnail_shadow.width  * rectangle_content.ratioWidth
            height: rectangle_thumbnail_shadow.height * rectangle_content.ratioHeight
            x: rectangle_thumbnail_shadow.width  * rectangle_content.locationWidth
            y: rectangle_thumbnail_shadow.height * rectangle_content.locationHeight
            color: "#A000FF00"

            MouseArea {
                property var mouse_pressed: ({})
                anchors.fill: parent
                propagateComposedEvents: true

                onPressed: (event) => {
                    // console.debug(`rectangle_thumbnail_handle:onPressed, event = ${JSON.stringify(event)}`)
                    rectangle_content.stillX = null  // 转为跟踪模式
                    rectangle_content.stillY = null  // 转为跟踪模式
                    var mouse_global = config.cursorPos()
                    mouse_pressed.locationWidth  = rectangle_content.locationWidth
                    mouse_pressed.locationHeight = rectangle_content.locationHeight
                    mouse_pressed.x = mouse_global.x
                    mouse_pressed.y = mouse_global.y
                }

                onPositionChanged: (event) => {
                    // console.debug(`rectangle_thumbnail_handle:onPositionChanged, event = ${JSON.stringify(event)}`)
                    var mouse_global = config.cursorPos()
                    var mouse_drift_x = mouse_global.x - mouse_pressed.x
                    var mouse_drift_y = mouse_global.y - mouse_pressed.y
                    rectangle.locationWidth  = mouse_pressed.locationWidth  + mouse_drift_x / rectangle_thumbnail_shadow.width
                    rectangle.locationHeight = mouse_pressed.locationHeight + mouse_drift_y / rectangle_thumbnail_shadow.height
                }

                onReleased: (event) => {
                    // console.debug(`rectangle_thumbnail_handle:onReleased, event = ${JSON.stringify(event)}`)
                    rectangle_content.stillX = rectangle_content.x  // 转为定位模式
                    rectangle_content.stillY = rectangle_content.y  // 转为定位模式
                    event.accepted = false  // 传播鼠标释放事件到底层平面缩略图
                }
            }
        }
    }
}
