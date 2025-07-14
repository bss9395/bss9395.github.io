import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: 100
        height: 100
        color: "#00FFFFFF"

        Canvas {
            property var bytesTotal: 100.0
            property var bytesReceived: 20.0
            property var name: "canvas_progress"
            id: canvas_progress
            anchors.fill: parent

            onPaint: {
                console.debug(`canvas_progress:onPaint`)
                var r = width / 2
                var lineWidth = 5
                var progress = (bytesTotal <= 0) ? 0.0 : (bytesReceived / bytesTotal)
                var angle = progress * 360
                var context = getContext("2d")
                func_canvas(context)

                // 重置画布
                context.clearRect(0, 0, canvas_progress.width, canvas_progress.height)

                // 绘制背景圆环
                context.strokeStyle = "#E6E6E6"
                context.lineWidth = lineWidth
                context.beginPath()
                context.arc(r, r, r - lineWidth / 2, -Math.PI / 2, -Math.PI / 2 + 2 * Math.PI, false)
                context.stroke()

                // 绘制进度圆弧
                context.strokeStyle = "#4399F3"
                context.lineWidth = lineWidth
                context.beginPath()
                context.arc(r, r, r - lineWidth / 2, -Math.PI / 2, -Math.PI / 2 + angle / 180 * Math.PI, false)
                context.stroke()
            }

            Component.onCompleted: {
                console.debug(`canvas_progress:onCompleted`)
                console.debug("
source-atop     : A atop B
source-in       : A in   B
source-out      : A out  B
source-over     : A over B
destination-atop: B atop A
destination-in  : B in   A
destination-out : B out  A
destination-over: B over A
lighter         : A plus B
copy            : A
xor             : A xor  B
")
            }

            function func_Canvas() {
                console.debug(`=================================================`)
                console.debug(`function func_info() {`)
                console.debug(`available      = ${available}`)
                console.debug(`canvasSize     = ${canvasSize}`)
                console.debug(`context        = ${context}`)
                console.debug(`contextType    = ${contextType}`)
                console.debug(`renderStrategy = ${renderStrategy}, Canvas.Immediate = ${Canvas.Immediate}, Canvas.Threaded = ${Canvas.Threaded}, Canvas.Cooperative = ${Canvas.Cooperative}`)
                console.debug(`renderTarget   = ${renderTarget}, Canvas.Image = ${Canvas.Image}, Canvas.FramebufferObject = ${Canvas.FramebufferObject}`)
            }

            function func_canvas(context) {
                func_Canvas()
                console.debug(`=================================================`)
                console.debug(`function func_canvas() {`)
                console.debug(`canvas                   = ${context.canvas}, context.canvas.name = ${context.canvas.name}`)
                console.debug(`fillRule                 = ${context.fillRule}, Qt.OddEvenFill = ${Qt.OddEvenFill}, Qt.WindingFill = ${Qt.WindingFill}`)
                console.debug(`fillStyle                = ${context.fillStyle}`)
                console.debug(`font                     = ${context.font}`)
                console.debug(`globalAlpha              = ${context.globalAlpha}`)
                console.debug(`globalCompositeOperation = ${context.globalCompositeOperation}, [source-atop, source-in, source-out, source-over, destination-atop, destination-in, destination-out, destination-over, lighter, copy, xor]`)
                console.debug(`lineCap                  = ${context.lineCap}, [butt, round, square]`)
                console.debug(`lineDashOffset           = ${context.lineDashOffset}`)
                console.debug(`lineJoin                 = ${context.lineJoin}, [bevel, round, miter]`)
                console.debug(`lineWidth                = ${context.lineWidth}`)
                console.debug(`miterLimit               = ${context.miterLimit}`)
                console.debug(`shadowBlur               = ${context.shadowBlur}`)
                console.debug(`shadowColor              = ${context.shadowColor}`)
                console.debug(`shadowOffsetX            = ${context.shadowOffsetX}`)
                console.debug(`shadowOffsetY            = ${context.shadowOffsetY}`)
                console.debug(`strokeStyle              = ${context.strokeStyle}`)
                console.debug(`textAlign                = ${context.textAlign}, [start, end, left, right, center]`)
                console.debug(`textBaseline             = ${context.textBaseline}, [top, hanging, middle, alphabetic, ideographic, bottom]`)
            }

            Label {
                property var list_bytesReceived : [
                    50.0,
                    25.0,
                    75.0
                ]
                property var index_bytesReceived: 0
                id: label_button
                anchors.centerIn: parent
                text: "button"

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        canvas_progress.bytesReceived = label_button.list_bytesReceived[label_button.index_bytesReceived % label_button.list_bytesReceived.length]
                        canvas_progress.requestPaint()
                        label_button.index_bytesReceived += 1
                    }
                }
            }
        }
    }
}
