#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include <QDebug>
#include <QString>

class Weather : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int temp READ temperature CONSTANT)
    Q_PROPERTY(Qstring time READ time CONSTANT)
    Q_PROPERTY(Qstring weather READ weathers CONSTANT)
    Q_PROPERTY(Qstring images READ image CONSTANT)
public:
    explicit Weather(QObject *parent = nullptr);

    int temperature() const;
    void setTemperature(int newTemperature);

    const QString &weathers() const;
    void setWeathers(const QString &newWeathers);

    const QString &time() const;
    void setTime(const QString &newTime);

    const QString &image() const;
    void setImage(const QString &newImage);

private:
    int m_temperature;
    QString m_weathers;
    QString m_time;
    QString m_image;

signals:

};

#endif // WEATHER_H
