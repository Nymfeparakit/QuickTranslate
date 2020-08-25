import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: translatedTextWindow
    objectName: "translatedTextWindow"

    /*BusyIndicator {
           id: busyIndicator
           objectName: "busyIndicator"
           anchors.centerIn: parent
           //running: false
        }*/

    TranslateTextRect {
        id: translatedText
        objectName: "translatedTextRect"
        color: "#333333"

        width: 320
        height: 140
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    signal exitSignal()
    signal onExpandBtnClicked()

    Image {
        anchors.top: translatedText.bottom
        anchors.right: parent.right

        source: "qrc:/qml/resources/expand-more-icon.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                stackView.replace("qrc:/qml/FullLayoutItem.qml")
                mainWindow.width = 640
                mainWindow.height = 520
                mainWindow.color = "#333333"
                mainWindow.flags = Qt.Window
                stackView.width = 640
                stackView.height = 480
                expandBtnClicked()

            }
        }
    }
    Component.onCompleted: {
        welcomeButtonClicked()
    }
}
