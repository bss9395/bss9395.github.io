import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    property var enum_closeOutsideEscape: "enum_closeOutsideEscape"
    property var enum_closeManual       : "enum_closeManual"

    ////////////////////////////////////////////////////////////////////////////

    signal opened()
    signal closed()
    default property var defaultData: undefined
    property var background         : undefined
    property var strategy    : enum_closeOutsideEscape
    property var modal       : true
    property var dim         : true
    property var draggable   : true
    property var dragDistance: 20
    id: rectangle
    enabled: true
    visible: false
    width : parent.width  / 4
    height: parent.height / 2
    x: (parent.width  - width ) / 2
    y: (parent.height - height) / 2
    color: "#00FFFFFF"
    clip: false

    onDefaultDataChanged: {
        console.debug(`rectangle:onDefaultDataChanged`)
        if(defaultData) {
            item_loader.loader.aliasData.push(defaultData)
        }
    }

    onBackgroundChanged: {
        console.debug(`rectangle:onBackgroundChanged, background = ${background}`)
        if(background) {
            item_loader.loader.aliasBackground.push(background)
        }
    }

    function open() {
        console.debug(`rectangle:function open() {`)
        item_loader.loader.open()
    }

    function close() {
        console.debug(`rectangle:function close() {`)
        item_loader.loader.close()
    }

    function toggle(on_off) {
        console.debug(`function toggle(on_off) {`)
        item_loader.loader.toggle(on_off)
    }

    Item {
        property var loader: component_overlay.createObject(rectangle, {  // 函数阻塞调用
            "rectangle": rectangle                                        // 此处存在回环
        })
        id: item_loader
        visible: false
        width : 0
        height: 0

        Component.onCompleted: {
            console.debug(`item_loader:onCompleted`)
            loader.parent = Overlay.overlay
        }

        Component.onDestruction: {
            console.debug(`item_loader:onDestruction`)
            loader.destroy()
        }

        Component {
            id: component_overlay

            Rectangle {
                property alias aliasData      : rectangle_popup.data       // data==chlidren+resources
                property alias aliasBackground: rectangle_background.data  // data==children+resources
                property var rectangle: undefined
                id: rectangle_overlay
                enabled: rectangle.enabled
                visible: rectangle.visible
                anchors.fill: parent  // 暗淡覆盖整个软件页面
                color: (rectangle.dim === true) ? "#20000000" : "#00000000"
                clip: false

                // 监听暗淡键盘事件
                Keys.onPressed: (event) => {
                    console.debug(`rectangle_overlay:onPressed, event.key = ${event.key}`)
                    if(event.key === Qt.Key_Escape) {
                        console.debug(`if(event.key === Qt.Key_Escape) {`)
                        if(rectangle.strategy === rectangle.enum_closeOutsideEscape) {
                            rectangle_overlay.close()
                        }
                    }
                    event.accepted = (rectangle.modal === true)
                }

                // 监听暗淡键盘事件
                Keys.onReleased: (event) => {
                    console.debug(`rectangle_overlay:onReleased, event.key = ${event.key}`)
                    event.accepted = (rectangle.model === true)
                }

                // 监听暗淡鼠标事件
                MouseArea {
                    id: mousearea_overlay
                    anchors.fill: parent
                    propagateComposedEvents: true  // 传播暗淡鼠标事件到底层

                    onPressed: (event) => {
                        console.debug(`mousearea_overlay:onPressed`)
                        if(rectangle.strategy === rectangle.enum_closeOutsideEscape) {
                            rectangle_overlay.close()
                        }
                        event.accepted = (rectangle.modal === true)
                    }

                    onReleased: (event) => {
                        console.debug(`mousearea_overlay:onReleased`)
                        event.accepted = (rectangle.modal === true)
                    }
                }

                function open() {
                    console.debug(`rectangle_overlay:function open() {`)
                    rectangle.visible = true
                    rectangle_overlay.focus = true   // 根组件获取焦点
                    rectangle.opened()               // 发射打开信号
                }

                function close() {
                    console.debug(`rectangle_overlay:function close() {`)
                    rectangle.visible = false
                    rectangle_overlay.focus = true   // 根组件抢夺焦点
                    rectangle_overlay.focus = false  // 根组件丢弃焦点
                    rectangle.closed()               // 发射关闭信号
                }

                function toggle(on_off) {
                    console.debug(`rectangle_overlay:function toggle(on_off) {`)
                    if(on_off === true) {
                        open()
                    } else {
                        close()
                    }
                }

                ////////////////////////////////////////////////////////////////////

                // 拦截背景鼠标事件
                MouseArea {
                    anchors.fill: rectangle_background
                }

                // 拖拽区域
                Rectangle {
                    id: rectangle_drag
                    anchors.left  : rectangle_popup.left
                    anchors.right : rectangle_popup.right
                    anchors.top   : rectangle_popup.top
                    anchors.bottom: rectangle_popup.top
                    anchors.bottomMargin: {
                        if(rectangle.dragDistance <= rectangle_popup.height) {
                            return -rectangle.dragDistance
                        } else {
                            return -rectangle_popup.height
                        }
                    }
                    color: "#00FFFFFF"
                    clip: false

                    MouseArea {
                        property var mouse_pressed: ({})
                        id: mousearea_drag
                        enabled: rectangle.draggable
                        anchors.fill: parent

                        onPressed: {
                            console.debug(`rectangle_drag:onPressed`)
                            var mouse_global = app.pos()
                            mouse_pressed.x_snap = rectangle.x
                            mouse_pressed.y_snap = rectangle.y
                            mouse_pressed.x = mouse_global.x
                            mouse_pressed.y = mouse_global.y
                        }

                        onPositionChanged: {
                            // console.debug(`rectangle_drag:onPositionChanged`)
                            var mouse_global = app.pos()
                            rectangle.x = mouse_pressed.x_snap + (mouse_global.x - mouse_pressed.x)
                            rectangle.y = mouse_pressed.y_snap + (mouse_global.y - mouse_pressed.y)
                        }
                    }
                }

                // 背景组件
                Rectangle {
                    id: rectangle_background
                    anchors.fill: rectangle_popup
                    color: "#00FFFFFF"
                    clip: false

                    // 背景组件大小同弹窗组件
                    onChildrenChanged: {
                        console.debug(`rectangle_background:onChildrenChanged`)
                        for(var i = 0; i < children.length; i += 1) {
                            children[i].width = width
                            children[i].height = height
                        }
                    }

                    // 背景组件大小同弹窗组件
                    onWidthChanged: {
                        console.debug(`rectangle_background:onWidthChanged`)
                        for(var i = 0; i < children.length; i += 1) {
                            children[i].width = width
                        }
                    }

                    // 背景组件大小同弹窗组件
                    onHeightChanged: {
                        console.debug(`rectangle_background:onHeightChanged`)
                        for(var i = 0; i < children.length; i += 1) {
                            children[i].height = height
                        }
                    }
                }

                // 弹窗组件
                Rectangle {
                    property var mapping_area: {
                        console.debug(`rectangle_popup, mapping_area, rectangle_overlay.parent = ${rectangle_overlay.parent}`)
                        rectangle_overlay.parent
                        rectangle.x
                        rectangle.y
                        rectangle_overlay.x
                        rectangle_overlay.y
                        return rectangle.mapToItem(rectangle_overlay, 0, 0)
                    }
                    id: rectangle_popup
                    width: rectangle.width
                    height: rectangle.height
                    x: mapping_area.x
                    y: mapping_area.y
                    color: "#00FFFFFF"
                    clip: false

                    ////////////////////////////////////////////////////////////////

                    // 填充子组件
                }
            }
        }
    }
}
