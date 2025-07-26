#include <iostream>
#include <ctime>

using namespace std;

class Forecast {
 
    int temp = 22;
    int humid = 15;
  
    public:

    void Up_Temp( int X)
    {
        temp ++;
    }

    void Down_Temp( int X)
    {
        temp --;
    }

    void Up_Humity( int X)
    {
        humid++;
    }

    void Down_Humity( int X)
    {
        humid--;
    }

    int Read_Temp()
    {
        return temp;
    }

    int Read_Humity()
    {
        return humid;
    }
};

class WeatherRegistry {

    time_t date;
    int temp;
    int hum;
    public:

    public:
    WeatherRegistry() : date(0), temp(0), hum(0) {}
    WeatherRegistry(time_t _date, int _temp, int _hum) : date(_date), temp(_temp), hum(_hum) {}

    time_t getDate() {return date;}
    int getTemp() {return temp;}
    int getHum() {return hum;}

};

class WeatherControl {
    Forecast* forecast;
    WeatherRegistry weatherLogs[9999];
    int weatherLogsCurrentIndex = 0;

    public:
    WeatherControl(Forecast* _forecast) : forecast(_forecast) {}

    void Up_Temp(int temp)
    {
        forecast->Up_Temp(temp);
    }
    void Down_Temp(int temp)
    {
        forecast->Down_Temp(temp);
    }
    void Up_Humity(int hum)
    {
        forecast->Up_Humity(hum);
    }
    void Down_Humity(int hum)
    {
        forecast->Down_Humity(hum);
    }
    void createLog(time_t date,int hum, int temp)
    {
        WeatherRegistry weatherRegistry(date, hum, temp);
        weatherLogs[weatherLogsCurrentIndex] = weatherRegistry;
        weatherLogsCurrentIndex ++;

    }
    void getLogs();
    void Update();


};




int testapi()
{
    Forecast forecast;
    int currentHumid = forecast.Read_Humity();
    int currentTemp = forecast.Read_Temp();


    cout << "Current Temperature: " << currentTemp << endl;
    forecast.Up_Temp(10);
    currentTemp = forecast.Read_Temp();
    cout << "Current Temperature: " << currentTemp << endl;
    forecast.Down_Temp(10);
    currentTemp = forecast.Read_Temp();
    cout << "Current Temperature: " << currentTemp << endl;
    forecast.Up_Humity(10);
    currentHumid = forecast.Read_Humity();
    cout << "Current Humidity: " << currentHumid << endl;
    forecast.Down_Humity(10);
    currentHumid = forecast.Read_Humity();
    cout << "Current Humidity: " << currentHumid << endl;
}

int main()
{
    Forecast* forecast = new Forecast();
    WeatherControl weatherControl(forecast);

    weatherControl.Up_Temp(10);
    //weatherControl.Up_Humity();
    weatherControl.getLogs();
    weatherControl.Update();

}