#include "WeatherModel.h"

WeatherModel::WeatherModel(QObject *parent)
    : QAbstractListModel{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    init();
}
void WeatherModel::init()
{
    for(int i=1;i<=24;i++)
    {
        m_weather = new Weather;
        QString hr=i<12?"am":"pm";
        m_weather->setTime(QString::number(i)+hr);
        int temp = i<7?10:(i>7&&i<10?20:(i>10&&i<20?30:40));
        m_weather->setTemperature(temp);
        QString weather=i<10?"cloudy":(i<20?"windy":(i<30?"rainy":(i<40?"sunny":"humidity")));
        m_weather->setWeathers(weather);
        QString img=i<10?"qrc:/cloudy.png":(i<20?"qrc:/wind.jpg":(i<30?"qrc:/rainy.png":(i<40?"qrc:/sunny.png":"qrc:/humidity.png")));
        m_weather->setImage(img);
        m_weatherList.push_back(m_weather);
    }
}

int WeatherModel::rowCount(const QModelIndex &index) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    return m_weatherList.size();
}

QVariant WeatherModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    int row=index.row();
    Weather *wt = m_weatherList.at(row);
    qDebug()<<Q_FUNC_INFO<<"Row--"<<row<<"Role--"<<role<<Qt::endl;
    switch (role)
    {
    case 1:return wt->time();
    case 2:return wt->temperature();
    case 3:return wt->weathers();
    case 4:return wt->image();
    }
    return "str";
}

QHash<int, QByteArray> WeatherModel::roleNames() const
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
    QHash<int, QByteArray> roles;
    roles[1]="Time";
    roles[2]="Temperature";
    roles[3]="Weather";
    roles[4]="Image5";
    return roles;
}


Weather *WeatherModel::getWthr(int index)
{
    Weather *wt=m_weatherList.at(index);
    return wt;
}

const QString &WeatherModel::city() const
{
    return m_city;
}

void WeatherModel::setCity(const QString &newCity)
{
    m_city = newCity;
}
