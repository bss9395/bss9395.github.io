import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    Frame {
        id: frame
        anchors.centerIn: parent

        Row {
            Tumbler {
                id: tumbler_hour
                model: 24
                delegate: component
            }

            Tumbler {
                id: tumbler_minute
                model: 60
                delegate: component
            }

            Tumbler {
                id: tumbler_ampm
                model: ["AM", "PM"]
                delegate: component
            }
        }

        Component {
            id: component

            Label {
                text: modelData.toString().length < 2 ? "0" + modelData : modelData
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                opacity: 1.0 - Math.abs(Tumbler.displacement / (Tumbler.tumbler.visibleItemCount / 2))
            }
        }
    }
}
