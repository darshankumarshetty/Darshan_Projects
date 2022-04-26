import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    height: root.height/6
    width: root.width/6
    color: "transparent"
    signal sendCity();
    Text{
        anchors.centerIn: parent
        text: Cityname
        font.bold: true
        font.pixelSize: 15
        color: "White"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("city--"+Cityname);
            sendCity();
        }
    }
}
