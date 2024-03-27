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
            { "value": Qt.ArrowCursor       , "name": "ArrowCursor       " },
            { "value": Qt.UpArrowCursor     , "name": "UpArrowCursor     " },
            { "value": Qt.CrossCursor       , "name": "CrossCursor       " },
            { "value": Qt.WaitCursor        , "name": "WaitCursor        " },
            { "value": Qt.IBeamCursor       , "name": "IBeamCursor       " },
            { "value": Qt.SizeVerCursor     , "name": "SizeVerCursor     " },
            { "value": Qt.SizeHorCursor     , "name": "SizeHorCursor     " },
            { "value": Qt.SizeBDiagCursor   , "name": "SizeBDiagCursor   " },
            { "value": Qt.SizeFDiagCursor   , "name": "SizeFDiagCursor   " },
            { "value": Qt.SizeAllCursor     , "name": "SizeAllCursor     " },
            { "value": Qt.BlankCursor       , "name": "BlankCursor       " },
            { "value": Qt.SplitVCursor      , "name": "SplitVCursor      " },
            { "value": Qt.SplitHCursor      , "name": "SplitHCursor      " },
            { "value": Qt.PointingHandCursor, "name": "PointingHandCursor" },
            { "value": Qt.ForbiddenCursor   , "name": "ForbiddenCursor   " },
            { "value": Qt.WhatsThisCursor   , "name": "WhatsThisCursor   " },
            { "value": Qt.BusyCursor        , "name": "BusyCursor        " },
            { "value": Qt.OpenHandCursor    , "name": "OpenHandCursor    " },
            { "value": Qt.ClosedHandCursor  , "name": "ClosedHandCursor  " },
            { "value": Qt.DragCopyCursor    , "name": "DragCopyCursor    " },
            { "value": Qt.DragMoveCursor    , "name": "DragMoveCursor    " },
            { "value": Qt.DragLinkCursor    , "name": "DragLinkCursor    " }
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
        columns: 10

        Repeater {
            model: grid.list_cursorShape

            Label {
                width: 60
                height: 60
                background: Rectangle {
                    color: grid.list_color[model.index % grid.list_color.length]
                }
                padding: 2
                text: grid.list_cursorShape[model.index]["name"]
                wrapMode: Text.WrapAnywhere

                MouseArea {
                    anchors.fill: parent
                    cursorShape: grid.list_cursorShape[model.index]["value"]
                }
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////

    Rectangle {
        id: rectangle_drawer
        width: 100
        height: 100
        x: 200
        y: 200
        color: "green"
        clip: false

        PropertyAnimation {
            id: propertyanimation
            target  : rectangle_drawer
            property: "x"
            running : false
            loops   : 1
            duration: 500
            from    : rectangle_drawer.x
            to      : 0
        }

        Rectangle {
            id: rectangle_drag
            width : 10
            height: 10
            anchors.left  : rectangle_drawer.left
            anchors.right : undefined
            anchors.top   : rectangle_drawer.top
            anchors.bottom: rectangle_drawer.bottom
            anchors.leftMargin: rectangle_drawer.width - width / 2
            color: "#60FFFF00"

            MouseArea {
                property var hovering     : false
                property var hoveringLast : false
                property var mouse_pressed: ({})
                anchors.fill: parent
                hoverEnabled: true

                onHoveringChanged: {
                    if(hovering === hoveringLast) {
                        return
                    }

                    console.debug(`rectangle_drag:onHoveringChanged, hovering = ${hovering}`)
                    if(hovering === true) {
                        config.overrideCursorShape(Qt.SizeHorCursor)
                    } else {
                        config.restoreCursorShape()
                    }
                    hoveringLast = hovering
                }

                onPressed: {
                    console.debug(`rectangle_drag:onPressed`)
                    hovering = true
                    var mouse_global = config.cursorPos()
                    mouse_pressed.drawer_x = rectangle_drawer.x
                    mouse_pressed.drawer_y = rectangle_drawer.y
                    mouse_pressed.x = mouse_global.x
                    mouse_pressed.y = mouse_global.y
                }

                onPositionChanged: {
                    // console.debug(`rectangle_drag:onPositionChanged`)
                    hovering = true
                    if(pressed === true) {
                        var mouse_global = config.cursorPos()
                        var mouse_drift_x = mouse_global.x - mouse_pressed.x
                        var mouse_drift_y = mouse_global.y - mouse_pressed.y
                        rectangle_drawer.x = mouse_pressed.drawer_x + mouse_drift_x
                    }
                }

                onExited: {
                    console.debug(`rectangle_drag:onExited`)
                    if(pressed === false) {
                        hovering = false
                    }
                }

                onReleased: {
                    console.debug(`rectangle_drag:onReleased`)
                    if(containsMouse === false) {
                        hovering = false
                    }
                    propertyanimation.running = true
                }
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////

    RectangleResize {
        anchors.fill: rectangle_content
    }

    Rectangle {
        id: rectangle_content
        width : 100
        height: 100
        x: 200
        y: 350
        color: "green"
        clip: true

    }
}
