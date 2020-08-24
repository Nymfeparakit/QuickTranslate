
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import "."

Window {
    id: mainWindow
    visible: false
    width: 640
    height: 480
    title: qsTr("")
    color: "#333333"

    signal mainWindowClosed()

    onClosing: {
        //console.log("closing window");
        mainWindowClosed()
    }

    GridLayout {
        objectName: "mainLayout"

        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.topMargin: 10
        anchors.bottomMargin: 10

        columns: 3

        StyledTextItem {
            anchors.horizontalCenter: parent.horizontalCenter
            Layout.columnSpan: 3
            Layout.rowSpan: 1
            text: "Translator"
            font.pointSize: 26
            font.bold: true
            //font: parent.normalFont
        }

        TranslateTextRect {
            objectName: "sourceTextRect"

            Layout.columnSpan: 3
            Layout.rowSpan: 3
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        SeparatingStrip {
        Layout.columnSpan: 3
        Layout.rowSpan: 1
        Layout.fillHeight: true
        Layout.fillWidth: true
        }

        TranslateTextRect {
        objectName: "translatedTextRect"
        Layout.columnSpan: 3
        Layout.rowSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true
        }

        LanguageBox {
            objectName: "destLangBox"

            //anchors.left: swapLangsBtn.right
            anchors.left: parent.left
            anchors.leftMargin: 30
            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }

        SimpleButton {
            objectName: "translateBtn"
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            anchors.right: parent.right

            signal clickedSignal()
            onClicked: clickedSignal()

            contentItem: StyledTextItem {
                text: "Translate"
            }
        }
    }

    WelcomeWindow {
        id: welcomeWindow
        objectName: "welcomeWindow"
        visible: false

        onExitSignal: {
            onlyTranslatedTextWindow.x = welcomeWindow.x
            onlyTranslatedTextWindow.y = welcomeWindow.y
            onlyTranslatedTextWindow.show()
            welcomeWindow.close()
            onWelcomeWindowBtnClicked()
        }
    }

    OnlyTranslatedTextWindow {
       id: onlyTranslatedTextWindow
       objectName: "onlyTranslatedTextWindow"
       visible: false

       onExitSignal: {
            mainWindow.show()
            onlyTranslatedTextWindow.close()
            onExpandBtnClicked()
        }
    }
}


