import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.12


// Qml绘图方式   : Shape, QQuickPaintedItem, 2D Canvas
// Shape支持的子集: PathArc, PathCubic, PathLine, PathMove, PathQuad, PathSvgPathText,
// Path支持的子集 : PathAngleArc, PathArc, PathAttribute,PathCubic, PathCurve, PathLine, PathMove, PathMultiLine, PathPercent, PathPolyline, PathQuad, PathSvg
// PathLine     : a straight line to a given position.
// PathPolyline : a polyline specified as a list of coordinates.
// PathMultiline: a list of polylines specified as a list of lists of coordinates.
// PathQuad     : a quadratic Bezier curve to a given position with a control point.
// PathCubic    : a cubic Bezier curve to a given position with two control points.
// PathArc      : an arc to a given position with a radius.
// PathAngleArc : an arc specified by center point, radii, and angles.
// PathSvg      : a path specified as an SVG path data string.
// PathCurve    : a point on a Catmull-Rom curve.
// PathAttribute: an attribute at a given position in the path.
// PathPercent  : a way to spread out items along various segments of the path.
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Timer {
        id: timer
        running: true
        repeat: true
        interval: 1000

        onTriggered: {
            var mouse_global = app.pos()
            var mouse_shape = shape.mapFromGlobal(mouse_global.x, mouse_global.y)
            console.debug(`shape.contains(mouse_shape) = ${shape.contains(mouse_shape)}, mouse_shape.x = ${mouse_shape.x}, mouse_shape.y = ${mouse_shape.y}`)
        }
    }

    Shape {
        id: shape
        visible: true
        width : 300
        height: 200
        anchors.centerIn: parent
        asynchronous: false
        containsMode: Shape.FillContains  // Shape.BoundingRectContains
        vendorExtensionsEnabled: false
        transform: [
            Rotation {
                axis.x: 0.0
                axis.y: 1.0
                axis.z: 0.0
                origin.x: shape.width  / 2
                origin.y: shape.height / 2
                angle: 180.0
            }, Rotation {
                axis.x: 1.0
                axis.y: 0.0
                axis.z: 0.0
                origin.x: shape.width  / 2
                origin.y: shape.height / 2
                angle: 180.0
            }
        ]
        antialiasing: true
        smooth: true
        layer.enabled: true
        layer.samples: 24
        layer.smooth: true

        onStatusChanged: {
            console.debug(`shape:onStatusChanged, status = ${status}, Shape.Null = ${Shape.Null}, Shape.Ready = ${Shape.Ready}, Shape.Processing = ${Shape.Processing}`)
        }

        Component.onCompleted: {
            console.debug(`shape.boundingRect = ${JSON.stringify(shape.boundingRect)}`)

            for(var i = 0; i < data.length; i += 1) {
                console.debug(`data[i] = ${data[i]}`)
            }

            console.debug(`rendererType = ${rendererType}, Shape.UnknownRenderer = ${Shape.UnknownRenderer}, Shape.GeometryRenderer = ${Shape.GeometryRenderer}, Shape.SoftwareRenderer = ${Shape.SoftwareRenderer}, Shape.CurveRenderer = ${Shape.CurveRenderer}`)
        }

        ShapePath {
            id: shapepath
            capStyle: ShapePath.RoundCap      // capStyle: ShapePath.FlatCap      // capStyle: ShapePath.SquareCap
            joinStyle: ShapePath.RoundJoin    // joinStyle: ShapePath.BevelJoin   // joinStyle: ShapePath.MiterJoin
            miterLimit: 2                     // ShapePath.MiterJoin
            strokeWidth: -1                   // strokeWidth < 0.0关闭边界宽度
            strokeStyle: ShapePath.SolidLine  // strokeStyle: ShapePath.DashLine
            strokeColor: "#FFFF0000"
            dashPattern: [1, 4]
            dashOffset: 0.0
            fillColor: "#FF00FF00"
//            fillGradient: LinearGradient {
//                x1: 20; y1: 20; x2: 180; y2: 130;
//                GradientStop { position: 0.0; color: "blue"  ; }
//                GradientStop { position: 0.2; color: "green" ; }
//                GradientStop { position: 0.4; color: "red"   ; }
//                GradientStop { position: 0.6; color: "yellow"; }
//                GradientStop { position: 1.0; color: "cyan"  ; }
//            }
            fillRule: ShapePath.WindingFill  // fillRule: ShapePath.OddEvenFill
            startX: 0.0
            startY: 0.0

            PathLine {
                x: shape.width
                y: shape.height
            }

            PathLine {
                x: 0.0
                y: shape.height
            }

            PathLine {
                x: 0.0
                y: 0.0
            }
        }
    }
}
