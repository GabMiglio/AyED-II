#include <WeatherControlUI.h>
#include <iostream>
#include <cstdlib>

using namespace std;

WeatherControlUI::WeatherControlUI(WeatherControl _weatherControl) : weatherControl(_weatherControl) {}

void WeatherControlUI::showLastLog() {
    WeatherLog lastLog = weatherControl.getLogs().back();
    cout << "Last Log: " << ConvertDate(lastLog.getDate()) << " Temp: " << lastLog.getTemp() << " Hum: " << lastLog.getHum() << endl;
    pressEnterToContinue();
}

string WeatherControlUI::ConvertDate(time_t date) {
    string dateString = ctime(&date);
    dateString.erase(dateString.find_last_not_of(" \n") + 1);
    return dateString;
}

void WeatherControlUI::showCurrentWeather() {
    WeatherLog currentWeather = weatherControl.getCurrentWeather();
    cout << "Current Temperature: " << currentWeather.getTemp() << endl;
    cout << "Current Humidity: " << currentWeather.getHum() << endl;
    pressEnterToContinue();
}

void WeatherControlUI::showLogs() {
    list<WeatherLog> logs = weatherControl.getLogs();
    for (auto log : logs) {
        cout << "Date: " << ConvertDate(log.getDate()) << " Temp: " << log.getTemp() << " Hum: " << log.getHum() << endl;
    }
    pressEnterToContinue();
}

void WeatherControlUI::upTemp() {
    float temp;
    cout << "Enter the temperature to increase: ";
    cin >> temp;
    weatherControl.Up_Temp(temp);
    showLastLog();
}

void WeatherControlUI::downTemp() {
    float temp;
    cout << "Enter the temperature to decrease: ";
    cin >> temp;
    weatherControl.Down_Temp(temp);
    showLastLog();
}

void WeatherControlUI::upHum() {
    float hum;
    cout << "Enter the humidity to increase: ";
    cin >> hum;
    weatherControl.Up_Humity(hum);
    showLastLog();
}

void WeatherControlUI::downHum() {
    float hum;
    cout << "Enter the humidity to decrease: ";
    cin >> hum;
    weatherControl.Down_Humity(hum);
    showLastLog();
}

void WeatherControlUI::pressEnterToContinue() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls");
}

void WeatherControlUI::showMenu() {
    int choice;
    do {
        cout << "1. Show Current Weather" << endl;
        cout << "2. Show Logs" << endl;
        cout << "3. Up Temp" << endl;
        cout << "4. Down Temp" << endl;
        cout << "5. Up Hum" << endl;
        cout << "6. Down Hum" << endl;
        cout << "7. Show Menu" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: showCurrentWeather(); break;
            case 2: showLogs(); break;
            case 3: upTemp(); break;
            case 4: downTemp(); break;
            case 5: upHum(); break;
            case 6: downHum(); break;
            case 7: showMenu(); break;
            case 8: return;
            default: cout << "Invalid choice" << endl; break;
        }
    } while (choice != 8);
} 