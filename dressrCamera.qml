import QtQuick 2.0
import QtQuick.Controls 1.2
import QtMultimedia 5.4

Rectangle {
    id: rect
    color: "#ff3c3c"
    //anchors.fill: parent
    width: 100
    height: 100

    VideoOutput {
        id: viewfinder
        visible: true

        x: 0
        y: 0
        width: parent.width
        height: parent.height

        source: camera
        autoOrientation: true
    }
    Camera {
        id: camera
        captureMode: Camera.CaptureStillImage

        videoRecorder {
             resolution: "640x480"
             frameRate: 30
        }
    }

    Button {
        id: capture
        text: "Capture"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        visible: camera.imageCapture.ready
        onClicked: camera.imageCapture.capture()
    }
}
