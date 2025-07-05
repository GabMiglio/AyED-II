#ifndef WEATHERLOG_H
#define WEATHERLOG_H

#include <ctime>

class WeatherLog {
private:
    time_t date;
    float temp;
    float hum;

public:
    WeatherLog(time_t _date, float _temp, float _hum);
    void setHum(float _hum);
    void setTemp(float _temp);
    time_t getDate();
    float getTemp();
    float getHum();
};

#endif // WEATHERLOG_H 