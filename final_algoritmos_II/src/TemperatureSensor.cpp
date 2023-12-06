#include <TemperatureSensor.hpp>

TemperatureSensor::TemperatureSensor()
{

}

TemperatureSensor::~TemperatureSensor()
{

}

float TemperatureSensor::getValue() 
{
    setValue(1.1);
    return m_value;
}

void TemperatureSensor::setValue(float value) 
{
    m_value++;
}
