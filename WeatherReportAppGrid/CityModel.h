#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QAbstractListModel >
#include <QObject>
#include <QString>
#include <QDebug>
#include "WeatherModel.h"

class CityModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CityModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index,int role)const override;
    QHash<int,QByteArray> roleNames()const override;
    Q_INVOKABLE WeatherModel* getWeather(int index);
    void init();
signals:
private:
    QList<WeatherModel*> m_weathermodelList;
    WeatherModel *m_weatherModel;
};

#endif // CITYMODEL_H
