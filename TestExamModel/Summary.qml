import QtQuick 2.0

Rectangle{
    property var t11;
    property string t14;
    id:rect1
    height: 300
    width:300
    color: "lavender"
    anchors.centerIn: parent
    Text {
        id: t6
        text:"SUMMARY"
        font.pixelSize: 20
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Text{
        id:t13
        text: t14
        font.pixelSize: 15
        anchors.top: parent.top
        anchors.topMargin: 50
        font.bold: true
    }
    Text {
        id: t12
        text: t11
        font.pixelSize: 15
        anchors.centerIn: parent
    }
}
