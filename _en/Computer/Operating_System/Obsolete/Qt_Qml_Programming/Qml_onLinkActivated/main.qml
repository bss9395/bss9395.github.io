import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    property var dpi: 1
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        Button {
            id: button
            text: "button"
            activeFocusOnTab: true

            onFocusChanged: {
                console.debug(`button:onFocusChanged`)
                if(focus === true) {
                    button.text = "focus === true"
                } else {
                    button.text = "focus === false"
                }
            }
        }

        // 隐私条款
        Label {
            property var url_baidu: "https://www.baidu.com"
            property var url_bing : "https://www.cn.bing.com"
            id: label_link
            width: parent.width
            font.pixelSize: 12 * dpi
            font.weight: Font.Normal
            color: "#FF666666"
            text: `<style>a { text-decoration: none; color: "#FF4399F3" }</style>了解&nbsp;<a href="{url_baidu}">隐私声明</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="{url_bing}">使用条款</a>&nbsp;`
            textFormat: Text.RichText

            onLinkActivated: (link) => {
                console.debug(`label_link:onLinkActivated, link = ${link}`)
                if(link === url_baidu) {
                    label_baidu.focus = true
                } else if(link === url_bing) {
                    label_bing.focus = true
                }
                Qt.openUrlExternally(link)
            }

            // 链接虚占位符
            Label {
                id: label_baidu
                activeFocusOnTab: true

                Keys.onReturnPressed: {
                    console.debug(`label_baidu:onReturnPressed`)
                    label_link.linkActivated(label_link.url_baidu)
                }
            }

            // 链接虚占位符
            Label {
                id: label_bing
                activeFocusOnTab: true

                Keys.onReturnPressed: {
                    console.debug(`label_bing:onReturnPressed`)
                    label_link.linkActivated(label_link.url_bing)
                }
            }
        }

        TextField {
            id: textfield
            text: "textfield"
            activeFocusOnTab: true

            onFocusChanged: {
                console.debug(`textfield:onFocusChanged`)
                if(focus === true) {
                    text = "focus === true"
                } else {
                    text = "focus === false"
                }
            }
        }
    }
}
