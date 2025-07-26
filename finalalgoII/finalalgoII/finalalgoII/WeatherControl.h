#ifndef WEATHERCONTROL_H
#define WEATHERCONTROL_H

#include <list>
#include <memory>
#include <ctime>
#include "Forecast.h"
#include "WeatherLog.h"

class WeatherControl {
private:
    std::shared_ptr<Forecast> forecast;
    std::list<WeatherLog> weatherLogs;
    
    // Compara dos weather logs
    bool compareWeatherLog(WeatherLog _weatherLog, WeatherLog _weatherLog2);

public:
    WeatherControl(std::shared_ptr<Forecast> _forecast);
    void Up_Temp(float temp);
    void Down_Temp(float temp);
    void Up_Humity(float hum);
    void Down_Humity(float hum);
    void createLog(time_t date, float hum, float temp);
    WeatherLog getCurrentWeather();
    std::list<WeatherLog> getLogs();
    void UpdateTemp(WeatherLog _weatherLog, float temp);
    void UpdateHum(WeatherLog _weatherLog, float hum);
};

#endif // WEATHERCONTROL_H 