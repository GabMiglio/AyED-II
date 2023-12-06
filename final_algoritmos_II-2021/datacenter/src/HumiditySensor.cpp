#include <HumiditySensor.hpp>

HumiditySensor::HumiditySensor(){}

HumiditySensor::~HumiditySensor(){}

float HumiditySensor::getValue() 
{
    setValue(1.1);
    return m_value;
}

void HumiditySensor::setValue(float value) 
{
    m_value++;
}
