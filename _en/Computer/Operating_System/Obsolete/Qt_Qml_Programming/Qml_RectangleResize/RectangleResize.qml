import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Rectangle {
    property var dragDistance: 10
    id: rectangle
    anchors.fill: parent
    anchors.leftMargin  : -dragDistance / 2
    anchors.rightMargin : -dragDistance / 2
    anchors.topMargin   : -dragDistance / 2
    anchors.bottomMargin: -dragDistance / 2
    color: "#60FFFF00"

    // 缩放区域
    MouseArea {
        property var enum_left    : 0b0001
        property var enum_right   : 0b0010
        property var enum_top     : 0b0100
        property var enum_bottom  : 0b1000
        property var hoveringPane : 0b0000
        property var hoveringLast : 0b0000
        property var mouse_pressed: ({})
        id: mousearea_resize
        anchors.fill: parent
        propagateComposedEvents: true
        hoverEnabled: true  // qml的hover事件机制不明

        onHoveringPaneChanged: {
            if(hoveringPane === hoveringLast) {
                return
            }

            console.debug(`mousearea_handle:onHoveringPaneChanged, hoveringPane = ${hoveringPane}`)
            if(hoveringPane === enum_left       || hoveringPane === enum_right) {
                config.overrideCursorShape(Qt.SizeHorCursor)
            } else if(hoveringPane === enum_top || hoveringPane === enum_bottom) {
                config.overrideCursorShape(Qt.SizeVerCursor)
            } else if(hoveringPane === (enum_left | enum_top)    || hoveringPane === (enum_right | enum_bottom)) {
                config.overrideCursorShape(Qt.SizeFDiagCursor)
            } else if(hoveringPane === (enum_left | enum_bottom) || hoveringPane === (enum_right | enum_top)) {
                config.overrideCursorShape(Qt.SizeBDiagCursor)
            } else {
                config.restoreCursorShape()
            }
            hoveringLast = hoveringPane
        }

        onPressed: (event) => {
            console.debug(`rectangle_resize:onPressed`)
            func_hoveringPane(event)
            var mouse_global = config.cursorPos()
            mouse_pressed.content_x = rectangle_content.x
            mouse_pressed.content_y = rectangle_content.y
            mouse_pressed.content_width  = rectangle_content.width
            mouse_pressed.content_height = rectangle_content.height
            mouse_pressed.x = mouse_global.x
            mouse_pressed.y = mouse_global.y
        }

        onPositionChanged: (event) => {
            // console.debug(`rectangle_resize:onPositionChanged`)
            if(pressed === false) {
                func_hoveringPane(event)
            } else {
                var mouse_global = config.cursorPos()
                var mouse_drift_x = mouse_global.x - mouse_pressed.x
                var mouse_drift_y = mouse_global.y - mouse_pressed.y
                if((hoveringPane & enum_left) === enum_left) {
                    var content_width_left  = mouse_pressed.content_width - mouse_drift_x
                    if((0 <= content_width_left) === false) {
                        content_width_left = 0
                    }
                    rectangle_content.width = content_width_left
                    rectangle_content.x     = mouse_pressed.content_x + mouse_pressed.content_width - content_width_left
                } else if((hoveringPane & enum_right) === enum_right) {
                    var content_width_right = mouse_pressed.content_width + mouse_drift_x
                    if((0 <= content_width_right) === false) {
                        content_width_right = 0
                    }
                    rectangle_content.width = content_width_right
                    rectangle_content.x     = mouse_pressed.content_x
                }
                if((hoveringPane & enum_top) === enum_top) {
                    var content_height_top = mouse_pressed.content_height - mouse_drift_y
                    if((0 <= content_height_top) === false) {
                        content_height_top = 0
                    }
                    rectangle_content.height = content_height_top
                    rectangle_content.y      = mouse_pressed.content_y + mouse_pressed.content_height - content_height_top
                } else if((hoveringPane & enum_bottom) === enum_bottom) {
                    var content_height_bottom = mouse_pressed.content_height + mouse_drift_y
                    if((0 <= content_height_bottom) === false) {
                        content_height_bottom = 0
                    }
                    rectangle_content.height = content_height_bottom
                    rectangle_content.y      = mouse_pressed.content_y
                }
            }
        }

        onExited: {
            console.debug(`rectangle_resize:onExited`)
            if(pressed === false) {
                hoveringPane = 0b0000
            }
        }

        onReleased: {
            console.debug(`rectangle_resize:onReleased`)
            if(containsMouse === false) {
                hoveringPane = 0b0000
            }
        }

        function func_hoveringPane(event) {
            if(mousearea_inner.x <= event.x && event.x <= mousearea_inner.x + mousearea_inner.width && mousearea_inner.y <= event.y && event.y <= mousearea_inner.y + mousearea_inner.height) {
                hoveringPane = 0b0000
            } else {
                var hovering = 0b0000
                if(0 <= event.x && event.x <= mousearea_inner.x) {
                    hovering |= enum_left
                } else if(mousearea_inner.x + mousearea_inner.width  <= event.x && event.x <= mousearea_resize.width) {
                    hovering |= enum_right
                }
                if(0 <= event.y && event.y <= mousearea_inner.y) {
                    hovering |= enum_top
                } else if(mousearea_inner.y + mousearea_inner.height <= event.y && event.y <= mousearea_resize.height) {
                    hovering |= enum_bottom
                }
                hoveringPane = hovering
            }
        }

        // 占位区域，拦截鼠标事件
        MouseArea {
            id: mousearea_inner
            anchors.fill: mousearea_resize
            anchors.leftMargin  : rectangle.dragDistance
            anchors.rightMargin : rectangle.dragDistance
            anchors.topMargin   : rectangle.dragDistance
            anchors.bottomMargin: rectangle.dragDistance
            propagateComposedEvents: true
            hoverEnabled: false  // qml的悬停事件机制不明

        }
    }
}
