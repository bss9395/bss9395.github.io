import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    width: 100
    height: 100

    Loader {
        id: loader_page
        source: "Page.qml"
    }

    Connections {
        target:loader_page.item

        function onSignal_message(msg) {
            console.log(msg)
        }
    }

    Component.onCompleted: {
        loader_page.item.signal_message.connect(function (msg) {
            console.log(msg)
        })
    }
}
