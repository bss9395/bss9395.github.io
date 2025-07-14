import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        property real  radius   : 24
        property color retention: "grey"
        property var   stripe   : true
        id: rectangle
        width: radius * 2
        height: radius * 2
        color: "#00FFFFFF"
        Repeater {
            property int index_midd: 0
            property int index_mini: repeater.index_midd - 1
            property int index_maxi: repeater.index_midd + 1
            id: repeater
            model: 8
            delegate: Rectangle {
                width:  rectangle.stripe === true ? height / 2             : height
                height: rectangle.stripe === true ? rectangle.radius * 0.5 : rectangle.radius * 0.4
                radius: rectangle.stripe === true ? 0                      : width / 2
                color: rectangle.retention
                transform: [
                    Translate {  // 以条形顶端中点为拟原点
                        x: - width / 2
                        y: 0
                    },
                    Translate {  // 将条形平移到区域正上方
                        x: rectangle.radius
                        y: 0
                    },
                    Rotation {   // 将条形按区域中心顺时针旋转
                        origin.x: rectangle.radius
                        origin.y: rectangle.radius
                        angle: (360.0 / repeater.model) * index
                    }
                ]
                // [7,0,1][0,1,2][1,2,3][2,3,4][3,4,5][4,5,6][5,6,7][6,7,0]
                opacity: {
                    // console.debug(`index = ${index}, index_midd = ${repeater.index_midd}, index_mini = ${index_mini}, index_maxi = ${index_maxi}`)
                    if(repeater.index_mini <= index && index <= repeater.index_maxi) {
                        return 1.0
                    } else if(repeater.index_mini < 0 && repeater.index_mini + repeater.model <= index) {
                        return 1.0
                    } else if(repeater.model <= repeater.index_maxi && index <= repeater.index_maxi - repeater.model) {
                        return 1.0
                    }
                    return 0.3
                }

                Behavior on opacity {
                    enabled: true

                    NumberAnimation {
                        duration: timer.interval
                    }
                }
            }
        }

        Timer {
            id: timer
            running: true
            repeat: true
            interval: 100

            onTriggered: {
                repeater.index_midd = (repeater.index_midd + 1) % repeater.model
            }
        }
    }
}
