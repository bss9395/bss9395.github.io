import QtQuick 2.12
import QtQuick.Window 2.12

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
                id: image_rotation
                source: "qrc:/images/qtlogo.png"
                transform: Rotation {
                    origin.x: image_rotation.width / 2
                    origin.y: image_rotation.height / 2
                    axis.x: 0
                    axis.y: 1
                    axis.z: 0
                    angle: 60
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
