import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {

    width: 30
    height: 30
    flags: Qt.FramelessWindowHint

    signal exitSignal()
    signal onWelcomeWindowBtnClicked()

    Image {
        anchors.fill: parent
        source: "qrc:/qml/resources/google-translate-icon.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                exitSignal()
            }
        }
    }

}
