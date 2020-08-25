import QtQuick 2.0

Item {
    objectName: "welcomeButtonItem"

    Image {
        anchors.fill: parent
        source: "qrc:/qml/resources/google-translate-icon.svg"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                stackView.replace("qrc:/qml/TranslatedTextItem.qml")
                mainWindow.width = 368
                mainWindow.height = 188
                mainWindow.color = "#333333"
                stackView.width = 368
                stackView.height = 188
            }
        }
    }

}
