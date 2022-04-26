#include "Weather.h"

Weather::Weather(QObject *parent)
    : QObject{parent}
{
    qDebug()<<Q_FUNC_INFO<<Qt::endl;
}

int Weather::temperature() const
{
    return m_temperature;
}

void Weather::setTemperature(int newTemperature)
{
    m_temperature = newTemperature;
}

const QString &Weather::weathers() const
{
    return m_weathers;
}

void Weather::setWeathers(const QString &newWeathers)
{
    m_weathers = newWeathers;
}

const QString &Weather::time() const
{
    return m_time;
}

void Weather::setTime(const QString &newTime)
{
    m_time = newTime;
}

const QString &Weather::image() const
{
    return m_image;
}

void Weather::setImage(const QString &newImage)
{
    m_image = newImage;
}
