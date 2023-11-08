import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    RangeSlider {
        id: rangeslider
        from: 0
        to: 100
        stepSize: 1
        first.value: 25
        second.value: 75

        first.onMoved: {
            console.debug(first.value + ", " + second.value)
        }

        second.onMoved: {
            console.debug(first.value + ", " + second.value)
        }
    }

    Slider {
        id: slider
        anchors.top: rangeslider.bottom
        from: 0
        to: 100
        stepSize: 10
        value: 25

        onMoved: {
            console.debug(value)
        }
    }
}
