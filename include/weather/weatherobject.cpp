#include "weatherobject.hpp"

WeatherObject::WeatherObject()
{
    _cityName = "Null";
    _time = "Null";
    _temp = 0;
    _feelsLike = 0;
    _pressure = 0;
    _humidity = 0;
    _windSpeed = 0;
}

WeatherObject::WeatherObject(const QJsonObject &data)
{
    _cityName = data["name"].toString();
    _time = QTime::currentTime().toString("HH:mm:ss");
    _temp = data["main"]["temp"].toDouble();
    _feelsLike = data["main"]["feels_like"].toDouble();
    _pressure = data["main"]["pressure"].toInt();
    _humidity = data["main"]["humidity"].toInt();
    _windSpeed = data["wind"]["speed"].toDouble();
}

QString WeatherObject::getCityName() const
{
    return _cityName;
}

QString WeatherObject::getTime() const
{
    return _time;
}

double WeatherObject::getTemp() const
{
    return _temp;
}

double WeatherObject::getFeelsLike() const
{
    return _feelsLike;
}

double WeatherObject::getPressure() const
{
    return _pressure;
}

double WeatherObject::getHumidity() const
{
    return _humidity;
}

double WeatherObject::getWindSpeed() const
{
    return _windSpeed;
}
