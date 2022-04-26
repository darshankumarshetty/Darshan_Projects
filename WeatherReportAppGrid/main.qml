import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
Window {
    id:root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "transparent"
    Image{
        id:img
        width:root.width
        height: root.height
        source: "qrc:/weatherimgg.webp"
    }
        GridView{
            id:lv
            anchors.fill: parent
            cellWidth: parent.width/3
            cellHeight: parent.height/6
            highlight: Rectangle{color:"maroon"; radius:5}
            visible: true
            focus: true
            model:CTMdl
            keyNavigationEnabled: true
            delegate:MyCityDelegateMdl{
                onSendCity: {
                    lv1.wmod=CTMdl.getWeather(index)
                    pup.open()
                    r2.visible=true
                    r2.current=lv1.model.getWthr(new Date().getHours()).temp
                    lv2.ind=index
                    console.log("____________"+r2.current)
                }
            }
        }
        Popup {
            id:pup
            width: img.width
            height: img.height
            modal: true
            focus:true
            visible: false
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
            background: Image {
                id: i1
                source: "qrc:/popi.webp"
            }

            Image {
                id:cancIm
                source: "qrc:/cancel.png"
                anchors.right: parent.right
                scale: 0.5
                MouseArea{
                    anchors.fill:parent
                    onClicked:
                        pup.close()
                }
            }
            Rectangle{
                id:r2
                anchors.top: parent.top
                anchors.topMargin: 30
                property var current
                property var imgs
                height: root.height/4
                width: root.width
                visible: false
                color: "transparent"
                ColumnLayout{
                    anchors.centerIn: parent
                    spacing: 5
                    Image {
                        id: img1
                        /*source: imgs*/
                        Layout.preferredHeight: 50
                        Layout.preferredWidth: 50
                        Layout.alignment: Qt.AlignHCenter

                    }
                    Text{
                        id:t1
                        Layout.alignment: Qt.AlignHCenter
                        text:r2.current+"°C"
                        font.pixelSize: root.width/25
                        color: "Black"
                    }
                    Text{
                        id:t2
                        Layout.alignment: Qt.AlignHCenter
                        text:"--------------------------------------24Hours---------------------------------------"
                        font.pixelSize: root.width/25
                        color: "Black"
                    }
                }
            }
            ListView{
                id:lv1
                property var wmod
                spacing: 2
                anchors.top: r2.bottom
                anchors.topMargin: 15
                width: parent.width
                height: parent.height/6
                model: wmod
                delegate:MyWeatherDelegateMdl{
                    onSendme1:{
                        r2.current=lv1.model.getWthr(index).temp
                        img1.source=/*lv1.model.getWthr(index).images*/Image5
                        console.log("statement"+lv1.model.getWthr(index).images)
                    }
                }
                orientation: Qt.Horizontal
            }
            ListView{
                id:lv2
                property int ind
                width: parent.width
                height: parent.height/6
                anchors.top: lv1.bottom
                anchors.topMargin: 60
                visible: true
                model:CTMdl
                currentIndex:ind
                delegate:MyCityDelegateMdl{
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            lv2.currentIndex=model.index
                            lv1.wmod=CTMdl.getWeather(index)
                        }
                    }
                }
                preferredHighlightBegin: 250
                preferredHighlightEnd: 250
                onCurrentIndexChanged: {
                    lv1.model=CTMdl.getWeather(currentIndex)
                }
                highlightRangeMode: ListView.StrictlyEnforceRange
                highlight: Rectangle{
                    color: "Dark blue"
                    radius: 5
                }
                focus: true

                orientation: Qt.Horizontal
            }
        }
    }

