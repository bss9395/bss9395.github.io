import QtQuick 2.12
import QtQuick.Controls 2.12

Label {
    property var initedWidth : false
    property var initedHeight: false
    property var inited      : false
    id: label
    width: 0
    height: 0

    Component.onCompleted: {
        console.debug(`label:onCompleted`)
        if(0 < width) {
            initedWidth = true
        }
        if(0 < height) {
            initedHeight = true
        }
        inited = true
        console.debug(`initedWidth = ${initedWidth}, initedHeight = ${initedHeight}, inited = ${inited}`)

        ////////////////////////////////////////////////////////////////////////

        console.debug(`label:onCompleted, implicitHeight = ${implicitHeight}, contentHeight = ${contentHeight}, lineCount = ${lineCount}, fontmetrics.height = ${fontmetrics.height}`)
        if(initedWidth === false) {
            label.width  = Qt.binding(function () {
                return label.implicitWidth
            })
        }
        if(initedHeight === false) {
            label.height = Qt.binding(function () {
                return label.implicitHeight - (label.contentHeight / label.lineCount - fontmetrics.height)
            })
        }
    }

    FontMetrics {
        id: fontmetrics
        font: label.font
    }
}
