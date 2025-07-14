import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    property alias from : rectangle_inner.from
    property alias into : rectangle_inner.into
    property alias step : rectangle_inner.step
    property alias value: rectangle_inner.value
    property alias snap : rectangle_inner.snap
    property alias angle: rectangle_inner.angle
    id: rectangle
    width: {
        Math.abs(rectangle_inner.width * Math.cos(angle * Math.PI / 180.0)) + Math.abs(rectangle_inner.height * Math.sin(angle * Math.PI / 180.0))
    }
    height: {
        Math.abs(rectangle_inner.width * Math.sin(angle * Math.PI / 180.0)) + Math.abs(rectangle_inner.height * Math.cos(angle * Math.PI / 180.0))
    }
    color: "#00FFFFFF"
    clip: true

    RectangleFit {
        property var from : 0.0
        property var into : 1.0
        property var step : 0.0
        property var value: 0.0
        property var snap : 0.0
        property var angle: 0.0
        property var inited: false
        property var shield: false
        id: rectangle_inner
        width: rectangle_handle.width / 2 + rectangle_shadow.width + rectangle_handle.width / 2
        height: 0
        anchors.centerIn: rectangle
        transform: [
            Rotation {
                origin.x: rectangle_inner.width / 2
                origin.y: rectangle_inner.height / 2
                angle: rectangle_inner.angle
            }
        ]
        color: "#00FFFFFF"
        clip: true

        onValueChanged: {
            if(inited === false) {
                return
            }
            if(shield === true) {
                return
            }
            if((from <= into) === false) {
                return
            }

            console.debug(`rectangle_inner:onValueChanged, value = ${value}`)
            shield = true
            var snap_value = value
            if((from <= snap_value) === false) {
                snap_value = from
            }
            if((snap_value <= into) === false) {
                snap_value = into
            }

            if(0.0 < step) {
                var snap_index = (snap_value - from) / step
                snap_index = Math.round(snap_index)
                snap_value = from + step * snap_index
                if((from <= snap_value) === false) {
                    snap_value = from
                }
                if((snap_value <= into) === false) {
                    snap_value = into
                }
            }

            value = snap_value
            snap = (value - from) / (into - from)
            shield = false
        }

        onSnapChanged: {  // 注意Qt.binding()加载存在延迟，注意qml的回环检测策略
            if(inited === false) {
                return
            }
            if(shield === true) {
                return
            }

            console.debug(`rectangle_inner:onSnapChanged`)
            value = from + (into - from) * snap
        }

        onFromChanged: {
            if(inited === false) {
                return
            }

            console.debug(`rectangle_inner:onFromChanged`)
            value = from + (into - from) * snap
        }

        onIntoChanged: {
            if(inited === false) {
                return
            }

            console.debug(`rectangle_inner:onIntoChanged`)
            value = from + (into - from) * snap
        }

        onStepChanged: {
            if(inited === false) {
                return
            }

            console.debug(`rectangle_inner:onStepChanged`)
            value = from + (into - from) * snap
        }

        Component.onCompleted: {
            rectangle_inner.inited = true
            valueChanged(value)
        }

        // 阴影条
        Rectangle {
            id: rectangle_shadow
            width: 200
            height: 8
            anchors.horizontalCenter: rectangle_inner.horizontalCenter
            anchors.verticalCenter: rectangle_inner.verticalCenter
            color: "#20000000"
            clip: true

            // 进度条
            Rectangle {
                id: rectangle_snap
                width: rectangle_inner.snap * rectangle_shadow.width
                height: rectangle_shadow.height
                anchors.left: rectangle_shadow.left
                anchors.verticalCenter: rectangle_shadow.verticalCenter
                color: "#A0000000"
                clip: true
            }
        }

        // 把柄块
        Rectangle {
            id: rectangle_handle
            width: rectangle_shadow.height * 1.5
            height: width
            anchors.horizontalCenter: rectangle_shadow.left
            anchors.horizontalCenterOffset: rectangle_inner.snap * rectangle_shadow.width
            anchors.verticalCenter: rectangle_shadow.verticalCenter
            radius: width / 2
            border.width: 1
            border.color: "#FF000000"
            color: "#00FFFFFF"
            clip: true

            MouseArea {
                property var mouse_pressed: ({})
                anchors.fill: parent

                onPressed: {
                    console.debug(`rectangle_handle:onPressed`)
                    var mouse_global = app.pos()
                    mouse_pressed.center = rectangle_handle.anchors.horizontalCenterOffset
                    mouse_pressed.x = mouse_global.x
                    mouse_pressed.y = mouse_global.y
                }

                onPositionChanged: {
                    console.debug(`rectangle_handle:onPositionChanged`)
                    var mouse_global = app.pos()
                    var mouse_offset = (mouse_global.x - mouse_pressed.x) * Math.cos(rectangle_inner.angle * Math.PI / 180.0) + (mouse_global.y - mouse_pressed.y) * Math.cos((rectangle_inner.angle - 90) * Math.PI / 180.0)
                    var handle_center = mouse_pressed.center + mouse_offset
                    rectangle_inner.value = rectangle_inner.from + (rectangle_inner.into - rectangle_inner.from) * (handle_center / rectangle_shadow.width)
                }
            }
        }
    }
}
