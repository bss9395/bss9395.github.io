import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.12
import QtGraphicalEffects 1.0


// 工具提示，放置在父容器中
RectanglePopup {
    property var enum_left_top    : "enum_left_top"
    property var enum_right_top   : "enum_right_top"
    property var enum_left_bottom : "enum_left_bottom"
    property var enum_right_bottom: "enum_right_bottom"

    ////////////////////////////////////////////////////////////////////////////

    property alias widthLabel : label_tooltip.width
    property alias heightLabel: label_tooltip.height
    property var widthLabelMaxi: Overlay.overlay.width
    property var radiusLabel: 10
    property var orientation: enum_right_top
    property var heightPeak : 10
    property var offsetPeak : parent.width / 2
    property var offsetInner: 0
    property var tooltip: ""
    id: rectanglepopup
    width : rectangle_content.width
    height: rectangle_content.height
    strategy: enum_closeManual
    modal: false
    dim: false
    draggable: false

    // 主体内容
    Rectangle {
        id: rectangle_content
        width : label_tooltip.width
        height: label_tooltip.height + rectanglepopup.heightPeak
        layer.enabled: true
        layer.effect: DropShadow {
            horizontalOffset: 0
            verticalOffset  : 0
            samples: 24
            radius: 8
            color: "#60000000"
        }
        color: "#00FFFFFF"

        // 小三角形
        Shape {
            property var offsetPeak: {
                var offsetPeakMini = 0 + label_tooltip.radius + rectanglepopup.heightPeak
                if((offsetPeakMini <= rectanglepopup.offsetPeak) === false) {
                    return offsetPeakMini
                }
                var offsetPeakMaxi = rectangle_content.width - rectanglepopup.heightPeak - label_tooltip.radius
                if((rectanglepopup.offsetPeak <= offsetPeakMaxi) === false) {
                    return offsetPeakMaxi
                }
                return rectanglepopup.offsetPeak
            }
            property var offsetInner: {
                // x + sqrt(a * a + x * x) = b
                // a * a + x * x = (b - x) * (b - x) = b * b - 2 * b * x + x * x
                // 2 * b * x = b * b - a * a
                // x = (b * b - a * a) / (2 * b)
                var b = rectangle_content.width - offsetPeak - label_tooltip.radius
                var offsetInnerMini = (b * b - rectanglepopup.heightPeak * rectanglepopup.heightPeak) / (2 * b)
                if((-offsetInnerMini <= rectanglepopup.offsetInner) === false) {
                    return -offsetInnerMini
                }


                // sqrt(c * c + x * x) + x = d
                // c * c + x * x = (d - x) * (d - x) = d * d - 2 * d * x + x * x
                // 2 * d * x = d * d - c * c
                // x = (d * d - c * c) / (2 * d)
                var d = rectanglepopup.offsetPeak - label_tooltip.radius
                var offsetInnerMaxi = (d * d - rectanglepopup.heightPeak * rectanglepopup.heightPeak) / (2 * d)
                if((rectanglepopup.offsetInner <= offsetInnerMaxi) === false) {
                    return offsetInnerMaxi
                }
                return rectanglepopup.offsetInner
            }
            property var offsetCenter: offsetPeak - offsetInner
            id: shape_triangle
            width: Math.sqrt(rectanglepopup.heightPeak * rectanglepopup.heightPeak + offsetInner * offsetInner) * 2
            height: rectanglepopup.heightPeak
            anchors.horizontalCenter      : (orientation === enum_left_top || orientation === enum_left_bottom) ? parent.left   : (orientation === enum_right_top || orientation === enum_right_bottom) ? parent.right  : undefined
            anchors.horizontalCenterOffset: (orientation === enum_left_top || orientation === enum_left_bottom) ? +offsetCenter : (orientation === enum_right_top || orientation === enum_right_bottom) ? -offsetCenter : undefined
            anchors.top   : (orientation === enum_left_bottom || orientation === enum_right_bottom) ? label_tooltip.bottom : undefined
            anchors.bottom: (orientation === enum_left_top    || orientation === enum_right_top   ) ? label_tooltip.top    : undefined
            transform: [
                Rotation {
                    axis.x: 0.0
                    axis.y: 1.0
                    axis.z: 0.0
                    origin.x: shape_triangle.width  / 2
                    origin.y: shape_triangle.height / 2
                    angle: (orientation === enum_left_top || orientation === enum_left_bottom) ? 0.0 : (orientation === enum_right_top || orientation === enum_right_bottom) ? 180.0 : 0.0
                }, Rotation {
                    axis.x: 1.0
                    axis.y: 0.0
                    axis.z: 0.0
                    origin.x: shape_triangle.width  / 2
                    origin.y: shape_triangle.height / 2
                    angle: (orientation === enum_left_top || orientation === enum_right_top) ? 0.0 : (orientation === enum_left_bottom || orientation === enum_right_bottom) ? 180.0 : 0.0
                }
            ]
            antialiasing : true
            smooth       : true
            layer.enabled: true
            layer.samples: 24
            layer.smooth : true

            ShapePath {
                id: shapepath
                capStyle : ShapePath.RoundCap
                joinStyle: ShapePath.RoundJoin
                strokeWidth: -1
                strokeStyle: ShapePath.SolidLine
                strokeColor: "#FF000000"
                dashPattern: [1, 4]
                fillColor: "#FFFFFFFF"
                fillRule: ShapePath.WindingFill

                // 第零个点
                startX: 0.0
                startY: shape_triangle.height

                // 第一个点
                PathLine {
                    x: shape_triangle.width
                    y: shape_triangle.height
                }

                // 第二个点
                PathLine {
                    x: shape_triangle.width / 2 + rectanglepopup.offsetInner
                    y: 0.0
                }

                // 第零个点
                PathLine {
                    x: shapepath.startX
                    y: shapepath.startY
                }
            }
        }

        // 提示文字
        Label {
            property var radius: {
                var radiusLabelMaxi = width / 2
                if((rectanglepopup.radiusLabel <= radiusLabelMaxi) === false) {
                    return radiusLabelMaxi
                }
                return rectanglepopup.radiusLabel
            }
            id: label_tooltip
            width : 0
            height: 0
            anchors.left  : (orientation === enum_left_top    || orientation === enum_left_bottom ) ? parent.left   : undefined
            anchors.right : (orientation === enum_right_top   || orientation === enum_right_bottom) ? parent.right  : undefined
            anchors.top   : (orientation === enum_left_bottom || orientation === enum_right_bottom) ? parent.top    : undefined
            anchors.bottom: (orientation === enum_left_top    || orientation === enum_right_top   ) ? parent.bottom : undefined
            background: Rectangle {
                radius: label_tooltip.radius
                color: "#FFFFFFFF"
            }
            leftPadding: fontmetrics.height / 3 * 2
            rightPadding: fontmetrics.height / 3 * 2
            topPadding: fontmetrics.height / 3 * 2
            bottomPadding: fontmetrics.height / 3 * 2
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignTop
            font.pixelSize: 12
            font.weight: Font.Normal
            wrapMode: Text.WrapAnywhere
            lineHeightMode: Text.ProportionalHeight
            lineHeight: 1.2
            color: "#FF333333"
            text: rectanglepopup.tooltip

            Component.onCompleted: {
                console.debug(`label_tooltip.width = ${label_tooltip.width}, label_tooltip.height = ${label_tooltip.height}`)
                var initedWidth  = (0 < width)
                var initedHeight = (0 < height)

                if(initedWidth === false) {
                    label_tooltip.textChanged.connect(function () {
                        width = rectanglepopup.widthLabelMaxi
                        var widthSnap = width
                        if((implicitWidth < widthSnap) === true) {
                            widthSnap = implicitWidth
                        }
                        var widthLabelMini = rectanglepopup.radiusLabel + rectanglepopup.height * 2 + rectanglepopup.radiusLabel
                        if((widthLabelMini <= widthSnap) === false) {
                            widthSnap = widthLabelMini
                        }
                        width = widthSnap
                    })
                    label_tooltip.textChanged(label_tooltip.text)
                }
                if(initedHeight === false) {
                    label_tooltip.height = Qt.binding(function () {
                        return label_tooltip.implicitHeight - (label_tooltip.contentHeight / label_tooltip.lineCount - fontmetrics.height)
                    })
                }
            }

            FontMetrics {
                id: fontmetrics
                font: label_tooltip.font
            }
        }
    }
}
