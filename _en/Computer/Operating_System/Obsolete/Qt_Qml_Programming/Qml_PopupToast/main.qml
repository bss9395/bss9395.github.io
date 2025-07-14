import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 800

    PopupToast {
        id: popup_toast

        onSignal_toastFinished: (identifier) => {
            console.debug(`popup_toast:onSignal_toastFinished, identifier = ${identifier}`)
        }
    }


    Button {
        property var counter: 0
        id: button
        text: "button"
        onClicked: {
            counter += 1
            popup_toast.toast("authentication_failed", "error", counter + "认证失败，请重新认证！", 3000)
        }
    }
}
