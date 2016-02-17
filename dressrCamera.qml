import QtQuick 2.0
import QtQuick.Controls 1.2
import QtMultimedia 5.4

Rectangle {
    id: rect
    color: "white"
//    anchors.fill: parent
    width: 100
    height: 100
    property int readyToCapture: 0
    property string imgPath
    onReadyToCaptureChanged: {
        if (readyToCapture === 1)
            camera.imageCapture.captureToLocation(imgPath);
        readyToCapture = 0;
    }

    signal captured(string message)

    Camera {
        id: camera
        captureMode: Camera.CaptureStillImage
        //width: parent.width
        //height: parent.height

        videoRecorder {
             resolution: "700x700"
             frameRate: 30
        }

        imageCapture {
            resolution: "700x700"
//            capturedImagePath: imgPath
            onImageSaved: {
                rect.captured(path);
            }
        }
    }

    VideoOutput {
        id: viewfinder
        visible: true

//        x: 0
//        y: 0
        anchors.fill: parent
//        width: parent.width
//        height: parent.height

        fillMode: VideoOutput.PreserveAspectCrop
        source: camera
        autoOrientation: true
    }

//    Button {
//        id: capture
//        text: "Capture"
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 50
//        visible: camera.imageCapture.ready
//        onClicked: camera.imageCapture.capture()
//    }
}
