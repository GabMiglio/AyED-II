#include <iostream>
#include <ctime>
#include <list>
#include <memory>
#include <algorithm>

using namespace std;

class Forecast {
 
    int temp = 22;
    int humid = 15;
  
    public:

    void Up_Temp( float X)
    {
        temp += X;
    }

    void Down_Temp( float X)
    {
        temp -= X;
    }

    void Up_Humity( float X)
    {
        humid += X;
    }

    void Down_Humity( float X)
    {
        humid -= X;
    }

    float Read_Temp()
    {
        return temp;
    }

    float Read_Humity()
    {
        return humid;
    }
};

class WeatherLog {

    time_t date;
    float temp;
    float hum;
    public:

    public:
    WeatherLog(time_t _date, float _temp, float _hum) : date(_date), temp(_temp), hum(_hum) {}

    void setHum(float _hum){
        hum = _hum;
    }

    void setTemp(float _temp){
        temp = _temp;
    }

    time_t getDate() {return date;}
    float getTemp() {return temp;}
    float getHum() {return hum;}
    

};

class WeatherControl {

    shared_ptr<Forecast> forecast;
    list<WeatherLog> weatherLogs;

    // Compara dos whater logs
    bool compareWeatherLog(WeatherLog _weatherLog, WeatherLog _weatherLog2){
        bool result = false;
        if (_weatherLog.getDate() == _weatherLog2.getDate() &&
            _weatherLog.getTemp() == _weatherLog2.getTemp() && 
            _weatherLog.getHum() == _weatherLog2.getHum())
        {
            result = true;
        }
        return result;
    }

    public:
    WeatherControl(shared_ptr<Forecast> _forecast) {
        forecast = _forecast;
    }

    void Up_Temp(float temp)
    {
        forecast->Up_Temp(temp);
        createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
    }
    void Down_Temp(float temp)
    {
        forecast->Down_Temp(temp);
        createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
    }
    void Up_Humity(float hum)
    {
        forecast->Up_Humity(hum);
        createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
    }
    void Down_Humity(float hum)
    {
        forecast->Down_Humity(hum);
        createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
    }  
    
    void createLog(time_t date,float hum, float temp)
    {
        WeatherLog weatherLog(date, hum, temp);
        weatherLogs.push_back(weatherLog);
    }

    WeatherLog getCurrentWeather(){

        createLog(time(0), forecast->Read_Humity(), forecast->Read_Temp());
        return weatherLogs.back();
    }
    
    list<WeatherLog> getLogs (){

        return weatherLogs;
    }

    void UpdateTemp(WeatherLog _weatherLog, float temp){

        //Busca _weatherLog en la lista y devuelve un puntero
        auto weatherLogsIterator = find_if(weatherLogs.begin(), weatherLogs.end(), [&](WeatherLog log) {
            return compareWeatherLog(log, _weatherLog);
        });
        
        //Modifica el dato para el registro
        weatherLogsIterator->setTemp(temp);

    }

    void UpdateHum(WeatherLog _weatherLog, float hum ){
        //Busca _weatherLog en la lista, compara y devuelve un puntero
        auto weatherLogsIterator = find_if(weatherLogs.begin(), weatherLogs.end(), [&](WeatherLog log) {
            return compareWeatherLog(log, _weatherLog);
        });
        

        //Modifica el dato para el registro
        weatherLogsIterator->setHum(hum);

    }
};

class WeatherControlUI{

    WeatherControl weatherControl;

    public:
    WeatherControlUI(WeatherControl _weatherControl) : weatherControl(_weatherControl) {}

    void showLastLog(){
        WeatherLog lastLog = weatherControl.getLogs().back();
        cout << "Last Log: " << ConvertDate(lastLog.getDate()) << " Temp: " << lastLog.getTemp() << " Hum: " << lastLog.getHum() << endl;
        pressEnterToContinue();
    }

    string ConvertDate(time_t date){
        string dateString = ctime(&date);
        dateString.erase(dateString.find_last_not_of(" \n") + 1);
        return dateString;
    }
    
    void showCurrentWeather(){
        WeatherLog currentWeather = weatherControl.getCurrentWeather();
        cout << "Current Temperature: " << currentWeather.getTemp() << endl;
        cout << "Current Humidity: " << currentWeather.getHum() << endl;
        pressEnterToContinue();
    }

    void showLogs(){
        list<WeatherLog> logs = weatherControl.getLogs();
        for (auto log : logs) {
            cout << "Date: " << ConvertDate(log.getDate()) << " Temp: " << log.getTemp() << " Hum: " << log.getHum() << endl;
        }
        pressEnterToContinue();
    }

    void upTemp(){
        float temp;
        cout << "Enter the temperature to increase: ";
        cin >> temp;
        weatherControl.Up_Temp(temp);
        showLastLog();
    }

    void downTemp(){
        float temp;
        cout << "Enter the temperature to decrease: ";
        cin >> temp;
        weatherControl.Down_Temp(temp);
        showLastLog();
    }

    void upHum(){
        float hum;
        cout << "Enter the humidity to increase: ";
        cin >> hum;
        weatherControl.Up_Humity(hum);
        showLastLog();
    }

    void downHum(){
        float hum;
        cout << "Enter the humidity to decrease: ";
        cin >> hum;
        weatherControl.Down_Humity(hum);
        showLastLog();
    }

    void pressEnterToContinue(){
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }

    void showMenu(){
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

};

int main()
{
    shared_ptr<Forecast> forecast = make_shared<Forecast>();
    WeatherControl weatherControl(forecast);
    WeatherControlUI weatherControlUI(weatherControl);
    weatherControlUI.showMenu();
}