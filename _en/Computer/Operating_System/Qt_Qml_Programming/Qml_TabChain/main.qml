import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        console.debug(`=========================================================`)
        console.debug(`focusPolicy`)
        console.debug(`Qt.TabFocus    = ${Qt.TabFocus}`)
        console.debug(`Qt.ClickFocus  = ${Qt.ClickFocus}`)
        console.debug(`Qt.StrongFocus = ${Qt.StrongFocus}`)
        console.debug(`Qt.WheelFocus  = ${Qt.WheelFocus}`)
        console.debug(`Qt.NoFocus     = ${Qt.NoFocus}`)
        console.debug(`=========================================================`)
        console.debug(`focusReason`)
        console.debug(`Qt.MouseFocusReason        = ${Qt.MouseFocusReason}`)
        console.debug(`Qt.TabFocusReason          = ${Qt.TabFocusReason}`)
        console.debug(`Qt.BacktabFocusReason      = ${Qt.BacktabFocusReason}`)
        console.debug(`Qt.ActiveWindowFocusReason = ${Qt.ActiveWindowFocusReason}`)
        console.debug(`Qt.PopupFocusReason        = ${Qt.PopupFocusReason}`)
        console.debug(`Qt.ShortcutFocusReason     = ${Qt.ShortcutFocusReason}`)
        console.debug(`Qt.MenuBarFocusReason      = ${Qt.MenuBarFocusReason}`)
        console.debug(`Qt.OtherFocusReason        = ${Qt.OtherFocusReason}`)
        console.debug(`=========================================================`)
    }

    Item {
        property var tabChain: ([])
        id: item
        focus: true  // 根组件获取初始焦点

        onFocusChanged: {
            console.debug(`item:onFocusChanged, focus = ${focus}, activeFocus = ${activeFocus}`)
        }

        Keys.onPressed: (event) => {
            console.debug(`item:onPressed`)
            if(event.key === Qt.Key_Tab) {
                console.debug(`item:if(event.key === Qt.Key_Tab) {`)
                item.func_tabChain()
                event.accepted = true
            } else {
                event.accepted = false
            }
        }

        Component.onCompleted: {
            tabChain.push(control)
            tabChain.push(textfield)
            tabChain.push(textarea)
            tabChain.push(label)
            tabChain.push(image)
        }

        function func_tabChain() {
            console.debug(`function func_tabChain() {`)
            if((1 <= tabChain.length) === false) {
                return
            }

            var i = 0
            var hitted = false
            for(; i < tabChain.length; i += 1) {
                if(tabChain[i].focus === true) {
                    console.debug(`if(tabChain[${i}].activeFocus === true) {`)
                    hitted = true
                    break
                }
            }
            if(hitted === true) {
                i = (i + 1) % tabChain.length
            } else {
                i = 0
            }
            console.debug(`tabChain.length = ${tabChain.length}`)
            tabChain[i].focus = true
        }

        ////////////////////////////////////////////////////////////////////////

        Column {
            Control {
                id: control
                width: 100
                height: 100
                background: Rectangle {
                    color: (control.focus === false) ? "yellow" : "green"
                }
                focusPolicy: Qt.NoFocus
                activeFocusOnTab: false

                onFocusChanged: {
                    console.debug(`control:onFocusChanged, focus = ${focus}, activeFocus = ${activeFocus}`)
                }

                Keys.onPressed: (event) => {
                    console.debug(`control:onPressed`)
                    if(event.key === Qt.Key_Tab) {
                        console.debug(`if(event.key === Qt.Key_Tab) {`)
                        item.func_tabChain()
                        event.accepted = true
                    } else {
                        event.accepted = false
                    }
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        control.focus = true
                    }
                }
            }

            TextField {
                id: textfield
                text: "textfield"
                activeFocusOnTab: false
                activeFocusOnPress: true

                onFocusChanged: {
                    console.debug(`textfield:onFocusChanged, focus = ${focus}, activeFocus = ${activeFocus}`)
                }

                Keys.onPressed: (event) => {
                    console.debug(`textfield:onPressed`)
                    if(event.key === Qt.Key_Tab) {
                        console.debug(`if(event.key === Qt.Key_Tab) {`)
                        item.func_tabChain()
                        event.accepted = true
                    } else{
                        event.accepted = false
                    }
                }
            }

            TextArea {
                id: textarea
                background: Rectangle {
                    border.width: 1
                    border.color: (textarea.focus === false) ? "yellow" : "green"
                }
                text: "textarea"
                activeFocusOnTab: false
                activeFocusOnPress: true

                onFocusChanged: {
                    console.debug(`textarea:onFocusChanged, focus = ${focus}, activeFocus = ${activeFocus}`)
                }

                Keys.onPressed: (event) => {
                    console.debug(`textarea:onPressed`)
                    if(event.key === Qt.Key_Tab) {
                        console.debug(`textarea:if(event.key === Qt.Key_Tab) {`)
                        item.func_tabChain()
                        event.accepted = true
                    } else{
                        event.accepted = false
                    }
                }
            }

            Label {
                id: label
                background: Rectangle {
                    color: (label.focus === false) ? "yellow" : "green"
                }
                text: "label"
                activeFocusOnTab: false

                onFocusChanged: {
                    console.debug(`label:onFocusChanged, focus = ${focus}, activeFocus = ${activeFocus}`)
                }

                Keys.onPressed: (event) => {
                    console.debug(`label:onPressed`)
                    if(event.key === Qt.Key_Tab) {
                        console.debug(`if(event.key === Qt.Key_Tab) {`)
                        item.func_tabChain()
                        event.accepted = true
                    } else {
                        event.accepted = false
                    }
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.debug(`label:onClicked`)
                        label.focus = true
                    }
                }
            }

            Image {
                id: image
                fillMode: Image.PreserveAspectFit
                source: (image.focus === false) ? "qrc:/images/icon_hide.png" : "qrc:/images/icon_show.png"
                activeFocusOnTab: false

                onFocusChanged: {
                    console.debug(`image:onFocusChanged, focus = ${focus}, activeFocus = ${activeFocus}`)
                }

                Keys.onPressed: (event) => {
                    console.debug(`image:onPressed`)
                    if(event.key === Qt.Key_Tab) {
                        console.debug(`if(event.key === Qt.Key_Tab) {`)
                        item.func_tabChain()
                        event.accepted = true
                    } else {
                        event.accepted = false
                    }
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        console.debug(`image:onClicked`)
                        image.focus = true
                    }
                }
            }
        }
    }
}
