#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <Sensor.hpp>

class TemperatureSensor : public Sensor
{
    public:
        TemperatureSensor();
        ~TemperatureSensor();
        float getValue();

    private:
        float m_value;
        void setValue(float value);
};

#endif