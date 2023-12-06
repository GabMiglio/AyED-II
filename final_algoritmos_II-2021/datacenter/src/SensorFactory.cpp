#include <SensorFactory.hpp>

SensorFactory::SensorFactory(){}

SensorFactory::~SensorFactory(){}

Sensor* SensorFactory::create(string id) 
{
    Sensor* instance;
    if(id == "humidity") instance = new HumiditySensor();
    if(id == "temperature") instance = new TemperatureSensor();

    return instance;
}
