import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    Row {
        anchors.fill: parent

        ListView {
            width: 160
            height: parent.height
            model: Qt.fontFamilies()
            delegate: ItemDelegate {
                text: modelData
                highlighted: ListView.isCurrentItem

                onClicked: {
                    console.debug('modelData = ', modelData)
                }
            }
            ScrollIndicator.vertical: ScrollIndicator {

            }
        }

        ListView {
            width: 140
            height: parent.height
            model: ["Option 1", "Option 2", "Option 3"]
            delegate: CheckDelegate {
                text: modelData
            }
        }

        ListView {
            width: 140
            height: parent.height
            model: ["Option 1", "Option 2", "Option 3"]
            delegate: RadioDelegate {
                text: modelData
                checked: index === 0
                ButtonGroup.group: buttongroup
            }

            ButtonGroup {
                id: buttongroup
            }
        }

        ListView {
            width: 140
            height: parent.height
            model: ["Option 1", "Option 2", "Option 3"]
            delegate: SwitchDelegate {
                text: modelData
            }
        }
    }
}
