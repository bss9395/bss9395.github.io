import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtMultimedia
import Qt.labs.platform

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
Rectangle {
    anchors.fill: parent
    color: "#FF000000"

    // 设备管理器
    MediaDevices {
        id: mediadevices

        Component.onCompleted: {
            // for(var i = 0; i < mediadevices.audioInputs.length; i += 1) {
            //     console.debug(`audioInputs[${i}] = ${mediadevices.audioInputs[i]}`)
            // }
            // for(var j = 0; j < mediadevices.audioOutputs.length; j += 1) {
            //     console.debug(`audioOutputs[${j}] = ${mediadevices.audioOutputs[j]}`)
            // }
            // for(var k = 0; k < mediadevices.videoInputs.length; k += 1) {
            //     console.debug(`videoInputs[${k}] = ${mediadevices.videoInputs[k]}`)
            // }
            // console.debug(`defaultAudioInput = ${mediadevices.defaultAudioInput}`)
            // console.debug(`defaultAudioOutput = ${mediadevices.defaultAudioOutput}`)
            // console.debug(`defaultVideoInput = ${mediadevices.defaultVideoInput}`)
        }
    }

    // 相机
    Camera {
        property string currentState: "camera_off"
        id: camera
        cameraDevice: mediadevices.defaultVideoInput
        flashMode: Camera.FlashAuto
        focusMode: Camera.FocusModeAuto
        torchMode: Camera.TorchAuto
        whiteBalanceMode: Camera.WhiteBalanceAuto

        onActiveChanged: {
            console.debug(`camera:onActiveChanged, active=${camera.active}`)
        }
    }

    // 视频输出
    VideoOutput {
        id: videooutput
        anchors.fill: parent
        // transform: Rotation {  // 左右反转图片
        //     origin.x: videooutput.width / 2
        //     origin.y: videooutput.height / 2
        //     origin.z: 0
        //     axis.x: 0
        //     axis.y: 1
        //     axis.z: 0
        //     angle: 180
        // }
        fillMode: VideoOutput.PreserveAspectFit
        orientation: 0
    }

    // 图片捕获
    ImageCapture {
        id: imagecapture
    }

    // 流媒体录制
    MediaRecorder {
        id: mediarecorder
    }

    // 捕获管理
    CaptureSession {
        audioInput: AudioInput {}  // 音频输入
        camera: camera
        videoOutput: videooutput
        imageCapture: imagecapture
        recorder: mediarecorder
    }

    // 启动按钮
    Button {
        id: button_start_stop
        anchors.horizontalCenter: videooutput.horizontalCenter
        anchors.bottom: videooutput.bottom
        text: camera.currentState === "camera_on" ? "关闭" : "打开"

        onClicked: {
            if(camera.currentState === "camera_on") {
                camera.stop()
                camera.currentState = "camera_off"
            } else {
                camera.start()
                camera.currentState = "camera_on"
            }
        }
    }

    // 拍照按钮
    Button {
        id: button_capture
        visible: camera.currentState === "camera_on"
        anchors.left: button_start_stop.right
        anchors.verticalCenter: button_start_stop.verticalCenter
        text: "拍照"

        onClicked: {
            imagecapture.capture()
            popup.open()
        }
    }

    // 录制按钮
    Button {
        id: button_record
        visible: camera.currentState === "camera_on"
        anchors.left: button_capture.right
        anchors.verticalCenter: button_capture.verticalCenter
        text: mediarecorder.recorderState === MediaRecorder.StoppedState ? "录像" : "停止"

        onClicked: {
            if(mediarecorder.recorderState === MediaRecorder.StoppedState) {
                filedialog_record.open()
            } else {
                mediarecorder.stop()
            }
        }
    }

    // 录制时长
    Label {
        id: label_record
        visible: mediarecorder.recorderState === MediaRecorder.RecordingState
        anchors.left: button_record.right
        anchors.verticalCenter: button_record.verticalCenter
        text: mediarecorder.duration / 1000
        color: "#FFFFFFFF"
    }

    // 截图弹窗
    Popup {
        id: popup
        width: 400
        height: 300
        anchors.centerIn: Overlay.overlay
        modal: true

        ScrollView {
            anchors.fill: parent

            Image {
                id: image
                source: imagecapture.preview
                fillMode: Image.PreserveAspectFit
                transform: Rotation {  // 此方法不影响grabToImage()
                    origin.x: image.width / 2
                    origin.y: image.height / 2
                    origin.z: 0
                    axis.x: 0
                    axis.y: 1
                    axis.z: 0
                    angle: 180
                }
            }
        }

        Button {
            id: button_save
            text: "保存"

            onClicked: {
                filedialog.open()
            }
        }

        FileDialog {
            id: filedialog
            folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
            fileMode: FileDialog.SaveFile
            currentFile: "untitled.png"

            onAccepted: {
                imagecapture.saveToFile(filedialog.file)
                // image.grabToImage(function (result) {  // 此方法未能左右反转图片
                //     result.saveToFile(filedialog.file)
                // })
            }
        }
    }

    // 录制保存对话框
    FileDialog {
        id: filedialog_record
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        fileMode: FileDialog.SaveFile
        currentFile: "untitled.mp4"

        onAccepted: {
            mediarecorder.outputLocation = filedialog_record.file
            mediarecorder.record()
        }
    }
}
}
