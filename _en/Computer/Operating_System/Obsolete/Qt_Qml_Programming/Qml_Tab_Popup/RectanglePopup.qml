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
    property var background: undefined
    property var strategy  : enum_closeOutsideEscape
    property var modal     : true
    property var dim       : true
    property var draggable : true
    id: rectangle
    enabled: true
    visible: true
    width: parent.width / 4
    height: parent.height / 2
    x: (parent.width - width) / 2
    y: (parent.height - height) / 2
    color: "#00FFFFFF"
    clip: false

    onDefaultDataChanged: {
        loader.func_defaultData(defaultData)
    }

    onBackgroundChanged: {
        loader.func_background(background)
    }

    function open() {
        console.debug(`rectangle:function open() {`)
        if(loader.status === Loader.Ready) {
            loader.item.open()
        }
    }

    function close() {
        console.debug(`rectangle:function close() {`)
        if(loader.status === Loader.Ready) {
            loader.item.close()
        }
    }

    function toggle(on_off) {
        console.debug(`rectangle:function toggle(on_off) {`)
        if(loader.status === Loader.Ready) {
            loader.item.toggle(on_off)
        }
    }

    Loader {
        property var defaultData: ([])
        property var background : undefined
        id: loader
        sourceComponent: Rectangle {
            property alias aliasData      : rectangle_popup.data
            property alias aliasBackground: rectangle_background.data
            id: rectangle_overlay
            parent: Overlay.overlay
            enabled: rectangle.enabled
            visible: rectangle.visible
            anchors.fill: parent  // 背景暗淡覆盖整个软件页面
            color: (rectangle.dim === true) ? "#20000000": "#00000000"
            clip: false
            // qml的焦点机制不明

            // 监听背景键盘事件
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

            // 监听背景键盘事件
            Keys.onReleased: (event) => {
                console.debug(`rectangle_overlay:onReleased, event.key = ${event.key}`)
                event.accepted = (rectangle.modal === true)
            }

            // 监听背景鼠标事件
            MouseArea {
                id: mousearea_overlay
                anchors.fill: parent
                propagateComposedEvents: true  // 传播鼠标事件到底层

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
                console.debug(`function open() {`)
                rectangle.visible = true
                rectangle_overlay.focus = true   // 根组件获取键盘焦点，qml的焦点机制不明
                rectangle.opened()               // 发射打开信号
            }

            function close() {
                console.debug(`function close() {`)
                rectangle.visible = false
                rectangle_overlay.focus = false  // 根组件放弃键盘焦点，qml的焦点机制不明
                rectangle.closed()               // 发射关闭信号
            }

            function toggle(on_off) {
                console.debug(`function toggle(on_off) {`)
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

            // 拖拽区域
            Rectangle {
                id: rectangle_drag
                enabled: rectangle.draggable
                anchors.left: rectangle_popup.left
                anchors.right: rectangle_popup.right
                anchors.top: rectangle_popup.top
                anchors.bottom: rectangle_popup.top
                anchors.bottomMargin: -Qt.styleHints.startDragDistance * 2
                color: "#00FFFFFF"
                clip: false

                MouseArea {
                    property var mouse_offset: ({})
                    id: mousearea_drag
                    anchors.fill: parent

                    onPressed: {
                        console.debug(`rectangle_drag:onPressed`)
                        var mouse_global = app.pos()
                        mouse_offset.x = mouse_global.x - rectangle.x
                        mouse_offset.y = mouse_global.y - rectangle.y
                    }

                    onPositionChanged: {
                        // console.debug(`rectangle_drag:onPositionChanged`)
                        var mouse_global = app.pos()
                        rectangle.x = mouse_global.x - mouse_offset.x
                        rectangle.y = mouse_global.y - mouse_offset.y
                    }
                }
            }

            // 弹窗组件
            Rectangle {
                id: rectangle_popup
                width: rectangle.width
                height: rectangle.height
                x: {
                    rectangle.x
                    var mapping_overlay = rectangle.mapToItem(parent, 0, 0)
                    return mapping_overlay.x
                }
                y: {
                    rectangle.y
                    var mapping_overlay = rectangle.mapToItem(parent, 0, 0)
                    return mapping_overlay.y
                }
                color: "#00FFFFFF"
                clip: false

                ////////////////////////////////////////////////////////////////

                // 填充子组件
            }
        }

        onActiveChanged: {
            console.debug(`loader:onActiveChanged, loader.active = ${loader.active}`)
        }

        onStatusChanged: {
            console.debug(`loader:onStatusChanged, status = ${status}`)
            if(status === Loader.Ready) {
                // 增添弹窗组件
                for( ; 0 < loader.defaultData.length; ) {
                    var itemData = loader.defaultData.shift()
                    if(itemData) {
                        loader.item.aliasData.push(itemData)
                    }
                }

                // 清空背景组件
                loader.item.aliasBackground = []  // qml的list<>对象没有移除相关的函数

                // 增添背景组件
                if(loader.background) {
                    loader.item.aliasBackground.push(loader.background)
                    loader.background = null  // 重置缓存变量
                }
            }
        }

        Component.onDestruction: {
            console.debug(`loader:onDestruction, loader.active = ${loader.active}`)
            loader.active = false  // 销毁动态加载的组件
        }

        function func_defaultData(defaultData) {
            console.debug(`loader:function func_defaultData(defaultData) {`)
            if(status === Loader.Ready) {
                if(defaultData) {
                    loader.item.aliasData.push(defaultData)
                }
            } else {
                loader.defaultData.push(defaultData)
            }
        }

        function func_background(background) {
            console.debug(`loader:function func_background(background) {`)
            if(status === Loader.Ready) {
                // 清空背景组件
                loader.item.aliasBackground = []  // qml的list<>对象没有移除相关的函数
                if(background) {
                    loader.item.aliasBackground.push(background)
                }
            } else {
                loader.background = background
            }
        }
    }
}
