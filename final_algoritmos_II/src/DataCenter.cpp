#include "DataCenter.hpp"

DataCenter::DataCenter(Sensor* humiditySensor, Sensor* tempSensor)
{
    m_sensor1 = humiditySensor;
    m_sensor2 = tempSensor;
    setMaxHumidity(3.1);
    setMaxTemp(3.1);
}

DataCenter::~DataCenter()
{

}

void DataCenter::requestData() 
{
    float currentHumidity = m_sensor1->getValue();
    float currentTemp = m_sensor2->getValue();

    if(currentHumidity == m_maxHumidity)
    {
        sendAlert("Max humidity reached!");
        log("2022/11/11 - Max humidity reached!");
        exit(-1);
    } 

    if(currentTemp == m_maxTemp)
    {
        sendAlert("Max humidity reached!");
        log("2022/11/11 - Max humidity reached!");
        exit(-1);
    } 

    cout << "Humidity: " << currentHumidity << endl;
    cout << "Temperature: " << currentTemp << endl;

    // return "Humidity: " + currentHumidity + " - Temperature: " + currentTemp; 
}

void DataCenter::setMaxTemp(float maxTemp) 
{
    m_maxTemp = maxTemp;
}

void DataCenter::setMaxHumidity(float maxHumidity) 
{
    m_maxHumidity = maxHumidity;
}

void DataCenter::sendAlert(string alert) 
{
    cout << "Alert: " << alert << endl;
}

void DataCenter::log(string message) 
{
    cout << "Log: " << message << endl;
}


