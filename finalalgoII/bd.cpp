#include <memory>
#include <Forecast.h>
#include <WeatherControl.h>
#include <WeatherControlUI.h>

int main() {
    std::shared_ptr<Forecast> forecast = std::make_shared<Forecast>();
    WeatherControl weatherControl(forecast);
    WeatherControlUI weatherControlUI(weatherControl);
    weatherControlUI.showMenu();
    return 0;
} 