import QtQuick 2.12
import QtQuick.Window 2.12

Rectangle {
    FontLoader {
        id: webFont
        source: "https://qter-images.qter.org/other/myfont.ttf"
    }

    Text {
        width: 200
        text: webFont.status === FontLoader.Ready ? "Loaded" : "Not loaded"
        font.family: webFont.name
        font.pointSize: 20
    }
}
