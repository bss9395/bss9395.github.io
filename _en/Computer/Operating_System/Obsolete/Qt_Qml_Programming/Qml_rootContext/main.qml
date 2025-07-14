import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Label {
        text: "label"
    }

    Component.onCompleted: {
        console.debug(`window:onCompleted`)
        configcpp.greeting()
    }
}


//Item {
//    id: item
//    width: 640
//    height: 480

//    Label {
//        text: "label"
//    }

//    Component.onCompleted: {
//        console.debug(`item:onCompleted`)
//        configcpp.greeting()

//    }
//}
