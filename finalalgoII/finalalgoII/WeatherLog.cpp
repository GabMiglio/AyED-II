#include "WeatherLog.h"

WeatherLog::WeatherLog(time_t _date, float _temp, float _hum) 
    : date(_date), temp(_temp), hum(_hum) {}

void WeatherLog::setHum(float _hum) {
    hum = _hum;
}

void WeatherLog::setTemp(float _temp) {
    temp = _temp;
}

time_t WeatherLog::getDate() {
    return date;
}

float WeatherLog::getTemp() {
    return temp;
}

float WeatherLog::getHum() {
    return hum;
} 