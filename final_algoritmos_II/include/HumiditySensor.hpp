#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include <Sensor.hpp>

class HumiditySensor : public Sensor
{
    public:
        HumiditySensor();
        ~HumiditySensor();
        float getValue();

    private:
        float m_value;
        void setValue(float value);
};

#endif