import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    RowLayout {
        spacing: 20

        DelayButton {
            id: delaybutton
            text: "延迟按钮"
            delay: 5000

            onActivated: {
                delaybutton.text = "已启动"
            }
        }

        Switch {
            id: switch_button
            text: "Wi-Fi"

            onToggled: {
                console.debug('switch_button.checked = ', switch_button.checked)
            }
        }
    }
}
