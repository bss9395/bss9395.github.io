pragma Singleton
import QtQuick 2.12

Item {
    property var font1: ""
    property var font2: ""
    id: item_config

    FontLoader {
        id: fontloader1
        source: "qrc:/fonts/FZLanTingHeiS-R-GB-Regular01.TTF"

        Component.onCompleted: {
            console.debug(`fontloader1:onCompleted`)
            if(fontloader1.status === FontLoader.Ready) {
                item_config.font1 = fontloader1.name
            } else {
                console.debug(`if(fontloader1.status === FontLoader.Ready) {`)
            }
        }

        onStatusChanged: {
            console.debug(`fontloader1.status = ${fontloader1.status}`)
        }
    }

    FontLoader {
        id: fontloader2
        source: "qrc:/fonts/FZLanTingHeiS-R-GB-Regular02.TTF"

        Component.onCompleted: {
            console.debug(`fontloader2:onCompleted`)
            if(fontloader2.status === FontLoader.Ready) {
                item_config.font2 = fontloader2.name
            } else {
                console.debug(`if(fontloader2.status === fontloader2.Ready) {`)
            }
        }

        onStatusChanged: {
            console.debug(`fontloader2.status = ${fontloader2.status}`)
        }
    }
}
