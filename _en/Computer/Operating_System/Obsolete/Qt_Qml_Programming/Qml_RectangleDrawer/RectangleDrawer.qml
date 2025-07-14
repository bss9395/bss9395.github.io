// 温馨提示：此组件功能受限

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    property var enum_left  : "enum_left"
    property var enum_right : "enum_right"
    property var enum_top   : "enum_top"
    property var enum_bottom: "enum_bottom"
    property var enum_closeOutsideEscape: "enum_closeOutsideEscape"
    property var enum_closeManual       : "enum_closeManual"

    ////////////////////////////////////////////////////////////////////////////

    signal opened()
    signal closed()
    readonly property var   father   : parent
    readonly property alias snap     : rectangle_drawer.snap
    default  property alias dataAlias: rectangle_drawer.data
    property alias background: rectangle_background.data
    property var dock        : enum_left
    property var strategy    : enum_closeOutsideEscape
    property var modal       : true
    property var dim         : true
    property var draggable   : true
    property var dragDistance: 10
    property var delayTime   : {
        // 动画时间与抽屉大小成正比
        if(dock === enum_left || dock === enum_right) {
            return width
        } else if(dock === enum_top || dock === enum_bottom) {
            return height
        }
    }
    id: rectangle
    width : parent.width  / 4
    height: parent.height / 2
    x: (parent.width  - width ) / 2
    y: (parent.height - height) / 2
    color: "#00FFFFFF"
    clip: false  // 不剪裁暗淡区域

    function open() {
        console.debug(`function open() {`)
        if(dock === enum_left || dock === enum_right) {
            propertyanimation_drawer.running  = false
            propertyanimation_drawer.from     = rectangle_drawer.bound
            propertyanimation_drawer.to       = rectangle.width
            propertyanimation_drawer.duration = (rectangle.width  - rectangle_drawer.bound) / rectangle.width * rectangle.delayTime
            propertyanimation_drawer.running  = true
        } else if(dock === enum_top || dock === enum_bottom) {
            propertyanimation_drawer.running  = false
            propertyanimation_drawer.from     = rectangle_drawer.bound
            propertyanimation_drawer.to       = rectangle.height
            propertyanimation_drawer.duration = (rectangle.height - rectangle_drawer.bound) / rectangle.height * rectangle.delayTime
            propertyanimation_drawer.running  = true
        }
    }

    function close() {
        console.debug(`function close() {`)
        if(dock === enum_left || dock === enum_right) {
            propertyanimation_drawer.running  = false
            propertyanimation_drawer.from     = rectangle_drawer.bound
            propertyanimation_drawer.to       = 0
            propertyanimation_drawer.duration = (rectangle_drawer.bound - 0) / rectangle.width * rectangle.delayTime
            propertyanimation_drawer.running  = true
        } else if(dock === enum_top || dock === enum_bottom) {
            propertyanimation_drawer.running  = false
            propertyanimation_drawer.from     = rectangle_drawer.bound
            propertyanimation_drawer.to       = 0
            propertyanimation_drawer.duration = (rectangle_drawer.bound - 0) / rectangle.height * rectangle.delayTime
            propertyanimation_drawer.running  = true
        }
    }

    function toggle(on_off) {
        console.debug(`function toggle(on_off) {`)
        if(on_off === true) {
            open()
        } else {
            close()
        }
    }

    // 暗淡区域，映射到底层组件的父组件
    Rectangle {
        id: rectangle_dim
        width : rectangle.father.width
        height: rectangle.father.height
        x: -rectangle.x
        y: -rectangle.y
        color: {
            if(rectangle.dim === false) {
                return "#00000000"
            }
            return app.colorLinearize("#00000000", "#20000000", rectangle_drawer.snap)  // opacity===0.125
        }
        clip: false

        // 监听暗淡键盘事件
        Keys.onPressed: (event) => {
            console.debug(`rectangle:onPressed, event.key = ${event.key}`)
            if(event.key === Qt.Key_Escape) {
                console.debug(`if(event.key === Qt.Key_Escape) {`)
                if(rectangle.strategy === enum_closeOutsideEscape) {
                    rectangle.close()
                }
            }
            event.accepted = (rectangle.modal === true)
        }

        // 监听暗淡键盘事件
        Keys.onReleased: (event) => {
            console.debug(`rectangle:onReleased, event.key = ${event.key}`)
            event.accepted = (rectangle.modal === true)
        }

        // 监听暗淡鼠标事件
        MouseArea {
            id: mousearea_dim
            anchors.fill: parent
            propagateComposedEvents: true  // 传播暗淡鼠标事件到底层

            onPressed: (event) => {
                console.debug(`mousearea_dim:onPressed`)
                if(rectangle.strategy === enum_closeOutsideEscape) {
                    rectangle.close()
                }
                event.accepted = (rectangle.modal === true)
            }

            onReleased: (event) => {
                console.debug(`mousearea_dim:onReleased`)
                event.accepted = (rectangle.modal === true)
            }
        }

        // 抽屉拖拽动画
        PropertyAnimation {
            id: propertyanimation_drawer
            target: rectangle_drawer
            property: "bound"
            running: false
            loops: 1
            duration: 0
        }

        // 抽屉区域，映射到底层组件的父组件
        Rectangle {
            property var mapping_area: {
                rectangle.x
                rectangle.y
                rectangle_dim.x
                rectangle_dim.y
                return rectangle.mapToItem(rectangle_dim, 0, 0)
            }
            id: rectangle_area
            anchors.left  : rectangle_dim.left
            anchors.right : rectangle_dim.right
            anchors.top   : rectangle_dim.top
            anchors.bottom: rectangle_dim.bottom
            anchors.leftMargin  : (rectangle.dock === enum_left  ) ? mapping_area.x                                           : 0
            anchors.rightMargin : (rectangle.dock === enum_right ) ? rectangle_dim.width - mapping_area.x - rectangle.width   : 0
            anchors.topMargin   : (rectangle.dock === enum_top   ) ? mapping_area.y                                           : 0
            anchors.bottomMargin: (rectangle.dock === enum_bottom) ? rectangle_dim.height - mapping_area.y - rectangle.height : 0
            color: "#00FFFFFF"
            clip: true  // 剪裁抽屉组件

            // 拦截背景鼠标事件
            MouseArea {
                anchors.fill: rectangle_background
            }

            // 拖拽区域
            Rectangle {
                property var sign: (rectangle.dock === enum_right || rectangle.dock === enum_bottom) ? -1 : +1
                id: rectangle_drag
                width : rectangle.dragDistance
                height: rectangle.dragDistance
                anchors.left  : (rectangle.dock === enum_right ) ? undefined : rectangle_drawer.left
                anchors.right : (rectangle.dock === enum_left  ) ? undefined : rectangle_drawer.right
                anchors.top   : (rectangle.dock === enum_bottom) ? undefined : rectangle_drawer.top
                anchors.bottom: (rectangle.dock === enum_top   ) ? undefined : rectangle_drawer.bottom
                anchors.leftMargin  : (rectangle.dock === enum_left  ) ? rectangle_drawer.width  - width  / 2 : 0
                anchors.rightMargin : (rectangle.dock === enum_right ) ? rectangle_drawer.width  - width  / 2 : 0
                anchors.topMargin   : (rectangle.dock === enum_top   ) ? rectangle_drawer.height - height / 2 : 0
                anchors.bottomMargin: (rectangle.dock === enum_bottom) ? rectangle_drawer.height - height / 2 : 0
                color: "#00FFFFFF"
                clip: false

                MouseArea {
                    property var pressing: false
                    property var hovering: false
                    property var stating : (pressing || hovering)
                    property var statingLast: false
                    property var mouse_pressed: ({})
                    id: mousearea_drag
                    enabled: rectangle.draggable
                    anchors.fill: parent
                    hoverEnabled: true  // 监听鼠标悬停事件

                    onStatingChanged: {
                        if(statingLast === stating) {
                            return
                        }

                        console.debug(`mousearea_drag:onStatingChanged, stating = ${stating}`)
                        if(stating === true) {
                            if(rectangle.dock === enum_left || rectangle.dock === enum_right) {
                                app.overrideCursorShape(Qt.SizeHorCursor)
                            } else if(rectangle.dock === enum_top || rectangle.dock === enum_bottom) {
                                app.overrideCursorShape(Qt.SizeVerCursor)
                            }
                        } else {
                            app.restoreCursorShape()
                        }
                        statingLast = stating
                    }

                    onPressed: {
                        console.debug(`rectangle_drag:onPressed`)
                        pressing = true

                        var mouse_global = app.cursorPos()
                        mouse_pressed.bound = rectangle_drawer.bound
                        mouse_pressed.x = mouse_global.x
                        mouse_pressed.y = mouse_global.y
                    }

                    onPositionChanged: {
                        // console.debug(`rectangle_drag:onPositionChanged`)
                        if(containsMouse === true) {
                            hovering = true
                        }

                        if(pressing === true) {
                            var mouse_global = app.cursorPos()
                            if(rectangle.dock === enum_left || rectangle.dock === enum_right) {
                                var drift_width = mouse_pressed.bound + rectangle_drag.sign * (mouse_global.x - mouse_pressed.x)
                                if((0 <= drift_width) === false) {
                                    drift_width = 0
                                }
                                if((drift_width <= rectangle_drawer.width) === false) {
                                    drift_width = rectangle_drawer.width
                                }
                                rectangle_drawer.bound = drift_width
                            } else if(rectangle.dock === enum_top || rectangle.dock === enum_bottom) {
                                var drift_height = mouse_pressed.bound + rectangle_drag.sign * (mouse_global.y - mouse_pressed.y)
                                if((0 <= drift_height) === false) {
                                    drift_height = 0
                                }
                                if((drift_height <= rectangle_drawer.height) === false) {
                                    drift_height = rectangle_drawer.height
                                }
                                rectangle_drawer.bound = drift_height
                            }
                        }
                    }

                    onExited: {
                        console.debug(`mousearea:onExited`)
                        hovering = false
                    }

                    onReleased: {
                        console.debug(`rectangle_drag:onReleased`)
                        pressing = false

                        var mouse_global = app.cursorPos()
                        // 以鼠标滑动方向为开关
                        if(rectangle.dock === enum_left || rectangle.dock === enum_right) {
                            var drift_x = mouse_global.x - mouse_pressed.x
                            if(drift_x !== 0) {
                                rectangle.toggle(0 < rectangle_drag.sign * drift_x)
                            }
                        } else if(rectangle.dock === enum_top || rectangle.dock === enum_bottom) {
                            var drift_y = mouse_global.y - mouse_pressed.y
                            if(drift_y !== 0) {
                                console.debug(`rectangle_drag.sign * drift_y = ${rectangle_drag.sign * drift_y}, sign = ${rectangle_drag.sign}, drift_y = ${drift_y}`)
                                rectangle.toggle(0 < rectangle_drag.sign * drift_y)
                            }
                        }
                    }
                }
            }

            // 抽屉背景，注意停靠边缘会被剪裁
            Rectangle {
                id: rectangle_background
                anchors.fill: rectangle_drawer
                color: "#00FFFFFF"
                clip: false

                onChildrenChanged: {
                    console.debug(`rectangle_background:onChildrenChanged`)
                    for(var i = 0; i < children.length; i += 1) {
                        children[i].width  = width
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
                    for(var i = 0; i < children.height; i += 1) {
                        children[i].height = height
                    }
                }
            }

            // 抽屉组件，映射到影子组件
            Rectangle {
                property real snap : bound / boundFull
                property real bound: 0  // 使用类型real
                property real boundLast: bound
                property real boundFull: {
                    if(rectangle.dock === enum_left || rectangle.dock === enum_right) {
                        return width
                    } else if(rectangle.dock === enum_top || rectangle.dock === enum_bottom) {
                        return height
                    }
                }
                id: rectangle_drawer
                width : rectangle_shadow.width
                height: rectangle_shadow.height
                anchors.left  : (rectangle.dock === enum_right ) ? undefined : rectangle_shadow.left
                anchors.right : (rectangle.dock === enum_left  ) ? undefined : rectangle_shadow.right
                anchors.top   : (rectangle.dock === enum_bottom) ? undefined : rectangle_shadow.top
                anchors.bottom: (rectangle.dock === enum_top   ) ? undefined : rectangle_shadow.bottom
                anchors.leftMargin  : (rectangle.dock === enum_left  ) ? bound : 0
                anchors.rightMargin : (rectangle.dock === enum_right ) ? bound : 0
                anchors.topMargin   : (rectangle.dock === enum_top   ) ? bound : 0
                anchors.bottomMargin: (rectangle.dock === enum_bottom) ? bound : 0
                color: "#00FFFFFF"
                clip: false

                onBoundChanged: {
                    // console.debug(`rectangle_drawer:onBoundChanged, bound = ${bound}`)
                    if(bound <= 0) {                          // 已经关闭状态
                        rectangle_dim.focus   = true          // 抢夺键盘焦点
                        rectangle_dim.focus   = false         // 丢弃键盘焦点
                        mousearea_dim.enabled = false         // 停止鼠标监听
                        rectangle.closed()                    // 发射关闭信号
                    } else if(boundLast <= 0 && 0 < bound) {  // 关闭转成打开
                        rectangle_dim.focus   = true          // 获取键盘焦点
                        mousearea_dim.enabled = true          // 启用鼠标监听
                    } else if(boundFull <= bound) {           // 已经打开状态
                        rectangle.opened()                    // 发射打开信号
                    }
                    boundLast = bound
                }

                ////////////////////////////////////////////////////////////////////////

                // 填充子组件
            }

            // 影子组件，映射到底层组件, 占位抽屉组件的初始位置
            Rectangle {
                property var mapping_area: {
                    rectangle.x
                    rectangle.y
                    rectangle_area.x
                    rectangle_area.y
                    return rectangle.mapToItem(rectangle_area, 0, 0)
                }
                id: rectangle_shadow
                width: rectangle.width
                height: rectangle.height
                x: {
                    if(rectangle.dock === enum_left) {
                        return mapping_area.x - width
                    } else if(rectangle.dock === enum_right) {
                        return mapping_area.x + width
                    }
                    return mapping_area.x
                }
                y: {
                    if(rectangle.dock === enum_top) {
                        return mapping_area.y - height
                    } else if(rectangle.dock === enum_bottom) {
                        return mapping_area.y + height
                    }
                    return mapping_area.y
                }
                color: "#00FFFFFF"
                clip: false
            }
        }
    }
}
