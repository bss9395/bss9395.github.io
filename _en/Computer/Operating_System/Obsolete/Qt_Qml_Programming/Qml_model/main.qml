import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        width: 300

        Repeater {
            id: repeater_model
            model: []

            delegate: Rectangle {
                width: 100
                height: 100
                Column {
                    Text {
                        text: modelData["name"]
                    }
                    Text {
                        text: modelData["value"]
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        var softwareData = []
        var item0 = {
            "name": "name0",
            "value": "value0",
        }
        var item1 = {
            "name": "name1",
            "value": "value1",
        }
        softwareData.push(item0)
        softwareData.push(item1)
        repeater_model.model = softwareData



        softwareData.shift()
        for(var i = 0; i < repeater_model.model.length; i += 1) {
            repeater_model.itemAt(i).visible = false
        }

        console.debug(softwareData.length, repeater_model.model.length)
        for(var j = 0; j < softwareData.length; j += 1) {
            for(var k = 0; k < repeater_model.model.length; k += 1) {
                console.debug(softwareData[j]["name"], repeater_model.model[k]["name"])
                if(softwareData[j]["name"] === repeater_model.model[k]["name"]) {
                    repeater_model.itemAt(k).visible = true
                }
            }
        }
    }
}
