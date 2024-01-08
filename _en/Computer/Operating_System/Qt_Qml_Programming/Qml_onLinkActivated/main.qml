import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    width: 800
    height: 600

    Text {
        font.pixelSize: 18
        color: "#FF000000"
        text: `<style>a { text-decoration: none; color: "#FF4399F3" }</style>欢迎访问<a href="https://www.baidu.com">百度一下，你就知道。</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="https://cn.bing.com">必应一下，你就知道。</a>`
        textFormat: Text.RichText

        onLinkActivated: (link) => {
            console.log("link activated: " + link)
            Qt.openUrlExternally(link)
        }
    }
}
