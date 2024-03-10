import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Grid {
        property var list_cursorShape: [
            Qt.ArrowCursor,
            Qt.UpArrowCursor,
            Qt.CrossCursor,
            Qt.WaitCursor,
            Qt.IBeamCursor,
            Qt.SizeVerCursor,
            Qt.SizeHorCursor,
            Qt.SizeBDiagCursor,
            Qt.SizeFDiagCursor,
            Qt.SizeAllCursor,
            Qt.BlankCursor,
            Qt.SplitVCursor,
            Qt.SplitHCursor,
            Qt.PointingHandCursor,
            Qt.ForbiddenCursor,
            Qt.WhatsThisCursor,
            Qt.BusyCursor,
            Qt.OpenHandCursor,
            Qt.ClosedHandCursor,
            Qt.DragCopyCursor,
            Qt.DragMoveCursor,
            Qt.DragLinkCursor
        ]
        property var list_color: [
            "#FFFF0000",
            "#FF00FF00",
            "#FF0000FF",
            "#FFFFFF00",
            "#FF00FFFF",
            "#FFFF00FF"
        ]
        id: grid
        columns: 8

        Repeater {
            model: grid.list_cursorShape

            Rectangle {
                width: 40
                height: 40
                color: grid.list_color[model.index % grid.list_color.length]

                MouseArea {
                    anchors.fill: parent
                    cursorShape: grid.list_cursorShape[model.index % grid.list_cursorShape.length]
                }
            }
        }
    }

    Rectangle {
        id: rectangle
        width: 100
        height: 100
        x: 200
        y: 200
        color: "green"

        PropertyAnimation {
            id: propertyanimation
            target: rectangle
            property: "x"
            running: false
            loops: 1
            duration: 500
            to: 0
        }

        Rectangle {
            id: rectangle_drag
            width: 10
            anchors.leftMargin: -width / 2
            anchors.left  : rectangle.right
            anchors.top   : rectangle.top
            anchors.bottom: rectangle.bottom
            color: "#60FFFF00"

            MouseArea {
                property var pressing: false
                property var hovering: false
                property var stating : (pressing || hovering)
                property var statingLast: false
                property var mouse_pressed: ({})
                id: mousearea_drag
                anchors.fill: parent
                hoverEnabled: true

                onStatingChanged: {
                    if(statingLast === stating) {
                        return
                    }

                    console.debug(`mousearea_drag:onStatingChanged, stating = ${stating}`)
                    if(stating === true) {
                        app.overrideCursorShape(Qt.SizeHorCursor)
                    } else {
                        app.restoreCursorShape()
                    }
                    statingLast = stating
                }

                onPressed: {
                    console.debug(`mousearea_drag:onPressed`)
                    pressing = true

                    var mouse_global = app.cursorPos()
                    mouse_pressed.snap_x = rectangle.x
                    mouse_pressed.snap_y = rectangle.y
                    mouse_pressed.x = mouse_global.x
                    mouse_pressed.y = mouse_global.y
                }

                onPositionChanged: {
                    // console.debug(`mousearea_drag:onPositionChanged`)
                    if(containsMouse === true) {
                        hovering = true
                    }

                    if(pressing === true) {
                        var mouse_global = app.cursorPos()
                        rectangle.x = mouse_pressed.snap_x + (mouse_global.x - mouse_pressed.x)
                        // rectangle.y = mouse_pressed.snap_y + (mouse_global.y - mouse_pressed.y)
                    }
                }

                onExited: {
                    console.debug(`mousearea_drag:onExited`)
                    hovering = false
                }

                onReleased: {
                    console.debug(`mousearea_drag:onReleased`)
                    pressing = false
                    propertyanimation.running = true
                }
            }
        }
    }
}
