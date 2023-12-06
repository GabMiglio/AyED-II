#include <TemperatureSensor.hpp>

TemperatureSensor::TemperatureSensor(){}

TemperatureSensor::~TemperatureSensor(){}

float TemperatureSensor::getValue() 
{
    m_value++;
    setValue(m_value);
    return m_value;
}

void TemperatureSensor::setValue(float value) 
{
    m_value = value;
}
