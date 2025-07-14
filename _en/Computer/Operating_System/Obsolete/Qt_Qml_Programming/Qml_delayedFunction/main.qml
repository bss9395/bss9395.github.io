import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQml 2.12

ApplicationWindow {
    id: parentItem
    visible: true
    width: 200
    height: 200

    Component.onCompleted: {
        delayedFunction(function () {
            console.debug('delayedFunction')
        })
    }

    function delayedFunction(func) {
        var timer = Qt.createQmlObject("import QtQuick 2.0; Timer {}", this)
        timer.running = true
        timer.interval = 50
        timer.repeat = false
        timer.triggered.connect(func)
        timer.start()
    }
}
