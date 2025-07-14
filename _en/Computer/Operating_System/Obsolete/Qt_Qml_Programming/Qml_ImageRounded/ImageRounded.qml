import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Shapes 1.12
import QtGraphicalEffects 1.0


OpacityMask {
    property real   radius       : width / 2
    property real   borderWidth  : 0.0
    property color  borderColor  : "#FF000000"
    property string borderStyle  : "SolidLine"
    property var    borderPattern: [1.0, 3.0]
    property var    fillMode     : Image.PreserveAspectFit
    property string imageSource  : ""
    id: opacitymask
    width: 64
    height: 64
    maskSource: shape_mask  // 注意: QQuickShaderEffectSource::textureProvider: can only be queried on the rendering thread of an exposed window
    source: image_source

    // 掩版
    ShapeRoundedCorner {
        id: shape_mask
        visible: false
        width: opacitymask.width
        height: opacitymask.height
        radiusCorner: [opacitymask.radius, opacitymask.radius, opacitymask.radius, opacitymask.radius]
        color: "#FFFF0000"
    }

    // 图片
    Image {
        id: image_source
        visible: false
        width: opacitymask.width
        height: opacitymask.height
        fillMode: opacitymask.fillMode
        source: opacitymask.imageSource
    }

    // 边框
    ShapeRoundedCorner {
        id: shaperoundedcorner
        width: opacitymask.width
        height: opacitymask.height
        radiusCorner: [opacitymask.radius, opacitymask.radius, opacitymask.radius, opacitymask.radius]
        borderWidth: opacitymask.borderWidth
        borderColor: opacitymask.borderColor
        borderStyle: opacitymask.borderStyle
        borderPattern: opacitymask.borderPattern
        color: "#00FFFFFF"
    }
}
