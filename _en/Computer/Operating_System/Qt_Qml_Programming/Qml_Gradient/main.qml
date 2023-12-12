import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.12

Control {
    visible: true
    width: row.width
    height: row.height

    Row {
        id: row

        Image {
            id: image_butterfly
            visible: true
            source: "qrc:/images/butterfly.png"
            smooth: true
        }

        ConicalGradient {
            id: conicalgradient
            width: image_butterfly.width
            height: image_butterfly.height
            source: image_butterfly
            gradient: Gradient {
                GradientStop {
                    position: 0.0
                    color: "#F0F0F0"
                }

                GradientStop {
                    position: 0.5
                    color: "#000000"
                }

                GradientStop {
                    position: 1.0
                    color: "#F0F0F0"
                }
            }
        }

        LinearGradient {
            width: image_butterfly.width
            height: image_butterfly.height
            source: image_butterfly
            start: Qt.point(0, 0)
            end: Qt.point(width, height)
            gradient: Gradient {
                GradientStop {
                    position: 0.0
                    color: "white"
                }

                GradientStop {
                    position: 1.0
                    color: "black"
                }
            }
        }

        RadialGradient {
            width: image_butterfly.width
            height: image_butterfly.height
            source: image_butterfly
            horizontalRadius: height / 3
            verticalRadius: width / 2
            angle: 30
            gradient: Gradient {
                GradientStop {
                    position: 0.0
                    color: "white"
                }

                GradientStop {
                    position: 1.0
                    color: "black"
                }
            }
        }
    }
}
