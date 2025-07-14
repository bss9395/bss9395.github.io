import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.12

Shape {
    property var    radiusCorner : [0.0, 0.0, 0.0, 0.0]
    property real   borderWidth  : 1.0
    property color  borderColor  : "#00FFFFFF"
    property string borderStyle  : "SolidLine"
    property var    borderPattern: [1.0, 3.0]
    property color  color        : "#00FFFFFF"
    id: shape
    antialiasing: true
    smooth: true
    layer.enabled: true
    layer.samples: 24
    layer.smooth: true

    ShapePath {
        strokeWidth: shape.borderWidth <= 0.0 ? -1 : shape.borderWidth  // strokeWidth为负数时不绘制
        strokeColor: shape.borderColor
        strokeStyle: {
            if(shape.borderStyle === "SolidLine") {
                return ShapePath.SolidLine
            } else if(shape.borderStyle === "DashLine") {
                return ShapePath.DashLine
            }
            return ShapePath.SolidLine
        }
        dashPattern: shape.borderPattern
        fillColor: shape.color

        // 第零个点
        startX: shape.radiusCorner[0]
        startY: 0                                   + shape.borderWidth / 2

        // 正上直线
        PathLine {
            x: shape.width - radiusCorner[1]
            y: 0                                    + shape.borderWidth / 2
        }

        // 右上圆弧
        PathArc {
            x: shape.width                          - shape.borderWidth / 2
            y: shape.radiusCorner[1]
            radiusX: shape.radiusCorner[1]          - shape.borderWidth / 2
            radiusY: shape.radiusCorner[1]          - shape.borderWidth / 2
        }

        // 正右直线
        PathLine {
            x: shape.width                          - shape.borderWidth / 2
            y: shape.height - shape.radiusCorner[2]
        }

        // 右下圆弧
        PathArc {
            x: shape.width - shape.radiusCorner[2]
            y: shape.height                         - shape.borderWidth / 2
            radiusX: shape.radiusCorner[2]          - shape.borderWidth / 2
            radiusY: shape.radiusCorner[2]          - shape.borderWidth / 2
        }

        // 正下直线
        PathLine {
            x: shape.radiusCorner[3]
            y: shape.height                         - shape.borderWidth / 2
        }

        // 左下圆弧
        PathArc {
            x: 0                                    + shape.borderWidth / 2
            y: shape.height - shape.radiusCorner[3]
            radiusX: shape.radiusCorner[3]          - shape.borderWidth / 2
            radiusY: shape.radiusCorner[3]          - shape.borderWidth / 2
        }

        // 正左直线
        PathLine {
            x: 0                                    + shape.borderWidth / 2
            y: shape.radiusCorner[0]
        }

        // 左上圆弧
        PathArc {
            x: shape.radiusCorner[0]
            y: 0                                    + shape.borderWidth / 2
            radiusX: shape.radiusCorner[0]          - shape.borderWidth / 2
            radiusY: shape.radiusCorner[0]          - shape.borderWidth / 2
        }
    }
}
