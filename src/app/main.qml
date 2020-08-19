
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

//Window {
  //  visible: true
  //  width: 640
  //  height: 480
  //  title: qsTr("Hello World again")
  //  color: "#333333"


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

        LanguageBox {
            objectName: "sourceLangBox"

            anchors.right: swapLangsBtn.left
            anchors.rightMargin: 30
            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }

        SimpleButton {
            id: swapLangsBtn

            Layout.columnSpan: 1
            Layout.rowSpan: 1
            anchors.horizontalCenter: parent.horizontalCenter

            contentItem: StyledTextItem {
                text: "Change"
            }
        }

        LanguageBox {
            objectName: "destLangBox"

            anchors.left: swapLangsBtn.right
            anchors.leftMargin: 30
            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }

        TranslateTextRect {
        objectName: "translatedTextRect"
        Layout.columnSpan: 3
        Layout.rowSpan: 3
        Layout.fillHeight: true
        Layout.fillWidth: true
        }

        SimpleButton {
            objectName: "translateBtn"
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            anchors.horizontalCenter: parent.horizontalCenter

            signal clickedSignal()
            onClicked: clickedSignal()

            contentItem: StyledTextItem {
                text: "Translate"
            }
        }
    }
//}
