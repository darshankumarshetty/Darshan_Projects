import QtQuick 2.0
import QtQuick.Controls 2.0
Rectangle {
    id:rect
    signal sendme1
    height: root.height/6
    width: root.width/6
    color: "transparent"
    Column{
        spacing: 2
        Text{text:Time;color: "Black";font.pixelSize: 15}
        Text{text:Temperature+"°C";color: "Black";font.pixelSize: 15}
        Text{text:Weather;color: "Black";font.pixelSize: 15}
        Image{source:Image5
            height:rect.height/2
            width: rect.width/2
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            sendme1();
        }
    }
}
