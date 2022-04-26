import QtQuick 2.0
import QtQuick.Controls 2.0
Rectangle{
    id:r11
    signal objectofSub(string subNm,var value);
    signal subjectName(string sub)
    width:win.width-490
    height: 100
    color: "yellow"
    Label{
        text:subject
        anchors.centerIn: parent
        font.pixelSize: 15
    }
    MouseArea{
        anchors.fill:parent
        onClicked: {
            subjectName(subject)
            objectofSub(subject,index);
            console.log("clicked")
            wintx.text="Instruction:\nWait for 10 Second\nExam Duration:30 min\nTotal Question: 30\nAll The Best"
        }
    }
}
