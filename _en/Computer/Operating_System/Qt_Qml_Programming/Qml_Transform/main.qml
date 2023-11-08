import QtQuick 2.14
import QtQuick.Window 2.14

Item {
    visible: true
    width: 640
    height: 480


    Column {
        Row {
            Image {
                source: "qrc:/images/qtlogo.png"
            }

            Image {
                source: "qrc:/images/qtlogo.png"
                transform: Rotation {
                    origin.x: 30
                    origin.y: 30
                    axis.x: 0
                    axis.y: 1
                    axis.z: 0
                    angle: 72
                }
            }
        }

        Row {
            Image {
                source: "qrc:/images/qtlogo.png"
            }

            Image {
                source: "qrc:/images/qtlogo.png"
                transform: Scale {
                    origin.x: 25
                    origin.y: 25
                    xScale: 2
                }
            }
        }

        Row {
            Image {
                source: "qrc:/images/qtlogo.png"
            }

            Image {
                source: "qrc:/images/qtlogo.png"
                transform: Translate {
                    x: 120
                    y: 50
                }
            }
        }
    }

}
