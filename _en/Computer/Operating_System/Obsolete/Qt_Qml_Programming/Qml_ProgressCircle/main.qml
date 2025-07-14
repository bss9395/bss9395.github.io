import QtQuick 2.14
import QtQuick.Window 2.14

Item {
    property real lineWidth: 5
    property string fontSize: "20px DejaVu Sans Mono"
    property color color: "steelblue"
    property real value: 0.6

    width: 100
    height: 100

    Canvas {
        id: canvas
        width: Math.min(parent.width, parent.height)
        height: width

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
    }

    onValueChanged: {
        canvas.requestPaint()
    }
}
