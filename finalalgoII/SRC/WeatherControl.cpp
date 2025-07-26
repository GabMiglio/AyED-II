#include <WeatherControl.h>
#include <algorithm>

WeatherControl::WeatherControl(std::shared_ptr<Forecast> _forecast) {
    forecast = _forecast;
}

bool WeatherControl::compareWeatherLog(WeatherLog _weatherLog, WeatherLog _weatherLog2) {
    bool result = false;
    if (_weatherLog.getDate() == _weatherLog2.getDate() &&
        _weatherLog.getTemp() == _weatherLog2.getTemp() && 
        _weatherLog.getHum() == _weatherLog2.getHum()) {
        result = true;
    }
    return result;
}

void WeatherControl::Up_Temp(float temp) {
    forecast->Up_Temp(temp);
    createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
}

void WeatherControl::Down_Temp(float temp) {
    forecast->Down_Temp(temp);
    createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
}

void WeatherControl::Up_Humity(float hum) {
    forecast->Up_Humity(hum);
    createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
}

void WeatherControl::Down_Humity(float hum) {
    forecast->Down_Humity(hum);
    createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
}

void WeatherControl::createLog(time_t date, float hum, float temp) {
    WeatherLog weatherLog(date, hum, temp);
    weatherLogs.push_back(weatherLog);
}

WeatherLog WeatherControl::getCurrentWeather() {
    createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
    return weatherLogs.back();
}

std::list<WeatherLog> WeatherControl::getLogs() {
    return weatherLogs;
}

void WeatherControl::UpdateTemp(WeatherLog _weatherLog, float temp) {
    // Busca _weatherLog en la lista y devuelve un puntero
    auto weatherLogsIterator = std::find_if(weatherLogs.begin(), weatherLogs.end(), [&](WeatherLog log) {
        return compareWeatherLog(log, _weatherLog);
    });
    
    // Modifica el dato para el registro
    weatherLogsIterator->setTemp(temp);
}

void WeatherControl::UpdateHum(WeatherLog _weatherLog, float hum) {
    // Busca _weatherLog en la lista, compara y devuelve un puntero
    auto weatherLogsIterator = std::find_if(weatherLogs.begin(), weatherLogs.end(), [&](WeatherLog log) {
        return compareWeatherLog(log, _weatherLog);
    });
    
    // Modifica el dato para el registro
    weatherLogsIterator->setHum(hum);
} 