#include <DataCenter.hpp>

DataCenter::DataCenter(Sensor* humiditySensor, Sensor* tempSensor)
{
    m_sensor1 = humiditySensor;
    m_sensor2 = tempSensor;
    setMaxHumidity(3.1);
    setMaxTemp(3.1);

    m_mailSender = new MailSender();
    m_logWriter = new LogWriter();
}

DataCenter::~DataCenter()
{
    delete m_mailSender;
    delete m_logWriter;
}

string DataCenter::requestData() 
{
    float currentHumidity = m_sensor1->getValue();
    float currentTemp = m_sensor2->getValue();

    if(currentHumidity >= m_maxHumidity)
    {
        cout << "Max humidity reached: " << currentHumidity << endl; 
        m_mailSender->send("DataCenter", "Alert of humidity", "Max humidity reached!");
        m_logWriter->write("Humidity Module", "Max humidity reached");
    } 

    if(currentTemp >= m_maxTemp)
    {
        cout << "Max temperature reached: " << currentTemp << endl;
        m_mailSender->send("DataCenter", "Alert of temperature", "Max temperature reached!");
        m_logWriter->write("Temperature Module", "Max temperature reached");
    } 

    return "Humidity: " + to_string(currentHumidity) + " - Temperature: " + to_string(currentTemp); 
}

void DataCenter::setMaxTemp(float maxTemp) 
{
    m_maxTemp = maxTemp;
}

void DataCenter::setMaxHumidity(float maxHumidity) 
{
    m_maxHumidity = maxHumidity;
}

