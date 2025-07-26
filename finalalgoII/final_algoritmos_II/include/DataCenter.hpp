#ifndef DATACENTER_H
#define DATACENTER_H

#include <string>
#include <Sensor.hpp>

class DataCenter
{
    public:
        DataCenter(Sensor*, Sensor*);
        ~DataCenter();
        void requestData();
        void setMaxTemp(float);
        void setMaxHumidity(float);


    private:
        Sensor* m_sensor1;
        Sensor* m_sensor2;
        float m_maxTemp;
        float m_maxHumidity;
        void sendAlert(string);
        void log(string);
};

#endif