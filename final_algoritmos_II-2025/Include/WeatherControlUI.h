#ifndef WEATHERCONTROLUI_H
#define WEATHERCONTROLUI_H

#include <string>
#include <ctime>
#include "WeatherControl.h"

class WeatherControlUI {
private:
    WeatherControl weatherControl;
    
public:
    WeatherControlUI(WeatherControl _weatherControl);
    void showLastLog();
    std::string ConvertDate(time_t date);
    void showCurrentWeather();
    void showLogs();
    void upTemp();
    void downTemp();
    void upHum();
    void downHum();
    void pressEnterToContinue();
    void showMenu();
};

#endif // WEATHERCONTROLUI_H 