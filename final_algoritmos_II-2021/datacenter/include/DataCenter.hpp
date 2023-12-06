#ifndef DATACENTER_H
#define DATACENTER_H

#include <Sensor.hpp>
#include <MailSender.hpp>
#include <LogWriter.hpp>
#include <string>

class DataCenter
{
    public:
        DataCenter(Sensor*, Sensor*);
        ~DataCenter();
        string requestData();
        void setMaxTemp(float);
        void setMaxHumidity(float);


    private:
        Sensor* m_sensor1;
        Sensor* m_sensor2;
        float m_maxTemp;
        float m_maxHumidity;
        MailSender* m_mailSender;
        LogWriter* m_logWriter;
};

#endif