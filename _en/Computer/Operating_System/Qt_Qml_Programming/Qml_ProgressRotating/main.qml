import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12

Control {
    property real lineWidth: 5
    property string fontSize: "20px DejaVu Sans Mono"
    property color color: "steelblue"
    property real value: 0.8
    visible: true
    width: 640
    height: 480

    Canvas {
        id: canvas
        width: 100
        height: 100

        onPaint: {
            var r = width / 2
            var angle = value * 360
            var ctx = getContext("2d")

            // 绘制背景圆
            ctx.strokeStyle = "#eee"
            ctx.lineWidth = lineWidth
            ctx.beginPath()
            ctx.arc(r, r, r - lineWidth / 2, -Math.PI / 2, -Math.PI / 2 + 2 * Math.PI, false)
            ctx.stroke()

            // 绘制进度圆弧
            ctx.strokeStyle = color
            ctx.lineWidth = lineWidth
            ctx.beginPath()
            ctx.arc(r, r, r - lineWidth / 2, -Math.PI / 2, -Math.PI / 2 + angle / 180 * Math.PI, false)
            ctx.stroke()

            // 绘制当前值文本
            ctx.fillStyle = color
            ctx.font = fontSize
            ctx.textAlign = "center"
            ctx.textBaseline = "middle"
            ctx.fillText(Math.round(value * 100 ) + "%", r, r)
        }

        PropertyAnimation {
            id: property_rotation
            target: canvas
            properties: "rotation"
            from: 0
            to: 360
            duration: 3000
            loops: Animation.Infinite
            running: true
       }
    }
}
