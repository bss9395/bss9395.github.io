import QtQuick 2.14
import QtGraphicalEffects 1.0
// import Qt5Compat.GraphicalEffects

Item {
    width: 600
    height: 600

    LinearGradient {
        width: parent.width
        height: 10
        y: 100
        start: Qt.point(width / 2, 0)
        end: Qt.point(width / 2, height)
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: "#FFFFFFFF"
            }

            GradientStop {
                position: 1.0
                color: "#80E1F5FE"
            }
        }
    }
}
