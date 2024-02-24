#pragma once

#include <QString>
#include <QJsonObject>

class WeatherObject{
public:
    WeatherObject();
    WeatherObject(const QJsonObject &data);

public:
    QString getCityName() const;
    QString getTime() const;
    double getTemp() const;
    double getFeelsLike() const;
    double getPressure() const;
    double getHumidity() const;
    double getWindSpeed() const;

private:
    QString _cityName;
    QString _time;
    double _temp;
    double _feelsLike;
    int _pressure;
    int _humidity;
    double _windSpeed;
};
