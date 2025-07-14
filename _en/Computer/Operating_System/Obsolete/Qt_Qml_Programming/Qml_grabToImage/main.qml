import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
Rectangle {
    id: rectangle
    anchors.fill: parent

    Image {
        id: image_bug
        visible: false
        source: "qrc:/images/bug.png"
        smooth: true
    }

    Image {
        id: image_mask
        visible: false
        source: "qrc:/images/mask.png"
        smooth: true
    }

    ThresholdMask {
        id: thresholdmask
        anchors.fill: image_bug
        source: image_bug
        maskSource: image_mask
        threshold: 0.375
        spread: 0.375
    }

    Button {
        id: button
        text: "保存"

        onClicked: {
//            thresholdmask.grabToImage(function (result) {
//                result.saveToFile("E:/Desktop/untitled.png")  // 程序无效果若此处添加前缀file:///
//            })
            rectangle.grabToImage(function (result) {
                result.saveToFile("E:/Desktop/untitled.png")    // 程序无效果若此处添加前缀file:///
            })
        }
    }
}
}
