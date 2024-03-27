import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Rectangle {
    default property var defaultData: undefined
    property var background         : undefined
    id: rectangle
    width: 200
    height: 200
    color: "transparent"

    onBackgroundChanged: {
        console.debug(`rectangle:onBackgroundChanged, background = ${background}`)
        rectangle_background.data = []
        if(background) {
            rectangle_background.data.push(background)
        }
    }

    onDefaultDataChanged: {
        console.debug(`rectangle:onDefaultDataChanged, defaultData = ${defaultData}`)
        if(defaultData) {
            rectangle_data.data.push(defaultData)
        }
    }

    Rectangle {
        id: rectangle_background
        anchors.fill: rectangle_data
        color: "transparent"

        onChildrenChanged: {
            console.debug(`rectangle_background:onChildrenChanged`)
            for(var i = 0; i < children.length; i += 1) {
                if(children[i].width <= 0) {
                    children[i].width = Qt.binding(function () {
                        return rectangle_background.width
                    })
                }
                if(children[i].height <= 0) {
                    children[i].height = Qt.binding(function () {
                        return rectangle_background.height
                    })
                }
                console.debug(`rectangle_background.width = ${rectangle_background.width}, rectangle_background.height = ${rectangle_background.height}, children[i].width = ${children[i].width}, children[i].height = ${children[i].height}`)
            }
        }
    }

    Rectangle {
        id: rectangle_data
        anchors.fill: parent
        color: "transparent"

    }
}
