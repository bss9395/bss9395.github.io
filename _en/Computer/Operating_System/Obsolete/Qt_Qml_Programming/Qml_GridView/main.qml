import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        width: parent.width

        GridView {
            property var columns: 2
            id: gridview
            width: parent.width  // GridView采用Flow布局
            height: childrenRect.height
            topMargin: 10
            cellWidth: 100
            cellHeight: 100
            clip: true
            model: ListModel {
                id: listmodel_gridview
            }
            delegate: Rectangle {
                property var softwareData: model.softwareData
                width: gridview.cellWidth
                height: gridview.cellHeight
                color: "red"
                Layout.alignment: Qt.AlignBottom

                Column {
                    Text {
                        text: softwareData["key"]
                    }

                    Text {
                        text: softwareData["value"]
                    }
                }

                Component.onCompleted: {
                    console.debug('rectangle_gridview:onCompleted')
                }

                Component.onDestruction: {
                    console.debug('rectangle_gridview:onDestruction')
                }
            }

            Component.onCompleted: {
                var abc = {
                    key: "key0",
                    value: "value0"
                }
                var def = {
                    key: "key1",
                    value: "value1"
                }
                var ghi = {
                    key: "key2",
                    value: "value2"
                }

                listmodel_gridview.append({ "softwareData": abc, "extraData": {} })
                listmodel_gridview.append({ "softwareData": def, "extraData": {} })
                listmodel_gridview.append({ "softwareData": ghi, "extraData": {} })

                def["value"] = "value_def"
                listmodel_gridview.get(1)["softwareData"] = def

                var timer = Qt.createQmlObject("import QtQuick 2.0; Timer {}", this)
                timer.triggered.connect(function () {
                    listmodel_gridview.remove(0)
                })
                timer.interval = 3000
                timer.repeat = false
                timer.running = true
            }
        }

        Grid {
            id: grid
            width: parent.width  // Gird采用静态布局
            height: childrenRect.height
            topPadding: 10
            columns: 2
            columnSpacing: 10
            rowSpacing: 10
            clip: true

            Repeater {
                id: repeater
                model: ListModel {
                    id: listmodel_grid
                }
                delegate: Rectangle {
                    property var softwareData: model.softwareData
                    property var extraData   : model.extraData
                    id: rectangle_grid
                    width: childrenRect.width
                    height: childrenRect.height
                    color: "green"

                    Column {
                        Text {
                            text: softwareData["key"]
                        }

                        Text {
                            text: softwareData["value"]
                        }
                    }

                    Component.onCompleted: {
                        console.debug('rectangle_grid:onCompleted')
                    }

                    Component.onDestruction: {
                        console.debug('rectangle_grid:onDestruction')
                    }
                }
            }

            Component.onCompleted: {
                var abc = {
                    key: "key0",
                    value: "value0"
                }
                var def = {
                    key: "key1",
                    value: "value1"
                }
                var ghi = {
                    key: "key2",
                    value: "value2"
                }
                listmodel_grid.append({ "softwareData": abc, "extraData": {} })
                listmodel_grid.append({ "softwareData": def, "extraData": {} })
                listmodel_grid.append({ "softwareData": ghi, "extraData": {} })

                def["value"] = "value_def"
                listmodel_grid.get(1)["softwareData"] = def

                var timer = Qt.createQmlObject("import QtQuick 2.0; Timer {}", this)
                timer.triggered.connect(function () {
                    listmodel_grid.remove(0)
                })
                timer.interval = 3000
                timer.repeat = false
                timer.running = true
            }
        }
    }
}
