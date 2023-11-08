import QtQuick 2.12
import QtQuick.Window 2.12

Item {
    width: 400
    height: 100

    Text {
        textFormat: Text.RichText
        font.pixelSize: 24
        text: "欢迎访问<a href='https://qter.org'>Qt开源社区</a>"

        onLinkActivated: (link) => {
            console.log("link activated: " + link)
        }
    }
}
