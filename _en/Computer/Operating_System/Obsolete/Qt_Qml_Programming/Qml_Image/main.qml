import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    visible: true
    width: 640
    height: 480

    Column {
        Frame {
            width: 200
            height: 200

            Image {
                width: parent.width
                height: parent.height
                horizontalAlignment: Image.AlignLeft
                verticalAlignment: Image.AlignTop
                source: "images/qtlogo.png"
                fillMode: Image.PreserveAspectFit // Image.Stretch | Image.PreserveAspectCrop | Image.Tile | Image.TileVertically | Image.TileHorizontally
            }
        }

        Frame {
            width: 200
            height: 200

            Image {
                id: image
                width: parent.width
                height: parent.height
                source: "http://www.baidu.com/img/baidu_sylogo1.gif"
                fillMode: Image.PreserveAspectFit
                // sourceSize.width: 100
                // sourceSize.height: 100
                cache: true
                mirror: false
                smooth: true

                onStatusChanged: {
                    if(image.status == Image.Ready) {
                        console.debug('Ready')
                    } else if(image.status == Image.Loading) {
                        console.debug('Loading')
                    } else if(image.status == Image.Null) {
                        console.debug('Null')
                    } else if(image.status == Image.Error) {
                        console.debug('Error')
                    }
                }
            }
        }
    }
}
