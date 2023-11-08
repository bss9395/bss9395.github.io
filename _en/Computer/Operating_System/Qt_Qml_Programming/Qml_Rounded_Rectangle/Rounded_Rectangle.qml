import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.12

Shape {
    property var radius: 0
    property color color: "#FFFFFFFF"
    property color borderColor: "#00FFFFFF"
    property real borderWidth: 1
    id: shape
    layer.enabled: true
    layer.samples: 4
    layer.smooth: true

    ShapePath {
        fillColor: color
        strokeColor: borderColor
        strokeWidth: borderWidth

        // 起始点
        startX: 0
        startY: radius[0]

        // 第一个点
        PathQuad {
            x: radius[0]
            y: 0
            controlX: 0
            controlY: 0
        }

        // 第二个点
        PathLine {
            x: shape.width - radius[1]
            y: 0
        }

        // 第三个点
        PathQuad {
            x: shape.width
            y: radius[1]
            controlX: shape.width
            controlY: 0
        }

        // 第四个点
        PathLine {
            x: shape.width
            y: shape.height - radius[2]
        }

        // 第五个点
        PathQuad {
            x: shape.width - radius[2]
            y: shape.height
            controlX: shape.width
            controlY: shape.height
        }

        // 第六个点
        PathLine {
            x: radius[3]
            y: shape.height
        }

        // 第七个点
        PathQuad {
            x: 0
            y: shape.height - radius[3]
            controlX: 0
            controlY: shape.height
        }

        // 第八个点
        PathLine {
            x: 0
            y: radius[0]
        }
    }
}
