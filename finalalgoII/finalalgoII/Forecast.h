#ifndef FORECAST_H
#define FORECAST_H

class Forecast {
private:
    int temp = 22;
    int humid = 15;
  
public:
    void Up_Temp(float X);
    void Down_Temp(float X);
    void Up_Humity(float X);
    void Down_Humity(float X);
    float Read_Temp();
    float Read_Humity();
};

#endif // FORECAST_H 