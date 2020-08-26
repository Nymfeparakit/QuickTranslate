import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    objectName: "fullLayoutItem"

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
        }

        // text field with source text
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

        // text field with translated text
        TranslateTextRect {
            objectName: "translatedTextRect"
            Layout.columnSpan: 3
            Layout.rowSpan: 3
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        // combobox of supported languages
        LanguageBox {
            objectName: "destLangBox"

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

            onClicked: translateBtnClicked()

            contentItem: StyledTextItem {
                text: "Translate"
            }
        }
    }

    Component.onCompleted: {
        expandBtnClicked()
    }
}
